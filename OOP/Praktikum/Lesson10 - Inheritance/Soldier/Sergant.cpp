#include "Sergant.hpp"

Sergant::Sergant()
    : vzvoda(nullptr), soldiers(nullptr)
{}

Sergant::Sergant(const char *vzvoda)
    : Soldier(this->getName(), this->getAge(), this->getPowerLevel(), this->getGold()), soldiers(nullptr)
{
    this->vzvoda = new char[strlen(vzvoda) + 1];
    strcpy(this->vzvoda, vzvoda);

    this->soldiers = nullptr;
}

Sergant::Sergant(const Sergant &other)
    : Soldier(other)
{
    this->vzvoda = new char[strlen(other.vzvoda) + 1];
    strcpy(this->vzvoda, other.vzvoda);

    for (int i = 0; i < this->soldiersCnt; i++)
    {
        this->soldiers[i] = other.soldiers[i];
    }
}

Sergant &Sergant::operator=(const Sergant &other)
{
    if (this != &other)
    {
        free();

        try
        {
            Soldier::operator= (other);
        }
        catch(const std::exception& e)
        {
            delete[] this->vzvoda;
            std::cerr << e.what() << '\n';
            throw std::invalid_argument("Invalid = operator on Sergant");
        }
    }
}

Sergant::~Sergant()
{
    free();
}

void Sergant::free()
{
    delete[] vzvoda;
}
