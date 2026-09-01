#include <stdio.h>
#include <stdlib.h>
#define STARTING_CAPACITY 4

int* readNumbers(int* outCount);
int grow(int** arr, int* outCapacity);
void printArray(int* arr, int itterations);
void insertionSort(int** arr, int count);
int binarySearch(int* arr, int size, int n);

int main()
{
    int n = 0;
    int* arr = readNumbers(&n);

    printArray(arr, n);
    insertionSort(&arr, n);
    printArray(arr, n);
    int res = binarySearch(arr, n, 10);
    printf("On what position is 10 in the array: %d", res);

    return 0;
}

int *readNumbers(int *outCount)
{
    int capacity = STARTING_CAPACITY;
    (*outCount) = 0;

    int* arr = (int*)malloc(sizeof(int) * capacity);
    if (!arr)
    {
        return NULL;
    }
    
    int n, flag;
    do
    {
        if ((*outCount) + 1 >= capacity)
        {
            flag = grow(&arr, &capacity);
            if (!flag)
            {
                return NULL;
            }
        }
        
        if (scanf("%d", &n) != 1)
        {
            free(arr);
            return NULL;
        }
        
        if (n != 0)
        {
            arr[(*outCount)++] = n;
        }
        
    } while (n != 0); 

    return arr;
}

int grow(int **arr, int* outCapacity)
{
    int* temp = (int*)malloc(sizeof(int) * (*outCapacity) * 2);
    if (!temp)
    {
        free(*arr);
        return 0;
    }
    
    for (int i = 0; i < (*outCapacity); i++)
    {
        temp[i] = (*arr)[i];
    }
    
    free(*arr);
    *arr = temp;
    (*outCapacity) *= 2;

    return 1;
}

void printArray(int *arr, int itterations)
{
    if (!arr)
    {
        return;
    }
    
    for (int i = 0; i < itterations; i++)
    {
        printf("[%d]", arr[i]);
    }
    puts(" ");
}

void insertionSort(int **arr, int count)
{
    for (size_t i = 0; i < count; i++)
    {
        int key = (*arr)[i];
        int j = i - 1;

        while (j >= 0 && (*arr)[j] > key)
        {
            (*arr)[j + 1] = (*arr)[j];
            j = j - 1;
        }

        (*arr)[j + 1] = key;
    }
    
}

int binarySearch(int* arr, int size, int n)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == n)
        {
            return mid;
        } 
        else if (arr[mid] <= n)
        {
            low = mid + 1;
        }
        else if (arr[mid] >= n)
        {
            high = mid - 1;
        }
    }

    return -1;
};
