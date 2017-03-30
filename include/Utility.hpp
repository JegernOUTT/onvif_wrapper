#pragma once

#include <random>

namespace onvifwrapper
{
    template<typename T>
    struct Safe
    {
        Safe(T* p)
        {
            ptr = p ? p : new T();
            valid = static_cast<bool>(p);
        }

        ~Safe()
        {
            if (!valid)
                delete ptr;
        }

        operator bool() const
        {
            return valid;
        }

        T* operator->()
        {
            return ptr;
        }

        T& operator*()
        {
            return *ptr;
        }

    private:
        bool valid;
        T* ptr;
    };


    // Safe getting pointer (with new value)
    template<typename T>
    Safe<T> S(T* ptr)
    {
        return { ptr };
    }

    template<typename T>
    T GF(T min, T max)
    {
        std::random_device device;
        std::default_random_engine generator(device());
        std::uniform_real_distribution<T> distribution(min, max);
        return distribution(generator);
    }

    template<typename T>
    T IF(T min, T max)
    {
        std::random_device device;
        std::default_random_engine generator(device());
        std::uniform_int_distribution<T> distribution(min, max);
        return distribution(generator);
    }
}