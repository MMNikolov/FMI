#include "Automobile.hpp"

Automobile::Automobile(const char *brand, const char *model, const RegistrationPlate &plate, const char *engine, unsigned horsePower)
    : Vehicle(brand, model, plate), engine(nullptr), horsePower(horsePower)
{
    if (!engine)
    {
        throw std::invalid_argument("no");
    }
    
    this->engine = new char[strlen(engine) + 1];
    strcpy(this->engine, engine);
}

//we can do that because of slicing
Automobile::Automobile(const Automobile &other)
    : Vehicle(other), engine(nullptr), horsePower(other.horsePower)
{
    this->engine = new char[strlen(other.engine) + 1];
    strcpy(this->engine, other.engine);
}

Automobile &Automobile::operator=(const Automobile &other)
{
    if (this != &other)
    {
        //once again with the power of slicing
        Vehicle::operator=(other);
        char* tempEngine = new char[strlen(other.engine) + 1];
        strcpy(tempEngine, other.engine);

        free();

        this->engine = tempEngine;
        this->horsePower = other.horsePower;
    }
    
    return *this;
}

Automobile::~Automobile()
{
    free();
}

double Automobile::getTax() const
{
    return (this->horsePower * 10);
}

Automobile *Automobile::clone() const
{
    return new Automobile(*this);
}

void Automobile::free()
{
    delete[] this->engine;
}
