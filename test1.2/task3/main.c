#include <stdio.h>

int main()
{
    FILE *file = fopen("input.txt", "r");
    if (file == NULL)
    {
        return -1;
    }

    char currentSign = fgetc(file);
    char lastSign = currentSign;
    int amount = 1;
    
    do
    {
        currentSign = fgetc(file);
        if (currentSign == EOF)
        {
            printf("%d%c",amount, lastSign);
            break;
        }
        if (lastSign == currentSign)
        {
            ++amount;
        }
        else
        {
            if (amount == 1)
            {
                printf("%c", lastSign);
            }
            else
            {
                printf("%d%c",amount, lastSign);
            }
            amount = 1;
            lastSign = currentSign;
        }

    } while (1);
    fclose(file);
    return 0;
}