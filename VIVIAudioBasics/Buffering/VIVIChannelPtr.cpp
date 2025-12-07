
SCENARIO("VIVI channel pointer", "[Normal BS]")
{
    GIVEN("Buffer")
    {
        VIVI::AudioBasics::VIVIChannelPtr<float> channelPtr;
        std::vector<float> values { 1.f, 2.f, 3.f, 4.f };

        WHEN("Preparing with float** context")
        {
            std::vector<float*> channelPointer { &values[0], &values[1] };

            THEN("Success")
            {
                channelPtr.prepare (channelPointer.data(),channelPointer.size());
                REQUIRE (channelPtr[0] == &values[0]);
                REQUIRE (channelPtr[1] == &values[1]);
                REQUIRE (channelPtr.getNumberChannels() == channelPointer.size());
            }
        }

        WHEN ("Gave invalid context")
        {
            std::vector<float*> channelPointer { &values[0], nullptr };

            THEN("Success")
            {
                channelPtr.prepare (channelPointer.data(),channelPointer.size());
            }
        }
    }

}