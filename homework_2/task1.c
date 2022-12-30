#include <stdio.h>

int recFib(int num)
{
    if (num <= 1)
    {
        return 1;
    }
    return recFib(num - 2) + recFib(num - 1);
}
int iterFib(int num)
{
    int current = 1;
    int previous = 1;
    for (int i = 2; i <= num; i++)
    {
        int temp = current;
        current = previous + current;
        previous = temp;
    }
    return current;
}

int main()
{
    int num = 0;

    printf("This program finds Fibonacci number\n");
    int isNum = -1;
    do
    {
        printf("Num should be >= 0. Enter num = ");
        isNum = scanf_s("%d", &num);
    } while (num < 0 && isNum == 1);

    printf("By iteractive fuction = %d \n", iterFib(num));
    printf("By recursive function = %d", recFib(num));
    return 0;
}