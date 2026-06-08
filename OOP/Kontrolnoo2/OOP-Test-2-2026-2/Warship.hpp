#pragma once

#include "Spacecraft.hpp"

class Warship : public virtual Spacecraft
{
public:
    Warship(const char* name, int condition, const char* weaponSystem, int firepower);

    Warship(const Warship& other);
    Warship& operator=(const Warship& other) = delete;

    ~Warship();

    //overriden methods
    double calculateEffectiveness() const override;
    Spacecraft* clone() const override;
    void print(std::ostream& out) const override;

    //getters
    const char* GetWeaponSystem() const { return this->weaponSystem; }
    int GetFirepower() const { return this->firepower; }

protected:
    char* weaponSystem;
    int firepower;

private: 
    void free();
};
