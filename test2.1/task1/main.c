#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool isPhoneNumber(char *string)
{
    int length = strlen(string);
    if (length != 14)
    {
        return false;
    }

    if (string[0] != '+' || string[2] != '(' || string[6] != ')')
    {
        return false;
    }

    for (int i = 1; i < 14; ++i)
    {
        if (i == 2 || i == 6)
        {
            continue;
        }
        if (!('0' <= string[i] && string[i] <= '9'))
        {
            return false;
        }
    }
    return true;
}

char *cutWordFromString(char *string, int start, int end)
{
    char *word = calloc(end - start + 1, sizeof(char));
    for (int i = 0; i < end - start; ++i)
    {
        word[i] = string[start + i];
    }
    return word;
}

int main()
{
    FILE *file = fopen("file.txt", "r");
    if (file == NULL)
    {
        printf("File were not opened");
        return -1;
    }

    char string[257] = {0};

    for (int i = 0; fgets(string, 256, file); ++i)
    {
        int length = strlen(string);
        for (int b = 0; b < length; ++b)
        {
            if (string[b] == '+')
            {
                int end = b;
                while (string[end + 1] != ' ' && string[end + 1] != '\0')
                {
                    ++end;
                }
                char *potentialNumber = cutWordFromString(string, b, end);
                if (isPhoneNumber(potentialNumber))
                {
                    printf("%d: %s\n", i + 1, potentialNumber);
                }
            }
        }
    }
    printf("\n");
    fclose(file);
    return 0;
}