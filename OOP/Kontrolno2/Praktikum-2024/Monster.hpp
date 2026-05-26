#pragma once

#include "Artifacts.hpp"

class Monster : public Artifacts
{
public:
    Monster();
    Monster(const char* name, unsigned power, unsigned hp);
    Monster(const Monster& other);
    Monster& operator=(const Monster& other);
    ~Monster();

    //methods
    void interact(Player& p) const;
    bool isDestroyed() const;

private:
    char* name;
    unsigned power;
    unsigned hp;
    unsigned position;

private:
    void copyFrom(const Monster& other);
    void free();
};
