#include "Mage.hpp"

Mage::Mage(int health, const char *name, int position, TypeOfWeapon weaponType, int attackDamage, const char *skill, double coefficient)
    : Player(health, name, position, weaponType, attackDamage)
{
    if (coefficient > 1 || coefficient < 0 || !name)
    {
        throw std::invalid_argument("Not a valid inpout for mage");
    }
    
    this->skill = new char[strlen(skill) + 1];
    strcpy(this->skill, skill);
    this->coefficient = coefficient;
}

Mage::Mage(const Mage &other)
    : Player(other)
{
    this->skill = new char[strlen(other.skill) + 1];
    strcpy(this->skill, other.skill);

    this->coefficient = other.coefficient;
}

Mage &Mage::operator=(const Mage &other)
{
    if (this != &other)
    {
        Player::operator=(other);
        free();
        this->skill = new char[strlen(other.skill) + 1];
        strcpy(this->skill, other.skill);

        this->coefficient = other.coefficient;
    }
    
    return *this;
}

Mage::~Mage()
{
    free();
}

void Mage::move()
{
    this->position += 1;
}

void Mage::handleAttack(const Player &player)
{
    if ((this->position - player.GetPosition()) > 1 || (this->position - player.GetPosition()) < -1)
    {
        throw std::invalid_argument("Not close enough to handle the attack");
    }
    
    if (this->health < player.GetAttackDamage())
    {
        std::cout << "The Mage has been slain";
        return;
    }

    this->health -= player.GetAttackDamage();
}

void Mage::print(std::ofstream &out) const
{
    int num = this->GetWeaponType();
    char* weapons[4] = {"Sword", "Wand", "Staff", "Axe"};
    out << "[Mage]" << this->health << ' ' << this->name << ' ' << this->attackDamage << ' ' << weapons[num];
}

void Mage::free()
{
    delete[] this->skill;
    this->skill = nullptr;
}
