%{
#include "tokens.h"
#include <stdio.h>
%}

%option noyywrap

DIGITO [0-9]
LETRA [a-zA-Z]

%%
main { fprintf(yyout, "TOK_MAIN %d main\n", TOK_MAIN); }
{LETRA}({LETRA}|{DIGITO})* { fprintf(yyout, "TOK_IDENTIFICADOR %d %s\n", TOK_IDENTIFICADOR, yytext); }
[ \t\n]+ { }
[.]+ { fprintf(yyout, "ERROR PALABRA_NO_RECONOCIDA %s\n", yytext); }
%%

int main(int argc, char **argv) {
    int status;

    if (argc != 3) {
        printf("Número incorrecto de argumentos.");
        return -1;
    }

    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
        printf("No se ha podido abrir el fichero %s.", argv[1]);
        return -1;
    }

    yyout = fopen(argv[2], "w");
    if (yyout == NULL) {
        printf("No se ha podido abrir el fichero %s.", argv[2]);
        fclose(yyin);
        return -1;
    }

    status = yylex();
    fclose(yyin);
    fclose(yyout);
    return status;
}