#include "AlbumManager.hpp"

//Kazah na gemini da mi dade random main, za da si istestvam logikata

int main()
{
    try
    {
        // 1. Създаваме албум
        Album myAlbum("Epic Rock Collection");

        // 2. Създаваме песни
        // Оригинална песен
        Song originalSong("Knockin' on Heaven's Door", "Bob Dylan", 1973, 150);

        // Друга песен
        Song queenSong("Bohemian Rhapsody", "Queen", 1975, 354);

        // Кавър на оригиналната песен (по-късна година, друг изпълнител)
        Song coverSong("Knockin' on Heaven's Door", "Guns N' Roses", 1991, 336);

        // Точен дубликат на queenSong
        Song duplicateSong("Bohemian Rhapsody", "Queen", 1975, 354);

        // 3. Добавяме ги в албума
        myAlbum.addSong(originalSong);
        myAlbum.addSong(queenSong);
        myAlbum.addSong(coverSong);
        myAlbum.addSong(duplicateSong);

        // Извеждаме албума преди да сме зачистили дубликатите и да сме намерили кавърите
        std::cout << "======== ПРЕДИ ОБРАБОТКА ========\n";
        myAlbum.printAlbum();
        std::cout << "=================================\n\n";

        // 4. Тестваме търсенето (findSong)
        std::cout << "--- Търсене на песен: 'Bohemian Rhapsody' ---\n";
        Song *found = myAlbum.findSong("Bohemian Rhapsody");
        if (found != nullptr)
        {
            std::cout << "Намерена е: ";
            found->printSong();
        }
        else
        {
            std::cout << "Песента не е намерена.\n";
        }
        std::cout << "\n";

        // 6. Извеждаме финалния резултат
        std::cout << "======== СЛЕД ОБРАБОТКА ========\n";
        myAlbum.printAlbum();
        std::cout << "=================================\n";
    }
    catch (const std::invalid_argument &e)
    {
        // Хващаме грешките, ако се опиташ да създадеш невалидна песен
        std::cerr << "Критична грешка при инициализация: " << e.what() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << "Неочаквана грешка: " << e.what() << '\n';
    }

    return 0;
}