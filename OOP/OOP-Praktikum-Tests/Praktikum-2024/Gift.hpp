#pragma once

#include "Artifacts.hpp"

class Gift  : virtual public Artifacts
{
public:
    Gift(int hp);

    //methods
    virtual void draw() const override;
    virtual void interact(Player& p) override;
    virtual bool IsDestroyed() const override;

protected:
    int hp;
};
