// Unit tests for VDSP WRAPPER

#include <Accelerate/Accelerate.h>
#include "Accelerate/AccelerateWrapper.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("VDSP wrapper testing", "[VDSP Wrapper]")
{
    std::vector<float> input (256);
    std::vector<float> output (256);

    input.assign (256, 0.0f);
    output.assign (256, 1.0f);

    SECTION ("Addition Test")
    {
        Vectorised::additionVectorised (input.data(), output.data(), 256);

        for (const auto buffer : { &input, &output })
        {
            for (const auto SampleValue : *buffer)
                REQUIRE (SampleValue == 1.f);
        }
    }

    SECTION ("Subtraction Test")
    {
        Vectorised::subtractionVectorised (input.data(), output.data(), 256);

        for (const auto buffer : { &input, &output })
        {
            for (const auto SampleValue : *buffer)
                REQUIRE (SampleValue == 0.f);
        }
    }

    SECTION ("Multiplication Test")
    {
       Vectorised::multiplicationVectorised (input.data(), output.data(), 256);
    }

    SECTION ("Division Test")
    {
        Vectorised::divisionVectorised (input.data(), output.data(), 256);
    }

    SECTION ("Division Test")
    {
        Vectorised::tanhVectorised (input.data(), output.data(), 256);
    }

    SECTION ("Division Test")
    {
        Vectorised::sineVectorised (input.data(), 256);
    }

    SECTION ("Division Test")
    {
        const auto lowerLimit = -1.f;
        const auto upperLimit = -1.f;

        Vectorised::hardClipVectorised (input.data(), output.data(), 256, &lowerLimit, &upperLimit);
    }
}