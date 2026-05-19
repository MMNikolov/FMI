#include "Device.hpp"

IDevice::IDevice()
{
    this->maker = new char[1];
    this->maker[0] = '\0';
}

IDevice::IDevice(const char *maker)
    : maker(nullptr)
{
    if (!maker)
    {
        throw std::invalid_argument("Invalid maker in IDevice!");
    }

    this->maker = new char[strlen(maker) + 1];
    strcpy(this->maker, maker);
}

IDevice::IDevice(const IDevice &other)
{
    copyFrom(other);
}

IDevice &IDevice::operator=(const IDevice &other)
{
    if (this != &other)
    {
        char* tempMaker = new char[strlen(other.maker) + 1];
        strcpy(tempMaker, other.maker);

        free();
        this->maker = tempMaker;
    }
    
    return *this;
}

IDevice::~IDevice()
{
    free();
}

void IDevice::free()
{
    delete[] this->maker;
}

void IDevice::copyFrom(const IDevice &other)
{
    this->maker = new char[strlen(other.maker) + 1];
    strcpy(this->maker, other.maker);
}
