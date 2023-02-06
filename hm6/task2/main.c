#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "loopedList.h"

int getLastWarrior(LoopedList *warriors, int step)
{
    while (!isOnlyOneElement(warriors))
    {
        delete (warriors, step - 1);
    }
    return get(warriors, 0);
}

bool test()
{
    LoopedList *loopedList = createLoopedList();
    for (int i = 0; i < 10; ++i)
    {
        add(loopedList, i);
    }
    if (!(4 == getLastWarrior(loopedList, 3)))
    {
        return false;
    }
    for (int i = 0; i < 11; ++i)
    {
        add(loopedList, i);
    }
    if (!(7 == getLastWarrior(loopedList, 3)))
    {
        return false;
    }
    return true;
}

int main()
{
    int amountOfWarriors = 0;
    int step = 0;
    LoopedList *loopedList = createLoopedList();
    if (loopedList == NULL)
    {
        return OUT_OF_MEMORY;
    }
    printf("Enter amount of warriors: ");
    int isSuccesful = scanf_s("%d", &amountOfWarriors);
    if (!(isSuccesful))
    {
        return INPUT_ERROR;
    }

    printf("Enter step: ");
    isSuccesful = scanf_s("%d", &step);
    if (!(isSuccesful))
    {
        return INPUT_ERROR;
    }

    for (int i = 0; i < amountOfWarriors; ++i)
    {
        add(loopedList, i + 1);
    }

    int lastWarrior = getLastWarrior(loopedList, step);
    printf("Last warrior is %d", lastWarrior);
    return 0;
}