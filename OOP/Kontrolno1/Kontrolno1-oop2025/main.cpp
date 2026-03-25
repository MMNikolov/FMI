#include <iostream>
#include <fstream>
#include <cstring>

class ElectricalAppliance
{
private:
    char *description = nullptr;
    char *model = nullptr;
    double powerInAmpers;
    struct PluggedIn
    {
        bool flag = false;
        char *whereItIsPluggedIn = nullptr;

    } plugged_in;
    bool TurnedOn = false;
    const unsigned int partitionNumber;

    static unsigned int nextID;

    // pomoshtna funciq ot gemini che mi praveshe problemi pri normalnoto strcpy
    void setString(char *&dest, const char *source)
    {
        if (!source)
        {
            return;
        }

        delete[] dest;
        dest = new char[strlen(source) + 1];
        strcpy(dest, source);
    }

public:
    ElectricalAppliance(const char *desc, const char *mod, double pwr) : description(nullptr), model(mod ? nullptr : nullptr),
                                                                         powerInAmpers(pwr), partitionNumber(++nextID)
    {
        setString(description, desc);
        setString(model, mod);
    }

    ~ElectricalAppliance()
    {
        delete[] description;
        delete[] model;
        delete[] plugged_in.whereItIsPluggedIn;
    }

    void outputTextFile(std::fstream &os)
    {
        os << description << model << powerInAmpers
           << plugged_in.flag << plugged_in.whereItIsPluggedIn
           << TurnedOn << partitionNumber;
    }

    void inputTextFile(std::ifstream &is)
    {
        return;
    }

    void changeDescriptionAndModel(char *newDescription, char *newModel)
    {
        if (newDescription && strlen(newDescription) > 0)
        {
            setString(description, newDescription);
        }
        if (newModel && strlen(newModel) > 0)
        {
            setString(model, newModel);
        }
    }

    void changePowerInAmps(double newPower)
    {
        if (plugged_in.flag == true || TurnedOn == true)
        {
            std::cerr << "You cant change the power to the model if it is plugged in to the network!";
            return;
        }

        if (newPower > 0)
        {
            powerInAmpers = newPower;
        }
    }

    void PowerOff()
    {
        if (TurnedOn == false)
        {
            std::cerr << "the device has already been shut down";
            return;
        }

        TurnedOn = false;
    }

    void changeStateOfPower()
    {
        if (plugged_in.flag == true && TurnedOn == false)
        {
            TurnedOn = true;
            return;
        }

        TurnedOn = false;
    }

    void CopyAppliance(ElectricalAppliance &ea)
    {
    }
};

int main()
{

    return 0;
}