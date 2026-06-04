#include "SuperUser.hpp"

SuperUser::SuperUser(const char *email, const char *password, int yearsInPosition, int competence)
    : Admin(email, password, yearsInPosition, competence), count(0), capacity(STARTING_USERS_CONTAINER)
{
    this->users = new User*[STARTING_USERS_CONTAINER];
}

SuperUser::~SuperUser()
{
    free();
}

void SuperUser::operator()(const char *email, const char *password)
{
    if (!IsValidEmail(email) || !IsValidPassword(password))
    {
        throw std::invalid_argument("Not Valid input in the SuperUser, for creating users");
    }

    if (this->count >= this->capacity)
    {
        // TO DO: if time
        resize();
    }
    
    User* user = new User(email, password);
    this->users[count++] = user;
}

bool SuperUser::operator[](const char *email)
{
    for (unsigned i = 0; i < count; i++)
    {
        if (strcmp(this->users[i]->GetEmail(), email) == 0)
        {
            return true;
        }
    }
    
    return false;
}

void SuperUser::resize()
{
    this->capacity *= 2;
    User** newUsers = new User*[this->capacity];

    for (unsigned i = 0; i < this->capacity; i++)
    {
        newUsers[i] = this->users[i];
    }
    
    free();
    this->users = newUsers;
}

void SuperUser::free()
{
    for (unsigned i = 0; i < this->count; i++)
    {
        delete[] this->users[i];
    }
    
    delete this->users;
}

std::ostream &operator<<(std::ostream &out, const SuperUser &user)
{
    out << user.email << ' ' << user.password << ' ' << user.yearsInPosition << ' ' << user.competence << '\n';
    out << "--------------Users created by the superUser--------------------\n";

    for (unsigned i = 0; i < user.GetUsersCount(); i++)
    {
        out << user.users[i]->GetEmail() << " " << user.users[i]->GetPassword() << '\n';
    }

    out << "----------------------------------------------------------------\n";
    
    return out;
}

std::istream &operator>>(std::istream &in, SuperUser &user)
{
    // TODO: insert return statement here
}
