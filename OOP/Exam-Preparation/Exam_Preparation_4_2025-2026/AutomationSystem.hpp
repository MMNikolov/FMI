#ifndef AUTOMATION_SYSTEM_HPP
#define AUTOMATION_SYSTEM_HPP

#include "AreaHub.hpp"

class AutomationSystem
{
public:
    AutomationSystem(AreaHub* mainhub);

    AutomationSystem(const AutomationSystem& other) = delete;
    AutomationSystem& operator=(const AutomationSystem& other) = delete;

    ~AutomationSystem();

    //getters
    AreaHub* GetAreaHub() const { return this->mainHub; }

private:
    AreaHub* mainHub;
};

#endif // AUTOMATION_SYSTEM_HPP