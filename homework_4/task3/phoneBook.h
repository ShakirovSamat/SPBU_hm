#ifndef CORE_H_INCLUDED
#define CORE_H_INCLUDED

typedef struct
{
    char name[20];
    char number[20];
} Person;

int showPhoneBook(char *path, Person *phoneBook, int amountOfPersons);

int addPerson(Person *phoneBook, int *amountOfPersons, char name[], char number[]);

int savePersons(char *path, Person *phoneBook, int *amountOfPersons);

int findNumberByName(char *path, Person *phoneBook, int amountOfPersons, char searchName[]);

int findNameByNumber(char *path, Person *phoneBook, int amountOfPersons, char searchNumber[]);

#endif // CORE_H_INCLUDED
