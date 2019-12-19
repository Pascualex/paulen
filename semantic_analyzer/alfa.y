%{
    #include "alfa.h"
    #include "y.tab.h"
    #include "TablaSimbolos.h"
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdarg.h>
    #include <stdbool.h>

    extern FILE *yyin;
    extern FILE *yyout;
    extern int yylex(void);
    extern int yylval;
    extern int yyleng;

    extern int row;
    extern int col;
    extern int codigo_tok;

    TablaSimbolos *tabla_simbolos;
    bool local;
    int pos_parametro_actual;
    int num_parametros_actual;
    int num_variables_locales_actual;
    int pos_variable_local_actual;

    tipo_atributos atributos;
    
    int yyerror(char *s);
%}

%union {
    tipo_atributos atributos;
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

/* Precedencia de operadores */
%left TOK_OR TOK_AND TOK_NOT
%left TOK_MENOR TOK_MAYOR TOK_IGUAL TOK_DISTINTO TOK_MENORIGUAL TOK_MAYORIGUAL
%left TOK_MAS TOK_MENOS
%left TOK_ASTERISCO TOK_DIVISION

%start programa


%%

programa: 
    TOK_MAIN TOK_LLAVEIZQUIERDA declaraciones funciones sentencias TOK_LLAVEDERECHA
    { fprintf(yyout, ";R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }\n"); };

declaraciones:
    declaracion
    { fprintf(yyout, ";R2:\t<declaraciones> ::= <declaracion>\n"); } |
    declaracion declaraciones
    { fprintf(yyout, ";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n"); };

declaracion:
    clase identificadores TOK_PUNTOYCOMA
    { fprintf(yyout, ";R4:\t<declaracion> ::= <clase> <identificadores> ;\n"); };

clase:
    clase_escalar
    { atributos.clase = ESCALAR; } |
    clase_vector
    { atributos.clase = VECTOR; };

clase_escalar: 
    tipo
    { fprintf(yyout, ";R9:\t<clase_escalar> ::= <tipo>\n"); };

tipo:
    TOK_INT 
    { atributos.tipo = INT; } |
    TOK_BOOLEAN
    { atributos.tipo = BOOLEAN; };

clase_vector: 
    TOK_ARRAY tipo TOK_CORCHETEIZQUIERDO TOK_CONSTANTE_ENTERA TOK_CORCHETEDERECHO { 
        atributos.tam_vector = yylval.atributos.valor_entero;
        if (tam_vector_actual < 1 || tam_vector_actual > MAX_TAM_VECTOR) {
            printf("ERROR: Tamaño de vector inválido.\n");
            return PARAR_COMPILADOR;
        }
    };

identificadores:
    identificador 
    { fprintf(yyout, ";R18:\t<identificadores> ::= <identificador>\n"); } |
    identificador TOK_COMA identificadores
    { fprintf(yyout, ";R19:\t<identificadores> ::= <identificador> , <identificadores>\n"); };

funciones:
    funcion funciones 
    { fprintf(yyout, ";R20:\t<funciones> ::= <funcion> <funciones>\n"); } |
    /* lambda */ 
    { fprintf(yyout, ";R21:\t<funciones> ::=\n"); };

fn_name:
    TOK_FUNCTION tipo TOK_IDENTIFICADOR {
        if (TablaSimbolos_existe_global(tabla_simbolos, yylval.atributos.lexema)) {
            printf("ERROR: nombre de funcion %s ya utilizado.\n", yylval.atributos.lexema);
            return PARAR_COMPILADOR;
        }
        local = true;
        TablaSimbolos_declarar_global(tabla_simbolos, yylval.atributos.lexema, &atributos);
        TablaSimbolos_declarar_local(tabla_simbolos, yylval.atributos.lexema, &atributos);
        num_variables_locales_actual = 0;
        pos_variable_local_actual = 1;
        num_parametros_actual = 0;
        pos_parametro_actual = 0;
        strcpy(atributos.lexema, yylval.atributos.lexema);
    };

fn_declaration: 
    fn_name TOK_PARENTESISIZQUIERDO parametro_funcion TOK_PARENTESISDERECHO TOK_CORCHETEIZQUIERDO declaraciones_funcion {
        
        // ???
        
        strcpy(atributos.lexema, yylval.atributos.lexema);
    };

funcion:
    fn_declaration sentencias TOK_CORCHETEDERECHO {
        
    };

parametros_funcion: 
    parametro_funcion resto_parametros_funcion
    { fprintf(yyout, ";R23:\t<parametros_funcion> ::= <parametros_funcion> <resto_parametros_funcion>\n"); } |
    /* lambda */ 
    { fprintf(yyout, ";R24:\t<parametros_funcion> ::=\n"); };

resto_parametros_funcion:
    TOK_PUNTOYCOMA parametro_funcion resto_parametros_funcion
    { fprintf(yyout, ";R25:\t<resto_parametros_funcion> ::= ; <parametros_funcion> <resto_parametros_funcion>\n"); } |
    /* lambda */ 
    { fprintf(yyout, ";R26:\t<resto_parametros_funcion> ::=\n"); };

parametro_funcion: 
    tipo idpf
    { fprintf(yyout, ";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n"); };

declaraciones_funcion:
    declaraciones 
    { fprintf(yyout, ";R28:\t<declaraciones_funcion> ::= <declaraciones>\n"); } |
    /* lambda */ 
    { fprintf(yyout, ";R29:\t<declaraciones_funcion> ::=\n"); };

sentencias: 
    sentencia 
    { fprintf(yyout, ";R30:\t<sentencias> ::= <sentencia>\n"); } |
    sentencia sentencias
    { fprintf(yyout, ";R31:\t<sentencias> ::= <sentencia> <sentencias>\n"); };

sentencia:
    sentencia_simple TOK_PUNTOYCOMA
    { fprintf(yyout, ";R32:\t<sentencia> ::= <sentencia_simple> ;\n"); } |
    bloque
    { fprintf(yyout, ";R33:\t<sentencia> ::= <bloque>\n"); };

sentencia_simple:
    asignacion 
    { fprintf(yyout, ";R34:\t<sentencia_simple> ::= <asignacion>\n"); } |
    lectura 
    { fprintf(yyout, ";R35:\t<sentencia_simple> ::= <lectura>\n"); } |
    escritura 
    { fprintf(yyout, ";R36:\t<sentencia_simple> ::= <escritura>\n"); } |
    retorno_funcion
    { fprintf(yyout, ";R38:\t<sentencia_simple> ::= <retorno_funcion>\n"); };

bloque:
    condicional 
    { fprintf(yyout, ";R40:\t<bloque> ::= <condicional>\n"); } |
    bucle
    { fprintf(yyout, ";R41:\t<bloque> ::= <bucle>\n"); };

asignacion: 
    identificador TOK_ASIGNACION exp 
    { fprintf(yyout, ";R43:\t<asignacion> ::= <identificador> = <exp>\n"); } |
    elemento_vector TOK_ASIGNACION exp
    { fprintf(yyout, ";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n"); };

elemento_vector: 
    identificador TOK_CORCHETEIZQUIERDO exp TOK_CORCHETEDERECHO
    { fprintf(yyout, ";R48:\t<elemento_vector> ::= <identificador> [ <exp> ]\n"); };

condicional:
    TOK_IF TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA 
    { fprintf(yyout, ";RMAX_LONGITUD_ID:\t<condicional> ::= if ( <exp> ) { <sentencias> }\n"); } |
    TOK_IF TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA TOK_ELSE TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA
    { fprintf(yyout, ";RMAX_LONGITUD_ID+1:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n"); };

bucle: 
    TOK_WHILE TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA
    { fprintf(yyout, ";R52:\t<bucle> ::= while ( <exp> ) { <sentencias> }\n"); };

lectura: 
    TOK_SCANF identificador
    { fprintf(yyout, ";R54:\t<lectura> ::= scanf <identificador>\n"); };

escritura: 
    TOK_PRINTF exp
    { fprintf(yyout, ";R56:\t<escritura> ::= printf <exp>\n"); };

retorno_funcion: 
    TOK_RETURN exp
    { fprintf(yyout, ";R61:\t<retorno_funcion> ::= return <exp>\n"); };

exp: 
    exp TOK_MAS exp 
    { fprintf(yyout, ";R72:\t<exp> ::= <exp> + <exp>\n"); } |
    exp TOK_MENOS exp 
    { fprintf(yyout, ";R73:\t<exp> ::= <exp> - <exp>\n"); } |
    exp TOK_DIVISION exp 
    { fprintf(yyout, ";R74:\t<exp> ::= <exp> / <exp>\n"); } |
    exp TOK_ASTERISCO exp 
    { fprintf(yyout, ";R75:\t<exp> ::= <exp> * <exp>\n"); } |
    TOK_MENOS exp 
    { fprintf(yyout, ";R76:\t<exp> ::= - <exp>\n"); } |
    exp TOK_AND exp 
    { fprintf(yyout, ";R77:\t<exp> ::= <exp> && <exp>\n"); } |
    exp TOK_OR exp 
    { fprintf(yyout, ";R78:\t<exp> ::= <exp> || <exp>\n"); } |
    TOK_NOT exp 
    { fprintf(yyout, ";R79:\t<exp> ::= ! <exp>\n"); } |
    identificador 
    { fprintf(yyout, ";R80:\t<exp> ::= <identificador>\n"); } |
    constante 
    { fprintf(yyout, ";R81:\t<exp> ::= <constante>\n"); } |
    TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO 
    { fprintf(yyout, ";R82:\t<exp> ::= ( <exp> )\n"); } |
    TOK_PARENTESISIZQUIERDO comparacion TOK_PARENTESISDERECHO 
    { fprintf(yyout, ";R83:\t<exp> ::= ( <comparacion> )\n"); } |
    elemento_vector 
    { fprintf(yyout, ";R85:\t<exp> ::= <elemento_vector>\n"); } |
    identificador TOK_PARENTESISIZQUIERDO lista_expresiones TOK_PARENTESISDERECHO
    { fprintf(yyout, ";R88:\t<exp> ::= <identificador> ( <lista_expresiones> )\n"); };

lista_expresiones:
    exp resto_lista_expresiones
    { fprintf(yyout, ";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n"); } |
    /* lambda */
    { fprintf(yyout, ";R90:\t<lista_expresiones> ::=\n"); };

resto_lista_expresiones:
    TOK_COMA exp resto_lista_expresiones
    { fprintf(yyout, ";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>\n"); } |
    /* lambda */
    { fprintf(yyout, ";R92:\t<resto_lista_expresiones> ::=\n"); };

comparacion:
    exp TOK_IGUAL exp 
    { fprintf(yyout, ";R93:\t<comparacion> ::= <exp> == <exp>\n"); } |
    exp TOK_DISTINTO exp 
    { fprintf(yyout, ";R94:\t<comparacion> ::= <exp> != <exp>\n"); } |
    exp TOK_MENORIGUAL exp 
    { fprintf(yyout, ";R95:\t<comparacion> ::= <exp> <= <exp>\n"); } |
    exp TOK_MAYORIGUAL exp 
    { fprintf(yyout, ";R96:\t<comparacion> ::= <exp> >= <exp>\n"); } |
    exp TOK_MENOR exp 
    { fprintf(yyout, ";R97:\t<comparacion> ::= <exp> < <exp>\n"); } |
    exp TOK_MAYOR exp
    { fprintf(yyout, ";R98:\t<comparacion> ::= <exp> > <exp>\n"); };

constante:
    constante_logica 
    { fprintf(yyout, ";R99:\t<constante> ::= <constante_logica>\n"); } |
    constante_entera
    { fprintf(yyout, ";R100:\t<constante> ::= <constante_entera>\n"); };

constante_logica:
    TOK_TRUE 
    { fprintf(yyout, ";R100:\t<constante_logica> ::= true\n"); } |
    TOK_FALSE
    { fprintf(yyout, ";R100:\t<constante_logica> ::= false\n"); };

constante_entera:
    TOK_CONSTANTE_ENTERA
    { fprintf(yyout, ";R104:\t<constante_entera> ::= TOK_CONSTANTE_ENTERA\n"); };

identificador:
    TOK_IDENTIFICADOR {
        strcpy(atributos.lexema, yylval.atributos.lexema);
        if (local) {
            if (TablaSimbolos_existe_local(tabla_simbolos, atributos.lexema)) {
                printf("ERROR: Identificador %s duplicado.\n", atributos.lexema);
                return PARAR_COMPILADOR;
            } else {
                TablaSimbolos_declarar_local(tabla_simbolos, atributos.lexema, &atributos);
            }
        } else {
            if (TablaSimbolos_existe_global(tabla_simbolos, atributos.lexema)) {
                printf("ERROR: Identificador %s duplicado.\n", atributos.lexema);
                return PARAR_COMPILADOR;
            } else {
                TablaSimbolos_declarar_global(tabla_simbolos, atributos.lexema, &atributos);
            }
        }
    };

idpf:
    TOK_IDENTIFICADOR {
        strcpy(atributos.lexema, yylval.atributos.lexema);
        if (TablaSimbolos_existe_local(tabla_simbolos, atributos.lexema)) {
            printf("ERROR: Identificador %s duplicado en la declaración de la función.\n", atributos.lexema);
            return PARAR_COMPILADOR;
        }
        atributos.posicion = pos_parametro_actual;
        TablaSimbolos_declarar_local(tabla_simbolos, atributos.lexema, &atributos);
        pos_parametro_actual++;
        num_parametros_actual++;
    };

%%

int main(int argc, char **argv) {
    int status;

    if (argc != 3) {
        printf("Número incorrecto de argumentos.\n");
        return -1;
    }

    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
        printf("No se ha podido abrir el fichero %s.\n", argv[1]);
        return -1;
    }

    yyout = fopen(argv[2], "w");
    if (yyout == NULL) {
        printf("No se ha podido abrir el fichero %s.\n", argv[2]);
        fclose(yyin);
        return -1;
    }

    tabla_simbolos = TablaSimbolos_create();
    if (tabla_simbolos == NULL) {
        printf("No se ha podido crear la tabla de símbolos.\n");
        fclose(yyin);
        fclose(yyout);
        return -1;
    }

    local = false;

    status = yyparse();

    TablaSimbolos_free(tabla_simbolos);
    fclose(yyin);
    fclose(yyout);

    return status;
}

int yyerror(char *s) {
    if (codigo_tok != TOK_ERROR) {
        fprintf(stderr, "Error sintactico en [lin %d, col %d]\n", row, col-yyleng);
    }
    return 0;
}