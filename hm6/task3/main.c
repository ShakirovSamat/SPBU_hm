#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <linkedList.h>

int main()
{
    LinkedList *linkedList = createLinkedList();
    if (linkedList == NULL)
    {
        return OUT_OF_MEMRY;
    }

    FILE *file = fopen("data.txt", "r");
    int error = readFile(file, linkedList);
    if (error != OK)
    {
        return error;
    }
    int command = 0;
    printf("File was readed sucessfully\nBy what do you wantt sort number or namer?\n");
    printf("1 - number\n2- name\n3 - exit\n");
    while (command != 3)
    {
        printf("Enter command: ");
        scanf("%d", &command);
        printf("\n\n");
        switch (command)
        {
        case 1:
            mergerSort(linkedList, "number");
            printLinkedList(linkedList);
            break;
        case 2:
            mergerSort(linkedList, "name");
            printLinkedList(linkedList);
            break;
        case 3:
            return OK;
        }
    }
    return OK;
}