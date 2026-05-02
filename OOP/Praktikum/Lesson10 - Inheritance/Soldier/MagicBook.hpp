#include "Soldier.hpp"

class MagicBook
{
public:
    //default ctor
    MagicBook();

    //parametrized ctor
    MagicBook(unsigned pagesCnt);

    //copy ctor
    MagicBook(const MagicBook& other);
    MagicBook& operator=(const MagicBook& other);

    //destructor
    ~MagicBook();

    //methods
    void usePage(unsigned pageUsed);
    void addPage();

private:
    unsigned* pages;
    unsigned pagesCnt;

    void free();
    void copyFrom(const MagicBook& other);
};
