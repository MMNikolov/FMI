#include "SelectorSwitch.hpp"

SelectorSwitch::SelectorSwitch(const char *tag, const char *location)
    : Component(tag, location), count(0), currentIndex(-1)
{
    this->displays = new StaticDisplay *[MAX_DISPLAYS];
    for (int i = 0; i < MAX_DISPLAYS; i++)
    {
        this->displays[i] = nullptr;
    }
}

SelectorSwitch::SelectorSwitch(const SelectorSwitch &other)
    : Component(other), count(other.count), currentIndex(other.currentIndex)
{
    this->displays = new StaticDisplay *[MAX_DISPLAYS];
    for (int i = 0; i < MAX_DISPLAYS; i++)
    {
        this->displays[i] = nullptr;
    }

    try
    {
        for (size_t i = 0; i < this->count; i++)
        {
            if (other.displays[i])
            {
                this->displays[i] = other.displays[i]->clone();
            }
        }
    }
    catch (...)
    {
        free();
        throw;
    }
}

SelectorSwitch &SelectorSwitch::operator=(const SelectorSwitch &other)
{
    if (this != &other)
    {
        SelectorSwitch temp(other);

        Component::operator=(other); 

        std::swap(this->displays, temp.displays);
        std::swap(this->count, temp.count);
        std::swap(this->currentIndex, temp.currentIndex);
    }
    return *this;

    return *this;
}

SelectorSwitch::~SelectorSwitch()
{
    free();
}

void SelectorSwitch::free()
{
    if (this->displays)
    {
        for (size_t i = 0; i < count; i++)
        {
            delete this->displays[i];
            this->displays[i] = nullptr;
        }
        delete[] this->displays;
        this->displays = nullptr;
    }
    count = 0;
}

void SelectorSwitch::render(std::ostream &out) const
{
    out << "[SelectorSwitch] ID: " << id << ", Tag: " << tag
        << ", Location: " << location << ", Active: " << (active ? "Yes" : "No") << "\n";
    out << "  Attached Displays (" << count << "):\n";
    for (size_t i = 0; i < count; i++)
    {
        out << (currentIndex == static_cast<int>(i) ? "   -> " : "      ");
        if (displays[i])
            displays[i]->render(out);
    }
}

void SelectorSwitch::save(std::ofstream &out) const
{
    Component::saveBase(out);

    out.write(reinterpret_cast<const char *>(&count), sizeof(count));
    out.write(reinterpret_cast<const char *>(&currentIndex), sizeof(currentIndex));

    for (size_t i = 0; i < count; i++)
    {
        if (displays)
        {
            displays[i]->save(out);
        }
    }
}

void SelectorSwitch::load(std::ifstream &in)
{
    Component::loadBase(in);

    size_t newCount = 0;
    int newCurrentIndex = -1;
    in.read(reinterpret_cast<char *>(&newCount), sizeof(newCount));
    in.read(reinterpret_cast<char *>(&newCurrentIndex), sizeof(newCurrentIndex));

    StaticDisplay **newDisplays = new StaticDisplay *[MAX_DISPLAYS];
    for (int i = 0; i < MAX_DISPLAYS; i++)
        newDisplays[i] = nullptr;

    try
    {
        for (size_t i = 0; i < newCount; i++)
        {
            newDisplays[i] = new StaticDisplay("dummy", "dummy");
            newDisplays[i]->load(in);
        }
    }
    catch (...)
    {
        for (int i = 0; i < MAX_DISPLAYS; i++)
            delete newDisplays[i];
        delete[] newDisplays;
        throw;
    }

    free();
    this->displays = newDisplays;
    this->count = newCount;
    this->currentIndex = newCurrentIndex;
}

const char *SelectorSwitch::status() const
{
    if (currentIndex == -1 || currentIndex >= static_cast<int>(count) || !displays[currentIndex])
    {
        char *emptyStr = new char[1];
        emptyStr[0] = '\0';
        return emptyStr;
    }

    const char *selectedTag = displays[currentIndex]->GetTag();
    char *resultTag = new char[strlen(selectedTag) + 1];
    strcpy(resultTag, selectedTag);
    return resultTag;
}

bool SelectorSwitch::operator()(unsigned id)
{
    IsActive();
    for (size_t i = 0; i < count; i++)
    {
        if (displays[i] && displays[i]->GetId() == id)
        {
            this->currentIndex = static_cast<int>(i);
            return true;
        }
    }
    return false;
}

void SelectorSwitch::addDisplay(const StaticDisplay &display)
{
    IsActive();
    if (this->count >= MAX_DISPLAYS)
    {
        throw std::invalid_argument("Cant add more displays");
    }

    for (size_t i = 0; i < count; i++)
    {
        if (displays[i] && displays[i]->GetId() == display.GetId())
        {
            throw std::invalid_argument("Display with this ID already exists in the selector");
        }
    }

    this->displays[this->count++] = display.clone();
}

void SelectorSwitch::removeDisplay(unsigned id)
{
    IsActive();
    int targetIndex = -1;
    for (size_t i = 0; i < count; i++)
    {
        if (displays[i] && displays[i]->GetId() == id)
        {
            targetIndex = static_cast<int>(i);
            break;
        }
    }

    if (targetIndex == -1)
    {
        throw std::invalid_argument("Cant find a display with this ID");
    }

    delete this->displays[targetIndex];

    for (size_t i = targetIndex; i < count - 1; i++)
    {
        this->displays[i] = this->displays[i + 1];
    }
    this->displays[count - 1] = nullptr;
    this->count--;

    if (currentIndex == targetIndex)
    {
        currentIndex = -1; 
    }
    else if (currentIndex > targetIndex)
    {
        currentIndex--; 
    }
}

StaticDisplay &SelectorSwitch::operator[](size_t index)
{
    if (index >= this->count || !displays[index])
    {
        throw std::invalid_argument("Index out of bounds");
    }

    return *this->displays[index];
}
