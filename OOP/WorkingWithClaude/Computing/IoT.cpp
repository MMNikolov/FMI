#include "IoT.hpp"

IoT::IoT(const char *brand, const char *model, double Ghz, const Architecture &arch, const char *sensors)
    : ComputingDevice(brand, model, Ghz, arch), sensors(nullptr)
// arch doesnt need validating it does that from the ComputingDevice in the init list
{
    if (!sensors)
    {
        throw std::invalid_argument("No");
    }

    this->sensors = new char[strlen(sensors) + 1];
    strcpy(this->sensors, sensors);
}

IoT::IoT(const IoT &other)
    : ComputingDevice(other), sensors(nullptr)
{
    this->sensors = new char[strlen(other.sensors) + 1];
    strcpy(this->sensors, other.sensors);
}

IoT &IoT::operator=(const IoT &other)
{
    if (this != &other)
    {
        ComputingDevice::operator=(other);
        char *tempSensors = new char[strlen(other.sensors) + 1];
        strcpy(tempSensors, other.sensors);

        free();
        this->sensors = tempSensors;
    }

    return *this;
}

IoT::~IoT()
{
    free();
}

unsigned IoT::compute(u_int8_t *nums, size_t count) const
{
    if (!hasMinCalc())
    {
        return 0;
    }
    return min(nums, count);
}

IoT *IoT::clone() const
{
    return new IoT(*this);
}

void IoT::free()
{
    delete[] this->sensors;
}

unsigned IoT::min(u_int8_t *nums, size_t count)
{
    unsigned minRes = nums[0];
    for (size_t i = 1; i < count; i++)
    {
        if (nums[i] < minRes)
        {
            minRes = nums[i];
        }
    }

    return minRes;
}

bool IoT::hasMinCalc() const
{
    const char *target = "min-calc";
    size_t targetLen = strlen(target); // 8

    const char *p = sensors;
    while (*p != '\0')
    {
        // Does "target" match starting EXACTLY at this position?
        // Fresh check every time -- j always restarts at 0 here.
        bool matches = true;
        for (size_t j = 0; j < targetLen; j++)
        {
            if (p[j] != target[j]) // p[j] is just pointer arithmetic: *(p + j)
            {
                matches = false;
                break;
            }
        }

        if (matches)
        {
            // p[targetLen] is always safe to read here: the inner loop only
            // finishes with matches==true if every one of p[0..targetLen-1]
            // was a real, non-null character, so p[targetLen] is guaranteed
            // to point at a real character too (possibly the '\0' itself).
            bool validStart = (p == sensors) || (*(p - 1) == ' ');
            bool validEnd = (p[targetLen] == '\0') || (p[targetLen] == ' ');

            if (validStart && validEnd)
            {
                return true;
            }
        }

        p++; // step to the next starting position -- exactly once
    }

    return false;
}
