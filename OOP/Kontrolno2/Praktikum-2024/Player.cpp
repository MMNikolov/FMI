#include "Player.hpp"

Player::Player()
    : HP(0), maxHP(0), power(0), position(1)
{
    this->name = new char[1];
    this->name[0] = '\0';
}

Player::Player(const char *name, int HP, int maxHP, int power)
    : position(1)
{
    // lets say that a character cant have more than 1000 hp and 1000 power
    if (!name || HP > maxHP || maxHP > 1000 || power > 1000 || HP <= 0 || maxHP <= 0 || power <= 0)
    {
        throw std::invalid_argument("Invalid input in Player!");
    }

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->HP = HP;
    this->maxHP = maxHP;
    this->power = power;
}

Player::Player(const Player &other)
{
    copyFrom(other);
}

Player &Player::operator=(const Player &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }

    return *this;
}

Player::~Player()
{
    free();
}

void Player::setHP(int newHP)
{
    if (newHP >= maxHP)
    {
        this->HP = maxHP;
    }
    else
    {
        this->HP = newHP;
    }
}

void Player::setMaxHP(int maxHP)
{
    if (maxHP > 1000 || maxHP <= 0)
    {
        throw std::invalid_argument("You cant set more than 1000 HP or lower than 0");
    }

    this->maxHP = maxHP;
}

void Player::setPower(int Power)
{
    // lets say that the power cant reach over 1000
    if (Power > 1000 || Power <= 0)
    {
        throw std::invalid_argument("You cant set more than 1000 power and it cant be lower than 0");
    }

    this->power = Power;
}

void Player::setPosition(unsigned newPos)
{
    if (newPos > 100)
    {
        throw std::invalid_argument("You cant play putside the board stupid");
    }

    this->position = newPos;
}

void Player::copyFrom(const Player &other)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

    this->HP = other.HP;
    this->maxHP = other.maxHP;
    this->power = other.power;
    this->position = other.position;
}

void Player::free()
{
    delete[] this->name;
}
