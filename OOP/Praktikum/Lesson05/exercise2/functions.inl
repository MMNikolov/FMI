template<typename T>
void init(MyArray<T>*& arr)
{
    int randomNum;
    for (unsigned int i = 0; i < n1; i++)
    {
        randomNum = rand() % 100;
        arr->set[i] = randomNum; 
    }
}

template<typename T>
bool contains(MyArray<T>*& arr, T element)
{
    for (unsigned int i = 0; i < n1; i++)
    {
        if (arr.set[i] == element)
        {
            return true;
        }
    }
    return false;
};

template<typename T>
bool add(MyArray<T>*& arr, T element)
{
    if (n1 < ARR_SIZE)
    {
        arr.set[n1] = element;
        n1++;
        return true;
    }
    return false;
};

template<typename T>
bool remove(MyArray<T>*& arr, T element)
{
    int index = -1;
    for (unsigned int i = 0; i < n1; i++)
    {
        if (arr.set[i] == element)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        return false;
    }
    
    for (unsigned int i = index; i < n1; i++)
    {
        arr.set[i] = arr.set[i + 1];
    }
    return true;
};

template<typename T>
bool count(MyArray<T>*& arr)
{
    unsigned int count;
};

template<typename T>
T getAt(const unsigned int index);

template<typename T>
void print(const MyArray<T>*& arr)
{
    for (unsigned int i = 0; i < n1; i++)
    {
        std::cout << "[" << arr.set[i] << "]";
    }
    std::cout << "\n";
};