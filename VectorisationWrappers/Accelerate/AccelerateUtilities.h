#pragma once
#include <Accelerate/Accelerate.h>

// VDSP wrapper namespace in a vectorised way
namespace Vectorised::Utilities
{
    template <typename T>
    static void scalerMultiplication (const T* InputBuffer, T* OutputBuffer, const int BufferSize, T& ScalarValue, const int InputStride = 1, const int OutputStride = 1)
    {
        if constexpr (std::is_same_v<T, float>)
            vDSP_vsmul (InputBuffer, InputStride, &ScalarValue, OutputBuffer, OutputStride, BufferSize);
        else if constexpr (std::is_same_v<T, double>)
            vDSP_vsmulD (InputBuffer, InputStride, &ScalarValue, OutputBuffer, OutputStride, BufferSize);
    }

    template <typename T>
    static void absBuffer (T* InputBuffer, T*  OutputBuffer, const int BufferSize, const int InputStride = 1, const int OutputStride = 1)
    {
        if constexpr (std::is_same_v<T, float>)
            vDSP_vabs (InputBuffer, InputStride, OutputBuffer, OutputStride, BufferSize);
        else if constexpr (std::is_same_v<T, double>)
            vDSP_vabsD (InputBuffer, InputStride, OutputBuffer, OutputStride, BufferSize);
    }

    template <typename T>
    static void fillBuffer (T* ValueToFill, T* Buffer, const int BufferSize, const int BufferStride = 1)
    {
        if constexpr (std::is_same_v<T, float>)
            vDSP_vfill (ValueToFill, Buffer, BufferStride, BufferSize);
        else if constexpr (std::is_same_v<T, double>)
            vDSP_vfillD (ValueToFill, Buffer, BufferStride, BufferSize);
    }

    template <typename T>
    static void zeroBuffer (T* Buffer, const int BufferSize, const int BufferStride = 1)
    {
        if constexpr (std::is_same_v<T, float>)
            vDSP_vclr (Buffer, BufferStride, BufferSize);
        if constexpr (std::is_same_v<T, double>)
            vDSP_vclrD (Buffer, BufferStride, BufferSize);
    }
};