#pragma once

#include "Mage.hpp"

class Necromancer : public Mage
{
public:
    Necromancer(int health, const char *name, int position, TypeOfWeapon weaponType, int attackDamage, const char *skill, double coefficient);

    Necromancer(const Necromancer& other);
    Necromancer& operator=(const Necromancer& other);

    ~Necromancer();

    //overriden methods
    void move() override;
    void handleAttack(const Player& player) override;
    void print(std::ofstream& out) const override;
    Player* clone() override;

    //getter
    unsigned GetUndeadCount() const { return this->undeadCount; }

private:
    Player* undeadSoldiers;
    unsigned undeadCount;

    void free();
};
