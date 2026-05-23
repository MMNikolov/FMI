#pragma once

#include "Person.hpp"
#include "Company.hpp"

class Employee : public Person<Company>
{
public:
    Employee();
    Employee(const char* name, const char* EGN, const char* speciality, Company* sponsor = nullptr);
    Employee(const Employee& other);
    Employee& operator=(const Employee& other);
    ~Employee();

    //methods
    void printInfo() const;

private:
    char* speciality;

private:
    void free();
    void copyFrom(const Employee& other);
};

#include "Employee.inl"