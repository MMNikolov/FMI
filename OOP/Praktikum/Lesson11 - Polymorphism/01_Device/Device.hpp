#pragma once

#include <iostream>
#include <stdexcept>
#include <cstring>

class IDevice
{
public:
    IDevice();
    IDevice(const char* maker);
    IDevice(const IDevice& other);
    IDevice& operator=(const IDevice& other);
    virtual ~IDevice();

    //methods
    virtual void print() const = 0;
    virtual unsigned get_perf() const = 0;

    virtual IDevice* clone() const = 0;

    //getters
    const char* getMaker() const { return this->maker; };
    
protected:
    char* maker;

private:
    void free();
    void copyFrom(const IDevice& other);
};
