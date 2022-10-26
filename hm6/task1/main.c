#include <stdio.h>
#include "sortedList.h"

int main()
{
    int comand = -1;
    SortedList *sortedList = createSortedList(); 
    do
    {
        printf("\nEnter comand: ");
        scanf_s("%d", &comand);

        switch (comand)
        {
            case 0:
                return 0;
                break;
            case 1:;
                int value = 0;
                printf("Enter number");
                scanf("%d", &value);
                addValue(sortedList, value);
                break;
            case 2:;
                int dvalue = 0;
                printf("Enter number");
                scanf("%d", &dvalue);
                deleteValue(sortedList, dvalue);
                break;
            case 3:
                printList(sortedList);
                break;
        }
    } while (comand != 0);
    
    return 0;
}