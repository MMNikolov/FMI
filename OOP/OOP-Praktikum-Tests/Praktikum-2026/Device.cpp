#include "Device.hpp"

unsigned Device::GlobalId = 0;

Device::Device(unsigned explicitId, const char *name)
    : id(explicitId)
{
    if (!name)
    {
        throw std::invalid_argument("Not valid input in Device");
    }

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    if (explicitId > GlobalId)
    {
        GlobalId = explicitId;
    }
}

Device::Device(const char *name)
    : id(Incrementer())
{
    if (!name)
    {
        throw std::invalid_argument("Not valid g");
    }
    
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

Device::Device(const Device &other)
    : id(other.id)
{
    copyFrom(other);
}

Device &Device::operator=(const Device &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }

    return *this;
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

void Device::copyFrom(const Device &other)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
}
