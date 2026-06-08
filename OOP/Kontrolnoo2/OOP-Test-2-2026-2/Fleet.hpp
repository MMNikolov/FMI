#pragma once

#include "Spacecraft.hpp"
#include "Warship.hpp"
#include "Cargoship.hpp"
#include "Smuglership.hpp"

#define STARTING_CAPACITY 2

class Fleet
{
public:
    Fleet();

    Fleet(const Fleet& other);
    Fleet& operator=(const Fleet& other);

    ~Fleet();

    //methods
    void operator+=(const Spacecraft& spacecraft);
    void operator-=(unsigned id);
    Spacecraft* GetMostEffective() const;
    Spacecraft** extractDamaged(int threshold, int& outCount);
    void saveToFile(const char* filename);
    void loadFromFile(const char* filename);

    //getters
    unsigned GetCapacity() const { return this->capacity; }
    unsigned GetCount() const { return this->count; }

private:
    Spacecraft** spacecrafts;
    unsigned capacity;
    unsigned count;

private:
    void resize();
    void free();
};
