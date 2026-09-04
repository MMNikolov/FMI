#include "Car.hpp"
#include <cstring>
#include <stdexcept>

// Static member definitions live in the .cpp -- same rule you already
// know from the theory test (Q43): defining this in the header would
// cause a multiple-definition linker error the moment more than one
// .cpp includes it.
unsigned Car::totalHorsePower = 0;

Car::Car()
    : model(nullptr), dateOfManufacture(1, 1, 1970), trunk(nullptr), 
    horsePower(0), seats(0)
{}

Car::Car(const char *model, const Date &date, const char *trunk, unsigned horsePower, unsigned seats)
    : model(nullptr), dateOfManufacture(date), trunk(validateTrunk(trunk)),
      horsePower(horsePower), seats(seats)
{
    // FIXED: checking the PARAMETER `model`, not `this->model`.
    // `this->model` was just set to nullptr one line above -- checking
    // it would always be true regardless of what the caller passed in,
    // which is exactly the bug from before.
    if (!model)
    {
        throw std::invalid_argument("Model isnt written down");
    }

    this->model = new char[strlen(model) + 1];
    // REMOVED the `if (!this->model) throw std::bad_alloc();` check here --
    // same reason as with Book: `new` throws on failure, it doesn't
    // return null, so that check could never fire.
    strcpy(this->model, model);

    totalHorsePower += horsePower;   // a new live Car exists now
}

Car::Car(std::istream& in)
    : model(nullptr), dateOfManufacture(1, 1, 1970), trunk(nullptr), horsePower(0), seats(0)
    // dateOfManufacture/trunk get temporary placeholder values here --
    // they're properly overwritten below once we've actually read the
    // real data. Date has no default constructor (by design, same as
    // Book/ISBN), so SOME valid value has to go in the init list.
{
    // NOTE: this simple version reads `model` as a single whitespace-free
    // token. If your model names can contain spaces, you'd need to switch
    // this to a getline-based format that matches whatever print() writes.
    char modelBuf[256];
    in >> modelBuf;
    this->model = new char[strlen(modelBuf) + 1];
    strcpy(this->model, modelBuf);

    char dateBuf[11];
    in >> dateBuf;
    this->dateOfManufacture = Date(dateBuf);

    char trunkBuf[32];
    in >> trunkBuf;
    this->trunk = validateTrunk(trunkBuf);

    in >> this->horsePower >> this->seats;

    totalHorsePower += horsePower;
}

Car::Car(const Car& other)
    : model(nullptr), dateOfManufacture(other.dateOfManufacture), trunk(other.trunk),
      horsePower(other.horsePower), seats(other.seats)
{
    this->model = new char[strlen(other.model) + 1];
    strcpy(this->model, other.model);

    totalHorsePower += horsePower;   // another live Car now exists
}

Car& Car::operator=(const Car& other)
{
    if (this != &other)
    {
        char* tempModel = new char[strlen(other.model) + 1];
        strcpy(tempModel, other.model);
        // build everything first, THEN commit -- same safe pattern as Book::operator=

        totalHorsePower = totalHorsePower - this->horsePower + other.horsePower;
        // No object is being created or destroyed here -- THIS object already
        // existed. Only ITS contribution to the shared total changes: remove
        // what it used to contribute, add what it contributes now.

        free();
        this->model = tempModel;
        this->dateOfManufacture = other.dateOfManufacture;
        this->trunk = other.trunk;
        this->horsePower = other.horsePower;
        this->seats = other.seats;
    }
    return *this;
}

Car::~Car()
{
    totalHorsePower -= horsePower;   // this Car is about to stop existing
    free();
}

void Car::free()
{
    delete[] this->model;
    // trunk is NOT deleted here -- it never owned anything, it always
    // points at a string literal (see validateTrunk below).
}

void Car::print(std::ostream& out) const
{
    out << model << " ";
    dateOfManufacture.print(out);
    out << " " << trunk << " " << horsePower << " " << seats;
}

const char* validateTrunk(const char* trunk)
{
    if (!trunk)
    {
        throw std::invalid_argument("Trunk type not given");
    }

    // strcmp checks the FULL string including the terminator -- fixes the
    // earlier bug where "Sedanish" would have incorrectly passed as "Sedan"
    if (strcmp(trunk, "Sedan") == 0)     return "Sedan";
    if (strcmp(trunk, "Kombi") == 0)     return "Kombi";
    if (strcmp(trunk, "Hatchback") == 0) return "Hatchback";

    // FIXED: this used to silently return nullptr for an invalid value.
    // Now it throws, so an invalid trunk type actually gets rejected
    // instead of quietly producing a broken Car.
    throw std::invalid_argument("Trunk type must be Sedan, Kombi, or Hatchback");
}