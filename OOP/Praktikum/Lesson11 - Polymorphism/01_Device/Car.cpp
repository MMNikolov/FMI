#include "Car.hpp"

Car::Car()
    : IDevice(), power(0), volumeOfEngine(0)
{}

Car::Car(const char *maker, unsigned power, unsigned volumeOfEngine)
    : IDevice(maker)
{
    //lets just say that this is impossible
    if (power > 10000 || volumeOfEngine > 10000)
    {
        throw std::invalid_argument("Invalid input in Car Constructor");
    }

    this->power = power;
    this->volumeOfEngine = volumeOfEngine;
}

void Car::print() const
{
    std::cout << "Manufacturer: " << this->maker << '\n'
              << "Power of Engine: " << this->power << '\n'
              << "Volume of Engine: " << this->volumeOfEngine << '\n';
}

unsigned Car::get_perf() const
{
    return this->power;
}

IDevice *Car::clone() const
{
    return new Car(*this);
}
