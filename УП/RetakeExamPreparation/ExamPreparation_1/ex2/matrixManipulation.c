#include <stdio.h>
#include <stdlib.h>
#define SIDES 4

unsigned** allocateMatrix(unsigned rows, unsigned cols);
unsigned** generateCustomMatrix(unsigned rows, unsigned cols);
unsigned calculateWeight(unsigned** matrix, unsigned rows, unsigned cols, unsigned rowIndex, unsigned colIndex);
void deleteRowsWithWeight(unsigned*** matrix, unsigned* rows, unsigned cols, unsigned weight);
int validPos(unsigned rowIndex, unsigned colIndex, unsigned rows, unsigned cols);
void printMatrix(unsigned** matrix, unsigned rows, unsigned cols);

int main()
{
    unsigned rows, cols;
    puts("Enter the rows and the cols of the matrix: ");
    if (scanf("%d %d", &rows, &cols) != 2)
    {
        puts("You need to enter the rows and the cols");
        return -1;
    }
    
    unsigned** matrix = generateCustomMatrix(rows, cols);
    printMatrix(matrix, rows, cols);

    puts(" ");

    deleteRowsWithWeight(&matrix, &rows, cols, 18);
    printMatrix(matrix, rows, cols);

    for (unsigned i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}

unsigned **allocateMatrix(unsigned rows, unsigned cols)
{
    unsigned** matrix = (unsigned**)malloc(sizeof(unsigned*) * rows);
    if (!matrix)
    {
        puts("matrix didnt allocate correctly");
        return NULL;
    }
    
    for (unsigned i = 0; i < rows; i++)
    {
        matrix[i] = (unsigned*)malloc(sizeof(unsigned) * cols);
        if (!matrix[i])
        {
            for (unsigned k = 0; k < i; k++)
            {
                free(matrix[k]);
            }
            free(matrix);
            return NULL;
        }
    }

    return matrix;
}

unsigned **generateCustomMatrix(unsigned rows, unsigned cols)
{
    unsigned** matrix = allocateMatrix(rows, cols);
    if (!matrix)
    {
        puts("There was a problem with allocating the matrix for the custom generation");
        return NULL;
    }
    
    for (unsigned i = 0; i < rows; i++)
    {
        for (unsigned j = 0; j < cols; j++)
        {
            matrix[i][j] = (i * cols) + j + 1;
        }
    }
    
    return matrix;
}

unsigned calculateWeight(unsigned **matrix, unsigned rows, unsigned cols, unsigned rowIndex, unsigned colIndex)
{
    if(!matrix) return 0;

    static const int directions[SIDES][2] =
    {
        {1, 1},
        {-1, 1},
        {1, -1},
        {-1, -1},
    }; 

    size_t weight = 0;

    for (int i = 0; i < SIDES; ++i)
    {
        size_t curr_x = colIndex, curr_y = rowIndex;
        
        if(!validPos(curr_y + directions[i][1], curr_x + directions[i][0], rows, cols)) continue;

        do
        {
            weight += matrix[curr_y][curr_x];

            curr_y += directions[i][1];
            curr_x += directions[i][0];
        } 
        while (validPos(curr_y, curr_x, rows, cols));
    }
 
    return weight;
}

void deleteRowsWithWeight(unsigned ***matrix, unsigned *rows, unsigned cols, unsigned weight)
{
    if (!matrix)
    {
        return;
    }
    
    unsigned* rowsToDelete = (unsigned*)malloc(sizeof(unsigned*) * (*rows));
    if (!rowsToDelete)
    {
        return;
    }
    
    unsigned r_temp = *rows;
    unsigned iter = 0;

    for (unsigned i = 0; i < r_temp; i++)
    {
        for (unsigned j = 0; j < cols; j++)
        {
            if (calculateWeight(*matrix, *rows, cols, i, j) == weight)
            {
                rowsToDelete[iter++] = 1;
                break;
            }
        }
    }
    
    if (iter = 0)
    {
        return;
    }
    
    for (unsigned i = 0; i < iter; i++)
    {
        unsigned* del = (*matrix)[i];
        for (unsigned j = *rowsToDelete; j < r_temp - 1; j++)
        {
            (*matrix)[j] = (*matrix)[j + 1];
        }
        
        --(*rows);
        if (i + 1 != iter)
        {
            --rowsToDelete[i + 1];
        }
    }
    
    unsigned** temp = realloc(*matrix, *rows * sizeof(unsigned*));
    if (!temp)
    {
        return;
    }
    *matrix = temp;

    free(rowsToDelete); rowsToDelete = NULL;
}

int validPos(unsigned rowIndex, unsigned colIndex, unsigned rows, unsigned cols)
{
    return rowIndex >= 0 && rowIndex < rows && colIndex >= 0 && colIndex < cols;
}

void printMatrix(unsigned **matrix, unsigned rows, unsigned cols)
{
    if (!matrix)
    {
        return;
    }
    
    for (unsigned i = 0; i < rows; i++)
    {
        for (unsigned j = 0; j < cols; j++)
        {
            printf("[%d]", matrix[i][j]);
        }
        puts(" ");
    }   
}
