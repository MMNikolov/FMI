#pragma once

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cstring>
#include <cstdlib>

#define ISBN_LENGTH 18

class Book
{
public:
    //default constructor
    Book();

    //ordinary constructor
    Book(const char* title, const char* author, double kg);

    //copy constructor
    Book(const Book& other);
    Book& operator=(const Book& other);

    //destructor
    ~Book();

    double getKg() const;
    char* getAuthor() const;
    char* getTitle() const;
    char getISBN() const;

private:
    char *title;
    char *author;
    double kg;
    char ISBN[ISBN_LENGTH];

    void free();
    void copyFrom(const Book& other);
    char* createISBN();
};

class Backpack
{
public:
    //default constructor
    Backpack();

    //ordinary constructor
    Backpack(double capacity);

    //copy constructor
    Backpack(const Book& other);
    Book& operator=(const Book& other);

    //destructor
    ~Backpack();

    void addBook(Book& book);
    void removeBook(char ISBN[ISBN_LENGTH]);

    void writeInBinary(std::ostream& out) const ;
    void readInBinary(std::istream& in);

private:
    Book* books;
    double capacity;
    unsigned short booksCount;

    void free();
    void copyFrom(const Backpack& other);
};
