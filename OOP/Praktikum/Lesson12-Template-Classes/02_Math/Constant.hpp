#pragma once

#include "MathExpression.hpp"

template<typename T>
class Constant : public MathExpression<T>
{
public:
    Constant();
    Constant(T data);
    Constant(const Constant& other);
    Constant& operator=(const Constant& other);

private:
    T data;

private:
    void copyFrom(const Constant& other);
};

#include "Constant.inl"