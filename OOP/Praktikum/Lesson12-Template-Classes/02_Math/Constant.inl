#include "Constant.hpp"

template<typename T>
inline Constant<T>::Constant()
    : data(0)
{}

template <typename T>
inline Constant<T>::Constant(T data)
{
    this->data = data;
}

template <typename T>
inline Constant<T>::Constant(const Constant &other)
{
    copyFrom(other);
}

template <typename T>
inline Constant<T> &Constant<T>::operator=(const Constant &other)
{
    if (this != &other)
    {
        copyFrom(other);
    }
    
    return *this;
}

template <typename T>
inline void Constant<T>::copyFrom(const Constant &other)
{
    this->data = other.data;
}
