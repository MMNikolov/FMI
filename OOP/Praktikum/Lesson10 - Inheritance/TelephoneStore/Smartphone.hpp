#include "Telephone.hpp"

class Smartphone : public Telephone
{
public:
    //default ctor
    Smartphone();

    //parametrized ctor
    Smartphone(const char* model, const char* maker, double price, const char* os, unsigned memory);

    //copy ctor
    Smartphone(const Smartphone& other);
    Smartphone& operator=(const Smartphone& other);

    //destructor
    ~Smartphone();

    //getters
    const char* getOS() const;
    unsigned getMemory() const;

private:
    char* os;
    unsigned memory;

    void free();
};
