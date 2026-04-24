#include "ElectricalAppliance.hpp"
#include <iostream>

int main() {
    try {
        std::cout << "=== 1. СЪЗДАВАНЕ НА УРЕДИ ===\n";
        ElectricalAppliance tv("Телевизор Samsung", "QLED 55", 2.0);       // 2.0 Ампера
        ElectricalAppliance pc("Геймърски компютър", "Custom Build", 3.5); // 3.5 Ампера
        ElectricalAppliance heater("Отоплителна печка", "Tesy 3000W", 10.0); // 10.0 Ампера
        
        std::cout << "TV ID: " << tv.getId() << "\n";
        std::cout << "PC ID: " << pc.getId() << "\n\n";

        std::cout << "=== 2. СЪЗДАВАНЕ НА РАЗКЛОНИТЕЛ ===\n";
        // Разклонител с 3 гнезда и максимум 12.0 Ампера
        PowerStrip myStrip(3, 12.0); 

        std::cout << "=== 3. ВКЛЮЧВАНЕ И ПУСКАНЕ ===\n";
        // Включваме ги в разклонителя
        myStrip.plugInAppliance(&tv);
        myStrip.plugInAppliance(&pc);

        // Оказваме на самите уреди, че са включени в мрежата (използвайки добавения метод)
        tv.setPluggedIn(true);
        pc.setPluggedIn(true);

        // Пускаме ги да работят (turnOn = true)
        tv.changeActivity(); 
        pc.changeActivity();

        std::cout << "Състояние преди печката:\n";
        myStrip.writeInTerminal(std::cout);
        myStrip.HasPowerStripReachMax(); // Проверяваме товара
        std::cout << "\nИзгорял ли е разклонителят? " << (myStrip.isBurnedOut() ? "ДА" : "НЕ") << "\n\n";


        std::cout << "=== 4. ПРЕТОВАРВАНЕ (ИЗГАРЯНЕ) ===\n";
        // Включваме печката (10А), което ще направи общия ток 15.5А (над лимита от 12А)
        myStrip.plugInAppliance(&heater);
        heater.setPluggedIn(true);
        heater.changeActivity();

        if (myStrip.HasPowerStripReachMax()) {
            std::cout << "БЯМ! Разклонителят беше претоварен и изгоря!\n";
        }

        // Проверяваме дали уредите са се изключили (както изисква условието)
        std::cout << "Работи ли телевизорът след изгарянето? " << (tv.getTurnedOn() ? "ДА" : "НЕ (Правилно)") << "\n\n";


        std::cout << "=== 5. ТЕСТВАНЕ НА RULE OF 3 ===\n";
        PowerStrip backupStrip = myStrip;
        std::cout << "Копираният разклонител има " << backupStrip.getInputs() << " гнезда и " 
                  << backupStrip.getOccupiedInputs() << " включени уреди.\n";
        if (backupStrip.getOccupiedInputs() == 0) {
            std::cout << "УСПЕХ: Копието е правилно създадено без уреди в него!\n";
        }

    } catch (const std::exception& e) {
        // Ако някъде гръмне (например хвърлиш invalid_argument), ще го хванем тук
        std::cerr << "ВЪЗНИКНА ГРЕШКА: " << e.what() << '\n';
    }

    return 0;
}