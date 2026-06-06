#pragma once

#include "MythicalCreature.hpp"

class Magical : public virtual MythicalCreature
{
public:
    Magical(const char* name, int power, const char* blood, const char* spell);

    Magical(const Magical& other);
    Magical& operator=(const Magical& other);

    ~Magical();

    //overriden methods
    std::ostream& describe(std::ostream& out) const override;
    bool canFly() const override;
    MythicalCreature* clone() const override;

    //methods

    //getters
    const char* GetSpell() const { return this->spell; };

protected:
    char* spell;

private:
    void free();
};
