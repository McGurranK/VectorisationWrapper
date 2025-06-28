cmake_minimum_required (VERSION 3.25)

project (WRAPPER DESCRIPTION "Vectorisation Wrapper with Unit tested" LANGUAGES CXX)

option(ENABLE_TESTS "Build unit tests" OFF)

set (CMAKE_CXX_STANDARD 23)

if (APPLE)
    add_library (VECTORISATION_WRAPPER STATIC VectorisationWrappers/Accelerate/AccelerateWrapper.cpp)
    target_include_directories (VECTORISATION_WRAPPER PUBLIC ${PROJECT_SOURCE_DIR}/VectorisationWrappers/Accelerate/)

    if (ENABLE_TESTS)
        # Todo: fetch catch for tests

        add_subdirectory (Catch2)
        set (ACCELERATE_SOURCES
                VectorisationWrappers/Accelerate/AccelerateWrapper.cpp
                VectorisationWrappers/Accelerate/Tests/AccelerateArithmeticUnitTests.cpp
                VectorisationWrappers/Accelerate/Tests/AccelerateUtilitiesUnitTests.cpp
                VectorisationWrappers/Accelerate/Tests/AccelerateRangeUnitTests.cpp
                VectorisationWrappers/Accelerate/Tests/AccelerateTrigonometryUnitTests.cpp)

        add_executable(accelerate_DSP ${ACCELERATE_SOURCES})

        target_link_libraries (accelerate_DSP PRIVATE Catch2::Catch2WithMain "$<LINK_LIBRARY:FRAMEWORK,Accelerate>")
    endif ()

elseif (MSVC)
    message ("No Wrapper")
endif()