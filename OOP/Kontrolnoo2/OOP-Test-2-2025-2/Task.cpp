#include "Task.hpp"

Task::Task(const char *name, const char *description, unsigned hours, bool isRepeatedMonthly, const char *endDate)
    : Event(name, description, hours, isRepeatedMonthly)
{
    if (!endDate)
    {
        throw std::invalid_argument("Invalid Input in the Task ctor");
    }
    
    this->endDate = new char[strlen(endDate) + 1];
    strcpy(this->endDate, endDate);
}

Task::Task(const Task &other)
    : Event(other)
{
    this->endDate = new char[strlen(other.endDate) + 1];
    strcpy(this->endDate, other.endDate);
}

Task &Task::operator=(const Task &other)
{
    if (this != &other)
    {
        Event::operator=(other);

        free();

        this->endDate = new char[strlen(other.endDate) + 1];
        strcpy(this->endDate, other.endDate);
    }
    
    return *this;
}

Task::~Task()
{
    free();
}

Task *Task::clone() const
{
    return new Task(*this);
}

void Task::free()
{
    delete[] this->endDate;
    this->endDate = nullptr;
}

//Ask Marto about this and how can we reuse the base abstract class, because its tedious to do it all over again
std::ostream &operator<<(std::ostream &out, const Task &task)
{

    operator << (out, task);


    return out;
}

//same as the out operator
std::istream &operator>>(std::istream &in, Task &task)
{
    operator>>(is, static_cast<Event>(task));
    return in;
}

//this is trivial and we dont need to look at it
bool operator>(const Task &one, const Task &two)
{
    return false;
}

//this is trivial as well
bool operator<(const Task &one, const Task &two)
{
    return false;
}
