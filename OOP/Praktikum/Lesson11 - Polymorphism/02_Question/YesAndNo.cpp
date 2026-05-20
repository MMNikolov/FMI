#include "YesAndNo.hpp"

YesAndNo::YesAndNo()
    : Question(), isRight(false)
{}

YesAndNo::YesAndNo(const char *description, unsigned points, bool isRight)
    : Question(description, points), isRight(isRight)
{}

void YesAndNo::ask() const
{
    std::cout << "(Points: " << this->points  << ") Question: " << this->description << '\n';
}

unsigned YesAndNo::grade() const
{
    return this->points;
}
