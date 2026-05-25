#pragma once

#include <stdexcept>
#include <cstring>

template<typename T>
class MathExpression
{
public:
    virtual T value() const;
    virtual void print() const;
};