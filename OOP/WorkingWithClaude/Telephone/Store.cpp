#include "Store.hpp"

Store::Store(const double budget)
    : count(0), capacity(STARTING_CAPACITY),  currentBudget(0), budget(validateBudget(budget))
{
    this->phones = new Telephone*[capacity];
    for (unsigned i = 0; i < capacity; i++)
    {
        this->phones[i] = nullptr;
    }
}

Store::Store(const Store &other)
    : count(other.count), capacity(other.capacity), currentBudget(other.currentBudget), budget(other.budget) 
{
    this->phones = new Telephone*[capacity];
    for (unsigned i = 0; i < count; i++)
    {
        this->phones[i] = other.phones[i]->clone();
    }
    for (unsigned i = count; i < other.capacity - 1; i++)
    {
        this->phones[i] = nullptr;
    }
    
}

Store &Store::operator=(const Store &other)
{
    if (this != &other)
    {
        if (this->budget != other.budget)
        {
            throw std::invalid_argument("Cant have two stores with different budgets");
        }
        
        Telephone** tempPhones = new Telephone*[other.capacity];
        for (unsigned i = 0; i < other.count; i++)
        {
            tempPhones[i] = this->phones[i];
        }
        
        free();

        this->phones = tempPhones;
        this->capacity = other.capacity;
        this->count = other.count;
        this->currentBudget = other.currentBudget;
    }
    
    return *this;
}

Store::~Store()
{
    free();
}

void Store::addTelephone(const Telephone &phone)
{
    if (this->count >= this->capacity)
    {
        resize();
    }

    if (this->currentBudget + phone.getPrice() > this->budget)
    {
        throw std::invalid_argument("There isnt enough money :(");
    }
    
    this->phones[count++] = phone.clone();
    this->currentBudget += phone.getPrice();
}

bool Store::removeTelephone(const char *model, const char *brand)
{
    if (!model || !brand)
    {
        throw std::invalid_argument("There mus be a brand or a model that we can search for");
    }
    
    for (unsigned i = 0; i < this->count; i++)
    {
        if ((strcmp(this->phones[i]->getBrand(), brand) == 0) &&
            (strcmp(this->phones[i]->getModel(), model) == 0))
        {
            this->currentBudget += this->phones[i]->getPrice();
            delete this->phones[i];
            this->phones[i] = this->phones[count];
            this->phones[count--] = nullptr;
            return true;
        }
    }
    
    return false;
}

void Store::free()
{   
    for (unsigned i = 0; i < count; i++)
    {
        delete this->phones[i];
    }

    delete[] this->phones;
}

void Store::resize()
{
    Telephone** tempPhones = new Telephone*[capacity * 2];
    for (unsigned i = 0; i < count; i++)
    {
        tempPhones[i] = this->phones[i];
    }
    for (unsigned i = count; i < capacity * 2; i++)
    {
        tempPhones[i] = nullptr;
    }
    
    delete[] this->phones;
    this->phones = tempPhones;
    this->capacity *= 2;
}

double validateBudget(const double budget)
{
    if (budget <= 0)
    {
        throw std::invalid_argument("Budget is too low to start a phone bussiness");
    }
    
    return budget;
}
