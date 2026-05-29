#include "CombinedItem.hpp"

CombinedItem::CombinedItem(unsigned hp)
    : Gift(hp), Teleport()
{}

void CombinedItem::draw() const
{
    std::cout << "[Combined item] You have stumbled upon a combined item!";
}

void CombinedItem::interact(Player &p)
{
    Gift::interact(p);
    Teleport::interact(p);
}

bool CombinedItem::IsDestroyed() const
{
    return false;
}
