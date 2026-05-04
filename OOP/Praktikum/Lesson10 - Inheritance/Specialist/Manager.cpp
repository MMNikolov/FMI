#include "Manager.hpp"

Manager::Manager()
    : Specialist(), departmentHeManages(nullptr), employees(nullptr), employeesCnt(0), capacity(0)
{
    this->departmentHeManages = new char[1];
    this->departmentHeManages[0] = '\0';
}

Manager::Manager(const char *name, const char *address, long EGN, const char *department, double salary, const char *description, const char *departmentHeManages)
    : Specialist(name, address, EGN, department, salary, description), employees(nullptr), employeesCnt(0), capacity(0)
{
    if (!departmentHeManages)
    {
        throw std::invalid_argument("Invalid Input for the Manager class");
    }

    this->departmentHeManages = new char[strlen(departmentHeManages) + 1];
    strcpy(this->departmentHeManages, departmentHeManages);
}

Manager::Manager(const Manager &other)
    : Specialist(other)
{
    this->departmentHeManages = new char[strlen(other.departmentHeManages) + 1];
    strcpy(this->departmentHeManages, other.departmentHeManages);

    this->employeesCnt = other.employeesCnt;
    this->capacity = other.capacity;

    if (this->capacity > 0)
    {
        this->employees = new Employee *[this->capacity];

        for (int i = 0; i < employeesCnt; i++)
        {
            this->employees[i] = other.employees[i];
        }
    }
    else
    {
        this->employees = nullptr;
    }
}

Manager &Manager::operator=(const Manager &other)
{
    if (this != &other)
    {
        Specialist::operator=(other);
        free();

        this->departmentHeManages = new char[strlen(other.departmentHeManages) + 1];
        strcpy(this->departmentHeManages, other.departmentHeManages);

        this->employeesCnt = other.employeesCnt;
        this->capacity = other.capacity;

        if (this->capacity > 0)
        {
            this->employees = new Employee *[this->capacity];
            for (int i = 0; i < employeesCnt; i++)
            {
                this->employees[i] = other.employees[i];
            }
        }
        else
        {
            this->employees = nullptr;
        }
    }

    return *this;
}

Manager::~Manager()
{
    free();
}

void Manager::addEmployee(Employee *employee)
{
    if (!employee)
    {
        return;
    }
    
    if (this->employeesCnt >= this->capacity)
    {
        resize();
    }

    this->employees[this->employeesCnt++] = employee;
}

void Manager::free()
{
    delete[] this->departmentHeManages;
    delete[] this->employees;
}

void Manager::resize()
{
    this->capacity = (this->capacity == 0) ? 2 : this->capacity * 2;
    Employee** temp = new Employee*[this->capacity];
    for (unsigned i = 0; i < this->employeesCnt; i++)
    {
        temp[i] = this->employees[i];
    }
    delete[] this->employees;
    this->employees = temp;
}
