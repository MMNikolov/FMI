#pragma once

#include <cstring>
#include <stdexcept>

template<typename T>
class Person
{
public:
    static constexpr size_t MAX_EGN_LENGTH = 10;

    Person();
    Person(const char* name, const char* EGN, T* sponsor = nullptr);
    Person(const Person& other);
    Person& operator=(const Person& other);
    ~Person();

protected:
    char* name;
    char EGN[MAX_EGN_LENGTH + 1];
    T* sponsor;

private: 
    void copyFrom(const Person& other);
    void free();
};


#include "Person.inl"