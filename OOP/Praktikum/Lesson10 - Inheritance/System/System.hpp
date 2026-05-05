#pragma once

#include "SuperUser.hpp"

class System
{
public:
    System(const char* name);
    System(const System& other) = delete;
    System& operator=(const System& other) = delete;
    ~System();

    //methods
    void addAdministrator(const Administrator& admin);
    void removeAdministrator(Administrator& admin);
    void removeUser(User& user);
    Administrator& operator^(unsigned number);

    //friend
    friend std::ostream& operator<<(std::ostream& out, const System& system);
    friend std::istream& operator>>(std::istream& in, System& system);

private:
    char* name;
    User** users;
    unsigned usersCount;
    Administrator** administrators;
    unsigned administratorsCount;
    bool hasSuperUser;
    SuperUser superUser;
};

void operator+(System& system, const User& user);
std::ostream& operator<<(std::ostream& out, const System& system);
std::istream& operator>>(std::istream& in, System& system);

