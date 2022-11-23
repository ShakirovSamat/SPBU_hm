#include <stdio.h>
#include "stack.h"

int main()
{
    Stack *stack = createStack();
    int comand = -1;
    printf("Comands:\n0 - exit\n1- push\n2 - pop\n3 - add\n4 - print\n");
    do
    {
        printf("Enter comand: ");
        scanf("%d", &comand);

        switch (comand)
        {
        case 0:
        {
            return 0;
            break;
        }
        case 1:
        {
            int value = 0;
            printf("Enter value: ");
            scanf("%d", &value);
            push(stack, value);
            break;
        }
        case 2:
        {
            int res = 0;
            pop(stack, &res);
            break;
        }
        case 3:
        {
            add(stack);
            break;
        }
        case 4:
        {
            print(stack);
            break;
        }
        }

    } while (comand != 0);

    return 0;
}