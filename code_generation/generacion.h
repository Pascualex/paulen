#ifndef GENERACION_H
#define GENERACION_H
#include <stdio.h>

#define MAX_ETIQUETAS 100
#define ENTERO 0
#define BOOLEANO 1
#define FALSE 0
#define TRUE 1

void escribir_cabecera_bss(FILE *file);
void escribir_subseccion_data(FILE *file);
void declarar_variable(FILE *file, char  *nombre, int tipo, int tamano);
void escribir_segmento_codigo(FILE *file);
void escribir_inicio_main(FILE *file);
void escribir_fin(FILE *file);
void escribir_operando(FILE *file, char *nombre, int es_variable);

void asignar(FILE *file, char *nombre, int es_variable);

void sumar(FILE *file, int es_variable_1, int es_variable_2);
void restar(FILE *file, int es_variable_1, int es_variable_2);
void multiplicar(FILE *file, int es_variable_1, int es_variable_2);
void dividir(FILE *file, int es_variable_1, int es_variable_2);
void o(FILE *file, int es_variable_1, int es_variable_2);
void y(FILE *file, int es_variable_1, int es_variable_2);
void cambiar_signo(FILE *file, int es_variable);

void no(FILE *file, int es_variable, int cuantos_no);

void igual(FILE *file, int es_variable_1, int es_variable_2, int etiqueta);
void distinto(FILE *file, int es_variable_1, int es_variable_2, int etiqueta);
void menor_igual(FILE *file, int es_variable_1, int es_variable_2, int etiqueta);
void mayor_igual(FILE *file, int es_variable_1, int es_variable_2, int etiqueta);
void menor(FILE *file, int es_variable_1, int es_variable_2, int etiqueta);
void mayor(FILE *file, int es_variable_1, int es_variable_2, int etiqueta);

void leer(FILE *file, char *nombre, int tipo);
void escribir(FILE *file, int es_variable, int tipo);

void ifthen_inicio(FILE *file, int exp_es_variable, int etiqueta);
void ifthen_fin(FILE *file, int etiqueta);

void ifthenelse_inicio(FILE *file, int exp_es_variable, int etiqueta);
void ifthenelse_fin_then(FILE *file, int etiqueta);
void ifthenelse_fin(FILE *file, int etiqueta);

void while_inicio(FILE *file, int etiqueta);
void while_exp_pila (FILE *file, int exp_es_variable, int etiqueta);
void while_fin(FILE *file, int etiqueta);

void escribir_codigo_for(FILE *file, int es_variable_1, int es_variable_2, int es_variable_3, char *bloque_codigo, int etiqueta);

void escribir_elemento_vector(FILE *file, char *nombre_vector, int tam_max, int exp_es_variable);

void declararFuncion(FILE *file, char *nombre_funcion, int num_var_loc);
void escribirParametro(FILE *file, int pos_parametro, int num_total_parametros);
void escribirVariableLocal(FILE *file, int pos_variable_local);
void asignarDestinoEnPila(FILE *file, int es_variable);
void retornarFuncion(FILE *file, int es_variable);
void operandoEnPilaAArgumento(FILE *file, int es_variable);
void llamarFuncion(FILE *file, char *nombre_funcion, int num_argumentos);
void limpiarPila(FILE *file, int num_argumentos);

#endif