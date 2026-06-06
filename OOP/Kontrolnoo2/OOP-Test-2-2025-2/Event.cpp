#include "Event.hpp"

Event::Event(const char *name, const char *description, unsigned hours, bool isRepeatedMonthly)
{
    if (!name || !description)
    {
        throw std::invalid_argument("Invalid Input in Event ctor");
    }
    
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->description = new (std::nothrow) char[strlen(description) + 1];
    if (!this->description)
    {
        delete[] this->name;
        throw std::bad_alloc();
    }
    strcpy(this->description, description);

    this->hours = hours;
    this->isRepeatedMonthly = isRepeatedMonthly;
}

Event::Event(const Event &other)
{
    copyFrom(other);
}

Event &Event::operator=(const Event &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    
}

Event::~Event()
{
    free();
}

Event *Event::clone() const
{
    return new Event(*this);
}

void Event::copyFrom(const Event &other)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

    this->description = new (std::nothrow) char[strlen(other.description) + 1];
    if (!this->description)
    {
        delete[] this->name;
        throw std::bad_alloc();
    }
    strcpy(this->description, other.description);

    this->hours = other.hours;
    this->isRepeatedMonthly = other.isRepeatedMonthly;
}

void Event::free()
{
    delete[] this->name;
    this->name = nullptr;
    delete[] this->description;
    this->description = nullptr;
}

std::ostream &operator<<(std::ostream &out, const Event &event)
{
    out << event.hours << ' ' << event.description << ' ' << event.hours << ' ' << event.isRepeatedMonthly << '\n';
    return out;
}

std::istream &operator>>(std::istream &in, Event &event)
{
    char tempName[512];
    char tempDesc[1024];
    unsigned tempHours;
    bool tempRepeated;

    in >> tempName >> tempDesc >> tempHours >> tempRepeated;

    if (!tempName || !tempDesc)
    {
        throw std::bad_alloc();
    }
    
    event.name = new char[strlen(tempName) + 1];
    strcpy(event.name, tempName);

    event.description = new (std::nothrow) char[strlen(tempDesc) + 1];
    if (!event.description)
    {
        delete[] event.name;
        throw std::bad_alloc();
    }
    strcpy(event.description, tempDesc);

    event.hours = tempHours;
    event.isRepeatedMonthly = tempRepeated;

    return in;
}

bool operator==(const Event &one, const Event &two)
{
    if (one.GetName() == two.GetName() &&
        one.GetDescr() == two.GetDescr() &&
        one.GetHours() == two.GetHours() &&
        one.GetIsRepeatedMonthly() == two.GetIsRepeatedMonthly())
    {
        return true;
    }
    
    return false;
}
