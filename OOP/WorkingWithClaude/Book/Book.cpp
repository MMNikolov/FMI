#include "Book.hpp"

Book::Book(const char* name, const char* author, float kg, const ISBN& isbn)
    : name(nullptr), author(nullptr), kg(0), isbn(isbn)
{
    if (!name || !author)
    {
        throw std::invalid_argument("Problem with the constructor in Book");
    }
    
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->author = new (std::nothrow) char[strlen(author) + 1];
    if (!this->author)
    {
        delete[] this->name;
        throw std::bad_alloc();
    }
    strcpy(this->author, author);
    
    this->kg = kg;
}

Book::Book(const Book &other)
    : name(nullptr), author(nullptr), kg(other.kg), isbn(other.isbn)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

    this->author = new (std::nothrow) char[strlen(other.author) + 1];
    if (!this->author)
    {
        delete[] this->name;
        throw std::bad_alloc();
    }
    strcpy(this->author, other.author);
}

Book &Book::operator=(const Book &other)
{
    if (this != &other)
    {
        char* tempName = new char[strlen(other.name) + 1];
        strcpy(tempName, other.name);

        char* tempAuthor = new (std::nothrow) char[strlen(other.author) + 1];
        if (!tempAuthor)
        {
            delete[] tempName;
            throw std::bad_alloc();
        }
        strcpy(tempAuthor, other.author);

        free();

        this->name = tempName;
        this->author = tempAuthor;
        this->kg = other.kg;
        this->isbn = other.isbn;
    }
    
    return *this;
}

Book::~Book()
{
    free();
}

void Book::setName(const char *newName)
{
    if (!newName)
    {
        throw std::invalid_argument("Not a valid string to set as new name for the book");
    }
    
    char* tempName = new char[strlen(newName) + 1];
    if (!tempName)
    {
        throw std::bad_alloc();
    }
    strcpy(tempName, newName);
    delete[] this->name;

    this->name = tempName;
}

void Book::setAuthor(const char *newAuthor)
{
    if (!newAuthor)
    {
        throw std::invalid_argument("Not a valid string to set as new name for the book");
    }
    
    char* tempAuthor = new char[strlen(newAuthor) + 1];
    if (!tempAuthor)
    {
        throw std::bad_alloc();
    }
    strcpy(tempAuthor, newAuthor);
    delete[] this->author;

    this->author = tempAuthor;
}

void Book::free()
{
    delete[] this->name;
    delete[] this->author;
}
