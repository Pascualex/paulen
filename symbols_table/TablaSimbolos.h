#ifndef TABLA_SIMBOLOS_H
#define TABLA_SIMBOLOS_H

#define OK 0
#define ERROR -1

typedef struct _TablaSimbolos TablaSimbolos;

TablaSimbolos *TablaSimbolos_create();
void TablaSimbolos_free(TablaSimbolos *tabla_simbolos);
int TablaSimbolos_declarar_global(TablaSimbolos *tabla_simbolos, char id[50], int value);
int TablaSimbolos_uso_global(TablaSimbolos *tabla_simbolos, char id[50]);
int TablaSimbolos_declarar_local(TablaSimbolos *tabla_simbolos, char id[50], int value);
int TablaSimbolos_uso_local(TablaSimbolos *tabla_simbolos, char id[50]);
int TablaSimbolos_declarar_funcion(TablaSimbolos *tabla_simbolos, char id[50], int value);
void TablaSimbolos_terminar_funcion(TablaSimbolos *tabla_simbolos);

#endif