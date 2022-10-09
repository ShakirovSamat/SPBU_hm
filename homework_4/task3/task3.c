#include <stdio.h>
#include <string.h>

typedef struct{
    char name[20];
    char number[20];
}Person;


void showList(char* path, Person* phoneBook, int amountOfPersons)
{
    FILE* fl = fopen(path, "a+");
    char name[20];
    char number[20];
    int line = 1;
    printf("\n");
    while(fscanf(fl, "%s %s", name, number) != EOF)
    {
        printf("%d) Name: %s; Number: %s\n", line, name, number);
        ++line;
    }

    for(int i = 0; i < amountOfPersons; ++i)
    {
        printf("%d) Name: %s; Number: %s\n", line + i + 1, phoneBook[i].name, phoneBook[i].number);
    }
    printf("\n");
    fclose(fl);
}

void addPerson(Person* phoneBook, int* amountOfPersons)
{
    char name[20];
    char number[20];
    printf("Enter name: ");
    fflush(stdin);
    fgets(name, 20, stdin);
    fflush(stdin);
    printf("Enter number: ");
    fgets(number, 20, stdin);
    fflush(stdin);

    name[strlen(name) - 1] = '\0';
    number[strlen(number) - 1] = '\0';
    Person newPerson;
    strcpy(newPerson.name, name);
    strcpy(newPerson.number, number);
    phoneBook[*amountOfPersons] = newPerson;
    ++(*amountOfPersons);
}

void savePersons(char* path, Person* phoneBook, int* amountOfPersons)
{
    FILE* fl = fopen(path, "a");
    for(int i = 0; i < amountOfPersons; ++i)
    {
        fputs(phoneBook[i].name, fl);
        fputs(" ", fl);
        fputs(phoneBook[i].number, fl);
        fputs("\n", fl);
    }
    fclose(fl);
    amountOfPersons = 0;
}


int main()
{
    int comand = -1;
    Person phoneBook[100];
    int amountOfPersons = 0;
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
            case 3:

                break;
            case 4:

                break;
            case 5:
                savePersons("Data.txt", phoneBook, amountOfPersons);
                break;
            default:
                printf("This comand doesn't exists\n"); 
        }
        printf("Enter comand: ");
        scanf("%d", &comand);
    }
    
    
    return 0;
}