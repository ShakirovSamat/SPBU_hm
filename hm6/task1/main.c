#include <stdio.h>
#include "sortedList.h"
#include <stdbool.h>

int main()
{
    if (!sortedListTest())
    {
        printf("Error in SortedList");
        return -1;
    }
    int command = -1;
    SortedList *sortedList = createSortedList();
    // Проверить память
    // Добавить список команд
    // Добавить команду печатующая список команд
    // Добавить дефолт при некорректоном коде команды
    while (true)
    {
        printf("\nEnter command: ");
        scanf_s("%d", &command);

        switch (command)
        {
        case 0:
            // Чистка памяти
            return 0;
        case 1:
        {
            int value = 0;
            printf("Enter number: ");
            scanf("%d", &value);
            addValue(sortedList, value);
            break;
        }
        case 2:
        {
            int dvalue = 0;
            printf("Enter number: ");
            scanf("%d", &dvalue);
            deleteValue(sortedList, dvalue);
            break;
        }
        case 3:
            printList(sortedList);
            break;
        }
    }
    //  Чистка памяти
}