#include <stdio.h>
#include <string.h>
#include "phoneBook.h"

int testAdd(Person *phoneBook, int *amountOfPersons)
{
    return addPerson(phoneBook, amountOfPersons);
}

int testShowList(char *path, Person *phoneBook, int *amountOfPersons)
{
    return showList(path, phoneBook, amountOfPersons);
}

int testSavePeron(char *parh, Person *phoneBook, int *amountOfPersons)
{
    return savePersons(path, phoneBook, amountOfPersons);
}

int testFindNumberByName(char *parh, Person *phoneBook, int amountOfPersons)
{
    return findNumberByName(parh, phoneBook, amountOfPersons);
}

int testFindNameByNumber(char *parh, Person *phoneBook, int amountOfPersons)
{
    return findNameByNumber(path, phoneBook, amountOfPersons);
}
int main()
{
    int comand = -1;
    Person phoneBook[100];
    int amountOfPersons = 0;
    if (!testAdd(phoneBook, &amountOfPersons))
    {
        printf("Add error");
        return -1;
    }
    if (!testShowList("Data.txt", phoneBook, amountOfPersons))
    {
        printf("ShowList error");
        return -1;
    }
    if (!testSavePeron("Test.txt", phoneBook, &amountOfPersons))
    {
        printf("AddPerrsons error");
        return -1;
    }
    if (!testFindNumberByName("Data.txt", phoneBook, amountOfPersons))
    {
        printf("FindNumberByName error");
        return -1;
    }
    if (!testFindNameByNumber("Data.txt", phoneBook, amountOfPersons))
    {
        printf("FindNameByNumber error");
        return -1;
    }

    printf("This is a phone book\nComands:\n0 - Exit\n1 - Add person\n2 - Show list of all people\n3 - Find phone number by name"
    "\n4 - Find nume by phone number\n5 - Save added data\n");
    printf("Enter comand: ");
    scanf("%d", &comand);

    while (comand != 0)
    {
        
        switch (comand)
        {
            case 1:
                addPerson(phoneBook, &amountOfPersons);
                break;
            case 2:
                showList("Data.txt", phoneBook, amountOfPersons);
                break;
            case 3:;
                findNumberByName("Data.txt", phoneBook, amountOfPersons);
                break;
            case 4:
                findNameByNumber("Data.txt",phoneBook, amountOfPersons);
                break;
            case 5:
                savePersons("Data.txt", phoneBook, &amountOfPersons);
                break;
            default:
                printf("This comand doesn't exists\n"); 
        }
        
        printf("Enter comand: ");
        scanf("%d", &comand);
    }
    
    
    return 0;
}