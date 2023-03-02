#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

typedef struct Stack
{
    struct Node *head;
} Stack;

Stack *createStack()
{
    return calloc(1, sizeof(Stack));
}

int push(Stack *stack, int value)
{
    if (stack == NULL)
    {
        return -1;
    }

    if (stack->head == NULL)
    {
        stack->head = calloc(1, sizeof(Node));
        if (stack->head == NULL)
        {
            return -1;
        }
        stack->head->value = value;
        return 0;
    }

    Node *currentHead = stack->head;
    Node *newHead = calloc(1, sizeof(Node));
    if (newHead == NULL)
    {
        return -1;
    }
    newHead->value = value;
    newHead->next = currentHead;
    stack->head = newHead;
    return 0;
}

int pop(Stack *stack, int *res)
{
    if (stack == NULL || stack->head == NULL)
    {
        return -1;
    }

    *res = stack->head->value;
    Node *currentHead = stack->head;
    stack->head = stack->head->next;
    free(currentHead);
    return 0;
}

int add(Stack *stack)
{
    if (stack == NULL || stack->head == NULL || stack->head->next == NULL)
    {
        return -1;
    }

    Node *secondNode = stack->head->next;
    stack->head->value += stack->head->next->value;
    stack->head->next = stack->head->next->next;
    free(secondNode);
    return 0;
}

int print(Stack *stack)
{
    if (stack == NULL)
    {
        return -1;
    }

    Node *currentNode = stack->head;
    printf("\nStack: ");
    while (currentNode != NULL)
    {
        printf("%d ", currentNode->value);
        currentNode = currentNode->next;
    }
    printf("\n\n");

    return 0;
}
