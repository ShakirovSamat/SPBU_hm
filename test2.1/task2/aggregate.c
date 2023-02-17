#include <stdlib.h>
#include <stdio.h>
#include "aggregate.h"

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

Aggregate *createAggregate()
{
    return calloc(1, sizeof(Aggregate));
}

int insert(Aggregate *aggregate, int value)
{
    if (aggregate == NULL)
    {
        return -1;
    }
    if (aggregate->head == NULL)
    {
        aggregate->head = calloc(1, sizeof(Node));
        if (aggregate->head == NULL)
        {
            return -1;
        }
        aggregate->head->value = value;
    }

    Node *currentNode = aggregate->head;
    Node *previousNode = NULL;

    Node *newNode = calloc(1, sizeof(Node));
    if (newNode == NULL)
    {
        return -1;
    }
    newNode->value = value;

    while (currentNode != NULL)
    {
        if (currentNode->value == value)
        {
            return 0;
        }
        if (currentNode->value > value)
        {
            if (previousNode == NULL)
            {
                newNode->next = aggregate->head;
                aggregate->head = newNode;
                return 0;
            }

            previousNode->next = newNode;
            newNode->next = currentNode;
            return 0;
        }
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    previousNode->next = newNode;
    return 0;
}

int deleteAggregate(Aggregate *aggregate)
{
    if (aggregate == NULL)
    {
        return -1;
    }

    Node *currentNode = aggregate->head;
    while (currentNode != NULL)
    {
        Node *tmp = currentNode;
        currentNode = currentNode->next;
        free(tmp);
    }
    free(aggregate);
    return 0;
}

int print(Aggregate *aggregate)
{
    if (aggregate == NULL)
    {
        return -1;
    }
    Node *currentNode = aggregate->head;
    printf("{");
    while (currentNode != NULL)
    {
        if (currentNode->next == NULL)
        {
            printf("%d", currentNode->value);
        }
        else
        {
            printf("%d, ", currentNode->value);
        }
        currentNode = currentNode->next;
    }
    printf("}\n\n");
}

int merge(Aggregate *aggr1, Aggregate *aggr2)
{
    if (aggr1 == NULL || aggr2 == NULL)
    {
        return -1;
    }

    Node *currentNode = aggr2->head;
    while (currentNode != NULL)
    {
        insert(aggr1, currentNode->value);
        currentNode = currentNode->next;
    }
    deleteAggregate(aggr2);
    return 0;
}