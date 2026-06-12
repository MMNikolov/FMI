#pragma once

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdint>

template<typename T, T M>
class Sound
{
public:
    virtual ~Sound() = default;

    //methods
    virtual size_t getDuration() const = 0;
    virtual T operator[](size_t index) const = 0;
    virtual Sound<T, M>* clone() const = 0;
};
