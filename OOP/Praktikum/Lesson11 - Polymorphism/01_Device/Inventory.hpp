#pragma once

#include "Device.hpp"
#define MAX_INV_SIZE 100

class Inventory
{
public:
    Inventory();
    Inventory(const Inventory& other);
    Inventory& operator=(const Inventory& other);
    ~Inventory();

    //methods
    void printDevices() const;
    void addDevice(const IDevice& device);
    bool isSorted();

private:
    IDevice *devices[MAX_INV_SIZE];
    unsigned count;

private:
    void free();
    void copyFrom(const Inventory& other);
};
