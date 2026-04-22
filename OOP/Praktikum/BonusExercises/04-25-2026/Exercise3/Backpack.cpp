#include "Backpack.hpp"

//-------------------
// BOOK FUNCTIONALITY
//-------------------

void Book::free()
{
    delete[] title;
    title = nullptr;
    delete[] author;
    author = nullptr;
};

void Book::copyFrom(const Book &other)
{
    if ((!other.title || other.title == '\0') || (!other.author || other.author == '\0'))
    {
        throw std::invalid_argument("The title and the author must be valid");
    }

    this->title = new char[strlen(other.title) + 1];
    if (!this->title)
    {
        throw std::bad_alloc();
    }
    this->title = other.title;

    this->author = new char[strlen(other.author) + 1];
    if (!this->author)
    {
        delete[] this->title;
        throw std::bad_alloc();
    }
    this->author = other.author;

    this->kg = other.kg;
}

char *Book::createISBN()
{
    char *buffer = new char[18];
    if (!buffer)
    {
        throw std::bad_alloc();
    }

    buffer[0] = '9';
    buffer[1] = '7';
    buffer[2] = '8';
    buffer[3] = '-';
    // first number
    buffer[4] = rand() % 10;
    buffer[5] = '-';
    // second number
    for (int i = 6; i < 8; i++)
    {
        buffer[i] = rand() % 10;
    }
    buffer[8] = '-';
    for (int i = 9; i < 15; i++)
    {
        buffer[i] = rand() % 10;
    }
    buffer[15] = '-';
    buffer[16] = rand() % 10;
    buffer[17] = '\0';
    
    return buffer;
}

Book::Book()
    : title(nullptr), author(nullptr), kg(0.0)
{
}

Book::Book(const char *title, const char *author, double kg)
    : title(nullptr), author(nullptr), kg(0.0)
{
    // Lets say that there isnt a book that weight over 10k KG
    if (!title || title == '\0' || !author || author == '\0' || kg < 0.0 || kg > 10000.0)
    {
        throw std::invalid_argument("There is a problem with the input data for the book");
    }

    this->title = new char[strlen(title) + 1];
    if (!this->title)
    {
        std::bad_alloc();
    }
    strcpy(this->title, title);

    this->author = new char[strlen(author) + 1];
    if (!this->author)
    {
        delete[] this->title;
        throw std::bad_alloc();
    }
    strcpy(this->author, author);

    this->kg = kg;
};

Book::Book(const Book &other)
{
    copyFrom(other);
}

Book &Book::operator=(const Book &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }

    return *this;
}

Book::~Book()
{
    free();
}

double Book::getKg() const
{
    return kg;
};

char *Book::getAuthor() const
{
    return author;
};

char *Book::getTitle() const
{
    return title;
};

char Book::getISBN() const
{
    return 'a';
};

//----------------------
// BACKPACK FUNCTIONALITY
//----------------------

void Backpack::free()
{
    delete[] books;
    books = nullptr;
}

void Backpack::copyFrom(const Backpack &other)
{
    // lets say that such a backpack doesnt exist, that can hold this much weight
    if (other.capacity < 0.0 || other.capacity > 10000.0)
    {
        throw std::invalid_argument("Problem with the copying of backpacks");
    }

    for (int i = 0; i < booksCount; i++)
    {
        this->books[i] = other.books[i];
    }
    this->capacity = other.capacity;
}

Backpack::Backpack()
    : books(nullptr), capacity(0.0), booksCount(0)
{
}

Backpack::Backpack(double capacity)
    : books(nullptr), capacity(0.0), booksCount(0)
{
    if (capacity < 0.0 || capacity > 10000.0)
    {
        throw std::invalid_argument("Physically impossible to have such a backpack");
    }

    this->capacity = capacity;
    this->books = nullptr;
    this->booksCount = 0;
}

Backpack::Backpack(const Backpack &other)
{
    copyFrom(other);
}

Backpack &Backpack::operator=(const Backpack &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }

    return *this;
}

Backpack::~Backpack()
{
    free();
}

void Backpack::addBook(Book &book)
{
    int sum = 0;

    for (int i = 0; i < booksCount; i++)
    {
        sum += books[i].getKg();
    }

    if (sum + book.getKg() > capacity)
    {
        throw std::invalid_argument("Cant exceed the weight of the backpack");
    }

    this->books[booksCount++] = book;
};

void Backpack::removeBook(char ISBN[ISBN_LENGTH])
{
    for (int i = 0; i < booksCount; i++)
    {
        if (books[i].getISBN() == ISBN[0])
        {
            // TO DO: remove book
        }
    }

    throw std::invalid_argument("There a book with such ISBN");
}

void Backpack::writeInBinary(std::ostream &out) const
{
    for (int i = 0; i < booksCount; i++)
    {
        out.write(reinterpret_cast<const char *>(&books[i]), sizeof(books[i]));
    }
}

void Backpack::readInBinary(std::istream &in)
{
    for (int i = 0; i < booksCount; i++)
    {
        in.read(reinterpret_cast<char *>(&books[i]), sizeof(books[i]));
    }
}