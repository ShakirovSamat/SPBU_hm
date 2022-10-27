#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

bool isCorrectString(char str[])
{
    Stack *stack = createStack();
    int a = 0;
    for(int i = 0; str[i] != '\0'; ++i)
    {
        int prevSign = 0;
        switch (str[i])
        {
            case '(':
            case '{':
            case '[':
                pushStack(stack, (int)str[i]);
                break;
            case ')':
                popStack(stack, &prevSign);
                if (prevSign != '(' || isEmptyStack(stack) && prevSign == 0)
                {
                    printf("%c", prevSign);
                    return false;
                }
                break;
            case '}':
                popStack(stack, &prevSign);
                if (prevSign != '{' || isEmptyStack(stack) && prevSign == 0)
                {
                    return false;
                }
                break;
            case ']':
                popStack(stack, &prevSign);
                if (prevSign != '[' || isEmptyStack(stack) && prevSign == 0)
                {
                    return false;
                }
                break;
            default:
                break;
        }
    }
    return isEmptyStack(stack);
}

bool test()
{
    char strings[4][7] = {"(){}[]", "((()))", "({[})]", "({})[]"};
    if (!isCorrectString(strings[0]))
    {
        return false;
    }
    if (!isCorrectString(strings[1]))
    {
        return false;
    }
    if (isCorrectString(strings[2]))
    {
        return false;
    }
    if (!isCorrectString(strings[3]))
    {
        return false;
    }

    return true;
}

int main()
{
    if(!test())
    {
        printf("Error in isCorrectString function");
        return-1;
    }
    char str[101];
    printf("Enter your string. Max lenght is 100 signs: ");
    scanf_s("%s", str);

    if (isCorrectString(str))
    {
        printf("String is correct");
    }
    else
    {
        printf("String is incorrect");
    }
    return 0;
}