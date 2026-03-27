#include "bestPractices.hpp"

oven::oven(const char *maker, const char *countryOfOrgin, int waranty, energy_class ec) :
    maker(nullptr), countryOfOrgin(nullptr), waranty(0), ec(energy_class::UNKNOWN)
{
    if (!maker)
    {
        this->IsValid = false;
        return;
    }
    
    if (ec == energy_class::UNKNOWN)
    {
        this->IsValid = false;
        return;
    }

    if (!setString(this->maker, maker) || !setString(this->countryOfOrgin, countryOfOrgin))
    {
        this->IsValid = false;
        free();
        return;
    }

    this->waranty = waranty;
    this->ec = ec;
};

bool oven::setString(char*& where, const char* what){
    if (!what || *what == '\0')
    {
        return;
    }

    char* temp = new (std::nothrow) char[strlen(what) + 1];
    if (!temp)
    {
        return;
    }
    
    strcpy(temp, what);
    delete where;
    where = temp;

    return true;
};

void oven::free(){
    delete[] maker;
    delete[] countryOfOrgin;
};

