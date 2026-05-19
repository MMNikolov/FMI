#include "Laptop.hpp"
#include "Car.hpp"
#include "Inventory.hpp"
#include "Device.hpp"

int main()
{
    try
    {
        Inventory myInv;

        Laptop l1("Dell", 2400);
        Laptop l2("Apple", 3200);
        Car c1("Toyota", 110, 2000);
        Car c2("BMW", 250, 3000);

        // Добавяме разбъркано, за да тестваме сортировката
        myInv.addDevice(c1); // 110
        myInv.addDevice(l1); // 2400
        myInv.addDevice(c2); // 250 (Тук се чупи възходящия ред)
        myInv.addDevice(l2); // 3200

        myInv.printDevices();

        if (myInv.isSorted())
        {
            std::cout << "The inventory IS sorted by performance.\n";
        }
        else
        {
            std::cout << "The inventory IS NOT sorted by performance.\n";
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return 0;
}