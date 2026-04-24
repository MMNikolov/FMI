#pragma once

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cstring>

#define ID_MAX_SIZE 12
#define MAX_BOOKS 500
#define BUFFER_SIZE 1024

class Book
{
public:
    // default constructor
    Book();

    // parametrized constructor
    Book(const char *title, const char *author, unsigned short pages);

    // copy constrcutor
    Book(const Book &other);
    Book &operator=(const Book &other);

    // destructor
    ~Book();

    // methods
    void writeInTxt(std::ostream &out) const;
    void readFromTxt(std::istream &in);
    void changeTitleAndAuthor(const char *newTitle, const char *newAuthor);

    // getters
    const char *getTitle() const;
    const char *getAuthor() const;
    unsigned short getPages() const;
    const char *getId() const;

private:
    char *title;
    char *author;
    // lets say that its impossible for a book to have more than 65000 pages
    unsigned short pages;
    char Id[ID_MAX_SIZE];

    static unsigned int GlobalId;
    static char* createId();
    static void IncrementId();

private:
    void free();
    void copyFrom(const Book& other);
};

class Bookshelf
{
public:
    //default constructor
    Bookshelf();

    //parametrized constructor
    Bookshelf(unsigned short rafts, unsigned short maxPagesOnRaft);

    //------------------
    //No copy constrcutor stated by the exercise  
    //------------------

    //destructor
    ~Bookshelf();

    //methods
    void AddBook(const Book* book);
    void RemoveBook(const Book* book);
    Book& searchBookByTitle(const char* title);
    void resizeRaft(unsigned short newMaxPagesOnRaft);

    //getters
    unsigned short getRafts();
    unsigned short getMaxPagesOnRaft();
    unsigned short getBooksInTheBookshelf();

private:
    unsigned short rafts;
    unsigned short maxPagesOnRaft;
    unsigned short booksInTheBookshelf;
    Book** books;

private:
    void free();
};
