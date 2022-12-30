#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "loopedList.h"

bool test()
{
    LoopedList *list = create();
    int input[2][3] = {{10, 5, 3}, {5, 2, 3}};
    for (int i = 0; i  < 2; ++i)
    {
        for (int j = 0; j < input[i][0]; ++j)
        {
            append(list, j + 1);
        }
        while (getLen(list) != 1)
        {
        delete(list, input[i][1]);
        }
        if (get(list, 0) != input[i][2])
        {
            return false;
        }
        delete(list, 0);
    }
    return true;
}

int main()
{
    if (!test())
    {
        printf("Error");
        return -1;
    }
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
    printf("Number of last warrior: %d", get(list, 0));
    return 0;
}