#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **stringSplit(const char *string, const char *delimiter);
int matchesAt(const char *string, int p, const char *delimiter, int delimLen);
void freeWords(char **words);
char *readLine();

int main()
{
    char *str = readLine();
    if (!str)
    {
        return 1;
    }

    char **split = stringSplit(str, " ");

    for (int i = 0; split[i] != NULL; i++)
    {
        printf("[%s]", split[i]);
    }
    
    freeWords(split);
    return 0;
}

char **stringSplit(const char *string, const char *delimiter)
{
    int delimLen = strlen(delimiter);
    int p = 0, counter = 0;

    while (string[p] != '\0')
    {
        while (string[p] != '\0' && matchesAt(string, p, delimiter, delimLen))
            p += delimLen;
        if (string[p] == '\0')
            break;
        counter++;
        while (string[p] != '\0' && !matchesAt(string, p, delimiter, delimLen))
            p++;
    }

    char **words = (char **)calloc(counter + 1, sizeof(char *));
    if (!words)
        return NULL;

    p = 0;
    int k = 0;
    while (string[p] != '\0')
    {
        while (string[p] != '\0' && matchesAt(string, p, delimiter, delimLen))
            p += delimLen;
        if (string[p] == '\0')
            break;

        int start = p;
        int wordLength = 0;
        while (string[p] != '\0' && !matchesAt(string, p, delimiter, delimLen))
        {
            wordLength++;
            p++;
        }
        char *buffer = (char *)malloc(sizeof(char) * (wordLength + 1));
        if (!buffer)
        {
            for (int i = 0; i < k; i++)
                free(words[i]);

            free(words);
            return NULL;
        }

        for (int i = 0; i < wordLength; i++)
            buffer[i] = string[start + i];
        buffer[wordLength] = '\0';
        words[k++] = buffer;
    }

    return words;
}

char *readLine()
{
    int capacity = 16;
    int length = 0;

    char *buffer = (char *)malloc(sizeof(char) * capacity);
    if (!buffer)
    {
        return NULL;
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (length + 1 >= capacity)
        {
            capacity *= 2;

            char *temp = (char *)realloc(buffer, capacity);
            if (!temp)
            {
                free(buffer);
                return NULL;
            }
            buffer = temp;
        }

        buffer[length++] = (char)c;
    }

    buffer[length] = '\0';
    return buffer;
}

int matchesAt(const char *string, int p, const char *delimiter, int delimLen)
{
    for (int i = 0; i < delimLen; i++)
    {
        if (string[p + i] == '\0')
            return 0;
        if (string[p + i] != delimiter[i])
            return 0;
    }
    return 1;
}

void freeWords(char **words)
{
    for (int i = 0; words[i] != NULL; i++)
        free(words[i]);
    free(words);
}