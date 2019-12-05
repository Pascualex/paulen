#include "HashTable.h"
#include <stdio.h>

int main() {
    HashTable *hash_table;

    hash_table = HashTable_create();
    if (hash_table == NULL) return -1;

    HashTable_put(hash_table, "kdmcuhjwl", 0);
    HashTable_put(hash_table, "asdijlanm", 0);
    HashTable_put(hash_table, "fkjahdlgh", 0);
    HashTable_put(hash_table, "ggyeiwosk", 0);
    HashTable_put(hash_table, "mvzmcywiq", 0);
    HashTable_put(hash_table, "asdjnvhcu", 0);
    HashTable_put(hash_table, "smxnahskf", 0);
    HashTable_put(hash_table, "hgbcneuyt", 0);
    HashTable_put(hash_table, "asnngdlqu", 0);

    HashTable_free(hash_table);

    return 0;
}