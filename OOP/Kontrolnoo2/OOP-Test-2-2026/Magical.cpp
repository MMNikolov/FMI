#include "Magical.hpp"

Magical::Magical(const char *name, int power, const char *blood, const char *spell)
    : MythicalCreature(name, power, blood)
{
    if (!spell)
    {
        throw std::invalid_argument("Invlaid");
    }
    
    this->spell = new char[strlen(spell) + 1];
    strcpy(this->spell, spell);
}

Magical::Magical(const Magical &other)
    : MythicalCreature(other)
{
    this->spell = new char[strlen(other.spell) + 1];
    strcpy(this->spell, other.spell);
}

Magical &Magical::operator=(const Magical &other)
{
    if (this != &other)
    {
        MythicalCreature::operator=(other);
        free();
        this->spell = new char[strlen(other.spell) + 1];
        strcpy(this->spell, other.spell);
    }
    
    return *this;
}

Magical::~Magical()
{
    free();
}

std::ostream &Magical::describe(std::ostream &out) const
{
    out << this->name << ' ' << this->power << ' ' << this->blood << ' ' << this->spell << '\n';
    return out;
}

bool Magical::canFly() const
{
    return false;
}

MythicalCreature *Magical::clone() const
{
    return new Magical(*this);
}

void Magical::free()
{
    delete[] this->spell;
    this->spell = nullptr;
}
