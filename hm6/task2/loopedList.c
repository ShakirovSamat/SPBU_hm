#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "loopedList.h"

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

typedef struct LoopedList
{
    struct Node *head;
    struct Node *tail;
} LoopedList;

LoopedList *createLoopedList()
{
    return calloc(1, sizeof(LoopedList));
}

int add(LoopedList *loopedList, int value)
{
    if (loopedList == NULL)
    {
        return OUT_OF_MEMORY;
    }

    Node *newNode = calloc(1, sizeof(Node));
    if (newNode == NULL)
    {
        return OUT_OF_MEMORY;
    }
    newNode->value = value;

    if (loopedList->head == NULL)
    {
        newNode->next = newNode;
        loopedList->head = newNode;
        loopedList->tail = newNode;
        return OK;
    }

    loopedList->tail->next = newNode;
    newNode->next = loopedList->head;
    loopedList->tail = newNode;
    return OK;
}
// Синхронизировать индексы в функциях
int get(LoopedList *loopedList, int index)
{
    if (loopedList == NULL)
    {
        return OUT_OF_MEMORY;
    }

    Node *currentNode = loopedList->head;
    Node *previousNode = NULL;

    for (int i = 0; i < index; i++)
    {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    return currentNode->value;
}

int delete(LoopedList *loopedList, int index)
{
    if (loopedList == NULL)
    {
        return OUT_OF_MEMORY;
    }

    if (index < 0)
    {
        return -1;
    }

    if (index == 0)
    {
        Node *tmp = loopedList->head;
        loopedList->tail->next = loopedList->head->next;
        loopedList->head = loopedList->tail;
        free(tmp);
        return OK;
    }

    Node *currentNode = loopedList->head;
    Node *previousNode = NULL;

    int i = 0;
    while (i < index)
    {
        previousNode = currentNode;
        currentNode = currentNode->next;
        ++i;
    }

    loopedList->head = currentNode->next;
    loopedList->tail = previousNode;
    loopedList->tail->next = loopedList->head;

    free(currentNode);
    return OK;
}

int getLen(LoopedList *loopedList)
{
    if (loopedList == NULL)
    {
        return -1;
    }
    if (loopedList->head == NULL)
    {
        return 0;
    }
    Node *currentNode = loopedList->head;
    int len = 1;
    while (currentNode != loopedList->tail)
    {
        len++;
        currentNode = currentNode->next;
    }
    return len;
}

bool isOnlyOneElement(LoopedList *loopedList)
{
    if (loopedList == NULL)
    {
        return false;
    }
    if (loopedList->head == NULL)
    {
        return false;
    }
    if (loopedList->head == loopedList->tail)
    {
        return true;
    }
    return false;
}

int printList(LoopedList *loopedList)
{
    if (loopedList == NULL)
    {
        return OUT_OF_MEMORY;
    }

    Node *currentNode = loopedList->head;

    printf("List: ");
    if (loopedList->head == NULL)
    {
        return OK;
    }
    while (currentNode != loopedList->tail)
    {
        printf("%d ", currentNode->value);
        currentNode = currentNode->next;
    }

    printf("%d", currentNode->value);
    return OK;
}
