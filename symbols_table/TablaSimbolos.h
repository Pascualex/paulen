#ifndef TABLA_SIMBOLOS_H
#define TABLA_SIMBOLOS_H

#define EXITO 0
#define ERROR -1

int TablaSimbolos_declarar_global(char id[50], int desc_id);
int TablaSimbolos_uso_global(char id[50]);
int TablaSimbolos_declarar_local(char id[50], int desc_id);
int TablaSimbolos_uso_local(char id[50]);
int TablaSimbolos_declarar_funcion(char id[50], int desc_id);

#endif