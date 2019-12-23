%{
    #include "alfa.h"
    #include "y.tab.h"
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdarg.h>

    int row = 1;
    int col = 1;
    int codigo_tok;

    int print_and_update(int codigo_tok_actual);
%}

%option noyywrap

DIGITO [0-9]
LETRA [a-zA-Z]

%%
    /* Palabras reservadas */
"main" { return print_and_update(TOK_MAIN); }
"int" { return print_and_update(TOK_INT); }
"boolean" { return print_and_update(TOK_BOOLEAN); }
"array" { return print_and_update(TOK_ARRAY); }
"function" { return print_and_update(TOK_FUNCTION); }
"if" { return print_and_update(TOK_IF); }
"else" { return print_and_update(TOK_ELSE); }
"while" { return print_and_update(TOK_WHILE); }
"scanf" { return print_and_update(TOK_SCANF); }
"printf" { return print_and_update(TOK_PRINTF); }
"return" { return print_and_update(TOK_RETURN); }

    /* Símbolos */
";" { return print_and_update(TOK_PUNTOYCOMA); }
"," { return print_and_update(TOK_COMA); }
"(" { return print_and_update(TOK_PARENTESISIZQUIERDO); }
")" { return print_and_update(TOK_PARENTESISDERECHO); }
"[" { return print_and_update(TOK_CORCHETEIZQUIERDO); }
"]" { return print_and_update(TOK_CORCHETEDERECHO); }
"{" { return print_and_update(TOK_LLAVEIZQUIERDA); }
"}" { return print_and_update(TOK_LLAVEDERECHA); }
"=" { return print_and_update(TOK_ASIGNACION); }
"+" { return print_and_update(TOK_MAS); }
"-" { return print_and_update(TOK_MENOS); }
"/" { return print_and_update(TOK_DIVISION); }
"*" { return print_and_update(TOK_ASTERISCO); }
"&&" { return print_and_update(TOK_AND); }
"||" { return print_and_update(TOK_OR); }
"!" { return print_and_update(TOK_NOT); }
"==" { return print_and_update(TOK_IGUAL); }
"!=" { return print_and_update(TOK_DISTINTO); }
"<=" { return print_and_update(TOK_MENORIGUAL); }
">=" { return print_and_update(TOK_MAYORIGUAL); }
"<" { return print_and_update(TOK_MENOR); }
">" { return print_and_update(TOK_MAYOR); }

    /* Constantes */ 
"true" { return print_and_update(TOK_TRUE); }
"false" { return print_and_update(TOK_FALSE); }
{DIGITO}+ {
    yylval.atributos.valor_entero = atoi(yytext);
    return print_and_update(TOK_CONSTANTE_ENTERA);
}

    /* Identificadores */
{LETRA}({LETRA}|{DIGITO})* {
    if (yyleng > MAX_LONGITUD_ID) {
        fprintf(stderr, "Error morfológico [lin %d, col %d]: identificador demasiado largo (%s)\n", row, col, yytext);
        codigo_tok = TOK_ERROR;
        return TOK_ERROR;
    } else {
        strcpy(yylval.atributos.lexema, yytext);
        return print_and_update(TOK_IDENTIFICADOR);
    }
}

    /* Separadores */
" "+ { col += yyleng; }
"\t" { col += 4-yyleng%4; }
"\n" { row++; col = 1; }

    /* Comentarios */
"//".+ { }

    /* Errores */
. {
    fprintf(stderr, "Error morfológico [lin %d, col %d]: simbolo no permitido (%s)\n", row, col, yytext);
    codigo_tok = TOK_ERROR;
    return TOK_ERROR;
}

%%

int print_and_update(int codigo_tok_actual) {
    codigo_tok = codigo_tok_actual;
    col += yyleng;
    //fprintf(yyout, ";D:\t%s\n", yytext);
    return codigo_tok;
}