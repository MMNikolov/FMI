#pragma once

#include <iostream>
#include <cstring>
#include <fstream>
#include <stdexcept>

class User
{
public:
    User(const char* email, const char* password);

    User(const User& other);
    User& operator=(const User& other);

    virtual ~User();

    //virtual methods
    virtual User* clone() const;

    //methods
    friend std::ostream& operator<<(std::ostream& out, const User& user);
    friend std::istream& operator>>(std::istream& in, User& user);

    //getters
    const char* GetEmail() const { return this->email; }
    const char* GetPassword() const { return this->password; }

protected:
    char* email;
    char* password;

private:
    void free();
    void copyFrom(const User& other);
};

bool IsValidEmail(const char* email);
bool IsValidPassword(const char* password);
bool operator==(const User& one, const User& two);