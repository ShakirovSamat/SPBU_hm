#include <stdio.h>
#include <stdbool.h>
#include "stack.h"
#include "stack.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct StackElement
{
    int value;
    struct StackElement *next;
} StackElement;

typedef struct Stack
{
    StackElement *top;
} Stack;

Stack *createStack()
{
    return calloc(1, sizeof(Stack));
}

int pushStack(Stack *stack, int value)
{
    if (stack == NULL)
    {
        return -1;
    }

    StackElement *newEleemnt = calloc(1, sizeof(StackElement));
    newEleemnt->value = value;

    if (stack->top == NULL)
    {
        stack->top = calloc(1, sizeof(StackElement));
        stack->top = newEleemnt;
        return 0;
    }

    newEleemnt->next = stack->top;
    stack->top = newEleemnt;
    return 0;
}

int popStack(Stack *stack, int *res)
{
    if (stack == NULL)
    {
        return -1;
    }

    *res = stack->top->value;
    stack->top = stack->top->next;
    return 0;
}

int deleteStack(Stack *stack)
{
    if (stack == NULL)
    {
        return -1;
    }

    StackElement *curElement = calloc(1, sizeof(StackElement));
    curElement = stack->top;

    while (curElement != NULL)
    {
        StackElement *nextEleement = curElement->next;
        free(curElement);
        curElement = nextEleement;
    }

    free(stack);
    return 0;
}

bool isEmptyStack(Stack *stack)
{
    return stack->top == NULL;
}
bool isCorrectString(char string[])
{
    Stack *stack = createStack();
    if (stack == NULL)
    {
        printf("Memory error");
        return -1;
    }
    // Проверить на память
    // Возвращать конкретный код ошибки
    // Добавить проверки пуш и поп
    int a = 0;
    for (int i = 0; string[i] != '\0'; ++i)
    {
        int previousBracket = 0;
        switch (string[i])
        {
        case '(':
        case '{':
        case '[':
            pushStack(stack, (int)string[i]);
            break;
        case ')':
            popStack(stack, &previousBracket);
            if (previousBracket != '(' || isEmptyStack(stack) && previousBracket == 0)
            {
                printf("%c) is in the string", previousBracket);
                return false;
            }
            break;
        case '}':
            popStack(stack, &previousBracket);
            if (previousBracket != '{' || isEmptyStack(stack) && previousBracket == 0)
            {
                printf("%c} is in the string", previousBracket);
                return false;
            }
            break;
        case ']':
            popStack(stack, &previousBracket);
            if (previousBracket != '[' || isEmptyStack(stack) && previousBracket == 0)
            {
                printf("(%c] is in the string", previousBracket);
                return false;
            }
            break;
        }
    }
    return isEmptyStack(stack);
}

// Добавить разные случаи
bool test()
{
    char strings[6][7] = {"(){}[]", "((()))", "({[})]", "({})[]", "(a)[{}]", "aaaaaaa"};
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
    if (!isCorrectString(strings[4]))
    {
        return false;
    }
    if (!isCorrectString(strings[5]))
    {
        return false;
    }

    return true;
}

int main()
{
    if (!test())
    {
        printf("Error in isCorrectString function");
        return -1;
    }
    char str[101] = {0};
    printf("Enter your string. Max lenght is 100 signs: ");
    scanf_s("%100s", str);

    // Добавить почему строка неправильная
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