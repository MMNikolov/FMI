#pragma once

#include "MythicalCreature.hpp"
#include "Flying.hpp"
#include "Magical.hpp"
#include "Dragon.hpp"

#define MAX_SIZE 25

class CreatureContainer
{
public:
    CreatureContainer(int capacity);

    CreatureContainer(const CreatureContainer& other) = delete;
    CreatureContainer& operator=(const CreatureContainer& other) = delete;

    ~CreatureContainer();

    //methods
    void add(const MythicalCreature& creature);
    void append(const CreatureContainer& container);
    MythicalCreature* find(const char* name);
    MythicalCreature** findByBlood(const char* blood);
    MythicalCreature** findMinAltitude(int altitude);
    void remove(const char* name);

    //getters
    int GetCapacity() const { return this->capacity; }
    int GetCount() const { return this->count; }

private:
    MythicalCreature** creatures;
    int capacity;
    int count;

    void free();
};
