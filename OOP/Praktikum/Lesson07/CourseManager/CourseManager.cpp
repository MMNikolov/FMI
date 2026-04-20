#include "CourseManager.hpp"

void Course::copyFrom(const Course &other)
{
    this->courseName = new char[strlen(other.courseName) + 1];
    strcpy(this->courseName, other.courseName);

    strcpy(this->major, other.major);

    this->year = other.year;
    this->dayOfTheWeek = other.dayOfTheWeek;
    this->duration = other.duration;
    this->room = other.room;
    this->startHour = other.startHour;
    this->stream = other.stream;
};

void Course::free()
{
    delete[] courseName;
    courseName = nullptr;
};

Course::Course() 
    : courseName(nullptr), major("none"), year(0),
      dayOfTheWeek(0), duration(0), room(0),
      startHour(0), stream(0) {}

Course::Course(const char *courseName, const char major[MAJOR_MAX_LENGTH],
           short year, short stream, short dayOfTheWeek, short startHour,
           short duration, short room)
    : courseName(nullptr), major("none"), year(0),
      dayOfTheWeek(0), duration(0), room(0),
      startHour(0), stream(0)
{

}