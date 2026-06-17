#include "GeneratorDataSource.hpp"

template <typename T>
inline GeneratorDataSource<T>::GeneratorDataSource(T (*func)())
{
    if (!func)
    {
        throw std::invalid_argument("Invlaid function");
    }

    this->func = func;
}

template <typename T>
inline T GeneratorDataSource<T>::takeNext()
{
    return this->func();
}

template <typename T>
inline T *GeneratorDataSource<T>::takeNextFew(int few, int &extractedCount)
{
    T *arr = new T[few];

    for (int i = 0; i < few; i++)
    {
        arr[i] = this->func();
    }
    
    extractedCount = few;
    return arr;
}

template <typename T>
inline bool GeneratorDataSource<T>::hasNext() const
{
    return true;
}

template <typename T>
inline bool GeneratorDataSource<T>::reset()
{
    return false;
}
