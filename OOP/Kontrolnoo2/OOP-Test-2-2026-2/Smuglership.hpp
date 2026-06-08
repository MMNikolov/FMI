#pragma once

#include "Spacecraft.hpp"
#include "Warship.hpp"
#include "Cargoship.hpp"

class Smuglership : public Warship, public Cargoship
{
public:
    Smuglership(const char* name, int condition, const char* weaponSystem, int firepower, int tonnage, int stealthLevel);

    Smuglership(const Smuglership& other);
    Smuglership& operator=(const Smuglership& other) = delete;

    //calling the default destrcutor

    //overriden methods
    double calculateEffectiveness() const override;
    Spacecraft* clone() const override;
    void print(std::ostream& out) const override;

    //getters
    int GetStealthLevel() const { return this->stealthLevel; }

private:
    int stealthLevel;
};
