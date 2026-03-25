#include "task1.hpp"

Color stringToColor(const char* str)
{
    if (strcmp(str, "red") == 0) return RED;
    if (strcmp(str, "yellow") == 0) return YELLOW;
    if (strcmp(str, "green") == 0) return GREEN;
    if (strcmp(str, "brown") == 0) return BROWN;
    if (strcmp(str, "pink") == 0) return PINK;
    if (strcmp(str, "orange") == 0) return ORANGE;
    return OTHER;
};

void readFruitFromTxt(Fruits &fruits, std::istream& is, unsigned size)
{
    for (size_t i = 0; i < size; i++)
    {
        char colorStr[20];
        is >> fruits.fruit[i].name 
           >> colorStr 
           >> fruits.fruit[i].characteristics.growsOnTrees
           >> fruits.fruit[i].characteristics.isSweet 
           >> fruits.fruit[i].characteristics.isTropical
           >> fruits.fruit[i].characteristics.isYearly 
           >> fruits.fruit[i].characteristics.withPyrene
           >> fruits.fruit[i].energy;
        fruits.fruit[i].colour = stringToColor(colorStr);
    }
};

void writeFruitInTxt(Fruits &fruits, std::ostream& os, unsigned size)
{
    for (unsigned i = 0; i < size; i++)
    {
        char colourStr[7][10] = {"brown", "pink", "green", "orange", "red", "yellow", "other"};
        os << std::boolalpha;
        os << "Name: " << fruits.fruit[i].name << ", "
           << "Color: " << colourStr[fruits.fruit[i].colour] << ", "
           << "Is it growing on trees: " << fruits.fruit[i].characteristics.growsOnTrees << ", "
           << "Is it sweet: " << fruits.fruit[i].characteristics.isSweet << ", "
           << "Is it tropical: " << fruits.fruit[i].characteristics.isTropical << ", "
           << "Is it an yearly fruit: " << fruits.fruit[i].characteristics.isYearly << ", "
           << "Is it with a pyrene: " << fruits.fruit[i].characteristics.withPyrene << ", "
           << "How much energy per 100g: " << fruits.fruit[i].energy << ";\n";
    }
};

void writeFruitInBinary(Fruits &fruits, std::ofstream& os, unsigned size)
{
    for (unsigned i = 0; i < size; i++)
    {
        os.write(reinterpret_cast<char* >(&fruits.fruit[i]),  sizeof(Fruit));
    }
};

void readFruitFromBinary(Fruits &fruits, std::ifstream& is);
void compareTwoFruits(Fruit &fruit1, Fruit &fruit2);
Fruits sortByName(Fruits &fruits);
void writeFromTxtByColor(std::ifstream& is, Fruits& fruits);
void removeFromBinaryFileIfRepeated(std::ifstream& is, Fruits& fruits);
void replaceNameForFruitTxt(std::ifstream& is, const char* oldname, const char* newName);
void replaceNameForFruitBinary(std::ifstream& is, const char* oldname, const char* newName);