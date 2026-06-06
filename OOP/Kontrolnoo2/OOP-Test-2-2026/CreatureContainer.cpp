#include "CreatureContainer.hpp"

CreatureContainer::CreatureContainer(int capacity)
{
    if (capacity < 0 || capacity > MAX_SIZE)
    {
        throw std::invalid_argument("Invalid");
    }
    
    this->capacity = capacity;
}

CreatureContainer::~CreatureContainer()
{
    free();
}

void CreatureContainer::free()
{
    for (unsigned i = 0; i < count; i++)
    {
        delete[] this->creatures[i];
    }
    
    delete[] this->creatures;
}
