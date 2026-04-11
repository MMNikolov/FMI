#pragma once

#include <iostream>
#include <stdexcept>
#include <cstring>

#define MAX_SONGS_IN_ALBUM 65000

class Song
{
public:
    // default constructor
    Song();

    // ordinary constructor
    Song(const char *title, const char *artist, unsigned short yearOfRelease, unsigned short lengthInSeconds);

    // copy constructor
    Song(const Song &other);
    Song &operator=(const Song &other);

    // destructor
    ~Song();

    void printSong() const;
    const int GetLengthInSeconds() const;
    const char* GetArtist() const;
    const char* GetTitle() const;

private:
    char *title;
    char *artist;
    unsigned short yearOfRelease;
    unsigned short lengthInSeconds;
    Song *original;

    void free();
    void copyFrom(const Song& other);
};

class Album
{
public:
    //default constructor
    Album();

    //ordinary constructor
    Album(const char* albumName);

    //copy constructor
    Album(const Album& other);
    Album& operator=(const Album& other);

    //destrcutor
    ~Album();

    void addSong(const Song& song);
    unsigned short getlenthInSeconds() const;
    char* getArtistInAlbum() const;
    Song* findSong(const char* title);
    void printAlbum() const;

private:
    Song* songs;
    char* albumName;
    //I doubt there will be an album with more than 65k songs
    unsigned short songsCount;

    void copyFrom(const Album& other);
    void free();
};
