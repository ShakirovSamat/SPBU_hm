#pragma once

enum Errors
{
    OUT_OF_MEMORY,
    OK,
    OUT_OF_LIST
};

typedef struct SortedList SortedList;

SortedList *createSortedList();

int insert(SortedList *sortedList, int value);

int deleteElement(SortedList *sortedList, int value);

int printSoredList(SortedList *sortedList);

int get(SortedList *sortedList, int index, int *result);