#include "Director.hpp"

Director::Director()
    : Manager(), secretery(nullptr)
{
}

Director::Director(const char *name, const char *address, long EGN, const char *department, double salary, const char *description, const char *departmentHeManages, Secretery *secretery)
    : Manager(name, address, EGN, department, salary, description, departmentHeManages)
{
    if (!secretery)
    {
        throw std::invalid_argument("Invlaid Input");
    }

    this->secretery = new Secretery(*secretery);
}

Director::Director(const Director &other)
    : Manager(other)
{
    if (other.secretery)
    {
        this->secretery = new Secretery(*(other.secretery));
    }
    else
    {
        this->secretery = nullptr;
    }
}

Director &Director::operator=(const Director &other)
{
    if (this != &other)
    {
        Manager::operator=(other); 
        free();                    

        if (other.secretery)
        {
            this->secretery = new Secretery(*(other.secretery));
        }
        else
        {
            this->secretery = nullptr;
        }
    }
    return *this; 
}

Director::~Director()
{
    free();
}

double Director::calculateTotalSalary() const
{
    double sumOfSalary = 0;

    for (int i = 0; i < employeesCnt; i++)
    {
        sumOfSalary += employees[i]->getSalary();
    }

    sumOfSalary += this->getSalary();

    if (this->secretery)
    {
        sumOfSalary += this->secretery->getSalary();
    }
    
    return sumOfSalary;
}

void Director::free()
{
    delete secretery;
}
