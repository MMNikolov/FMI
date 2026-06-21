#include "AreaHub.hpp"

AreaHub::AreaHub(const char *tag, const char *location, size_t capacity)
    : Component(tag, location), count(0), currentId(-1), capacity(capacity)
{
    this->components = new Component *[capacity];
    for (size_t i = 0; i < capacity; i++)
    {
        this->components[i] = nullptr;
    }
}

AreaHub::AreaHub(const AreaHub &other)
    : Component(other), count(other.count), currentId(other.currentId), capacity(other.capacity)
{
    this->components = new Component *[other.capacity];
    for (size_t i = 0; i < this->capacity; i++)
    {
        this->components[i] = nullptr;
    }

    try
    {
        for (size_t i = 0; i < other.count; i++)
        {
            this->components[i] = other.components[i]->clone();
        }
    }
    catch (const std::exception &e)
    {
        // we free the memory and we rethrow the exception
        free();
        std::cerr << e.what() << '\n';
        throw;
    }
}

AreaHub &AreaHub::operator=(const AreaHub &other)
{
    if (this != &other)
    {
        AreaHub temp(other);

        Component::operator=(other);

        std::swap(this->components, temp.components);
        std::swap(this->count, temp.count);
        std::swap(this->capacity, temp.capacity);
    }

    return *this;
}

AreaHub::~AreaHub()
{
    free();
}

void AreaHub::render(std::ostream &out) const
{
    out << "[AreaHub] ID: " << id << ", Tag: " << tag
        << ", Location: " << location << ", Active: " << (active ? "Yes" : "No") << "\n";
    out << "  --- Inner Components (" << count << "/" << capacity << ") ---\n";
    for (size_t i = 0; i < count; i++)
    {
        if (components[i])
        {
            out << "    ";
            components[i]->render(out);
        }
    }
}

void AreaHub::resize()
{
    size_t newCapacity = this->capacity * 2;
    Component **newComp = new Component *[newCapacity];

    for (size_t i = 0; i < newCapacity; i++)
    {
        newComp[i] = nullptr;
    }

    for (size_t i = 0; i < this->count; i++)
    {
        newComp[i] = this->components[i];
    }

    delete[] this->components;

    this->components = newComp;
    this->capacity = newCapacity;
}

void AreaHub::save(std::ofstream &out) const
{
    Component::saveBase(out);
    out.write(reinterpret_cast<const char *>(&this->count), sizeof(this->count));
    out.write(reinterpret_cast<const char *>(&this->capacity), sizeof(this->capacity));

    for (size_t i = 0; i < count; i++)
    {
        if (components[i])
        {
            int typeId = components[i]->getTypeID();
            out.write(reinterpret_cast<const char *>(&typeId), sizeof(typeId));
            components[i]->save(out);
        }
    }
}

void AreaHub::load(std::ifstream &in)
{
    Component::loadBase(in);
    size_t newCount, newCapacity;
    in.read(reinterpret_cast<char *>(&newCount), sizeof(newCount));
    in.read(reinterpret_cast<char *>(&newCapacity), sizeof(newCapacity));

    Component **newComp = new Component *[newCapacity];
    for (size_t i = 0; i < newCapacity; i++)
        newComp[i] = nullptr;

    try
    {
        for (size_t i = 0; i < newCount; i++)
        {
            int typeId = 0;
            in.read(reinterpret_cast<char *>(&typeId), sizeof(typeId));

            // В зависимост от прочетения тип разпределяме паметта полиморфно
            if (typeId == 1)
                newComp[i] = new StaticDisplay("dummy", "dummy");
            else if (typeId == 2)
                newComp[i] = new ThermostatImput("dummy", "dummy", 0, -50, 100);
            else if (typeId == 4)
                newComp[i] = new AreaHub("dummy", "dummy", 100);
            else if (typeId == 5)
                newComp[i] = new ActionActuator("dummy", "dummy", nullptr, this);

            if (newComp[i])
                newComp[i]->load(in);
        }
    }
    catch (...)
    {
        for (size_t i = 0; i < newCapacity; i++)
            delete newComp[i];
        delete[] newComp;
        throw;
    }

    free();
    this->components = newComp;
    this->count = newCount;
    this->capacity = newCapacity;
}

const char *AreaHub::status() const
{
    size_t totalLen = 0;
    const char **tempStrings = new const char *[count];

    // 1. Събираме междинните статуси и смятаме точната дължина
    for (size_t i = 0; i < count; i++)
    {
        tempStrings[i] = components[i]->status();
        totalLen += strlen(tempStrings[i]) + 1; // статус + '#'
    }

    char *finalBuffer = new char[totalLen + 1];
    finalBuffer[0] = '\0';

    // 2. Конкатенираме и задължително трием заделената от децата памет
    for (size_t i = 0; i < count; i++)
    {
        strcat(finalBuffer, tempStrings[i]);
        strcat(finalBuffer, "#");
        delete[] tempStrings[i]; // Спираме теча на памет тук!
    }

    delete[] tempStrings;
    return finalBuffer;
}

AreaHub *AreaHub::clone() const
{
    return new AreaHub(*this);
}

void AreaHub::SetActive(bool activeState)
{
    Component::SetActive(activeState);
    for (size_t i = 0; i < count; i++)
    {
        if (components[i])
        {
            components[i]->SetActive(activeState);
        }
    }
}

void AreaHub::operator+(const Component &component)
{
    IsActive();
    for (size_t i = 0; i < count; i++)
    {
        if (components[i] && components[i]->GetId() == component.GetId())
        {
            throw std::invalid_argument("Duplicate ID identifier detected");
        }
    }
    if (this->count >= this->capacity)
    {
        resize();
    }
    this->components[this->count++] = component.clone();
}

void AreaHub::operator-(unsigned id)
{
    IsActive();
    int target = -1;
    for (size_t i = 0; i < count; i++)
    {
        if (components[i] && components[i]->GetId() == id)
        {
            target = static_cast<int>(i);
            break;
        }
    }
    if (target == -1)
        return;

    delete this->components[target];
    for (size_t i = target; i < count - 1; i++)
    {
        this->components[i] = this->components[i + 1];
    }
    this->components[count - 1] = nullptr;
    this->count--;
}

Component *AreaHub::operator[](unsigned id)
{
    for (size_t i = 0; i < count; i++)
    {
        if (components[i] && components[i]->GetId() == id)
            return components[i];
    }
    return nullptr;
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
