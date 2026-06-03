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

    //methods
    friend std::ofstream& operator<<(std::ofstream& out, const User& user);
    friend std::ifstream& operator>>(std::ifstream& in, User& user);

    //getters
    const char* GetEmail() const { return this->email; }
    const char* GetPassword() const { return this->password; }

protected:
    static const char* gloabalEmail;
    static const char* changeEmail();

    const char* email;
    char* password;

private:
    void free();
};

std::ofstream& operator<<(std::ofstream& out, const User& user);
std::ifstream& operator>>(std::ifstream& in, User& user);
bool operator==(const User& one, const User& two);