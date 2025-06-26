cmake_minimum_required (VERSION 3.25)
project (WRAPPER DESCRIPTION "Vectorisation Wrapper with Unit tested" LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 23)
add_subdirectory (Catch2)

if (APPLE)
    set (ACCELERATE_SOURCES VectorisationWrappers/Accelerate/AccelerateWrapper.cpp
                            VectorisationWrappers/AccelerateArithmeticUnitTests.cpp
                            VectorisationWrappers/AccelerateUtilitiesUnitTests.cpp
                            VectorisationWrappers/AccelerateRangeUnitTests.cpp)

    add_executable(accelerate_DSP ${ACCELERATE_SOURCES})

    target_link_libraries (accelerate_DSP PRIVATE Catch2::Catch2WithMain "$<LINK_LIBRARY:FRAMEWORK,Accelerate>")
elseif (MSVC)
    message ("No Wrapper")
endif()