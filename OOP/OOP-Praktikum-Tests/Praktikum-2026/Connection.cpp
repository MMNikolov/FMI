#include "Connection.hpp"

Connection::Connection()
    : device(nullptr), tick(0)
{
}

Connection::Connection(Device *device, unsigned tick)
{
    // copy constructor will take care of the problems
    this->device = device;
    this->tick = tick;
}

Connection::Connection(const Connection &other)
{
    copyFrom(other);
}

Connection &Connection::operator=(const Connection &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }

    return *this;
}

Connection::~Connection()
{
    free();
}

void Connection::copyFrom(const Connection &other)
{
    if (other.device)
    {
        this->device = other.device->clone(); // DEEP COPY
    }
    else
    {
        this->device = nullptr;
    }
    this->tick = other.tick;
}

void Connection::free()
{
    delete this->device;
}
