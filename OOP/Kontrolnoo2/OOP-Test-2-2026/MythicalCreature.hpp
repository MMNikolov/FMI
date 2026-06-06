#pragma once

#include <iostream>
#include <cstring>
#include <stdexcept>
#include <fstream>

class MythicalCreature
{
public:
    MythicalCreature(const char* name, int power, const char* blood);

    MythicalCreature(const MythicalCreature& other);
    MythicalCreature& operator=(const MythicalCreature& other);

    virtual ~MythicalCreature();

    //methods
    virtual std::ostream& describe(std::ostream& out) const = 0;
    virtual bool canFly() const = 0;
    virtual MythicalCreature* clone() const = 0;

    //getters
    const char* GetName() const { return this->name; };
    int GetPower() const { return this->power; };
    const char* GetBlood() { return this->blood; };

protected:
    char* name;
    int power;
    char* blood;

private:
    void free();
    void copyFrom(const MythicalCreature& other);
};
