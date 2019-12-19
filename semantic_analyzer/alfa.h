#ifndef ALFA_H
#define ALFA_H

#include <stdbool.h>

#define MAX_LONGITUD_ID 50
#define MAX_TAM_VECTOR 64

#define ESCALAR 1
#define VECTOR 2

#define INT 1
#define BOOLEAN 2

#define PARAR_COMPILADOR 0

typedef struct {
    char lexema[MAX_LONGITUD_ID+1];
    int categoria;
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