#include <stdio.h>
#include <string.h>

int tripleTransformation(char *binary, char *octale)
{
    int result = 0;
    int length = strlen(binary);
    if (length != 3)
    {
        return -1;
    }
    for (int i = 2; i >= 0; --i)
    {
        if (binary[i] != '1' && binary[i] != '0')
        {
            return -1;
        }
        if (binary[2 - i] == '1')
        {
            int exponent = i;
            int sum = 1;
            while (exponent > 0)
            {
                sum *= 2;
                --exponent;
            }
            result += sum;
        }
        *octale = result + 48;
    }
    return 0;
}
int binaryToOctale(char *binary, char *octale)
{
    int length = strlen(binary);
    int currentPosition = length % 3;
    int currentIndex = 1;
    char triple[4] = "000";
    int error = 0;
    switch (currentPosition)
    {
    case 1:
    {
        triple[2] = binary[0];
        error = tripleTransformation(triple, &(octale[0]));
        break;
    }
    case 2:
    {
        triple[1] = binary[0];
        triple[2] = binary[1];
        error = tripleTransformation(triple, &(octale[0]));
        break;
    }
    default:
        currentIndex = 0;
        break;
    }

    if (error != 0)
    {
        printf("Wrong input\n");
        return -1;
    }

    for (; currentPosition < length; currentPosition += 3)
    {
        triple[0] = binary[currentPosition];
        triple[1] = binary[currentPosition + 1];
        triple[2] = binary[currentPosition + 2];
        error = tripleTransformation(triple, &(octale[currentIndex]));
        if (error != 0)
        {
            printf("Wrong input\n");
            return -1;
        }
        ++currentIndex;
    }
    return 0;
}

int main()
{
    char binaryNumber[257] = {0};
    char octalNumber[33] = {0};

    printf("This program translates binary number to octale number\n");
    printf("Enter binary number: ");
    scanf("%256s", binaryNumber);

    int error = binaryToOctale(binaryNumber, octalNumber);

    if (error != 0)
    {
        return -1;
    }

    printf("Octale: %s\n", octalNumber);
}