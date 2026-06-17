#ifndef FILE_DATA_SOURCE_HPP
#define FILE_DATA_SOURCE_HPP

#include "DataSource.hpp"

template <typename T>
class FileDataSource : public DataSource<T>
{
public:
    FileDataSource(const char* filename);

    FileDataSource(const FileDataSource<T>& other);
    FileDataSource& operator=(const FileDataSource<T>& other);

    ~FileDataSource();

    //overriden methods
    T takeNext() override;
    T* takeNextFew(int few, int& extractedCount) override;
    bool hasNext() const override;
    bool reset() override;  

private:
    char* filename;
    std::ifstream file;

private:
    void free();
    void copyFrom(const FileDataSource<T>& other);
};

#include "FileDataSource.inl"

#endif // FILE_DATA_SOURCE_HPP


