#pragma once

#include "Sound.hpp"

template<typename T, T M>
class Silence : public Sound<T, M>
{
public:
    Silence(size_t duration);
    
    //no need for a destructor as we aint working with dynamic memory

    //overriden methods
    size_t getDuration() const override;
    T operator[](size_t index) const override;
    Silence<T, M>* clone() const override;

private:
    size_t duration;
};

#include "Silence.inl"