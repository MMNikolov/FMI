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

// Cashier::Cashier(const Cashier &other)
// {
//     copyFrom(other);
// }

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

void Cashier::read(std::istream &in)
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

void Cashier::print(std::ostream &out) const
{
    out << "Cashier: " << name << " | Turnover: " << turnoverBGN << " BGN\n";
}

const char *Cashier::getName() const
{
    return name;
}

double Cashier::getTurnover() const
{
    return turnoverBGN;
}

// STORE IMPLEMENTATION

void Store::copyFrom(const Store &other)
{
    char *name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

    this->cashiersCount = other.cashiersCount;
    for (int i = 0; i < other.cashiersCount; i++)
    {
        this->cashiers[i] = other.cashiers[i];
    }
}

void Store::free()
{
    delete[] name;
    name = nullptr;
}

Store::Store() : name(nullptr), cashiersCount(0)
{
    name = new char[1];
    name[0] = '\0';
}

Store::Store(const char *name) : cashiersCount(0)
{
    if (!name)
    {
        throw std::invalid_argument("The store doesnt have a name");
    }

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
};

// Store::Store(const Store &other)
// {
//     copyFrom(other);
// };

Store &Store::operator=(const Store &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }

    return *this;
};

Store::~Store()
{
    free();
};

void Store::addCashiers(const Cashier &cashier)
{
    if (this->cashiersCount > MAX_CASHIERS_IN_STORE)
    {
        throw std::invalid_argument("Cant have more than 10 cashiers at a time");
    }

    cashiers[cashiersCount] = cashier;
    cashiersCount++;
}

void Store::read(std::istream &in)
{
    char buffer[100];
    std::cout << "Enter store name: ";
    in >> buffer;

    free();
    this->name = new char[strlen(buffer) + 1];
    strcpy(this->name, buffer);

    std::cout << "How many cashiers to add: ";
    short count;
    in >> count;

    if (count > MAX_CASHIERS_IN_STORE)
    {
        count = MAX_CASHIERS_IN_STORE;
    }

    cashiersCount = 0;
    for (short i = 0; i < count; i++)
    {
        Cashier temp;
        temp.read(in);
        addCashiers(temp);
    }
};

double Store::getTotalTurnover() const
{
    double sum = 0;
    for (unsigned short i = 0; i < this->cashiersCount; i++)
    {
        sum += cashiers[i].getTurnover();
    }
    return sum;
};

void Store::print(std::ostream &out) const
{
    out << "--- Store: " << name << " ---\n";
    for (unsigned short i = 0; i < cashiersCount; i++)
    {
        cashiers[i].print(out);
    }

    out << "Total Store Turnover: " << getTotalTurnover() << " BGN\n";
    out << "------------------------\n";
}

const Cashier *Store::findCashierByName(const char *searchName)
{
    if (!searchName || strlen(searchName) > MAX_SIZE_OF_NAME)
    {
        throw std::invalid_argument("Invalid input name in findCashierName functionality");
    }

    for (unsigned short i = 0; i < cashiersCount; i++)
    {
        if (strcmp(this->cashiers[i].getName(), searchName) == 0)
        {
            return &cashiers[i];
        }
    }

    return nullptr;
};

// пита се за среден оборот на каса
int Store::equals(const Store &other) const
{
    double thisAverage = 0; double otherAverage = 0;
    if (this->cashiersCount == 0)
    {
        thisAverage = 0;
    }
    else
    {
        thisAverage = this->getTotalTurnover() / this->cashiersCount;
    }

    if (other.cashiersCount == 0)
    {
        otherAverage = 0;
    }
    else
    {
        otherAverage = other.getTotalTurnover() / other.cashiersCount;
    }

    if (thisAverage > otherAverage)
    {
        return 1;
    }
    else if (otherAverage > thisAverage)
    {
        return -1;
    }
    else
    {
        return 0;
    }
};