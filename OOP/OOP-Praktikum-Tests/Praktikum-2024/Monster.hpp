#pragma once

#include "Artifacts.hpp"

class Monster : public Artifacts
{
public:
    Monster();
    Monster(const char* name, int power, int hp);
    Monster(const Monster& other);
    Monster& operator=(const Monster& other);
    ~Monster();

    //methods
    void draw() const override;
    void interact(Player& p) override;
    bool IsDestroyed() const override;

private:
    char* name;
    int power;
    int hp;
    unsigned position;

private:
    void copyFrom(const Monster& other);
    void free();
};
