#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdbool.h>

#define OK 0
#define ERROR -1

typedef struct _HashTable HashTable;

HashTable *HashTable_create();
void HashTable_free(HashTable *hash_table);
void HashTable_put(HashTable *hash_table, char key[50], int value);
bool HashTable_contains_key(HashTable *hash_table, char key[50]);
int HashTable_get(HashTable *hash_table, char key[50]);

#endif