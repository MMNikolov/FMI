#include "Soldier.hpp"

Soldier::Soldier()
    : name(nullptr), age(0), powerLevel(0), gold(0)
{}

Soldier::Soldier(const char *name, unsigned age, unsigned powerLevel, unsigned gold)
    : powerLevel(powerLevel), gold(gold)
{
    if (!name || age > 150)
    {
        throw std::invalid_argument("Invalid Input");
    }
    
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->age = age;
}

Soldier::Soldier(const Soldier &other)
{
    copyFrom(other);
}

Soldier &Soldier::operator=(const Soldier &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    
    return *this;
}

Soldier::~Soldier()
{
    free();
}

void Soldier::free()
{
    delete[] name;
}

void Soldier::copyFrom(const Soldier &other)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

    this->age = other.age;
    this->powerLevel = other.powerLevel;
    this->gold = other.gold;
}
