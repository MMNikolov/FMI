#ifndef DATA_SOURCE_HPP
#define DATA_SOURCE_HPP

#include <fstream>
#include <stdexcept>
#include <iostream>
#include <cstring>

template<typename T>
class DataSource
{
public:
    virtual ~DataSource() = default;

    //virtual methods
    virtual T takeNext() = 0;
    virtual T* takeNextFew(int few, int& extractedCount) = 0;
    virtual bool hasNext() const = 0;
    //if the operation succeeded or no
    virtual bool reset() = 0;

    T operator()() { return takeNext(); };

    DataSource<T>& operator>>(T& element) 
    {
        element = takeNext();
        return *this;
    }

    operator bool() const 
    {
        return hasNext();
    }
};

#endif // DATA_SOURCE_HPP
