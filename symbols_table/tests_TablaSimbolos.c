#include "TablaSimbolos.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool only_one_word(char line[100]);

int main(int argc, char **argv) {
    FILE *input_file, *output_file;
    TablaSimbolos *tabla_simbolos;
    char line[100], id[51];
    bool local;
    int value, ret;

    if (argc != 3) {
        printf("Número incorrecto de argumentos.\n");
        return -1;
    }

    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("No se ha podido abrir el fichero %s.\n", argv[1]);
        return -1;
    }

    output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("No se ha podido abrir el fichero %s.\n", argv[2]);
        fclose(input_file);
        return -1;
    }

    tabla_simbolos = TablaSimbolos_create();
    if (tabla_simbolos == NULL) {
        printf("No se ha podido crear la tabla de símbolos.\n");
        fclose(output_file);
        fclose(input_file);
        return -1;
    }

    local = false;
    while (1) {
        fgets(line, sizeof(line), input_file);
        if (feof(input_file)) break;

        if (only_one_word(line)) {
            sscanf(line, "%s", id);
            if (local) {
                ret = TablaSimbolos_uso_local(tabla_simbolos, id);
                fprintf(output_file, "%s %d\n", id, ret);
            } else {
                ret = TablaSimbolos_uso_global(tabla_simbolos, id);
                fprintf(output_file, "%s %d\n", id, ret);
            }
        } else {
            sscanf(line, "%s %d", id, &value);
            if (value >= 0) {
                if (local) {
                    ret = TablaSimbolos_declarar_local(tabla_simbolos, id, value);
                    if (ret == OK) fprintf(output_file, "%s\n", id);
                    else fprintf(output_file, "-1 %s\n", id);
                } else {
                    ret = TablaSimbolos_declarar_global(tabla_simbolos, id, value);
                    if (ret == OK) fprintf(output_file, "%s\n", id);
                    else fprintf(output_file, "-1 %s\n", id);
                }
            } else if (value < -1) {
                if (strcmp(id, "cierre") == 0 && value == -999) {
                    TablaSimbolos_terminar_funcion(tabla_simbolos);
                    local = false;
                    fprintf(output_file, "cierre\n");
                } else {
                    ret = TablaSimbolos_declarar_funcion(tabla_simbolos, id, value);
                    local = true;
                    if (ret == OK) fprintf(output_file, "%s\n", id);
                    else fprintf(output_file, "-1 %s\n", id);
                }
            } else {
                fprintf(output_file, "ERROR EN EL TEST - El identificador no puede ser -1\n");
            }
        }
    }

    TablaSimbolos_free(tabla_simbolos);
    fclose(output_file);
    fclose(input_file);

    return 0;
}

bool only_one_word(char line[100]) {
    bool first_word_found, space_found;
    int i;

    first_word_found = false;
    space_found = false;

    for (i = 0; i < 100; i++) {
        if (line[i] == '\0') break;
        if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n') {
            if (first_word_found) space_found = true;
        } else {
            first_word_found = true;
            if (space_found) return false;
        }
    }

    return true;
}