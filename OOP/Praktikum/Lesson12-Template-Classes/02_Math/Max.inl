#include "Max.hpp"

template<typename T>
inline Max<T>::Max()
    : data(0)
{}

template <typename T>
inline Max<T>::Max(T data[MAX_DATA_SIZE])
{
    unsigned size = (sizeof(data) / sizeof(data[0]));
    if (size >= 10)
    {
        throw std::invalid_argument("Problem with the input");
    }
    
    for (int i = 0; i < size; i++)
    {
        this->data[i] = data[i];
    }
}
