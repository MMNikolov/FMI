#include "Flying.hpp"

Flying::Flying(const char *name, int power, const char *blood, int altitude)
    : MythicalCreature(name, power, blood)
{
    if (altitude < 0)
    {
        throw std::invalid_argument("invalid");
    }
    
    this->altitude = altitude;
}

Flying::Flying(const Flying &other)
    : MythicalCreature(other), altitude(other.altitude)
{}

Flying &Flying::operator=(const Flying &other)
{
    if (this != &other)
    {
        MythicalCreature::operator=(other);
        this->altitude = other.altitude;
    }
    
    return *this;
}

std::ostream& Flying::describe(std::ostream &out) const
{
    out << this->name << ' ' << this->power << ' ' << this->blood << ' ' << this->altitude << '\n';
    return out;
}

bool Flying::canFly() const
{
    return true;
}

MythicalCreature *Flying::clone() const
{
    return new Flying(*this);
}
