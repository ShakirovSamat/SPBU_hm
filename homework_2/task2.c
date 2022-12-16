#include <stdio.h>
#include <stdbool.h>
#include <math.h>

float linearPower(float num, int exponent)
{
    if (num == 0 && exponent == 0)
    {
        return 1;
    }
    float res = 1;
    if (exponent >= 0)
    {
        for (int i = 0; i < exponent; ++i)
        {
            res = res * num;
        }
    }
    else
    {
        for (int i = 0; i > exponent; --i)
        {
            res = res / num;
        }
    }

    return res;
}

float binPow(float num, int exponent)
{
    float res = 1;

    bool isPositiveExponent = true;
    if (exponent < 0)
    {
        isPositiveExponent = false;
    }

    exponent = abs(exponent);

    while (exponent)
    {
        if (exponent & 1)
        {
            res *= num;
            --exponent;
        }
        else
        {
            num *= num;
            exponent >>= 1;
        }
    }
    if (!isPositiveExponent)
    {
        res = 1 / res;
    }
    return res;
}

int main()
{

    float num = 0;
    int exponent = 0;

    printf("This program calculates the power of a number\nEnter a number = ");
    scanf_s("%f", &num);
    printf("Enter exponent = ");
    scanf_s("%d", &exponent);

    printf("Linear Power = %f \n", linearPower(num, exponent));
    printf("Binary Power = %f", binPow(num, exponent));
    return 0;
}