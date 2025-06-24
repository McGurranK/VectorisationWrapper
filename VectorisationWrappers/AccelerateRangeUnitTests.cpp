#include <Accelerate/Accelerate.h>
#include "Accelerate/AccelerateRange.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE ("Accelerate Ranges Unit tests", "[Accelerate Ranges]")
{
    const auto bufferSize = 256;
    const auto minimumIndex = 2;
    const auto maximumIndex = 18;

    const auto minValue = -1.f;
    const auto maxValue = 1.f;


    std::vector<float> buffer (bufferSize);
    buffer.assign (bufferSize, 0.f);

    buffer.at (minimumIndex) = minValue;
    buffer.at (maximumIndex) = maxValue;

    SECTION ("Minimum Value")
    {
        auto outputValue = -10.f;
        Vectorised::Range::minimumValue (buffer.data(), bufferSize, outputValue);
        REQUIRE (outputValue == minValue);
    }

    SECTION ("Minimum Value with Index")
    {
        auto outputValue = -10.f;
        auto range = -1;
        Vectorised::Range::minimumValueIndex (buffer.data(), bufferSize, outputValue, range);
        REQUIRE (outputValue == minValue);
        REQUIRE (range == minimumIndex);
    }
}