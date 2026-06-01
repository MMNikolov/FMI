#include "MobileDevice.hpp"

MobileDevice::MobileDevice(const char *name, int battery)
    : Device(name)
{
    if (battery < 0 || battery > 100)
    {
        throw std::invalid_argument("Invalid inout for the battery");
    }
    
    this->battery = battery;
}

MobileDevice::MobileDevice(const MobileDevice &other)
    : Device(other.name), battery(other.battery)
{}

unsigned MobileDevice::GetId() const
{
    return this->id;
}

const char *MobileDevice::GetName() const
{
    return this->name;
}

int MobileDevice::GetBattery() const
{
    return this->battery;
}

void MobileDevice::print(std::ostream &out) const
{
    out << this->id << ' ' << this->name << ' ' << this->battery << '\n';
}

const char *MobileDevice::GetType() const
{
    return "mobile";
}

Device *MobileDevice::clone() const
{
    return new MobileDevice(*this);
}
