#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "AlternateDataSource.hpp"
#include "ArrayDataSource.hpp"
#include "GeneratorDataSource.hpp"

// ---------------------------------------------------------
// Помощен клас за прости числа (защото пазят състояние)
// ---------------------------------------------------------
class PrimeDataSource : public DataSource<int>
{
    int current = 1;
    bool isPrime(int n) const
    {
        if (n <= 1)
            return false;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }

public:
    int takeNext() override
    {
        current++;
        while (!isPrime(current))
            current++;
        return current;
    }
    int *takeNextFew(int few, int &extracted) override
    {
        int *arr = new int[few];
        for (int i = 0; i < few; i++)
            arr[i] = takeNext();
        extracted = few;
        return arr;
    }
    bool hasNext() const override { return true; }
    bool reset() override
    {
        current = 1;
        return true;
    }
};

// ---------------------------------------------------------
// Функции за GeneratorDataSource
// ---------------------------------------------------------
int randomIntGenerator()
{
    return std::rand() % 10000; // Случайно число
}

char *randomStringGenerator()
{
    // Заделяме 11 байта (10 символа + терминираща нула)
    char *str = new char[11];
    for (int i = 0; i < 10; i++)
    {
        str[i] = 'a' + (std::rand() % 26); // Малки латински букви
    }
    str[10] = '\0';
    return str;
}

// ---------------------------------------------------------
// Същинска логика
// ---------------------------------------------------------
int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    try
    {
        // 1. ПОДГОТОВКА НА ФИБОНАЧИ (първите 25 числа)
        int fib[25];
        fib[0] = 1;
        fib[1] = 1;
        for (int i = 2; i < 25; i++)
        {
            fib[i] = fib[i - 1] + fib[i - 2];
        }

        // 2. СЪЗДАВАНЕ НА ИЗТОЧНИЦИТЕ
        DataSource<int> *sources[3];
        sources[0] = new PrimeDataSource();                            // 1. Прости числа
        sources[1] = new GeneratorDataSource<int>(randomIntGenerator); // 2. Случайни числа
        sources[2] = new ArrayDataSource<int>(fib, 25);                // 3. Фибоначи

        AlternateDataSource<int> combinedSource(sources, 3);

        // 3. ЗАПИС НА 1000 ЧИСЛА В ДВОИЧЕН ФАЙЛ
        char filename1[256];
        std::cout << "Enter filename for 1000 numbers (.bin): ";
        std::cin >> filename1;

        std::ofstream outFile1(filename1, std::ios::binary);
        if (!outFile1)
            throw std::runtime_error("Cannot open file for writing numbers");

        for (int i = 0; i < 1000; i++)
        {
            int number = combinedSource.takeNext();
            outFile1.write(reinterpret_cast<const char *>(&number), sizeof(int));
        }
        outFile1.close();
        std::cout << "Successfully wrote 1000 numbers.\n";

        // 4. ГЕНЕРАТОР НА СТРИНГОВЕ
        GeneratorDataSource<char *> stringSource(randomStringGenerator);

        char filename2[256];
        std::cout << "Enter filename for 50 strings (.bin): ";
        std::cin >> filename2;

        std::ofstream outFile2(filename2, std::ios::binary);
        if (!outFile2)
        {
            throw std::runtime_error("Cannot open file for writing strings");
        }
            
        for (int i = 0; i < 50; i++)
        {
            char *randomStr = stringSource.takeNext();
            // Записваме 10-те символа
            outFile2.write(randomStr, 10);

            // КРИТИЧНО: Ние носим отговорност за изтриването на заделената от генератора памет
            delete[] randomStr;
        }
        outFile2.close();
        std::cout << "Successfully wrote 50 strings.\n";

        // 5. РАЗЧИСТВАНЕ НА ПАМЕТТА
        delete sources[0];
        delete sources[1];
        delete sources[2];
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return 0;
}