#pragma once

#include "Device.hpp"

class Car : public IDevice
{
public:
    Car();
    Car(const char* maker, unsigned power, unsigned volumeOfEngine);

    //methods
    void print() const override;
    unsigned get_perf() const override;
    IDevice* clone() const override;

private:
    unsigned power;
    unsigned volumeOfEngine;
};
