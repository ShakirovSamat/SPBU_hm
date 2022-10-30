#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mergeSort.h"

void merge(Person *(*array), Person *first[], Person *second[], int firstLen, int secondLen, int byWhatSort)
{
    int firstIndex = 0;
    int secondIndex = 0;

    while (firstIndex < firstLen && secondIndex < secondLen)
    {
        if (byWhatSort == 1)
        {
            if (strcmp(first[firstIndex]->name, second[secondIndex]->name) < 0)
            {
                array[firstIndex + secondIndex] = first[firstIndex];
                firstIndex++;
            }
            else
            {
                array[firstIndex + secondIndex] = second[secondIndex];
                secondIndex++;
            } 
        }
        else
        {
            if (strcmp(first[firstIndex]->number, second[secondIndex]->number) < 0)
            {
                array[firstIndex + secondIndex] = first[firstIndex];
                firstIndex++;
            }
            else
            {
                array[firstIndex + secondIndex] = second[secondIndex];
                secondIndex++;
            } 
        }
    }

    while (firstIndex < firstLen)
    {
        array[firstIndex + secondIndex] = first[firstIndex];
        firstIndex++;
    }

    while (secondIndex < secondLen)
    {
        array[firstIndex + secondIndex] = second[secondIndex];
        secondIndex++;
    }
}

void mergeSort(Person *(*array), int len, int byWhatSort)
{
    if (len <= 1)
    {
        return;
    }
    int mid = len / 2;
    Person *(*left) = calloc(1, sizeof(Person) * mid);
    Person *(*right) = calloc(1, sizeof(Person) * (len - mid));

    for(int i = 0; i < mid; ++i)
    {
        left[i] = array[i];
    }
    for (int i = mid; i < len; ++i)
    {
        right[i - mid] = array[i];
    }

    mergeSort(left, mid, byWhatSort);
    mergeSort(right, len - mid, byWhatSort);
    merge(array, left, right, mid, len - mid, byWhatSort);
}

bool test()
{
    Person one = {"Sosiska", "+7912345678"};
    Person two = {"Sardelka", "+7987654321"};
    Person *persons[2] = {&one, &two};
    mergeSort(persons, 2, 1);
    if (strcmp(persons[0]->name, "Sardelka") != 0)
    {
        return false;
    }
    if (strcmp(persons[1]->name, "Sosiska") != 0)
    {
        return false;
    }
    if (strcmp(persons[0]->number, "+7987654321") != 0)
    {
        return false;
    }
    if (strcmp(persons[1]->number, "+7912345678") != 0)
    {
        return false;
    }

    mergeSort(persons, 2, 2);
    if (strcmp(persons[1]->name, "Sardelka") != 0)
    {
        return false;
    }
    if (strcmp(persons[0]->name, "Sosiska") != 0)
    {
        return false;
    }
    if (strcmp(persons[1]->number, "+7987654321") != 0)
    {
        return false;
    }
    if (strcmp(persons[0]->number, "+7912345678") != 0)
    {
        return false;
    }
    return true;  
}