#include "AutomationSystem.hpp"

AutomationSystem::AutomationSystem(AreaHub *mainhub)
    : mainHub(mainHub)
{
    if (!mainHub)
    {
        throw std::invalid_argument("There is no mainhub to work with");
    }
}

AutomationSystem::~AutomationSystem()
{
    delete mainHub;
}
