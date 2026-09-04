#ifndef LAPTOP_HPP
#define LAPTOP_HPP

#include "ComputingDevice.hpp"

class Laptop : public ComputingDevice
{
public:
    Laptop(const char* brand, const char* model, double Ghz, const Architecture& arch, unsigned RAM, unsigned memory);

    Laptop(const Laptop& other);
    Laptop& operator=(const Laptop& other);

    ~Laptop();

    //methods
    unsigned compute(u_int8_t* nums, size_t count) const override;
    Laptop* clone() const override;

    //getters
    unsigned getRAM() const { return this->RAM; };
    unsigned getMemory() const { return this->memory; };

    //setters
    void setRam(unsigned RAM);
    void setMemory(unsigned Memory);

private:
    unsigned RAM;
    unsigned memory;

    static Architecture validateArch(const Architecture& arch);
};

#endif // LAPTOP_HPP