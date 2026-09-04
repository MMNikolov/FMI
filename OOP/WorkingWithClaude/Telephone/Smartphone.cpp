#include "Smartphone.hpp"

Smartphone::Smartphone(const char *model, const char *brand, double price, const char *OS, unsigned RAM)
    : Telephone(model, brand, price), OS(nullptr), RAM(0)
{
    if (!OS)
    {
        throw std::invalid_argument("Doesnt have an OS");
    }
    
    this->OS = new char[strlen(OS) + 1];
    strcpy(this->OS, OS);

    this->RAM = RAM;
}

//this is now what we call slicing :DD:DDDDDD
Smartphone::Smartphone(const Smartphone &other)
    : Telephone(other), RAM(other.RAM)
{
    this->OS = new char[strlen(other.OS) + 1];
    strcpy(this->OS, other.OS);
}

Smartphone &Smartphone::operator=(const Smartphone &other)
{
    if (this != &other)
    {
        char* tempOS = new char[strlen(other.OS) + 1];
        strcpy(tempOS, other.OS);

        free();

        this->OS = tempOS;
        this->RAM = other.RAM;
    }
    
    return *this;
}

Smartphone::~Smartphone()
{
    free();
}

double Smartphone::getPrice() const
{
    return (Telephone::getPrice() + this->RAM);
}

Smartphone *Smartphone::clone() const
{
    return new Smartphone(*this);
}

void Smartphone::free()
{
    delete[] this->OS;
}
