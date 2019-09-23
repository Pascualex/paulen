#include <stdlib.h>
#include <stdio.h>

void escribir_subseccion_data(FILE *file) {
    if (file == NULL) return;
    fprintf(file, "segment .data\n");
    fprintf(file, "\tmensaje_division_0 db \"Error: division por cero\", 0\n");
}

void escribir_cabecera_bss(FILE *file) {
    if (file == NULL) return;
    fprintf(file, "segment .bss\n");
    fprintf(file, "\t__esp resd 1\n");
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

void escribir_segmento_codigo(FILE *file) {
    if (file == NULL) return;
    fprintf(file, "segment .text\n");
    fprintf(file, "global main\n");
    fprintf(file, "extern print_int, print_boolean, print_string, print_blank, print_endofline, scan_int, scan_boolean\n");
}

void uno_si_mayor_de_10(FILE *file, int es_variable_1, int es_variable_2, int etiqueta) {
    if (file == NULL) return;

    if (es_variable_1 == 0) {
        fprintf(file, "\tpop edx\n");
    } else {
        fprintf(file, "\tmov edx, %d\n", es_variable_1);
    }

    if (es_variable_2 == 0) {
        fprintf(file, "\tpop eax\n");
    } else {
        fprintf(file, "\tmov eax, %d\n", es_variable_2);
    }

    fprintf(file, "\tadd eax, edx\n");
    fprintf(file, "\tmov edx, 10\n");
    fprintf(file, "\tcmp eax, edx\n");
    fprintf(file, "\tjg es_mayor_%d\n", etiqueta);
    fprintf(file, "\tmov edx, 0\n");
    fprintf(file, "\tjmp imprimir_y_almacenar_%d\n", etiqueta);
    fprintf(file, "es_mayor_%d:\n", etiqueta);
    fprintf(file, "\tmov edx, 1\n");
    fprintf(file, "imprimir_y_almacenar_%d:\n", etiqueta);
    fprintf(file, "\tpush edx\n");
    fprintf(file, "\tcall print_int\n");
}