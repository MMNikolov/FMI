#include <iostream>
#include "Employee.hpp"

inline Employee::Employee()
    : Person()
    , speciality(nullptr)
{
    this->speciality = new char[1];
    this->speciality[0] = '\0';
}

inline Employee::Employee(const char *name, const char *EGN, const char *speciality, Company* sponsor)
    : Person<Company>(name, EGN, sponsor)
{
    if (!speciality)
    {
        throw std::invalid_argument("Not correct input values");
    }
    
    this->speciality = new char[strlen(speciality) + 1];
    strcpy(this->speciality, speciality);
}

inline Employee::Employee(const Employee &other)
    : Person(other)
    , speciality(nullptr)
{
    copyFrom(other);
}

inline Employee &Employee::operator=(const Employee &other)
{
    if (this != &other)
    {
        Person<Company>::operator=(other);

        char* tempSpeciality = new char[strlen(other.speciality) + 1];
        strcpy(tempSpeciality, other.speciality);

        delete[] this->speciality;
        this->speciality = tempSpeciality;
    }
    
    return *this;
}

inline Employee::~Employee()
{
    free();
}

inline void Employee::printInfo() const
{
    std::cout << "----------------- Employee Info: ----------------------\n";
    std::cout << "Name: " << this->name << '\n'
              << "EGN: " << this->EGN << '\n'
              << "Speciality: " << this->speciality << '\n';

    if (this->sponsor != nullptr)
    {
        std::cout << "Company name: " << this->sponsor->name << '\n'
                  << "Company bullstat: " << this->sponsor->BULSTAT << '\n';
    }
    else
    {
        std::cout << "Company: None\n";
    }
}

inline void Employee::free()
{
    delete[] this->speciality;
}

inline void Employee::copyFrom(const Employee &other)
{
    this->speciality = new char[strlen(other.speciality) + 1];
    strcpy(this->speciality, other.speciality);
}
