#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "mergeSort.h"

int main()
{
    if (!test())
    {
        printf("mergeSort Error");
        return -1;
    }
    int byWhatSort = -1;
    do
    {
        printf("By watch do you want to sort data:\n1 - by name\n2 - by number\nEnter comand: ");
        scanf_s("%d", &byWhatSort);
    } while(byWhatSort != 1 && byWhatSort != 2);
    
    FILE *file = fopen("data.txt", "r");
    Person *persons[100];
    int amountOfPersons = 0;
    char name[20];
    char number[20];
    for (; amountOfPersons < 100; amountOfPersons++)
    {
        if (fscanf(file, "%s %s", name, number) == EOF)
        {
            break;
        }
        Person *newPerson = calloc(1, sizeof(Person));
        strcpy(newPerson->name, name);
        strcpy(newPerson->number, number);
        persons[amountOfPersons] = newPerson; 
    }

    mergeSort(persons, amountOfPersons, byWhatSort);

    for (int i = 0; i < amountOfPersons; ++i)
    {
        printf("  %s : %s\n", persons[i]->name, persons[i]->number);
    }
    return 0;
}