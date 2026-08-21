#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *readLine();
int wordsInString(const char *string);

int main()
{
    // Read the string that the user sends
    printf("Please enter a string: ");
    char *string = readLine();

    if (string == NULL)
    {
        printf("Isnt initialized correctly!");
        return 0;
    }

    // How many words are in the string (we will do it by reading until whitespace and seperate them)
    int wordCount = wordsInString(string);
    printf("There are %d words in the string!", wordCount);

    return 0;
}

char *readLine()
{
    int capacity = 32;
    int length = 0;
    char *str = malloc(capacity);

    if (str == NULL)
    {
        return NULL;
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if ((length + 1) >= capacity)
        {
            capacity *= 2;
            char *temp = realloc(str, capacity);
            if (temp == NULL)
            {
                free(str);
                return NULL;
            }
            str = temp;
        }

        str[length++] = (char)c;
    }

    str[length] = '\0';
    return str;
}

int wordsInString(const char *string)
{
    if (string == NULL)
    {
        printf("There is no string found!");
        return 0;
    }
    
    int words = 0;
    int i = 0;
    while (string[i] != '\0')
    {
        while (string[i] == ' ')
        {
            ++i;
        }
        
        if (string[i] != '\0')
        {
            ++words;

            while (string[i] != ' ' && string[i] != '\0')
            {
                ++i;
            }
        }
    }

    return words;
}