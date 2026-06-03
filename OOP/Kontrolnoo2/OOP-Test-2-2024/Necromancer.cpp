#include "Necromancer.hpp"

Necromancer::Necromancer(int health, const char *name, int position, TypeOfWeapon weaponType, int attackDamage, const char *skill, double coefficient)
    : Mage(health, name, position, weaponType, attackDamage, skill, coefficient)
{
    this->undeadCount = 0;
    this->undeadSoldiers = nullptr;
}

Necromancer::Necromancer(const Necromancer &other)
    : Mage(other)
{}

Necromancer &Necromancer::operator=(const Necromancer &other)
{
    if (this != &other)
    {
        Mage::operator=(other);
        free();
        this->undeadCount = other.undeadCount;
        for (unsigned i = 0; i < this->undeadCount; i++)
        {
            this->undeadSoldiers[i] = other.undeadSoldiers[i];
        }
    }
}

Necromancer::~Necromancer()
{
    free();
}

void Necromancer::move()
{
    this->position += 1;
}

void Necromancer::handleAttack(const Player &player)
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

void Necromancer::print(std::ofstream &out) const
{
    int num = this->GetWeaponType();
    char* weapons[4] = {"Sword", "Wand", "Staff", "Axe"};
    out << "[Necromancer]" << this->health << ' ' << this->name << ' ' << this->attackDamage << ' ' << weapons[num];
}

void Necromancer::free()
{
    delete[] this->undeadSoldiers;
    this->undeadSoldiers = nullptr;
}
