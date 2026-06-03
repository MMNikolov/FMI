#pragma once

#include "Artifacts.hpp"

static unsigned globalId;

class Teleport : virtual public Artifacts
{
public:
    Teleport();

    //methods
    virtual void draw() const override;
    virtual void interact(Player& p) override;
    virtual bool IsDestroyed() const override;

protected:
    const unsigned Id;
    unsigned position;

private:
    const unsigned createId();
};

unsigned randomNum();
