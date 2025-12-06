
TEMPLATE_TEST_CASE ("Channel Pointer Testing", "[VIVI Pointer]", float, double)
{
    VIVI::AudioBasics::VIVIChannelPtr<TestType> channel_Ptr;

    SECTION ("Addition Test")
    {
        // Needs a runtime check and throw
        std::vector<TestType*> channel;
        channel.push_back(new TestType);
        channel.push_back(new TestType);
        channel.push_back(new TestType);

        channel_Ptr.prepare(channel);
        REQUIRE (1);
    }
}