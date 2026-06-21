#include <iostream>
#include <fstream>
#include <cstdlib>
#include "AutomationSystem.hpp"
#include "AreaHub.hpp"
#include "ActionActuator.hpp"

// Global pointer to track the tracking file location
const char *g_fileTarget = nullptr;

// Action for the RUN actuator
void runAction(const char *tag, AreaHub *hub)
{
    if (!hub)
        return;

    const char *currentStatus = hub->status();
    std::cout << "\n=== Generated Telemetry Status ===\n"
              << currentStatus << "\n=================================\n";

    // Clean up dynamic status memory immediately
    delete[] currentStatus;
}

// Action for the STOP actuator
void stopAction(const char *tag, AreaHub *hub)
{
    if (!hub || !g_fileTarget)
        return;

    std::ofstream out(g_fileTarget, std::ios::binary);
    if (out)
    {
        hub->save(out);
        out.close();
        std::cout << "\nSystem state successfully saved to: " << g_fileTarget << "\n";
    }
    else
    {
        std::cerr << "\nCritical: Unable to open file for saving state.\n";
    }

    std::cout << "Exiting automation process safely.\n";
    std::exit(0);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <binary_file>\n";
        return 1;
    }

    g_fileTarget = argv[1];

    // Allocate the core hub inside a managed pointer wrapper
    AreaHub *mainHub = new AreaHub("MainHub", "Zone_Alpha", 100);
    mainHub->SetActive(true); // Must be active to load data or insert components

    std::ifstream in(g_fileTarget, std::ios::binary);
    if (in)
    {
        try
        {
            mainHub->load(in);
            in.close();
            std::cout << "Successfully recovered data from " << g_fileTarget << "\n";
        }
        catch (...)
        {
            std::cout << "Target file is unreadable or empty. Initializing baseline pool.\n";
        }
    }

    try
    {
        // Construct the forced operational actuators
        ActionActuator runActuator("RUN", "ControlRoom", runAction, mainHub);
        ActionActuator stopActuator("STOP", "ControlRoom", stopAction, mainHub);

        runActuator.SetActive(true);
        stopActuator.SetActive(true);

        // Inject components into the main system layout
        *mainHub + runActuator;
        *mainHub + stopActuator;

        // AutomationSystem assumes full tracking and lifecycle ownership of mainHub
        AutomationSystem automation(mainHub);

        std::cout << "\n--- Present Visual Matrix Layout ---\n";
        mainHub->render(std::cout);

        // Simulate external interactive triggers
        std::cout << "\n--- Triggering RUN Action ---";
        runActuator();

        std::cout << "\n--- Triggering STOP Action ---";
        stopActuator(); // Performs file operations and forces a clean exit
    }
    catch (const std::exception &e)
    {
        std::cerr << "Runtime failure: " << e.what() << "\n";
        delete mainHub;
        return 1;
    }

    return 0;
}