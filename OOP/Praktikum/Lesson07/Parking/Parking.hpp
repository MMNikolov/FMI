#pragma once

#include <iostream>
#include <cstring>

#define MAX_PLATE_STRING 8
#define MAX_CAR_CAPACITY 1280

static double taxRateeeee;

class Car
{
public:
    //default constructor
    Car();

    //the ordinary constructor
    Car(const char* licencePlate, unsigned int minutesParked);

    //copy constructor
    Car(const Car& other);
    Car& operator=(const Car& other);

    //destructor
    ~Car();

    //functions in Car
    char* GetLicencePlate() const;
    unsigned int GetMinuteEntered() const;

private:
    char* licencePlate;
    unsigned int minuteEntered;

    void copyFrom(const Car& other);
    void free();
};

class Parking
{
public:
    // default constructor
    Parking();

    //ordinaty constructor
    Parking(Car& cars, unsigned int parkingCapacity);

    //copy constructor
    Parking(const Parking& other);
    Parking& operator=(const Parking& other);

    void Enter(Car& car);
    void Leave(Car& car, unsigned int minutesPassed, double taxRate);
    bool isRegistered(Car& car);
    void printCars();

private:
    Car cars[MAX_CAR_CAPACITY];
    unsigned short parkingCapacity;
    unsigned short carsEntered;

    void copyFrom(const Parking& other);
    //oid free();
};
