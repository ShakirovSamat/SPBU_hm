#include "stack.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct StackElement
{
    int value;
    struct StackElement *next;
}StackElement;


typedef struct Stack
{
    StackElement *top;
}Stack;


Stack * createStack()
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

