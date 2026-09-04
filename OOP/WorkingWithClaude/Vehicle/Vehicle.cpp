#include "Vehicle.hpp"

Vehicle::Vehicle(const char *brand, const char *model, const RegistrationPlate &plate)
    : brand(nullptr), model(nullptr), plate(plate)
{
    if (!brand || !model)
    {
        throw std::invalid_argument("no");
    }
    
    this->brand = new char[strlen(brand) + 1];
    strcpy(this->brand, brand);

    this->model = new (std::nothrow) char[strlen(model) + 1];
    if (!this->model)
    {
        delete[] this->brand;
        throw std::bad_alloc();
    }
    strcpy(this->model, model);
}

Vehicle::Vehicle(const Vehicle &other)
    : brand(nullptr), model(nullptr), plate(other.plate)
{
    this->brand = new char[strlen(other.brand) + 1];
    strcpy(this->brand, other.brand);

    this->model = new (std::nothrow) char[strlen(other.model) + 1];
    if (!this->model)
    {
        delete[] this->brand;
        throw std::bad_alloc();
    }
    strcpy(this->model, other.model);
}

Vehicle &Vehicle::operator=(const Vehicle &other)
{
    if (this != &other)
    {
        char* tempBrand = new char[strlen(other.brand) + 1];
        strcpy(tempBrand, other.brand);

        char* tempModel = new (std::nothrow) char[strlen(other.model) + 1];
        if (!tempModel)
        {
            delete[] tempBrand;
            throw std::bad_alloc();
        }
        strcpy(tempModel, other.model);

        free();

        this->brand = tempBrand;
        this->model = tempModel;
        this->plate = other.plate;
    }
    
    return *this;
}

Vehicle::~Vehicle()
{
    free();
}

void Vehicle::free()
{
    delete[] this->brand;
    delete[] this->model;
}
