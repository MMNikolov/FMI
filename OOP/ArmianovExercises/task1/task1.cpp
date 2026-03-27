#include "task1.hpp"

// txt work
Color stringToColor(const char *str)
{
    if (strcmp(str, "red") == 0)
        return RED;
    if (strcmp(str, "yellow") == 0)
        return YELLOW;
    if (strcmp(str, "green") == 0)
        return GREEN;
    if (strcmp(str, "brown") == 0)
        return BROWN;
    if (strcmp(str, "pink") == 0)
        return PINK;
    if (strcmp(str, "orange") == 0)
        return ORANGE;
    return OTHER;
};

void readFruitFromTxt(Fruits &fruits, std::istream &is, unsigned size)
{
    for (size_t i = 0; i < size; i++)
    {
        char colorStr[20];
        is >> fruits.fruit[i].name >> colorStr >> fruits.fruit[i].growsOnTrees >> fruits.fruit[i].isSweet >> fruits.fruit[i].isTropical >> fruits.fruit[i].isYearly >> fruits.fruit[i].withPit >> fruits.fruit[i].energy;
        fruits.fruit[i].colour = stringToColor(colorStr);
    }
};

void writeFruitInTxt(Fruits &fruits, std::ostream &os, unsigned size)
{
    for (unsigned i = 0; i < size; i++)
    {
        char colourStr[7][10] = {"brown", "pink", "green", "orange", "red", "yellow", "other"};
        os << std::boolalpha;
        os << "Name: " << fruits.fruit[i].name << ", "
           << "Color: " << colourStr[fruits.fruit[i].colour] << ", "
           << "Is it growing on trees: " << fruits.fruit[i].growsOnTrees << ", "
           << "Is it sweet: " << fruits.fruit[i].isSweet << ", "
           << "Is it tropical: " << fruits.fruit[i].isTropical << ", "
           << "Is it an yearly fruit: " << fruits.fruit[i].isYearly << ", "
           << "Is it with a pyrene: " << fruits.fruit[i].withPit << ", "
           << "How much energy per 100g: " << fruits.fruit[i].energy << ";\n";
    }
};

// binary work
void writeFruitInBinary(Fruits &fruits, std::ofstream &os, unsigned size)
{
    for (unsigned i = 0; i < size; i++)
    {
        os.write(reinterpret_cast<char *>(&fruits.fruit[i]), sizeof(Fruit));
    }
};

void readFruitFromBinary(Fruits &fruits, std::ifstream &is, unsigned num)
{
    is.read(reinterpret_cast<char *>(&fruits.fruit), sizeof(Fruit) * num);
};

void compareTwoFruits(Fruit &fruit1, Fruit &fruit2)
{
    if (strcmp(fruit1.name, fruit2.name) == 0)
    {
        std::cout << "The fruits are the same lexicographique";
    }
    else if (strcmp(fruit1.name, fruit2.name) > 0)
    {
        std::cout << "The first fruit is bigger lexicographique";
    }
    else
    {
        std::cout << "The second fruit is bigger lexicographique";
    }
};

Fruits sortByName(Fruits &fruits)
{
    
};

void writeFromTxtByColor(std::ifstream &is, Fruits &fruits);
void removeFromBinaryFileIfRepeated(std::ifstream &is, Fruits &fruits);
void replaceNameForFruitTxt(std::ifstream &is, const char *oldname, const char *newName);
void replaceNameForFruitBinary(std::ifstream &is, const char *oldname, const char *newName);