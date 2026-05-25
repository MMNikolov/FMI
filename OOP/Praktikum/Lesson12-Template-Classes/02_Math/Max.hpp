#pragma once

#include "MathExpression.hpp"

#define MAX_DATA_SIZE 10

template <typename T>
class Max : public MathExpression<T>
{
public:
    Max();
    Max(T data[MAX_DATA_SIZE]);

    //method
    void addExpression(T data);

private:
    T data[MAX_DATA_SIZE];
};

#include "Max.inl"