#include "ActionActuator.hpp"

ActionActuator::ActionActuator(const char *tag, const char *location, void (*func)(const char *, AreaHub *), AreaHub *parent)
    : Component(tag, location), func(func), parent(parent)
{
    if (!parent)
    {
        throw std::invalid_argument("There is no AreaHub where this resides");
    }
}

void ActionActuator::render(std::ostream &out) const
{
    out << "[ActionActuator] ID: " << id << ", Tag: " << tag
        << ", Location: " << location << ", Active: " << (active ? "Yes" : "No")
        << ", Action: " << (func ? "Assigned" : "None") << "\n";
}

void ActionActuator::save(std::ofstream &out) const
{
    Component::saveBase(out);
}

void ActionActuator::load(std::ifstream &in)
{
    Component::loadBase(in);
}

const char *ActionActuator::status() const
{
    const char *actionStatus = this->func ? " (has action)" : " (no action)";
    size_t len = strlen(this->tag) + strlen(actionStatus);

    char *result = new char[len + 1];
    strcpy(result, this->tag);
    strcat(result, actionStatus);

    return result;
}

ActionActuator *ActionActuator::clone() const
{
    return new ActionActuator(*this);
}

void ActionActuator::operator()()
{
    IsActive();
    if (this->func)
    {
        // Извикваме я директно
        this->func(this->tag, this->parent);
    }
}