#pragma once

#include <iostream>
#include <cstring>
#include <fstream>

class licencePlate
{
public:
    licencePlate(const char* front, unsigned int num, const char* back);
    licencePlate();
    ~licencePlate()
    {
        freeMemory();
    };

    void readFromTxt(std::ifstream& is);
    void printCharacteristics();

private:
    char* front;
    unsigned int num;
    char* back;
    bool isValid;

private:
    bool setString(char*& where, const char* what);
    void freeMemory();
};
