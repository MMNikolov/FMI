#pragma once

#include "Device.hpp"

class MobileDevice : public Device
{
public:
    MobileDevice(const char* name, int battery);

    MobileDevice(const MobileDevice& other);
    MobileDevice& operator=(const MobileDevice& other) = delete;

    //no need for a destructor

    //overriden getters
    unsigned GetId() const override;
    const char* GetName() const override;

    //normal getters
    int GetBattery() const;

    //overriden methods
    void print(std::ostream& out) const override;
    const char* GetType() const override;
    Device* clone() const override;

    //normal methods
    //none

private:
    int battery;
};
