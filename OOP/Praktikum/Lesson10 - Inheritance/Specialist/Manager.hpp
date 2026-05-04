#pragma once

#include "Specialist.hpp"

class Manager : public Specialist
{
public:
    //default ctor
    Manager();

    //parametrized ctor
    Manager(const char* name, const char* address, long EGN, const char* department, double salary, const char* description, const char* departmentHeManages);

    //copy ctor
    Manager(const Manager& other);
    Manager& operator=(const Manager& other);

    //destructor
    ~Manager();

    //methods
    void addEmployee(Employee* employee);

    //getters
    const char* getDepartmentHeManages() const { return this->departmentHeManages; };

protected:
    char* departmentHeManages;
    unsigned employeesCnt;
    unsigned capacity;
    Employee** employees;

private:
    void free();
    void resize();
};
