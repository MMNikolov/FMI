#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* readLine();
int wordsCountInString(const char* string);
char** ArrayOfWords(const char* string, int words);
void freeWords(char** WordsArray, int wordsCount);
void printWords(char** WordsArray, int wordsCount);

int main()
{
    //read the string
    puts("Enter a string: ");
    char* string = readLine();

    //determine how many words are in the string
    int wordsInString = wordsCountInString(string);

    //make a 2D array consisting of char**
    char** ArrayWords = ArrayOfWords(string, wordsInString);

    //print the outcome
    printWords(ArrayWords, wordsInString);

    //free the memort
    freeWords(ArrayWords, wordsInString);
    free(string);

    return 0;
}

char* readLine()
{
    int capacity = 32;
    int length = 0;
    char* string = malloc(capacity);

    if (string == NULL)
    {
        puts("Couldnt allocate correctly the input!");
        return NULL;
    }
    
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if ((length + 1) >= capacity)
        {
            capacity *= 2;
            char* temp = realloc(string, capacity);
            if (temp == NULL)
            {
                puts("There was a problem with the reallocation of the string to the temp");
                return 0;
            }
            string = temp;
        }
        string[length++] = (char)c;
    }
    
    string[length] = '\0';
    return string;
}

int wordsCountInString(const char *string)
{
    if (string == NULL)
    {
        puts("Cant read the string if there isnt any");
        return 0;
    }
    
    int words = 0, i = 0;
    while (string[i] != '\0')
    {
        while (string[i] == ' ')
        {
            i++;
        }

        if (string[i] != '\0')
        {
            words++;

            while (string[i] != ' ' && string[i] != '\0')
            {
                i++;
            }
            
        }
    }
    
    return words;
}

char **ArrayOfWords(const char *string, int wordsCount)
{
    if (wordsCount == 0)
    {
        puts("There arent any words to put in the array");
        return NULL;
    }
    
    char** Array2D = malloc(wordsCount * sizeof(char*));
    if (Array2D == NULL)
    {
        puts("The allocation of the 2D matrix isnt done");
        return NULL;
    }
    
    int i = 0, wordIndex = 0;
    while (string[i] != '\0' && wordIndex < wordsCount)
    {
        while (string[i] == ' ')
        {
            i++;
        }
        
        if (string[i] == '\0')
        {
            break;
        }
        
        int start = i;
        while (string[i] != '\0' && string[i] != ' ')
        {
            i++;
        }
        int wordLength = i - start;

        Array2D[wordIndex] = malloc(wordLength + 1);
        if (Array2D[wordIndex] == NULL)
        {
            for (int k = 0; k < wordIndex; k++)
            {
                free(Array2D[k]);
            }
            free(Array2D);
            wordsCount = 0;
            return NULL;
        }
        
        memcpy(Array2D[wordIndex], string + start, wordLength);
        Array2D[wordIndex][wordLength] = '\0';

        wordIndex++;
    }
    
    return Array2D;
}

void freeWords(char **WordsArray, int wordsCount)
{
    if (WordsArray == NULL)
    {
        puts("There is not a single wordd in the array");
        return;
    }
    
    for (int i = 0; i < wordsCount; i++)
    {
        free(WordsArray[i]);
    }
    free(WordsArray);
}

void printWords(char** WordsArray, int wordsCount)
{
    if (WordsArray == NULL)
    {
        puts("There is not a single wordd in the array");
        return;
    }

    for (int i = 0; i < wordsCount; i++)
    {
        printf("[%s]", WordsArray[i]);
    }
}
