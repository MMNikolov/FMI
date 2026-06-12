#pragma once

#include "Sound.hpp"

template<typename T, T M>
class FileSound : public Sound<T, M>
{
public:
    FileSound(const char* filename);

    FileSound(const FileSound<T, M>& other);
    FileSound& operator=(const FileSound<T, M>& other) = default;

    ~FileSound();

    //overriden functions
    size_t getDuration() const override;
    T operator[](size_t index) const override;
    FileSound<T, M>* clone() const override;

private:
    char* filename;
    size_t cachedDuration;

private:
    void free();
    void copyFrom(const FileSound<T, M>& other);
};

#include "FileSound.inl"


