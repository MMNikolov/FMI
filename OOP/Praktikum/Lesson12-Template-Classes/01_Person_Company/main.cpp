#include <iostream>
#include <cstring>
#include "Company.hpp"
#include "Employee.hpp"

int main()
{
    try
    {
        std::cout << "=== 1. Създаване на компании ===\n";
        Company c1;
        strcpy(c1.name, "TechCorp EOOD");
        strcpy(c1.BULSTAT, "123456789");

        Company c2;
        strcpy(c2.name, "SoftDev OOD");
        strcpy(c2.BULSTAT, "987654321");
        std::cout << "Компаниите са създадени успешно.\n";

        std::cout << "\n=== 2. Създаване на служители (Параметризиран конструктор) ===\n";
        // Служител СЪС зададена компания
        Employee emp1("Ivan Ivanov", "1234567890", "Backend Developer", &c1);
        emp1.printInfo();

        // Служител БЕЗ зададена компания (очакваме да отпечата Company: None)
        Employee emp2("Maria Popova", "0987654321", "HR Manager"); 
        emp2.printInfo();

        std::cout << "\n=== 3. Тестване на Copy Конструктор ===\n";
        Employee emp3(emp1);
        std::cout << "Данни на копирания служител (emp3 трябва да е същият като Ivan):\n";
        emp3.printInfo();

        std::cout << "\n=== 4. Тестване на Оператор за присвояване (=) ===\n";
        Employee emp4("Petar Petrov", "1111111111", "DevOps", &c2);
        std::cout << "Данни ПРЕДИ присвояването (emp4):\n";
        emp4.printInfo();
        
        emp4 = emp2; // emp4 вече трябва да е пълно копие на emp2 (Maria, без компания)
        std::cout << "Данни СЛЕД присвояването (emp4 = emp2):\n";
        emp4.printInfo();

        std::cout << "\n=== 5. Тестване на изключения (Грешни данни) ===\n";
        try 
        {
            std::cout << "-> Опит за създаване с невалидно ЕГН (3 цифри)...\n";
            Employee badEmp("Georgi", "123", "QA", &c1);
        }
        catch(const std::invalid_argument& e)
        {
            std::cerr << "Успешно хванато изключение: " << e.what() << '\n';
        }

        try 
        {
            std::cout << "-> Опит за създаване с nullptr специалност...\n";
            Employee badEmp2("Dimitar", "1234567890", nullptr);
        }
        catch(const std::invalid_argument& e)
        {
            std::cerr << "Успешно хванато изключение: " << e.what() << '\n';
        }

        std::cout << "\n=== Всички тестове преминаха успешно! ===\n";
        // При излизане от скоупа (края на main), деструкторите ще се извикат автоматично
        // и ще изчистят заделената динамична памет.
    }
    catch(const std::exception& e)
    {
        std::cerr << "Критична грешка: " << e.what() << '\n';
    }

    return 0;
}