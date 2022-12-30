#include <stdio.h>
#include <string.h>
#include "phoneBook.h"

int main()
{
    int command = -1;
    Person phoneBook[100];
    int amountOfPersons = 0;

    printf("This is a phone book\nCommands:\n0 - Exit\n1 - Add person\n2 - Show list of all people\n3 - Find phone number by name"
           "\n4 - Find nume by phone number\n5 - Save added data\n");
    printf("Enter command: ");
    scanf("%d", &command);

    while (command != 0)
    {

        switch (command)
        {
        case 1:
        {
            char name[20] = {0};
            char number[20] = {0};

            printf("\nEnter name: ");
            fflush(stdin);
            fgets(name, 20, stdin);
            fflush(stdin);

            printf("Enter number: ");
            fgets(number, 20, stdin);
            fflush(stdin);
            printf("\n");

            name[strlen(name) - 1] = '\0';
            number[strlen(number) - 1] = '\0';

            addPerson(phoneBook, &amountOfPersons, name, number);
            break;
        }
        case 2:
            showPhoneBook("Data.txt", phoneBook, amountOfPersons);
            break;
        case 3:
        {
            char searchName[20] = {0};

            printf("Enter name: ");
            fflush(stdin);
            fgets(searchName, 20, stdin);
            fflush(stdin);
            searchName[strlen(searchName) - 1] = '\0';

            findNumberByName("Data.txt", phoneBook, amountOfPersons, searchName);
            printf("\n");
            break;
        }
        case 4:
        {
            char searchNumber[20] = {0};

            printf("Enter number: ");
            fflush(stdin);
            fgets(searchNumber, 20, stdin);
            fflush(stdin);
            searchNumber[strlen(searchNumber) - 1] = '\0';

            findNameByNumber("Data.txt", phoneBook, amountOfPersons, searchNumber);
            printf("\n");
            break;
        }
        case 5:
            savePersons("Data.txt", phoneBook, &amountOfPersons);
            break;
        default:
            printf("This command doesn't exists\n");
        }

        printf("Enter command: ");
        scanf("%d", &command);
    }

    return 0;
}