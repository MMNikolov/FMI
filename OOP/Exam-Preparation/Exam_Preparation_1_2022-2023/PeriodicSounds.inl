#include "PeriodicSounds.hpp"

template <typename T, T M>
inline PeriodicSounds<T, M>::PeriodicSounds(const T *pattern, size_t repeats)
{
    if (!pattern || repeats < 0)
    {
        throw std::invalid_argument("Invlaid");
    }
    
    this->repeats = repeats;
    for (size_t i = 0; i < this->repeats; i++)
    {
        this->pattern[i] = pattern[i];
    }
}

template <typename T, T M>
inline PeriodicSounds<T, M>::PeriodicSounds(const PeriodicSounds<T, M> &other)
{
    copyFrom(other);
}

template <typename T, T M>
inline PeriodicSounds<T, M>::~PeriodicSounds()
{
    free();
}

template <typename T, T M>
inline size_t PeriodicSounds<T, M>::getDuration() const
{
    size_t duration = 0;
    for (size_t i = 0; i < this->repeats; i++)
    {
        duration = this->pattern[i];
    }
    
    return duration;
}

template <typename T, T M>
inline T PeriodicSounds<T, M>::operator[](size_t index) const
{
    //dont know what they want from me here
    return T();
}

template <typename T, T M>
inline PeriodicSounds<T, M> *PeriodicSounds<T, M>::clone() const
{
    return new PeriodicSounds(*this);
}

template <typename T, T M>
inline void PeriodicSounds<T, M>::free()
{
    for (size_t i = 0; i < repeats; i++)
    {
        delete[] this->pattern[i];
        this->pattern[i] = nullptr;
    }

    delete this->pattern;
}

template <typename T, T M>
inline void PeriodicSounds<T, M>::copyFrom(const PeriodicSounds<T, M> &other)
{
    this->repeats = other.repeats;

    for (size_t i = 0; i < this->repeats; i++)
    {
        this->repeats[i] = other.repeats[i];
    }
}
