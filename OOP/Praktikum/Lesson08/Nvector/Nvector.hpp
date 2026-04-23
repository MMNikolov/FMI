#pragma once

#include <iostream>
#include <stdexcept>

class Nvector
{
public:
    //default constructor
    Nvector();

    //ordinary constructor
    Nvector(int* data, size_t size);

    //copy constructor
    Nvector(const Nvector& other);
    Nvector& operator=(const Nvector& other);

    //destructor
    ~Nvector();

    int& operator[](size_t index);
    Nvector& operator+=(const Nvector& other);
    Nvector& operator-=(const Nvector& other);
    Nvector& operator*=(size_t scalar);
    Nvector& operator/=(size_t scalar);

    friend std::ostream& operator<<(std::ostream& out, const Nvector& vec);

    size_t GetSize() const;
    int* GetData() const;
private:
    int* data;
    // A vector cant be < 0 dimensional
    size_t size;

private: 
    void free();
    void copyFrom(const Nvector& other);
};

Nvector operator+(const Nvector& one, const Nvector& two);
Nvector operator-(const Nvector& one, const Nvector& two);
Nvector operator*(const Nvector& one, const Nvector& two);
Nvector operator/(const Nvector& one, const Nvector& two);
Nvector operator%(const Nvector& one, const Nvector& two);
