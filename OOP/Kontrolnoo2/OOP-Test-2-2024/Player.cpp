#include "Player.hpp"

Player::Player(int health, const char *name, int position, TypeOfWeapon weaponType, int attackDamage)
{
    //I didnt make them usnigned, because in RPG games it could be possible
    //for the player to go below 0 HP and then revert back to 4 billion (unsigned)
    if (health < 0 || !name || position < 0 || weaponType < 0 || weaponType > 4 || attackDamage < 0)
    {
        throw std::invalid_argument("Invalid inout in the abstract class");
    }
    
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->health = health;
    this->position = position;
    this->weaponType = weaponType;
    this->attackDamage = attackDamage;
}

Player::Player(const Player &other)
{
    copyFrom(other);
}

Player &Player::operator=(const Player &other)
{
    if (this != & other)
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

void Player::free()
{
    delete[] this->name;
    this->name = nullptr;
}

void Player::copyFrom(const Player &other)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    this->health = other.health;
    this->position = other.position;
    this->weaponType = other.weaponType;
    this->attackDamage = other.attackDamage;
}
