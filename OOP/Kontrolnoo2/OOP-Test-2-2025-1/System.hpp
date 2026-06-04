#pragma once

#include "SuperUser.hpp"

#define STARTING_SYSTEM_CAPACITY 4

class System
{
public:
    System(const char* name);

    System(const System& other);
    System& operator=(const System& other) = delete;

    ~System();

    //methods
    void operator+(const User& user);
    void AddAdmin(const Admin& admin);
    //we need to find a common ground in admin and user to delete without extra memory
    void operator-(const char* email);
    //the implementation of this is trivial
    //User* operator^(unsigned competence);
    //the implementations of these are trivial as well
    friend std::ostream& operator<<(std::ostream& out, const System& system);
    friend std::istream& operator>>(std::istream& in, System& system);

    //getters
    const char* GetName() const { return this->name; }
    bool GetHasSuperUser() const { return this->hasSuperUser; }

private:
    char* name;
    User** users;
    unsigned count;
    unsigned capacity;
    bool hasSuperUser;

    void copyFrom(const System& other);
    void free();
    bool UserExists(const char* email);
    void resize();
};

