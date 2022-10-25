#include "stack.h"
#include <stdio.h>
#include <stdbool.h>

int reversePolishNotaion(char str[])
{
    Stack *stack = createStack();
    for(int i = 0; str[i] != '\0'; ++i)
    {
        int b = 0;
        int a = 0;
        switch (str[i])
        {
        case '+':
            popStack(stack, &a);
            popStack(stack, &b);
            pushStack(stack, a + b);
            break;
        case '-':
            popStack(stack, &a);
            popStack(stack, &b);
            pushStack(stack, b - a);
            break;
        case '*':
            popStack(stack, &a);
            popStack(stack, &b);
            pushStack(stack, a * b);
            break;
        case '/':
            popStack(stack, &a);
            popStack(stack, &b);
            pushStack(stack, b / a);
            break;
        default:
            pushStack(stack, (int)str[i] - 48);
            break;
        }
    }
    int res = 0;
    popStack(stack, &res);
    deleteStack(stack);
    return res;
}

bool test()
{
    int res = 0;
    char strings[4][4] = {"56+", "97-", "65*","82/"};
    res = reversePolishNotaion(strings[0]);
    if (res != 11)
    {
        return false;
    }
    res = reversePolishNotaion(strings[1]);
    if (res != 2)
    {
        return false;
    }
    res = reversePolishNotaion(strings[2]);
    if (res != 30)
    {
        return false;
    }
    res = reversePolishNotaion(strings[3]);
    if (res != 4)
    {
        return false;
    }

    return true;
}

int main()
{  
    if (!test())
    {
        printf("Error in reversePolishNotation function");
        return -1;
    }
    char str[101]; 
    printf("Enter reverse polish notation.Max length is 100: ");
    scanf_s("%s", str);
    
    int res = reversePolishNotaion(str);
    printf("%d\n", res);

    return 0;
}