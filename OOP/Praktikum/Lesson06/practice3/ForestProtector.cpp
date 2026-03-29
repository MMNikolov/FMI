#include "ForestProtector.hpp"

ForestProtector::ForestProtector(const char* name, unsigned int age, unsigned int yearsWorking)
: name(nullptr), age(0), yearsWorking(0)
{
    if (this->age < 18)
    {
        std::cerr << "Not old enough to be a forest protector";
        this->isValid = false;
        return;
    }

    if (this->yearsWorking < 0)
    {
        std::cerr << "Impossible to have worked for minus years";
        this->isValid = false;
        return;
    }
    
    
}

bool ForestProtector::SetString(char* where, const char* what)
{
    if (!what || *what == '\0')
    {
        std::cerr << "There was a problem with the string setting";
        return 0;
    }
    
    char* temp = new (std::nothrow) char[strlen(what) + 1];
    if (!temp)
    {
        std::cerr << "Temp was not allocated correctly";
        freeMemory();
        return false;
    }
    
    strcpy(temp, what);
    delete[] where;
    where = temp;

    return 0;
}

void ForestProtector::freeMemory()
{
    delete [] name;
}