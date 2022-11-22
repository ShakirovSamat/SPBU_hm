#pragma once;
#include <stdbool.h>

typedef struct List List;

List *listCreate();

int listAdd(List *list, char *word);

int listLength(List *list);

bool listIsEmpty(List *list);

int listPrint(List *list);