#include "Parking.hpp"
#include <cmath>

int main()
{
    try
    {
        taxRateeeee = 2.50;

        Parking myParking;

        Car car1("CB1234AB", 60);
        Car car2("PB5678CT", 120);
        Car car3("V9999VV", 150);

        std::cout << "--- Registering Cars ---\n";
        myParking.Enter(car1);
        myParking.Enter(car2);
        myParking.Enter(car3);

        myParking.printCars();

        std::cout << "\n--- Checking Registration ---\n";
        if (myParking.isRegistered(car2))
        {
            std::cout << car2.GetLicencePlate() << " is in the parking.\n";
        }

        Car unregisteredCar("A0000AA", 0);
        if (!myParking.isRegistered(unregisteredCar))
        {
            std::cout << unregisteredCar.GetLicencePlate() << " is NOT in the parking.\n";
        }

        std::cout << "\n--- Leaving Parking ---\n";
        myParking.Leave(car1, 185, taxRateeeee);

        std::cout << "\n--- Cars left in parking ---\n";
        myParking.printCars();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Critical Error: " << e.what() << '\n';
    }

    return 0;
}