#include "Book.hpp"

// Book(std::istream in);
Book::Book(const char* title, const char* author, unsigned pages) : ID(createID())
{

};

//     Book(const Book& other);
//     Book& operator=(const Book& other);

//     ~Book();

//     //funcs
//     void printBooks(std::ostream& out);
//     const char* GetTitle() const { return this->title; };
//     const char* GetAuthor() const { return this->author; };
//     unsigned GetPages() const { return this->pages; };

//     bool SetTitle(const char* newTitle);
//     bool SetAuthor(const char* newAuthor);

char* Book::createID()
{
    
}