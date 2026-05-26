#pragma once

#include "Items.hpp"

static unsigned globalId;

class Teleport : Items
{
public:
    Teleport();
    ~Teleport();

    //methods

private:
    const char* Id;
    unsigned position;
};
