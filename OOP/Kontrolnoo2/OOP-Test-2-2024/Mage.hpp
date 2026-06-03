#pragma once

#include "Player.hpp"

class Mage : public Player
{
public:
    Mage(int health, const char* name, int position, TypeOfWeapon weaponType, int attackDamage, const char* skill, double coefficient);

    Mage(const Mage& other);
    Mage& operator=(const Mage& other);

    ~Mage();

    //overriden methods
    void move() override;
    void handleAttack(const Player& player) override;
    void print(std::ofstream& out) const override;

    //getters
    const char* GetSkill() const { return this->skill; };
    const double GetCoef() const { return this->coefficient; }

protected:
    char* skill;
    // [0-1]
    double coefficient;

private:
    void free();
};
