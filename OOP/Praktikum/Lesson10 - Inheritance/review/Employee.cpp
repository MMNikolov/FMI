#include "Employee.hpp"

Employee::Employee()
    : EGN(0), salary(0)
{
    this->name = new char[1];
    this->name[0] = '\0';
    this->address = new char[1];
    this->address[0] = '\0';
    this->department = new char[1];
    this->department[0] = '\0';
}

Employee::Employee(const char *name, const char *address, long EGN, const char *department, double salary)
{
    if (!name || !address || !department || EGN < 0 || salary < 0)
    {
        throw std::invalid_argument("Invalid input");
    }

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->address = new (std::nothrow) char[strlen(address) + 1];
    if (!address)
    {
        delete[] this->name;
        throw std::bad_alloc();
    }
    strcpy(this->address, address);

    this->department = new (std::nothrow) char[strlen(department) + 1];
    if (!department)
    {
        delete[] this->name;
        delete[] this->address;
        throw std::bad_alloc();
    }
    strcpy(this->department, department);

    this->EGN = EGN;
    this->salary = salary;
}

Employee::Employee(const Employee &other)
{
    copyFrom(other);
}

Employee &Employee::operator=(const Employee &other)
{
    if (this != &other)
    {
        // Опитай се да ги правиш strong exception safe, поне като упражнение
        free();
        copyFrom(other);
    }

    return *this;
}

Employee::~Employee()
{
    free();
}

void Employee::free()
{
    delete[] this->name;
    delete[] this->address;
    delete[] this->department;
}

void Employee::copyFrom(const Employee &other)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

    this->address = new (std::nothrow) char[strlen(other.address) + 1];
    if (!address)
    {
        delete[] this->name;
        throw std::bad_alloc();
    }
    strcpy(this->address, other.address);

    this->department = new (std::nothrow) char[strlen(other.department) + 1];
    if (!department)
    {
        delete[] this->name;
        delete[] this->address;
        throw std::bad_alloc();
    }
    strcpy(this->department, other.department);

    this->EGN = other.EGN;
    this->salary = other.salary;
}
