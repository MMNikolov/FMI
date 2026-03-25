#pragma once

#include <iostream>
#include <fstream>
#include <cstring>
#define MAX_CHAR_IN_NAME 16
#define MAX_FRUITS 20

enum Color
{
    BROWN,
    PINK,
    GREEN,
    ORANGE,
    RED,
    YELLOW,
    OTHER
};

struct Fruit
{
    char name[MAX_CHAR_IN_NAME];
    Color colour;
    struct Characteristics
    {
        bool isYearly;
        bool isTropical;
        bool isSweet;
        bool withPyrene;
        bool growsOnTrees;

    } characteristics;
    unsigned int energy;
};

struct Fruits
{
    Fruit fruit[MAX_FRUITS];
};

Color stringToColor(const char* str);
void readFruitFromTxt(Fruits &fruits, std::istream& is, unsigned size);
void writeFruitInTxt(Fruits &fruits, std::ostream& os, unsigned size);
void writeFruitInBinary(Fruits &fruit, std::ofstream& os, unsigned size);
void readFruitFromBinary(Fruits &fruit, std::ifstream& is);
void compareTwoFruits(Fruit &fruit1, Fruit &fruit2);
Fruits sortByName(Fruits &fruits);
void writeFromTxtByColor(std::ifstream& is, Fruits& fruits);
void removeFromBinaryFileIfRepeated(std::ifstream& is, Fruits& fruits);
void replaceNameForFruitTxt(std::ifstream& is, const char* oldname, const char* newName);
void replaceNameForFruitBinary(std::ifstream& is, const char* oldname, const char* newName);