#include "Accelerate/AccelerateUtilities.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_template_test_macros.hpp>

TEMPLATE_TEST_CASE("Accelerate Ranges Unit Tests", "[Accelerate Ranges]", float, double)
{
    using T = TestType;

    std::vector<T> inputBuffer;
    std::vector<T> outputBuffer;



    SECTION("Accelerate Abs Values")
    {    }

    SECTION ("Accelerate Fill Buffer")
    {
        T valueToFill = 1.0;
        Vectorised::Utilities::fillBuffer (&valueToFill, inputBuffer.data(), 256);
    }

    SECTION ("Accelerate Zero Buffer")
    {

        Vectorised::Utilities::zeroBuffer (inputBuffer.data(), 256);
    }

    SECTION ("Accelerate Scale Buffer")
    {
        Vectorised::Utilities::scalerMultiplication (inputBuffer.data(), outputBuffer.data(), 256);
    }
}