#pragma once

#include <iostream>
#include <stdexcept>
#include <cstring>

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

    void printSong();

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

    unsigned short getlenthInSeconds();
    char* getArtist();
    Song* findSong();
    // duplicates count as same artist, title, ReleaseDate and length
    void deleteDuplicates();
    void detectCovers();

private:
    Song* songs;
    char* albumName;

    void copyFrom(const Album& other);
    void free();
};
