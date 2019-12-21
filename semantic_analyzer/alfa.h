#ifndef ALFA_H
#define ALFA_H

#include <stdbool.h>
#include <string.h>

#define MAX_LONGITUD_ID 50
#define MAX_TAM_VECTOR 64

#define ESCALAR 1
#define VECTOR 2
#define FUNCION 3

#define INT 1
#define BOOLEAN 2

#define FALSE 0
#define TRUE 1

#define PARAR_COMPILADOR 0

typedef struct {
    char lexema[MAX_LONGITUD_ID+1];
    int clase;
    int tipo;
    int numero_elementos;
    int posicion;
    int valor_entero;
    int num_parametros;
    int num_variables_locales;
    bool es_direccion;
    int etiqueta;
} tipo_atributos;

#endif