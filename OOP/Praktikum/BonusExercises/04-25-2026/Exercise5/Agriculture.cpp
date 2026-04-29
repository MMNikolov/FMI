#include "Agriculture.hpp"

Produce::Produce()
    : name(nullptr), products(nullptr)
{
}

Produce::Produce(const char *name, const char *products)
{
    if (!name || !products)
    {
        throw std::invalid_argument("Invalid input");
    }

    this->name = new char[strlen(name) + 1];
    if (!this->name)
    {
        throw std::bad_alloc();
    }
    strcpy(this->name, name);

    this->products = new char[strlen(products) + 1];
    if (!this->products)
    {
        delete[] this->name;
        throw std::bad_alloc();
    }
    strcpy(this->products, products);
}

Produce::Produce(const Produce &other)
{
    copyFrom(other);
}

Produce &Produce::operator=(const Produce &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }

    return *this;
}

Produce::~Produce()
{
    free();
}

const char *Produce::searchInProducts(const char *product)
{
    char *buffer = new char[strlen(this->products) + 1];
    if (!buffer)
    {
        throw std::bad_alloc();
    }

    int size = strlen(this->products);

    int index;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            // TODO
        }
    }

    return buffer;
}

void Produce::free()
{
    delete[] this->name;
    this->name = nullptr;
    delete[] this->products;
    this->products = nullptr;
}

void Produce::copyFrom(const Produce &other)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

    try
    {
        this->products = new char[strlen(other.products) + 1];
    }
    catch (const std::bad_alloc &e)
    {
        delete[] this->name;
        throw e;
    }

    strcpy(this->products, other.products);
}

//------------------------------
// Plant implementation
//------------------------------

Plant::Plant()
    : id(globalId++), name(nullptr), column(0), row(0), price(0.0), produce(nullptr)
{}

Plant::Plant(const char *name, double price)
    : id(globalId++), name(nullptr), column(0), row(0), price(0.0), produce(nullptr)
{
    if (!name || price < 0.0)
    {
        throw std::invalid_argument("Invalid inputs");
    }

    this->name = new char[strlen(name) + 1];
    if (!this->name)
    {
        throw std::bad_alloc();
    }
    strcpy(this->name, name);

    this->price = price;
}

Plant::~Plant()
{
    free();
}

const char *Plant::getName() const {
    return this->name;
};

unsigned Plant::getColumn() const
{
    return this->column;
};

unsigned Plant::getRow() const
{
    return this->row;
};

double Plant::getPrice() const
{
    return this->price;
};

void Plant::free() 
{
    delete[] this->name; this->name = nullptr;
    delete[] this->produce; this->produce = nullptr;
};

unsigned Plant::globalId = 1;

// ------------------------------
// Field functionality
// ------------------------------

Field::Field(int width, int height)
{
    if (width < 0 || height < 0)
    {
        throw std::invalid_argument("Invalid input");
    }
    
    this->width = width;
    this->height = height;
}

Field::~Field()
{
    this->plants = nullptr;
}

void Field::resize(int newWidth, int newHeight)
{
    if (newWidth < 0 || newHeight < 0)
    {
        throw std::invalid_argument("Invalid input");
    }
    
    this->width = width;
    this->height = height;
}
