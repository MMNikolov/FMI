#ifndef REGISTRATION_PLATE_HPP
#define REGISTRATION_PLATE_HPP

#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>
#define PLATE_LENGTH 9

class RegistrationPlate
{
public:
    RegistrationPlate(const char* plate);

    RegistrationPlate(const RegistrationPlate& other);
    RegistrationPlate& operator=(const RegistrationPlate& other);

    ~RegistrationPlate();

    //methods
    const char* getPlate() const { return this->plate; };

private:
    char plate[PLATE_LENGTH];

private:
    static bool validateLetter(const char c);
    static bool validateNumber(const char c);
    static bool validatePlate(const char* plate);
};

#endif // REGISTRATION_PLATE_HPP