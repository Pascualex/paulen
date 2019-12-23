#ifndef ALFA_H
#define ALFA_H

#include <stdbool.h>
#include <string.h>

#define MAX_LONGITUD_ID 50
#define MAX_TAM_VECTOR 64

#define VARIABLE 1
#define PARAMETRO 2
#define FUNCION 3

#define ESCALAR 1
#define VECTOR 2

#define ENTERO 1
#define BOOLEANO 2

#define FALSE 0
#define TRUE 1

#define PARAR_COMPILADOR 0

typedef struct {
    char lexema[MAX_LONGITUD_ID+1];
    int categoria;
    int clase;
    int tipo;
    int numero_elementos;
    int valor_entero;
    int pos_parametro;
    int num_parametros;
    int pos_variable_local;
    int num_variables_locales;
    bool es_direccion;
    int etiqueta;
} tipo_atributos;

#endif