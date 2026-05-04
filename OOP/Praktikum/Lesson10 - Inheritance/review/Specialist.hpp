#pragma once

#include "Employee.hpp"

class Specialist : public Employee
{
public:
    //default ctor
    Specialist();

    //parametrized ctor
    Specialist(const char* name, const char* address, long EGN, const char* department, double salary, const char* description);

    //copy ctor
    Specialist(const Specialist& other);
    Specialist& operator=(const Specialist& other);

    //destructor
    ~Specialist();

    //getters
    const char* getDescription() const { return this->description; };

protected:
    char* description;

private: 
    void free();
};
