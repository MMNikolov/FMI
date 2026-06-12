#pragma once

#include "Sound.hpp"

template<typename T, T M>
class PeriodicSounds : public Sound<T, M>
{
public:
    PeriodicSounds(const T* pattern, size_t repeats);

    PeriodicSounds(const PeriodicSounds<T, M>& other);
    PeriodicSounds& operator=(const PeriodicSounds<T, M>& other) = default;

    ~PeriodicSounds();

    //overriden methods
    size_t getDuration() const override;
    T operator[](size_t index) const override;
    PeriodicSounds<T, M>* clone() const override;

private:
    T* pattern;
    size_t repeats;

private:
    void free();
    void copyFrom(const PeriodicSounds<T, M>& other);
};

#include "PeriodicSounds.inl"
