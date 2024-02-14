/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/

/*! @brief Direction type  */
typedef enum _pin_mux_direction
{
  kPIN_MUX_DirectionInput = 0U,         /* Input direction */
  kPIN_MUX_DirectionOutput = 1U,        /* Output direction */
  kPIN_MUX_DirectionInputOrOutput = 2U  /* Input or output direction */
} pin_mux_direction_t;

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

#define BOARD_INITPINS_IOMUXC_GPR_GPR26_GPIO_MUX1_GPIO_SEL_MASK 0x080000U /*!< GPIO1 and GPIO6 share same IO MUX function, GPIO_MUX1 selects one GPIO function: affected bits mask */
#define BOARD_INITPINS_IOMUXC_GPR_GPR27_GPIO_MUX2_GPIO_SEL_MASK 0x08U /*!< GPIO2 and GPIO7 share same IO MUX function, GPIO_MUX2 selects one GPIO function: affected bits mask */
#define BOARD_INITPINS_IOMUXC_GPR_GPR29_GPIO_MUX4_GPIO_SEL_MASK 0x0170U /*!< GPIO4 and GPIO9 share same IO MUX function, GPIO_MUX4 selects one GPIO function: affected bits mask */

/* GPIO_B0_03 (coord D8), USR_LED */
/* Routed pin properties */
#define BOARD_INITPINS_USR_LED_PERIPHERAL                                  GPIO2   /*!< Peripheral name */
#define BOARD_INITPINS_USR_LED_SIGNAL                                    gpio_io   /*!< Signal name */
#define BOARD_INITPINS_USR_LED_CHANNEL                                        3U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_USR_LED_GPIO                                        GPIO2   /*!< GPIO peripheral base pointer */
#define BOARD_INITPINS_USR_LED_GPIO_PIN                                       3U   /*!< GPIO pin number */
#define BOARD_INITPINS_USR_LED_GPIO_PIN_MASK                          (1U << 3U)   /*!< GPIO pin mask */
#define BOARD_INITPINS_USR_LED_PORT                                        GPIO2   /*!< PORT peripheral base pointer */
#define BOARD_INITPINS_USR_LED_PIN                                            3U   /*!< PORT pin number */
#define BOARD_INITPINS_USR_LED_PIN_MASK                               (1U << 3U)   /*!< PORT pin mask */

/* GPIO_AD_B1_06 (coord J12), CSI_VSYNC/J35[18]/J22[2]/UART_TX */
/* Routed pin properties */
#define BOARD_INITPINS_CSI_VSYNC_PERIPHERAL                               LPI2C3   /*!< Peripheral name */
#define BOARD_INITPINS_CSI_VSYNC_SIGNAL                                      SDA   /*!< Signal name */

/* GPIO_AD_B1_07 (coord K10), CSI_HSYNC/J35[16]/J22[1]/UART_RX */
/* Routed pin properties */
#define BOARD_INITPINS_CSI_HSYNC_PERIPHERAL                               LPI2C3   /*!< Peripheral name */
#define BOARD_INITPINS_CSI_HSYNC_SIGNAL                                      SCL   /*!< Signal name */

/* GPIO_AD_B1_03 (coord M12), Sync */
/* Routed pin properties */
#define BOARD_INITPINS_Sync_PERIPHERAL                                     GPIO1   /*!< Peripheral name */
#define BOARD_INITPINS_Sync_SIGNAL                                       gpio_io   /*!< Signal name */
#define BOARD_INITPINS_Sync_CHANNEL                                          19U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_Sync_GPIO                                           GPIO1   /*!< GPIO peripheral base pointer */
#define BOARD_INITPINS_Sync_GPIO_PIN                                         19U   /*!< GPIO pin number */
#define BOARD_INITPINS_Sync_GPIO_PIN_MASK                            (1U << 19U)   /*!< GPIO pin mask */
#define BOARD_INITPINS_Sync_PORT                                           GPIO1   /*!< PORT peripheral base pointer */
#define BOARD_INITPINS_Sync_PIN                                              19U   /*!< PORT pin number */
#define BOARD_INITPINS_Sync_PIN_MASK                                 (1U << 19U)   /*!< PORT pin mask */

/* GPIO_AD_B0_12 (coord K14), SCL4 */
/* Routed pin properties */
#define BOARD_INITPINS_SCL4_PERIPHERAL                                    LPI2C4   /*!< Peripheral name */
#define BOARD_INITPINS_SCL4_SIGNAL                                           SCL   /*!< Signal name */

/* GPIO_AD_B0_13 (coord L14), SDA4 */
/* Routed pin properties */
#define BOARD_INITPINS_SDA4_PERIPHERAL                                    LPI2C4   /*!< Peripheral name */
#define BOARD_INITPINS_SDA4_SIGNAL                                           SDA   /*!< Signal name */

/* GPIO_EMC_04 (coord F2), SW_UP */
/* Routed pin properties */
#define BOARD_INITPINS_SW_UP_PERIPHERAL                                    GPIO4   /*!< Peripheral name */
#define BOARD_INITPINS_SW_UP_SIGNAL                                      gpio_io   /*!< Signal name */
#define BOARD_INITPINS_SW_UP_CHANNEL                                          4U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_SW_UP_GPIO                                          GPIO4   /*!< GPIO peripheral base pointer */
#define BOARD_INITPINS_SW_UP_GPIO_PIN                                         4U   /*!< GPIO pin number */
#define BOARD_INITPINS_SW_UP_GPIO_PIN_MASK                            (1U << 4U)   /*!< GPIO pin mask */
#define BOARD_INITPINS_SW_UP_PORT                                          GPIO4   /*!< PORT peripheral base pointer */
#define BOARD_INITPINS_SW_UP_PIN                                              4U   /*!< PORT pin number */
#define BOARD_INITPINS_SW_UP_PIN_MASK                                 (1U << 4U)   /*!< PORT pin mask */

/* GPIO_EMC_08 (coord H3), SW_MOD */
/* Routed pin properties */
#define BOARD_INITPINS_SW_MOD_PERIPHERAL                                   GPIO4   /*!< Peripheral name */
#define BOARD_INITPINS_SW_MOD_SIGNAL                                     gpio_io   /*!< Signal name */
#define BOARD_INITPINS_SW_MOD_CHANNEL                                         8U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_SW_MOD_GPIO                                         GPIO4   /*!< GPIO peripheral base pointer */
#define BOARD_INITPINS_SW_MOD_GPIO_PIN                                        8U   /*!< GPIO pin number */
#define BOARD_INITPINS_SW_MOD_GPIO_PIN_MASK                           (1U << 8U)   /*!< GPIO pin mask */
#define BOARD_INITPINS_SW_MOD_PORT                                         GPIO4   /*!< PORT peripheral base pointer */
#define BOARD_INITPINS_SW_MOD_PIN                                             8U   /*!< PORT pin number */
#define BOARD_INITPINS_SW_MOD_PIN_MASK                                (1U << 8U)   /*!< PORT pin mask */

/* GPIO_EMC_05 (coord G5), SW_DOWN */
/* Routed pin properties */
#define BOARD_INITPINS_SW_DOWN_PERIPHERAL                                  GPIO4   /*!< Peripheral name */
#define BOARD_INITPINS_SW_DOWN_SIGNAL                                    gpio_io   /*!< Signal name */
#define BOARD_INITPINS_SW_DOWN_CHANNEL                                        5U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_SW_DOWN_GPIO                                        GPIO4   /*!< GPIO peripheral base pointer */
#define BOARD_INITPINS_SW_DOWN_GPIO_PIN                                       5U   /*!< GPIO pin number */
#define BOARD_INITPINS_SW_DOWN_GPIO_PIN_MASK                          (1U << 5U)   /*!< GPIO pin mask */
#define BOARD_INITPINS_SW_DOWN_PORT                                        GPIO4   /*!< PORT peripheral base pointer */
#define BOARD_INITPINS_SW_DOWN_PIN                                            5U   /*!< PORT pin number */
#define BOARD_INITPINS_SW_DOWN_PIN_MASK                               (1U << 5U)   /*!< PORT pin mask */

/* GPIO_EMC_06 (coord H5), SW_RESET */
/* Routed pin properties */
#define BOARD_INITPINS_SW_RESET_PERIPHERAL                                 GPIO4   /*!< Peripheral name */
#define BOARD_INITPINS_SW_RESET_SIGNAL                                   gpio_io   /*!< Signal name */
#define BOARD_INITPINS_SW_RESET_CHANNEL                                       6U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITPINS_SW_RESET_GPIO                                       GPIO4   /*!< GPIO peripheral base pointer */
#define BOARD_INITPINS_SW_RESET_GPIO_PIN                                      6U   /*!< GPIO pin number */
#define BOARD_INITPINS_SW_RESET_GPIO_PIN_MASK                         (1U << 6U)   /*!< GPIO pin mask */
#define BOARD_INITPINS_SW_RESET_PORT                                       GPIO4   /*!< PORT peripheral base pointer */
#define BOARD_INITPINS_SW_RESET_PIN                                           6U   /*!< PORT pin number */
#define BOARD_INITPINS_SW_RESET_PIN_MASK                              (1U << 6U)   /*!< PORT pin mask */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitDEBUG_UART(void);

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitSDRAM(void);

#define BOARD_INITCSI_IOMUXC_GPR_GPR26_GPIO_MUX1_GPIO_SEL_MASK 0x10U /*!< GPIO1 and GPIO6 share same IO MUX function, GPIO_MUX1 selects one GPIO function: affected bits mask */

/* GPIO_AD_B1_00 (coord J11), I2C1_SCL/CSI_I2C_SCL/J35[20]/J23[6]/U13[17]/U32[4] */
/* Routed pin properties */
#define BOARD_INITCSI_CSI_I2C_SCL_PERIPHERAL                              LPI2C1   /*!< Peripheral name */
#define BOARD_INITCSI_CSI_I2C_SCL_SIGNAL                                     SCL   /*!< Signal name */

/* GPIO_AD_B1_01 (coord K11), I2C1_SDA/CSI_I2C_SDA/J35[22]/J23[5]/U13[18]/U32[6] */
/* Routed pin properties */
#define BOARD_INITCSI_CSI_I2C_SDA_PERIPHERAL                              LPI2C1   /*!< Peripheral name */
#define BOARD_INITCSI_CSI_I2C_SDA_SIGNAL                                     SDA   /*!< Signal name */

/* GPIO_AD_B0_04 (coord F11), CSI_PWDN/J35[17]/BOOT_MODE[0] */
/* Routed pin properties */
#define BOARD_INITCSI_CSI_PWDN_PERIPHERAL                                  GPIO1   /*!< Peripheral name */
#define BOARD_INITCSI_CSI_PWDN_SIGNAL                                    gpio_io   /*!< Signal name */
#define BOARD_INITCSI_CSI_PWDN_CHANNEL                                        4U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITCSI_CSI_PWDN_GPIO                                        GPIO1   /*!< GPIO peripheral base pointer */
#define BOARD_INITCSI_CSI_PWDN_GPIO_PIN                                       4U   /*!< GPIO pin number */
#define BOARD_INITCSI_CSI_PWDN_GPIO_PIN_MASK                          (1U << 4U)   /*!< GPIO pin mask */
#define BOARD_INITCSI_CSI_PWDN_PORT                                        GPIO1   /*!< PORT peripheral base pointer */
#define BOARD_INITCSI_CSI_PWDN_PIN                                            4U   /*!< PORT pin number */
#define BOARD_INITCSI_CSI_PWDN_PIN_MASK                               (1U << 4U)   /*!< PORT pin mask */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitCSI(void);

#define BOARD_INITLCD_IOMUXC_GPR_GPR27_GPIO_MUX2_GPIO_SEL_MASK 0x80000000U /*!< GPIO2 and GPIO7 share same IO MUX function, GPIO_MUX2 selects one GPIO function: affected bits mask */

/* GPIO_B1_15 (coord B14), USB_HOST_PWR/BACKLIGHT_CTL */
/* Routed pin properties */
#define BOARD_INITLCD_BACKLIGHT_CTL_PERIPHERAL                             GPIO2   /*!< Peripheral name */
#define BOARD_INITLCD_BACKLIGHT_CTL_SIGNAL                               gpio_io   /*!< Signal name */
#define BOARD_INITLCD_BACKLIGHT_CTL_CHANNEL                                  31U   /*!< Signal channel */

/* Symbols to be used with GPIO driver */
#define BOARD_INITLCD_BACKLIGHT_CTL_GPIO                                   GPIO2   /*!< GPIO peripheral base pointer */
#define BOARD_INITLCD_BACKLIGHT_CTL_GPIO_PIN                                 31U   /*!< GPIO pin number */
#define BOARD_INITLCD_BACKLIGHT_CTL_GPIO_PIN_MASK                    (1U << 31U)   /*!< GPIO pin mask */
#define BOARD_INITLCD_BACKLIGHT_CTL_PORT                                   GPIO2   /*!< PORT peripheral base pointer */
#define BOARD_INITLCD_BACKLIGHT_CTL_PIN                                      31U   /*!< PORT pin number */
#define BOARD_INITLCD_BACKLIGHT_CTL_PIN_MASK                         (1U << 31U)   /*!< PORT pin mask */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitLCD(void);

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitCAN(void);

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitENET(void);

/* GPIO_SD_B0_05 (coord J2), SD1_D3 */
/* Routed pin properties */
#define BOARD_INITUSDHC_SD1_D3_PERIPHERAL                                 USDHC1   /*!< Peripheral name */
#define BOARD_INITUSDHC_SD1_D3_SIGNAL                                 usdhc_data   /*!< Signal name */
#define BOARD_INITUSDHC_SD1_D3_CHANNEL                                        3U   /*!< Signal channel */

/* GPIO_SD_B0_04 (coord H2), SD1_D2 */
/* Routed pin properties */
#define BOARD_INITUSDHC_SD1_D2_PERIPHERAL                                 USDHC1   /*!< Peripheral name */
#define BOARD_INITUSDHC_SD1_D2_SIGNAL                                 usdhc_data   /*!< Signal name */
#define BOARD_INITUSDHC_SD1_D2_CHANNEL                                        2U   /*!< Signal channel */

/* GPIO_SD_B0_03 (coord K1), SD1_D1/J24[5]/SPI_MISO */
/* Routed pin properties */
#define BOARD_INITUSDHC_SD1_D1_PERIPHERAL                                 USDHC1   /*!< Peripheral name */
#define BOARD_INITUSDHC_SD1_D1_SIGNAL                                 usdhc_data   /*!< Signal name */
#define BOARD_INITUSDHC_SD1_D1_CHANNEL                                        1U   /*!< Signal channel */

/* GPIO_SD_B0_02 (coord J1), SD1_D0/J24[4]/SPI_MOSI/PWM */
/* Routed pin properties */
#define BOARD_INITUSDHC_SD1_D0_PERIPHERAL                                 USDHC1   /*!< Peripheral name */
#define BOARD_INITUSDHC_SD1_D0_SIGNAL                                 usdhc_data   /*!< Signal name */
#define BOARD_INITUSDHC_SD1_D0_CHANNEL                                        0U   /*!< Signal channel */

/* GPIO_SD_B0_00 (coord J4), SD1_CMD/J24[6] */
/* Routed pin properties */
#define BOARD_INITUSDHC_SD1_CMD_PERIPHERAL                                USDHC1   /*!< Peripheral name */
#define BOARD_INITUSDHC_SD1_CMD_SIGNAL                                 usdhc_cmd   /*!< Signal name */

/* GPIO_SD_B0_01 (coord J3), SD1_CLK/J24[3] */
/* Routed pin properties */
#define BOARD_INITUSDHC_SD1_CLK_PERIPHERAL                                USDHC1   /*!< Peripheral name */
#define BOARD_INITUSDHC_SD1_CLK_SIGNAL                                 usdhc_clk   /*!< Signal name */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitUSDHC(void);

/* GPIO_SD_B1_07 (coord L4), FlexSPI_CLK */
/* Routed pin properties */
#define BOARD_INITHYPERFLASH_FlexSPI_CLK_PERIPHERAL                      FLEXSPI   /*!< Peripheral name */
#define BOARD_INITHYPERFLASH_FlexSPI_CLK_SIGNAL                   FLEXSPI_A_SCLK   /*!< Signal name */

/* GPIO_SD_B1_10 (coord P4), FlexSPI_D2_A */
/* Routed pin properties */
#define BOARD_INITHYPERFLASH_FlexSPI_D2_A_PERIPHERAL                     FLEXSPI   /*!< Peripheral name */
#define BOARD_INITHYPERFLASH_FlexSPI_D2_A_SIGNAL                 FLEXSPI_A_DATA2   /*!< Signal name */

/* GPIO_SD_B1_08 (coord P3), FlexSPI_D0_A */
/* Routed pin properties */
#define BOARD_INITHYPERFLASH_FlexSPI_D0_A_PERIPHERAL                     FLEXSPI   /*!< Peripheral name */
#define BOARD_INITHYPERFLASH_FlexSPI_D0_A_SIGNAL                 FLEXSPI_A_DATA0   /*!< Signal name */

/* GPIO_SD_B1_09 (coord N4), FlexSPI_D1_A */
/* Routed pin properties */
#define BOARD_INITHYPERFLASH_FlexSPI_D1_A_PERIPHERAL                     FLEXSPI   /*!< Peripheral name */
#define BOARD_INITHYPERFLASH_FlexSPI_D1_A_SIGNAL                 FLEXSPI_A_DATA1   /*!< Signal name */

/* GPIO_SD_B1_00 (coord L5), FlexSPI_D3_B */
/* Routed pin properties */
#define BOARD_INITHYPERFLASH_FlexSPI_D3_B_PERIPHERAL                     FLEXSPI   /*!< Peripheral name */
#define BOARD_INITHYPERFLASH_FlexSPI_D3_B_SIGNAL                 FLEXSPI_B_DATA3   /*!< Signal name */

/* GPIO_SD_B1_01 (coord M5), FlexSPI_D2_B */
/* Routed pin properties */
#define BOARD_INITHYPERFLASH_FlexSPI_D2_B_PERIPHERAL                     FLEXSPI   /*!< Peripheral name */
#define BOARD_INITHYPERFLASH_FlexSPI_D2_B_SIGNAL                 FLEXSPI_B_DATA2   /*!< Signal name */

/* GPIO_SD_B1_02 (coord M3), FlexSPI_D1_B */
/* Routed pin properties */
#define BOARD_INITHYPERFLASH_FlexSPI_D1_B_PERIPHERAL                     FLEXSPI   /*!< Peripheral name */
#define BOARD_INITHYPERFLASH_FlexSPI_D1_B_SIGNAL                 FLEXSPI_B_DATA1   /*!< Signal name */

/* GPIO_SD_B1_03 (coord M4), FlexSPI_D0_B */
/* Routed pin properties */
#define BOARD_INITHYPERFLASH_FlexSPI_D0_B_PERIPHERAL                     FLEXSPI   /*!< Peripheral name */
#define BOARD_INITHYPERFLASH_FlexSPI_D0_B_SIGNAL                 FLEXSPI_B_DATA0   /*!< Signal name */

/* GPIO_SD_B1_04 (coord P2), FlexSPI_CLK_B */
/* Routed pin properties */
#define BOARD_INITHYPERFLASH_FlexSPI_CLK_B_PERIPHERAL                    FLEXSPI   /*!< Peripheral name */
#define BOARD_INITHYPERFLASH_FlexSPI_CLK_B_SIGNAL                 FLEXSPI_B_SCLK   /*!< Signal name */

/* GPIO_SD_B1_06 (coord L3), FlexSPI_SS0 */
/* Routed pin properties */
#define BOARD_INITHYPERFLASH_FlexSPI_SS0_PERIPHERAL                      FLEXSPI   /*!< Peripheral name */
#define BOARD_INITHYPERFLASH_FlexSPI_SS0_SIGNAL                  FLEXSPI_A_SS0_B   /*!< Signal name */

/* GPIO_SD_B1_11 (coord P5), FlexSPI_D3_A */
/* Routed pin properties */
#define BOARD_INITHYPERFLASH_FlexSPI_D3_A_PERIPHERAL                     FLEXSPI   /*!< Peripheral name */
#define BOARD_INITHYPERFLASH_FlexSPI_D3_A_SIGNAL                 FLEXSPI_A_DATA3   /*!< Signal name */

/* GPIO_SD_B1_05 (coord N3), FlexSPI_DQS */
/* Routed pin properties */
#define BOARD_INITHYPERFLASH_FlexSPI_DQS_PERIPHERAL                      FLEXSPI   /*!< Peripheral name */
#define BOARD_INITHYPERFLASH_FlexSPI_DQS_SIGNAL                    FLEXSPI_A_DQS   /*!< Signal name */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitHyperFlash(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
