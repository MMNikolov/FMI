#include "Telephone.hpp"

Telephone::Telephone()
    : model(nullptr), maker(nullptr), price(0.0)
{
}

Telephone::Telephone(const char *model, const char *maker, double price)
{
    if (!model || !maker || price < 0.0)
    {
        throw std::invalid_argument("Invalid inputs");
    }

    this->model = new char[strlen(model) + 1];
    strcpy(this->model, model);

    this->maker = new (std::nothrow) char[strlen(maker) + 1];
    if (!this->maker)
    {
        delete[] this->model;
        throw std::bad_alloc();
    }
    strcpy(this->maker, maker);

    this->price = price;
}

Telephone::Telephone(const Telephone &other)
{
    copyFrom(other);
}

Telephone &Telephone::operator=(const Telephone &other)
{
    if (this != &other)
    {
        char* str = model;
        model = nullptr;
        char* mkr = maker;
        maker = nullptr;

        try  { copyFrom(other); } 
        catch(...)
        {

        }

        // delete 
    }
    
    return *this;
}

Telephone::~Telephone()
{
    free();
}

const char *Telephone::getModel() const
{
    return this->model;
}

const char *Telephone::getMaker() const
{
    return this->maker;
}

double Telephone::getPrice() const
{
    return this->price;
}

void Telephone::free()
{
    delete[] this->model;
    delete[] this->maker;
}

void Telephone::copyFrom(const Telephone &other)
{
    this->model = new char[strlen(other.model) + 1];
    strcpy(this->model, model);

    this->maker = new (std::nothrow) char[strlen(other.maker) + 1];
    if (!this->maker)
    {
        delete[] this->model;
        throw std::bad_alloc();
    }
    strcpy(this->maker, maker);

    this->price = other.price;
}
