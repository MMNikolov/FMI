#include "Dragon.hpp"

Dragon::Dragon(const char *name, int power, const char *blood, int altitude, const char *spell)
    : MythicalCreature(name, power, blood),
      Flying(name, power, blood, altitude),
      Magical(name, power, blood, spell)
{}

Dragon::Dragon(const Dragon &other)
    : MythicalCreature(other),
      Flying(other),
      Magical(other)
{}

Dragon &Dragon::operator=(const Dragon &other)
{
    if (this != &other)
    {
        MythicalCreature::operator=(other);
        Flying::operator=(other);
        Magical::operator=(other);
    }
    
    return *this;
}

std::ostream &Dragon::describe(std::ostream &out) const
{
    out << this->name << ' ' << this->power << ' ' << this->blood << ' ' << this->altitude << ' ' << this->spell << '\n';
    return out;
}

bool Dragon::canFly() const
{
    return true;
}

MythicalCreature *Dragon::clone() const
{
    return new Dragon(*this);
}
