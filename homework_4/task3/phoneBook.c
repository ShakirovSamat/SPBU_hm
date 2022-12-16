#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "phoneBook.h"

int showPhoneBook(char *path, Person *phoneBook, int amountOfPersons)
{
    FILE *fl = fopen(path, "r");
    if (fl == NULL)
    {
        return -1;
    }
    char name[20];
    char number[20];
    int line = 1;
    printf("\n");
    while (fscanf(fl, "%s %s", name, number) != EOF)
    {
        printf("%d) Name: %s; Number: %s\n", line, name, number);
        ++line;
    }

    for (int i = 0; i < amountOfPersons; ++i)
    {
        printf("%d) Name: %s; Number: %s\n", line + i, phoneBook[i].name, phoneBook[i].number);
    }
    printf("\n");
    fclose(fl);
    return 0;
}

int addPerson(Person *phoneBook, int *amountOfPersons)
{
    if (phoneBook == NULL)
    {
        return -1;
    }
    char name[20];
    char number[20];
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
    Person newPerson;
    strcpy(newPerson.name, name);
    strcpy(newPerson.number, number);
    phoneBook[*amountOfPersons] = newPerson;
    if (phoneBook[*amountOfPersons].name == NULL || phoneBook[*amountOfPersons].number == NULL)
    {
        return -1;
    }
    ++(*amountOfPersons);

    return 0;
}

int savePersons(char *path, Person *phoneBook, int *amountOfPersons)
{
    FILE *fl = fopen(path, "a");
    if (fl == NULL)
    {
        return -1;
    }
    for (int i = 0; i < *amountOfPersons; ++i)
    {
        fputs(phoneBook[i].name, fl);
        fputs(" ", fl);
        fputs(phoneBook[i].number, fl);
        fputs("\n", fl);
    }
    fclose(fl);
    amountOfPersons = 0;
    return 0;
}

int findNumberByName(char *path, Person *phoneBook, int amountOfPersons)
{
    FILE *fl = fopen(path, "r");
    if (fl == NULL)
    {
        return -1;
    }
    char searchName[20];
    printf("Enter name: ");
    printf("\n");
    fflush(stdin);
    fgets(searchName, 20, stdin);
    fflush(stdin);

    char name[20];
    char number[20];
    searchName[strlen(searchName) - 1] = '\0';

    while (fscanf(fl, "%s %s", name, number) != EOF)
    {
        if (strcmp(searchName, name) == 0)
        {
            printf("%s\n", number);
            return 0;
        }
    }

    for (int i = 0; i < amountOfPersons; ++i)
    {
        if (strcmp(searchName, phoneBook[i].name) == 0)
        {
            printf("%s\n", phoneBook[i].number);
            return 0;
        }
    }
    printf("Wasn't found\n");
    fclose(fl);
    return 0;
}

int findNameByNumber(char *path, Person *phoneBook, int amountOfPersons)
{
    FILE *fl = fopen(path, "r");
    if (fl == NULL)
    {
        return -1;
    }
    char searchNumber[20];
    printf("Enter number: ");
    fflush(stdin);
    fgets(searchNumber, 20, stdin);
    fflush(stdin);

    char name[20];
    char number[20];
    searchNumber[strlen(searchNumber) - 1] = '\0';

    while (fscanf(fl, "%s %s", name, number) != EOF)
    {
        if (strcmp(searchNumber, number) == 0)
        {
            printf("%s\n", name);
            return 0;
        }
    }

    for (int i = 0; i < amountOfPersons; ++i)
    {
        if (strcmp(searchNumber, phoneBook[i].number) == 0)
        {
            printf("%s\n", phoneBook[i].name);
            return 0;
        }
    }
    printf("Wasn't found\n");
    fclose(fl);
    return 0;
}