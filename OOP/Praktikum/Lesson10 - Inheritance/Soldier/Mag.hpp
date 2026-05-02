#include "Sergant.hpp"

class Mag : public Sergant   
{
public:
    //default ctor
    Mag();

    //parametrized ctor
    Mag();

    //copy ctor
    Mag(const Mag& other);
    Mag& operator=(const Mag& other);

    //destructor
    ~Mag();

private:
    char* battalion;
    unsigned sergantsCnt;
    Sergant* sergants;
};
