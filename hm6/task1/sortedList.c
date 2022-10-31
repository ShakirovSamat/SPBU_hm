#include "sortedList.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Node
{
    int value;
    struct Node *next;
}Node;

typedef struct SortedList
{
    Node *head;
}SortedList;

SortedList * createSortedList()
{
    return calloc(1, sizeof(SortedList));
}

int addValue(SortedList *sortedList, int value)
{
    if (sortedList == NULL)
    {
        return -1;
    }

    Node *newNode = calloc(1, sizeof(Node));
    newNode->value = value;
    
    Node *prevNode = NULL;
    Node *curNode = sortedList->head;

    if (sortedList->head == NULL)
    {
        sortedList->head = newNode;
        return 0;
    }
    if (value <= sortedList->head->value)
    {
        newNode->next = sortedList->head;
        sortedList->head = newNode;
        return 0;
    }

    while (curNode->next != NULL)
    {
        prevNode = curNode;
        curNode = curNode->next;

        if (prevNode->value <= value && value <= curNode->value)
        {
            prevNode->next = newNode;
            newNode->next = curNode;
            return 0;
        }
    }
    curNode->next = newNode;
    return 0;
}

int deleteValue(SortedList *sortedList, int value)
{
    if (sortedList == NULL)
    {
        return -1;
    }
    Node *prevNode = NULL;
    Node *curNode = sortedList->head;

    if (curNode->value == value)
    {
        sortedList->head = curNode->next;
        free(curNode);
        return 0;
    }

    while (curNode != NULL)
    {
        prevNode = curNode;
        curNode = curNode->next;

        if (value == curNode->value)
        {
            prevNode->next = curNode->next;
            free(curNode);
            return 0;
        }
    }

    return 0;
}

int printList(SortedList *sortedList)
{
    if (sortedList == NULL)
    {
        return -1;
    }
    Node *curNode = sortedList->head;
    while (curNode != NULL)
    {
        printf("%d ", curNode->value);
        curNode = curNode->next;
    }
    return 0;
}

bool sortedListTest()
{
    SortedList *list = createSortedList();
    addValue(list, 1);
    addValue(list, 5);
    addValue(list, 2);
    addValue(list, 7);
    deleteValue(list, 5);
    if (list->head->value != 1)
    {
        return false;
    }
    if (list->head->next->value != 2)
    {
        return false;
    }
    if (list->head->next->next->value != 7)
    {
        return false;
    }
    return true;
}