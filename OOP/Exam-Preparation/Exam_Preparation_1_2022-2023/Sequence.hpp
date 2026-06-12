#pragma once

#include "Sound.hpp"

template<typename T, T M>
class Sequence : public Sound
{
public:
    Sequence();

    Sequence(const Sequence<T, M>& other);
    Sequence& operator=(const Sequence<T, M>& other) = default;

    ~Sequence();

    //overriden methods
    size_t getDuration() const override;
    T operator[](size_t index) const override;
    Sequence<T, M>* clone() const override;

    //methods
    void addSound(const Sound<T, M>& sound);

private:
    Sound<T, M>** sounds;
    size_t count;

private:
    void free();
    void copyFrom(const Sequence<T, M>& other);
};

#include "Sequence.inl"