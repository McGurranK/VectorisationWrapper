#pragma once
#include <Accelerate/Accelerate.h>
#include <type_traits>

namespace Vectorised::Range
{
    template <typename T>
    static void minimumValue(T* Buffer, int BufferSize, T& OutputValue, int Stride = 1)
    {
        if constexpr (std::is_same_v<T, float>)
            vDSP_minv(Buffer, Stride, &OutputValue, BufferSize);
        else if constexpr (std::is_same_v<T, double>)
            vDSP_minvD(Buffer, Stride, &OutputValue, BufferSize);
    }

    template <typename T>
    static void maximumValue(T* Buffer, int BufferSize, T& OutputValue, int Stride = 1)
    {
        if constexpr (std::is_same_v<T, float>)
            vDSP_maxv(Buffer, Stride, &OutputValue, BufferSize);
        else if constexpr (std::is_same_v<T, double>)
            vDSP_maxvD(Buffer, Stride, &OutputValue, BufferSize);
    }

    template <typename T>
    static void minimumValueIndex(T* Buffer, int BufferSize, T& OutputValue, int Stride, int& Position)
    {
        vDSP_Length pos = 0;

        if constexpr (std::is_same_v<T, float>)
            vDSP_minvi(Buffer, Stride, &OutputValue, &pos, BufferSize);
        else if constexpr (std::is_same_v<T, double>)
            vDSP_minviD(Buffer, Stride, &OutputValue, &pos, BufferSize);

        Position = static_cast<int>(pos);
    }

    template <typename T>
    static void maximumValueIndex(T* Buffer, int BufferSize, T& OutputValue, int Stride, int& Position)
    {
        vDSP_Length pos = 0;

        if constexpr (std::is_same_v<T, float>)
            vDSP_maxvi(Buffer, Stride, &OutputValue, &pos, BufferSize);
        else if constexpr (std::is_same_v<T, double>)
            vDSP_maxviD(Buffer, Stride, &OutputValue, &pos, BufferSize);

        Position = static_cast<int>(pos);
    }
}
