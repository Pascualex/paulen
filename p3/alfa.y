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

%start programa

%left "||" "&&" "!"
%left "<" ">" "==" "!=" "<=" ">="
%left "+" "-"
%left "*" "/"

%%

programa: TOK_MAIN TOK_LLAVEIZQUIERDA declaraciones funciones sentencias TOK_LLAVEDERECHA;

declaraciones:
    declaracion |
    declaracion declaraciones;

declaracion: clase identificadores TOK_PUNTOYCOMA;

clase:
    clase_escalar |
    clase_vector;

clase_escalar: tipo;

tipo:
    TOK_INT |
    TOK_BOOLEAN;

clase_vector: TOK_ARRAY tipo TOK_CORCHETEIZQUIERDO TOK_CONSTANTE_ENTERA TOK_CORCHETEDERECHO;

identificadores:
    TOK_IDENTIFICADOR |
    TOK_IDENTIFICADOR TOK_COMA identificadores;

funciones:
    funcion funciones |
    /* lambda */ ;

funcion: TOK_FUNCTION tipo TOK_IDENTIFICADOR TOK_PARENTESISIZQUIERDO parametros_funcion TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA declaraciones_funcion sentencias TOK_LLAVEDERECHA;

parametros_funcion: 
    parametros_funcion resto_parametros_funcion |
    /* lambda */ ;

resto_parametros_funcion:
    TOK_PUNTOYCOMA parametros_funcion resto_parametros_funcion |
    /* lambda */ ;

parametros_funcion: tipo TOK_IDENTIFICADOR;

declaraciones_funcion:
    declaraciones |
    /* lambda */ ;

sentencias: 
    sentencia |
    sentencia sentencias;

sentencia:
    sentencia_simple TOK_PUNTOYCOMA |
    bloque;

sentencia_simple:
    asignacion |
    lectura |
    escritura |
    retorno_funcion;

bloque:
    condicional |
    bucle;

asignacion: 
    TOK_IDENTIFICADOR TOK_IGUAL exp |
    elemento_vector TOK_IGUAL exp;

elemento_vector: TOK_IDENTIFICADOR TOK_CORCHETEIZQUIERDO exp TOK_CORCHETEDERECHO;

condicional:
    TOK_IF TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA |
    TOK_IF TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA TOK_ELSE TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA;

bucle: TOK_WHILE TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA;

lectura: TOK_SCANF TOK_IDENTIFICADOR;

escritura: TOK_PRINTF exp;

retorno_funcion: TOK_RETURN exp;

exp: 
    exp TOK_MAS exp |
    exp TOK_MENOR exp |
    exp TOK_DIVISION exp |
    exp TOK_ASTERISCO exp |
    TOK_MENOS exp |
    exp TOK_AND exp |
    exp TOK_OR exp |
    TOK_NOT exp |
    TOK_IDENTIFICADOR |
    constante |
    TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO |
    TOK_PARENTESISIZQUIERDO comparacion TOK_PARENTESISDERECHO |
    elemento_vector |
    TOK_IDENTIFICADOR TOK_PARENTESISIZQUIERDO lista_expresiones TOK_PARENTESISDERECHO;

lista_expresiones:
    exp resto_lista_expresiones |
    /* lambda */;

comparacion:
    exp TOK_IGUAL exp |
    exp TOK_DISTINTO exp |
    exp TOK_MENORIGUAL exp |
    exp TOK_MAYORIGUAL exp |
    exp TOK_MENOR exp |
    exp TOK_MAYOR exp;

constante:
    constante_logica |
    TOK_CONSTANTE_ENTERA;

constante_logica:
    TOK_TRUE |
    TOK_FALSE;

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