#pragma once

#include "Banana.hpp"

class Bunch : public Banana
{
public:
    Bunch(const char *name, bool isHidden, bool isRotten, bool toEat, bool watchOnly);

    Bunch(const Bunch& other) = delete;
    Bunch& operator=(const Bunch& other) = delete;

    ~Bunch();

    //methods
    void operator+(const char* info) override;

private:
    Banana* bananas;

    void free();
};
