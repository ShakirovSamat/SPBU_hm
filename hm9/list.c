#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Node
{
    int amount;
    char *word;
    struct Node *next;
} Node;

typedef struct List
{
    struct Node *head;
} List;

List *listCreate()
{
    return calloc(1, sizeof(List));
}

int listAdd(List *list, char *word)
{
    if (list == NULL)
    {
        return -1;
    }

    if (list->head == NULL)
    {
        list->head = calloc(1, sizeof(Node));
        list->head->word = word;
        list->head->amount = 1;
        return 0;
    }

    Node *currentNode = list->head;
    Node *previousNode = NULL;
    while (currentNode != NULL)
    {
        if (strcmp(currentNode->word, word) == 0)
        {
            ++currentNode->amount;
            return 0;
        }
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    Node *newNode = calloc(1, sizeof(Node));
    newNode->word = word;
    newNode->amount = 1;
    previousNode->next = newNode;
    return 0;
}

int listLength(List *list)
{
    if (list == NULL)
    {
        return -1;
    }

    Node *currentNode = list->head;
    int length = 0;
    while (currentNode != NULL)
    {
        currentNode = currentNode->next;
        ++length;
    }
    return length;
}

bool listIsEmpty(List *list)
{
    if (list->head == NULL)
    {
        return true;
    }
    return false;
}
int listPrint(List *list)
{
    if (list == NULL)
    {
        return -1;
    }

    Node *currentNode = list->head;
    while (currentNode != NULL)
    {
        printf("%s %d\n", currentNode->word, currentNode->amount);
        currentNode = currentNode->next;
    }
    return 0;
}