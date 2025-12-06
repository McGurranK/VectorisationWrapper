#pragma once
#include <concepts>
#include <vector>

namespace VIVI::AudioBasics
{
    // Buffers have been configured to be one continuous block of memory
    template <std::floating_point SamplePtrType>
    class VIVIChannelPtr
    {
    public:
        explicit VIVIChannelPtr() = default;

        void prepare (std::vector<SamplePtrType*>& samples)
        {
            channelPtrBuffer = std::move(samples);
        }

        SamplePtrType* operator[] (const int channelIndex)
        {
            const auto numChannels = channelPtrBuffer.size();

            // You are access invalid memory
            assert (channelIndex < numChannels);
            return channelPtrBuffer[channelIndex];
        }

    private:
        std::vector<SamplePtrType*> channelPtrBuffer;
    };

};