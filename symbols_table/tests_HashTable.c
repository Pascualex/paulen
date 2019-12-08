#include "HashTable.h"
#include <stdio.h>

int main() {
    HashTable *hash_table;

    hash_table = HashTable_create();
    if (hash_table == NULL) return -1;

    HashTable_put(hash_table, "kdmcuhjwl", 0);
    HashTable_put(hash_table, "asdijlanm", 1);
    HashTable_put(hash_table, "fkjahdlgh", 2);
    HashTable_put(hash_table, "ggyeiwosk", 3);
    HashTable_put(hash_table, "mvzmcywiq", 4);
    HashTable_put(hash_table, "asdjnvhcu", 5);
    HashTable_put(hash_table, "smxnahskf", 6);
    HashTable_put(hash_table, "hgbcneuyt", 7);
    HashTable_put(hash_table, "asnngdlqu", 8);

    if (HashTable_get(hash_table, "kdmcuhjwl") != 0) printf("Error get 'kdmcuhjwl'\n");
    if (HashTable_get(hash_table, "asdijlanm") != 1) printf("Error get 'asdijlanm'\n");
    if (HashTable_get(hash_table, "fkjahdlgh") != 2) printf("Error get 'fkjahdlgh'\n");
    if (HashTable_get(hash_table, "ggyeiwosk") != 3) printf("Error get 'ggyeiwosk'\n");
    if (HashTable_get(hash_table, "mvzmcywiq") != 4) printf("Error get 'mvzmcywiq'\n");
    if (HashTable_get(hash_table, "asdjnvhcu") != 5) printf("Error get 'asdjnvhcu'\n");
    if (HashTable_get(hash_table, "smxnahskf") != 6) printf("Error get 'smxnahskf'\n");
    if (HashTable_get(hash_table, "hgbcneuyt") != 7) printf("Error get 'hgbcneuyt'\n");
    if (HashTable_get(hash_table, "asnngdlqu") != 8) printf("Error get 'asnngdlqu'\n");
    if (HashTable_get(hash_table, "error") != -1) printf("Error get 'error'\n");

    if (!HashTable_contains_key(hash_table, "kdmcuhjwl")) printf("Error contains_key 'kdmcuhjwl'\n");
    if (!HashTable_contains_key(hash_table, "asdijlanm")) printf("Error contains_key 'asdijlanm'\n");
    if (!HashTable_contains_key(hash_table, "fkjahdlgh")) printf("Error contains_key 'fkjahdlgh'\n");
    if (!HashTable_contains_key(hash_table, "mvzmcywiq")) printf("Error contains_key 'mvzmcywiq'\n");
    if (!HashTable_contains_key(hash_table, "asdjnvhcu")) printf("Error contains_key 'asdjnvhcu'\n");
    if (!HashTable_contains_key(hash_table, "smxnahskf")) printf("Error contains_key 'smxnahskf'\n");
    if (!HashTable_contains_key(hash_table, "hgbcneuyt")) printf("Error contains_key 'hgbcneuyt'\n");
    if (!HashTable_contains_key(hash_table, "asnngdlqu")) printf("Error contains_key 'asnngdlqu'\n");
    if (HashTable_contains_key(hash_table, "error")) printf("Error contains_key 'error'\n");

    HashTable_free(hash_table);

    return 0;
}