#pragma once

#include "TypeOfWeapon.hpp"
#include <iostream>
#include <cstring>
#include <fstream>
#include <stdexcept>

class Player
{
public:
    Player(int health, const char* name, int position, TypeOfWeapon weaponType, int attackDamage);

    Player(const Player& other);
    Player& operator=(const Player& other);

    virtual ~Player();

    //methods
    virtual void move() = 0;
    virtual void handleAttack(const Player& player) = 0;
    virtual void print(std::ofstream& out) const = 0;
    virtual Player* clone();

    //getters
    int GetHealth() const { return this->health; };
    const char* GetName() const { return this->name; };
    int GetPosition() const { return this->position; };
    TypeOfWeapon GetWeaponType() const { return this->weaponType; };
    int GetAttackDamage() const { return this->attackDamage; };

protected:
    int health;
    char* name;
    int position;
    TypeOfWeapon weaponType;
    int attackDamage;

private:
    void free();
    void copyFrom(const Player& other);
};
