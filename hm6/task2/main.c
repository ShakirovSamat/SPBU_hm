#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "loopedList.h"

bool test()
{
    LoopedList *list = create();
    int input[2][3] = {{10, 5, 3}, {5, 2, 3}};
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < input[i][0]; ++j)
        {
            add(list, j + 1);
        }
        while (getLen(list) != 1)
        {
            delete (list, input[i][1]);
        }
        if (get(list, 0) != input[i][2])
        {
            return false;
        }
        delete (list, 0);
    }
    return true;
}

int main()
{
    // Добавить тесты на алгоритм фунции
    if (!test())
    {
        // Расширить информацию об ошибке
        printf("Error");
        return -1;
    }
    int amountOfWarriors = 0;
    int step = 0;
    LoopedList *list = create();
    // Проверка памяти
    //  Проверить корректность ввода
    printf("Enter amount of warriors: ");
    scanf_s("%d", &amountOfWarriors);

    printf("Enter step: ");
    scanf_s("%d", &step);

    for (int i = 0; i < amountOfWarriors; ++i)
    {
        add(list, i + 1);
    }

    // Добавить фунцию, которая проверят состоит ли список из одного элемента
    while (getLen(list) != 1)
    {
        printList(list);
        printf("\n");
        delete (list, step - 1);
    }
    printf("Number of last warrior: %d", get(list, 0));
    return 0;
}