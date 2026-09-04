#ifndef COMPUTINGDEVICE_HPP
#define COMPUTINGDEVICE_HPP

#include "Architecture.hpp"

class ComputingDevice
{
public:
    ComputingDevice(const char* brand, const char* model, double Ghz, const Architecture& arch);

    ComputingDevice(const ComputingDevice& other);
    ComputingDevice& operator=(const ComputingDevice& other);

    virtual ~ComputingDevice();

    //methods
    virtual unsigned compute(u_int8_t* nums, size_t count) const = 0;
    virtual ComputingDevice* clone() const = 0;

    //getters
    const char* getBrand() const { return this->brand; };
    const char* getModel() const { return this->model; };
    double getGhz() const { return this->Ghz; };
    Architecture getArch() const { return this->arch; };

    //setters
    void setBrand(const char* newBrand);
    void setModel(const char* newModel);
    void setGhz(double Ghz);

private:
    char* brand;
    char* model;
    double Ghz;
    const Architecture arch;

private:
    void free();
    static Architecture validateArch(const Architecture& arch);
};

#endif // COMPUTINGDEVICE_HPP