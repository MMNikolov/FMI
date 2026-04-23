#pragma once

#include <iostream>
#include <stdexcept>
#include <cstring>

// major constraints
#define MAJOR_MAX_LENGTH 30

// year constraints
#define YEAR_MIN_NUMBER 0
#define YEAR_MAX_NUMBER 4

// stream constraints
#define STREAM_MIN_NUMBER 0
#define STREAM_MAX_NUMBER 2

// day of the week constraints
#define DAY_OF_WEEK_MIN 1
#define DAY_OF_WEEK_MAX 6

// start hour constraints
#define START_HOUR_MIN 7
#define START_HOUR_MAX 20

// duration constraints
#define DURATION_MIN 1
#define DURATION_MAX 6

// room constraints
#define ROOM_MIN 1
#define ROOM_MAX 599

class Course
{
public:
    // default constructor
    Course();

    // ordinary constructor
    Course(const char *courseName, const char major[MAJOR_MAX_LENGTH],
           short year, short stream, short dayOfTheWeek, short startHour,
           short duration, short room);

    // copy constructor
    Course(const Course &other);
    Course &operator=(const Course &other);

    // destructor
    ~Course();

    // getters
    const char *GetCourseName() const;
    const char GetMajor() const;
    const short GetYear() const;
    const short GetStream() const;
    const short GetDayOfTheWeek() const;
    const short GetStartHour() const;
    const short GetDuration() const;
    const short GetRoom() const;

private:
    char *courseName;
    char major[MAJOR_MAX_LENGTH];
    short year;
    short stream;
    short dayOfTheWeek;
    short startHour;
    short duration;
    short room;

private:
    void copyFrom(const Course &other);
    void free();
};

class SemesterSchedule
{
public:
    //default constructor
    SemesterSchedule();

    //ordinary constructor
    SemesterSchedule(short freeAuditoryRooms[ROOM_MAX]);

    //copy constructor
    SemesterSchedule(const SemesterSchedule& other);
    SemesterSchedule& operator=(const SemesterSchedule& other);

    //destructor
    ~SemesterSchedule();

    //functions
    void addCourse(const Course& course);
    void printAuditoriumSchedule();
    void printClassSchedule();
    void findFreeSlot();

private:
    Course* courses;
    short freeAuditoryRooms[ROOM_MAX];

private:
    void copyFrom(const SemesterSchedule& other);
    void free();
};
