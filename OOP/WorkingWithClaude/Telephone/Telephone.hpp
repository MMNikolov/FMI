#ifndef TELEPHONE_HPP
#define TELEPHONE_HPP

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cstring>

class Telephone
{
public:
    Telephone(const char* model, const char* brand, double price);

    Telephone(const Telephone& other);
    Telephone& operator=(const Telephone& other);

    virtual ~Telephone();

    //methods
    const char* getModel() const { return this->model; };
    const char* getBrand() const { return this->brand; };
    virtual double getPrice() const { return this->price; }
    virtual Telephone* clone() const;

private:
    char* model;
    char* brand;
    double price;

private:
    void free();
};

#endif // TELEPHONE_HPP