#pragma once
#include "Player.hpp"
#include <stdexcept>
#include <cstring>

class PlayerCollection
{
public:
    PlayerCollection();

    PlayerCollection(const PlayerCollection& other);
    PlayerCollection& operator=(const PlayerCollection& other);
    
    ~PlayerCollection();
    
    void addPlayer(Player& player);
    bool removePlayer(const char* name);
    
    // Read-only access as required by the assignment
    const Player& operator[](unsigned index) const;
    unsigned getCount() const;

private:
    Player** players;
    unsigned count;
    unsigned capacity;

    void resize();
    void free();
    void copyFrom(const PlayerCollection& other);
};