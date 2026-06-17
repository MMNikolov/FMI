#include "AlternateDataSource.hpp"

template <typename T>
inline AlternateDataSource<T>::AlternateDataSource(DataSource<T> **sources, size_t count)
    : currentIndex(0)
{
    if (!sources || count <= 0)
    {
        throw std::invalid_argument("Invalid alternating data source");
    }

    this->count = count;
    this->sources = new DataSource<T> *[count];
    for (size_t i = 0; i < count; i++)
    {
        this->sources[i] = sources[i];
    }
}

template <typename T>
inline AlternateDataSource<T>::AlternateDataSource(const AlternateDataSource<T> &other)
{
    copyFrom(other);
}

template <typename T>
inline AlternateDataSource<T> &AlternateDataSource<T>::operator=(const AlternateDataSource<T> &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }

    return *this;
}

template <typename T>
inline AlternateDataSource<T>::~AlternateDataSource()
{
    free();
}

template <typename T>
inline T AlternateDataSource<T>::takeNext()
{
    if (!this->hasNext())
    {
        return T();
    }
        
    for (size_t i = 0; i < this->count; i++)
    {
        size_t actualIndex = (this->currentIndex + i) % this->count;

        if (this->sources[actualIndex]->hasNext())
        {
            T element = this->sources[actualIndex]->takeNext();
            this->currentIndex = (actualIndex + 1) % this->count;
            return element;
        }
    }
    return T();
}

template <typename T>
inline T *AlternateDataSource<T>::takeNextFew(int few, int &extractedCount)
{
    T *arr = new T[few];
    extractedCount = 0;

    for (size_t i = 0; i < few; i++)
    {
        if (this->hasNext())
        {
            arr[i] = this->takeNext();
            extractedCount++;
        }
        else
        {
            return T();
        }
    }

    if (extractedCount == 0)
    {
        delete[] arr;
        arr = nullptr;
    }

    return arr;
}

template <typename T>
inline bool AlternateDataSource<T>::hasNext() const
{
    if (this->currentIndex < this->count)
    {
        return true;
    }

    return false;
}

template <typename T>
inline bool AlternateDataSource<T>::reset()
{
    this->currentIndex = 0;
    return true;
}

template <typename T>
inline void AlternateDataSource<T>::free()
{
    delete[] this->sources;
    this->sources = nullptr;
}

template <typename T>
inline void AlternateDataSource<T>::copyFrom(const AlternateDataSource<T> &other)
{
    this->count = other.count;
    this->currentIndex = other.currentIndex;
    this->sources = new DataSource<T> *[this->count];

    for (size_t i = 0; i < count; i++)
    {
        this->sources[i] = other.sources[i];
    }
}
