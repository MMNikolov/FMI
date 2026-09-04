#ifndef COMPUTING_CENTER
#define COMPUTING_CENTER

#include "ComputingDevice.hpp"
#define MAX_DEVICES 16

class ComputingCenter
{
public:
    ComputingCenter();

    ComputingCenter(const ComputingCenter& other);
    ComputingCenter& operator=(const ComputingCenter& other);

    ~ComputingCenter();

    //methods
    void addDevice(const ComputingDevice& device);
    bool removeDevice(const char* brand);
    void compute(u_int8_t* nums, size_t count) const;

private:
    //heterogenous container with fixed size
    ComputingDevice** devices;
    unsigned count;

private:
    void free();
};

#endif
