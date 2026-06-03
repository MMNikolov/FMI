#pragma once

#include "Device.hpp"

class Connection
{
public:
    Connection();
    Connection(Device* device, unsigned tick);

    //copy ctor
    Connection(const Connection& other);
    Connection& operator=(const Connection& other);

    ~Connection();

    Device* getDevice() const { return this->device; }
    unsigned getTick() const { return this->tick; }
    
private:
    Device* device;
    unsigned tick;

    void copyFrom(const Connection& other);
    void free();
};
