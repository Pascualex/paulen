#ifndef ALFA_H
#define ALFA_H

#include <stdio.h>

#define ENTERO        0
#define BOOLEANO      1
#define MAX_ETIQUETAS 32768

void escribir_subseccion_data(FILE *file);
void escribir_cabecera_bss(FILE *file);
void escribir_inicio_main(FILE *file);
void escribir_fin(FILE *file);
void escribir_segmento_codigo(FILE *file);
void uno_si_mayor_de_10(FILE *file, int es_variable_1, int es_variable_2, int etiqueta);

#endif
