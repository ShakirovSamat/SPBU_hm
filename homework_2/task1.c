#include <stdio.h>

int recFib(int num)
{
    if (num <= 1)
    {
        return 1;
    }
    return recFib(num - 2 ) + recFib(num - 1);
}
int iterFib(int num)
{
    int last = 1;
    int first = 1;
    for(int i = 2; i <= num; i++)
    {
        int temp = first;
        first = first + last;
        last = temp;
    }
    return first;

}

int main() 
{
    int num = 0;
    
    printf("This program finds fibonacci number\n");
    do
    {
        printf("Num should be >= 0. Enter num = ");
        int isNum = scanf_s("%d", &num);
    } while(num < 0 && isNum == 1);


    printf("By iteractive fuction = %d \n", iterFib(num));
    printf("By recursive function = %d", recFib(num));
    return 0;
}