#include <stdlib.h>
#include <stdio.h>
#include "sortedList.h"

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

typedef struct SortedList
{
    struct Node *head;
} SortedList;

SortedList *createSortedList()
{
    return calloc(1, sizeof(SortedList));
}

int insert(SortedList *sortedList, int value)
{
    if (sortedList == NULL)
    {
        return OUT_OF_MEMORY;
    }

    Node *newNode = calloc(1, sizeof(Node));
    if (newNode == NULL)
    {
        return OUT_OF_MEMORY;
    }
    newNode->value = value;

    if (sortedList->head == NULL)
    {
        sortedList->head = newNode;
        return OK;
    }

    Node *currentNode = sortedList->head;
    Node *previousNode = NULL;
    while (currentNode != NULL && value > currentNode->value)
    {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    if (previousNode == NULL)
    {
        newNode->next = sortedList->head;
        sortedList->head = newNode;
        return OK;
    }
    if (currentNode == NULL)
    {
        previousNode->next = newNode;
        return OK;
    }

    previousNode->next = newNode;
    newNode->next = currentNode;
    return OK;
}

int deleteElement(SortedList *sortedList, int value)
{
    if (sortedList == NULL)
    {
        return OUT_OF_MEMORY;
    }

    // Если список пуст
    if (sortedList->head == NULL)
    {
        return OK;
    }
    // Если удаляем голову
    if (value == sortedList->head->value)
    {
        Node *tmp = sortedList->head;
        sortedList->head = sortedList->head->next;
        free(tmp);
        return OK;
    }

    Node *currentNode = sortedList->head;
    Node *previousNode = NULL;
    while (currentNode != NULL && value > currentNode->value)
    {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    // Удаление элемента, у которого есть и предок, и ребенок
    if (currentNode != NULL && value == currentNode->value)
    {
        previousNode->next = currentNode->next;
        free(currentNode);
        return OK;
    }
    // Удаление если нет ребёнка
    previousNode->next = NULL;
    free(currentNode);
    return OK;
}

int printSoredList(SortedList *sortedList)
{
    if (sortedList == NULL)
    {
        return OUT_OF_MEMORY;
    }

    Node *currentNode = sortedList->head;
    printf("SortedList: ");
    while (currentNode != NULL)
    {
        printf("%d ", currentNode->value);
        currentNode = currentNode->next;
    }
    printf("\n\n");
    return OK;
}

int get(SortedList *sortedList, int index, int *result)
{
    if (sortedList == NULL)
    {
        return OUT_OF_MEMORY;
    }

    Node *currentNode = sortedList->head;
    int i = 0;
    while (currentNode != NULL && i < index)
    {
        currentNode = currentNode->next;
        ++i;
    }
    if (i == index)
    {
        *result = currentNode->value;
        return OK;
    }
    return OUT_OF_LIST;
}