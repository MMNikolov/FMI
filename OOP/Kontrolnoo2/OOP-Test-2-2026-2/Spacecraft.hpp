#pragma once

#include <iostream>
#include <cstring>
#include <fstream>
#include <stdexcept>

#define MAX_CONDITION_STAT 100

class Spacecraft
{
public:
    Spacecraft(const char* name, int condition);

    Spacecraft(const Spacecraft& other);
    Spacecraft& operator=(const Spacecraft& other) = delete;

    virtual ~Spacecraft();

    //methods
    virtual double calculateEffectiveness() const = 0;
    virtual Spacecraft* clone() const = 0;
    virtual void print(std::ostream& out) const = 0;

    //getters
    unsigned GetId() const { return this->id; }
    const char* GetName() const { return this->name; }
    unsigned GetCondition() const { return this->condition; }
    
protected:
    const unsigned id;
    char* name;
    int condition;

private:
    static unsigned GlobalId;
    static unsigned Incrementer();

    void free();
    void copyFrom(const Spacecraft& other);
};
