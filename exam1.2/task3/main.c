#include <stdio.h>
#include <stdbool.h>

#define LENGTH 200

bool isCorrectingString(char string[], int length)
{
    int stage = 1;
    for (int i = 0; i < length - 1; ++i)
    {
        char currentChar = string[i];
        switch (stage)
        {
        case 1:
        {
            if ('1' <= currentChar && currentChar <= '9' || 'A' <= currentChar && currentChar <= 'E' || 'a' <= currentChar && currentChar <= 'e')
            {
                stage = 2;
            }
            else
            {
                stage = 5;
                return false;
            }
            break;
        }

        case 2:
        {
            if ('0' <= currentChar && currentChar <= '9' || 'A' <= currentChar && currentChar <= 'E' || 'a' <= currentChar && currentChar <= 'e')
            {
                stage = 2;
            }
            else if (currentChar == '.')
            {
                stage = 3;
            }
            else
            {
                stage = 5;
                return false;
            }
            break;
        }
        case 3:
        {
            if ('0' <= currentChar && currentChar <= '9' || 'A' <= currentChar && currentChar <= 'E' || 'a' <= currentChar && currentChar <= 'e')
            {
                stage = 4;
            }
            else
            {
                stage = 5;
                return false;
            }
            break;
        }
        case 4:
            if ('0' <= currentChar && currentChar <= '9' || 'A' <= currentChar && currentChar <= 'E' || 'a' <= currentChar && currentChar <= 'e')
            {
                stage = 4;
            }
            else
            {
                stage = 5;
                return false;
            }
            break;
        }
    }
}
int main()
{
    char string[LENGTH + 1] = {0};

    printf("Enter your string. No more than %d signs: ", LENGTH);
    scanf("%200s", string);

    if (isCorrectingString(string, LENGTH))
    {
        printf("Your string is correct\n");
    }
    else
    {
        printf("Your string is incorrect\n");
    }

    return 0;
}