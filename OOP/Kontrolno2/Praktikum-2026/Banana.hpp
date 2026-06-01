#pragma once

#include <iostream>
#include <stdexcept>
#include <cstring>
#include <fstream>

class Banana
{
public:
    Banana(const char *name, bool isHidden, bool isRotten, bool toEat, bool watchOnly);

    Banana(const Banana &other) = delete;
    Banana &operator=(const Banana &other) = delete;

    virtual ~Banana();

    // methods
    friend std::ostream &operator<<(std::ostream &os, const Banana &banana);
    virtual void operator+(const char* info) = 0;
    virtual unsigned getWeight() const = 0;

protected:
    const unsigned Id;
    char *name;
    bool isHidden;
    bool isRotten;
    bool toEat;
    bool watchOnly;

private:
    static unsigned BananaId;
    static unsigned IdCounter() { return ++BananaId; };

    void free();
};

std::ostream &operator<<(std::ostream &os, const Banana &banana);