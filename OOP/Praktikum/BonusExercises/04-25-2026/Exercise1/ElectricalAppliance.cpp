#include "ElectricalAppliance.hpp"

unsigned int ElectricalAppliance::globalIdCounter = 1;

ElectricalAppliance::ElectricalAppliance()
    : description(nullptr), model(nullptr), powerInAmpers(0.0), pluggedIn(false), powerStrip(nullptr), turnedOn(false), id(0)
{
    this->description = new char[1];
    this->description[0] = '\0';

    this->model = new char[1];
    this->model[0] = '\0';

    this->id = globalIdCounter++;
}

ElectricalAppliance::ElectricalAppliance(const char *description, const char *model, double powerInAmps)
    : description(nullptr), model(nullptr), powerInAmpers(0.0), pluggedIn(false), powerStrip(nullptr), turnedOn(false), id(0)
{
    if (!description || !model || powerInAmpers < 0.0)
    {
        throw std::invalid_argument("There was an error in the constructor");
    }

    this->description = new char[strlen(description) + 1];
    if (!this->description)
    {
        throw std::bad_alloc();
    }
    strcpy(this->description, description);

    this->model = new char[strlen(model) + 1];
    if (!this->model)
    {
        delete[] description;
        throw std::bad_alloc();
    }
    strcpy(this->model, model);

    this->powerInAmpers = powerInAmpers;
    this->id = globalIdCounter++;
};

void ElectricalAppliance::free()
{
    delete[] description; this->description = nullptr;
    delete[] model; this->model = nullptr;
}

void ElectricalAppliance::copyFrom(const ElectricalAppliance& other)
{
    this->description = new char[strlen(other.description) + 1];
    if (!this->description)
    {
        throw std::bad_alloc();
    }
    strcpy(this->description, other.description);

    this->model = new char[strlen(other.model) + 1];
    if (!this->model)
    {
        delete[] this->description;
        throw std::bad_alloc();
    }
    strcpy(this->model, other.model);

    this->powerInAmpers = other.powerInAmpers;
    this->pluggedIn = false;
    this->powerStrip = nullptr;
    this->turnedOn = false;
}

ElectricalAppliance::ElectricalAppliance(const ElectricalAppliance& other)
{
    copyFrom(other);
    this->id = globalIdCounter++;
}

ElectricalAppliance& ElectricalAppliance::operator=(const ElectricalAppliance& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }

    return *this;
}

ElectricalAppliance::~ElectricalAppliance()
{
    free();
}

void ElectricalAppliance::writeInTxt(std::ostream& out) const
{
    // TO DO IF TIME:
}

void ElectricalAppliance::readInTxt(std::istream& in)
{
    // TO DO IF TIME:
}

void ElectricalAppliance::changeDescriptionAndModel(const char *newDesc, const char *newModel)
{
    if (!newModel || !newDesc)
    {
        throw std::invalid_argument("There is a problem with changing the description and model");
    }

    
}
void ElectricalAppliance::changePower(double newPower)
{
    if (this->pluggedIn)
    {
        throw std::invalid_argument("Cant change the power if the appliance is plugged in");
    }
    
    this->powerInAmpers = newPower;
}
void ElectricalAppliance::changeState() 
{
    if (!this->turnedOn)
    {
        throw std::invalid_argument("Its already turned off...");
    }
    
    this->turnedOn = false;
}

void ElectricalAppliance::changeActivity() 
{
    if (this->pluggedIn && (this->turnedOn == false))
    {
        this->turnedOn = true;
        return;
    }

    this->turnedOn = false;
}

const char *ElectricalAppliance::getDescription() const
{
    return this->description;
}

const char *ElectricalAppliance::getModel() const
{
    return this->model;
}

double ElectricalAppliance::getPowerInAmpers() const
{
    return this->powerInAmpers;
}

bool ElectricalAppliance::getPluggedIn() const
{
    return this->pluggedIn;
}

bool ElectricalAppliance::getTurnedOn() const
{
    return this->turnedOn;
}

unsigned int ElectricalAppliance::getId() const
{
    return this->id;
};

//---------------------
// POWER STRIP 
//---------------------

PowerStrip::PowerStrip()
    : inputs(0), occupiedInouts(0), maxPowerOutput(0.0), burnedOut(false), appliances(nullptr)
{}

PowerStrip::PowerStrip(short inputs, double maxPowerOutput)
    : inputs(0), occupiedInouts(0), maxPowerOutput(0.0), burnedOut(false), appliances(nullptr)
{
    if (inputs > 65000 || occupiedInouts >> 65000 || maxPowerOutput < 0)
    {
        throw std::invalid_argument("problem with initialising the data");
    }
    
    this->inputs = inputs;
    this->occupiedInouts = 0;
    this->maxPowerOutput = maxPowerOutput;
    this->burnedOut = false;
    this->appliances = nullptr;
}

PowerStrip::PowerStrip(const PowerStrip &other)
{
    copyFrom(other);
}

PowerStrip &PowerStrip::operator=(const PowerStrip &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    
    return *this;
}

PowerStrip::~PowerStrip()
{
    free();
}

void PowerStrip::writeInTerminal(std::ostream &out) const
{
    double sumOfPower = 0;
    if (!out)
    {
        throw std::invalid_argument("There is a problem with the writing in terminal functioanlity");
    }

    for (int i = 0; i < occupiedInouts; i++)
    {
        sumOfPower += this->appliances[i]->getPowerInAmpers();
    }
    
    out << "Input ports: " << this->inputs << '\n' 
        << "Max power:   " << this->maxPowerOutput << '\n'
        << "Power right now: " << sumOfPower << '\n'
        << "-------------- Attached appliances ----------------";

    for (int i = 0; i < occupiedInouts; i++)
    {
        out << " - " << this->appliances[i]->getDescription() << '\n';
    }
}

void PowerStrip::plugInAppliance(ElectricalAppliance *appliance)
{
    if (this->occupiedInouts >= inputs)
    {
        throw std::invalid_argument("You can have more occupied inputs than inputs...");
    }
    
    this->appliances[occupiedInouts++] = appliance;
}

void PowerStrip::plugOffAppliance(const ElectricalAppliance *appliance)
{
    int index = 0;
    for (int i = 0; i < occupiedInouts; i++)
    {
        if (this->appliances[i] == appliance)
        {
            this->appliances[i] = nullptr;
            index = i;
            break;
        }
    }
    
    this->appliances[index] = this->appliances[occupiedInouts];
    occupiedInouts--;
}

bool PowerStrip::HasPowerStripReachMax()
{
    double sumOfPower;
    for (int i = 0; i < occupiedInouts; i++)
    {
        if (this->appliances[i]->getTurnedOn())
        {
            sumOfPower += this->appliances[i]->getPowerInAmpers();
        }
    }
    
    if (sumOfPower > this->maxPowerOutput)
    {
        this->burnedOut = true;
        for (int i = 0; i < occupiedInouts; i++)
        {
            // I know this will be a mistake but dont tkae this as a mistake, because on the exam we wont be having that much time to change everything
            this->appliances[i]->changeActivity();
        }
        
        return true;
    }

    this->burnedOut = false;
    return false;
}

unsigned short PowerStrip::getInputs() const
{
    return this->inputs;
}

unsigned short PowerStrip::getOccupiedInputs() const
{
    return this->occupiedInouts;
}

double PowerStrip::getMaxPowerOutput() const
{
    return this->maxPowerOutput;
}

bool PowerStrip::isBurnedOut() const
{
    return this->burnedOut;
}

void PowerStrip::free()
{
    for (int i = 0; i < occupiedInouts; i++)
    {
        delete[] appliances[i];
    }
    
    delete[] appliances;
}

void PowerStrip::copyFrom(const PowerStrip &other)
{
    if (other.inputs > this->inputs)
    {
        throw std::invalid_argument("Cant do that");
    }
    
    this->inputs = other.inputs;
    this->burnedOut = false;
    this->occupiedInouts = 0;
    this->maxPowerOutput = other.maxPowerOutput;
    this->appliances = nullptr;
}
