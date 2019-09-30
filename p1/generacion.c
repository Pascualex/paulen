#include <stdio.h>
#include <stdlib.h>

void escribir_cabecera_bss(FILE *file) {
    if (file == NULL) return;

    fprintf(file, "segment .data\n");
    fprintf(file, "\tmensaje_division_0 db \"Error: division por cero\", 0\n");
}

void escribir_subseccion_data(FILE *file) {
    if (file == NULL) return;

    fprintf(file, "segment .bss\n");
    fprintf(file, "\t__esp resd 1\n");
}

void declarar_variable(FILE *file, char  *nombre, int tipo, int tamano) {

}

void escribir_segmento_codigo(FILE *file) {
    if (file == NULL) return;

    fprintf(file, "segment .text\n");
    fprintf(file, "global main\n");
    fprintf(file, "extern print_int, print_boolean, print_string, print_blank, print_endofline, scan_int, scan_boolean\n");
}

void escribir_inicio_main(FILE *file) {
    if (file == NULL) return;

    fprintf(file, "main:\n");
    fprintf(file, "\tmov [__esp], esp\n");
}

void escribir_fin(FILE *file) {
    if (file == NULL) return;

    fprintf(file, "\tjmp fin\n");
    fprintf(file, "division_0:\n");
    fprintf(file, "\tpush dword mensaje_division_0\n");
    fprintf(file, "\tcall print_string\n");
    fprintf(file, "fin:\n");
    fprintf(file, "\tmov esp, [__esp]\n");
    fprintf(file, "\tret\n");
}

void escribir_operando(FILE *file, char *nombre, int es_variable) {

}

void asignar(FILE *file, char *nombre, int es_variable) {

}

void sumar(FILE *file, int es_variable_1, int es_variable_2) {
    if (file == NULL) return;

    fprintf(file, "\tjmp fin\n");
    fprintf(file, "division_0:\n");
    fprintf(file, "\tpush dword mensaje_division_0\n");
    fprintf(file, "\tcall print_string\n");
    fprintf(file, "fin:\n");
    fprintf(file, "\tmov esp, [__esp]\n");
    fprintf(file, "\tret\n");
}

void restar(FILE *file, int es_variable_1, int es_variable_2) {

}

void multiplicar(FILE *file, int es_variable_1, int es_variable_2) {

}

void dividir(FILE *file, int es_variable_1, int es_variable_2) {

}

void o(FILE *file, int es_variable_1, int es_variable_2) {

}

void y(FILE *file, int es_variable_1, int es_variable_2) {

}

void cambiar_signo(FILE *file, int es_variable) {

}

void no(FILE *file, int es_variable, int cuantos_no) {

}

void igual(FILE *file, int es_variable1, int es_variable2, int etiqueta) {

}

void distinto(FILE *file, int es_variable1, int es_variable2, int etiqueta) {

}

void menor_igual(FILE *file, int es_variable1, int es_variable2, int etiqueta) {

}

void mayor_igual(FILE *file, int es_variable1, int es_variable2, int etiqueta) {

}

void menor(FILE *file, int es_variable1, int es_variable2, int etiqueta) {

}

void mayor(FILE *file, int es_variable1, int es_variable2, int etiqueta) {

}

void leer(FILE *file, char *nombre, int tipo) {

}

void escribir(FILE *file, int es_variable, int tipo) {

}