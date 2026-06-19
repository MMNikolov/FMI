#include "Control.hpp"

unsigned Control::GlobalId = 0;

Control::Control(const char *name, const char *helpMessage)
    : id(Incrementer()), enabled(false)
{
    // we check only for name, because it said that helpMessage can be empty
    if (!name)
    {
        throw std::invalid_argument("The name cannot be empty");
    }

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->helpMessage = new (std::nothrow) char[strlen(helpMessage) + 1];
    if (!this->helpMessage)
    {
        delete[] this->name;
        throw std::bad_alloc();
    }
    strcpy(this->helpMessage, helpMessage);
}

Control::Control(const Control &other)
    : id(other.id), enabled(other.enabled)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

    this->helpMessage = new (std::nothrow) char[strlen(other.helpMessage) + 1];
    if (!this->helpMessage)
    {
        delete[] this->name;
        throw std::bad_alloc();
    }
    strcpy(this->helpMessage, other.helpMessage);
}

Control &Control::operator=(const Control &other)
{
    unsigned CurrentId = GlobalId;
    if (this != &other)
    {
        char *newName = new char[strlen(other.name) + 1];
        strcpy(newName, other.name);

        char *newHelpMessage = new (std::nothrow) char[strlen(other.helpMessage) + 1];
        if (!newHelpMessage)
        {
            delete[] newName;
            throw std::bad_alloc();
        }
        strcpy(newHelpMessage, other.helpMessage);

        free();

        this->name = newName;
        this->helpMessage = newHelpMessage;
        this->enabled = other.enabled;
    }

    return *this;
}

Control::~Control()
{
    free();
}

void Control::store(std::ofstream &file) const
{
    file.write(reinterpret_cast<const char *>(&id), sizeof(id));
    size_t namelen = strlen(this->name);
    file.write(reinterpret_cast<const char *>(&namelen), sizeof(namelen));
    file.write(this->name, namelen);

    size_t helpMessageLen = strlen(this->name);
    file.write(reinterpret_cast<const char *>(&helpMessageLen), sizeof(helpMessageLen));
    file.write(this->helpMessage, helpMessageLen);
    file.write(reinterpret_cast<const char *>(&this->enabled), sizeof(enabled));
}

void Control::load(std::ifstream &file)
{
    unsigned dummyId;
    file.read(reinterpret_cast<char *>(&dummyId), sizeof(dummyId));

    size_t nameLen;
    file.read(reinterpret_cast<char *>(&nameLen), sizeof(nameLen));
    char *newName = new char[nameLen + 1];
    file.read(newName, nameLen);
    newName[nameLen] = '\0';

    size_t newHelpLen;
    file.read(reinterpret_cast<char *>(&newHelpLen), sizeof(newHelpLen));
    char *newHelp = new char[newHelpLen + 1];
    file.read(newHelp, newHelpLen);
    newHelp[newHelpLen] = '\0';

    free();
    this->name = newName;
    this->helpMessage = newHelp;
    file.read(reinterpret_cast<char *>(&enabled), sizeof(enabled));
}

void Control::free()
{
    delete[] this->name;
    this->name = nullptr;
    delete[] this->helpMessage;
    this->helpMessage = nullptr;
}

void Control::setName(const char *newName)
{
    checkActive();
    if (!newName)
    {
        throw std::invalid_argument("It must have a name");
    }

    this->name = new char[strlen(newName) + 1];
    strcpy(this->name, newName);
}

void Control::setHelpMessage(const char *newHelpMessage)
{
    checkActive();

    this->helpMessage = new char[strlen(newHelpMessage) + 1];
    strcpy(this->helpMessage, newHelpMessage);
}

bool Control::setEnabled(bool newEnabled)
{
    this->enabled = newEnabled;
    return this->enabled;
}
