#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024
#define ASTERIKS 3

int isDigit(const char c);
char *censor(const char *str);

int main()
{
    // so now we have a sentence in the buffer that has allocated 1024 BYTES
    char buffer[BUFFER_SIZE];
    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    {
        puts("Something went wrong with the buffer");
        return 1;
    }
    char *newBuffer = censor(buffer);

    printf("%s", newBuffer);
    free(newBuffer);
    return 0;
}

int isDigit(const char c)
{
    return (c >= '0' && c <= '9');
}

char *censor(const char *str)
{
    if (!str)
    {
        return NULL;
    }

    // first we are getting the exact length of the new string
    int length = strlen(str);
    int numbers = 0, decrease = 0;

    for (int i = 0; i < length; i++)
    {
        if (isDigit(str[i]))
        {
            while (isDigit(str[i]))
            {
                i++;
                decrease++;
            }

            numbers++;
        }
    }

    // plus one for the terminator zero
    int newLength = length - decrease + (numbers * ASTERIKS) + 1;
    char *newStr = (char *)malloc(sizeof(char) * newLength);
    if (!newStr)
    {
        puts("Problem with memory allocation for the new string");
        return NULL;
    }

    // this will be the pointer that goes along with the new string
    // and i will be the pointer that goes along with the old string
    int p = 0, i = 0;

    while (i < length)
    {
        if (isDigit((unsigned char)str[i]))
        {
            for (int j = 0; j < ASTERIKS; j++)
            {
                newStr[p++] = '*';
            }

            while (isDigit((unsigned char)str[i]))
            {
                i++;
            }
        }
        else
        {
            newStr[p++] = str[i++];
        }
    }
    newStr[p] = '\0';

    return newStr;
}
