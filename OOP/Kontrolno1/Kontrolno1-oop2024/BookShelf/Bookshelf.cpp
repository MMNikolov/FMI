#include "Bookshelf.hpp"

Book::Book()
    : title(nullptr), author(nullptr), pages(0), Id("something") // TODO
{
    this->title = new char[1];
    this->title = '\0';

    this->author = new char[1];
    this->author = '\0';

    IncrementId();
}

void Book::free()
{
    delete[] this->title;
    this->title = nullptr;
    delete[] this->author;
    this->author = nullptr;
}

void Book::copyFrom(const Book &other)
{
    this->title = new char[strlen(other.title) + 1];
    if (!this->title)
    {
        throw std::bad_alloc();
    }
    strcpy(this->title, other.title);

    this->author = new char[strlen(other.author) + 1];
    if (!this->author)
    {
        delete[] this->title;
        throw std::bad_alloc();
    }
    strcpy(this->author, other.author);

    this->pages = other.pages;
    // TODO
    // this->Id = other.Id;
};

Book::Book(const char *title, const char *author, unsigned short pages)
    : title(nullptr), author(nullptr), pages(0), Id("something") // TODO
{
    if (!title || !author || pages > 65000)
    {
        throw std::invalid_argument("The was a problem with the initialization of the constructor");
    }

    this->title = new char[strlen(title) + 1];
    if (!this->title)
    {
        throw std::bad_alloc();
    }
    strcpy(this->title, title);

    this->author = new char[strlen(author) + 1];
    if (!this->author)
    {
        delete[] title;
        throw std::bad_alloc();
    }
    strcpy(this->author, author);

    this->pages = pages;
    // TODO (Id)

    IncrementId();
}

char *Book::createId()
{
    char buffer[ID_MAX_SIZE];
    strcat(buffer, "IS-INF-");

    // TODO
}

void Book::IncrementId()
{
    GlobalId++;
}

Book::Book(const Book &other)
{
    copyFrom(other);
};

Book &Book::operator=(const Book &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }

    return *this;
};

Book::~Book()
{
    free();
}

void Book::writeInTxt(std::ostream &out) const
{
    if (!out)
    {
        throw std::invalid_argument("Invalid");
    }

    out << "Title: " << this->title << '\n'
        << "Author: " << this->author << '\n'
        << "Pages: " << this->pages << '\n'
        << "Id: " << this->Id << '\n';
}

void Book::readFromTxt(std::istream &in)
{
    char buffer[BUFFER_SIZE];

    // TO DO
}

void Book::changeTitleAndAuthor(const char *newTitle, const char *newAuthor)
{
    if (!newTitle || !newAuthor)
    {
        throw std::invalid_argument("Innvalid in changeTitleAndAuhtor");
    }

    char *tempTitle = new char[strlen(newTitle) + 1];
    if (!tempTitle)
    {
        throw std::bad_alloc();
    }
    strcpy(tempTitle, newTitle);

    char *tempAuthor = new char[strlen(newAuthor) + 1];
    if (!tempAuthor)
    {
        delete[] tempTitle;
        throw std::bad_alloc();
    }
    strcpy(tempAuthor, newAuthor);

    free();

    this->title = tempTitle;
    this->author = tempAuthor;
}

const char *Book::getTitle() const 
{
    return this->title;
};
const char *Book::getAuthor() const
{
    return this->author;
};
unsigned short Book::getPages() const
{
    return this->pages;
};
const char *Book::getId() const
{
    return this->Id;
};

//--------------------------
// BOOKSHELF IMPLEMENTATION
//--------------------------

Bookshelf::Bookshelf()
    : rafts(0), maxPagesOnRaft(0), booksInTheBookshelf(0), books(nullptr)
{}

Bookshelf::Bookshelf(unsigned short rafts, unsigned short maxPagesOnRaft)
    : rafts(0), maxPagesOnRaft(0), booksInTheBookshelf(0), books(nullptr)
{
    if (rafts > 65000 || maxPagesOnRaft > 65000)
    {
        throw std::invalid_argument("Invalid ordinary constructor for the bookshelf");
    }
    
    this->rafts = rafts;
    this->maxPagesOnRaft = maxPagesOnRaft;
    this->booksInTheBookshelf = 0;
    this->books = new Book*[MAX_BOOKS];
}

Bookshelf::~Bookshelf()
{
    free();
}

void Bookshelf::AddBook(const Book *book)
{
    for (int i = 0; i < booksInTheBookshelf; i++)
    {
        if (strcmp(this->books[i]->getTitle(), book->getTitle()) == 0)
        {
            throw std::invalid_argument("You cant add the same book on the bookshelf");
        }
    }
    
    if (book->getPages() > this->maxPagesOnRaft)
    {
        throw std::invalid_argument("You cant have such a big book on this raft");
    }
}

void Bookshelf::RemoveBook(const Book *book)
{
}

Book &Bookshelf::searchBookByTitle(const char *title)
{
    for (int i = 0; i < booksInTheBookshelf; i++)
    {
        if (strcmp(this->books[i]->getTitle(), title) == 0)
        {
            return *this->books[i];
        }
    }
    
    std::cout << "No such book with this title in the bookshelf";
    throw std::invalid_argument("No such book with this title in the bookshelf");
}

void Bookshelf::resizeRaft(unsigned short newMaxPagesOnRaft)
{
    this->maxPagesOnRaft = newMaxPagesOnRaft;

    //Didnt understand what the next part is trying to say
}

unsigned short Bookshelf::getRafts()
{
    return this->rafts;
}

unsigned short Bookshelf::getMaxPagesOnRaft()
{
    return this->maxPagesOnRaft;
}

unsigned short Bookshelf::getBooksInTheBookshelf()
{
    return this->booksInTheBookshelf;
}

void Bookshelf::free()
{   
    delete[] this->books; this->books = nullptr;
}
