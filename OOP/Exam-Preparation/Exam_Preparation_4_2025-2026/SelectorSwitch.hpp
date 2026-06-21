#ifndef SELECTOR_SWITCH_HPP
#define SELECTOR_SWITCH_HPP

#include "Component.hpp"
#include "StaticDisplay.hpp"
#define MAX_DISPLAYS 12

class SelectorSwitch : public Component
{
public:
    SelectorSwitch(const char* tag, const char* location);

    SelectorSwitch(const SelectorSwitch& other);
    SelectorSwitch& operator=(const SelectorSwitch& other);

    ~SelectorSwitch();

    //overriden methods
    void render(std::ostream& out) const override;
    void save(std::ofstream& out) const override;
    void load(std::ifstream& in) override;
    const char* status() const override;
    SelectorSwitch* clone() const override { return new SelectorSwitch(*this); }
    int getTypeID() const override { return 3; }

    //methods
    bool operator()(unsigned id);
    void addDisplay(const StaticDisplay& display);
    void removeDisplay(unsigned id);
    StaticDisplay& operator[](size_t index);
    
    //getters
    size_t GetCurrentIndex() const { return this->currentIndex; }
    size_t GetCount() const { return this->count; }

private:
    StaticDisplay** displays;
    size_t count;
    int currentIndex;

private:
    void free();
};

#endif // SELECTOR_SWITCH_HPP