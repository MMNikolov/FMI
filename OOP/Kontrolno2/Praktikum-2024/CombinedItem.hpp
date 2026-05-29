#pragma once

#include "Gift.hpp"
#include "Teleport.hpp"

class CombinedItem : public Gift, public Teleport
{
public:
    CombinedItem(unsigned hp);

    //methods
    virtual void draw() const override;
    virtual void interact(Player& p) override;
    virtual bool IsDestroyed() const override;

private:
};
