#include "stack.h"
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

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

    StackElement *newElement = calloc(1, sizeof(StackElement));
    // Проверить выделение памяти
    newElement->value = value;

    if (stack->top == NULL)
    {
        stack->top = newElement;
        return 0;
    }

    newElement->next = stack->top;
    stack->top = newElement;
    return 0;
}

int popStack(Stack *stack, int *res)
{
    if (stack == NULL)
    {
        return -1;
    }

    *res = stack->top->value;
    StackElement *elementToFree = stack->top;
    stack->top = stack->top->next;
    free(elementToFree);

    return 0;
}

int deleteStack(Stack *stack)
{
    if (stack == NULL)
    {
        return -1;
    }

    StackElement *curElement = stack->top;

    while (curElement != NULL)
    {
        StackElement *nextEleement = curElement->next;
        free(curElement);
        curElement = nextEleement;
    }

    free(stack);
    return 0;
}
// Разобраться с Null случаем
bool isEmptyStack(Stack *stack)
{
    if (stack == NULL)
    {
        return true;
    }

    return stack->top == NULL;
}

int calculatePolishNotaion(char polishNotaion[])
{
    Stack *stack = createStack();
    // Проверить на null
    // Арифметические исключения + вынести в функцию арифметические опреации
    for (int i = 0; polishNotaion[i] != '\0'; ++i)
    {
        int b = 0;
        int a = 0;
        switch (polishNotaion[i])
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
            // Разобраться с пробелами и другими символами
            pushStack(stack, (int)polishNotaion[i] - 48);
            break;
        }
    }
    int res = 0;
    popStack(stack, &res);
    // Добавить проверки: пустой стек после снятия и непустой стек до снятия
    deleteStack(stack);
    return res;
}
// Доработать тест
bool test()
{
    int res = 0;
    char strings[4][4] = {"56+", "97-", "65*", "82/"};
    res = calculatePolishNotaion(strings[0]);
    if (res != 11)
    {
        return false;
    }
    res = calculatePolishNotaion(strings[1]);
    if (res != 2)
    {
        return false;
    }
    res = calculatePolishNotaion(strings[2]);
    if (res != 30)
    {
        return false;
    }
    res = calculatePolishNotaion(strings[3]);
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
        printf("Error in calculatePolishNotation function");
        return -1;
    }
    char inputString[101] = {0};
    printf("Enter reverse polish notation.Max length is 100: ");
    scanf_s("%100s", inputString);
    // Улучшить  вывод
    int res = calculatePolishNotaion(inputString);
    printf("%d\n", res);

    return 0;
}