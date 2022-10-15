#ifndef CORE_H_INCLUDED
#define CORE_H_INCLUDED

typedef struct{
    char name[20];
    char number[20];
}Person;

void showList(char* path, Person* phoneBook, int amountOfPersons);

void addPerson(Person* phoneBook, int* amountOfPersons);

void savePersons(char* path, Person* phoneBook, int* amountOfPersons);

void findNumberByName(char* path, Person* phoneBook, int amountOfPersons);

void findNameByNumber(char* path, Person* phoneBook, int amountOfPersons);


#endif // CORE_H_INCLUDED
