#pragma once

namespace Vectorised::Trigonometry
{
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

    template <typename T>
    static void sinhVectorised (const T* WorkBuffer, T* OutputBuffer, const int BufferSize)
    {
        if constexpr (std::is_same_v<T, float>)
            vvsinhf (OutputBuffer, WorkBuffer, &BufferSize);
        else if constexpr (std::is_same_v<T, double>)
            vvsinh (OutputBuffer, WorkBuffer, &BufferSize);
        else
            static_assert (sizeof(T) == 0, "Unsupported type for tanh");
    }

    template <typename T>
    static void coshVectorised (const T* WorkBuffer, T* OutputBuffer, const int BufferSize)
    {
        if constexpr (std::is_same_v<T, float>)
            vvcoshf (OutputBuffer, WorkBuffer, &BufferSize);
        else if constexpr (std::is_same_v<T, double>)
            vvcosh (OutputBuffer, WorkBuffer, &BufferSize);
        else
            static_assert (sizeof(T) == 0, "Unsupported type for tanh");
    }

    template <typename T>
    static void tanhVectorised (const T* WorkBuffer, T* OutputBuffer, const int BufferSize)
    {
        if constexpr (std::is_same_v<T, float>)
            vvtanhf (OutputBuffer, WorkBuffer, &BufferSize);
        else if constexpr (std::is_same_v<T, double>)
            vvtanh (OutputBuffer, WorkBuffer, &BufferSize);
        else
            static_assert (sizeof(T) == 0, "Unsupported type for tanh");
    }

    template <typename T>
    static void sineVectorised (const T* InputBuffer,  T* OutputBuffer,const int BufferSize)
    {
        if constexpr (std::is_same_v<T, float>)
            vvsinf (OutputBuffer, InputBuffer, &BufferSize);
        else if constexpr  (std::is_same_v<T, double>)
            vvsin (OutputBuffer, InputBuffer, &BufferSize);
        else
            static_assert (sizeof(T) == 0, "Unsupported type for sine");
    }

    template <typename T>
    static void cosVectorised (const T* InputBuffer, T* OutputBuffer, const int BufferSize)
    {
        if constexpr (std::is_same_v<T, float>)
            vvcosf (OutputBuffer, InputBuffer, &BufferSize);
        else if constexpr  (std::is_same_v<T, double>)
            vvcos (OutputBuffer, InputBuffer, &BufferSize);
        else
            static_assert (sizeof(T) == 0, "Unsupported type for sine");
    }

    template <typename T>
    static void tanVectorised (const T* InputBuffer, T* OutputBuffer, const int BufferSize)
    {
        if constexpr (std::is_same_v<T, float>)
            vvtanf (OutputBuffer, InputBuffer, &BufferSize);
        else if constexpr  (std::is_same_v<T, double>)
            vvtan (OutputBuffer, InputBuffer, &BufferSize);
        else
            static_assert (sizeof(T) == 0, "Unsupported type for sine");
    }

    template <typename T>
    static void arcSinVectorised (const T* InputBuffer, T* OutputBuffer, const int BufferSize)
    {
        if constexpr (std::is_same_v<T, float>)
            vvasinf (OutputBuffer, InputBuffer, &BufferSize);
        else if constexpr  (std::is_same_v<T, double>)
            vvasin (OutputBuffer, InputBuffer, &BufferSize);
        else
            static_assert (sizeof(T) == 0, "Unsupported type for sine");
    }

    template <typename T>
    static void arcCosVectorised (const T* InputBuffer, T* OutputBuffer, const int BufferSize)
    {
        if constexpr (std::is_same_v<T, float>)
            vvacosf (OutputBuffer, InputBuffer, &BufferSize);
        else if constexpr  (std::is_same_v<T, double>)
            vvacos (OutputBuffer, InputBuffer, &BufferSize);
        else
            static_assert (sizeof(T) == 0, "Unsupported type for sine");
    }

    template <typename T>
    static void tanCosVectorised (const T* InputBuffer, T* OutputBuffer, const int BufferSize)
    {
        if constexpr (std::is_same_v<T, float>)
            vvatanf (OutputBuffer, InputBuffer, &BufferSize);
        else if constexpr  (std::is_same_v<T, double>)
            vvatan (OutputBuffer, InputBuffer, &BufferSize);
        else
            static_assert (sizeof(T) == 0, "Unsupported type for sine");
    }
}