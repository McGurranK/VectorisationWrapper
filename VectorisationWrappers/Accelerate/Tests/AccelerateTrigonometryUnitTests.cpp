#include "../AccelerateWrapper.h"
#include <cmath>
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_template_test_macros.hpp>
#include <catch2/catch_approx.hpp>

TEMPLATE_TEST_CASE("Accelerate Trigonometry Unit Testing", "[Accelerate Trigonometry]", float, double)
{
    using T = TestType;

    constexpr auto bufferSize = 1024;

    std::vector<T> workingBuffer (bufferSize);
    workingBuffer.assign (bufferSize, static_cast<T>(1));

    SECTION ("Sine Function Tests")
    {
        auto sinValue = static_cast<T> (std::sin (1.f));

        Vectorised::Trigonometry::sineVectorised (workingBuffer.data(), workingBuffer.data(), bufferSize);

        for (const auto& value : workingBuffer)
        {
            REQUIRE (value == Catch::Approx (sinValue));
        }
    }

    SECTION ("Cos Function Tests")
    {
        auto cosValue = static_cast<T> (std::cos (1.f));

        Vectorised::Trigonometry::cosVectorised (workingBuffer.data(), workingBuffer.data(), bufferSize);

        for (const auto& value : workingBuffer)
        {
            REQUIRE (value == Catch::Approx (cosValue));
        }
    }

    SECTION ("Tanh Function Tests")
    {
        workingBuffer.assign (bufferSize, static_cast<T> (10));
        const auto tanhValue = static_cast<T> (std::tanh (10.f));

        Vectorised::Trigonometry::tanhVectorised (workingBuffer.data(), workingBuffer.data(), bufferSize);

        for (const auto& value : workingBuffer)
        {
            REQUIRE (value == Catch::Approx (tanhValue));
        }
    }

    SECTION ("Sigmud Function Tests")
    {
        const auto minValue = static_cast<T>(-1);
        const auto maxValue = static_cast<T>(1);

        workingBuffer.assign (bufferSize, static_cast<T> (-10));
        Vectorised::Trigonometry::hardClipVectorised (workingBuffer.data(), workingBuffer.data(), bufferSize, &minValue, &maxValue);

        for (const auto& value : workingBuffer)
        {
            REQUIRE (value == Catch::Approx (minValue));
        }

        workingBuffer.assign (bufferSize, static_cast<T> (10));
        Vectorised::Trigonometry::hardClipVectorised (workingBuffer.data(), workingBuffer.data(), bufferSize, &minValue, &maxValue);

        for (const auto& value : workingBuffer)
        {
            REQUIRE (value == Catch::Approx (maxValue));
        }
    }
}