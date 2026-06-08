#include "Warship.hpp"

Warship::Warship(const char *name, int condition, const char *weaponSystem, int firepower)
    : Spacecraft(name, condition)
{
    if (!weaponSystem || firepower < 0)
    {
        throw std::invalid_argument("Invalid");
    }
    
    this->weaponSystem = new char[strlen(weaponSystem) + 1];
    strcpy(this->weaponSystem, weaponSystem);

    this->firepower = firepower;
}

Warship::Warship(const Warship &other)
    : Spacecraft(other)
{
    this->weaponSystem = new char[strlen(other.weaponSystem) + 1];
    strcpy(this->weaponSystem, other.weaponSystem);

    this->firepower = other.firepower;
}

Warship::~Warship()
{
    free();
}

double Warship::calculateEffectiveness() const
{
    return firepower * (condition / 100.0);
}

Spacecraft *Warship::clone() const
{
    return new Warship(*this);
}

void Warship::print(std::ostream &out) const
{
    out << this->id << ' ' << this->name << ' ' << this->condition << ' ' << this->weaponSystem << ' ' << this->firepower << '\n';
}

void Warship::free()
{
    delete[] this->weaponSystem;
    this->weaponSystem = nullptr;
}
