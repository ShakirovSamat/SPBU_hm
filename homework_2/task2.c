#include <stdio.h>

float linPow(float num, int exponent)
{
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
    if (exponent < 0)
    {
        exponent -= 2*exponent;
        while (exponent != 0)
        {  
            if (exponent & 1) 
            {
                res /= num;
                --exponent;
            }
            else
            {
                num *= num;
                exponent >>= 1;
            }
        }
        return res;
    }
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
    return res;
}

int main() 
{
    
    float num = 0;
    int exponent = 0;

    printf("This program calculates the power of a number\nEnter num = ");
    scanf_s("%f", &num);
    printf("Enter exponent = ");
    scanf_s("%d", &exponent);
    
    printf("Line Pow = %f \n", linPow(num, exponent));
    printf("Bin Pow = %f", binPow(num, exponent));
    return 0;
}