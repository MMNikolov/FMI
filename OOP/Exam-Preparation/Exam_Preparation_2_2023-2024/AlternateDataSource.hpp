#ifndef ALTERNATE_DATA_SOURCE_HPP
#define ALTERNATE_DATA_SOURCE_HPP

#include "DataSource.hpp"

template<typename T>
class AlternateDataSource : public DataSource<T>
{
public:
    AlternateDataSource(DataSource<T>** sources, size_t count);

    AlternateDataSource(const AlternateDataSource<T>& other);
    AlternateDataSource<T>& operator=(const AlternateDataSource<T>& other);

    ~AlternateDataSource();

    //overriden methods
    T takeNext() override;
    T* takeNextFew(int few, int& extractedCount) override;
    bool hasNext() const override;
    bool reset() override;  

private:
    DataSource<T>** sources;
    size_t count;
    size_t currentIndex;

private:
    void free();
    void copyFrom(const AlternateDataSource<T>& other);
};

#include "AlternateDataSource.inl"

#endif // ALTERNATE_DATA_SOURCE_HPP


