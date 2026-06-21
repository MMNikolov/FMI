#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>

class Component
{
public:
    Component(const char *tag, const char *location);

    Component(const Component &other);
    Component &operator=(const Component &other);

    virtual ~Component();

    // methods
    virtual void render(std::ostream &out) const = 0;
    virtual void save(std::ofstream &out) const = 0;
    virtual void load(std::ifstream &in) = 0;
    virtual const char *status() const = 0;
    virtual Component *clone() const = 0;

    virtual void SetActive(bool activeState) { this->active = activeState; }
    virtual int getTypeID() const = 0;

    // getters
    unsigned GetId() const { return this->id; }
    const char *GetTag() const { return this->tag; }
    const char *GetLocation() const { return this->location; }

protected:
    const unsigned id;
    char *tag;
    char *location;
    bool active;

    void IsActive() const
    {
        if (active == false)
        {
            throw std::invalid_argument("The component has to be active to perform this action");
        }
    };

    void saveBase(std::ofstream &out) const;
    void loadBase(std::ifstream &in);

private:
    static unsigned GlobalId;
    static unsigned Incrementer() { return ++GlobalId; };

    void free();
};

#endif // COMPONENT_HPP