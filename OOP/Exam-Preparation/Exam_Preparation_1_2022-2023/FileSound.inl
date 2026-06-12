#include "FileSound.hpp"

template <typename T, T M>
inline FileSound<T, M>::FileSound(const char *filename)
{
    if (!filename)
    {
        throw std::invalid_argument("Invlaid");
    }
    
    this->filename = new char[strlen(filename) + 1];
    strcpy(this->filename, filename);

    this->cachedDuration = strlen(this->filename);
}

template <typename T, T M>
inline FileSound<T, M>::FileSound(const FileSound<T, M> &other)
{
    copyFrom(other);
}

template <typename T, T M>
inline FileSound<T, M>::~FileSound()
{
    free();
}

template <typename T, T M>
inline size_t FileSound<T, M>::getDuration() const
{
    return this->cachedDuration;
}

template <typename T, T M>
inline T FileSound<T, M>::operator[](size_t index) const
{
    //dont know what they want from me also I didnt do it like a binary file so....
    return T();
}

template <typename T, T M>
inline FileSound<T, M> *FileSound<T, M>::clone() const
{
    return new FileSound(*this);
}

template <typename T, T M>
inline void FileSound<T, M>::free()
{
    delete[] this->filename;
    this->filename = nullptr;
}

template <typename T, T M>
inline void FileSound<T, M>::copyFrom(const FileSound<T, M> &other)
{
    this->filename = new char[strlen(other.filename) + 1];
    strcpy(this->filename, other.filename);

    this->cachedDuration = other.cachedDuration;
}
