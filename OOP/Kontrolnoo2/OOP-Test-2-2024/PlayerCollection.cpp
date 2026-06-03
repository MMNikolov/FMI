#include "PlayerCollection.hpp"

PlayerCollection::PlayerCollection() : count(0), capacity(4)
{
    this->players = new Player*[this->capacity];
}

PlayerCollection::PlayerCollection(const PlayerCollection& other)
{
    copyFrom(other);
}

PlayerCollection& PlayerCollection::operator=(const PlayerCollection& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

PlayerCollection::~PlayerCollection()
{
    free();
}

void PlayerCollection::addPlayer(Player& player)
{
    // Prevent duplicate names
    for (unsigned i = 0; i < this->count; ++i)
    {
        if (strcmp(this->players[i]->GetName(), player.GetName()) == 0)
        {
            throw std::invalid_argument("A player with this name already exists.");
        }
    }

    if (this->count >= this->capacity)
    {
        resize();
    }

    this->players[this->count++] = player.clone();
}

bool PlayerCollection::removePlayer(const char* name)
{
    if (!name) return false;

    for (unsigned i = 0; i < this->count; ++i)
    {
        if (strcmp(this->players[i]->GetName(), name) == 0)
        {
            delete this->players[i];
            
            // O(1) Swap with the last element to avoid shifting
            this->players[i] = this->players[this->count - 1];
            this->players[this->count - 1] = nullptr;
            this->count--;
            
            return true;
        }
    }
    return false;
}

const Player& PlayerCollection::operator[](unsigned index) const
{
    if (index >= this->count)
    {
        throw std::out_of_range("Index out of bounds.");
    }
    return *(this->players[index]);
}

unsigned PlayerCollection::getCount() const
{
    return this->count;
}

void PlayerCollection::resize()
{
    this->capacity *= 2;
    Player** newArr = new Player*[this->capacity];
    
    for (unsigned i = 0; i < this->count; ++i)
    {
        newArr[i] = this->players[i];
    }
    
    delete[] this->players;
    this->players = newArr;
}

void PlayerCollection::free()
{
    for (unsigned i = 0; i < this->count; ++i)
    {
        delete this->players[i];
    }
    delete[] this->players;
    this->players = nullptr;
}

void PlayerCollection::copyFrom(const PlayerCollection& other)
{
    this->count = other.count;
    this->capacity = other.capacity;
    this->players = new Player*[this->capacity];
    
    for (unsigned i = 0; i < this->count; ++i)
    {
        this->players[i] = other.players[i]->clone();
    }
}