#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generacion.h"

int main (int argc, char **argv) {
    FILE *fd_asm;

    if (argc != 2) {
        fprintf (stdout, "ERROR POCOS ARGUMENTOS\n");
        return -1;
    }

    fd_asm = fopen(argv[1], "w");

    escribir_subseccion_data(fd_asm);
    escribir_cabecera_bss(fd_asm);

    //int z;
    declarar_variable(fd_asm, "z", 1, 1);
    
    escribir_segmento_codigo(fd_asm);
    escribir_inicio_main(fd_asm);

    //z=2
    escribir_operando(fd_asm, "2", 0);
    asignar(fd_asm, "z", 0);

    //for (int i = 1; i <= 3; i++) z=z+3
    escribir_operando(fd_asm, "1", 0);
    escribir_operando(fd_asm, "3", 0);
    escribir_operando(fd_asm, "1", 0);
    escribir_codigo_for(fd_asm, 0, 0, 0, "add dword [_z], 3\n", 0);
    
    //Imprimimos el resultado de la funcion.
    escribir_operando(fd_asm, "z", 1);
    escribir(fd_asm, 1, ENTERO);

    escribir_fin(fd_asm);
    fclose(fd_asm);

    return 0;
}