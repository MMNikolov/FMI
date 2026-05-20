#include "Inventory.hpp"

Inventory::Inventory()
    : count(0)
{
    for (unsigned i = 0; i < MAX_INV_SIZE; i++)
    {
        devices[i] = nullptr;
    }
}

Inventory::Inventory(const Inventory &other)
{
    copyFrom(other);
}

Inventory& Inventory::operator=(const Inventory& other)
{
    if (this == &other)
    {
        return *this;
    }

    IDevice* tempDevices[MAX_INV_SIZE];
    for (int i = 0; i < MAX_INV_SIZE; ++i)
    {
        tempDevices[i] = nullptr;
    }

    try
    {
        for (int i = 0; i < other.count; ++i)
        {
            tempDevices[i] = other.devices[i]->clone();
        }
    }
    catch (...)
    {
        for (int i = 0; i < other.count; ++i)
        {
            delete tempDevices[i];
        }
        
        throw;
    }

    this->free();

    this->count = other.count;
    for (int i = 0; i < MAX_INV_SIZE; ++i)
    {
        this->devices[i] = tempDevices[i];
    }

    return *this;
}

Inventory::~Inventory()
{
    free();
}

void Inventory::printDevices() const
{
    std::cout << "--------The list of all the devices---------------\n";

    for (unsigned i = 0; i < this->count; i++)
    {
        this->devices[i]->print();
    }

    std::cout << "--------------------------------------------------\n";
}

void Inventory::addDevice(const IDevice &device)
{
    if (this->count >= MAX_INV_SIZE)
    {
        throw std::invalid_argument("Cant have more devices than the Maximum inventory");
    }
    
    this->devices[count++] = device.clone();
}

bool Inventory::isSorted()
{
    if (this->count <= 1)
    {
        return true;
    }
    

    for (unsigned i = 0; i < this->count - 1; i++)
    {
        if (this->devices[i]->get_perf() > this->devices[i + 1]->get_perf())
        {
            return false;
        }
    }
    
    return true;
}

void Inventory::free()
{
    for (unsigned i = 0; i < count; i++)
    {
        delete this->devices[i];
        this->devices[i] = nullptr;
    }
    
    this->count = 0;
}

void Inventory::copyFrom(const Inventory &other)
{
    this->count = other.count;
    for (unsigned i = 0; i < this->count; i++)
    {
        this->devices[i] = other.devices[i]->clone();
    }
    
}
