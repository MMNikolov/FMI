#include "Spacecraft.hpp"

unsigned Spacecraft::GlobalId = 1;

Spacecraft::Spacecraft(const char *name, int condition)
    : id(Incrementer())
{
    if (!name || condition < 0 || condition > MAX_CONDITION_STAT)
    {
        throw std::invalid_argument("Invalid");
    }
    
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->condition = condition;
}

Spacecraft::Spacecraft(const Spacecraft &other)
    : id(Incrementer())
{
    copyFrom(other);
}

Spacecraft::~Spacecraft()
{
    free();
}

unsigned Spacecraft::Incrementer()
{
    return Spacecraft::GlobalId++;
}

void Spacecraft::free()
{
    delete[] this->name;
    this->name = nullptr;
}

void Spacecraft::copyFrom(const Spacecraft &other)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

    this->condition = other.condition;
}