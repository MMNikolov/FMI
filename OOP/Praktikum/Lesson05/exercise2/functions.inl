template <typename T>
void init(MyArray<T> *&arr)
{
    int randomNum;
    for (unsigned int i = 0; i < arr->currentSize; i++)
    {
        randomNum = rand() % 100;
        arr->set[i] = randomNum;
    }
}

template <typename T>
bool contains(const MyArray<T> *arr, T element) 
{
    if (!arr) return false;

    for (unsigned int i = 0; i < arr->currentSize; i++)
    {
        if (arr->set[i] == element)
        {
            return true;
        }
    }
    return false;
}

template <typename T>
bool add(MyArray<T> *&arr, T element)
{
    if (contains(arr, element))
    {
        return false;
    }
    
    if (arr->currentSize < ARR_SIZE)
    {
        arr->set[arr->currentSize] = element;
        arr->currentSize++;
        return true;
    }
    return false;
};

template <typename T>
bool remove(MyArray<T> *arr, T element)
{
    int index = -1;
    for (unsigned int i = 0; i < arr->currentSize; i++)
    {
        if (arr->set[i] == element)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
        return false;

    for (unsigned int i = index; i < arr->currentSize - 1; i++)
    {
        arr->set[i] = arr->set[i + 1];
    }
    arr->currentSize--;
    return true;
}

// I am not going to use this as I implemented currentSize inside the struct
template <typename T>
bool count(MyArray<T> *&arr)
{
    return true;
};

template <typename T>
T getAt(MyArray<T> *&arr, const unsigned int index)
{
    return arr->set[index];
};

template <typename T>
void print(const MyArray<T> *arr)
{
    for (unsigned int i = 0; i < arr->currentSize; i++)
    {
        std::cout << "[" << arr->set[i] << "]";
    }
    std::cout << "\n";
};

//---------------------------------------------

template <typename T>
MyArray<T> *Intersect(MyArraysss<T>& sets)
{
    MyArray<T> *result = new (std::nothrow) MyArray<T>;
    if (!result)
    {
        std::cerr << "There was a problem with the memory allocation in the Intersect";
        return {};
    }

    for (unsigned int i = 0; i < sets.arrays[0].currentSize; i++)
    {
        T candidate = sets.arrays[0].set[i];
        bool foundInAll = true;

        for (unsigned int j = 1; j < MAX_ARRS_IN_ARR; j++)
        {
            if (sets.arrays[j].currentSize == 0)
            {
                continue;
            }
            

            if (!contains(&(sets.arrays[j]), candidate))
            {
                foundInAll = false;
                break;
            }
        }

        if (foundInAll)
        {
            add(result, candidate);
        }
    }
    return result;
}

template <typename T>
MyArray<T> *Union(MyArraysss<T>& sets)
{
    MyArray<T> *result = new (std::nothrow) MyArray<T>;
    if (!result)
        return nullptr;

    for (unsigned int i = 0; i < MAX_ARRS_IN_ARR; i++)
    {
        for (unsigned int j = 0; j < sets.arrays[i].currentSize; j++)
        {
            add(result, sets.arrays[i].set[j]);
        }
    }

    return result;
}