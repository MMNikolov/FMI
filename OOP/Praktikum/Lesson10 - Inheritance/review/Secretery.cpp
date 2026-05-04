#include "Secretery.hpp"

Secretery::Secretery()
    : Specialist(), languages(nullptr)
{
    this->languages = new char[1];
    this->languages[0] = '\0';
}

Secretery::Secretery(const char *name, const char *address, long EGN, const char *department, double salary, const char *description, const char* languages)
    : Specialist(name, address, EGN, department, salary, description)
{
    if (!languages)
    {
        throw std::invalid_argument("Invlaid input in the secretary class");
    }

    this->languages = new char[strlen(languages) + 1];
    strcpy(this->languages, languages);
}

Secretery::Secretery(const Secretery &other)
    : Specialist(other)
{
    this->languages = new char[strlen(other.languages) + 1];
    strcpy(this->languages, other.languages);
}

Secretery &Secretery::operator=(const Secretery &other)
{
    if (this != &other)
    {
        Specialist::operator=(other);
        free(); // Пак гаранцията!

        this->languages = new char[strlen(other.languages) + 1];
        strcpy(this->languages, other.languages);
    }
    
    return *this;
}

Secretery::~Secretery()
{
    free();
}

void Secretery::free()
{
    delete[] languages;
}
