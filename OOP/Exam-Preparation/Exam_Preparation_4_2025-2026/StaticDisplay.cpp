#include "StaticDisplay.hpp"

StaticDisplay::StaticDisplay(const char *tag, const char *location)
    : Component(tag, location)
{}

void StaticDisplay::render(std::ostream &out) const
{
    out << "[StaticDisplay] ID: " << id 
        << ", Tag: " << tag 
        << ", Location: " << location 
        << ", Active: " << (active ? "Yes" : "No") << "\n";
}

void StaticDisplay::save(std::ofstream &out) const
{
    Component::saveBase(out);
}

void StaticDisplay::load(std::ifstream &in)
{
    Component::loadBase(in);
}

const char *StaticDisplay::status() const
{
    char* emptyStr = new char[1];
    emptyStr[0] = '\0';
    return emptyStr;
}

StaticDisplay *StaticDisplay::clone() const
{
    return new StaticDisplay(*this);
}
