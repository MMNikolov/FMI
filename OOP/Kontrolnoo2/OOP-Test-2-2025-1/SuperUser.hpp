#pragma once

#include "Admin.hpp"

#define STARTING_USERS_CONTAINER 4

class SuperUser : public Admin
{
public:
    SuperUser(const char* email, const char* password, int yearsInPosition, int competence);

    //no need for copy constructors, because there can only be one superUser
    //If I have time I want to learn the move semantics

    ~SuperUser();

    //methods
    void operator()(const char* email, const char* password);
    bool operator[](const char* email);
    friend std::ostream& operator<<(std::ostream& out, const SuperUser& user);
    friend std::istream& operator>>(std::istream& in, SuperUser& user);

    //overriden methods:
    //we dont even need the clone functionality:
    // FIRST: because we dont have a copy constructor either way
    // SECOND: because we just dont need two super users. The exercise says so
    //SuperUser* clone() override;

    //getters
    unsigned GetUsersCount() const { return this->count; };
    unsigned GetUsersCapacity() const { return this->capacity; };

private:
    User** users;
    unsigned count;
    unsigned capacity;

    void resize();
    void free();
};
