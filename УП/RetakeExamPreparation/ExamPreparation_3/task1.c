#include <stdio.h>
#include <stdlib.h>

unsigned isPrime(unsigned num1);
unsigned NOK(unsigned num1, unsigned num2);
void readArr(unsigned *arr, unsigned n);
void insertionSort(unsigned *arr, unsigned count);
int binarySearch(unsigned *arr, unsigned count, unsigned target);

int main()
{
    unsigned n;
    if (scanf("%u", &n) != 1)
    {
        return 1;
    }

    unsigned *arr = (unsigned *)malloc(sizeof(unsigned) * n);
    if (!arr)
    {
        return 1;
    }

    readArr(arr, n);

    // for the worst case scenario
    unsigned *buffer = (unsigned *)malloc(sizeof(unsigned) * n * 2);
    if (!buffer)
    {
        free(arr);
        return 1;
    }

    int p = 0, counter = 0;
    for (unsigned i = 0; i < n; i++)
    {
        if (i == 0)
        {
            // addition is commutative so we can check only once
            if (isPrime(arr[i] + arr[i + 1]))
            {
                buffer[p++] = arr[i];
            }
            else
            {
                buffer[p++] = arr[i];
                buffer[p++] = NOK(arr[i], arr[i + 1]);
                counter++;
            }
        }
        else if ((i + 1) >= n)
        {
            buffer[p] = arr[i];
        }
        else
        {
            if (isPrime(arr[i] + arr[i - 1]) || isPrime(arr[i] + arr[i + 1]))
            {
                buffer[p++] = arr[i];
            }
            else
            {
                buffer[p++] = arr[i];
                buffer[p++] = NOK(arr[i], arr[i + 1]);
                counter++;
            }
        }
    }

    for (unsigned i = 0; i < n + counter; i++)
    {
        printf("[%d]", buffer[i]);
    }

    puts(" ");
    puts("-------AFTER INSERTION SORT-----------");
    insertionSort(&buffer, n + counter);
    for (unsigned i = 0; i < n + counter; i++)
    {
        printf("[%d]", buffer[i]);
    }
    puts(" ");
    puts("-------- AFTER BINARY SEARCH-----------");
    printf("%u", binarySearch(buffer, n + counter, 7));

    free(buffer);
    free(arr);
    return 0;
}

unsigned isPrime(unsigned num1)
{
    if (num1 == 0 || num1 == 1)
    {
        return 0;
    }
    else if (num1 == 2 || num1 == 3)
    {
        return 1;
    }

    for (unsigned i = 2; i * i <= num1; i++)
    {
        if (num1 % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

unsigned GCD(unsigned a, unsigned b)
{
    while (b != 0)
    {
        unsigned temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

unsigned NOK(unsigned a, unsigned b)
{
    if (a == 0 || b == 0)
    {
        return 0;
    }

    return (a / GCD(a, b) * b);
}

void readArr(unsigned *arr, unsigned n)
{
    if (n == 0)
    {
        return;
    }

    for (unsigned i = 0; i < n; i++)
    {
        if (scanf("%u", &arr[i]) != 1)
        {
            return;
        }
    }
}

void insertionSort(unsigned *arr, unsigned count)
{
    if (count == 0)
    {
        return;
    }

    for (unsigned i = 1; i < count; i++)
    {
        unsigned key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
}

int binarySearch(unsigned *arr, unsigned count, unsigned target)
{
    if (count == 0)
    {
        return 0;
    }

    int mid = 0;

    int low = 0;
    int high = count - 1;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}
