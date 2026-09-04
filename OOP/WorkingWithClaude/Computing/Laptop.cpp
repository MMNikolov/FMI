#include "Laptop.hpp"

Laptop::Laptop(const char *brand, const char *model, double Ghz, const Architecture &arch, unsigned RAM, unsigned memory)
    : ComputingDevice(brand, model, Ghz, Laptop::validateArch(arch)), RAM(RAM), memory(memory)
{ }

Laptop::Laptop(const Laptop &other)
    : ComputingDevice(other), RAM(other.RAM), memory(other.memory)
{ }

Laptop &Laptop::operator=(const Laptop &other)
{
    if (this != &other)
    {
        ComputingDevice::operator=(other);
        this->RAM = other.RAM;
        this->memory = other.memory;
    }
    
    return *this;
}

Laptop::~Laptop()
{ }

unsigned Laptop::compute(u_int8_t *nums, size_t count) const
{
    int res = 0;
    for (size_t i = 0; i < count; i++)
    {
        res += nums[i];
    }
    
    if (res > this->RAM)
    {
        throw std::invalid_argument("No");
    }
    
    return res;
}

Laptop *Laptop::clone() const
{
    return new Laptop(*this);
}

void Laptop::setRam(unsigned RAM)
{
    this->RAM = RAM;
}

void Laptop::setMemory(unsigned Memory)
{
    this->memory = Memory;
}

Architecture Laptop::validateArch(const Architecture &arch)
{
    if (arch != X86_64 && arch != ARM)
    {
        throw std::invalid_argument("Laptop must be x86-64 or ARM architecture");
    }

    return arch;
}
