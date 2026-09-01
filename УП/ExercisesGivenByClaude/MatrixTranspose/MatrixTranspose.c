#include <stdio.h>
#include <stdlib.h>

int** readMatrix(int rows, int cols);
void freeMatrix(int** matrix, int rows);
void printMatrix(int** matrix, int rows, int cols);
//if we have a matrix Aij then the transpose matrix will be (A)t or Aji
//so we just need to swith the places of i and j while swaping their values
//also we need to pass by pointer so that when we change the places of the rows and cols
//the values can be correct for future transformations we would want to add to the matrix
void transpose(int*** matrix, int* rows, int* cols);

int main()
{
    int rows, cols;
    if (scanf("%d %d", &rows, &cols) != 2)
    {
        puts("you need to put the correct dimensionality of the matrix");
        return 0;
    }
    
    int** matrix = readMatrix(rows, cols);
    printMatrix(matrix, rows, cols);
    transpose(&matrix, &rows, &cols);
    printMatrix(matrix, rows, cols);

    freeMatrix(matrix, rows);
    return 0;
}

int **readMatrix(int rows, int cols)
{
    if (rows <= 0 || cols <= 0)
    {
        puts("cant have a matrix with negative dimensions");
        return NULL;
    }
    
    int** matrix = (int**)malloc(sizeof(int*) * rows);
    if (matrix == NULL)
    {
        puts("Didnt allocate the matreix correctly");
        return NULL;
    }
    

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int*)malloc(sizeof(int) * cols);
        if (matrix[i] == NULL)
        {
            printf("Error allocating the %d element", i);
            freeMatrix(matrix, i);
            return NULL;
        }
        
        for (int j = 0; j < cols; j++)
        {
            if (scanf("%d", &matrix[i][j]) != 1)
            {
                puts("write only one number at a tipic stupid");
                freeMatrix(matrix, i);
                return NULL;
            }
        }
    }
    
    return matrix;
}

void freeMatrix(int **matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }

    free(matrix);
}

void printMatrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("[%d]", matrix[i][j]);
        }
        puts(" ");
    }
}

void transpose(int ***matrix, int* rows, int* cols)
{
    int rows2 = *cols, cols2 = *rows;
    int** transposeMatrix = (int**)malloc(sizeof(int*) * rows2);

    for (int i = 0; i < rows2; i++)
    {
        transposeMatrix[i] = (int*)malloc(sizeof(int) * cols2);
        if (!transposeMatrix[i])
        {
            puts("The transpose matrix didnt allocate correctly!");
            freeMatrix(transposeMatrix, i);
            return;
        }
        
        for (int j = 0; j < cols2; j++)
        {
            transposeMatrix[i][j] = (*matrix)[j][i];
        }
    }
    
    freeMatrix(*matrix, *rows);
    *matrix = transposeMatrix;

    *rows = rows2;
    *cols = cols2;
}
