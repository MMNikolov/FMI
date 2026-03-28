#include "tree.hpp"

tree::tree(const char *name, unsigned height, unsigned age, bool isEndangered, unsigned yearsLeft)
: name(nullptr), height(0), age(0), isEndangered(false), yearsLeft(0), isValid(true)
{
    if (height <= 0 || age < 0 || yearsLeft < 0)
    {
        std::cerr << "A tree cant have these values";
        return;
    }

    if (!SetString(this->name, name))
    {
        isValid = false;
        freeMemory();
        return;
    }
    
    this->age = age;
    this->height = height;
    this->isEndangered = isEndangered;
    this->yearsLeft = yearsLeft;
    this->isValid = true;
}

tree::tree()
: name(nullptr), height(0), age(0), isEndangered(false), yearsLeft(0), isValid(true)
{
    SetString(this->name, "Unknown");
}

void tree::printCharacteristics()
{
    std::cout << std::boolalpha;
    std::cout << "The Name of the tree: " << this->name << '\n'
              << "The age of the tree: " << this->age << '\n'
              << "The height of the tree: " << this->height << '\n'
              << "Is the tree endangered: " << this->isEndangered << '\n'
              << "The remaining life of the tree: " << this->yearsLeft << '\n';
}

bool tree::SetString(char*& where, const char* what)
{
    if (!what || *what == '\0')
    {   
        std::cerr << "There was an error with the memory allocation in ";
        return false;
    }
    
    char* temp = new (std::nothrow) char[strlen(what) + 1];
    if (!temp)
    {
        std::cerr << "There was a problem with the memory allocation in tree constructor";
        freeMemory();
        return false;
    }
    
    strcpy(temp, what);

    delete[] where;
    where = temp;

    return true;
};

void tree::freeMemory()
{
    delete[] name;
};

void tree::readFile(std::ifstream& is)
{
    is >> std::boolalpha;
    is >> std::ws;

    char tempBuffer[BUFFER_SIZE];
    unsigned int tHeight, tAge, tYEars;
    bool tEndangered;

    if (!(is.getline(tempBuffer, 1024, ',')))
    {
        return;
    }
    
    if (!(is >> tHeight >> tAge >> tEndangered >> tYEars))
    {
        std::cerr << "There was a problem with the file management in readFile function";
        is.clear();
        return;
    }
 
    if (SetString(this->name, tempBuffer))
    {
        this->height = tHeight;
        this->age = tAge;
        this->isEndangered = tEndangered;
        this->yearsLeft = tYEars;
        this->isValid = true;
    }
    
}