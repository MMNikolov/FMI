#pragma once

#include <iostream>
#include <stdexcept>
#include <cstring>
#include <ctime>
#include <random>

class Player
{
public:
    Player();
    Player(const char* name, int HP, int maxHP, int power);
    Player(const Player& other);
    Player& operator=(const Player& other);
    ~Player();

    //getters
    const char* getName() const { return this->name; };
    int getHP() const {return this->HP; };
    int getMaxHP() const { return this->maxHP; };
    int getPower() const { return this->power; };
    unsigned getPositin() const { return this->position; };

    //setters
    void setHP(int HP);
    void setMaxHP(int maxHP);
    void setPower(int Power);
    void setPosition(unsigned newPos);

private:
    char* name;
    int HP;
    int maxHP;
    int power;
    unsigned position;

private:
    void copyFrom(const Player& other);
    void free();
};
