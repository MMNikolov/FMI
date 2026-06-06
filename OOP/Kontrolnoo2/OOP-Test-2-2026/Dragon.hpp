#pragma once

#include "Flying.hpp"
#include "Magical.hpp"

class Dragon : public Flying, public Magical
{
public:
    Dragon(const char* name, int power, const char* blood, int altitude, const char* spell);

    Dragon(const Dragon& other);
    Dragon& operator=(const Dragon& other);

    ~Dragon() = default;

    //overriden methods
    std::ostream& describe(std::ostream& out) const override;
    bool canFly() const override;
    MythicalCreature* clone() const override;
};
