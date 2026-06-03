#include "Banana.hpp"

unsigned Banana::BananaId = 0;

Banana::Banana(const char *name, bool isHidden, bool isRotten, bool toEat, bool watchOnly)
    : Id(IdCounter())
{
    if (!name || name[0] == '\0')
    {
        throw std::invalid_argument("Invalid input!");
    }
    
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->isHidden = isHidden;
    this->isRotten = isRotten;
    this->toEat = toEat;
    this->watchOnly = watchOnly;
}

Banana::~Banana()
{
    free();
}

void Banana::free()
{
    delete[] this->name;
}
