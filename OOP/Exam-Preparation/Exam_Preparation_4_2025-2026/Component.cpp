#include "Component.hpp"

unsigned Component::GlobalId = 0;

Component::Component(const char *tag, const char *location)
    : id(Incrementer()), active(false)
{
    // we dont need validation for the location char*, because it said that IT CAN BE empty
    if (!tag)
    {
        throw std::invalid_argument("Cant have a tag that isnt there");
    }

    this->tag = new char[strlen(tag) + 1];
    strcpy(this->tag, tag);

    this->location = new (std::nothrow) char[strlen(location) + 1];
    if (!this->location)
    {
        delete[] this->tag;
        throw std::bad_alloc();
    }

    if (location)
        strcpy(this->location, location);
    else
        this->location[0] = '\0';
}

Component::Component(const Component &other)
    : id(other.id), active(other.active)
{
    this->tag = new char[strlen(other.tag) + 1];
    strcpy(this->tag, other.tag);

    this->location = new (std::nothrow) char[strlen(other.location) + 1];
    if (!this->location)
    {
        delete[] this->tag;
        throw std::bad_alloc();
    }
    strcpy(this->location, other.location);
}

Component &Component::operator=(const Component &other)
{
    if (this != &other)
    {
        char* newTag = new char[strlen(other.tag) + 1];
        strcpy(newTag, other.tag);

        char* newLocation = new (std::nothrow) char[strlen(other.location) + 1];
        if (!newLocation)
        {
            delete[] newTag;
            throw std::bad_alloc();
        }
        strcpy(newLocation, other.location);

        free();

        this->tag = newTag;
        this->location = newLocation;
        this->active = other.active;
    }

    return *this;
}

Component::~Component()
{
    free();
}

void Component::saveBase(std::ofstream &out) const
{
    out.write(reinterpret_cast<const char*>(&id), sizeof(id));

    unsigned tagLen = strlen(this->tag);
    out.write(reinterpret_cast<const char*>(&tagLen), sizeof(tagLen));
    out.write(this->tag, tagLen);

    unsigned locationLen = strlen(this->location);
    out.write(reinterpret_cast<const char*>(&locationLen), sizeof(locationLen));
    out.write(this->location, locationLen);

    out.write(reinterpret_cast<const char*>(&active), sizeof(active));
}

void Component::loadBase(std::ifstream &in)
{
    unsigned dummyId;
    in.read(reinterpret_cast<char*>(&dummyId), sizeof(dummyId));

    size_t tagLen = 0;
    in.read(reinterpret_cast<char*>(&tagLen), sizeof(tagLen));
    char* newTag = new char[tagLen + 1];
    in.read(newTag, tagLen);
    newTag[tagLen] = '\0';

    size_t locationLen = 0;
    in.read(reinterpret_cast<char*>(&locationLen), sizeof(locationLen));
    char* newLocation = new (std::nothrow) char[locationLen + 1];
    if (!newLocation)
    {
        delete[] newTag;
        throw std::bad_alloc();
    }
    in.read(newLocation, locationLen);
    newLocation[locationLen] = '\0';

    bool newActive;
    in.read(reinterpret_cast<char*>(&newActive), sizeof(newActive));

    delete[] this->tag;
    delete[] this->location;

    this->tag = newTag;
    this->location = newLocation;
    this->active = newActive;
}

void Component::free()
{
    delete[] this->tag;
    this->tag = nullptr;
    delete[] this->location;
    this->location = nullptr;
}
