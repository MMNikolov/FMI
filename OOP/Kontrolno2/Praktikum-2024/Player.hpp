#pragma once

#include <iostream>
#include <stdexcept>
#include <cstring>

class Player
{
public:
    Player();
    Player(const char* name, unsigned HP, unsigned maxHP, unsigned power);
    Player(const Player& other);
    Player& operator=(const Player& other);
    ~Player();

    //getters
    const char* getName() const { return this->name; };
    unsigned getHP() const {return this->HP; };
    unsigned getMaxHP() const { return this->maxHP; };
    unsigned getPower() const { return this->power; };
    unsigned getPositin() const { return this->position; };

    //setters
    void setHP(unsigned HP);
    void setMaxHP(unsigned maxHP);
    void setPower(unsigned Power);
    void setPosition(unsigned newPos);

private:
    char* name;
    unsigned HP;
    unsigned maxHP;
    unsigned power;
    unsigned position;

private:
    void copyFrom(const Player& other);
    void free();
};
