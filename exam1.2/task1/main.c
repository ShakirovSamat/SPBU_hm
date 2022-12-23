#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define LENGTH 257

bool isRomanDigit(char sign)
{
    return sign == 'I' || sign == 'V' || sign == 'X' || sign == 'L' || sign == 'C' || sign == 'D' || sign == 'M';
}

int getDecimalDigitFromRoman(char romanDigit, int *decimalDigit)
{
    switch (romanDigit)
    {
    case 'I':
        *decimalDigit = 1;
        break;
    case 'V':
        *decimalDigit = 5;
        break;
    case 'X':
        *decimalDigit = 10;
        break;
    case 'L':
        *decimalDigit = 50;
        break;
    case 'C':
        *decimalDigit = 100;
        break;
    case 'D':
        *decimalDigit = 500;
        break;
    case 'M':
        *decimalDigit = 1000;
        break;
    }
    return 0;
}
int getDecimalNumberFromRoman(char romanNumber[], int length, int *decimalNumber)
{
    while (romanNumber[length] == 0 || romanNumber[length] == '\n')
    {
        --length;
    }
    int previousRomanDigit = 0;
    int numberOfIdenticalDigitsInRow = 1;
    bool isLastSubtraction = false;
    for (int i = length; i >= 0; --i)
    {

        if (isRomanDigit(romanNumber[i]))
        {
            int decimalDigit = 0;
            int error = getDecimalDigitFromRoman(romanNumber[i], &decimalDigit);
            if (error)
            {
                return error;
            }

            // Выполнение аримфметической операции и проверка корректности вычитания
            if ((previousRomanDigit == 5 || previousRomanDigit == 10) && decimalDigit == 1)
            {
                if (isLastSubtraction)
                {
                    return -2;
                }
                *decimalNumber -= 1;
                isLastSubtraction = true;
            }
            else if ((previousRomanDigit == 100 || previousRomanDigit == 50) && decimalDigit == 10)
            {
                if (isLastSubtraction)
                {
                    return -2;
                }
                *decimalNumber -= 10;
                isLastSubtraction = true;
            }
            else if ((previousRomanDigit == 1000 || previousRomanDigit == 500) && decimalDigit == 100)
            {
                if (isLastSubtraction)
                {
                    return -2;
                }
                *decimalNumber -= 100;
                isLastSubtraction = true;
            }
            else if (previousRomanDigit > decimalDigit)
            {
                return -2;
            }
            else
            {
                *decimalNumber += decimalDigit;
                isLastSubtraction = false;
            }

            // Проверка того, что нет последовательности более чем из 3 одинаковых символов при сложении
            if (previousRomanDigit == decimalDigit)
            {
                ++numberOfIdenticalDigitsInRow;
                if (numberOfIdenticalDigitsInRow == 4)
                {
                    return -2;
                }
            }
            else
            {
                numberOfIdenticalDigitsInRow = 0;
            }
            previousRomanDigit = decimalDigit;
        }
        else
        {
            return -1;
        }
    }
    return 0;
}

int main()
{
    char romanNumber[LENGTH] = {0};

    printf("This program converts a roman number to a decimal\n");
    printf("Enter roman number: ");
    fgets(romanNumber, LENGTH, stdin);
    romanNumber[strlen(romanNumber) - 1] = '\0';

    int decimalNumber = 0;

    int error = getDecimalNumberFromRoman(romanNumber, LENGTH, &decimalNumber);
    if (error == -1)
    {
        printf("Wrong input: there are other characters beside roman digits\n");
        return error;
    }
    if (error == -2)
    {
        printf("Wrong input: wrong roman number\n");
        return error;
    }

    printf("%s = %d\n", romanNumber, decimalNumber);
    return 0;
}