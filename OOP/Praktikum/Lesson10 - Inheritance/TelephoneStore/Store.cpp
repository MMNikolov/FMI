#include "Store.hpp"

Store::Store(double budget)
{
    if (budget < 0.0)
    {
        throw std::invalid_argument("Invalid Input");
    }
    
    this->budget = budget;
}

Store::Store(const Store &other)
{
    copyFrom(other);
}

Store &Store::operator=(const Store &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    
    return *this;
}

Store::~Store()
{
    free();
}

void Store::addTelephone(const Smartphone &phone)
{
    if (budget < phone.getPrice())
    {
        throw std::invalid_argument("Budget is low...");
    }
    
    // but if the budget is enough
    this->phones[this->phonesCount++] = phone;
    this->budget -= phone.getPrice();
}

void Store::removeTelephone(const char *model, const char *maker)
{
    for (int i = 0; i < phonesCount; i++)
    {
        if (strcmp(this->phones[i].getModel(), model) == 0 && strcmp(this->phones[i].getMaker(), maker) == 0)
        {
            this->budget += this->phones[i].getPrice();
            this->phones[i] = this->phones[phonesCount--];
        }
    }
}

double Store::getBudget() const
{
    return this->budget;
}

void Store::free()
{
    delete[] phones;
}

void Store::copyFrom(const Store &other)
{
    // try ...
    for (int i = 0; i < phonesCount; i++)
    {
        this->phones[i] = other.phones[i];
    }

    this->budget = other.budget;
}
