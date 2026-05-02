#include "MagicBook.hpp"

MagicBook::MagicBook()
    : pages(nullptr), pagesCnt(0)
{}

MagicBook::MagicBook(unsigned pagesCnt)
    : pages(nullptr)
{
    if (pagesCnt > 1000)
    {
        throw std::invalid_argument("Wtf is this heavy ahh book");
    }
    
    this->pagesCnt = pagesCnt;
}

MagicBook::MagicBook(const MagicBook &other)
{
    copyFrom(other);
}

MagicBook &MagicBook::operator=(const MagicBook &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    
    return *this;
}

MagicBook::~MagicBook()
{
    free();
}

void MagicBook::usePage(unsigned pageUsed)
{
    this->pages[pageUsed] = 0;
    this->pages[pageUsed] = this->pages[pagesCnt--];
}

void MagicBook::addPage()
{
    // TO DO
    // I DONT EVEN KNOW WHAT TO DO
    this->pages[pagesCnt] = 1;
}

void MagicBook::free()
{
    delete[] pages;
}

void MagicBook::copyFrom(const MagicBook& other)
{
    for (int i = 0; i < pagesCnt; i++)
    {
        this->pages[i] = other.pages[i];
    }
    
    this->pagesCnt = other.pagesCnt;
}
