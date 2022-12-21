#pragma once

typedef struct Aggregate
{
    struct Node *head;
} Aggregate;

Aggregate *createAggregate();

int insert(Aggregate *aggregate, int value);

int deleteAggregate(Aggregate *aggregate);

int print(Aggregate *aggregate);

int merge(Aggregate *aggr1, Aggregate *aggr2);