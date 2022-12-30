#pragma once

#include <stdbool.h>
#include <stdlib.h>

typedef enum Errors
{
    OUT_OF_MEMORY,
    OK,
    INPUT_ERROR
} Errors;

typedef struct LoopedList LoopedList;
// Написать комментарии для функций
LoopedList *createLoopedList();

int add(LoopedList *loopedlist, int value);

int get(LoopedList *loopedList, int index);

int delete(LoopedList *loopedList, int value);

int getLen(LoopedList *loopedList);

int printList(LoopedList *loopedList);

bool isOnlyOneElement(LoopedList *loopedList);