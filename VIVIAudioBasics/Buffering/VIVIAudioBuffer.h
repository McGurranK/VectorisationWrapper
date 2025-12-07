#pragma once
#include <vector>

namespace VIVI::AudioBasics
{
    // None owning audio buffer vector which is useful to avoid
    template <std::floating_point SampleType>
    class VIVIAudioBuffer final
    {
    public:
        VIVIAudioBuffer (SampleType** SampleData, int NumChannels, int NumSamples)
        {
            channelPointer.prepare (SampleData, NumChannels);
        }

        const float* const* getChannelsReadPointer (const unsigned int ChannelIndex)
        {
            return channelPointer.getChannelPtr (ChannelIndex);
        }

        float* const* getChannelsWritePointer (const unsigned int ChannelIndex)
        {
            return channelPointer.getChannelPtr (ChannelIndex);
        }

    private:
        VIVIChannelPtr<SampleType> channelPointer;
    };
}
