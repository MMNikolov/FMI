#pragma once

#include "Sound.hpp"

template<typename T, T M>
class Mix : public Sound
{
public:
    Mix();

    Mix(const Mix<T, M>& other);
    Mix& operator=(const Mix<T, M>& other) = default;

    ~Mix();

    //overriden methods
    size_t getDuration() const override;
    T operator[](size_t index) const override;
    Mix<T, M>* clone() const override;

    //methods
    void addSound(const Sound<T, M>& sound);

private:
    Sound<T, M>** sounds;
    size_t count;

private:
    void free();
    void copyFrom(const Mix<T, M>& other);
};

#include "Mix.inl"


