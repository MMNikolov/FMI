#include "Nvector.hpp"

void Nvector::free()
{
    delete[] data;
    data = nullptr;
    size = 0;
}

void Nvector::copyFrom(const Nvector &other)
{
    if (this->size != other.size)
    {
        throw std::invalid_argument("Cant copy different dimensional vectors");
    }

    this->size = other.size;

    for (int i = 0; i < size; i++)
    {
        this->data[i] = other.data[i];
    }
}

Nvector::Nvector()
    : data(nullptr), size(0)
{
    this->data = new int[1];
    this->data[0] = 0;
    this->size = 0;
}

Nvector::Nvector(int *data, size_t size)
    : data(nullptr), size(0)
{
    if (size < 1)
    {
        throw std::invalid_argument("Cant have less than one dimensional vector");
    }

    this->data = new int[size];
    this->data = data;
    this->size = size;
};

Nvector::Nvector(const Nvector &other)
{
    copyFrom(other);
}

Nvector &Nvector::operator=(const Nvector &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }

    return *this;
}

Nvector::~Nvector()
{
    free();
}

int &Nvector::operator[](size_t index)
{
    return this->data[index];
}

Nvector &Nvector::operator*=(size_t scalar)
{
    for (int i = 0; i < this->size; i++)
    {
        this->data[i] *= scalar;
    }
}

Nvector &Nvector::operator/=(size_t scalar)
{
    if (scalar == 0)
    {
        throw std::invalid_argument("You cant be this dumb");
    }

    for (int i = 0; i < this->size; i++)
    {
        this->data[i] /= scalar;
    }
};

Nvector &Nvector::operator-=(const Nvector &other)
{
    if (this->size != other.size)
    {
        throw std::invalid_argument("Vectors are not the same size");
    }

    for (int i = 0; i < size; i++)
    {
        this->data[i] -= other.data[i];
    }
};

Nvector &Nvector::operator+=(const Nvector &other)
{
    if (this->size != other.size)
    {
        throw std::invalid_argument("Vectors are not the same size");
    }

    for (int i = 0; i < size; i++)
    {
        this->data[i] += other.data[i];
    }
};

std::ostream &operator<<(std::ostream &out, const Nvector &vec)
{
    out << "( " << vec.data[0];

    for (size_t i = 1; i < vec.size; i++)
    {
        out << ", " << vec.data[i];
    }

    out << ")";
}

size_t Nvector::GetSize() const 
{
    return this->size;
}

Nvector operator+(const Nvector& one, const Nvector& two)
{
    if (one.GetSize() != two.GetSize())
    {
        throw std::invalid_argument("The vectors have to be the same size to performs this operation");
    }
    
    Nvector result;
    result += one;
    result += two;

    return result;
};
Nvector operator-(const Nvector& one, const Nvector& two)
{
    if (one.GetSize() != two.GetSize())
    {
        throw std::invalid_argument("The vectors have to be the same size to performs this operation");
    }
    
    Nvector result;
    result -= one;
    result -= two;
    
    return result;
};
