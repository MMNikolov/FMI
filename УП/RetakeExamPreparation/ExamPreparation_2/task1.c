#include <stdio.h>
#include <stdlib.h>

// void resize(unsigned* arr, unsigned* n);
unsigned gcd(unsigned num1, unsigned num2);
// void shiftElementToRight(unsigned* arr, unsigned k, unsigned n);

int main()
{
    unsigned n;
    if (scanf("%u", &n) != 1)
    {
        return 1;
    }

    // we are allocating the worst case scenario
    unsigned *arr = (int *)malloc(sizeof(int) * n);
    if (!arr)
    {
        return 1;
    }

    for (unsigned i = 0; i < n; i++)
    {
        if (scanf("%u", &arr[i]) != 1)
        {
            return 1;
        }
    }

    unsigned *buffer = (int *)malloc(sizeof(int) * n * 2);
    if (!buffer)
    {
        return 1;
    }

    // this will be the pointer for the buffer
    int p = 0, num, counter = 0;
    for (unsigned i = 0; i < n; i++)
    {
        if (i == 0)
        {
            buffer[p++] = arr[0];
        }
        else if (i + 1 == n)
        {
            if (arr[i - 1] % arr[i] == 0 || arr[i] % arr[i - 1] == 0)
            {
                buffer[p++] = arr[i];
            }
            else if (arr[i - 1] % arr[i] != 0 && arr[i] % arr[i - 1] != 0)
            {
                num = gcd(arr[i - 1], arr[i]);
                buffer[p++] = num;
                buffer[p++] = arr[i];
                counter++;
            }
        }
        else
        {
            if ((arr[i - 1] % arr[i] == 0 || arr[i] % arr[i - 1] == 0) || (arr[i] % arr[i + 1] == 0 || arr[i + 1] % arr[i] == 0))
            {
                buffer[p++] = arr[i];
            }
            else if ((arr[i - 1] % arr[i]) != 0 && (arr[i] % arr[i + 1] != 0))
            {
                num = gcd(arr[i - 1], arr[i]);
                buffer[p++] = num;
                buffer[p++] = arr[i];
                counter++;
            }
            else if ((arr[i] % arr[i + 1]) != 0 && (arr[i + 1] % arr[i]) != 0)
            {
                num = gcd(arr[i + 1], arr[i]);
                buffer[p++] = arr[i - 1];
                buffer[p++] = num;
                counter++;
            }
        }
    }

    for (unsigned i = 0; i < n + counter; i++)
    {
        printf("[%u]", buffer[i]);
    }

    free(arr);
    free(buffer);
    return 0;
}

// void resize(unsigned* arr, unsigned* n)
// {
//     (*n) *= 2;
//     int* array = (int*)realloc(arr, sizeof(int) * (*n));
//     if (!array)
//     {
//         free(arr);
//         return;
//     }

//     arr = array;
// }

unsigned gcd(unsigned num1, unsigned num2)
{
    while (num2 != 0)
    {
        unsigned temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }

    return num1;
}

// void shiftElementToRight(unsigned *arr, unsigned k, unsigned n)
// {
//     for (unsigned i = k; i < n; i++)
//     {
//         arr[i] = arr[i + 1];
//     }

// }
