#include "System.hpp"

System::System(const char *name)
{
    if (!name)
    {
        throw std::invalid_argument("Invlaid inout in the system");
    }

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->users = new User *[this->capacity];
}

System::System(const System &other)
{
    copyFrom(other);
}

System::~System()
{
    free();
}

void System::operator+(const User &user)
{
    if (UserExists(user.GetEmail()))
    {
        return;
    }

    // Ask gemini why doesnt this work when the data we provide is "const" User& user
    this->users[this->count++] = user.clone();
}

void System::AddAdmin(const Admin &admin)
{
    if (UserExists(admin.GetEmail()))
    {
        return;
    }

    if (this->count >= this->capacity)
    {
        resize();
    }

    this->users[count++] = admin.clone();
}

void System::operator-(const char *email)
{
    if (!email)
    {
        std::cout << "Invalid input in deleting a User\n";
        return;
    }
    
    for (unsigned i = 0; i < this->count; i++)
    {
        if (strcmp(this->users[i]->GetEmail(), email) == 0)
        {
            delete this->users[i];

            // O(1) премахване: Заменяме изтрития елемент с последния
            this->users[i] = this->users[this->count - 1];
            this->users[this->count - 1] = nullptr;
            this->count--;
            return;
        }
    }
}

void System::copyFrom(const System &other)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

    this->count = other.count;
    this->capacity = other.capacity;
    this->users = new User *[this->capacity];

    for (unsigned i = 0; i < this->count; i++)
    {
        this->users[i] = other.users[i]->clone();
    }
}

void System::free()
{
    delete[] this->name;
    this->name = nullptr;

    for (unsigned i = 0; i < count; i++)
    {
        delete this->users[i];
    }

    delete[] this->users;
}

bool System::UserExists(const char *email)
{
    // if we want to optimize this system we would have ordered them lexicographique
    // and then search for the person letter by letter. This helps with time complexity if the system becomes to big
    for (unsigned i = 0; i < this->count; i++)
    {
        if (strcmp(this->users[i]->GetEmail(), email) == 0)
        {
            std::cout << "There is already a user with this email\n";
            return true;
        }
    }

    return false;
}

void System::resize()
{
    this->capacity *= 2;
    User **temp = new User *[this->capacity];

    for (unsigned i = 0; i < this->count; ++i)
    {
        temp[i] = this->users[i];
    }

    delete[] this->users;
    this->users = temp;
}

//trivial its just hard work with no reap in benefits
std::ostream &operator<<(std::ostream &out, const System &system)
{
    return out;
}

std::istream &operator>>(std::istream &in, System &system)
{
    return in;
}
