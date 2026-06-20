#ifndef AREA_HUB_HPP
#define AREA_HUB_HPP

#include "Component.hpp"

class AreaHub : public Component
{
public:
    AreaHub(const char* tag, const char* location, size_t capacity);

    AreaHub(const AreaHub& other);
    AreaHub& operator=(const AreaHub& other);

    ~AreaHub();

    //overriden methods
    void render(std::ostream& out) const override;
    void save(std::ofstream& out) const override;
    void load(std::ifstream& in) override;
    const char* status() const override;
    AreaHub* clone() const override;

    //methods
    void operator+(const Component& component);
    void operator-(unsigned id);
    Component operator[](unsigned id);

    //getters
    size_t GetCount() const { return this->count; }
    size_t GetCapacity() const { return this->capacity; }
    int GetCurrentId() const { return this->currentId; }

private:
    Component** components;
    size_t count;
    size_t capacity;
    int currentId;

private:
    void free();
};

#endif // AREA_HUB_HPP