#ifndef BOOK_HPP
#define BOOK_HPP

#include <iostream>
#include <cstring>
#include <exception>
#include <fstream>
#include "ISBN.hpp"
#define ISBN_LENGTH 13

class Book
{
public:
    //ordinary constructor
    Book(const char* name, const char* author, float kg, const ISBN& isbn);

    //copy Constructors
    Book(const Book& other);
    Book& operator=(const Book& other);

    //destructor
    ~Book();

    //getters
    const char* getName() const { return this->name; };
    const char* getAuthor() const { return this->author; };
    float getWeight() const { return this->kg; };
    const ISBN& getISBN() const { return this->isbn; };   // ADDED: you had no way to read it back out at all

    //setters
    void setName(const char* newName);
    void setAuthor(const char* newAuthor);

private:
    char* name;
    char* author;
    float kg;
    ISBN isbn;

private:
    void free();
};

#endif // BOOK_HPP