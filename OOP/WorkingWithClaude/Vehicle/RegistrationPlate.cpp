#include "RegistrationPlate.hpp"

RegistrationPlate::RegistrationPlate(const char *plate)
{
    if (!plate)
    {
        throw std::invalid_argument("no");
    }
    
    if (!validatePlate(plate))
    {
        throw std::invalid_argument("no");
    }
    
    for (unsigned i = 0; i < PLATE_LENGTH - 1; i++)
    {
        this->plate[i] = plate[i];
    }
    this->plate[PLATE_LENGTH - 1] = '\0';
}

RegistrationPlate::RegistrationPlate(const RegistrationPlate &other)
{
    for (unsigned i = 0; i < PLATE_LENGTH - 1; i++)
    {
        this->plate[i] = other.plate[i];
    }
    this->plate[PLATE_LENGTH - 1] = '\0';
}

RegistrationPlate &RegistrationPlate::operator=(const RegistrationPlate &other)
{
    if (this != &other)
    {
        for (unsigned i = 0; i < PLATE_LENGTH - 1; i++)
        {
            this->plate[i] = other.plate[i];
        }
        this->plate[PLATE_LENGTH - 1] ='\0';
    }
    
    return *this;
}

RegistrationPlate::~RegistrationPlate()
{ }

//because the registration plates consist only of upper case letters...
bool RegistrationPlate::validateLetter(const char c)
{
    return (c >= 'A' && c <= 'Z');
}

bool RegistrationPlate::validateNumber(const char c)
{
    return (c >= '0' && c <= '9');
}

bool RegistrationPlate::validatePlate(const char *plate)
{
    if (!plate)
    {
        throw std::invalid_argument("no");
    }
    
    unsigned length = strlen(plate);
    if (length != PLATE_LENGTH - 1)
    {
        return false;
    }
    
    for (unsigned i = 0; i < 2; i++)
    {
        if (validateLetter(plate[i]))
        {
            continue;
        }
        
        return false;
    }
    for (unsigned i = 2; i < 6; i++)
    {
        if (validateNumber(plate[i]))
        {
            continue;
        }
        
        return false;
    }
    for (unsigned i = 6; i < 8; i++)
    {
        if (validateLetter(plate[i]))
        {
            continue;
        }
        
        return false;
    }
    if (plate[PLATE_LENGTH - 1] != '\0')
    {
        return false;
    }
    
    
    return true;
}
