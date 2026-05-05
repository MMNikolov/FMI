#pragma once

#include "User.hpp"

class Administrator : public User
{
public:
    Administrator();
    Administrator(const char* email, const char* password, unsigned yearsUnderBelt, unsigned short competence);
    Administrator(const Administrator& other);
    Administrator& operator=(const Administrator& other);
    ~Administrator();

    //competence increase or decrease
    void operator++();
    void operator--();

    //friend functions (operators)
    friend std::ostream& operator<<(std::ostream& out, const Administrator& administrtor);
    friend std::istream& operator>>(std::istream& in, Administrator& administrtor);

private:
    unsigned yearsUnderBelt;
    unsigned short competence;
};

bool operator<(const Administrator& one, const Administrator& two);
bool operator>(const Administrator& one, const Administrator& two);
bool operator==(const Administrator& one, const Administrator& two);
std::ostream& operator<<(std::ostream& out, const Administrator& administrtor);
std::istream& operator>>(std::istream& in, Administrator& administrtor);