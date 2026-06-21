#ifndef ACTION_ACTUATOR_HPP
#define ACTION_ACTUATOR_HPP

#include "Component.hpp"
#include "AreaHub.hpp"

class ActionActuator : public Component
{
public:
    ActionActuator(const char* tag, const char* location, void (*func)(const char*, AreaHub*), AreaHub* parent);
    ~ActionActuator() override = default;

    //overriden methods
    void render(std::ostream& out) const override;
    void save(std::ofstream& out) const override;
    void load(std::ifstream& in) override;
    const char* status() const override;
    ActionActuator* clone() const override;
    int getTypeID() const override { return 5; }

    //methods
    void operator()();

private:
    void (*func)(const char*, AreaHub*);
    AreaHub* parent;
};

#endif // ACTION_ACTUATOR_HPP