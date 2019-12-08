#include "HashTable.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifdef DEBUG
#define DEBUG_PRINT(...) printf(__VA_ARGS__)
#else
#define DEBUG_PRINT(...) do {} while (0)
#endif

#define INITIAL_SIZE 8

typedef struct _Entry Entry;

struct _HashTable {
	Entry **entries;
    int n_entries;
	int size;
};

struct _Entry {
	char key[51];
	int value;
	Entry *next;
};

void HashTable_resize(HashTable *hash_table);

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

    hash_table->n_entries = 0;
    hash_table->size = INITIAL_SIZE;

    DEBUG_PRINT("HashTable ready (%d/%d):\n", hash_table->n_entries, hash_table->size);

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
    DEBUG_PRINT(" -> Insertion with index %d (%d/%d)\n", index, hash_table->n_entries+1, hash_table->size);
    if (hash_table->entries[index] == NULL) {
        hash_table->entries[index] = Entry_create(key, value);
        hash_table->n_entries++;
        if (hash_table->n_entries > hash_table->size/2) HashTable_resize(hash_table);
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
        hash_table->n_entries++;
        if (hash_table->n_entries > hash_table->size/2) HashTable_resize(hash_table);
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

void HashTable_resize(HashTable *hash_table) {
    Entry **new_entries, **old_entries, *current_entry;
    int old_size, i;

    if (hash_table == NULL) return;

    new_entries = (Entry **) malloc(sizeof(Entry *)*hash_table->size*2);
    if (new_entries == NULL) return;

    old_entries = hash_table->entries;
    old_size = hash_table->size;
    hash_table->entries = new_entries;
    hash_table->n_entries = 0;
    hash_table->size *= 2;

    for (i = 0; i < hash_table->size; i++) {
        hash_table->entries[i] = NULL;
    }

    DEBUG_PRINT("Resize from size %d to %d:\n", old_size, hash_table->size);
    for (i = 0; i < old_size; i++) {
        current_entry = old_entries[i];
        while (current_entry != NULL) {
            HashTable_put(hash_table, current_entry->key, current_entry->value);
            current_entry = current_entry->next;
        }
        if (old_entries[i] != NULL) Entry_free(old_entries[i]);
    }
    DEBUG_PRINT("HashTable ready (%d/%d):\n", hash_table->n_entries, hash_table->size);

    free(old_entries);
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