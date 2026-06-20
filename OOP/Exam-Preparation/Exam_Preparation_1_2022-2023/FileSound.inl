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

    // Отваряме файла бинарно и отиваме в края (ate - at end), за да му вземем размера
    std::ifstream file(this->filename, std::ios::binary | std::ios::ate);
    if (!file)
    {
        throw std::runtime_error("Could not open file");
    }

    size_t fileSize = file.tellg();
    this->cachedDuration = fileSize / sizeof(T);
    file.close();
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
    if (index >= this->cachedDuration)
        return 0; // Защита от излизане извън граници

    std::ifstream file(this->filename, std::ios::binary);
    // Преместваме курсора до точния байт
    file.seekg(index * sizeof(T), std::ios::beg);

    T sample;
    file.read(reinterpret_cast<char *>(&sample), sizeof(T));
    file.close();

    return sample;
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
