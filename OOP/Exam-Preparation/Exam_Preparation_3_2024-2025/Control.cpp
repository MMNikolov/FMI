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
    : id(other.id)
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

    this->enabled = other.enabled;
}

Control &Control::operator=(const Control &other)
{
    unsigned CurrentId = GlobalId;
    if (this != &other)
    {
        char* newName = new char[strlen(other.name) + 1];
        strcpy(newName, other.name);

        char* newHelpMessage = new (std::nothrow) char[strlen(other.helpMessage) + 1];
        if (!newHelpMessage)
        {
            delete[] newName;
            throw std::bad_alloc();
        }
        strcpy(newHelpMessage, other.helpMessage);

        free();

        this->name = new char[strlen(newName) + 1];
        strcpy(this->name, newName);

        this->helpMessage = new (std::nothrow) char[strlen(newHelpMessage) + 1];
        if (!this->helpMessage)
        {
            delete[] this->name;
            throw std::bad_alloc();
        }
        strcpy(this->helpMessage, newHelpMessage);
        this->enabled = other.enabled;

        //please Gemini tell me how to do the Id part here
    }
    
    return *this;
}

Control::~Control()
{
    free();
}

void Control::free()
{
    delete[] this->name;
    this->name = nullptr;
    delete[] this->helpMessage;
    this->helpMessage = nullptr;
}

const char *Control::setName(const char *newName)
{
    if (!newName)
    {
        throw std::invalid_argument("It must have a name");
    }
    
    this->name = new char[strlen(newName) + 1];
    strcpy(this->name, newName);
}

const char *Control::setHelpMessage(const char *newHelpMessage)
{
    //we dont need validations for this one
    this->helpMessage = new char[strlen(newHelpMessage) + 1];
    strcpy(this->helpMessage, newHelpMessage);
}

bool Control::setEnabled(bool newEnabled)
{
    this->enabled = newEnabled;
}
