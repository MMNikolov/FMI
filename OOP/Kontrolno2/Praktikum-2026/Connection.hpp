#pragma once

#include "Device.hpp"

class Connection
{
public:
    Connection();
    ~Connection();

private:
    unsigned tact;
    Device* device;
};
