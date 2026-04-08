#include "AlbumManager.hpp"

void Song::free()
{
    delete[] title; title = nullptr;
    delete[] artist; artist = nullptr;
    delete[] original; original = nullptr;
};

void Song::copyFrom(const Song& other)
{
    this->title = new char[strlen(other.title) + 1];
    strcpy(this->title, other.title);
    this->artist = new char[strlen(other.artist) + 1];
    strcpy(this->artist, other.artist);

    this->yearOfRelease = other.yearOfRelease;
    this->lengthInSeconds = other.lengthInSeconds;

    this->original = new Song;
    this->original = other.original;
};

Song::Song() : 
    title(nullptr), 
    artist(nullptr), 
    yearOfRelease(0), 
    lengthInSeconds(0), 
    original(nullptr)
{
    this->artist = new char[1];
    this->artist[0] = '\0';

    this->title = new char[1];
    this->title[0] = '\0';

    this->original = new Song[1];
    this->original[0] = {};
}

Song::Song(const char *title, const char *artist, unsigned short yearOfRelease, unsigned short lengthInSeconds)
    : title(nullptr), 
    artist(nullptr), 
    yearOfRelease(0), 
    lengthInSeconds(0), 
    original(nullptr)
{
    if (!title || *title == '\0')
    {
        throw std::invalid_argument("Problem with ordinary constructor");
    }

    this->title = new char[strlen(title) + 1];
    strcpy(this->title, title);

    if (!artist || *artist == '\0')
    {
        delete[] title;
        throw std::invalid_argument("Problem with the ordinary constructor");
    }
    
    this->artist = new char[strlen(artist) + 1];
    strcpy(this->artist, artist);
    
    if (yearOfRelease < 1900 || yearOfRelease > 2026)
    {
        delete[] title;
        delete[] artist;
        throw std::invalid_argument("Are you a time traveller");
    }
    
    this->yearOfRelease = yearOfRelease;

    if (lengthInSeconds > 65535)
    {
        delete[] title;
        delete[] artist;
        throw std::invalid_argument("You are taking a piss");
    }
    
    this->lengthInSeconds = lengthInSeconds;
};

Song::Song(const Song& other)
{
    copyFrom(other);
};

Song& Song::operator=(const Song &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    
    return *this;
};

Song::~Song()
{
    free();
}

void Song::printSong()
{
    std::cout << "Title: " << this->title
              << "\nArtist: " << this->artist
              << "\nYear Of Release: " << this->yearOfRelease
              << "\nLength (in seconds): " << this->lengthInSeconds
              << "\n";
}

