#include "licencePlate.hpp"

class Person
{
public:
    Person(const char* name, long EGN, long telephoneNumber);
    ~Person()
    {
        delete[] name;
    };

private:
    char* name;
    long EGN;
    long telephoneNumber;
};
