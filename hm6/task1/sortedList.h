#ifndef CORE_H_INCLUDED
#define CORE_H_INCLUDED
#include <stdbool.h>

typedef enum Error
{
    OK,
    MemoryError
} Error;

typedef struct SortedList SortedList;

SortedList *createSortedList();

// Adding new element to sorted list
// has error code = -1
int addValue(SortedList *SortedList, int value);

// Deleting elemnet of sorted list
// has error code = -1
int deleteValue(SortedList *sortedList, int value);

// Printing sorted list in console
// has error code = -1
int printList(SortedList *sortedList);

// Tests for sorted list
bool sortedListTest();

#endif // CORE_H_INCLUDED
