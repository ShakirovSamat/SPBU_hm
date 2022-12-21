#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "loopedList.h"

typedef int Error;

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

typedef struct LoopedList
{
    Node *head;
    Node *tail;
} LoopedList;

LoopedList *create()
{
    return calloc(1, sizeof(LoopedList));
}

Error add(LoopedList *list, int value)
{
    if (list == NULL)
    {
        return -1;
    }

    Node *newNode = calloc(1, sizeof(Node));
    // Проверить память
    newNode->value = value;

    if (list->head == NULL)
    {
        newNode->next = newNode;
        list->head = newNode;
        list->tail = newNode;
        return 0;
    }

    list->tail->next = newNode;
    newNode->next = list->head;
    list->tail = newNode;
    return 0;
}
// Синхронизировать индексы в функциях
int get(LoopedList *list, int index)
{
    if (list == NULL)
    {
        return -1;
    }

    Node *curNode = list->head;
    Node *prevNode = NULL;

    for (int i = 0; i < index; i++)
    {
        prevNode = curNode;
        curNode = curNode->next;
    }

    return curNode->value;
}

Error delete(LoopedList *list, int index)
{
    if (list == NULL)
    {
        return -1;
    }

    if (index < 1)
    {
        return -1;
    }

    if (index == 1)
    {
        Node *tmp = list->head;
        list->tail->next = list->head->next;
        list->head = list->tail;
        free(tmp);
        return 0;
    }

    Node *curNode = list->head;
    Node *prevNode = NULL;

    int i = 0;
    while (i < index)
    {
        prevNode = curNode;
        curNode = curNode->next;
        ++i;
    }

    list->head = curNode->next;
    list->tail = prevNode;
    list->tail->next = list->head;

    free(curNode);
    return 0;
}

int getLen(LoopedList *list)
{
    if (list == NULL)
    {
        return -1;
    }
    if (list->head == NULL)
    {
        return 0;
    }
    Node *curNode = list->head;
    int len = 1;
    while (curNode != list->tail)
    {
        len++;
        curNode = curNode->next;
    }
    return len;
}

Error printList(LoopedList *list)
{
    if (list == NULL)
    {
        return -1;
    }

    Node *curNode = list->head;

    printf("List: ");
    if (list->head == NULL)
    {
        return 0;
    }
    while (curNode != list->tail)
    {
        printf("%d ", curNode->value);
        curNode = curNode->next;
    }

    printf("%d", curNode->value);
    return 0;
}
