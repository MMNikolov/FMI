#include "Nvector.hpp"

void Nvector::free()
{
    delete[] data;
}

void Nvector::copyFrom(const Nvector& other)
{
    if (this->size != other.size)
    {
        throw std::invalid_argument("Cant copy different dimensional vectors");
    }
    
    this->size = other.size;

    for (int i = 0; i < size; i++)
    {
        this->data[i] = other.data[i];
    }
}

Nvector::Nvector()
    : data(nullptr), size(0)
{
    this->data = new int[1];
    this->data[0] = 0;
    this->size = 0;
}

Nvector::Nvector(int* data, size_t size)
    : data(nullptr), size(0)
{
    if (size < 1)
    {
        throw std::invalid_argument("Cant have less than one dimensional vector");
    }
    
    this->data = new int[size];
    this->data = data;
    this->size = size;
};

Nvector::Nvector(const Nvector& other)
{
    copyFrom(other);
}

Nvector& Nvector::operator=(const Nvector& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    
    return *this;
}

Nvector::~Nvector()
{
    free();
}

int& Nvector::operator[](size_t index)
{
    return this->data[index];
}