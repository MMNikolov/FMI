#pragma once

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstring>

class Produce
{
public:
    // default ctor
    Produce();

    // ordinary ctor
    Produce(const char *name, const char* products);

    // copy ctor
    Produce(const Produce &other);
    Produce &operator=(const Produce &other);

    // destructor
    ~Produce();

    // methods
    const char* searchInProducts(const char *product);

private:
    char *name;
    char *products;

private:
    void free();
    void copyFrom(const Produce& other);
};

class Plant
{
public:
    // default constructor
    Plant();

    // ordinary constructor
    Plant(const char *name, double price);

    // destructor
    ~Plant();

    // getters
    const char *getName() const;
    unsigned getColumn() const;
    unsigned getRow() const;
    double getPrice() const;

private:
    const unsigned id;
    static unsigned globalId;

    char *name;
    unsigned column;
    unsigned row;
    double price;
    Produce* produce;

    bool isPlanted;
    bool isGrown;
    bool isReadyToHarvest;

private:
    void free();
};

class Field
{
public:
    //ordinary ctor
    Field(int width, int height);

    //destructor
    ~Field();

    //functionality
    bool plant(Plant& s, int row, int column);
    Produce removePlant(int plantId);
    void tick(int time);
    const int* operator[](int index);

    //streams
    void saveLog(const char* filename) const;
    void loadLog(const char* filename);

    //friend
    friend std::ostream& operator<<(std::ostream os, const Field& field);
    friend std::istream& operator>>(std::ostream& is, Field& field);

    //operators
    int operator()(const char* words, int count);
    bool operator>(const Plant& plant);
    bool operator<(const Plant& plant);

private:
    int width;
    int height;
    Plant** plants;
    unsigned plantsCount;

    void resize(int newWidth, int newHeight);
};

std::ostream& operator<<(std::ostream& os, const Field& field);
std::istream& operator>>(std::istream& is, Field& field);