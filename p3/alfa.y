%{
    #include "y.tab.h"
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdarg.h>

    extern FILE *yyin;
    extern FILE *yyout;
    extern int yylex(void);

    int yyerror(char *s);
%}

%union {
    char *cadena;
    int numero;
}

/* Palabras reservadas */ 
%token TOK_MAIN
%token TOK_INT
%token TOK_BOOLEAN
%token TOK_ARRAY
%token TOK_FUNCTION
%token TOK_IF
%token TOK_ELSE
%token TOK_WHILE
%token TOK_SCANF
%token TOK_PRINTF
%token TOK_RETURN

/* Símbolos */
%token TOK_PUNTOYCOMA
%token TOK_COMA
%token TOK_PARENTESISIZQUIERDO
%token TOK_PARENTESISDERECHO
%token TOK_CORCHETEIZQUIERDO
%token TOK_CORCHETEDERECHO
%token TOK_LLAVEIZQUIERDA
%token TOK_LLAVEDERECHA
%token TOK_ASIGNACION
%token TOK_MAS
%token TOK_MENOS
%token TOK_DIVISION
%token TOK_ASTERISCO
%token TOK_AND
%token TOK_OR
%token TOK_NOT
%token TOK_IGUAL
%token TOK_DISTINTO
%token TOK_MENORIGUAL
%token TOK_MAYORIGUAL
%token TOK_MENOR
%token TOK_MAYOR

/* Identificadores  */
%token <cadena> TOK_IDENTIFICADOR

/* Constantes */ 
%token <numero> TOK_CONSTANTE_ENTERA
%token TOK_TRUE
%token TOK_FALSE

/* Errores */
%token TOK_ERROR

%start S

%%

S: ;

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

    status = yyparse();
    fclose(yyin);
    fclose(yyout);
    return status;
}

int yyerror(char *s) {
    return 0;
}