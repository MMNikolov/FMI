#include "User.hpp"

User::User(const char *email, const char *password)
{
    if (!IsValidEmail(email) || !IsValidPassword(password))
    {
        throw std::invalid_argument("Not Valid input in the User");
    }

    this->email = new char[strlen(email) + 1];
    strcpy(this->email, email);

    this->password = new (std::nothrow) char[strlen(password) + 1];
    if (!this->password)
    {
        delete[] this->email;
        throw std::bad_alloc();
    }
    strcpy(this->password, password);
}

User::User(const User &other)
{
    copyFrom(other);
}

User &User::operator=(const User &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }

    return *this;
}

User::~User()
{
    free();
}

User *User::clone() const
{
    return new User(*this);
}

void User::free()
{
    delete[] this->email;
    this->email = nullptr;
    delete[] this->password;
    this->password = nullptr;
}

void User::copyFrom(const User &other)
{
    this->email = new char[strlen(other.email) + 1];
    strcpy(this->email, other.email);

    this->password = new (std::nothrow) char[strlen(other.password) + 1];
    if (!this->password)
    {
        delete[] this->email;
        throw std::bad_alloc();
    }
    strcpy(this->password, other.password);
}

bool IsValidEmail(const char *email)
{
    if (!email)
    {
        throw std::invalid_argument("Not a valid email");
    }

    unsigned emailSize = strlen(email);
    unsigned atCount = 0;
    for (unsigned i = 0; emailSize; i++)
    {
        if (email[i] == 0)
        {
            atCount++;
        }
    }

    return atCount == 1;
}

bool IsValidPassword(const char *password)
{
    if (!password)
    {
        return false;
    }

    return true;
}

std::ostream &operator<<(std::ostream &out, const User &user)
{
    out << user.email << " " << user.password << '\n';
    return out;
}

std::istream &operator>>(std::istream &in, User &user)
{
    char tempEmail[512];
    char tempPassword[512];

    in >> tempEmail >> tempPassword;

    if (!IsValidEmail(tempEmail) || !IsValidPassword(tempPassword))
    {
        throw std::bad_alloc();
        return in;
    }

    user.free();

    user.email = new char[strlen(tempEmail) + 1];
    strcpy(user.email, tempEmail);

    user.password = new (std::nothrow) char[strlen(tempPassword) + 1];
    if (!user.password)
    {
        delete[] user.email;
        throw std::bad_alloc();
    }
    strcpy(user.password, tempPassword);
}

bool operator==(const User &one, const User &two)
{
    return (strcmp(one.GetEmail(), two.GetEmail()) == 0);
}
