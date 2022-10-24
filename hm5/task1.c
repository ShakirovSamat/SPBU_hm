#include "stack.h"
#include <stdio.h>

int main()
{  
    Stack *stack = createStack();
    char str[101]; 
    printf("Enter reverse polish notation.Max length is 100: ");
    scanf_s("%s", str);
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
    printf("%d\n", res);

    return 0;
}