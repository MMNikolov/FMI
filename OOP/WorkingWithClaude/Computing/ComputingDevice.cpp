#include "ComputingDevice.hpp"

ComputingDevice::ComputingDevice(const char *brand, const char *model, double Ghz, const Architecture &arch)
    : brand(nullptr), model(nullptr), Ghz(0), arch(validateArch(arch))
{
    if (!brand || !model || Ghz < 0)
    {
        throw std::invalid_argument("No");
    }
    
    this->brand = new char[strlen(brand) + 1];
    strcpy(this->brand, brand);

    this->model = new (std::nothrow) char[strlen(model) + 1];
    if (!this->model)
    {
        delete[] this->brand;
        throw std::bad_alloc();
    }
    strcpy(this->model, model);

    this->Ghz = Ghz;
}

ComputingDevice::ComputingDevice(const ComputingDevice &other)
    : brand(nullptr), model(nullptr), Ghz(other.Ghz), arch(other.arch)
{
    this->brand = new char[strlen(other.brand) + 1];
    strcpy(this->brand, other.brand);

    this->model = new (std::nothrow) char[strlen(other.model) + 1];
    if (!this->model)
    {
        delete[] this->brand;
        throw std::bad_alloc();
    }
    strcpy(this->model, other.model);
}

ComputingDevice &ComputingDevice::operator=(const ComputingDevice &other)
{
    if (this != &other)
    {
        char* tempBrand = new char[strlen(other.brand) + 1];
        strcpy(tempBrand, other.brand);

        char* tempModel = new (std::nothrow) char[strlen(other.model) + 1];
        if (!tempModel)
        {
            delete[] tempBrand;
            throw std::bad_alloc();
        }
        strcpy(tempModel, other.model);

        free();

        this->brand = tempBrand;
        this->model = tempModel;
        this->Ghz = other.Ghz;
    }
    
    return *this;
}

ComputingDevice::~ComputingDevice()
{
    free();
}

void ComputingDevice::setBrand(const char *newBrand)
{
    if (!newBrand)
    {
        throw std::invalid_argument("no");
    }
    
    char* tempBrand = new char[strlen(newBrand) + 1];
    strcpy(tempBrand, newBrand);

    delete[] this->brand;
    this->brand = tempBrand;
}

void ComputingDevice::setModel(const char *newModel)
{
    if (!newModel)
    {
        throw std::invalid_argument("no");
    }
    
    char* tempModel = new char[strlen(newModel) + 1];
    strcpy(tempModel, newModel);

    delete[] this->model;
    this->model = tempModel;
}

void ComputingDevice::setGhz(double Ghz)
{
    if (Ghz < 0)
    {
        throw std::invalid_argument("no");
    }
    
    this->Ghz = Ghz;
}

void ComputingDevice::free()
{
    delete[] this->brand;
    delete[] this->model;
}

Architecture ComputingDevice::validateArch(const Architecture &arch)
{
    if ((int)arch < 0 || (int)arch >= COUNT)
    {
        throw std::invalid_argument("Not a valid architecture");
    }

    return arch;
}
