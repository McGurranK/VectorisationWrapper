#pragma once
#include <concepts>
#include <vector>
#include <span>

namespace VIVI::AudioBasics
{
    // Non-owning channel Pointer class for audio buffers
    template <std::floating_point SamplePtrType>
    class VIVIChannelPtr
    {
    public:
        explicit VIVIChannelPtr() = default;

        void prepare(SamplePtrType** ChannelPtr, int NumberOfChannels)
        {
            assert (ChannelPtr && "ChannelPtr is null");
            assert (NumberOfChannels > 0 && "NumberOfChannels must be positive");

            for (int i = 0; i < NumberOfChannels; ++i)
                assert(ChannelPtr[i] && "Channel pointer at index is null");

            channelPtrBuffer = std::span<SamplePtrType*>(ChannelPtr, NumberOfChannels);
        }

        SamplePtrType* operator[] (const unsigned int channelIndex)
        {
            const auto spanEmpty = channelPtrBuffer.empty();
            const auto numChannels = channelPtrBuffer.size();

            if (spanEmpty || numChannels <= channelIndex)
            {
                assert(spanEmpty && "Invalid channel context");
                return nullptr;
            }

            return channelPtrBuffer [channelIndex];
        }

        SamplePtrType** getChannelPtr() noexcept
        {
            // Invalid channel configuration
            assert (channelPtrBuffer.empty());
            return channelPtrBuffer.data();
        }

        [[nodiscard]] int getNumberChannels() const
        {
            return static_cast<int>(channelPtrBuffer.size());
        }

    private:
        std::span<SamplePtrType*> channelPtrBuffer;
    };

};