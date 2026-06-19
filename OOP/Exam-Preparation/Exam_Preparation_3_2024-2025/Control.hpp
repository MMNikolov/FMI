#ifndef CONTROL_HPP
#define CONTROL_HPP

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstring>
#include <ios>

class Control
{
public:
    Control(const char *name, const char *helpMessage);

    Control(const Control &other);
    Control &operator=(const Control &other);

    virtual ~Control();

    // methods
    virtual void print() const = 0;
    virtual void store(std::ofstream& file) const;
    virtual void load(std::ifstream& file);
    virtual const char *settings() = 0;

    // setters
    virtual void setName(const char *newName);
    virtual void setHelpMessage(const char *newHelpMessage);
    bool setEnabled(bool newEnabled);

    //getters
    unsigned getId() const { return this->id; };
    const char* getName() const { return this->name; };
    const char* getHelpMessage() const { return this->helpMessage; };
    bool IsEdnabled() const { return this->enabled; };

protected:
    const unsigned id;
    char *name;
    char *helpMessage;
    bool enabled;

    void checkActive() const
    {
        if (!enabled)
        {
            throw std::invalid_argument("Control is disabled. Modification not allowed.");
        }
    }

private:
    static unsigned GlobalId;
    static unsigned Incrementer() { return ++GlobalId; };

    void free();
};

#endif // CONTROL_HPP
