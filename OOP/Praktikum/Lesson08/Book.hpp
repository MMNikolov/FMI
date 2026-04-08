#pragma once

#include <iostream>
#include <cstring>
#include <stdexcept>

class Book
{
public:
    //constructor
    Book(std::istream in);
    Book(const char* title, const char* author, unsigned pages);

    Book(const Book& other);
    Book& operator=(const Book& other);

    ~Book();

    //funcs
    void printBooks(std::ostream& out);
    const char* GetTitle() const { return this->title; };
    const char* GetAuthor() const { return this->author; };
    unsigned GetPages() const { return this->pages; };

    bool SetTitle(const char* newTitle);
    bool SetAuthor(const char* newAuthor);

private:
    static char* createID();

    char* title;
    char* author;
    unsigned pages;

    const char* ID;

    static int counter;
    static int counterID;
};
