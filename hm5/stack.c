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

    StackElement *newElement = calloc(1, sizeof(StackElement));
    if (newElement == NULL)
    {
        return -1;
    }
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
    if (stack->top == NULL)
    {
        return -2;
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

int isEmptyStack(Stack *stack)
{
    if (stack == NULL)
    {
        return -1;
    }

    if (stack->top == NULL)
    {
        return -2;
    }
    return 0;
}
