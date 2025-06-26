cmake_minimum_required (VERSION 3.25)
project (WRAPPER DESCRIPTION "Vectoisation Wrapper with Unit tested" LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 23)
add_subdirectory (Catch2)

if (APPLE)
    add_executable (accelerate_DSP VectorisationWrappers/Accelerate/AccelerateArithmetic.h
                                    VectorisationWrappers/Accelerate/AccelerateRange.h
                                    VectorisationWrappers/Accelerate/AccelerateUtilities.h
                                    VectorisationWrappers/AccelerateArithmeticUnitTests.cpp
                                    VectorisationWrappers/AccelerateUtilitiesUnitTests.cpp
                                    VectorisationWrappers/AccelerateRangeUnitTests.cpp)

    target_link_libraries (accelerate_DSP PRIVATE Catch2::Catch2WithMain "$<LINK_LIBRARY:FRAMEWORK,Accelerate>")
ELSEIF (MSVC)
    message ("No Wrapper is availble")
ENDIF()