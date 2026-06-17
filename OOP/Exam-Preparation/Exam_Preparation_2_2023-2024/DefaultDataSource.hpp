#ifndef DEFAULT_DATA_SOURCE_HPP
#define DEFAULT_DATA_SOURCE_HPP

#include "DataSource.hpp"

template<typename T>
class DefaultDataSource : public DataSource<T>
{
public:
    DefaultDataSource() = default;
    ~DefaultDataSource() override = default;

    T takeNext() override;
    T* takeNextFew(int few, int& extractedCount) override;
    bool hasNext() const override;
    bool reset() override;  
};

#include "DefaultDataSource.inl"

#endif // DEFAULT_DATA_SOURCE_HPP

