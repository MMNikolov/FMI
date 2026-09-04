#ifndef BACKPACK_HPP
#define BACKPACK_HPP

#include "Book.hpp"

class BackPack
{
public:
    BackPack(float weightCapacity);

    //copy constructors
    BackPack(const BackPack& other);
    BackPack& operator=(const BackPack& other);

    //destructor
    ~BackPack();

    //methods
    bool addBook(const Book& book);
    bool removeBook(const ISBN& isbn);

    //save and read from file
    void saveToFile(const char* filename) const;
    void loadFromFile(const char* filename);

private:
    Book** books;
    unsigned count;
    unsigned capacity;
    float currentWeight;
    const float weightCapacity;

private:
    void free();
    void copyFrom(const BackPack& other);
    void grow();
};

#endif // BACKPACK_HPP