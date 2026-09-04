#include "Plant.hpp"

Plant::Plant(const char *species, const char *sort, unsigned height, const Type &type)
    : species(nullptr), sort(nullptr), height(height), type(type), description(nullptr)
{
    if (!species || !sort || (int)type < 0 || (int)type > 3)
    {
        throw std::invalid_argument("Problem in the contructor of Plant");
    }
    
    this->species = new char[strlen(species) + 1];
    strcpy(this->species, species);

    this->sort = new (std::nothrow) char[strlen(sort) + 1];
    if (!this->sort)
    {
        delete[] this->species;
        throw std::bad_alloc();
    }
    strcpy(this->sort, sort);
}

Plant::Plant(const Plant &other)
    : species(nullptr), sort(nullptr), height(other.height), type(other.type)
{
    copyFrom(other);
}

Plant &Plant::operator=(const Plant &other)
{
    if (this != &other)
    {
        char* tempSpecies = new char[strlen(other.species) + 1];
        strcpy(tempSpecies, other.species);

        char* tempSort = new (std::nothrow) char[strlen(other.sort) + 1];
        if (!tempSort)
        {
            delete[] tempSpecies;
            throw std::bad_alloc();
        }
        strcpy(tempSort, other.sort);

        free();
        this->species = tempSpecies;
        this->sort = tempSort;
        this->height = other.height;
    }
    
    return *this;
}

Plant::~Plant()
{
    free();
}

void Plant::setDescription(const char *description)
{
    if (!description)
    {
        throw std::invalid_argument("this is an invalid argument");
    }
    
    this->description = new char[strlen(description) + 1];
    strcpy(this->description, description);
}

void Plant::free()
{
    delete[] this->species;
    delete[] this->sort;
}

void Plant::copyFrom(const Plant& other)
{
    this->species = new char[strlen(other.species) + 1];
    strcpy(this->species, other.species);

    this->sort = new (std::nothrow) char[strlen(other.sort) + 1];
    if (!this->sort)
    {
        throw std::bad_alloc();
    }
    strcpy(this->sort, other.sort);
};
