#pragma once

#include <iostream>
#include <cstring>
#include <stdexcept>

//constraints
#define MAX_SIZE_OF_NAME 30
#define MAX_CASHIERS_IN_STORE 10

class Cashier
{
public:
    //initializing the default constructor
    Cashier();

    //the ordinary constructor that we are going to use
    Cashier(const char *name, double turnoverBGN);

    //copy constructor
    Cashier& operator=(const Cashier& other);
    ~Cashier();

    void read(std::istream& in);
    void print(std::ostream& out) const;

    const char* getName() const;
    double getTurnover() const;

private:
    //validation for name will come in the constructor
    char* name;
    double turnoverBGN;

    void copyFrom(const Cashier& other);
    void free();
};

class Store
{
public:
    //default constructor
    Store();

    //the ordinary constructor
    Store(const char* name);

    //copy constructor
    Store& operator=(const Store& other);
    ~Store();

    
    void addCashiers(const Cashier& cashier);
    void read(std::istream& in);
    void print(std::ostream& out) const;

    double getTotalTurnover() const;
    const Cashier* findCashierByName(const char* searchName);

    int equals(const Store& other) const;

private:
    char* name;
    Cashier cashiers[MAX_CASHIERS_IN_STORE];
    short cashiersCount;

    void copyFrom(const Store& other);
    void free();
};
