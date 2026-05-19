#pragma once

#include "Device.hpp"

class Laptop : public IDevice
{
public:
    Laptop();
    Laptop(const char* maker, unsigned MGHz);

    //methods
    void print() const override;
    unsigned get_perf() const override;
    IDevice* clone() const override;

private:
    unsigned MGHz;
};
