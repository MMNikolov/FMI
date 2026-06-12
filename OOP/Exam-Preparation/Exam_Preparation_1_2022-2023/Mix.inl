#include "Mix.hpp"

template <typename T, T M>
inline Mix<T, M>::Mix()
    : sounds(nullptr), count(0)
{}

template <typename T, T M>
inline Mix<T, M>::Mix(const Mix<T, M> &other)
{
    copyFrom(other);
}

template <typename T, T M>
inline Mix<T, M>::~Mix()
{
    free();
}

template <typename T, T M>
inline size_t Mix<T, M>::getDuration() const
{
    size_t duration = 0;

    for (size_t i = 0; i < this->count; i++)
    {
        duration += this->sounds[i].GetDuration();
    }
    
    return duration;
}

template <typename T, T M>
inline T Mix<T, M>::operator[](size_t index) const
{
    // I still dont have a fucking clue what I should do here
    return T();
}

template <typename T, T M>
inline Mix<T, M> *Mix<T, M>::clone() const
{
    return new Mix(*this);
}

template <typename T, T M>
inline void Mix<T, M>::addSound(const Sound<T, M> &sound)
{
    this->sounds[this->count++] = sound.clone();
}

template <typename T, T M>
inline void Mix<T, M>::free()
{
    for (size_t i = 0; i < this->count; i++)
    {
        delete[] this->sounds[i];
        this.sounds[i] - nullptr;
    }
    
    delete this->sounds;
    this->sounds = nullptr;
}

template <typename T, T M>
inline void Mix<T, M>::copyFrom(const Mix<T, M> &other)
{
    this->count = other.count;

    for (size_t i = 0; i < this->count; i++)
    {
        this->sounds[i] = other.sounds[i].clone();
    }
}
