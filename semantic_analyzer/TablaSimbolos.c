#include "TablaSimbolos.h"
#include "HashTable.h"
#include <stdlib.h>

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

int TablaSimbolos_declarar_global(TablaSimbolos *tabla_simbolos, char id[MAX_LONGITUD_ID+1], tipo_atributos *value) {
    if (tabla_simbolos == NULL) return ERROR;
    if (value == NULL) return ERROR;
    if (HashTable_contains_key(tabla_simbolos->contexto_global, id)) return ERROR;
    HashTable_put(tabla_simbolos->contexto_global, id, value);
    return OK;
}

tipo_atributos *TablaSimbolos_uso_global(TablaSimbolos *tabla_simbolos, char id[MAX_LONGITUD_ID+1]) {
    if (tabla_simbolos == NULL) return NULL;
    return HashTable_get(tabla_simbolos->contexto_global, id);
}

bool TablaSimbolos_existe_global(TablaSimbolos *tabla_simbolos, char id[MAX_LONGITUD_ID+1]) {
    if (tabla_simbolos == NULL) return false;
    return HashTable_contains_key(tabla_simbolos->contexto_global, id);
}

tipo_atributos **TablaSimbolos_get_elementos_global(TablaSimbolos *tabla_simbolos) {
    if (tabla_simbolos == NULL) return NULL;
    return HashTable_get_elements(tabla_simbolos->contexto_global);
}

int TablaSimbolos_tam_global(TablaSimbolos *tabla_simbolos) {
    if (tabla_simbolos == NULL) return 0;
    return HashTable_size(tabla_simbolos->contexto_global);
}

int TablaSimbolos_declarar_local(TablaSimbolos *tabla_simbolos, char id[MAX_LONGITUD_ID+1], tipo_atributos *value) {
    if (tabla_simbolos == NULL) return ERROR;
    if (tabla_simbolos->contexto_local == NULL) return ERROR;
    if (value == NULL) return ERROR;
    if (HashTable_contains_key(tabla_simbolos->contexto_local, id)) return ERROR;
    HashTable_put(tabla_simbolos->contexto_local, id, value);
    return OK;
}

tipo_atributos *TablaSimbolos_uso_local(TablaSimbolos *tabla_simbolos, char id[MAX_LONGITUD_ID+1]) {
    if (tabla_simbolos == NULL) return NULL;
    if (tabla_simbolos->contexto_local == NULL) return NULL;
    if (HashTable_contains_key(tabla_simbolos->contexto_local, id)) {
        return HashTable_get(tabla_simbolos->contexto_local, id);
    } else {
        return HashTable_get(tabla_simbolos->contexto_global, id);
    }
}

bool TablaSimbolos_existe_local(TablaSimbolos *tabla_simbolos, char id[MAX_LONGITUD_ID+1]) {
    if (tabla_simbolos == NULL) return false;
    if (tabla_simbolos->contexto_local == NULL) return NULL;
    if (HashTable_contains_key(tabla_simbolos->contexto_local, id)) {
        return HashTable_contains_key(tabla_simbolos->contexto_local, id);
    } else {
        return HashTable_contains_key(tabla_simbolos->contexto_global, id);
    }
}

bool TablaSimbolos_existe_local_estricto(TablaSimbolos *tabla_simbolos, char id[MAX_LONGITUD_ID+1]) {
    if (tabla_simbolos == NULL) return false;
    return HashTable_contains_key(tabla_simbolos->contexto_local, id);
}

int TablaSimbolos_declarar_funcion(TablaSimbolos *tabla_simbolos, char id[MAX_LONGITUD_ID+1], tipo_atributos *value) {
    if (tabla_simbolos == NULL) return ERROR;
    if (tabla_simbolos->contexto_local != NULL) return ERROR;
    if (value == NULL) return ERROR;
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