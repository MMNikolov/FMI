#pragma once

#include "MythicalCreature.hpp"

class Flying : public virtual MythicalCreature
{
public:
    Flying(const char* name, int power, const char* blood, int altitude);

    Flying(const Flying& other);
    Flying& operator=(const Flying& other);

    //No need for a destrcutor

    //overriden methods
    std::ostream& describe(std::ostream& out) const override;
    bool canFly() const override;
    MythicalCreature* clone() const override;

    //methods

    //getters
    int GetAltitude() const { return this->altitude; };

protected:
    int altitude;
};
