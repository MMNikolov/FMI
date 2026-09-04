#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include "RegistrationPlate.hpp"

class Vehicle
{
public:
    Vehicle(const char* brand, const char* model, const RegistrationPlate& plate);

    Vehicle(const Vehicle& other);
    Vehicle& operator=(const Vehicle& other);

    virtual ~Vehicle();

    //methods
    virtual double getTax() const = 0;
    virtual Vehicle* clone() const = 0;

    //getters
    const char* getBrand() const { return this->brand; };
    const char* getModel() const { return this->model; };
    RegistrationPlate getPlate() const { return this->plate; };

private:
    char* brand;
    char* model;
    RegistrationPlate plate;

private:
    void free();
};

#endif