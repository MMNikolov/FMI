#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ============ findPath: stop at the FIRST working path ============
bool findPathHelper(int **lab, size_t n, size_t m, bool **visited, int row, int col, int *path, int idx)
{
    if (row < 0 || row >= (int)n || col < 0 || col >= (int)m)
        return false;
    if (lab[row][col] == 1 || lab[row][col] == 3)
        return false;
    if (visited[row][col])
        return false;

    visited[row][col] = true;

    if (row == (int)n - 1 && col == (int)m - 1)
    {
        path[idx] = 0;
        return true;
    }

    path[idx] = 'R';
    if (findPathHelper(lab, n, m, visited, row, col + 1, path, idx + 1))
        return true;

    path[idx] = 'D';
    if (findPathHelper(lab, n, m, visited, row + 1, col, path, idx + 1))
        return true;

    path[idx] = 'L';
    if (findPathHelper(lab, n, m, visited, row, col - 1, path, idx + 1))
        return true;

    path[idx] = 'U';
    if (findPathHelper(lab, n, m, visited, row - 1, col, path, idx + 1))
        return true;

    visited[row][col] = false;
    return false;
}

bool findPath(int **lab, size_t n, size_t m, int *path)
{
    bool **visited = (bool **)malloc(sizeof(bool *) * n);

    if (!visited)
        return false;

    for (size_t i = 0; i < n; i++)
        visited[i] = (bool *)calloc(m, sizeof(bool));

    bool found = findPathHelper(lab, n, m, visited, 0, 0, path, 0);

    for (size_t i = 0; i < n; i++)
        free(visited[i]);

    free(visited);
    return found;
}

// ============ findOptimumPath: explore EVERYTHING, keep the shortest ============
void findOptimumPathHelper(int **lab, size_t n, size_t m, bool **visited,
                           int row, int col, int *currentPath, int idx,
                           int *bestPath, int *bestLen)
{
    if (row < 0 || row >= (int)n || col < 0 || col >= (int)m)
        return;
    if (lab[row][col] == 1 || lab[row][col] == 3)
        return;
    if (visited[row][col])
        return;

    visited[row][col] = true;

    if (row == (int)n - 1 && col == (int)m - 1)
    {
        // reached target: is THIS path better than the best one seen so far?
        if (*bestLen == -1 || idx < *bestLen)
        {
            for (int i = 0; i < idx; i++)
                bestPath[i] = currentPath[i];
            bestPath[idx] = 0;
            *bestLen = idx;
        }
        visited[row][col] = false; // unmark even on success — must keep exploring
        return;                    // NOTE: no "stop everything" here, just returns normally
    }

    currentPath[idx] = 'R';
    findOptimumPathHelper(lab, n, m, visited, row, col + 1, currentPath, idx + 1, bestPath, bestLen);
    currentPath[idx] = 'D';
    findOptimumPathHelper(lab, n, m, visited, row + 1, col, currentPath, idx + 1, bestPath, bestLen);
    currentPath[idx] = 'L';
    findOptimumPathHelper(lab, n, m, visited, row, col - 1, currentPath, idx + 1, bestPath, bestLen);
    currentPath[idx] = 'U';
    findOptimumPathHelper(lab, n, m, visited, row - 1, col, currentPath, idx + 1, bestPath, bestLen);

    visited[row][col] = false; // always, win or lose
}

bool findOptimumPath(int **lab, size_t n, size_t m, int *path)
{
    bool **visited = (bool **)malloc(sizeof(bool *) * n);
    if (!visited)
        return false;
    for (size_t i = 0; i < n; i++)
        visited[i] = (bool *)calloc(m, sizeof(bool));

    int *currentPath = (int *)malloc(sizeof(int) * (n * m + 1)); // scratch space, separate from the answer
    int bestLen = -1;                                            // -1 means "nothing found yet"

    findOptimumPathHelper(lab, n, m, visited, 0, 0, currentPath, 0, path, &bestLen);

    free(currentPath);
    for (size_t i = 0; i < n; i++)
        free(visited[i]);
    free(visited);
    return bestLen != -1;
}

int main()
{
    int r0[] = {0, 0, 0, 1};
    int r1[] = {0, 0, 1, 0};
    int r2[] = {0, 1, 0, 0};
    int r3[] = {0, 0, 0, 0};
    int *lab[] = {r0, r1, r2, r3};

    int path1[100];
    bool f1 = findPath(lab, 4, 4, path1);
    int len1 = 0;

    while (path1[len1] != 0)
        len1++;

    printf("findPath:        found=%d  path=", f1);

    for (int i = 0; path1[i] != 0; i++)
        putchar(path1[i]);
        
    printf("  (length %d)\n", len1);

    int path2[100];
    bool f2 = findOptimumPath(lab, 4, 4, path2);
    int len2 = 0;
    while (path2[len2] != 0)
        len2++;
    printf("findOptimumPath: found=%d  path=", f2);
    for (int i = 0; path2[i] != 0; i++)
        putchar(path2[i]);
    printf("  (length %d)\n", len2);

    return 0;
}