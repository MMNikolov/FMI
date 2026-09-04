#ifndef CAR_HPP
#define CAR_HPP

#include <iostream>
#include "Date.hpp"

class Car
{
public:
    Car();
    Car(const char* model, const Date& date, const char* trunk, unsigned horsePower, unsigned seats);
    Car(std::istream& in);   // builds a Car from text previously written by print()

    Car(const Car& other);
    Car& operator=(const Car& other);
    ~Car();

    void print(std::ostream& out) const;   // CHANGED: non-const, non-ofstream-specific --
                                             // writing through a stream reference requires
                                             // non-const, and ostream works with cout, files,
                                             // stringstreams, anything.

    const char* getModel() const { return this->model; }
    const Date& getDate() const { return this->dateOfManufacture; }
    const char* getTrunk() const { return this->trunk; }
    unsigned getHorsePower() const { return this->horsePower; }
    unsigned getSeats() const { return this->seats; }

    // Total horsepower across every currently-alive Car object.
    static unsigned getTotalHorsePower() { return totalHorsePower; }

private:
    char* model;
    Date dateOfManufacture;
    const char* trunk;   // ALWAYS points at one of 3 fixed string literals below --
                          // never dynamically allocated, never owned, never delete[]'d.
    unsigned horsePower;
    unsigned seats;

    static unsigned totalHorsePower;   // one shared value for the whole class

private:
    void free();
};

// Returns one of exactly three fixed literals if trunk matches (case-sensitive,
// exact match including length), or throws if it doesn't match any of them.
const char* validateTrunk(const char* trunk);

#endif