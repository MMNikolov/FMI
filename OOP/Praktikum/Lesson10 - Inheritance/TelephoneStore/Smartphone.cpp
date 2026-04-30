#include "Smartphone.hpp"

Smartphone::Smartphone()
    : Telephone(), os(nullptr), memory(0)
{
}

Smartphone::Smartphone(const char *model, const char *maker, double price, const char *os, unsigned memory)
    : Telephone(model, maker, price), os(nullptr), memory(0)
{
    if (!os)
    {
        throw std::invalid_argument("Invalid Input");
    }

    this->os = new char[strlen(os) + 1];
    strcpy(this->os, os);

    this->memory = memory;
    price += memory;
}

Smartphone::Smartphone(const Smartphone &other)
    : Telephone(other.getModel(), other.getMaker(), other.getPrice() + other.memory), os(nullptr), memory(0)
{
    this->os = new char[strlen(other.os) + 1];
    strcpy(this->os, os);

    this->memory = other.memory;
}

Smartphone &Smartphone::operator=(const Smartphone &other)
{
    if (this != &other)
    {
        char* os = nullptr;
        
        //TO DO
        try { Telephone::operator = (other); }
        catch(...)
        {
            delete[] os;
            throw;
        }

        free();
        // 
    }

    return *this;
}

Smartphone::~Smartphone()
{
    free();
}

const char *Smartphone::getOS() const
{
    return this->os;
}

unsigned Smartphone::getMemory() const
{
    return this->memory;
}

void Smartphone::free()
{
    delete[] os;
}
