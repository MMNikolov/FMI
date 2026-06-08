#include "Smuglership.hpp"

Smuglership::Smuglership(const char *name, int condition, const char *weaponSystem, int firepower, int tonnage, int stealthLevel)
    : Spacecraft(name, condition),
      Warship(name, condition, weaponSystem, firepower),
      Cargoship(name, condition, tonnage)
{
    if (stealthLevel < 1 || stealthLevel > 10)
    {
        throw std::invalid_argument("Invalid");
    }
    
    this->stealthLevel = stealthLevel;
}

Smuglership::Smuglership(const Smuglership &other)
    : Spacecraft(other), Warship(other), Cargoship(other), stealthLevel(other.stealthLevel)
{}

double Smuglership::calculateEffectiveness() const
{
    return (firepower + tonnage) * stealthLevel * (condition / 100.0);
}

Spacecraft *Smuglership::clone() const
{
    return new Smuglership(*this);
}

void Smuglership::print(std::ostream &out) const
{
    out << this->id << ' ' << this->name << ' ' << this->condition << ' ' << this->weaponSystem << ' ' << this->firepower << ' ' << this->tonnage << ' ' << this->stealthLevel << '\n';
}
