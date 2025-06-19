#pragma once

#include <Accelerate/Accelerate.h>

// VDSP wrapper namespace in a vectorised way
namespace Vectorised
{
    // Vectorised Addition function for VDSP
    template <typename T>
    static void additionVectorised (T* BufferA, const T* BufferB, const int BufferSize)
    {
        if constexpr (std::is_same_v<T, float>)
            vDSP_vadd (BufferA, 1, BufferB, 1, BufferA, 1, BufferSize);
        else if constexpr (std::is_same_v<T, double>)
            vDSP_vaddD (BufferA, 1, BufferB, 1, BufferA, 1, BufferSize);
        else
            static_assert (sizeof(T) == 0, "Unsupported type for addition");
    }

    // Vectorised Addition function for VDSP
    template <typename T>
    static void subtractionVectorised (T* BufferA, const T* BufferB, const int BufferSize)
    {
        if constexpr (std::is_same_v<T, float>)
            vDSP_vsub (BufferA, 1, BufferB, 1, BufferA, 1, BufferSize);
        else if constexpr (std::is_same_v<T, double>)
            vDSP_vsubD (BufferA, 1, BufferB, 1, BufferA, 1, BufferSize);
        else
            static_assert (sizeof(T) == 0, "Unsupported type for addition");
    }

    // Vectorised Multiplication function using vdsp
    template <typename T>
    static void multiplicationVectorised(T* BufferA, const T* BufferB, const int BufferSize)
    {
        if constexpr (std::is_same_v<T, float>)
            vDSP_vmul (BufferA, 1, BufferB, 1, BufferA, 1, BufferSize);
        else if constexpr (std::is_same_v<T, double>)
            vDSP_vmulD (BufferA, 1, BufferB, 1, BufferA, 1, BufferSize);
        else
            static_assert (sizeof(T) == 0, "Unsupported type for addition");
    }

    template <typename T>
    static void scalerMultiplication (T* InputBuffer, T* OutputBuffer, const int BufferSize, const int InputStride = 1, const int OutputStride = 1)
    {
        if constexpr (std::is_same_v<T, float>)
            VDSP_vscal (InputBuffer, InputStride, OutputBuffer, OutputStride, BufferSize);
        else if constexpr (std::is_same_v<T, double>)
            VDSP_vscalD (InputBuffer, InputStride, OutputBuffer, OutputStride, BufferSize);
    }

    template <typename T>
    static void fillBuffer (T* ValueToFill, T* Buffer, const int BufferSize, const int BufferStride = 1)
    {
        if constexpr (std::is_same_v<T, float>)
            VDSP_vfill (ValueToFill, Buffer, BufferStride, BufferSize);
        else if constexpr (std::is_same_v<T, double>)
            VDSP_vfill (ValueToFill, Buffer, BufferStride, BufferSize);
    }

    template <typename T>
    static void divisionVectorised (T* OutputPtr, T* InputPtr, const int BufferSize)
    {
        if constexpr (std::is_same_v<T, float>)
            vvdivf (OutputPtr, InputPtr, OutputPtr, &BufferSize);
        else if constexpr (std::is_same_v<T, double>)
            vvdiv (OutputPtr, InputPtr, OutputPtr, &BufferSize);
    }


    // Vectorised tanh function for VDSP
    template <typename T>
    static void tanhVectorised (const T* InputBuffer, T* OutputBuffer, const int BufferSize)
    {
        if constexpr (std::is_same_v<T, float>)
            vvtanhf (OutputBuffer, InputBuffer, &BufferSize);
        else if constexpr (std::is_same_v<T, double>)
            vvtanh (OutputBuffer, InputBuffer, &BufferSize);
        else
            static_assert (sizeof(T) == 0, "Unsupported type for tanh");
    }

    // Vectorised tanh function for hard clipping
    template <typename T>
    static void hardClipVectorised(const T* InputBuffer, T* OutputBuffer, const int BufferSize, const T* ClipLowerLimit, const T* ClipUpperLimit)
    {
        if constexpr (std::is_same_v<T, float>)
            vDSP_vclip(InputBuffer, 1, ClipLowerLimit, ClipUpperLimit, OutputBuffer, 1, BufferSize);
        else if constexpr (std::is_same_v<T, double>)
            vDSP_vclipD(InputBuffer, 1, ClipLowerLimit, ClipUpperLimit, OutputBuffer, 1, BufferSize);
        else
            static_assert (sizeof(T) == 0, "Unsupported type for hard clipping");
    }

    // Vectorised tanh function for sine
    template <typename T>
    static void sineVectorised (T* InputBuffer, const int BufferSize)
    {
        if constexpr (std::is_same_v<T, float>)
            vvsinf (InputBuffer, InputBuffer, &BufferSize);
        else if constexpr  (std::is_same_v<T, double>)
            vvsin (InputBuffer, InputBuffer, &BufferSize);
        else
            static_assert (sizeof(T) == 0, "Unsupported type for sine");
    }
};