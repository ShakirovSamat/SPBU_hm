#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

typedef struct HashTable
{
    int hashSize;
    List *(*data);
} HashTable;

HashTable *hashTableCreate(int hashSize)
{
    HashTable *hashTable = calloc(1, sizeof(HashTable));
    hashTable->hashSize = hashSize;
    hashTable->data = calloc(hashSize, sizeof(List *));

    for (int i = 0; i < hashSize; ++i)
    {
        hashTable->data[i] = listCreate();
    }

    return hashTable;
}
int hashFunction(HashTable *hashTable, char *word)
{
    int hash = 0;
    for (int i = 0; word[i] != '\0'; ++i)
    {
        hash = (hash + word[i]) % hashTable->hashSize;
    }
    return hash;
}

int hashTableAdd(HashTable *hashTable, char *word)
{
    if (hashTable == NULL)
    {
        return -1;
    }

    int hash = hashFunction(hashTable, word);
    listAdd(hashTable->data[hash], word);
    return 0;
}
float getLoadFactor(HashTable *hashTable)
{
    float existing = 0;
    for (int i = 0; i < hashTable->hashSize; ++i)
    {
        if (listIsEmpty(hashTable->data[i]))
        {
            ++existing;
        }
    }
    return existing / hashTable->hashSize;
}

float getAveregeSize(HashTable *hashTable)
{
    float sum = 0;
    for (int i = 0; i < hashTable->hashSize; ++i)
    {
        sum += listLength(hashTable->data[i]);
    }
    return sum / hashTable->hashSize;
}

int getMaxSize(HashTable *hashTable)
{
    int max = 0;
    for (int i = 0; i < hashTable->hashSize; ++i)
    {
        int length = listLength(hashTable->data[i]);
        if (length > max)
        {
            max = length;
        }
    }
    return max;
}

int hashTableInfoPrint(HashTable *hashtable)
{
    if (hashtable == NULL)
    {
        return -1;
    }
    printf("\nInforamtion\n\n");
    printf("load facor: %f\n", getLoadFactor(hashtable));
    printf("Averege size of list: %f\n", getAveregeSize(hashtable));
    printf("Max size of list: %d\n\n", getMaxSize(hashtable));

    return 0;
}

int hashTablePrint(HashTable *hashTable)
{
    if (hashTable == NULL)
    {
        return -1;
    }

    for (int i = 0; i < hashTable->hashSize; ++i)
    {
        listPrint(hashTable->data[i]);
    }
    return 0;
}