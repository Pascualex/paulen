#ifndef TABLA_SIMBOLOS_H
#define TABLA_SIMBOLOS_H

#include "alfa.h"
#include "stdbool.h"

#define OK 0
#define ERROR -1

typedef struct _TablaSimbolos TablaSimbolos;

TablaSimbolos *TablaSimbolos_create();
void TablaSimbolos_free(TablaSimbolos *tabla_simbolos);
int TablaSimbolos_declarar_global(TablaSimbolos *tabla_simbolos, char id[MAX_LONGITUD_ID+1], tipo_atributos *value);
tipo_atributos *TablaSimbolos_uso_global(TablaSimbolos *tabla_simbolos, char id[MAX_LONGITUD_ID+1]);
bool TablaSimbolos_existe_global(TablaSimbolos *tabla_simbolos, char id[MAX_LONGITUD_ID+1]);
int TablaSimbolos_declarar_local(TablaSimbolos *tabla_simbolos, char id[MAX_LONGITUD_ID+1], tipo_atributos *value);
tipo_atributos *TablaSimbolos_uso_local(TablaSimbolos *tabla_simbolos, char id[MAX_LONGITUD_ID+1]);
bool TablaSimbolos_existe_local(TablaSimbolos *tabla_simbolos, char id[MAX_LONGITUD_ID+1]);
int TablaSimbolos_declarar_funcion(TablaSimbolos *tabla_simbolos, char id[MAX_LONGITUD_ID+1], tipo_atributos *value);
void TablaSimbolos_terminar_funcion(TablaSimbolos *tabla_simbolos);

#endif