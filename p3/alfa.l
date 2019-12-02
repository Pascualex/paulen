%{
    #include "y.tab.h"
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdarg.h>

    int row = 1;
    int col = 1;

    void print_and_update();
%}

%option noyywrap

DIGITO [0-9]
LETRA [a-zA-Z]

%%
    /* Palabras reservadas */
"main" { print_and_update(); return TOK_MAIN; }
"int" { print_and_update(); return TOK_INT; }
"bool" { print_and_update(); return TOK_BOOLEAN; }
"array" { print_and_update(); return TOK_ARRAY; }
"function" { print_and_update(); return TOK_FUNCTION; }
"if" { print_and_update(); return TOK_IF; }
"else" { print_and_update(); return TOK_ELSE; }
"while" { print_and_update(); return TOK_WHILE; }
"scanf" { print_and_update(); return TOK_SCANF; }
"printf" { print_and_update(); return TOK_PRINTF; }
"return" { print_and_update(); return TOK_RETURN; }

    /* Símbolos */
";" { print_and_update(); return TOK_PUNTOYCOMA; }
"," { print_and_update(); return TOK_COMA; }
"(" { print_and_update(); return TOK_PARENTESISIZQUIERDO; }
")" { print_and_update(); return TOK_PARENTESISDERECHO; }
"[" { print_and_update(); return TOK_CORCHETEIZQUIERDO; }
"]" { print_and_update(); return TOK_CORCHETEDERECHO; }
"{" { print_and_update(); return TOK_LLAVEIZQUIERDA; }
"}" { print_and_update(); return TOK_LLAVEDERECHA; }
"=" { print_and_update(); return TOK_ASIGNACION; }
"+" { print_and_update(); return TOK_MAS; }
"-" { print_and_update(); return TOK_MENOS; }
"/" { print_and_update(); return TOK_DIVISION; }
"*" { print_and_update(); return TOK_ASTERISCO; }
"and" { print_and_update(); return TOK_AND; }
"or" { print_and_update(); return TOK_OR; }
"not" { print_and_update(); return TOK_NOT; }
"==" { print_and_update(); return TOK_IGUAL; }
"!=" { print_and_update(); return TOK_DISTINTO; }
"<=" { print_and_update(); return TOK_MENORIGUAL; }
">=" { print_and_update(); return TOK_MAYORIGUAL; }
"<" { print_and_update(); return TOK_MENOR; }
">" { print_and_update(); return TOK_MAYOR; }

    /* Constantes */ 
{DIGITO}+ { print_and_update(); return TOK_CONSTANTE_ENTERA; }
"true" { print_and_update(); return TOK_TRUE; }
"false" { print_and_update(); return TOK_FALSE; }

    /* Identificadores */
{LETRA}({LETRA}|{DIGITO})* { print_and_update(); return TOK_IDENTIFICADOR; }

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

void print_and_update() {
    col += yyleng;
    fprintf( , ";D: %s", yytext);
}