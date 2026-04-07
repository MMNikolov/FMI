#include "Parking.hpp"

// ---------------------------
// CAR FUNCTIONALITY
// ---------------------------

void Car::copyFrom(const Car& other)
{
    this->licencePlate = new char[strlen(other.licencePlate) + 1];
    strcpy(this->licencePlate, other.licencePlate);

    this->minuteEntered = other.minuteEntered;
}

void Car::free()
{
    delete[] licencePlate;
    this->licencePlate = nullptr;
}

Car::Car() : licencePlate(nullptr), minuteEntered(0)
{
    this->licencePlate = new char[1];
    this->licencePlate[0] = '\0';
}

Car::Car(const char* licencePlate, unsigned int minutesParked)
{
    if (!licencePlate || strlen(licencePlate) > MAX_PLATE_STRING)
    {
        throw std::invalid_argument("There is a problem with the initialization of the Car");
    }
    
    this->licencePlate = new char[strlen(licencePlate) + 1];
    strcpy(this->licencePlate, licencePlate);
    this->minuteEntered = minutesParked;
}

Car& Car::operator=(const Car& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    
    return *this;
}

Car::~Car()
{
    free();
}

char* Car::GetLicencePlate() const
{
    return this->licencePlate;
}

unsigned int Car::GetMinuteEntered() const
{
    return this->minuteEntered;
}

// ---------------------------
// PARKING FUNCTIONALITY
// ---------------------------

void Parking::copyFrom(const Parking& other)
{
    this->parkingCapacity = other.parkingCapacity;
    this->carsEntered = other.carsEntered;

    for (unsigned short i = 0; i < carsEntered; i++)
    {
        this->cars[i] = other.cars[i];
    }
}

Parking::Parking() : parkingCapacity(0), carsEntered(0) {};

Parking::Parking(Car& cars, unsigned int parkingCapacity) : carsEntered(0)
{
    this->parkingCapacity = parkingCapacity;
    this->carsEntered = 0;
}

Parking& Parking::operator=(const Parking& other)
{
    if (this != &other)
    {
        copyFrom(other);
    }

    return *this;
}   

void Parking::Enter(Car& car)
{
    if (this->carsEntered >= MAX_CAR_CAPACITY)
    {
        throw std::invalid_argument("Cannot exceed the limit in the parking");
    }
    
    this->cars[carsEntered] = car;
    carsEntered++;
}

void Parking::Leave(Car& car, unsigned int minutesPassed, double taxRate)
{
    double hours;
    char* carsLicencePlate = car.GetLicencePlate();

    for (unsigned short i = 0; i < this->carsEntered; i++)
    {
        if (strcmp(carsLicencePlate, this->cars[i].GetLicencePlate()) == 0)
        {
            hours = minutesPassed / 60;
            std::cout << "This car needs to pay: " << hours * taxRate << " BGN for staying\n";
            this->cars[i] = this->cars[carsEntered - 1];
            this->carsEntered--;
            return;
        }
        
        continue;
    }
    
    std::cout << "There is no car with this licence plate in the parking\n";
    return;
}

bool Parking::isRegistered(Car& car)
{
    char* carsLicencePlate = car.GetLicencePlate();

    for (unsigned short i = 0; i < this->carsEntered; i++)
    {
        if (strcmp(carsLicencePlate, this->cars[i].GetLicencePlate()) == 0)
        {
            return true;
        }
    }
    
    return false;
}

void Parking::printCars()
{
    std::cout << "All the cars in the parking:\n";

    for (unsigned short i = 0; i < this->carsEntered; i++)
    {
        std::cout << " - " << this->cars[i].GetLicencePlate() << "\n";
    }
}