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

    SECTION ("Tan Function Tests")
    {
        auto tanValue = static_cast<T> (std::tan (1.f));

        Vectorised::Trigonometry::tanVectorised (workingBuffer.data(), workingBuffer.data(), bufferSize);

        for (const auto& value : workingBuffer)
        {
            REQUIRE (value == Catch::Approx (tanValue));
        }
    }

    SECTION ("Arcsin Function Tests")
    {
        auto asinValue = static_cast<T> (std::asin (1.f));

        Vectorised::Trigonometry::arcSinVectorised (workingBuffer.data(), workingBuffer.data(), bufferSize);

        for (const auto& value : workingBuffer)
        {
            REQUIRE (value == Catch::Approx (asinValue));
        }
    }

    SECTION ("Arccos Function Tests")
    {
        auto aCosValue = static_cast<T> (std::acos (1.f));

        Vectorised::Trigonometry::arcCosVectorised (workingBuffer.data(), workingBuffer.data(), bufferSize);

        for (const auto& value : workingBuffer)
        {
            REQUIRE (value == Catch::Approx (aCosValue));
        }
    }

    SECTION ("ArcTan Function Tests")
    {
        auto aTanValue = static_cast<T> (std::atan (1.f));

        Vectorised::Trigonometry::arcTanVectorised (workingBuffer.data(), workingBuffer.data(), bufferSize);

        for (const auto& value : workingBuffer)
        {
            REQUIRE (value == Catch::Approx (aTanValue));
        }
    }

    SECTION ("Sinh Function Tests")
    {
        const auto sinhValue = static_cast<T> (std::sinh (1.f));

        Vectorised::Trigonometry::sinhVectorised (workingBuffer.data(), workingBuffer.data(), bufferSize);

        for (const auto& value : workingBuffer)
        {
            REQUIRE (value == Catch::Approx (sinhValue));
        }
    }

    SECTION ("Cosh Function Tests")
    {
        const auto coshValue = static_cast<T> (std::cosh (1.f));

        Vectorised::Trigonometry::coshVectorised (workingBuffer.data(), workingBuffer.data(), bufferSize);

        for (const auto& value : workingBuffer)
        {
            REQUIRE (value == Catch::Approx (coshValue));
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

    SECTION ("Inverse Hyperbolic Cosine Function Tests")
    {
        workingBuffer.assign (bufferSize, static_cast<T> (2));
        const auto compareValue = static_cast<T> (std::asinh (2));

        Vectorised::Trigonometry::inverseSinhVectorised (workingBuffer.data(), workingBuffer.data(), bufferSize);

        for (const auto& value : workingBuffer)
        {
            REQUIRE (value == Catch::Approx (compareValue));
        }
    }

    SECTION ("Inverse Hyperbolic Cosine Function Tests")
    {
        workingBuffer.assign (bufferSize, static_cast<T> (2));
        const auto compareValue = static_cast<T> (std::acosh (2));

        Vectorised::Trigonometry::inverseCoshVectorised (workingBuffer.data(), workingBuffer.data(), bufferSize);

        for (const auto& value : workingBuffer)
        {
            REQUIRE (value == Catch::Approx (compareValue));
        }
    }

    SECTION ("Inverse Hyperbolic Tangent Function Tests")
    {
        workingBuffer.assign (bufferSize, static_cast<T> (0.8));
        const auto compareValue = static_cast<T> (std::atanh (0.8));

        Vectorised::Trigonometry::inverseTanhVectorised (workingBuffer.data(), workingBuffer.data(), bufferSize);

        for (const auto& value : workingBuffer)
        {
            REQUIRE (value == Catch::Approx (compareValue));
        }
    }

    SECTION ("Sigmoid Function Tests")
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