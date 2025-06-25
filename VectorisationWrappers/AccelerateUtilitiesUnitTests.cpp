#include "Accelerate/AccelerateUtilities.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_template_test_macros.hpp>

TEMPLATE_TEST_CASE("Accelerate Ranges Unit Tests", "[Accelerate Ranges]", float, double)
{
    using T = TestType;

    constexpr auto bufferSize = 1024;

    std::vector<T> inputBuffer (bufferSize);
    std::vector<T> outputBuffer (bufferSize);

    inputBuffer.assign (bufferSize, static_cast<T>(0));
    outputBuffer.assign (bufferSize, static_cast<T>(2));


    SECTION("Accelerate Abs Values")
    {    }

    SECTION ("Accelerate Fill Buffer")
    {
        T valueToFill = 1.0;
        Vectorised::Utilities::fillBuffer (&valueToFill, inputBuffer.data(), bufferSize);

        for (const auto& Value : inputBuffer)
        {
            REQUIRE (Value == valueToFill);
        }
    }

    SECTION ("Accelerate Zero Buffer")
    {
        Vectorised::Utilities::zeroBuffer (outputBuffer.data(), bufferSize);

        for (const auto& Value : inputBuffer)
        {
            REQUIRE (Value == static_cast<T>(0));
        }
    }

    SECTION ("Accelerate Scale Buffer")
    {
        // Vectorised::Utilities::scalerMultiplication (inputBuffer.data(), outputBuffer.data(), 256);
    }
}