#pragma once

enum Errors
{
    OUT_OF_MEMORY,
    OK,
    BAD_INPUT
};

typedef struct Person Person;

typedef struct LinledList LinkedList;

LinkedList *createLinkedList();

int insert(LinkedList *linkedList, Person *person);

int mergerSort(LinkedList *linkedList, char *iterator);