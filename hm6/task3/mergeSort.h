#ifndef CORE_H_INCLUDED
#define CORE_H_INCLUDED

#include <stdbool.h>

typedef struct{
    char name[20];
    char number[20];
}Person;

void merge(Person *(*array), Person *first[], Person *second[], int firstLen, int secondLen, int byWhatSort);

void mergeSort(Person *(*array), int len, int byWhatSort);

bool test();

#endif // CORE_H_INCLUDED
