#ifndef CORE_H_INCLUDED
#define CORE_H_INCLUDED
#include <stdbool.h>

typedef struct SortedList SortedList;

SortedList * createSortedList();

int addValue(SortedList *SortedList, int value);

int deleteValue(SortedList *sortedList, int value);

int printList(SortedList *sortedList);

bool sortedListTest();

#endif // CORE_H_INCLUDED
