#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SCALAR 2

int **genMatrix(size_t rows, size_t cols);
void freeMatrix(int **matrix, size_t rows, size_t cols);
int **genTriangle(size_t height);
void freeTriangle(int **triangle, size_t height);
void printMatrix(int **matrix, size_t rows, size_t cols);
void printTriangle(int **triangle, size_t height);
int **scaleMatrix(int **matrix, size_t rows, size_t cols, int scalar);
int **sumMatrix(int **matrixA, int **matrixB, size_t rows, size_t cols);
int **mulMatrix(int **matrixA, size_t aRows, size_t aCols, int **matrixB, size_t bRows, size_t bCols);
long long int squashTriangle(int** triangle, size_t height);

int main()
{
    srand((unsigned int)time(NULL));
    size_t rows, cols, height;
    if (scanf("%zu %zu %zu", &rows, &cols, &height) != 3)
    {
        puts("Invalid amount of parameters");
        return 1;
    }
    int **matrix = genMatrix(rows, cols);
    if (matrix == NULL)
    {
        return 1;
    }
    int **triangle = genTriangle(height);
    if (triangle == NULL)
    {
        return 1;
    }

    // printing the generated matrices
    puts("---------------ORIGINAL MATRIX------------------");
    printMatrix(matrix, rows, cols);
    printTriangle(triangle, height);

    // multiply by scalar
    puts("---------------SCALAR MATRIX------------------");
    int **scalarMatrix = scaleMatrix(matrix, rows, cols, SCALAR);
    if (!scalarMatrix)
    {
        return 1;
    }
    printMatrix(scalarMatrix, rows, cols);

    // sum Two matrices
    puts("---------------SUM MATRIX------------------");
    int **sumOfTwoMatrices = sumMatrix(matrix, scalarMatrix, rows, cols);
    if (!sumOfTwoMatrices)
    {
        return 1;
    }
    printMatrix(sumOfTwoMatrices, rows, cols);

    // multiplying two matrices
    puts("---------------MULTIPLIED MATRIX------------------");
    int** multipliedMatrix = mulMatrix(matrix, rows, cols, scalarMatrix, rows, cols);
    if (!multipliedMatrix)
    {
        return 1;
    }
    printMatrix(multipliedMatrix, rows, cols);

    //squash the triangle into a sum
    puts("-------------SQUASHING TRIANGLE--------------------");
    long long int sum = squashTriangle(triangle, height);
    printf("%d", sum);

    freeMatrix(matrix, rows, cols);
    freeMatrix(scalarMatrix, rows, cols);
    freeMatrix(sumOfTwoMatrices, rows, cols);
    freeMatrix(multipliedMatrix, rows, cols);
    freeTriangle(triangle, height);
    return 0;
}

int **genMatrix(size_t rows, size_t cols)
{
    int **matrix = (int **)malloc(sizeof(int *) * rows);
    if (!matrix)
    {
        return NULL;
    }

    for (size_t i = 0; i < rows; i++)
    {
        matrix[i] = (int *)malloc(sizeof(int) * cols);
        if (!matrix[i])
        {
            freeMatrix(matrix, i, cols);
            return NULL;
        }

        for (size_t j = 0; j < cols; j++)
        {
            matrix[i][j] = rand() % 10;
        }
    }

    return matrix;
}

void freeMatrix(int **matrix, size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}
int **genTriangle(size_t height)
{
    int **trinagle = (int **)malloc(sizeof(int *) * height);
    if (!trinagle)
    {
        return NULL;
    }

    for (size_t i = 0; i < height; i++)
    {
        trinagle[i] = (int *)malloc(sizeof(int) * (i + 1));
        if (!trinagle[i])
        {
            freeTriangle(trinagle, i);
            return NULL;
        }

        for (size_t j = 0; j < (i + 1); j++)
        {
            trinagle[i][j] = rand() % 10;
        }
    }

    return trinagle;
}
void freeTriangle(int **triangle, size_t height)
{
    for (size_t i = 0; i < height; i++)
    {
        free(triangle[i]);
    }
    free(triangle);
}
void printMatrix(int **matrix, size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            printf("[%d]", matrix[i][j]);
        }

        puts(" ");
    }
}
void printTriangle(int **triangle, size_t height)
{
    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < (i + 1); j++)
        {
            printf("[%d]", triangle[i][j]);
        }

        puts(" ");
    }
}

int **scaleMatrix(int **matrix, size_t rows, size_t cols, int scalar)
{
    int **scalarMatrix = (int **)malloc(sizeof(int *) * rows);
    if (!scalarMatrix)
    {
        return NULL;
    }

    // because the matrix isnt a polylinear function when we multiply with the scalar it multiplies the whole matrix
    for (size_t i = 0; i < rows; i++)
    {
        scalarMatrix[i] = (int *)malloc(sizeof(int) * cols);
        if (!scalarMatrix[i])
        {
            freeMatrix(scalarMatrix, i, cols);
            return NULL;
        }

        for (size_t j = 0; j < cols; j++)
        {
            scalarMatrix[i][j] = matrix[i][j] * scalar;
        }
    }

    return scalarMatrix;
}
int **sumMatrix(int **matrixA, int **matrixB, size_t rows, size_t cols)
{
    int **sumMatrix = (int **)malloc(sizeof(int *) * rows);
    if (!sumMatrix)
    {
        return NULL;
    }

    for (size_t i = 0; i < rows; i++)
    {
        sumMatrix[i] = (int *)malloc(sizeof(int) * cols);
        if (!sumMatrix[i])
        {
            freeMatrix(sumMatrix, i, cols);
            return NULL;
        }

        for (size_t j = 0; j < cols; j++)
        {
            sumMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    return sumMatrix;
}
int **mulMatrix(int **matrixA, size_t aRows, size_t aCols, int **matrixB, size_t bRows, size_t bCols)
{
    if (aCols != bRows)
    {
        puts("The cols of the first matrix have to be equal to the rows of the second one");
        return NULL;
    }

    // we do it with a Rows because aRows x aCols * bRows x bCols = aRows x bCols
    int **multipliedMatrix = (int **)malloc(sizeof(int *) * aRows);
    if (!multipliedMatrix)
    {
        return NULL;
    }

    for (size_t i = 0; i < aRows; i++)
    {
        multipliedMatrix[i] = (int *)calloc(bCols, sizeof(int));
        if (!multipliedMatrix[i])
        {
            freeMatrix(multipliedMatrix, i, bCols);
            return NULL;
        }

        for (size_t j = 0; j < bCols; j++)
        {
            for (size_t k = 0; k < bRows; k++)
            {
                multipliedMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    return multipliedMatrix;
}
long long int squashTriangle(int **triangle, size_t height)
{
    long long int sum = 0;

    for (size_t i = 0; i < height; i++)
    {
        for (size_t j = 0; j < i + 1; j++)
        {
            sum += triangle[i][j];
        }
    }
    
    return sum;
};
