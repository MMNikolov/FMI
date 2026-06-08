#include "Cargoship.hpp"

Cargoship::Cargoship(const char *name, int condition, int tonnage)
    : Spacecraft(name, condition)
{
    if (tonnage < 0)
    {
        throw std::invalid_argument("Invlaid");
    }
    
    this->tonnage = tonnage;
}

Cargoship::Cargoship(const Cargoship &other)
    : Spacecraft(other), tonnage(other.tonnage)
{}

double Cargoship::calculateEffectiveness() const
{
    return tonnage * 0.5 * (condition / 100.0);
}

Spacecraft *Cargoship::clone() const
{
    return new Cargoship(*this);
}

void Cargoship::print(std::ostream &out) const
{
    out << this->id << ' ' << this->name << ' ' << this->condition << ' ' << this->tonnage << '\n';
}
