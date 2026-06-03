#pragma once

#include "Banana.hpp"

#define MAX_SORT_LENGTH 5

class SimpleBanana : public Banana
{
public:
    SimpleBanana(const char *name, bool isHidden, bool isRotten, bool toEat, bool watchOnly, const char sort[MAX_SORT_LENGTH]);

    SimpleBanana(const SimpleBanana& other) = delete;
    SimpleBanana& operator=(const SimpleBanana& other) = delete;

    //methods
    friend std::ostream& operator<<(std::ostream& out, const SimpleBanana& simpleBanana);
    virtual void operator+(const char* info) override;
    unsigned getWeight() const override;

private:
    char sort[MAX_SORT_LENGTH + 1];
};

std::ostream& operator<<(std::ostream& out, const SimpleBanana& simpleBanana);
