#include <stdio.h>
#include <stdbool.h>
#include "sortedList.h"

bool test()
{
    SortedList *sortedList = createSortedList();
    if (sortedList == NULL)
    {
        return false;
    }

    insert(sortedList, 9);
    insert(sortedList, 1);
    insert(sortedList, 4);
    deleteElement(sortedList, 4);
    insert(sortedList, 5);
    insert(sortedList, 3);
    insert(sortedList, 3);
    deleteElement(sortedList, 3);
    deleteElement(sortedList, 563);
    insert(sortedList, 69);
    insert(sortedList, 69);
    printSoredList(sortedList);
    int expectedResult[6] = {1, 3, 5, 9, 69, 69};
    int result = 0;
    for (int i = 0; i < 6; ++i)
    {
        get(sortedList, i, &result);
        if (expectedResult[i] != result)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    if (!(test()))
    {
        return -1;
    }
    SortedList *sortedList = createSortedList();
    if (sortedList == NULL)
    {
        return OUT_OF_MEMORY;
    }

    int command = -1;

    printf("Command:\n0 - exit from program\n1 - add new element to sorted list\n2 - delete element from sored list\n3 - print sorted list\n4 - print commands\n\n");

    while (command != 0)
    {
        printf("Enter command: ");
        scanf("%d", &command);

        switch (command)
        {
        case 0:
            return 0;
        case 1:
        {
            int value = 0;
            printf("Enter value: ");
            scanf("%d", &value);
            int error = insert(sortedList, value);
            if (error != OK)
            {
                return error;
            }
            break;
        }
        case 2:
        {
            int value = 0;
            printf("Enter value: ");
            scanf("%d", &value);
            int error = deleteElement(sortedList, value);
            if (error != OK)
            {
                return error;
            }
            break;
        }
        case 3:
            printSoredList(sortedList);
            break;
        case 4:
            printf("Command:\n0 - exit from program\n1 - add new element to sorted list\n2 - delete element from sored list\n3 - print sorted list\n4 - print commands\n\n");
            break;
        }
    }
    return 0;
}