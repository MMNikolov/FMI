#ifndef FLOWER_HPP
#define FLOWER_HPP

#include "Plant.hpp"

class Flower : public Plant
{
public:
    Flower(/* args */);
    ~Flower();

private:
    bool blooms[12];
};

#endif // FLOWER_HPP
