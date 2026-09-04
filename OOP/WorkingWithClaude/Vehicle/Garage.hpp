#ifndef GARAGE_HPP
#define GARAGE_HPP

#include "Vehicle.hpp"
#include "Automobile.hpp"
#include "Truck.hpp"

class Garage
{
public:
    Garage(const unsigned capacity);

    Garage(const Garage& other);
    Garage& operator=(const Garage& other);

    ~Garage();

    //methods
    void addVehicle(const Vehicle& vehicle);
    void removeVehicle(const char* brand, const char* model);
    double getAllTaxes();

    //getters
    unsigned getAutomobileCount() const;
    unsigned getCapacity() const { return this->capacity; };

    //operators
    Vehicle* operator[](unsigned index);

private:
    Vehicle** vehicles;
    unsigned count;
    const unsigned capacity;

private:
    void free();
};

#endif