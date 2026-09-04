#ifndef PLANT_HPP
#define PLANT_HPP

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cstring>
#include "Type.hpp"

class Plant
{
public:
    Plant(const char* species, const char* sort, unsigned height, const Type& type);

    Plant(const Plant& other);
    Plant& operator=(const Plant& other);

    virtual ~Plant();

    //methods
    const char* getSpecies() const { return this->species; };
    const char* getSort() const { return this->sort; };
    unsigned getHeight() const { return this->height; };
    Type getType() const { return this->type; };
    const char* getDescription() const { return this->description; };

    virtual void setDescription(const char* description);

private:
    char* species;
    char* sort;
    unsigned height;
    const Type type;
    char* description;

private:
    void free();
    void copyFrom(const Plant& other);
};

#endif // PLANT_HPP