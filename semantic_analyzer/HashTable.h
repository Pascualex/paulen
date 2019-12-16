#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "alfa.h"
#include <stdbool.h>

typedef struct _HashTable HashTable;

HashTable *HashTable_create();
void HashTable_free(HashTable *hash_table);
void HashTable_put(HashTable *hash_table, char key[MAX_LONGITUD_ID+1], tipo_atributos *value);
bool HashTable_contains_key(HashTable *hash_table, char key[MAX_LONGITUD_ID+1]);
tipo_atributos *HashTable_get(HashTable *hash_table, char key[MAX_LONGITUD_ID+1]);

#endif