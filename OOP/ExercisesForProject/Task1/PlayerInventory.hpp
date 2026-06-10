#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>

class PlayerInventory
{
public:
    PlayerInventory();
    //should we keep the destructor or the copy ctors? Ask Gemini;
    //~PlayerInventory();

    //methods
    void lootItem(const std::string& item);
    bool dropItem(const std::string& item);
    std::vector<std::string> filterWeapons() const;

    //getters
    std::vector<std::string> GetItems() const;

private:
    std::vector<std::string> items;
};
