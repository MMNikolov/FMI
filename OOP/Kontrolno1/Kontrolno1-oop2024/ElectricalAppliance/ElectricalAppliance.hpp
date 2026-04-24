#pragma once

#include <iostream>
#include <cstring>
#include <stdexcept>
#include <fstream>

class PowerStrip;

class ElectricalAppliance
{
public:
    // default constructor
    ElectricalAppliance();

    // ordinary constructor
    ElectricalAppliance(const char *description, const char *model, double powerInAmps);

    // copy constructor
    ElectricalAppliance(const ElectricalAppliance &other);
    ElectricalAppliance &operator=(const ElectricalAppliance &other);

    // destructor
    ~ElectricalAppliance();

    // functionalities
    void writeInTxt(std::ostream& out) const;
    void readInTxt(std::istream& in);
    void changeDescriptionAndModel(const char *newDesc, const char *newModel);
    // Only when its plugged in
    void changePower(double newPower);
    // when the electrical appliance is plugged off, its turned off
    void changeState();
    // You can change turn on and off feature only when its plugged in
    void changeActivity();
    void setPluggedIn(bool state);

    // getters
    const char *getDescription() const;
    const char *getModel() const;
    double getPowerInAmpers() const;
    bool getPluggedIn() const;
    bool getTurnedOn() const;
    unsigned int getId() const;

private:
    char *description;
    char *model;
    double powerInAmpers;
    bool pluggedIn;
    PowerStrip *powerStrip;
    bool turnedOn;
    unsigned int id;
    static unsigned int globalIdCounter;

private:
    void free();
    void copyFrom(const ElectricalAppliance &other);
};

class PowerStrip
{
public:
    // default constructor
    PowerStrip();

    // ordinary constructor
    PowerStrip(short inputs, double maxPowerOutput);

    // copy constructor
    PowerStrip(const PowerStrip &other);
    PowerStrip &operator=(const PowerStrip &other);

    // destructor
    ~PowerStrip();

    // functionalities
    void writeInTerminal(std::ostream& out) const;

    void plugInAppliance(ElectricalAppliance* appliance);
    void plugOffAppliance(const ElectricalAppliance* appliance);

    bool HasPowerStripReachMax();

    // getters
    unsigned short getInputs() const;
    unsigned short getOccupiedInputs() const;
    double getMaxPowerOutput() const;
    bool isBurnedOut() const;

private:
    unsigned short inputs;
    unsigned short occupiedInouts;
    double maxPowerOutput;
    bool burnedOut;
    ElectricalAppliance **appliances;

private:
    void free();
    void copyFrom(const PowerStrip &other);
};
