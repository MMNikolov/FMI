#include "Sequence.hpp"

template <typename T, T M>
inline Sequence<T, M>::Sequence()
    : sounds(nullptr), count(0)
{}

template <typename T, T M>
inline Sequence<T, M>::Sequence(const Sequence<T, M> &other)
{
    copyFrom(other);
}

template <typename T, T M>
inline Sequence<T, M>::~Sequence()
{
    free();
}

template <typename T, T M>
inline size_t Sequence<T, M>::getDuration() const
{
    size_t duration = 0;

    for (size_t i = 0; i < this->count; i++)
    {
        duration += this->sounds[i].GetDuration();
    }
    
    return duration;
}

template <typename T, T M>
inline T Sequence<T, M>::operator[](size_t index) const
{
    //dont know what I should do here
    return T();
}

template <typename T, T M>
inline Sequence<T, M> *Sequence<T, M>::clone() const
{
    return new Sequence(*this);
}

template <typename T, T M>
inline void Sequence<T, M>::addSound(const Sound<T, M> &sound)
{
    this->sounds[this->count++] = sound.clone();
}

template <typename T, T M>
inline void Sequence<T, M>::free()
{
    for (size_t i = 0; i < this->count; i++)
    {
        delete[] this->sounds[i];
        this->sounds[i] = nullptr;
    }
    
    delete this->sounds;
    this->sounds = nullptr;
}

template <typename T, T M>
inline void Sequence<T, M>::copyFrom(const Sequence<T, M> &other)
{
    this->count = other.count;

    for (size_t i = 0; i < this->count; i++)
    {
        this->sounds[i] = other.sounds[i].clone();
    }
}
