// Unit tests for VDSP WRAPPER

#include <Accelerate/Accelerate.h>
#include "Accelerate/AccelerateWrapper.h"
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_template_test_macros.hpp>


TEMPLATE_TEST_CASE ("VDSP wrapper testing", "[VDSP Wrapper]", float, double)
{
    using T = TestType;

    constexpr auto bufferSize = 1024;

    std::vector<T> input (bufferSize);
    std::vector<T> output (bufferSize);

    input.assign (bufferSize, 0.0f);
    output.assign (bufferSize, 1.0f);

    SECTION ("Addition Test")
    {
        Vectorised::additionVectorised (input.data(), output.data(), bufferSize);

        for (const auto& value : output)
        {
            REQUIRE (value == static_cast<T>(1));
        }
    }

    SECTION ("Subtraction Test")
    {
        input.assign (bufferSize, 5.0f);
        output.assign (bufferSize, 4.0f);

        // Todo: This call order is confusing
        Vectorised::subtractionVectorised (output.data(), input.data(), bufferSize);

        for (const auto& value : output)
        {
            REQUIRE (value == static_cast<T>(1));
        }
    }

    SECTION ("Multiplication Test")
    {
        input.assign (bufferSize, 2.0f);
        output.assign (bufferSize, 1.0f);

        // Todo: Order is confusing
       Vectorised::multiplicationVectorised (input.data(), output.data(), bufferSize);

        for (const auto& value : input)
        {
            REQUIRE (value == static_cast<T>(2));
        }
    }

    SECTION ("Division Test")
    {
        input.assign (bufferSize, 2.0f);
        output.assign (bufferSize, 2.0f);

        // Todo: Function input confusing
        Vectorised::divisionVectorised (input.data(), output.data(), bufferSize);

        for (const auto& value : input)
        {
            REQUIRE (value == static_cast<T>(1));
        }
    }
    
    // SECTION ("Division Test")
    // {
    //     Vectorised::tanhVectorised (input.data(), output.data(), 256);
    // }
    //
    // SECTION ("Division Test")
    // {
    //     Vectorised::sineVectorised (input.data(), 256);
    // }
    //
    // SECTION ("Division Test")
    // {
    //     const auto lowerLimit = -1.f;
    //     const auto upperLimit = -1.f;
    //
    //     Vectorised::hardClipVectorised (input.data(), output.data(), 256, &lowerLimit, &upperLimit);
    // }
}