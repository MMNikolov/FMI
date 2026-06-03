#include "Gift.hpp"

Gift::Gift(int hp)
{
    if (hp > 200 || hp <= 0)
    {
        throw std::invalid_argument("Invalid input for the gift constructor");
    }

    this->hp = hp;
}

void Gift::draw() const
{
    std::cout << "[Gift] Gift that has: " << this->hp << " HP" << '\n';
}

void Gift::interact(Player &p)
{
    int missingHP = p.getMaxHP() - p.getHP();
    int healAmount = (this->hp > missingHP) ? missingHP : this->hp;

    p.setHP(p.getHP() + healAmount);
    this->hp -= healAmount;
}

bool Gift::IsDestroyed() const
{
    if (this->hp <= 0)
    {
        return true;
    }
    
    return false;
}
