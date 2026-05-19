#include "Laptop.hpp"

Laptop::Laptop()
    : IDevice(), MGHz(0)
{}

Laptop::Laptop(const char *maker, unsigned MGHz)
    : IDevice(maker), MGHz(0)
{
    // lets say that this is impossible
    if (MGHz > 10000)
    {
        throw std::invalid_argument("Cant have this much MGHz");
    }
    
    this->MGHz = MGHz;
}

void Laptop::print() const
{
    std::cout << "Manufacturer: " << this->maker << '\n'
              << "MGHz: " << this->MGHz << '\n';
}

unsigned Laptop::get_perf() const
{
    return this->MGHz;
}

IDevice *Laptop::clone() const
{
    return new Laptop(*this);
}
