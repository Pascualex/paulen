#include "TablaSimbolos.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

int main(int argc, char **argv) {
    FILE *input_file, *output_file;
    char line[100], id[50];
    bool local;
    int value;

    if (argc != 3) {
        printf("Número incorrecto de argumentos.");
        return -1;
    }

    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("No se ha podido abrir el fichero %s.", argv[1]);
        return -1;
    }

    output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("No se ha podido abrir el fichero %s.", argv[2]);
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
                TablaSimbolos_uso_local(id);
                fprintf(output_file, "Imprimir %s (local)\n", id);
            } else {
                TablaSimbolos_uso_global(id);
                fprintf(output_file, "Imprimir %s (global)\n", id);
            }
        } else {
            sscanf(line, "%s %d", id, &value);
            if (value >= 0) {
                if (local) {
                    TablaSimbolos_uso_local(id);
                    fprintf(output_file, "Declarar %s (local) con valor %d\n", id, value);
                } else {
                    TablaSimbolos_uso_global(id);
                    fprintf(output_file, "Declarar %s (global) con valor %d\n", id, value);
                }
            } else {
                if (strcmp(id, "cierre") == 0 && value == -999) {
                    local = false;
                    fprintf(output_file, "Cerrar contexto\n");
                } else {
                    local = true;
                    fprintf(output_file, "Abrir contexto %s\n", id);
                }
            }
        }
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}