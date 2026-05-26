#include "Monster.hpp"

Monster::Monster()
    : power(0), hp(0)
{
    this->name = new char[1];
    this->name[0] = '\0';
}

Monster::Monster(const char *name, unsigned power, unsigned hp)
{
    //lets say that the power and the HP cant be over 1000
    if (!name || power > 1000 || hp > 1000)
    {
        throw std::invalid_argument("Invalid input for the Monster");
    }
    
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->power = power;
    this->hp = hp;
}

Monster::Monster(const Monster &other)
{
    copyFrom(other);
}

Monster &Monster::operator=(const Monster &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    
    return *this;
}

Monster::~Monster()
{
    free();
}

void Monster::interact(Player &p) const
{
    if (this->power > p.getHP())
    {
        std::cout << "The player has been slain";
        return;
    }

    std::cout << "The player haas taken " << this->power << " damage.\n"; 
    p.setHP(p.getHP() - power);
}

bool Monster::isDestroyed() const
{
    if (this->hp <= 0)
    {
        return true;
    }
    
    return false;
}

void Monster::copyFrom(const Monster &other)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

    this->power = other.power;
    this->hp = other.hp;
}

void Monster::free()
{
    delete[] this->name;
}
