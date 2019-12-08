#include "TablaSimbolos.h"
#include "HashTable.h"
#include <stdlib.h>
#include <stdbool.h>

struct _TablaSimbolos {
    HashTable *contexto_global;
    HashTable *contexto_local;
};

TablaSimbolos *TablaSimbolos_create() {
    TablaSimbolos *tabla_simbolos;

    tabla_simbolos = (TablaSimbolos *) malloc(sizeof(TablaSimbolos));
    if (tabla_simbolos == NULL) return NULL;

    tabla_simbolos->contexto_global = HashTable_create();
    if (tabla_simbolos == NULL) {
        free(tabla_simbolos);
        return NULL;
    }

    tabla_simbolos->contexto_local = NULL;

    return tabla_simbolos;
}

void TablaSimbolos_free(TablaSimbolos *tabla_simbolos) {
    if (tabla_simbolos == NULL) return;
    HashTable_free(tabla_simbolos->contexto_global);
    if (tabla_simbolos->contexto_local != NULL) HashTable_free(tabla_simbolos->contexto_local);
    free(tabla_simbolos);
}

int TablaSimbolos_declarar_global(TablaSimbolos *tabla_simbolos, char id[51], int value) {
    if (tabla_simbolos == NULL) return ERROR;
    if (value < 0) return ERROR;
    if (HashTable_contains_key(tabla_simbolos->contexto_global, id)) return ERROR;
    HashTable_put(tabla_simbolos->contexto_global, id, value);
    return OK;
}

int TablaSimbolos_uso_global(TablaSimbolos *tabla_simbolos, char id[51]) {
    if (tabla_simbolos == NULL) return ERROR;
    return HashTable_get(tabla_simbolos->contexto_global, id);
}

int TablaSimbolos_declarar_local(TablaSimbolos *tabla_simbolos, char id[51], int value) {
    if (tabla_simbolos == NULL) return ERROR;
    if (tabla_simbolos->contexto_local == NULL) return ERROR;
    if (value < 0) return ERROR;
    if (HashTable_contains_key(tabla_simbolos->contexto_local, id)) return ERROR;
    HashTable_put(tabla_simbolos->contexto_local, id, value);
    return OK;
}

int TablaSimbolos_uso_local(TablaSimbolos *tabla_simbolos, char id[51]) {
    if (tabla_simbolos == NULL) return ERROR;
    if (tabla_simbolos->contexto_local == NULL) return ERROR;
    if (HashTable_contains_key(tabla_simbolos->contexto_local, id)) {
        return HashTable_get(tabla_simbolos->contexto_local, id);
    } else {
        return HashTable_get(tabla_simbolos->contexto_global, id);
    }
}

int TablaSimbolos_declarar_funcion(TablaSimbolos *tabla_simbolos, char id[51], int value) {
    if (tabla_simbolos == NULL) return ERROR;
    if (tabla_simbolos->contexto_local != NULL) return ERROR;
    if (value >= -1) return ERROR;
    if (HashTable_contains_key(tabla_simbolos->contexto_global, id)) return ERROR;
    tabla_simbolos->contexto_local = HashTable_create();
    if (tabla_simbolos->contexto_local == NULL) return ERROR;
    HashTable_put(tabla_simbolos->contexto_global, id, value);
    HashTable_put(tabla_simbolos->contexto_local, id, value);
    return OK;
}

void TablaSimbolos_terminar_funcion(TablaSimbolos *tabla_simbolos) {
    if (tabla_simbolos == NULL) return;
    if (tabla_simbolos->contexto_local == NULL) return;
    HashTable_free(tabla_simbolos->contexto_local);
    tabla_simbolos->contexto_local = NULL;
}