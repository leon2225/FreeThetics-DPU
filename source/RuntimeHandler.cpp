/*
 * RuntimeHandler.cpp
 *
 *  Created on: Jan 9, 2024
 *      Author: leon
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "RuntimeHandler.h"

#include <vector>
#include <string>
#include <span>

#include "ComInterface.h"
#include "ConfigurationManager.h"
#include "Configuration.h"
#include "AnalysisAlgorithm.h"
#include "PassAlgorithm.h"
#include "Status.h"


/*******************************************************************************
 * Defines
 ******************************************************************************/

/*******************************************************************************
 * Data Types
 * ****************************************************************************/

/*******************************************************************************
 * Private Variables
 * ****************************************************************************/
freesthetics::ComInterface* comInterface = nullptr;
freesthetics::ConfigurationManager* configManager = nullptr;
freesthetics::AnalysisAlgorithm* activeAnalysisAlgorithm = nullptr;

volatile bool isRunning = false;

uint8_t g_debugBuffer[32];
/*******************************************************************************
 * Function Prototypes
 * ****************************************************************************/
void renumrateDevices();
void start();
void stop();
void inputHandlingDone();

// init
void initHardware();
void gpio_init();
void init_debug();
/*******************************************************************************
 * Functions
 * ****************************************************************************/
void main()
{
	freesthetics::Status status;

	/** Initialization **/
	initHardware();
	init_debug();

	/** fill globals **/
	comInterface = new freesthetics::ComInterface(inputHandlingDone);
	configManager = new freesthetics::ConfigurationManager(comInterface);
	activeAnalysisAlgorithm = configManager->getActiveConfiguration().algorithm;

	// Add a configuration
	freesthetics::AnalysisAlgorithm* passAlgorithm = new freesthetics::PassAlgorithm("Pass Algorithm");
	freesthetics::Configuration passConfiguration {
		"Pass",
		passAlgorithm
	};
	// Devices
	freesthetics::DeviceDescriptor electrode {
		.deviceType = "Elctr6Ch",
		.deviceIdentifier = "Elctr1",
		.peripheralIndex = -1,
		.deviceAddress = -1,
		.name = "Electrode"
	};
	freesthetics::DeviceDescriptor display {
		.deviceType = "BarDis6Ch",
		.deviceIdentifier = "Display1",
		.peripheralIndex = -1,
		.deviceAddress = -1,
		.name = "Display"
	};

	passConfiguration.PDSs.push_back({
		.name = "Electrode",
		.channels = {},
		.isInput = true
	});
	passConfiguration.PDSs.push_back({
		.name = "Display",
		.channels = {},
		.isInput = false
	});

	// Add channels
	for(uint32_t i = 0; i < 6; i++)
	{
		freesthetics::ChannelDescriptor electrodeChannel {
			.device = &electrode,
			.channelIndex = i,
			.name = "Channel " + std::to_string(i + 1)
		};
		passConfiguration.PDSs[0].channels.push_back(electrodeChannel);
		freesthetics::ChannelDescriptor displayChannel {
			.device = &display,
			.channelIndex = i,
			.name = "Channel " + std::to_string(i + 1)
		};
		passConfiguration.PDSs[1].channels.push_back(displayChannel);
	}
	configManager->addConfiguration(passConfiguration);

	/** Initialzation done -> Enumerate the devices **/
	renumrateDevices();

	//Main Loop
	while(1)
	{
		if(!isRunning)
		{
			// Check if the configuration is valid
			status = comInterface->configurationValid();
			if(status != freesthetics::Status::Ok)
			{
				// Configuration is not valid, stop the cycle and setup new configuration
				renumrateDevices();
			}
			else
			{
				// Start the cycle
				start();
			}
		}
	}
}


void renumrateDevices()
{
	//Stop the cycle
	stop();

	// Renumerate the devices
	freesthetics::Status status = configManager->renumrateDevices();
	assert(status == freesthetics::Status::Ok);

	status = configManager->incrementActiveConfiguration();
	assert(status == freesthetics::Status::Ok);

	// Update the active configuration
	static freesthetics::Configuration activeConfiguration = configManager->getActiveConfiguration();

	// Update the analysis algorithm
	activeAnalysisAlgorithm = activeConfiguration.algorithm;
	activeAnalysisAlgorithm->setComInterface(comInterface);

	// Start the cycle
	start();	
}

/**
 * @brief Starts the realtime processing cycle
 * 
 */
void start()
{
	// Start the ComInterface
	freesthetics::Status status = comInterface->enterRealTimeMode();
	assert(status == freesthetics::Status::Ok);

	// Start the analysis algorithm
	activeAnalysisAlgorithm->start();

	// Set the running flag
	isRunning = true;
}

/**
 * @brief Stops the realtime processing cycle
 * 
 */
void stop()
{
	// Stop the analysis algorithm
	activeAnalysisAlgorithm->stop();

	// Stop the ComInterface
	freesthetics::Status status = comInterface->exitRealTimeMode();
	assert(status == freesthetics::Status::Ok);

	// Clear the running flag
	isRunning = false;
}

/**
 * @brief Callback that is called when the input handling of the ComInterface is done
 * 			and the data should be processed
 * 
 */
void inputHandlingDone()
{
	//Check if the configuration is valid
	freesthetics::Status status = comInterface->configurationValid();
	if(status != freesthetics::Status::Ok)
	{
		// Stop realtime processing
		stop();

		// Configuration is not valid, stop the cycle and setup new configuration
		renumrateDevices();

		return;
	}

	activeAnalysisAlgorithm->run();

	status = comInterface->processOutgoingData();
	assert(status == freesthetics::Status::Ok);
}

/*******************************************************************************
 * Interrupt Handlers
 * ****************************************************************************/
extern "C"
{
void PIT_IRQHandler(void)
{
	/* Clear interrupt flag.*/
	PIT_ClearStatusFlags(PIT_PERIPHERAL, PIT_CHANNEL_0, kPIT_TimerFlag);

	static int i;
    i++;
    GPIO_PinWrite(BOARD_INITPINS_Sync_GPIO, BOARD_INITPINS_Sync_GPIO_PIN, i & 1);


    // start i2c transfer after 100 cycles
    if (i & 1 && i > 100 && isRunning)
	{
		comInterface->CyclicHandler();
	}
}
}

/*******************************************************************************
 * Initialization Functions
 ******************************************************************************/


void initHardware()
{
    /* Init board hardware. */
    BOARD_ConfigMPU();
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
    // Set frequency to 200Hz
    PIT_SetTimerPeriod(PIT_PERIPHERAL, PIT_CHANNEL_0, USEC_TO_COUNT(5000, CLOCK_GetFreq(kCLOCK_PerClk)));

    gpio_init();
}



void gpio_init()
{
    /* Define the init structure for the output LED pin*/
    gpio_pin_config_t led_config = {
        kGPIO_DigitalOutput,
        0,
    };

    /* Init output LED GPIO. */
    GPIO_PinInit(BOARD_INITPINS_USR_LED_GPIO, BOARD_INITPINS_USR_LED_GPIO_PIN, &led_config);
    GPIO_PinInit(BOARD_INITPINS_Sync_GPIO, BOARD_INITPINS_Sync_GPIO_PIN, &led_config);
}

void init_debug()
{

    SEGGER_RTT_Init();
    SEGGER_RTT_ConfigUpBuffer(1, "DataOut", &g_debugBuffer[0], sizeof(g_debugBuffer),
                              SEGGER_RTT_MODE_BLOCK_IF_FIFO_FULL);

    SEGGER_RTT_WriteString(0, "SEGGER Real-Time-Terminal Sample\r\n\r\n");
    SEGGER_RTT_WriteString(0, BOARD_NAME);
	SEGGER_RTT_WriteString(0, "\r\n\r\n");

}
