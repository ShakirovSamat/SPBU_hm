#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "loopedList.h"

int main()
{
    int amountOfWarriors = 0;
    int step = 0;
    LoopedList *list = create();

    printf("Enter amount of warriors: ");
    scanf_s("%d", &amountOfWarriors);

    printf("Enter step: ");
    scanf_s("%d", &step);
    
    for (int i = 0; i < amountOfWarriors; ++i)
    {
        append(list, i + 1);
    }
    while (getLen(list) != 1)
    {
        delete(list, step);
    }
    printList(list);
    return 0;
}