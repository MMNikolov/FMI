#ifndef TRUCK_HPP
#define TRUCK_HPP

#include "Vehicle.hpp"

class Truck : public Vehicle
{
public:
    Truck(const char* brand, const char* model, const RegistrationPlate& plate, double weight, const char* cargo);

    Truck(const Truck& other);
    Truck& operator=(const Truck& other);

    ~Truck();

    //methods
    double getTax() const override;
    Truck* clone() const override;

    //getters
    double getWeight() const { return this->weight; };
    const char* getCargo() const { return this->cargo; };

private:
    double weight;
    char* cargo;

private:
    void free();
};

#endif
