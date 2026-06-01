#include <iostream>
#include <fstream>
#include <string>
#include "Server.hpp"
#include "MobileDevice.hpp"
#include "DesktopDevice.hpp"

int main()
{
    try 
    {
        // 1. Създайте сървър с капацитет 4 връзки и таймаут 10.
        std::cout << "--- Стъпка 1 & 2 ---\n";
        Server server1(4, 10);

        // 2. Създайте 6 устройства от различни типове и с различни имена.
        MobileDevice m1("Phone1", 80);
        DesktopDevice d1("PC1", "192.168.0.1");
        MobileDevice m2("Tablet", 45);
        DesktopDevice d2("Laptop", "github.com");
        MobileDevice m3("SmartWatch", 99);
        DesktopDevice d3("ServerNode", "10.0.0.5");

        // 3. Такт 0: свържете 2 устройства.
        server1.connect(m1);
        server1.connect(d1);
        
        // Такт 3: свържете трето. Запишете server.log.
        server1.tick(3);
        server1.connect(m2);
        
        server1.saveLog("server.log");
        std::cout << "Логът 'server.log' е записан успешно (Такт 3).\n\n";

        // 4. Такт 5: свържете четвърто устройство.
        std::cout << "--- Стъпка 4 ---\n";
        server1.tick(2); // (Текущо време 3) + 2 = 5
        server1.connect(d2);
        
        // Опитайте да свържете пето — трябва да бъде отхвърлено.
        bool isConnected = server1.connect(m3);
        if (!isConnected)
        {
            std::cout << "Опитът за пето устройство е отхвърлен (сървърът е пълен).\n";
        }

        // 5. Такт 11: Прекъснете ръчно едно от останалите свързани устройства.
        std::cout << "\n--- Стъпка 5 ---\n";
        server1.tick(6); // (Текущо време 5) + 6 = 11. (m1 и d1 автоматично изтичат тук)
        
        // Прекъсваме ръчно m2
        server1.disconnect(m2.GetId());
        std::cout << "Устройство с ID " << m2.GetId() << " е прекъснато ръчно.\n";
        
        // Свържете петото устройство.
        server1.connect(m3);
        std::cout << "Петото устройство (SmartWatch) е свързано.\n";
        
        std::cout << "Съдържание на final_server.log:\n";
        std::ifstream file("final_server.log");
        std::string line;
        while (std::getline(file, line))
        {
            std::cout << line << '\n';
        }
        file.close();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Критична грешка: " << e.what() << '\n';
    }

    return 0;
}