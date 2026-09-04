#ifndef SMARTPHONE_HPP
#define SMARTPHONE_HPP

#include "Telephone.hpp"

class Smartphone : public Telephone
{
public:
    Smartphone(const char* model, const char* brand, double price, const char* OS, unsigned RAM);

    Smartphone(const Smartphone& other);
    Smartphone& operator=(const Smartphone& other);

    ~Smartphone();

    //methods
    const char* getOS() const { return this->OS; };
    unsigned getRAM() const { return this->RAM; };
    double getPrice() const override;
    Smartphone* clone() const override;

private:
    char* OS;
    unsigned RAM;

private:
    void free();
};

#endif // SMARTPHONE_HPP