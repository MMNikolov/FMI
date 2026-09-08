#include <stdio.h>
#include <stdlib.h>

unsigned **readMatrix(unsigned rows, unsigned cols);
int isSquareFree(unsigned num);
void shiftElementsLeft(unsigned **matrix, unsigned rows, unsigned *cols, unsigned targetCol);
void printMatrix(unsigned **matrix, unsigned rows, unsigned cols);
void freeMatrix(unsigned **matrix, unsigned rows, unsigned cols);

int main()
{
    unsigned rows, cols;
    if (scanf("%u %u", &rows, &cols) != 2)
    {
        return 1;
    }

    unsigned **matrix = readMatrix(rows, cols);
    if (matrix == NULL)
    {
        return 1;
    }

    for (unsigned i = 0; i < rows; i++)
    {
        for (unsigned j = 0; j < cols; j++)
        {
            if (isSquareFree(matrix[i][j]))
            {
                shiftElementsLeft(matrix, rows, &cols, j);
                j--;
            }
        }
    }

    if (cols == 0)
    {
        freeMatrix(matrix, rows, cols);
        puts("Every single column has been exterminated");
    }
    else
    {
        printMatrix(matrix, rows, cols);
        freeMatrix(matrix, rows, cols);
    }
    return 0;
}

unsigned **readMatrix(unsigned rows, unsigned cols)
{
    unsigned **matrix = (unsigned **)malloc(sizeof(unsigned *) * rows);
    if (!matrix)
    {
        return NULL;
    }

    for (unsigned i = 0; i < rows; i++)
    {
        matrix[i] = (unsigned *)malloc(sizeof(unsigned) * cols);

        for (unsigned j = 0; j < cols; j++)
        {
            if (scanf("%u", &matrix[i][j]) != 1)
            {
                return NULL;
            }
        }
    }

    return matrix;
}

int isSquareFree(unsigned num)
{
    for (unsigned i = 2; i * i <= num; i++)
    {
        if ((num % (i * i)) == 0)
        {
            return 0;
        }
    }

    return 1;
}

void shiftElementsLeft(unsigned **matrix, unsigned rows, unsigned *cols, unsigned targetCol)
{
    if ((*cols) == 1)
    {
        (*cols)--;
        return;
    }

    for (unsigned i = 0; i < rows; i++)
    {
        for (unsigned j = targetCol; j < (*cols); j++)
        {
            if (j + 1 != (*cols))
            {
                matrix[i][j] = matrix[i][j + 1];
            }
        }
    }
    (*cols)--;
}

void freeMatrix(unsigned **matrix, unsigned rows, unsigned cols)
{
    for (unsigned i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
};

void printMatrix(unsigned **matrix, unsigned rows, unsigned cols)
{
    for (unsigned i = 0; i < rows; i++)
    {
        for (unsigned j = 0; j < cols; j++)
        {
            printf("[%u]", matrix[i][j]);
        }
        puts(" ");
    }
};