#include "Monster.hpp"

Monster::Monster()
    : power(0), hp(0)
{
    this->name = new char[1];
    this->name[0] = '\0';
}

Monster::Monster(const char *name, int power, int hp)
{
    // lets say that the power and the HP cant be over 1000
    if (!name || power > 1000 || hp > 1000 || power <= 0 || hp <= 0)
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

void Monster::draw() const
{
    std::cout << "[Monster] There is a monster in the way. Slay it";
}

void Monster::interact(Player &p)
{
    std::cout << "The player has taken " << this->power << " damage.\n";
    p.setHP(p.getHP() - this->power);

    std::cout << "The monster has taken " << p.getPower() << " damage.\n";
    this->hp -= p.getPower();

    if (p.getHP() <= 0)
    {
        std::cout << "The player has been slain!\n";
    }
}

bool Monster::IsDestroyed() const
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
