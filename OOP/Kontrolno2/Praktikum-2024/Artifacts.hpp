#pragma once

#include "Player.hpp"

class Artifacts
{
public:
    Artifacts();
    virtual ~Artifacts();

    //methods 
    virtual void draw() const = 0;
    virtual void interact(Player& p) = 0;
    virtual bool IsDestroyed() const = 0;

private:
};
