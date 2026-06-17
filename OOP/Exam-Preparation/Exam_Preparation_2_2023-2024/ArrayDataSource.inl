#include "ArrayDataSource.hpp"

template <typename T>
inline ArrayDataSource<T>::ArrayDataSource()
    : elements(nullptr), count(0)
{}

template <typename T>
inline ArrayDataSource<T>::ArrayDataSource(T *elements, size_t count)
{
    if (!elements || count <= 0)
    {
        throw std::invalid_argument("Cant initialize array with zero elements. We have a default ctor for that");
    }
    
    this->count = count;
    this->elements = new T[count];
    for (size_t i = 0; i < count; i++)
    {
        this->elements[i] = elements[i];
    }

    this->currentIndex = 0;
}

template <typename T>
inline ArrayDataSource<T>::ArrayDataSource(const ArrayDataSource<T> &other)
{
    copyFrom(other);
}

template <typename T>
inline ArrayDataSource<T> &ArrayDataSource<T>::operator=(const ArrayDataSource<T> &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    
    return *this;
}

template <typename T>
inline ArrayDataSource<T>::~ArrayDataSource()
{
    free();
}

template <typename T>
inline T ArrayDataSource<T>::takeNext()
{
    if (this->hasNext())
    {
        return this->elements[this->currentIndex++];
    }
    
    return T();
}

template <typename T>
inline T *ArrayDataSource<T>::takeNextFew(int few, int &extractedCount)
{
    T* arr = new T[few];
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
inline bool ArrayDataSource<T>::hasNext() const
{
    if (this->currentIndex < this->count)
    {
        return true;
    }
    
    return false;
}

template <typename T>
inline bool ArrayDataSource<T>::reset()
{
    this->currentIndex = 0; // Връщаме генератора в началото
    return true;
}

template <typename T>
inline ArrayDataSource<T>& ArrayDataSource<T>::operator+=(const T& element)
{
    // 1. Заделяме нов масив с 1 място повече
    T* newElements = new T[this->count + 1];

    // 2. Копираме старите елементи
    for (size_t i = 0; i < this->count; i++)
    {
        newElements[i] = this->elements[i];
    }

    // 3. Добавяме новия елемент накрая
    newElements[this->count] = element;

    // 4. Трием стария масив и пренасочваме указателя
    delete[] this->elements;
    this->elements = newElements;
    this->count++;

    return *this;
}

template <typename T>
inline void ArrayDataSource<T>::operator--()
{
    if (this->currentIndex == 0)
    {
        throw std::invalid_argument("Cant access the element before 0");
    }
    
    this->currentIndex--;
}

template <typename T>
inline void ArrayDataSource<T>::free()
{
    delete[] this->elements; // Това е напълно достатъчно
    this->elements = nullptr;
}

template <typename T>
inline void ArrayDataSource<T>::copyFrom(const ArrayDataSource<T> &other)
{
    this->count = other.count;
    this->currentIndex = other.currentIndex;

    this->elements = new T[this->count];
    for (size_t i = 0; i < count; i++)
    {
        this->elements[i] = other.elements[i];
    }
}

template <typename T>
inline ArrayDataSource<T> ArrayDataSource<T>::operator+(const T& element) const
{
    // Създаваме копие на текущия обект
    ArrayDataSource<T> result(*this); 
    // Използваме вече готовия +=, за да добавим елемента към копието
    result += element; 
    return result;
}