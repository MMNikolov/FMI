#include "supermarket.hpp"

int main()
{
    try
    {
        Store storeA("Fantastico");

        Cashier c1("Ivan", 1500.50);
        Cashier c2("Maria", 2300.00);

        storeA.addCashiers(c1);
        storeA.addCashiers(c2);

        storeA.print(std::cout);

        Store storeB("Kaufland");
        Cashier c3("Georgi", 5000.00);
        storeB.addCashiers(c3);

        storeB.print(std::cout);

        int comparison = storeA.equals(storeB);
        if (comparison == 1)
        {
            std::cout << "Fantastico has a better average turnover per cashier.\n";
        }
        else if (comparison == -1)
        {
            std::cout << "Kaufland has a better average turnover per cashier.\n";
        }
        else
        {
            std::cout << "Both stores have equal average turnover.\n";
        }

        const Cashier *found = storeA.findCashierByName("Maria");
        if (found)
        {
            std::cout << "\nFound cashier: ";
            found->print(std::cout);
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return 0;
}