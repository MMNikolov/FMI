#ifndef RADIO_BUTTON_HPP
#define RADIO_BUTTON_HPP

#include "Control.hpp"
#include "Label.hpp"

#define MAX_LABELS 16

class RadioButton : public Control
{
public:
    RadioButton(const char* name, const char* helpMessage);
    ~RadioButton();

    //overriden methods
    void print() const override;
    const char *settings() override;
    void store(std::ofstream& file) const override;
    void load(std::ifstream& file) override;

    //methods
    bool operator()(size_t currentIndex);
    void addLabel(size_t index);
    void removeLabel(size_t index);
    
    //getters
    Label GetLabel(int index) const { return *this->labels[index]; }
    size_t GetCount() const { return this->count; };
    size_t GetCurrentIdnex() const { return this->currentIndex; }

private:
    Label* labels[MAX_LABELS];
    size_t count;
    int currentIndex;

private: 
    void free();
};

#endif // RADIO_BUTTON_HPP