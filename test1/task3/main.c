#include <stdio.h>
#include <stddef.h>

int signsFrequency(char *path)
{
    FILE *fl = fopen(path, "r");
    if (fl == NULL)
    {
        return 0;
    }

    int frequency[1024] = {0};
    
    char str[100];
    while (fgets(str, 100, fl) != NULL)
    {
        for (int i = 0 ; str[i] != '\0'; ++i)
        {
            frequency[str[i]]++;
        }
    }

    for (int i = 0; i < 1024; ++i)
    {
        if (frequency[i] != 0)
        {
            printf("%c: %d\n", (char)i, frequency[i]);
        }
    }
}

int main()
{
    signsFrequency("Data.txt");
    return 0;
}