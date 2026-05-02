#pragma once

#include <iostream>
#include <stdexcept>
#include <cstring>

class Soldier
{
public:
    //default ctor
    Soldier();

    //parametrized ctor
    Soldier(const char* name, unsigned age, unsigned powerLevel, unsigned gold);

    //copy ctor
    Soldier(const Soldier& other);
    Soldier& operator=(const Soldier& other);

    //destructor
    ~Soldier();

    //getters
    const char* getName() const { return this->name; };
    unsigned getAge() const { return this->age; };
    unsigned getPowerLevel() const { return this->powerLevel; };
    unsigned getGold() const { return this->gold; };

private:
    char* name;
    unsigned age;
    unsigned powerLevel;
    unsigned gold;

    void free();
    void copyFrom(const Soldier& other);
};
