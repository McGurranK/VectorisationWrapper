
SCENARIO("VIVI channel pointer", "[Normal BS]")
{
    GIVEN("Buffer")
    {
        VIVI::AudioBasics::VIVIChannelPtr<float> channelPtr;

        WHEN("Preparing with float** context")
        {
            std::vector<float> values { 1.f, 2.f, 3.f, 4.f };
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
            std::vector<float> values { 1.f, 2.f, 3.f, 4.f };
            std::vector<float*> channelPointer { &values[0], nullptr };

            THEN("Success")
            {
                channelPtr.prepare (channelPointer.data(),channelPointer.size());
            }
        }
    }

}




// TEMPLATE_TEST_CASE ("Channel Pointer Testing", "[VIVI Pointer]", float, double)
// {
//     VIVI::AudioBasics::VIVIChannelPtr<TestType> channelPtr;
//
//     // std::vector<t> typeBuffer;
//     // typeBuffer.push_back(1);
//     // typeBuffer.push_back(2);
//     // typeBuffer.push_back(3);
//     //
//     // SECTION ("preparing channel pointers")
//     // {
//     //     // Needs a runtime check and throw
//     //     std::vector<t*> channel;
//     //     channel.push_back(&typeBuffer[0]);
//     //     channel.push_back(&typeBuffer[1]);
//     //     channel.push_back(&typeBuffer[2]);
//     //
//     //     channelPtr.prepare(channel);
//     //
//     //     const auto numberOfChannels = channelPtr.getNumberChannels();
//     //
//     //     REQUIRE (numberOfChannels == 3);
//     //     REQUIRE (*channelPtr[0] == static_cast<t>(1));
//     //     REQUIRE (*channelPtr[1] == static_cast<t>(2));
//     //     REQUIRE (*channelPtr[2] == static_cast<t>(3));
//     //     REQUIRE (channelPtr[0][1] == static_cast<t>(2));
//     //     REQUIRE (channelPtr[0][2] == static_cast<t>(3));
//     // }
// }