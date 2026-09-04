#ifndef DEALERSHIP_HPP
#define DEALERSHIP_HPP

#include "Car.hpp"

struct Listing 
{
    Car* car;
    double price;
};

class Dealership
{
public:
    Dealership(unsigned capacity);

    Dealership(const Dealership& other);
    Dealership& operator=(const Dealership& other);

    ~Dealership();

    //methods
    bool add(const Car& car, double price);
    bool sell(unsigned count);
    void printCars() const;

    void searchBrand(const char* brand) const;
    void serachByValue(double price) const;
    void searchByDate(const Date& date) const;

private:
    Listing* listings;
    unsigned count;
    unsigned capacity;
    double allCarsPrice;

private:
    void free();
};

#endif // DEALSHIP_HPP