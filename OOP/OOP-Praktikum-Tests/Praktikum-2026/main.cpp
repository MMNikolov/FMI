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
        // 1. Create a server with capacity 4 and timeout 10.
        Server server1(4, 10);

        // 2. Create 6 devices of different types.
        MobileDevice m1("Phone1", 80);
        DesktopDevice d1("PC1", "192.168.0.1");
        MobileDevice m2("Tablet", 45);
        DesktopDevice d2("Laptop", "github.com");
        MobileDevice m3("SmartWatch", 99);
        DesktopDevice d3("ServerNode", "10.0.0.5");

        // 3. Tick 0: connect 2 devices.
        server1.connect(m1);
        server1.connect(d1);

        // Tick 3: connect third. Save server.log.
        server1.tick(3);
        server1.connect(m2);
        server1.saveLog("server.log");
        std::cout << "[Tick 3] Saved server.log\n";

        // 4. Tick 5: connect fourth. Attempt fifth -> should be rejected.
        server1.tick(2); // 3 + 2 = 5
        server1.connect(d2);

        if (!server1.connect(m3))
        {
            std::cout << "[Tick 5] Fifth device successfully rejected (Server full).\n";
        }

        // 5. Tick 11: Disconnect manually one of the remaining, connect fifth.
        server1.tick(6); // 5 + 6 = 11. (m1 and d1 naturally timeout here).

        server1.disconnect(m2.GetId());
        std::cout << "[Tick 11] Device ID " << m2.GetId() << " disconnected manually.\n";

        server1.connect(m3);
        std::cout << "[Tick 11] Connected fifth device.\n";

        // 6. Create new server, load server.log. Connect sixth device.
        Server server2(4, 10);
        server2.loadLog("server.log");
        server2.connect(d3);

        // 7. Call print operation to demonstrate polymorphism.
        std::cout << "\n--- Server 2 Polymorphic State ---\n";
        server2.printServerState();

        // 8. Save final log and print it.
        server2.saveLog("final_server.log");

        std::cout << "\n--- final_server.log Content ---\n";
        std::ifstream file("final_server.log");
        std::string line;
        while (std::getline(file, line))
        {
            std::cout << line << '\n';
        }
        file.close();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Fatal Error: " << e.what() << '\n';
    }

    return 0;
}