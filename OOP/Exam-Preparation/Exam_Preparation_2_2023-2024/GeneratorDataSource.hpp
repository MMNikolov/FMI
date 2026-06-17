#ifndef GENERATOR_DATA_SOURCE_HPP
#define GENERATOR_DATA_SOURCE_HPP

#include "DataSource.hpp"

template<typename T>
class GeneratorDataSource : public DataSource<T>
{
public:
    GeneratorDataSource(T (*func)());

    ~GeneratorDataSource() override = default;

    //overriden methods
    T takeNext() override;
    T* takeNextFew(int few, int& extractedCount) override;
    bool hasNext() const override;
    bool reset() override;  

private:
    T (*func)();
};

#include "GeneratorDataSource.inl"

#endif // GENERATOR_DATA_SOURCE_HPP


