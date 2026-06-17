#ifndef ARRAY_DATA_SOURCE_HPP
#define ARRAY_DATA_SOURCE_HPP

#include "DataSource.hpp"

template<typename T>
class ArrayDataSource : public DataSource<T>
{
public:
    ArrayDataSource();
    ArrayDataSource(T* elements, size_t count);

    ArrayDataSource(const ArrayDataSource<T>& other);
    ArrayDataSource<T>& operator=(const ArrayDataSource<T>& other);

    ~ArrayDataSource();

    //overriden methods
    T takeNext() override;
    T* takeNextFew(int few, int& extractedCount) override;
    bool hasNext() const override;
    bool reset() override;  

    //newly added methods
    ArrayDataSource<T>& operator+=(const T& element);
    ArrayDataSource<T> operator+(const T& element) const;
    void operator--();

private:
    T* elements;
    size_t count;
    size_t currentIndex;

private:
    void free();
    void copyFrom(const ArrayDataSource<T>& other);
};

#include "ArrayDataSource.inl"

#endif // ARRAY_DATA_SOURCE_HPP


