#include "AlbumManager.hpp"

// -----------------------
// SONG IMPLEMENTATION
// -----------------------

void Song::free()
{
    delete[] title;
    title = nullptr;
    delete[] artist;
    artist = nullptr;
};

void Song::copyFrom(const Song &other)
{
    this->title = new char[strlen(other.title) + 1];
    strcpy(this->title, other.title);
    this->artist = new char[strlen(other.artist) + 1];
    strcpy(this->artist, other.artist);

    this->yearOfRelease = other.yearOfRelease;
    this->lengthInSeconds = other.lengthInSeconds;

    if (other.original != nullptr)
    {
        this->original = new Song(*(other.original)); // Calls copy constructor recursively
    }
    else
    {
        this->original = nullptr;
    }
};

Song::Song() : title(nullptr),
               artist(nullptr),
               yearOfRelease(0),
               lengthInSeconds(0),
               original(nullptr)
{
    this->artist = new char[1];
    this->artist[0] = '\0';

    this->title = new char[1];
    this->title[0] = '\0';

    this->original = nullptr;
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
        free();
        throw std::invalid_argument("Are you a time traveller");
    }

    this->yearOfRelease = yearOfRelease;

    if (lengthInSeconds > 65535)
    {
        free();
        throw std::invalid_argument("You are taking a piss");
    }

    this->lengthInSeconds = lengthInSeconds;
};

Song::Song(const Song &other)
{
    copyFrom(other);
};

Song &Song::operator=(const Song &other)
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

void Song::printSong() const
{
    std::cout << "Title: " << this->title
              << "\nArtist: " << this->artist
              << "\nYear Of Release: " << this->yearOfRelease
              << "\nLength (in seconds): " << this->lengthInSeconds
              << "\n";
}

const int Song::GetLengthInSeconds() const
{
    return this->lengthInSeconds;
};

const char *Song::GetArtist() const
{
    return this->artist;
};

const char *Song::GetTitle() const
{
    return this->title;
};

// -----------------------
// ALBUM IMPLEMENTATION
// -----------------------

void Album::free()
{
    delete[] albumName;
    delete[] songs;
}

void Album::copyFrom(const Album &other)
{
    this->songsCount = other.songsCount;
    
    this->songs = new Song[MAX_SONGS_IN_ALBUM];
    for (unsigned short i = 0; i < songsCount; i++)
    {
        this->songs[i] = other.songs[i];
    }

    this->albumName = new char[strlen(other.albumName) + 1];
    strcpy(this->albumName, other.albumName);
}

Album::Album()
    : albumName(nullptr),
      songs(nullptr),
      songsCount(0)
{
    this->albumName = new char[1];
    this->albumName[0] = '\0';

    this->songs = new Song[MAX_SONGS_IN_ALBUM];
}

Album::Album(const char *albumName)
    : albumName(nullptr),
      songs(nullptr),
      songsCount(0)
{
    if (!albumName || *albumName == '\0')
    {
        throw std::invalid_argument("There was a problem with the album constructor");
    }

    this->albumName = new char[strlen(albumName) + 1];
    strcpy(this->albumName, albumName);

    this->songs = new Song[MAX_SONGS_IN_ALBUM];
}

Album::Album(const Album &other)
{
    copyFrom(other);
}

Album &Album::operator=(const Album &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }

    return *this;
}

Album::~Album()
{
    free();
}

void Album::addSong(const Song &song)
{
    if (this->songsCount > MAX_SONGS_IN_ALBUM)
    {
        throw std::invalid_argument("You cannot have over 65 000 songs in an album");
    }

    this->songs[songsCount++] = song;
}

unsigned short Album::getlenthInSeconds() const
{
    unsigned short sum = 0;

    for (unsigned short i = 0; i < songsCount; i++)
    {
        sum += this->songs[i].GetLengthInSeconds();
    }

    return sum;
};

char *Album::getArtistInAlbum() const
{
    if (songsCount == 0) return (char*)"Unknown";

    const char *firstArtist = this->songs[0].GetArtist();

    for (unsigned short i = 1; i < songsCount; i++)
    {
        if (strcmp(firstArtist, this->songs[i].GetArtist()) == 0)
        {
            continue;
        }
        else
        {
            return (char*)"Various Artists";
        }
    }

    return (char*)firstArtist;
};

Song *Album::findSong(const char *title)
{
    for (unsigned short i = 0; i < songsCount; i++)
    {
        if (strcmp(title, this->songs[i].GetTitle()) == 0)
        {
            return &songs[i];
        }
    }

    return nullptr;
};

void Album::printAlbum() const
{
    std::cout << "=== Album: " << albumName << " ===\n";
    std::cout << "Album Artist: " << getArtistInAlbum() << "\n";
    std::cout << "Total Length: " << getlenthInSeconds() << "s\n\n";

    for (unsigned short i = 0; i < songsCount; ++i)
    {
        songs[i].printSong();
    }
}
