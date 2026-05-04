#pragma once

#include <iostream>
#include <stdexcept>
#include <cstring>

class Employee
{
public:
    //default ctor
    Employee();

    //parametrized ctor
    Employee(const char* name, const char* address, long EGN, const char* department, double salary);

    //copy ctor
    Employee(const Employee& other);
    Employee& operator=(const Employee& other);

    //destructor
    ~Employee();

    //getters
    const char* getName() const { return this->name; };
    const char* getAddress() const { return this->address; };
    long getEGN() const { return this->EGN; };
    const char* getDepartment() const { return this->department; };
    double getSalary() const { return this->salary; };

protected:
    char* name;
    char* address;
    char* department;
    
    long EGN;           // егн не може да бъде число, защото може да започва с нула
    double salary;

private:
    void free();
    void copyFrom(const Employee& other);
};
