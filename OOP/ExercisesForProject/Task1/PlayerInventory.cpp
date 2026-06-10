#include "PlayerInventory.hpp"

PlayerInventory::PlayerInventory()
    : items()
{}

void PlayerInventory::lootItem(const std::string &item)
{
    this->items.push_back(item);
}

bool PlayerInventory::dropItem(const std::string &item)
{
    int size = this->items.size();

    if (size <= 0)
    {
        throw std::invalid_argument("NUh uh");
    }

    for (unsigned i = 0; i < size; i++)
    {
        if (this->items.at(i) == item)
        {
            this->items.at(i).erase();
            return true;
        }
    }
    
    return false;
}

std::vector<std::string> PlayerInventory::filterWeapons() const
{
    std::vector<std::string> filteredItems;
    int size = this->items.size();

    if (size <= 0)
    {
        throw std::invalid_argument("cmon man..");
    }

    for (unsigned i = 0; i < size; i++)
    {
        if (this->items[i] == "Sword" || 
            this->items[i] == "Axe" ||
            this->items[i] == "Wand" || 
            this->items[i] == "Staff")
        {
            filteredItems.push_back(this->items[i]);
        }
    }

    return filteredItems;
}

std::vector<std::string> PlayerInventory::GetItems() const
{
    return this->items;
}
