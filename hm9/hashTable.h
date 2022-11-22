#pragma once

typedef struct HashTable HashTable;

HashTable *hashTableCreate(int hashSize);

int hashTableAdd(HashTable *hashTable, char *word);

int hashTableInfoPrint(HashTable *hashtable);

int hashTablePrint(HashTable *hashTable);