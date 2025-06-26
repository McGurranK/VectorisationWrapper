#include "Accelerate/AccelerateWrapper.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_template_test_macros.hpp>

TEMPLATE_TEST_CASE("Accelerate Ranges Unit Tests", "[Accelerate Ranges]", float, double)
{
    using T = TestType;

    constexpr auto bufferSize = 256;
    constexpr auto minimumIndex = 2;
    constexpr auto maximumIndex = 18;

    const T minValue = static_cast<T>(-1.0);
    const T maxValue = static_cast<T>(1.0);

    std::vector<T> buffer(bufferSize, static_cast<T>(0));

    buffer.at(minimumIndex) = minValue;
    buffer.at(maximumIndex) = maxValue;

    SECTION("Minimum Value")
    {
        T outputValue = static_cast<T>(-10.0);
        Vectorised::Range::minimumValue(buffer.data(), bufferSize, outputValue);
        REQUIRE(outputValue == minValue);
    }

    SECTION("Minimum Value with Index")
    {
        T outputValue = static_cast<T>(-10.0);
        int index = -1;
        Vectorised::Range::minimumValueIndex(buffer.data(), bufferSize, outputValue, index);
        REQUIRE(outputValue == minValue);
        REQUIRE(index == minimumIndex);
    }

    SECTION("Maximum Value")
    {
        T outputValue = static_cast<T>(-10.0);
        Vectorised::Range::maximumValue(buffer.data(), bufferSize, outputValue);
        REQUIRE(outputValue == maxValue);
    }

    SECTION("Maximum Value with Index")
    {
        T outputValue = static_cast<T>(-10.0);
        int index = -1;
        Vectorised::Range::maximumValueIndex(buffer.data(), bufferSize, outputValue, index);
        REQUIRE(outputValue == maxValue);
        REQUIRE(index == maximumIndex);
    }
}
