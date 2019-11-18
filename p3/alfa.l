%{
    #include "y.tab.h"
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdarg.h>

    int row = 1;
    int col = 1;

    void print_and_update(char *format, ...);
%}

%option noyywrap

DIGITO [0-9]
LETRA [a-zA-Z]

%%
    /* Palabras reservadas */
"main" { col += yyleng; return TOK_MAIN; }
"int" { col += yyleng; return TOK_INT; }
"bool" { col += yyleng; return TOK_BOOLEAN; }
"array" { col += yyleng; return TOK_ARRAY; }
"function" { col += yyleng; return TOK_FUNCTION; }
"if" { col += yyleng; return TOK_IF; }
"else" { col += yyleng; return TOK_ELSE; }
"while" { col += yyleng; return TOK_WHILE; }
"scanf" { col += yyleng; return TOK_SCANF; }
"printf" { col += yyleng; return TOK_PRINTF; }
"return" { col += yyleng; return TOK_RETURN; }

    /* Símbolos */
";" { col += yyleng; return TOK_PUNTOYCOMA; }
"," { col += yyleng; return TOK_COMA; }
"(" { col += yyleng; return TOK_PARENTESISIZQUIERDO; }
")" { col += yyleng; return TOK_PARENTESISDERECHO; }
"[" { col += yyleng; return TOK_CORCHETEIZQUIERDO; }
"]" { col += yyleng; return TOK_CORCHETEDERECHO; }
"{" { col += yyleng; return TOK_LLAVEIZQUIERDA; }
"}" { col += yyleng; return TOK_LLAVEDERECHA; }
"=" { col += yyleng; return TOK_ASIGNACION; }
"+" { col += yyleng; return TOK_MAS; }
"-" { col += yyleng; return TOK_MENOS; }
"/" { col += yyleng; return TOK_DIVISION; }
"*" { col += yyleng; return TOK_ASTERISCO; }
"and" { col += yyleng; return TOK_AND; }
"or" { col += yyleng; return TOK_OR; }
"not" { col += yyleng; return TOK_NOT; }
"==" { col += yyleng; return TOK_IGUAL; }
"!=" { col += yyleng; return TOK_DISTINTO; }
"<=" { col += yyleng; return TOK_MENORIGUAL; }
">=" { col += yyleng; return TOK_MAYORIGUAL; }
"<" { col += yyleng; return TOK_MENOR; }
">" { col += yyleng; return TOK_MAYOR; }

    /* Constantes */ 
{DIGITO}+ { col += yyleng; return TOK_CONSTANTE_ENTERA; }
"true" { col += yyleng; return TOK_TRUE; }
"false" { col += yyleng; return TOK_FALSE; }

    /* Identificadores */
{LETRA}({LETRA}|{DIGITO})* { col += yyleng; return TOK_IDENTIFICADOR; }

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