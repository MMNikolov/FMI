#pragma once

#include "Spacecraft.hpp"

class Cargoship : public virtual Spacecraft
{
public:
    Cargoship(const char* name, int condition, int tonnage);

    Cargoship(const Cargoship& other);
    Cargoship& operator=(const Cargoship& other) = delete;

    //Calling the defaul destructor

    //overriden methods
    double calculateEffectiveness() const override;
    Spacecraft* clone() const override;
    void print(std::ostream& out) const override;

    //getters
    int GetTonnage() const { return this->tonnage; }

protected:
    int tonnage;
};
