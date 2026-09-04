#include "Garage.hpp"

Garage::Garage(const unsigned capacity)
    : count(0), capacity(capacity)
{
    this->vehicles = new Vehicle*[capacity];
    for (unsigned i = 0; i < capacity; i++)
    {
        this->vehicles[i] = nullptr;
    }
}

Garage::Garage(const Garage &other)
    : count(other.count), capacity(other.capacity)
{
    this->vehicles = new Vehicle*[capacity];
    for (unsigned i = 0; i < count; i++)
    {
        this->vehicles[i] = other.vehicles[i]->clone();
    }
    for (size_t i = count; i < capacity; i++)
    {
        this->vehicles[i] = nullptr;
    }
}

Garage &Garage::operator=(const Garage &other)
{
    if (this != &other)
    {
        if (this->capacity != other.capacity)
        {
            throw std::invalid_argument("no");
        }
        
        Vehicle** tempVehicles = new Vehicle*[capacity];
        for (unsigned i = 0; i < other.count; i++)
        {
            tempVehicles[i] = other.vehicles[i]->clone(); 
        }
        for (unsigned i = other.count; i < capacity; i++)
        {
            tempVehicles[i] = nullptr;
        }
        
        free();

        this->vehicles = tempVehicles;
        this->count = other.count;
    }
    
    return *this;
}

Garage::~Garage()
{
    free();
}

void Garage::addVehicle(const Vehicle &vehicle)
{
    if (this->count >= this->capacity)
    {
        throw std::invalid_argument("no");
    }
    
    this->vehicles[count++] = vehicle.clone();
}

void Garage::removeVehicle(const char *brand, const char *model)
{
    if (!brand || !model)
    {
        throw std::invalid_argument("no");
    }
    
    for (unsigned i = 0; i < this->count; i++)
    {
        if (strcmp(this->vehicles[i]->getBrand(), brand) == 0 && 
            strcmp(this->vehicles[i]->getModel(), model) == 0)
        {
            delete this->vehicles[i];
            this->vehicles[i] = this->vehicles[count - 1];
            this->vehicles[count - 1] = nullptr;
            i--; count--;
        }
    }
}

double Garage::getAllTaxes()
{
    double result = 0.0;

    for (unsigned i = 0; i < this->count; i++)
    {
        result += this->vehicles[i]->getTax();
    }
    
    return result;
}

unsigned Garage::getAutomobileCount() const
{
    unsigned automobiles = 0;
    for (unsigned i = 0; i < this->count; i++)
    {
        if (dynamic_cast<Automobile*>(this->vehicles[i]) != nullptr)
        {
            automobiles++;
        }
    }
    
    return automobiles;
}

Vehicle *Garage::operator[](unsigned index)
{
    if (index >= this->count)
    {
        throw std::invalid_argument("no");
    }
    
    return this->vehicles[index];
}

void Garage::free()
{
    for (unsigned i = 0; i < count; i++)
    {
        delete this->vehicles[i];
    }
    delete[] this->vehicles;
}
