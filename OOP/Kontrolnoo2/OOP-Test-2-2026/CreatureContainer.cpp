#include "CreatureContainer.hpp"

CreatureContainer::CreatureContainer(int capacity)
{
    if (capacity < 0 || capacity > MAX_SIZE)
    {
        throw std::invalid_argument("Invalid");
    }
    
    this->capacity = capacity;
    this->creatures = new MythicalCreature*[this->capacity];
}

CreatureContainer::~CreatureContainer()
{
    free();
}

void CreatureContainer::add(const MythicalCreature &creature)
{
    if (this->count >= this->capacity)
    {
        throw std::invalid_argument("Invalid");
    }
    
    this->creatures[this->count++] = creature.clone();
}

void CreatureContainer::append(const CreatureContainer &container)
{
    if (this->count + container.count >= this->capacity)
    {
        throw std::invalid_argument("Invalid");
    }
    
    for (unsigned i = 0; i < container.count; i++)
    {
        this->creatures[this->count + i] = container.creatures[i]->clone();
    }
    
}

MythicalCreature *CreatureContainer::find(const char *name)
{
    if (!name)
    {
        throw std::invalid_argument("Invalid");
    }

    for (unsigned i = 0; i < this->count; i++)
    {
        if (strcmp(this->creatures[i]->GetName(), name) == 0)
        {
            return this->creatures[i];
        }
    }
    
    return nullptr;
}

MythicalCreature **CreatureContainer::findByBlood(const char *blood)
{
    int bloodCount = 0;
    for (unsigned i = 0; i < count; i++)
    {
        if (strcmp(this->creatures[i]->GetBlood(), blood) == 0)
        {
            bloodCount++;
        }
    }
    
    if (bloodCount <= 0)
    {
        return nullptr;
    }
    
    MythicalCreature** bloodRelatives = new MythicalCreature*[bloodCount];
    int index = 0;
    for (unsigned i = 0; i < count; i++)
    {
        if (strcmp(this->creatures[i]->GetBlood(), blood) == 0)
        {
            bloodRelatives[index++] = this->creatures[i]->clone();
        }
    }
    
    return bloodRelatives;
}

MythicalCreature **CreatureContainer::findMinAltitude(int altitude)
{
    int flyingCreatures = 0;
    for (unsigned i = 0; i < count; i++)
    {
        if (dynamic_cast<Flying*>(this->creatures[i])->GetAltitude() > altitude)
        {
            flyingCreatures++;
        }
    }
    
    if (flyingCreatures <= 0)
    {
        return 0;
    }
    
    MythicalCreature** flyingMfs = new MythicalCreature*[flyingCreatures];
    int index = 0;
    for (unsigned i = 0; i < count; i++)
    {
        if (dynamic_cast<Flying*>(this->creatures[i])->GetAltitude() > altitude)
        {
            flyingMfs[index++] = this->creatures[i]->clone();
        }
    }
    return flyingMfs;
}

void CreatureContainer::remove(const char *name)
{
    if (!name)
    {
        throw std::invalid_argument("Invlid name");
    }
    
    for (unsigned i = 0; i < count; i++)
    {
        if (strcmp(this->creatures[i]->GetName(), name) == 0)
        {
            delete[] this->creatures[i];

            for (int j = i; j < count - 1; j++) 
            {
                this->creatures[j] = this->creatures[j + 1];
            }
            
            this->creatures[count - 1] = nullptr;
            this->count--;
            return;
        }
    }
}

void CreatureContainer::free()
{
    for (unsigned i = 0; i < count; i++)
    {
        delete this->creatures[i];
    }
    
    delete[] this->creatures;
}
