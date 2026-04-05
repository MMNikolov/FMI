#include "supermarket.hpp"

// CASHIER IMPLEMENTATION

void Cashier::copyFrom(const Cashier &other)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    this->turnoverBGN = other.turnoverBGN;
};

void Cashier::free()
{
    delete[] name;
    name = nullptr;
}

Cashier::Cashier()
    : name(nullptr), turnoverBGN(0.0)
{
    name = new char[1];
    name[0] = '\0';
}

Cashier::Cashier(const char *name, double turnoverBGN)
{
    if (!name || strlen(name) > MAX_SIZE_OF_NAME)
    {
        throw std::invalid_argument("Invalid name length");
    }

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->turnoverBGN = turnoverBGN;
}

Cashier::Cashier(const Cashier &other)
{
    copyFrom(other);
}

Cashier &Cashier::operator=(const Cashier &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }

    return *this;
}

Cashier::~Cashier()
{
    free();
}

void Cashier::read(std::istream& in)
{
    char buffer[MAX_SIZE_OF_NAME + 1];
    std::cout << "Enter cashier name (max 30 chars)";
    in >> buffer;

    std::cout << "Enter turnover (BGN): ";
    double turnover;
    in >> turnover;

    free();
    this->name = new char[strlen(buffer) + 1];
    strcpy(this->name, buffer);
    this->turnoverBGN = turnover;
};

void Cashier::print(std::ostream& out) const {
    out << "Cashier: " << name << " | Turnover: " << turnoverBGN << " BGN\n";
}