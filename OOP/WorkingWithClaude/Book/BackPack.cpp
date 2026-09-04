#include "BackPack.hpp"

BackPack::BackPack(float weightCapacity)
    : count(0), currentWeight(0), capacity(2), weightCapacity(weightCapacity)
{
    this->books = new Book *[capacity];
}

BackPack::~BackPack()
{
    free();
}

BackPack::BackPack(const BackPack &other)
    : weightCapacity(other.weightCapacity)
{
    copyFrom(other);
}

BackPack &BackPack::operator=(const BackPack &other)
{
    if (this != &other)
    {
        free();
        this->count = other.count;
        this->capacity = other.capacity;
        this->currentWeight = other.currentWeight;

        this->books = new Book *[capacity];
        for (size_t i = 0; i < count; i++)
        {
            this->books[i] = new Book(*(other.books[i]));
        }
    }

    return *this;
}

bool BackPack::addBook(const Book &book)
{
    if (book.getWeight() + this->currentWeight >= weightCapacity)
    {
        return false;
    }
    if (this->count >= capacity)
    {
        grow();
    }

    books[count++] = new Book(book);
    currentWeight += book.getWeight();

    return true;
}

void BackPack::copyFrom(const BackPack &other)
{
    this->count = other.count;
    this->capacity = other.capacity;
    this->currentWeight = other.currentWeight;
    books = new Book *[capacity];
    for (unsigned i = 0; i < count; i++)
    {
        books[i] = new Book(*(other.books[i]));
    }
}

void BackPack::grow()
{
    this->capacity = (capacity == 0) ? 2 : capacity * 2;
    Book **newBooks = new Book *[capacity];

    for (unsigned i = 0; i < count; i++)
    {
        newBooks[i] = this->books[i];
    }

    delete[] books;
    books = newBooks;
}

// I dont know what kind of shifting method I should do so I will just do 0(1) shifting
bool BackPack::removeBook(const ISBN &isbn)
{
    if (this->count <= 0)
    {
        throw std::invalid_argument("We dont have any books in this backpack :D");
    }

    for (unsigned i = 0; i < count; i++)
    {
        if (books[i]->getISBN() == isbn)
        {
            this->currentWeight -= books[i]->getWeight();

            delete books[i];

            for (size_t j = i; j < count - 1; j++)
            {
                books[j] = books[j + 1];
            }
            this->count--;
            return true;
        }
    }

    return false;
}

void BackPack::saveToFile(const char *filename) const
{
    if (!filename)
    {
        throw std::invalid_argument("this filename doesnt exist");
    }

    std::ofstream out(filename, std::ios::binary);
    if (!out.is_open())
    {
        throw std::invalid_argument("Cant open the file :D");
    }

    out.write(reinterpret_cast<const char *>(&this->count), sizeof(count));
    for (unsigned i = 0; i < count; i++)
    {
        int titleLength = strlen(this->books[i]->getName()) + 1;
        out.write(reinterpret_cast<const char *>(&titleLength), sizeof(titleLength));
        out.write(reinterpret_cast<const char *>(this->books[i]->getName()), titleLength);

        int authorLength = strlen(this->books[i]->getAuthor()) + 1;
        out.write(reinterpret_cast<const char *>(&authorLength), sizeof(authorLength));
        out.write(reinterpret_cast<const char *>(this->books[i]->getAuthor()), authorLength);

        float weight = books[i]->getWeight();
        out.write(reinterpret_cast<const char *>(&weight), sizeof(weight));

        // out.write(books[i]->getISBN(), 14);
    }

    out.close();
}

void BackPack::loadFromFile(const char *filename)
{
    if (!filename)
    {
        throw std::invalid_argument("this filename doesnt exist");
    }

    std::ifstream in(filename, std::ios::binary);
    if (!in.is_open())
    {
        throw std::invalid_argument("Cant open the file :D");
    }

    float savedCapacity;
    in.read(reinterpret_cast<char *>(&savedCapacity), sizeof(savedCapacity));

    // weightCapacity is const -- can't SET it here, only check it. If this
    // object wasn't constructed with the same capacity the file was saved
    // with, there's no legitimate way to load it into this specific object.
    if (savedCapacity != weightCapacity)
    {
        throw std::invalid_argument("Saved backpack's weight capacity doesn't match this one");
    }

    // Clear out whatever this backpack currently holds -- loadFromFile
    // REPLACES the contents, it doesn't merge with what's already there.
    free();
    books = nullptr;
    count = 0;
    capacity = 0;      // must reset this too, not just books -- otherwise the
    currentWeight = 0; // first addBook below won't know it needs to grow()

    unsigned savedCount;
    in.read(reinterpret_cast<char *>(&savedCount), sizeof(savedCount));

    for (unsigned i = 0; i < savedCount; i++)
    {
        int titleLength;
        in.read(reinterpret_cast<char *>(&titleLength), sizeof(titleLength));
        char *name = new char[titleLength];
        in.read(name, titleLength);

        int authorLength;
        in.read(reinterpret_cast<char *>(&authorLength), sizeof(authorLength));
        char *author = new char[authorLength];
        in.read(author, authorLength);

        float weight;
        in.read(reinterpret_cast<char *>(&weight), sizeof(weight));

        ISBN isbn = ISBN::read(in);

        Book book(name, author, weight, isbn);
        addBook(book);

        delete[] name;
        delete[] author;
    }
}

void BackPack::free()
{
    for (unsigned i = 0; i < count; i++)
    {
        delete this->books[i];
    }

    delete[] this->books;
}
