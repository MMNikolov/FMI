template<typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
};

template<typename T>
void init(MyArray<T>& arr)
{
    int randomNum;
    for (unsigned int i = 0; i < n; i++)
    {
        randomNum = rand() % 100;
        arr.arr[i] = randomNum;   
    }
}

template<typename T>
void copy(MyArray<T>& arr, const MyArray<T>& other)
{
    for (unsigned int i = 0; i < n; i++)
    {
        arr.arr[i] = other.arr[i];
    }
}

template<typename T>
void add(MyArray<T>& arr, const T& element)
{
    if (n < ARR_SIZE) 
    {
        arr.arr[n] = element; 
        n++;                  
    }
}

template<typename T>
void remove(MyArray<T>& arr, int index)
{
    if (index < 0 || index >= n)
    {
        std::cerr << "Not in index range\n";
        return;
    }
  
    for (unsigned int i = index; i < n - 1; i++)
    {
        arr.arr[i] = arr.arr[i + 1];
    }
    n--;
}

template<typename T>
void reverse(MyArray<T>& arr)
{
    if (n <= 1)
    {
        std::cerr << "Not enough elements in the array to reverse";
        return;
    }
    int start = 0; int end = n - 1;
    while (start < end)
    {
        swap(arr.arr[start], arr.arr[end]);
        start++; end--;
    }
}

template<typename T>
void print(const MyArray<T>& arr)
{
    for (unsigned int i = 0; i < n; i++)
    {
        std::cout << "[" << arr.arr[i] << "]";
    }
    std::cout << "\n";
};