#include "Person.hpp"

template<typename T>
inline Person<T>::Person()
    : name(nullptr), EGN(""), sponsor(nullptr)
{
    this->name = new char[1];
    this->name[0] = '\0';
}

template <typename T>
inline Person<T>::Person(const char *name, const char *EGN, T* sponsor)
{
    if (!name || !EGN || strlen(EGN) != MAX_EGN_LENGTH)
    {
        throw std::invalid_argument("Not valid input in Person");
    }
    
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    strcpy(this->EGN, EGN);
    this->sponsor = sponsor;
}

template <typename T>
inline Person<T>::Person(const Person &other)
{
    copyFrom(other);
}

template <typename T>
inline Person<T> &Person<T>::operator=(const Person &other)
{
    if (this != &other)
    {
        char* tempName = new char[strlen(other.name) + 1];
        strcpy(tempName, other.name);

        delete[] this->name;
        this->name = tempName;
        strcpy(this->EGN, other.EGN);
        this->sponsor = other.sponsor;
    }

    return *this;
}

template <typename T>
inline Person<T>::~Person()
{
    free();
}

template <typename T>
inline void Person<T>::copyFrom(const Person &other)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

    strcpy(this->EGN, other.EGN);
    this->sponsor = other.sponsor;
}

template <typename T>
inline void Person<T>::free()
{
    delete[] this->name;
    this->name = nullptr;
    this->sponsor = nullptr;
}
