#ifndef LABEL_HPP
#define LABEL_HPP

#include "Control.hpp"

class Label : public Control
{
public:
    Label(const char* name, const char* helpMessage);

    //overriden methods
    void print() const override;
    const char *settings() override;
    void setName(const char *newName) override;
    void setHelpMessage(const char *newHelpMessage) override;
};

#endif // LABEL_HPP
