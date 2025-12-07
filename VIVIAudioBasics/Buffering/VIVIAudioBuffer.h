#pragma once
#include <vector>

namespace VIVI::AudioBasics
{
    template <std::floating_point SampleType>
    class VIVIAudioBuffer final
    {
    public:
        VIVIAudioBuffer (SampleType** SampleData, int NumChannels, int NumSamples)
        {
            channelPointer.prepare (SampleData, NumChannels);
        }


    private:
        VIVIChannelPtr<SampleType> channelPointer;
    };
}
