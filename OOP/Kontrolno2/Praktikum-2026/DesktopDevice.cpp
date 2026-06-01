#include "DesktopDevice.hpp"

DesktopDevice::DesktopDevice(const char *name, const char *URL)
    : Device(name)
{
    if (!URL || URL[0] == '\0')
    {
        throw std::invalid_argument("Invalid input in the Desktop Device");
    }
    
    this->URL = new char[strlen(URL) + 1];
    strcpy(this->URL, URL);
}

DesktopDevice::DesktopDevice(const DesktopDevice &other)
    : Device(other.name)
{
    copyFrom(other);
}

DesktopDevice &DesktopDevice::operator=(const DesktopDevice &other)
{
    if (this != &other)
    {
        Device::operator=(other);
        copyFrom(other);
    }
    
    return *this;
}

DesktopDevice::~DesktopDevice()
{
    free();
}

unsigned DesktopDevice::GetId() const
{
    return this->id;
}

const char *DesktopDevice::GetName() const
{
    return this->name;
}

const char *DesktopDevice::GetURL() const
{
    return this->URL;
}

void DesktopDevice::print(std::ostream &out) const
{
    out << this->id << ' ' << this->name << ' ' << this->URL << '\n';
}

const char *DesktopDevice::GetType() const
{
    return "desktop";
}

Device *DesktopDevice::clone() const
{
    return new DesktopDevice(*this);
}

void DesktopDevice::free()
{
    delete[] this->URL;
}

void DesktopDevice::copyFrom(const DesktopDevice &other)
{
    this->URL = new char[strlen(other.URL) + 1];
    strcpy(this->URL, other.URL);
}
