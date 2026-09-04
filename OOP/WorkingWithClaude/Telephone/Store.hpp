#ifndef STORE_HPP
#define STORE_HPP

#include "Telephone.hpp"
#include "Smartphone.hpp"
#define STARTING_CAPACITY 4

class Store
{
public:
    Store(const double budget);

    Store(const Store& other);
    Store& operator=(const Store& other);

    ~Store();

    //methods
    void addTelephone(const Telephone& phone);
    bool removeTelephone(const char* model, const char* brand);


private:
    //this will be out heterogeneous container without a fixed size (for the challenge :D)
    Telephone** phones;
    unsigned count;
    unsigned capacity;
    double currentBudget;
    const double budget;

private:
    void free();
    void resize();
};

double validateBudget(const double budget);

#endif // STORE_HPP