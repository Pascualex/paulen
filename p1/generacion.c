#include <stdlib.h>
#include "generacion.h"

void cargar_registro(FILE *file, char *reg, int es_variable) {
    fprintf(file, "pop dword %s\n", reg);

    if (es_variable) {
        fprintf(file, "mov dword %s, [%s]\n", reg, reg);
    }
}

void escribir_cabecera_bss(FILE *file) {
    if (file == NULL) return;

    fprintf(file, "segment .bss\n");
    fprintf(file, "__esp resd 1\n");
}

void escribir_subseccion_data(FILE *file) {
    if (file == NULL) return;

    fprintf(file, "segment .data\n");
    fprintf(file, "mensaje_division_0 db \"Error: division por cero\", 0\n");
    fprintf(file, "mensaje_fuera_de_rango db \"Error: indice de vector fuera de rango\", 0\n");
}

void declarar_variable(FILE *file, char *nombre, int tipo, int tamano) {
    if (file == NULL || nombre == NULL) return;

    if (tipo == ENTERO) {
        fprintf(file, "_%s resd %d\n", nombre, tamano);
    } else if (tipo == BOOLEANO) {
        fprintf(file, "_%s resd %d\n", nombre, tamano);
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
    fprintf(file, "mov dword [__esp], esp\n");
}

void escribir_fin(FILE *file) {
    if (file == NULL) return;

    fprintf(file, "jmp fin\n");
    fprintf(file, "division_0:\n");
    fprintf(file, "push dword mensaje_division_0\n");
    fprintf(file, "jmp imprimir_error\n");
    fprintf(file, "fuera_de_rango:\n");
    fprintf(file, "push dword mensaje_fuera_de_rango\n");
    fprintf(file, "imprimir_error:\n");
    fprintf(file, "call print_string\n");
    fprintf(file, "call print_endofline\n");
    fprintf(file, "fin:\n");
    fprintf(file, "mov dword esp, [__esp]\n");
    fprintf(file, "ret\n");
}

void escribir_operando(FILE *file, char *nombre, int es_variable) {
    if (file == NULL || nombre == NULL) return;

    if (es_variable) {
        fprintf(file, "push dword _%s\n", nombre);
    } else {
        fprintf(file, "push dword %s\n", nombre);
    }
}

void asignar(FILE *file, char *nombre, int es_variable) {
    if (file == NULL || nombre == NULL) return;

    cargar_registro(file, "eax", es_variable);
    fprintf(file, "mov dword [_%s], eax\n", nombre);
}

void sumar(FILE *file, int es_variable_1, int es_variable_2) {
    if (file == NULL) return;

    cargar_registro(file, "edx", es_variable_2);
    cargar_registro(file, "eax", es_variable_1);

    fprintf(file, "add eax, edx\n");
    fprintf(file, "push dword eax\n");
}

void restar(FILE *file, int es_variable_1, int es_variable_2) {
    if (file == NULL) return;

    cargar_registro(file, "edx", es_variable_2);
    cargar_registro(file, "eax", es_variable_1);
    
    fprintf(file, "sub eax, edx\n");
    fprintf(file, "push dword eax\n");
}

// NOTA: Solo guarda la parte baja del resultado
void multiplicar(FILE *file, int es_variable_1, int es_variable_2) {
    if (file == NULL) return;

    cargar_registro(file, "edx", es_variable_2);
    cargar_registro(file, "eax", es_variable_1);
    
    fprintf(file, "imul eax, edx\n");
    fprintf(file, "push dword eax\n");
}

// NOTA: Solo guarda el cociente
void dividir(FILE *file, int es_variable_1, int es_variable_2) {
    if (file == NULL) return;

    cargar_registro(file, "ecx", es_variable_2);
    cargar_registro(file, "eax", es_variable_1);

    fprintf(file, "cmp ecx, 0\n");
    fprintf(file, "jz division_0\n");
    fprintf(file, "cdq\n"); // Extiende el signo de eax en edx
    fprintf(file, "idiv ecx\n");
    fprintf(file, "push dword eax\n");
}

void o(FILE *file, int es_variable_1, int es_variable_2) {
    if (file == NULL) return;

    cargar_registro(file, "edx", es_variable_2);
    cargar_registro(file, "eax", es_variable_1);

    fprintf(file, "or eax, edx\n");
    fprintf(file, "push dword eax\n");
}

void y(FILE *file, int es_variable_1, int es_variable_2) {
    if (file == NULL) return;

    cargar_registro(file, "edx", es_variable_2);
    cargar_registro(file, "eax", es_variable_1);

    fprintf(file, "and eax, edx\n");
    fprintf(file, "push dword eax\n");
}

void cambiar_signo(FILE *file, int es_variable) {
    if (file == NULL) return;

    cargar_registro(file, "eax", es_variable);

    fprintf(file, "neg eax\n");
    fprintf(file, "push dword eax\n");
}

void no(FILE *file, int es_variable, int cuantos_no) {
    if (file == NULL) return;

    cargar_registro(file, "eax", es_variable);

    fprintf(file, "cmp eax, 0\n");
    fprintf(file, "jz meter_1_no_%d\n", cuantos_no);
    fprintf(file, "mov dword eax, 0\n");
    fprintf(file, "jmp fin_no_%d\n", cuantos_no);
    fprintf(file, "meter_1_no_%d:\n", cuantos_no);
    fprintf(file, "mov dword eax, 1\n");
    fprintf(file, "fin_no_%d:\n", cuantos_no);
    fprintf(file, "push dword eax\n");
}

void igual(FILE *file, int es_variable_1, int es_variable_2, int etiqueta) {
    if (file == NULL) return;

    cargar_registro(file, "edx", es_variable_2);
    cargar_registro(file, "eax", es_variable_1);

    fprintf(file, "cmp eax, edx\n");
    fprintf(file, "jz devolver_1_%d\n", etiqueta);
    fprintf(file, "mov dword eax, 0\n");
    fprintf(file, "jmp fin_%d\n", etiqueta);
    fprintf(file, "devolver_1_%d:\n", etiqueta);
    fprintf(file, "mov dword eax, 1\n");
    fprintf(file, "fin_%d:\n", etiqueta);
    fprintf(file, "push dword eax\n");
}

void distinto(FILE *file, int es_variable_1, int es_variable_2, int etiqueta) {
    if (file == NULL) return;

    cargar_registro(file, "edx", es_variable_2);
    cargar_registro(file, "eax", es_variable_1);

    fprintf(file, "cmp eax, edx\n");
    fprintf(file, "jnz devolver_1_%d\n", etiqueta);
    fprintf(file, "mov dword eax, 0\n");
    fprintf(file, "jmp fin_%d\n", etiqueta);
    fprintf(file, "devolver_1_%d:\n", etiqueta);
    fprintf(file, "mov dword eax, 1\n");
    fprintf(file, "fin_%d:\n", etiqueta);
    fprintf(file, "push dword eax\n");
}

void menor_igual(FILE *file, int es_variable_1, int es_variable_2, int etiqueta) {
    if (file == NULL) return;

    cargar_registro(file, "edx", es_variable_2);
    cargar_registro(file, "eax", es_variable_1);

    fprintf(file, "cmp eax, edx\n");
    fprintf(file, "jle devolver_1_%d\n", etiqueta);
    fprintf(file, "mov dword eax, 0\n");
    fprintf(file, "jmp fin_%d\n", etiqueta);
    fprintf(file, "devolver_1_%d:\n", etiqueta);
    fprintf(file, "mov dword eax, 1\n");
    fprintf(file, "fin_%d:\n", etiqueta);
    fprintf(file, "push dword eax\n");
}

void mayor_igual(FILE *file, int es_variable_1, int es_variable_2, int etiqueta) {
    if (file == NULL) return;

    cargar_registro(file, "edx", es_variable_2);
    cargar_registro(file, "eax", es_variable_1);

    fprintf(file, "cmp eax, edx\n");
    fprintf(file, "jge devolver_1_%d\n", etiqueta);
    fprintf(file, "mov dword eax, 0\n");
    fprintf(file, "jmp fin_%d\n", etiqueta);
    fprintf(file, "devolver_1_%d:\n", etiqueta);
    fprintf(file, "mov dword eax, 1\n");
    fprintf(file, "fin_%d:\n", etiqueta);
    fprintf(file, "push dword eax\n");
}

void menor(FILE *file, int es_variable_1, int es_variable_2, int etiqueta) {
    if (file == NULL) return;

    cargar_registro(file, "edx", es_variable_2);
    cargar_registro(file, "eax", es_variable_1);

    fprintf(file, "cmp eax, edx\n");
    fprintf(file, "jl devolver_1_%d\n", etiqueta);
    fprintf(file, "mov dword eax, 0\n");
    fprintf(file, "jmp fin_%d\n", etiqueta);
    fprintf(file, "devolver_1_%d:\n", etiqueta);
    fprintf(file, "mov dword eax, 1\n");
    fprintf(file, "fin_%d:\n", etiqueta);
    fprintf(file, "push dword eax\n");
}

void mayor(FILE *file, int es_variable_1, int es_variable_2, int etiqueta) {
    if (file == NULL) return;

    cargar_registro(file, "edx", es_variable_2);
    cargar_registro(file, "eax", es_variable_1);

    fprintf(file, "cmp eax, edx\n");
    fprintf(file, "jg devolver_1_%d\n", etiqueta);
    fprintf(file, "mov dword eax, 0\n");
    fprintf(file, "jmp fin_%d\n", etiqueta);
    fprintf(file, "devolver_1_%d:\n", etiqueta);
    fprintf(file, "mov dword eax, 1\n");
    fprintf(file, "fin_%d:\n", etiqueta);
    fprintf(file, "push dword eax\n");
}

void leer(FILE *file, char *nombre, int tipo) {
    if (file == NULL || nombre == NULL) return;

    fprintf(file, "push dword _%s\n", nombre);

    if (tipo == ENTERO) {
        fprintf(file, "call scan_int\n");
    } else if (tipo == BOOLEANO) {
        fprintf(file, "call scan_boolean\n");
    } else {
        return;
    }

    fprintf(file, "add esp, 4\n");
}

void escribir(FILE *file, int es_variable, int tipo) {
    if (file == NULL) return;

    if (es_variable) {
        fprintf(file, "pop dword eax\n");
        fprintf(file, "mov dword eax, [eax]\n");
        fprintf(file, "push dword eax\n");
    }

    if (tipo == ENTERO) {
        fprintf(file, "call print_int\n");
    } else if (tipo == BOOLEANO) {
        fprintf(file, "call print_boolean\n");
    } else {
        return;
    }

    fprintf(file, "add esp, 4\n");
    fprintf(file, "call print_endofline\n");
}

void ifthen_inicio(FILE *file, int exp_es_variable, int etiqueta) {
    if (file == NULL) return;

    cargar_registro(file, "eax", exp_es_variable);

    fprintf(file, "cmp eax, %d", FALSE);
    fprintf(file, "je ifthen_fin_%d\n", etiqueta);
}

void ifthen_fin(FILE *file, int etiqueta) {
    if (file == NULL) return;

    fprintf(file, "ifthen_fin_%d:\n", etiqueta);
}

void ifthenelse_inicio(FILE *file, int exp_es_variable, int etiqueta) {
    if (file == NULL) return;

    cargar_registro(file, "eax", exp_es_variable);

    fprintf(file, "cmp eax, %d\n", FALSE);
    fprintf(file, "je ifthenelse_fin_then_%d\n", etiqueta);
}

void ifthenelse_fin_then(FILE *file, int etiqueta) {
    if (file == NULL) return;

    fprintf(file, "jmp ifthenelse_fin_%d\n", etiqueta);
    fprintf(file, "ifthenelse_fin_then_%d:\n", etiqueta);
}

void ifthenelse_fin(FILE *file, int etiqueta) {
    if (file == NULL) return;

    fprintf(file, "ifthenelse_fin_%d:\n", etiqueta);
}

void while_inicio(FILE *file, int etiqueta) {
    if (file == NULL) return;

    fprintf(file, "while_inicio_%d:\n", etiqueta);
}

void while_exp_pila (FILE *file, int exp_es_variable, int etiqueta) {
    if (file == NULL) return;

    cargar_registro(file, "eax", exp_es_variable);

    fprintf(file, "cmp eax, %d\n", FALSE);
    fprintf(file, "je while_fin_%d\n", etiqueta);
}

void while_fin(FILE *file, int etiqueta) {
    if (file == NULL) return;

    fprintf(file, "jmp while_inicio_%d\n", etiqueta);
    fprintf(file, "while_fin_%d:\n", etiqueta);
}

void escribir_elemento_vector(FILE *file, char *nombre_vector, int tam_max, int exp_es_variable) {
    if (file == NULL) return;

    cargar_registro(file, "eax", exp_es_variable);

    fprintf(file, "cmp eax, %d\n", tam_max);
    fprintf(file, "jge fuera_de_rango\n");
    fprintf(file, "lea eax, [_%s+4*eax]\n", nombre_vector);
}

void declararFuncion(FILE *file, char *nombre_funcion, int num_var_loc) {
    if (file == NULL) return;

    fprintf(file, "_%s:\n", nombre_funcion);
    fprintf(file, "push dword ebp\n");
    fprintf(file, "mov ebp, esp\n");
    fprintf(file, "sub esp, %d\n", num_var_loc*4);
}

void escribirParametro(FILE *file, int pos_parametro, int num_total_parametros) {
    if (file == NULL) return;

    fprintf(file, "mov eax, ebp\n");
    fprintf(file, "add eax, %d\n", (num_total_parametros-pos_parametro+1)*4);
    fprintf(file, "push dword eax\n");
}

void escribirVariableLocal(FILE *file, int posicion_variable_local) {
    if (file == NULL) return;

    fprintf(file, "mov eax, ebp\n");
    fprintf(file, "sub eax, %d\n", posicion_variable_local*4);
    fprintf(file, "push dword eax\n");
}

void asignarDestinoEnPila(FILE *file, int es_variable) {
    if (file == NULL) return;

    cargar_registro(file, "eax", FALSE);
    cargar_registro(file, "ebx", es_variable);

    fprintf(file, "mov [eax], ebx\n");
}

void retornarFuncion(FILE *file, int es_variable) {
    if (file == NULL) return;

    cargar_registro(file, "eax", es_variable);

    fprintf(file, "mov esp, ebp\n");
    fprintf(file, "pop dword ebp\n");
    fprintf(file, "ret\n");
}

void operandoEnPilaAArgumento(FILE *file, int es_variable) {
    if (file == NULL) return;

    if (es_variable) {
        fprintf(file, "pop dword eax\n");
        fprintf(file, "mov dword eax, [eax]\n");
        fprintf(file, "push dword eax\n");
    }
}

void llamarFuncion(FILE *file, char *nombre_funcion, int num_argumentos) {
    if (file == NULL) return;

    fprintf(file, "call _%s\n", nombre_funcion);
    limpiarPila(file, num_argumentos);
    fprintf(file, "push eax\n");
}

void limpiarPila(FILE *file, int num_argumentos) {
    if (file == NULL) return;

    fprintf(file, "add esp, %d\n", num_argumentos*4);
}
