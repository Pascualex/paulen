#include <stdio.h>
#include <stdlib.h>

void cargar_registro(FILE *file, char *reg, int es_variable) {
    fprintf(file, "pop %s\n", reg);

    if (es_variable != 0) {
        fprintf(file, "mov %s, [%s]\n", reg, reg);
    }
}

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

void declarar_variable(FILE *file, char *nombre, int tipo, int tamano) {
    if (file == NULL || nombre == NULL) return;

    if (tipo == ENTERO) {
        fprintf(file, "_%s dw %d\n", nombre, tamano);
    } else if (tipo == BOOLEANO) {
        fprintf(file, "_%s db %d\n", nombre, tamano);
    }
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
    if (file == null || nombre == null) return;

    if (es_variable == 0) {
        fprintf(file, "mov eax, %s\n", nombre);
    } else {
        fprintf(file, "mov eax, _%s\n", nombre);
    }

    fprintf(file, "push eax\n");
}

void asignar(FILE *file, char *nombre, int es_variable) {
    if (file == NULL || nombre == null) return;

    cargar_registro(file, "eax", es_variable);
    fprintf(file, "\tmov _%s, eax\n", nombre);
}

void sumar(FILE *file, int es_variable_1, int es_variable_2) {
    if (file == NULL) return;

    cargar_registro(file, "eax", es_variable_1);
    cargar_registro(file, "edx", es_variable_2);

    fprintf(file, "add eax, edx\n");
    fprintf(file, "push eax\n");
}

void restar(FILE *file, int es_variable_1, int es_variable_2) {
    if (file == NULL) return;

    cargar_registro(file, "eax", es_variable_1);
    cargar_registro(file, "edx", es_variable_2);
    
    fprintf(file, "sub eax, edx\n");
    fprintf(file, "push eax\n");
}

// NOTA: Solo guarda la parte baja del resultado
void multiplicar(FILE *file, int es_variable_1, int es_variable_2) {
    if (file == NULL) return;

    cargar_registro(file, "eax", es_variable_1);
    cargar_registro(file, "edx", es_variable_2);
    
    fprintf(file, "imul eax, edx\n");
    fprintf(file, "push eax\n");
}

// NOTA: Solo guarda el cociente
void dividir(FILE *file, int es_variable_1, int es_variable_2) {
    if (file == NULL) return;

    cargar_registro(file, "eax", es_variable_1);
    cargar_registro(file, "edx", es_variable_2);

    fprintf(file, "cmp edx, 0\n");
    fprintf(file, "jz division_0\n");
    fprintf(file, "idiv eax, edx\n");
    fprintf(file, "push eax\n");
}

void o(FILE *file, int es_variable_1, int es_variable_2) {
    if (file == NULL) return;

    cargar_registro(file, "eax", es_variable_1);
    cargar_registro(file, "edx", es_variable_2);

    fprintf(file, "or eax, edx\n");
    fprintf(file, "push eax\n");
}

void y(FILE *file, int es_variable_1, int es_variable_2) {
    if (file == NULL) return;

    cargar_registro(file, "eax", es_variable_1);
    cargar_registro(file, "edx", es_variable_2);

    fprintf(file, "and eax, edx\n");
    fprintf(file, "push eax\n");
}

void cambiar_signo(FILE *file, int es_variable) {
    if (file == NULL) return;

    cargar_registro(file, "eax", es_variable);

    fprintf(file, "neg eax\n");
    fprintf(file, "push eax\n");
}

void no(FILE *file, int es_variable, int cuantos_no) {
    if (file == NULL) return;

    cargar_registro(file, "eax", es_variable);


    fprintf(file, "cmp eax, 0\n");
    fprintf(file, "jz meter_1_no_%d\n", cuantos_no);
    fprintf(file, "mov eax, 0\n");
    fprintf(file, "jmp fin_no_%d\n", cuantos_no);
    fprintf(file, "meter_1_no_%d:\n", cuantos_no);
    fprintf(file, "mov eax, 1\n");
    fprintf(file, "fin_no_%d:\n", cuantos_no);
    fprintf(file, "push eax\n");
}

void igual(FILE *file, int es_variable1, int es_variable2, int etiqueta) {
    if (file == NULL) return;

    cargar_registro(file, "eax", es_variable1);
    cargar_registro(file, "edx", es_variable2);

    fprintf(file, "cmp eax, edx\n");
    fprintf(file, "jz devolver_1_%d\n", etiqueta);
    fprintf(file, "mov eax, 0\n");
    fprintf(file, "jmp fin_%d\n", etiqueta);
    fprintf(file, "devolver_1_%d:\n", etiqueta);
    fprintf(file, "mov eax, 1\n");
    fprintf(file, "fin_%d:\n", etiqueta);
    fprintf(file, "push eax\n");
}

void distinto(FILE *file, int es_variable1, int es_variable2, int etiqueta) {
    if (file == NULL) return;

    cargar_registro(file, "eax", es_variable1);
    cargar_registro(file, "edx", es_variable2);

    fprintf(file, "cmp eax, edx\n");
    fprintf(file, "jnz devolver_1_%d\n", etiqueta);
    fprintf(file, "mov eax, 0\n");
    fprintf(file, "jmp fin_%d\n", etiqueta);
    fprintf(file, "devolver_1_%d:\n", etiqueta);
    fprintf(file, "mov eax, 1\n");
    fprintf(file, "fin_%d:\n", etiqueta);
    fprintf(file, "push eax\n");
}

void menor_igual(FILE *file, int es_variable1, int es_variable2, int etiqueta) {
    if (file == NULL) return;

    cargar_registro(file, "eax", es_variable1);
    cargar_registro(file, "edx", es_variable2);

    fprintf(file, "cmp eax, edx\n");
    fprintf(file, "jle devolver_1_%d\n", etiqueta);
    fprintf(file, "mov eax, 0\n");
    fprintf(file, "jmp fin_%d\n", etiqueta);
    fprintf(file, "devolver_1_%d:\n", etiqueta);
    fprintf(file, "mov eax, 1\n");
    fprintf(file, "fin_%d:\n", etiqueta);
    fprintf(file, "push eax\n");
}

void mayor_igual(FILE *file, int es_variable1, int es_variable2, int etiqueta) {
    if (file == NULL) return;

    cargar_registro(file, "eax", es_variable1);
    cargar_registro(file, "edx", es_variable2);

    fprintf(file, "cmp eax, edx\n");
    fprintf(file, "jge devolver_1_%d\n", etiqueta);
    fprintf(file, "mov eax, 0\n");
    fprintf(file, "jmp fin_%d\n", etiqueta);
    fprintf(file, "devolver_1_%d:\n", etiqueta);
    fprintf(file, "mov eax, 1\n");
    fprintf(file, "fin_%d:\n", etiqueta);
    fprintf(file, "push eax\n");
}

void menor(FILE *file, int es_variable1, int es_variable2, int etiqueta) {
    if (file == NULL) return;

    cargar_registro(file, "eax", es_variable1);
    cargar_registro(file, "edx", es_variable2);

    fprintf(file, "cmp eax, edx\n");
    fprintf(file, "jl devolver_1_%d\n", etiqueta);
    fprintf(file, "mov eax, 0\n");
    fprintf(file, "jmp fin_%d\n", etiqueta);
    fprintf(file, "devolver_1_%d:\n", etiqueta);
    fprintf(file, "mov eax, 1\n");
    fprintf(file, "fin_%d:\n", etiqueta);
    fprintf(file, "push eax\n");
}

void mayor(FILE *file, int es_variable1, int es_variable2, int etiqueta) {
    if (file == NULL) return;

    cargar_registro(file, "eax", es_variable1);
    cargar_registro(file, "edx", es_variable2);

    fprintf(file, "cmp eax, edx\n");
    fprintf(file, "jg devolver_1_%d\n", etiqueta);
    fprintf(file, "mov eax, 0\n");
    fprintf(file, "jmp fin_%d\n", etiqueta);
    fprintf(file, "devolver_1_%d:\n", etiqueta);
    fprintf(file, "mov eax, 1\n");
    fprintf(file, "fin_%d:\n", etiqueta);
    fprintf(file, "push eax\n");
}

void leer(FILE *file, char *nombre, int tipo) {
    if (file == null || nombre == null) return;

    if (tipo == ENTERO) {
        fprintf(file, "call scan_int\n");
    } else if (tipo == BOOLEANO) {
        fprintf(file, "call scan_boolean\n");
    }

    printf(file, "pop eax\n");
    printf(file, "mov _%s, eax\n", nombre);
}

void escribir(FILE *file, int es_variable, int tipo) {
    if (file == null) return;

    if (es_variable == 1) {
        printf(file, "pop eax\n");
        printf(file, "mov eax, [eax]\n");
        printf(file, "push eax\n");
    }

    if (tipo == ENTERO) {
        fprintf(file, "call print_int\n");
    } else if (tipo == BOOLEANO) {
        fprintf(file, "call print_boolean\n");
    }

    printf(file, "pop eax\n");
}