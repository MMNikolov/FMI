#include "ComputingCenter.hpp"

ComputingCenter::ComputingCenter()
    : count(0)
{
    this->devices = new ComputingDevice*[MAX_DEVICES];
    for (unsigned i = 0; i < MAX_DEVICES; i++)
    {
        this->devices[i] = nullptr;
    }
}

ComputingCenter::ComputingCenter(const ComputingCenter &other)
    : count(other.count)
{
    this->devices = new ComputingDevice*[MAX_DEVICES];
    for (unsigned i = 0; i < count; i++)
    {
        this->devices[i] = other.devices[i]->clone();
    }
    for (unsigned i = count; i < MAX_DEVICES - 1; i++)
    {
        this->devices[i] = nullptr;
    }
}

ComputingCenter &ComputingCenter::operator=(const ComputingCenter &other)
{
    if (this != &other)
    {
        ComputingDevice** tempDevices = new ComputingDevice*[MAX_DEVICES];
        for (unsigned i = 0; i < other.count; i++)
        {
            //only pointers
            tempDevices[i] = other.devices[i]->clone();
        }
        
        free();
        this->devices = tempDevices;
        this->count = other.count;
    }
    
    return *this;
}

ComputingCenter::~ComputingCenter()
{
    free();
}

void ComputingCenter::addDevice(const ComputingDevice &device)
{
    if (this->count >= MAX_DEVICES)
    {
        throw std::invalid_argument("No");
    }
    
    this->devices[count++] = device.clone();
}

bool ComputingCenter::removeDevice(const char *brand)
{
    if (!brand || this->count <= 0)
    {
        throw std::invalid_argument("No");
    }
    
    int removed = 0;
    for (unsigned i = 0; i < count; i++)
    {
        if (strcmp(this->devices[i]->getBrand(), brand) == 0)
        {
            delete this->devices[i];
            this->devices[i] = nullptr;
            this->devices[i] = this->devices[count - 1];
            this->devices[count - 1] = nullptr;
            count--;
            removed++;
            i--;
        }
    }
    
    if (removed > 0)
    {
        return true;
    }
    
    return false;
}

void ComputingCenter::compute(u_int8_t *nums, size_t count) const
{
    if (count <= 0)
    {
        throw std::invalid_argument("no");
    }
    
    for (unsigned i = 0; i < this->count; i++)
    {
        std::cout << "Device number: " << (i + 1) << ';' << this->devices[i]->compute(nums, count) << "Computed by a: " << this->devices[i]->getBrand() << "\n";
    }
}

void ComputingCenter::free()
{
    for (unsigned i = 0; i < count; i++)
    {
        delete this->devices[i];
    }

    delete[] this->devices;
}
