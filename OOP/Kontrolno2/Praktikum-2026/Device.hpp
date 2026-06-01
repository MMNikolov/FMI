#pragma once

#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>

class Device
{
public:
    Device(const char* name);

    Device(const Device& other);
    Device& operator=(const Device& other);

    virtual ~Device();

    //getters
    virtual unsigned GetId() const = 0;
    virtual const char* GetName() const = 0;

    //methods
    virtual void print(std::ostream& out) const = 0;
    virtual const char* GetType() const = 0;
    virtual Device* clone() const = 0;

protected:
    const unsigned id;
    char* name;

    static unsigned GlobalId;
    static unsigned Incrementer();

private:
    void free();
    void copyFrom(const Device& other);
};
