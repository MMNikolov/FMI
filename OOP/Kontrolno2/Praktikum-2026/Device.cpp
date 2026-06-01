#include "Device.hpp"

unsigned Device::GlobalId = 0;

Device::Device(const char *name)
    : id(Incrementer())
{
    if (!name)
    {
        throw std::invalid_argument("Not valid inut in Device");
    }
    
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

Device::Device(const Device &other)
    : id(Incrementer())
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
}

Device::~Device()
{
    free();
}

unsigned Device::Incrementer()
{
    return ++GlobalId;
}

void Device::free()
{
    delete[] this->name;
}

