#include "Fleet.hpp"

Fleet::Fleet()
    : count(0), capacity(STARTING_CAPACITY)
{
    this->spacecrafts = new Spacecraft*[STARTING_CAPACITY];
}

Fleet::Fleet(const Fleet &other)
    : count(other.count), capacity(other.capacity)
{
    for (unsigned i = 0; i < capacity; i++)
    {
        this->spacecrafts[i] = other.spacecrafts[i]->clone();
    }
}

Fleet& Fleet::operator=(const Fleet &other)
{
    if (this != &other)
    {
        free();
        this->count = other.count;
        this->capacity = other.capacity;

        for (unsigned i = 0; i < capacity; i++)
        {
            this->spacecrafts[i] = other.spacecrafts[i]->clone();
        }
    }
    
    return *this;
}

Fleet::~Fleet()
{
    free();
}

void Fleet::operator+=(const Spacecraft &spacecraft)
{
    if (this->count >= capacity)
    {
        resize();
    }
    
    for (unsigned i = 0; i < this->count; i++)
    {
        if (strcmp(this->spacecrafts[i]->GetName(), spacecraft.GetName()) == 0)
        {
            return;
        }
    }
    
    this->spacecrafts[this->count++] = spacecraft.clone();
}

void Fleet::operator-=(unsigned id)
{
    for (unsigned i = 0; i < this->count; i++)
    {
        if (this->spacecrafts[i]->GetId() == id)
        {
            delete[] this->spacecrafts[i];

            for (unsigned j = i; j < count; j++)
            {
                spacecrafts[j] = spacecrafts[j + 1];
            }
            
        }
    }
       
}

Spacecraft *Fleet::GetMostEffective() const
{
    if (this->count == 0)
    {
        return nullptr;
    }
    
    int startingEffectiiveness = spacecrafts[0]->calculateEffectiveness();
    int maxEffectiveness = startingEffectiiveness;
    int index;

    for (unsigned i = 1; i < count; i++)
    {   
        if (this->spacecrafts[i]->calculateEffectiveness() > maxEffectiveness)
        {
            maxEffectiveness = this->spacecrafts[i]->calculateEffectiveness();
            index = i;
        }
    }
    
    return this->spacecrafts[index];
}

Spacecraft **Fleet::extractDamaged(int threshold, int &outCount)
{
    return nullptr;
}

void Fleet::resize()
{
    this->capacity *= 2;
    Spacecraft** tempSpeacecrafts = new Spacecraft*[this->capacity];

    for (unsigned i = 0; i < this->capacity; i++)
    {
        tempSpeacecrafts[i] = this->spacecrafts[i]->clone();
    }
    
    free();
    this->spacecrafts = tempSpeacecrafts;
}

void Fleet::free()
{
    for (unsigned i = 0; i < count; i++)
    {
        delete this->spacecrafts[i];
    }
    
    delete[] this->spacecrafts;
}
