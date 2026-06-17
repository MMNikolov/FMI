#include "FileDataSource.hpp"

template <typename T>
inline FileDataSource<T>::FileDataSource(const char *filename)
{
    if (!filename)
    {
        throw std::invalid_argument("The filename cannot be empty");
    }

    this->filename = new char[strlen(filename) + 1];
    strcpy(this->filename, filename);

    this->file.open(this->filename);
    if (!this->file.is_open())
    {
        throw std::runtime_error("Could not open file");
    }
}

template <typename T>
inline FileDataSource<T>::FileDataSource(const FileDataSource<T> &other)
{
    copyFrom(other);
}

template <typename T>
inline FileDataSource<T> &FileDataSource<T>::operator=(const FileDataSource<T> &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }

    return *this;
}

template <typename T>
inline FileDataSource<T>::~FileDataSource()
{
    free();
}

template <typename T>
inline T FileDataSource<T>::takeNext()
{
    T element;
    if (this->hasNext())
    {
        this->file >> element;
    }
    else
    {
        element = T();
    }

    return element;
}

template <typename T>
inline T *FileDataSource<T>::takeNextFew(int few, int &extractedCount)
{
    T* arr = new T[few];
    extractedCount = 0;

    for (int i = 0; i < few; i++)
    {
        if (this->hasNext())
        {
            this->file >> arr[i];
            extractedCount++;
        }
        else
        {
            break;
        }
    }   
    
    if (extractedCount == 0)
    {
        delete[] arr;
        arr = nullptr;
    }
    
    return arr;
}

template <typename T>
inline bool FileDataSource<T>::hasNext() const
{
    std::ifstream& nonConstFile = const_cast<std::ifstream&>(this->file);
    nonConstFile >> std::ws;
    return !nonConstFile.eof();
}

template <typename T>
inline bool FileDataSource<T>::reset()
{
    if (this->file.is_open())
    {
        this->file.close();
    }
    this->file.clear(); // Изчистваме error флаговете (напр. EOF)
    this->file.open(this->filename); // Отваряме го наново от самото начало

    return this->file.is_open();
}

template <typename T>
inline void FileDataSource<T>::free()
{
    delete[] this->filename;
    this->filename = nullptr;
    if (this->file.is_open())
    {
        this->file.close();
    }
}

template <typename T>
inline void FileDataSource<T>::copyFrom(const FileDataSource<T> &other)
{
    this->filename = new char[strlen(other.filename) + 1];
    strcpy(this->filename, other.filename);

    this->file.open(this->filename);
}