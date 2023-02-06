#include <stddef.h>
#include <stdlib.h>
#include "linkedList.h"

typedef struct Person
{
    char *name;
    char *number;
} Person;

typedef struct Node
{
    Person *person;
    struct Node *next;
} Node;

typedef struct LinkedList
{
    struct Node *head;
} LinkedList;

LinkedList *createLinkedList()
{
    return calloc(1, sizeof(LinkedList));
}

int insert(LinkedList *linkedList, Person *person)
{
    if (linkedList == NULL)
    {
        return OUT_OF_MEMORY;
    }

    Node *newNode = calloc(1, sizeof(Node));
    if (newNode == NULL)
    {
        return OUT_OF_MEMORY;
    }
    newNode->person = person;

    if (linkedList->head == NULL)
    {
        linkedList->head = newNode;
        return OK;
    }

    Node *currentNode = linkedList->head;
    while (currentNode->next != NULL)
    {

        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
    return OK;
}

int length(LinkedList *linkedList)
{
    if (linkedList == NULL || linkedList->head == NULL)
    {
        return 0;
    }

    Node *currentNode = linkedList->head;
    int listLength = 0;
    while (currentNode != NULL)
    {
        ++linkedList;
        currentNode = currentNode->net;
    }

    return listLength;
}

Person *get(LinkedList *linkedList, int index)
{
    Node *currentNode = linkedList->head;
    for (int i = 0; i < index; ++i)
    {
        currentNode = currentNode->next;
        if (currentNode == NULL)
        {
            return;
        }
    }
    return currentNode->person;
}
void swap(Person *person1, Person *person2)
{
    Person *tmp = person1;
    person1 = person2;
    person2 = tmp;
}
int mergerSort(LinkedList *linkedList, char *iterator)
{
    if (linkedList == NULL)
    {
        OUT_OF_MEMORY;
    }
    int step = 2;
    for (int i = step; i < length(linkedList); i *= 2)
    {
        for (int j = i - step; j < i; ++j)
        {
            Person *person1 = get(linkedList, j);
            Person *person2 = get(linkedList, j + 1);
            if (strcmp(iterator, "name") == 0 && strcmp(person1->name, person2->name > 0))
            {
                swap(person1, person2);
            }
        }
        step *= 2;
    }
}

int printLinkedList(LinkedList *linkedList)
{
    if (linkedList == NULL)
    {
        return OUT_OF_MEMORY;
    }

    Node *currentNode = linkedList->head;

    while (currentNode != NULL)
    {
        printf("%s - %s", name, number);
        currentNode = currentNode->next;
    }

    return OK;
}