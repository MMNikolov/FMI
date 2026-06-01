#pragma once

#include "Device.hpp"

class DesktopDevice : public Device
{
public:
    DesktopDevice(const char* name, const char* URL);

    DesktopDevice(const DesktopDevice& other);
    DesktopDevice& operator=(const DesktopDevice& other) = delete;

    ~DesktopDevice();

    //overriden getters
    unsigned GetId() const override;
    const char* GetName() const override;

    //normal getters
    const char* GetURL() const;

    //overriden methods
    void print(std::ostream& out) const override;
    const char* GetType() const override;
    Device* clone() const override;

    //normal methods
    //none

private:
    char* URL;

    void free();
};
