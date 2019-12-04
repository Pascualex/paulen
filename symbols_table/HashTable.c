#include "HashTable.h"
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 8

typedef struct _Entry Entry;

struct _HashTable {
	Entry **entries;	
	int size;
};

struct _Entry {
	char key[51];
	int value;
	Entry *next;
};

Entry *Entry_create(char key[51], int value);
void Entry_free(Entry *entry);

unsigned long hash_key(char id[51]);

HashTable *HashTable_create() {
    HashTable *hash_table;
    int i;

    hash_table = (HashTable *) malloc(sizeof(HashTable));
    if (hash_table == NULL) return NULL;

    hash_table->entries = (Entry **) malloc(sizeof(Entry *)*INITIAL_SIZE);
    if (hash_table->entries == NULL) {
        free(hash_table);
        return NULL;
    }

    for (i = 0; i < INITIAL_SIZE; i++) {
        hash_table->entries[i] = NULL;
    }

    hash_table->size = INITIAL_SIZE;

    return hash_table;
}

void HashTable_free(HashTable *hash_table) {
    int i;

    if (hash_table == NULL) return;

    for (i = 0; i < hash_table->size; i++) {
        if (hash_table->entries[i] != NULL) Entry_free(hash_table->entries[i]);
    }

    free(hash_table->entries);
    free(hash_table);
}

void HashTable_put(HashTable *hash_table, char key[51], int value) {
    Entry *current_entry;
    int index;

    if (hash_table == NULL) return;

    index = hash_key(key)%hash_table->size;
    if (hash_table->entries[index] == NULL) {
        hash_table->entries[index] = Entry_create(key, value);
    } else {
        current_entry = hash_table->entries[index];
        if (strcmp(current_entry->key, key) == 0) {
            current_entry->value = value;
            return;
        }
        while (current_entry->next != NULL) {
            current_entry = current_entry->next;
            if (strcmp(current_entry->key, key) == 0) {
                current_entry->value = value;
                return;
            }
        }
        current_entry->next = Entry_create(key, value);
    }
}

bool HashTable_contains_key(HashTable *hash_table, char key[51]) {
    Entry *current_entry;
    int index;

    if (hash_table == NULL) return false;

    index = hash_key(key)%hash_table->size;
    if (hash_table->entries[index] == NULL) {
        return false;
    } else {
        current_entry = hash_table->entries[index];
        if (strcmp(current_entry->key, key) == 0) return true;
        while (current_entry->next != NULL) {
            current_entry = current_entry->next;
            if (strcmp(current_entry->key, key) == 0) return true;
        }
        return false;
    }
}

int HashTable_get(HashTable *hash_table, char key[51]) {
    Entry *current_entry;
    int index;

    if (hash_table == NULL) return ERROR;

    index = hash_key(key)%hash_table->size;
    if (hash_table->entries[index] == NULL) {
        return ERROR;
    } else {
        current_entry = hash_table->entries[index];
        if (strcmp(current_entry->key, key) == 0) return current_entry->value;
        while (current_entry->next != NULL) {
            current_entry = current_entry->next;
            if (strcmp(current_entry->key, key) == 0) return current_entry->value;
        }
        return ERROR;
    }
}

Entry *Entry_create(char key[51], int value) {
    Entry *entry;

    entry = (Entry *) malloc(sizeof(Entry));
    if (entry == NULL) return NULL;

    strcpy(entry->key, key);
    entry->value = value;
    entry->next = NULL;

    return entry;
}

void Entry_free(Entry *entry) {
    if (entry == NULL) return;
    if (entry->next != NULL) Entry_free(entry->next);
    free(entry);
}

unsigned long hash_key(char key[51]) {
    unsigned long hash;
    int i;

    hash = 5381;
    i = 0;
    while (key[i] != '\0' && i < 51) {
        hash = ((hash<<5)+hash)+key[i];
        i++;
    }

    return hash;
}