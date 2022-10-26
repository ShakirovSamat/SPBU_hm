#ifndef CORE_H_INCLUDED
#define CORE_H_INCLUDED

typedef struct SortedList SortedList;

SortedList * createSortedList();

int addValue(SortedList *SortedList, int value);

int deleteValue(SortedList *sortedList, int value);

int printList(SortedList *sortedList);

#endif // CORE_H_INCLUDED
