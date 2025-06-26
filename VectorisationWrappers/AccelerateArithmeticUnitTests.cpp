// Unit tests for VDSP WRAPPER

#include "Accelerate/AccelerateWrapper.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_template_test_macros.hpp>

TEMPLATE_TEST_CASE ("VDSP wrapper testing", "[VDSP Wrapper]", float, double)
{
    using T = TestType;

    constexpr auto bufferSize = 1024;

    std::vector<T> BufferA (bufferSize);
    std::vector<T> BufferB (bufferSize);

    BufferA.assign (bufferSize, 0.0f);
    BufferB.assign (bufferSize, 1.0f);

    SECTION ("Addition Test")
    {
        Vectorised::additionVectorised (BufferA.data(), BufferB.data(), BufferB.data(), bufferSize);

        for (const auto& value : BufferB)
        {
            REQUIRE (value == static_cast<T>(1));
        }
    }

    SECTION ("Subtraction Test")
    {
        BufferA.assign (bufferSize, 4.0f);
        BufferB.assign (bufferSize, 5.0f);

        Vectorised::subtractionVectorised (BufferA.data(), BufferB.data(), BufferB.data(), bufferSize);

        for (const auto& value : BufferB)
        {
            REQUIRE (value == static_cast<T>(1));
        }
    }

    SECTION ("Multiplication Test")
    {
        BufferA.assign (bufferSize, 2.0f);
        BufferB.assign (bufferSize, 1.0f);

       Vectorised::multiplicationVectorised (BufferA.data(), BufferB.data(), BufferB.data(), bufferSize);

        for (const auto& value : BufferB)
        {
            REQUIRE (value == static_cast<T>(2));
        }
    }

    SECTION ("Division Test")
    {
        BufferA.assign (bufferSize, 2.0f);
        BufferB.assign (bufferSize, 2.0f);

        Vectorised::divisionVectorised (BufferA.data(), BufferB.data(), BufferB.data(), bufferSize);

        for (const auto& value : BufferB)
        {
            REQUIRE (value == static_cast<T>(1));
        }
    }
}