#include <stdio.h>
#include <limits.h>
#define MAXN 100

unsigned int dist(unsigned int a, unsigned int b);
void read(unsigned int A[MAXN][MAXN], int rows, int cols);
void clearK(unsigned int A[][MAXN], int *rows, int cols, unsigned int K);

void print(unsigned int A[][MAXN], int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%u ", A[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    unsigned int A[MAXN][MAXN];
    int rows, cols;
    unsigned int K, maxPossible;

    printf("Redove: ");
    scanf("%d", &rows);
    printf("Koloni: ");
    scanf("%d", &cols);

    read(A, rows, cols);

    maxPossible = (unsigned int)(CHAR_BIT * sizeof(unsigned int)) * (unsigned int)cols;
    do
    {
        printf("K (0 do %u): ", maxPossible);
        scanf("%u", &K);
    } while (K > maxPossible);

    clearK(A, &rows, cols, K); // &rows — подаваме адрес, защото clearK иска int*

    printf("Rezultat:\n");
    print(A, rows, cols);

    return 0;
}

unsigned int dist(unsigned int a, unsigned int b)
{
    unsigned int diff = a ^ b; // 1 на всяка позиция, където A и B се различават
    unsigned int count = 0;
    for (; diff; diff >>= 1)
    {
        // >> е побитова операция, не аритметична — позволена
        if (diff & 1)
        {
            count++; // единствено + / ++, никакво -, *, /, %
        }
    }
    return count;
}

void read(unsigned int A[MAXN][MAXN], int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%u", &A[i][j]);
        }
    }
}

void clearK(unsigned int A[][MAXN], int *rows, int cols, unsigned int K)
{
    int toRemove[MAXN] = {0}; // 0 = false, 1 = true; няма bool в чист C89/C99 без stdbool.h
    int i, j, c, newRows;

    /* стъпка 1: маркирай всеки ред, участващ в поне 1 K-подобна двойка */
    for (i = 0; i < *rows; i++)
    {
        for (j = i + 1; j < *rows; j++)
        {
            unsigned int sum = 0;

            for (c = 0; c < cols; c++)
            {
                sum += dist(A[i][c], A[j][c]);
            }

            if (sum <= K)
            {
                toRemove[i] = 1;
                toRemove[j] = 1;
            }
        }
    }

    /* стъпка 2: компактирай — премести незамаркираните редове в началото */
    newRows = 0;
    for (i = 0; i < *rows; i++)
    {
        if (!toRemove[i])
        {
            if (newRows != i)
            {
                for (c = 0; c < cols; c++)
                {
                    A[newRows][c] = A[i][c];
                }
            }
            newRows++;
        }
    }
    *rows = newRows; // пишем през указателя — това е C-заместителят на референция
}
