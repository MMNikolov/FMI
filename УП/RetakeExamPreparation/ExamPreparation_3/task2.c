#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** readMatrix(unsigned rows, unsigned cols);
void freeMatrix(char** matrix, unsigned rows);
int isVerbal(const char c);
int isRowVerbal(char* str, unsigned cols);
void shiftElemnetsUp(char** matrix, unsigned* rows, unsigned cols, unsigned targetRow);
void printMatrix(char** matrix, unsigned rows, unsigned cols);

int main()
{
    unsigned rows, cols;
    if (scanf("%u %u", &rows, &cols) != 2)
    {
        return 1;
    }

    char** matrix = readMatrix(rows, cols);

    for (unsigned i = 0; i < rows; i++)
    {
        if (isRowVerbal(matrix[i], cols))
        {
            shiftElemnetsUp(matrix, &rows, cols, i);
        }
    }
    
    printMatrix(matrix, rows, cols);

    freeMatrix(matrix, rows);
    return 0;
}

char **readMatrix(unsigned rows, unsigned cols)
{
    if (rows == 0 || cols == 0)
    {
        return NULL;
    }
    
    char** matrix = (char**)malloc(sizeof(char*) * rows);
    if (!matrix)
    {
        return NULL;
    }
    
    for (unsigned i = 0; i < rows; i++)
    {
        matrix[i] = (char*)malloc(sizeof(char) * cols);
        if (!matrix[i])
        {
            for (unsigned k = 0; k < i; k++)
            {
                free(matrix[k]);
            }
            free(matrix);
            return NULL;
        }
        
        for (unsigned j = 0; j < cols; j++)
        {
            if (scanf(" %c", &matrix[i][j]) != 1)
            {
                for (unsigned k = 0; k <= i; k++)
                {
                    free(matrix[k]);
                }
                free(matrix);
                return NULL;
            }
        }
    }

    return matrix;
}

void freeMatrix(char **matrix, unsigned rows)
{
    for (unsigned i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

int isVerbal(const char c)
{
    const char verbal[5] = {'a', 'e', 'i', 'o', 'u'};

    for (unsigned i = 0; i < 5; i++)
    {
        if (c == verbal[i])
        {
            return 1;
        }
    }
    
    return 0;
}

int isRowVerbal(char *str, unsigned cols)
{
    if (!str)
    {
        return 0;
    }

    int counter = 0;
    for (unsigned i = 0; i < cols; i++)
    {
        if (!isVerbal(str[i]))
        {
            counter++;
        }
    }
    
    if (counter > cols / 2)
    {
        return 1;
    }
    
    return 0;
}

void shiftElemnetsUp(char **matrix, unsigned* rows, unsigned cols, unsigned targetRow)
{
    if ((*rows) == 0)
    {
        return;
    }

    free(matrix[targetRow]);

    for (unsigned i = targetRow; i < (*rows) - 1; i++)
    {
        matrix[i] = matrix[i + 1];
    }
    (*rows)--;
}

void printMatrix(char **matrix, unsigned rows, unsigned cols)
{
    for (unsigned i = 0; i < rows; i++)
    {
        for (unsigned j = 0; j < cols; j++)
        {
            printf("%c", matrix[i][j]);
        }
        puts(" ");
    }
}
