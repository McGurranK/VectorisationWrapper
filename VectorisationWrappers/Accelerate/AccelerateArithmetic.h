#pragma once

#include <Accelerate/Accelerate.h>

// VDSP wrapper namespace in a vectorised way
namespace Vectorised
{
    // Vectorised Addition function for VDSP
    template <typename T>
    static void additionVectorised (const T* BufferA, const T* BufferB, T* OutputBuffer, const int BufferSize, const int BufferAStride = 1, const int BufferBStride = 1, const int OutputStride = 1)
    {
        if constexpr (std::is_same_v<T, float>)
            vDSP_vadd (BufferA, BufferAStride, BufferB, BufferBStride, OutputBuffer, OutputStride, BufferSize);
        else if constexpr (std::is_same_v<T, double>)
            vDSP_vaddD (BufferA, BufferAStride, BufferB, BufferBStride, OutputBuffer, OutputStride, BufferSize);
        else
            static_assert (sizeof(T) == 0, "Unsupported type for addition");
    }

    // Vectorised Addition function for VDSP
    template <typename T>
    static void subtractionVectorised (const T* BufferA, const T* BufferB, T* OutputBuffer, const int BufferSize, const int BufferAStride = 1, const int BufferBStride = 1, const int OutputStride = 1)
    {
        if constexpr (std::is_same_v<T, float>)
            vDSP_vsub (BufferA, BufferAStride, BufferB, BufferBStride, OutputBuffer, OutputStride, BufferSize);
        else if constexpr (std::is_same_v<T, double>)
            vDSP_vsubD (BufferA, BufferAStride, BufferB, BufferBStride, OutputBuffer, OutputStride, BufferSize);
        else
            static_assert (sizeof(T) == 0, "Unsupported type for addition");
    }

    // Vectorised Multiplication function using vdsp
    template <typename T>
    static void multiplicationVectorised (const T* BufferA, const T* BufferB, T* OutputBuffer, const int BufferSize, const int BufferAStride = 1, const int BufferBStride = 1, const int OutputStride = 1)
    {
        if constexpr (std::is_same_v<T, float>)
            vDSP_vmul (BufferA, BufferAStride, BufferB, BufferBStride, OutputBuffer, OutputStride, BufferSize);
        else if constexpr (std::is_same_v<T, double>)
            vDSP_vmulD (BufferA, BufferAStride, BufferB, BufferBStride, OutputBuffer, OutputStride, BufferSize);
        else
            static_assert (sizeof(T) == 0, "Unsupported type for addition");
    }

    template <typename T>
    static void divisionVectorised (const T* BufferA, const T* BufferB, T* OutputBuffer, const int BufferSize)
    {
        if constexpr (std::is_same_v<T, float>)
            vvdivf (OutputBuffer, BufferA, BufferB, &BufferSize);
        else if constexpr (std::is_same_v<T, double>)
            vvdiv (OutputBuffer, BufferA, BufferB, &BufferSize);
    }
};