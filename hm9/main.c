#include <stdio.h>
#include <stdlib.h>
#include "hashTable.h"

#define HASHSIZE 125
int main()
{
    HashTable *hashTable = hashTableCreate(HASHSIZE);
    FILE *file = fopen("text.txt", "r");

    char c;
    char *word = calloc(30, sizeof(char));
    int index = 0;
    for (;;)
    {
        c = fgetc(file);
        if (c == EOF)
        {
            hashTableAdd(hashTable, word);
            break;
        }
        if (c == ' ')
        {
            hashTableAdd(hashTable, word);
            index = 0;
            word = calloc(30, sizeof(char));
        }
        else
        {
            word[index] = c;
            ++index;
        }
    }

    hashTablePrint(hashTable);
    hashTableInfoPrint(hashTable);
    return 0;
}