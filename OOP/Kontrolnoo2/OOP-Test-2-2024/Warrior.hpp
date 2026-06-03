#pragma once

#include "Player.hpp"

class Warrior : public Player
{
public:
    Warrior(int health, const char* name, int position, TypeOfWeapon weaponType, int attackDamage, int armour);

    Warrior(const Warrior& other);
    Warrior& operator=(const Warrior& other);

    //No need for a destructor when we dont have dynamically allocated data

    //overriden methods
    virtual void move() override;
    virtual void handleAttack(const Player& player) override;
    virtual void print(std::ofstream& out) const override;

    //normal getters
    int GetArmour() const { return this->armour; }

private:
    int armour;
};
