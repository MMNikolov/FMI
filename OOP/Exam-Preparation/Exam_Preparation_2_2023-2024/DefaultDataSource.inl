#include "DefaultDataSource.hpp"

template <typename T>
inline T DefaultDataSource<T>::takeNext()
{
    return T();
}

template <typename T>
inline T *DefaultDataSource<T>::takeNextFew(int few, int &extractedCount)
{
    T* arr = new T[few];

    for (int i = 0; i < few; i++)
    {
        arr[i] = T();
    }
    
    extractedCount = few;
    return arr;
}

template <typename T>
inline bool DefaultDataSource<T>::hasNext() const
{
    //this geenrator is infinite thats why it will always be true when it asks us for has next
    return true;
}

template <typename T>
inline bool DefaultDataSource<T>::reset()
{
    //this state will always be true, because its the default state
    return true;
}
