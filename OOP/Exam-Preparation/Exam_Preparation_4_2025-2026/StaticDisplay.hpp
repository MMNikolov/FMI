#ifndef STATIC_DISPLAY_HPP
#define STATIC_DISPLAY_HPP

#include "Component.hpp"

class StaticDisplay : public Component
{
public:
    StaticDisplay(const char* tag, const char* location);
    //~StaticDisplay();

    //overriden methods
    void render(std::ostream& out) const override;
    void save(std::ofstream& out) const override;
    void load(std::ifstream& in) override;
    const char* status() const override;
    StaticDisplay* clone() const override;
    int getTypeID() const override { return 1; }

    //NO SETTERS
};

#endif // STATIC_DISPLAY_HPP