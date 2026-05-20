#include "Question.hpp"

Question::Question()
    : points(0)
{
    this->description = new char[1];
    this->description[0] = '\0';
}

Question::Question(const char *description, unsigned points)
    : points(points)
{
    if (!description)
    {
        throw std::invalid_argument("Invalid input in Question class");
    }
    
    this->description = new char[strlen(description) + 1];
    strcpy(this->description, description);
}

Question::Question(const Question &other)
{
    copyFrom(other);
}

Question &Question::operator=(const Question &other)
{
    if (this != &other)
    {
        char* tempDesc = new char[strlen(other.description) + 1];
        strcpy(tempDesc, other.description);

        free();
        strcpy(this->description, tempDesc);
    }

    return *this;    
}

Question::~Question()
{
    free();
}

void Question::free()
{
    delete[] this->description;
}

void Question::copyFrom(const Question &other)
{
    this->description = new char[strlen(other.description) + 1];
    strcpy(this->description, other.description);

    this->points = other.points;
}
