#pragma once

#include "Secretery.hpp"
#include "Manager.hpp"

class Director : public Manager
{
public:
    //default ctor
    Director();

    //parametrized ctor
    Director(const char* name, const char* address, long EGN, const char* department, double salary, const char* description, const char* departmentHeManages, Secretery* secretery);

    //copy ctor
    Director(const Director& other);
    Director& operator=(const Director& other);

    //destructor
    ~Director();

    //methods
    double calculateTotalSalary() const;

private:
    Secretery* secretery;
    
    void free();
};
