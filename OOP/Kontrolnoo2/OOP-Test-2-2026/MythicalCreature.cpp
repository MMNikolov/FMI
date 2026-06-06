#include "MythicalCreature.hpp"

MythicalCreature::MythicalCreature(const char *name, int power, const char *blood)
{
    if (!name || power < 0 || !blood)
    {
        throw std::invalid_argument("Invlaid");
    }
    
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->blood = new (std::nothrow) char[strlen(blood) + 1];
    if (!this->blood)
    {
        delete[] this->name;
        throw std::bad_alloc();
    }
    strcpy(this->blood, blood);

    this->power = power;
}

MythicalCreature::MythicalCreature(const MythicalCreature &other)
{
    copyFrom(other);
}

MythicalCreature &MythicalCreature::operator=(const MythicalCreature &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    
    return *this;
}

MythicalCreature::~MythicalCreature()
{
    free();
}

void MythicalCreature::free()
{
    delete[] this->name;
    this->name = nullptr;
    delete[] this->blood;
    this->blood = nullptr;
}

void MythicalCreature::copyFrom(const MythicalCreature &other)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

    this->blood = new (std::nothrow) char[strlen(other.blood) + 1];
    if (!this->blood)
    {
        delete[] this->name;
        throw std::bad_alloc();
    }
    strcpy(this->blood, other.blood);

    this->power = other.power;
}
