%{
#include "tokens.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

int row = 1;
int col = 1;

void print_and_update(char *format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(yyout, format, args);
    va_end(args);
    col += yyleng;
}
%}

%option noyywrap

DIGITO [0-9]
LETRA [a-zA-Z]

%%
    /* Palabras reservadas */
"main" { print_and_update("TOK_MAIN %d main\n", TOK_MAIN); }
"int" { print_and_update("TOK_INT %d int\n", TOK_INT); }
"bool" { print_and_update("TOK_BOOLEAN %d bool\n", TOK_BOOLEAN); }
"array" { print_and_update("TOK_ARRAY %d array\n", TOK_ARRAY); }
"function" { print_and_update("TOK_FUNCTION %d function\n", TOK_FUNCTION); }
"if" { print_and_update("TOK_IF %d if\n", TOK_IF); }
"else" { print_and_update("TOK_ELSE %d else\n", TOK_ELSE); }
"while" { print_and_update("TOK_WHILE %d while\n", TOK_WHILE); }
"scanf" { print_and_update("TOK_SCANF %d scanf\n", TOK_SCANF); }
"printf" { print_and_update("TOK_PRINTF %d printf\n", TOK_PRINTF); }
"return" { print_and_update("TOK_RETURN %d return\n", TOK_RETURN); }

    /* Símbolos */
";" { print_and_update("TOK_PUNTOYCOMA %d ;\n", TOK_PUNTOYCOMA); }
"," { print_and_update("TOK_COMA %d ,\n", TOK_COMA); }
"(" { print_and_update("TOK_PARENTESISIZQUIERDO %d (\n", TOK_PARENTESISIZQUIERDO); }
")" { print_and_update("TOK_PARENTESISDERECHO %d )\n", TOK_PARENTESISDERECHO); }
"[" { print_and_update("TOK_CORCHETEIZQUIERDO %d [\n", TOK_CORCHETEIZQUIERDO); }
"]" { print_and_update("TOK_CORCHETEDERECHO %d ]\n", TOK_CORCHETEDERECHO); }
"{" { print_and_update("TOK_LLAVEIZQUIERDA %d {\n", TOK_LLAVEIZQUIERDA); }
"}" { print_and_update("TOK_LLAVEDERECHA %d }\n", TOK_LLAVEDERECHA); }
"=" { print_and_update("TOK_ASIGNACION %d =\n", TOK_ASIGNACION); }
"+" { print_and_update("TOK_MAS %d +\n", TOK_MAS); }
"-" { print_and_update("TOK_MENOS %d -\n", TOK_MENOS); }
"/" { print_and_update("TOK_DIVISION %d /\n", TOK_DIVISION); }
"*" { print_and_update("TOK_ASTERISCO %d *\n", TOK_ASTERISCO); }
"and" { print_and_update("TOK_AND %d and\n", TOK_AND); }
"or" { print_and_update("TOK_OR %d or\n", TOK_OR); }
"not" { print_and_update("TOK_NOT %d not\n", TOK_NOT); }
"==" { print_and_update("TOK_IGUAL %d ==\n", TOK_IGUAL); }
"!=" { print_and_update("TOK_DISTINTO %d !=\n", TOK_DISTINTO); }
"<=" { print_and_update("TOK_MENORIGUAL %d <=\n", TOK_MENORIGUAL); }
">=" { print_and_update("TOK_MAYORIGUAL %d >=\n", TOK_MAYORIGUAL); }
"<" { print_and_update("TOK_MENOR %d <\n", TOK_MENOR); }
">" { print_and_update("TOK_MAYOR %d >\n", TOK_MAYOR); }

    /* Constantes */ 
{DIGITO}+ { print_and_update("TOK_CONSTANTE_ENTERA %d %s\n", TOK_CONSTANTE_ENTERA, yytext); }
"true" { print_and_update("TOK_TRUE %d true\n", TOK_TRUE); }
"false" { print_and_update("TOK_FALSE %d false\n", TOK_FALSE); }

    /* Identificadores */
{LETRA}({LETRA}|{DIGITO})* {
    if (yyleng > 50) {
        fprintf(stderr, "Error en [lin %d, col %d]: identificador demasiado largo (%s)\n", row, col, yytext);
        return -1;
    }
    print_and_update("TOK_IDENTIFICADOR %d %s\n", TOK_IDENTIFICADOR, yytext);
}

    /* Separadores */
" "+ { col += yyleng; }
"\t" { col += 4-yyleng%4; }
"\n" { row++; col = 1; }

    /* Comentarios */
"//".+ { }

    /* Errores */
. {
    fprintf(stderr, "Error en [lin %d, col %d]: simbolo no permitido (%s)\n", row, col, yytext);
    return -1;
}

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