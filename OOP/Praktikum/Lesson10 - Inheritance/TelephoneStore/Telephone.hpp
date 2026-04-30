#pragma once

#include <iostream>
#include <stdexcept>
#include <cstring>

class Telephone
{
public:
    //default ctor
    Telephone();

    //parametrized ctor
    Telephone(const char* model, const char* maker, double price);

    //copy ctor
    Telephone(const Telephone& other);
    Telephone& operator=(const Telephone& other);

    //destructor
    ~Telephone();

    //getters
    const char* getModel() const;
    const char* getMaker() const;
    double getPrice() const;

private:
    char* model;
    char* maker;
    double price;

    void free();
    void copyFrom(const Telephone& other);
};
