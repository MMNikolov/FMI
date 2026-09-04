#include "Truck.hpp"

Truck::Truck(const char *brand, const char *model, const RegistrationPlate &plate, double weight, const char *cargo)
    : Vehicle(brand, model, plate), weight(0), cargo(nullptr)
{
    if (!cargo || weight < 0)
    {
        throw std::invalid_argument("no");
    }
    
    this->cargo = new char[strlen(cargo) + 1];
    strcpy(this->cargo, cargo);

    this->weight = weight;
}

Truck::Truck(const Truck &other)
    : Vehicle(other), weight(other.weight), cargo(nullptr)
{
    this->cargo = new char[strlen(other.cargo) + 1];
    strcpy(this->cargo, other.cargo);
}

Truck &Truck::operator=(const Truck &other)
{
    if (this != &other)
    {
        Vehicle::operator=(other);
        char* tempCargo = new char[strlen(other.cargo) + 1];
        strcpy(tempCargo, other.cargo);

        free();

        this->weight = other.weight;
        this->cargo = tempCargo;
    }
    
    return *this;
}

Truck::~Truck()
{
    free();
}

double Truck::getTax() const
{
    return (weight * 50);
}

Truck *Truck::clone() const
{
    return new Truck(*this);
}

void Truck::free()
{
    delete[] this->cargo;
}
