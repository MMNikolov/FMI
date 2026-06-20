#include "AreaHub.hpp"

AreaHub::AreaHub(const char *tag, const char *location, size_t capacity)
    : Component(tag, location), count(0), currentId(-1), capacity(capacity)
{
    this->components = new Component*[capacity];
    for (size_t i = 0; i < capacity; i++)
    {
        this->components[i] = nullptr;
    }
}

AreaHub::AreaHub(const AreaHub &other)
    : Component(other), count(other.count), currentId(other.currentId), capacity(other.capacity)
{
    this->components = new Component*[other.capacity];
    for (size_t i = 0; i < other.count; i++)
    {
        this->components[i] = other.components[i]->clone();
    }
}

AreaHub& AreaHub::operator=(const AreaHub &other)
{
    if (this != &other)
    {
        
    }
    
    return *this;
}

AreaHub::~AreaHub()
{
    free();
}

void AreaHub::render(std::ostream &out) const
{
    // Gemini do this one for me please
}

void AreaHub::save(std::ofstream &out) const
{
    Component::saveBase(out);

    out.write(reinterpret_cast<const char*>(&this->count), sizeof(this->count));
    out.write(reinterpret_cast<const char*>(&this->capacity), sizeof(this->capacity));
    out.write(reinterpret_cast<const char*>(&this->currentId), sizeof(currentId));

    for (size_t i = 0; i < count; i++)
    {
        if (components)
        {
            this->components[i]->save(out);
        }
    }
}

void AreaHub::load(std::ifstream &in)
{
    Component::loadBase(in);

    in.read(reinterpret_cast<char*>(&this->count), sizeof(this->count));
    in.read(reinterpret_cast<char*>(&this->capacity), sizeof(this->capacity));
    in.read(reinterpret_cast<char*>(&this->currentId), sizeof(currentId));

    for (size_t i = 0; i < count; i++)
    {
        if (components)
        {
            this->components[i]->load(in);
        }
    }
}

const char *AreaHub::status() const
{
    char buffer[1024];
    const char* delimiter = "#";

    for (size_t i = 0; i < count; i++)
    {
        strcat(buffer, this->components[i]->status());
        strcat(buffer, delimiter);
    }
}

AreaHub *AreaHub::clone() const
{
    return new AreaHub(*this);
}

void AreaHub::operator+(const Component &component)
{
    
}

void AreaHub::free()
{
    if (components)
    {
        for (size_t i = 0; i < count; i++)
        {
            delete this->components[i];
            this->components[i] = nullptr;
        }
    }
    
    delete[] this->components;
}
