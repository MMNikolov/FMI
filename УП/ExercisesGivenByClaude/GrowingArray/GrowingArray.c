#include <stdio.h>
#include <stdlib.h>
#define STARTIN_CAPACITY 4

int* readUntilZero(int* outCount);
int grow(int** arr, int* outCapacity);

int main()
{
    int outCount = 0;
    int* arr = readUntilZero(&outCount);

    printf("%d", outCount);
    for (int i = 0; i < outCount; i++)
    {
        printf("[%d]", arr[i]);
    }
    
    free(arr);
    return 0;
}

int *readUntilZero(int *outCount)
{
    *outCount = 0;
    int capacity = STARTIN_CAPACITY;
    int* arr = (int*)malloc(sizeof(int) * capacity);
    if (arr == NULL)
    {
        puts("Incorrect array allocation");
        return 0;
    }

    int num, flag;
    while (1)
    {
        if ((*outCount) + 1 >= capacity)
        {
            flag = grow(&arr, &capacity);
            if (flag == 0)
            {
                return arr;
            }
        }
        
        if (scanf("%d", &num) != 1)
        {
            puts("Must input a number one at a time");
            return arr;
        }

        if (num == 0)
        {
            return arr;
        }

        arr[(*outCount)] = num;
        (*outCount)++;
    }
}

int grow(int **arr, int* outCapacity)
{
    int* temp = realloc(*arr, sizeof(int) * (*outCapacity) * 2);
    if (temp == NULL)
    {
        puts("The realloc didnt do its job :(");
        return NULL;
    }
    
    *outCapacity *= 2;
    *arr = temp;
    return 1;
}
