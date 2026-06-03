#include "Warrior.hpp"

Warrior::Warrior(int health, const char *name, int position, TypeOfWeapon weaponType, int attackDamage, int armour)
    : Player(health, name, position, weaponType, attackDamage)
{
    if (armour < 0)
    {
        throw std::invalid_argument("Invalid input in warrior");
    }

    this->armour = armour;
}

Warrior::Warrior(const Warrior &other)
    : Player(other)
{
    this->armour = other.armour;
}

Warrior &Warrior::operator=(const Warrior &other)
{
    if (this != &other)
    {
        Player::operator=(other);
        this->armour = other.armour;
    }
    
    return *this;
}

//dont know what to do so imma just increment by one
void Warrior::move()
{
    this->position += 1;
}

void Warrior::handleAttack(const Player &player)
{
    if ((this->position - player.GetPosition()) > 1 || (this->position - player.GetPosition()) < -1)
    {
        throw std::invalid_argument("Not close enough to handle the attack");
    }
    

    if (this->health < player.GetAttackDamage() + this->armour)
    {
        std::cout << "The Warrior has been slain";
        return;
    }
    
    if (this->armour > 0)
    {
        if (this->armour < player.GetAttackDamage())
        {
            int remainderOfTheAttack = player.GetAttackDamage() - this->armour;
            this->armour = 0;
            this->health -= remainderOfTheAttack;
        }
        else
        {
            this->armour -= player.GetAttackDamage();
        }
    }
    else
    {
        this->health -= player.GetAttackDamage();
    }
}

void Warrior::print(std::ofstream &out) const
{
    int num = this->GetWeaponType();
    char* weapons[4] = {"Sword", "Wand", "Staff", "Axe"};
    out << "[Warrior]" << this->health << ' ' << this->name << ' ' << this->attackDamage << ' ' << weapons[num];
}
