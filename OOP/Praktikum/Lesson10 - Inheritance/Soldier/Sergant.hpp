#include "Soldier.hpp"

class Sergant : public Soldier
{
public:
    //default ctor
    Sergant();

    //parametrized ctor
    Sergant(const char* voivoda);

    //copy ctor
    Sergant(const Sergant& other);
    Sergant& operator=(const Sergant& other);

    //destructor
    ~Sergant();

    //getters
    const char* getVzvoda() const { return this->vzvoda; };

private:
    char* vzvoda;
    unsigned soldiersCnt;
    Soldier* soldiers;

    void free();
};
