#pragma once

#include <iostream>
#include <cstring>
#include <stdexcept>
#include <fstream>

class User
{
public:
    User();
    User(const char* email, const char* password);
    User(const User& other);
    User& operator=(const User& other);
    ~User();

    //getters
    const char* getEmail() const { return this->email; };
    const char* getPassword() const { return this->password; }

    //operators
    friend std::ostream& operator<<(std::ostream& out, User& user);
    friend std::istream& operator>>(std::istream& in, User& user);

private:
    char* email;
    char* password;
};

std::ostream& operator<<(std::ostream& out, User& user);
std::istream& operator>>(std::istream& in, User& user);
bool operator==(User& user1, User& user2);