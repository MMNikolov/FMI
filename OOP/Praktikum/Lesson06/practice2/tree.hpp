#pragma once

#include <iostream>
#include <fstream>
#include <cstring>
#define BUFFER_SIZE 200

class tree
{
public:
    tree(const char *name, unsigned height, unsigned age, bool isEndangered, unsigned yearsLeft);
    ~tree()
    {
        delete[] name;
    };
    tree();

    void readFile(std::ifstream& is);
    void printCharacteristics();

private:
    char *name;
    unsigned int height;
    unsigned int age;
    bool isEndangered;
    unsigned int yearsLeft;
    bool isValid;

private:
    bool SetString(char*& where, const char* what);
    void freeMemory();
};
