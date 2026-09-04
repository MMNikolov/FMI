#ifndef AUTOMOBILE_HPP
#define AUTOMOBILE_HPP

#include "Vehicle.hpp"

class Automobile : public Vehicle
{
public:
    Automobile(const char* brand, const char* model, const RegistrationPlate& plate, const char* engine, unsigned horsePower);

    Automobile(const Automobile& other);
    Automobile& operator=(const Automobile& other);

    ~Automobile();

    //methods
    double getTax() const override;
    Automobile* clone() const override;

    //getters
    const char* getEngine() const { return this->engine; };
    unsigned getHorsePower() const { return this->horsePower; };

private:
    char* engine;
    unsigned horsePower;

private:
    void free();
};

#endif