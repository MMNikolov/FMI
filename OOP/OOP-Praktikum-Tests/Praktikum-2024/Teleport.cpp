#include "Teleport.hpp"

Teleport::Teleport()
    : Id(createId()), position(randomNum())
{}

void Teleport::draw() const
{
    std::cout << "[Portal] Portal created at position: " << this->position << '\n';
}

void Teleport::interact(Player &p)
{
    p.setPosition(randomNum());
}

bool Teleport::IsDestroyed() const
{
    return false;
}

const unsigned Teleport::createId()
{
    return ++globalId;
}

unsigned randomNum()
{
    return (rand() % 100) + 1;
}
