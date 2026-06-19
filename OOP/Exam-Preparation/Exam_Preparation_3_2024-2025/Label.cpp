#include "Label.hpp"

Label::Label(const char *name, const char *helpMessage)
    : Control(name, helpMessage)
{}

void Label::print() const
{
    std::cout << "[Label] " << this->name << " : " << this->helpMessage << "\n";
}

const char *Label::settings()
{
    char* null = new char[1];
    null[0] = '\0';
    return null;
}

void Label::setName(const char *newName)
{
    throw std::invalid_argument("Cant modify the name");
}

void Label::setHelpMessage(const char *newHelpMessage)
{
    throw std::invalid_argument("Cant modify the helpMessage");
}
