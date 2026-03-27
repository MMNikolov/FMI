#pragma once

#include <iostream>
#include <cstring>
#include <new>

enum energy_class
{
    UNKNOWN,

    AA,
    A,
    B,
    C
};

class oven
{
public:
    oven(const char *maker, const char *countryOfOrgin, int waranty, energy_class ec);
    ~oven()
    {
        free();
    };

private:
    bool setString(char*& where, const char* what);
    void free();

private:
    char *maker;
    char *countryOfOrgin;
    int waranty;
    energy_class ec;
    bool IsValid;
};
