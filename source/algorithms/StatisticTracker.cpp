#include "StatisticTracker.h"
#include <vector>
#include <span>

namespace freesthetics {

StatisticTracker::StatisticTracker(float timeResolution, float memoryLength, float32_t resetValue, float32_t startValue, float fs, uint32_t samplesPerCycle, uint32_t outlierCounter)
    :   resetValue(resetValue), 
        binDurationC(static_cast<uint32_t>(timeResolution * fs / samplesPerCycle)), 
        nBins(static_cast<uint32_t>(memoryLength / timeResolution)),
        cycleCounter(0),
        outlierCounter(outlierCounter),
        bins(nBins, startValue), 
        sortedBins(nBins)
{
    arm_sort_init_f32(&sortInstance, ARM_SORT_INSERTION, ARM_SORT_ASCENDING);
    assert(nBins > 2 * outlierCounter);
}

float32_t StatisticTracker::update(std::span<const float32_t> data)
{
    // Update elements in current bin (bins[0])
    float32_t result = 0;
    result = statistic(data);
    float32_t values[2] = {result, bins[0]};
    bins[0] = statistic(values);

    // shift bins if necessary and reset last bin
    if ((cycleCounter % binDurationC) == 0)
    {
        cycleCounter = 0;
        for (size_t i = nBins - 1; i > 0; i--)
        {
            bins[i] = bins[i - 1];
        }
        bins[0] = resetValue;
    }

    // calculate result
    arm_sort_f32(&sortInstance, bins.data(), sortedBins.data(), nBins);
    std::span<float32_t> subSpan {&sortedBins[outlierCounter], &sortedBins[nBins - outlierCounter]};
    result = statistic(subSpan);
    return result;
}

// Implement the derived classes here

} // namespace freesthetics