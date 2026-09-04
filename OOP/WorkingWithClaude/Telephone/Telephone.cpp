#include "Telephone.hpp"

Telephone::Telephone(const char *model, const char *brand, double price)
    : model(nullptr), brand(nullptr), price(0)
{
    if (!model || !brand || price <= 0)
    {
        throw std::invalid_argument("Doesnt have the model or the brand fix");
    }
    
    this->model = new char[strlen(model) + 1];
    strcpy(this->model, model);

    this->brand = new (std::nothrow) char[strlen(brand) + 1];
    if (!this->brand)
    {
        delete[] this->model;
        throw std::bad_alloc();
    }
    strcpy(this->brand, brand);
    
    this->price = price;
}

Telephone::Telephone(const Telephone &other)
{
    this->model = new char[strlen(other.model) + 1];
    strcpy(this->model, other.model);

    this->brand = new (std::nothrow) char[strlen(other.brand) + 1];
    if (!this->brand)
    {
        delete[] this->model;
        throw std::bad_alloc();
    }
    strcpy(this->brand, other.brand);

    this->price = other.price;
}

Telephone &Telephone::operator=(const Telephone &other)
{
    if (this != &other)
    {
        char* tempModel = new char[strlen(other.model) + 1];
        strcpy(tempModel, other.model);

        char* tempBrand = new (std::nothrow) char[strlen(other.brand) + 1];
        if (!tempBrand)
        {
            delete[] tempModel;
            throw std::bad_alloc();
        }
        strcpy(tempBrand, other.brand);

        free();

        this->model = tempModel;
        this->brand = tempBrand;
        this->price = other.price;
    }
    
    return *this;
}

Telephone::~Telephone()
{
    free();
}

Telephone *Telephone::clone() const
{
    return new Telephone(*this);
}

void Telephone::free()
{
    delete[] this->model;
    delete[] this->brand;
}