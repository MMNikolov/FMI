#pragma once

#include "../practice2/tree.hpp"
#include <iostream>
#include <cstring>
#include <fstream>

class ForestProtector
{
public:
    ForestProtector(const char* name, unsigned age, unsigned yearsWorking);
    ~ForestProtector()
    {
        delete[] name;
        delete[] protectorsTree;
    };

    bool SetString(char* where, const char* what);
    void freeMemory();

private:
    const char* name;
    unsigned int age;
    unsigned int yearsWorking;
    tree* protectorsTree;
    bool isValid;

    
};
