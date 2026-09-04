#include "Dealership.hpp"

Dealership::Dealership(unsigned capacity)
    : count(0), capacity(capacity), allCarsPrice(0)
{
    this->listings = new Listing[capacity];
    for (size_t i = 0; i < capacity; i++)
    {
        this->listings[i].car = nullptr;
        this->listings[i].price = 0;
    }
}

Dealership::Dealership(const Dealership &other)
{
    this->listings = new Listing[other.capacity];
    for (size_t i = 0; i < other.count; i++)
    {
        this->listings[i].car = other.listings[i].car;
        this->listings[i].price = other.listings[i].price;
    }
    
    this->allCarsPrice = other.allCarsPrice;
    this->capacity = other.capacity;
    this->count = other.count;
}

Dealership &Dealership::operator=(const Dealership &other)
{
    if (this != &other)
    {
        Listing* tempListings = new Listing[other.capacity];
        for (unsigned i = 0; i < this->count; i++)
        {
            tempListings[i].car = other.listings[i].car;
            tempListings[i].price = other.listings[i].price;
        }
        
        free();

        this->listings = tempListings;
        this->allCarsPrice = other.allCarsPrice;
        this->capacity = other.capacity;
        this->count = other.count;
    }
    
    return *this;
}

Dealership::~Dealership()
{
    free();
}

bool Dealership::add(const Car &car, double price)
{
    //we dont have a resize function because how the fuck are u going to expand the dealership 
    if (this->count + 1 >= capacity)
    {
        throw std::invalid_argument("There is not enough space on the car dealership");
    }
    
    this->listings[count].car = new Car(car);
    this->listings[count++].price = price;
    this->allCarsPrice += price;
}

bool Dealership::sell(unsigned count)
{
    if (this->count < count || count > capacity)
    {
        throw std::invalid_argument("There isnt this much cars in the parking lot");
    }
    
    //I am going to to do 0(1) shifiting, because imagine the situation, you have a dealership
    //and then someone buys a car and u have to shift all of them one to the left
    //that is just plain ridicilous
    delete this->listings[count].car;

    this->allCarsPrice -= this->listings[count].price;
    this->listings[count].car = this->listings[this->count].car;
    this->listings[count].price = this->listings[this->count--].price;
}

void Dealership::printCars() const
{
    if (!count)
    {
        throw std::invalid_argument("There arent any cars to print");
    }
    
    for (unsigned i = 0; i < count; i++)
    {
        std::cout << "Car number: " << (i + 1);
        std::cout << this->listings[i].car->getModel() << this->listings[i].car->getDate()
                  << this->listings[i].car->getHorsePower() << this->listings[i].price;
    }
    
}

void Dealership::searchBrand(const char *brand) const
{
    if (!brand)
    {
        throw std::invalid_argument("You have not typed in a brand");
    }
    
    for (unsigned i = 0; i < count; i++)
    {
        if (strcmp(this->listings[i].car->getModel(), brand) == 0)
        {
            std::cout << this->listings[i].car->getModel() << this->listings[i].car->getDate()
                      << this->listings[i].car->getHorsePower() << this->listings[i].price;
        }
    }
}

void Dealership::free()
{
    if (!count)
    {
        throw std::invalid_argument("there are no cars in the dealership");
    }
    
    for (unsigned i = 0; i < this->count; i++)
    {
        delete this->listings[i].car;
    }
    delete[] this->listings;
}
