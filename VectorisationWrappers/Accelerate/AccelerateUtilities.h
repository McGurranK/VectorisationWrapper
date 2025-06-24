#pragma once
#include <Accelerate/Accelerate.h>

// VDSP wrapper namespace in a vectorised way
namespace Vectorised::Utilities
{
    template <typename T>
    static void scalerMultiplication (T* InputBuffer, T* OutputBuffer, const int BufferSize, const int InputStride = 1, const int OutputStride = 1)
    {
        if constexpr (std::is_same_v<T, float>)
            VDSP_vscal (InputBuffer, InputStride, OutputBuffer, OutputStride, BufferSize);
        else if constexpr (std::is_same_v<T, double>)
            VDSP_vscalD (InputBuffer, InputStride, OutputBuffer, OutputStride, BufferSize);
    }

    template <typename T>
    static void absBuffer (T* InputBuffer, T*  OutputBuffer, const int BufferSize, const int InputStride = 1, const int OutputStride = 1)
    {
        if constexpr (std::is_same_v<T, float>)
            vDSP_abs (InputBuffer, InputStride, OutputBuffer, OutputStride, BufferSize);
        else if constexpr (std::is_same_v<T, double>)
            vDSP_absD (InputBuffer, InputStride, OutputBuffer, OutputStride, BufferSize);
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
    static void zeroBuffer (T* ValueToFill, const int BufferSize, const int BufferStride = 1)
    {
        if constexpr (std::is_same_v<T, float>)
            vdsp_vzero (ValueToFill, BufferStride, BufferSize);
        if constexpr (std::is_same_v<T, double>)
            vdsp_vzeroD (ValueToFill, BufferStride, BufferSize);
    }
};