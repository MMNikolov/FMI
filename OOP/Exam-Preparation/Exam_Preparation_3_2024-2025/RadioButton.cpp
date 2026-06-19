#include "RadioButton.hpp"

RadioButton::RadioButton(const char *name, const char *helpMessage)
    : Control(name, helpMessage), count(0), labels(), currentIndex(-1)
{}

RadioButton::~RadioButton()
{
    free();
}

void RadioButton::print() const
{
}

void RadioButton::free()
{
    for (size_t i = 0; i < count; i++)
    {
        delete this->labels[i];
    }
}
