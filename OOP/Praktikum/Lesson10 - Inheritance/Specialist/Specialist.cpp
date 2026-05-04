#include "Specialist.hpp"

Specialist::Specialist()
    : Employee(), description(nullptr)
{
    this->description = new char[1];
    this->description[0] = '\0';
}

Specialist::Specialist(const char *name, const char *address, long EGN, const char *department, double salary, const char *description)
    : Employee(name, address, EGN, department, salary), description(nullptr)
{
    if (!description)
    {
        throw std::invalid_argument("Invlaid input");
    }

    this->description = new char[strlen(description) + 1];
    strcpy(this->description, description);
}

Specialist::Specialist(const Specialist &other)
    : Employee(other)
{
    this->description = new char[strlen(other.description) + 1];
    strcpy(this->description, other.description);
}

Specialist &Specialist::operator=(const Specialist &other)
{
    if (this != &other)
    {
        Employee::operator=(other);
        free();

        this->description = new char[strlen(other.description) + 1];
        strcpy(this->description, other.description);
    }

    return *this;
}

Specialist::~Specialist()
{
    free();
}

void Specialist::free()
{
    delete[] this->description;
}
