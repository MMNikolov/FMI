#ifndef IOT_HPP
#define IOT_HPP

#include "ComputingDevice.hpp"
#define STARTING_CAPACITY 4

class IoT : public ComputingDevice
{
public:
    IoT(const char* brand, const char* model, double Ghz, const Architecture& arch, const char* sensors);

    IoT(const IoT& other);
    IoT& operator=(const IoT& other);

    ~IoT();

    //methods
    unsigned compute(u_int8_t* nums, size_t count) const override;
    IoT* clone() const override;

    //getters
    //yea... trivial

private:
    char* sensors;

private:
    void free();
    static unsigned min(u_int8_t* nums, size_t count);
    bool hasMinCalc() const;
};

#endif // IOT_HPP