#pragma once

#include "User.hpp"

#define MIN_COMPETENCE 1
#define MAX_COMPETENCE 5
#define MAX_YEARS_IN_POSITION 100

class Admin : public User
{
public:
    Admin(const char* email, const char* password, int yearsInPosition, int competence);

    Admin(const Admin& other);
    Admin& operator=(const Admin& other);

    //Dont need a destructor when we dont have dynamically allocated memory

    //methods
    int operator++();
    int operator--();
    friend std::ostream& operator<<(std::ostream& out, const Admin& user);
    friend std::istream& operator>>(std::istream& in, Admin& user);

    //overriden methods
    Admin* clone() const override;

    //getters
    int GetYearsInPosition() const { return this->yearsInPosition; }
    int GetCompetence() const { return this->competence; }

protected:
    int yearsInPosition;
    //[1 - 5]
    int competence;
};

bool operator>(const Admin& one, const Admin& two);
bool operator<(const Admin& one, const Admin& two);
