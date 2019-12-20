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
    bool en_explist;
    int tipo_actual;
    int clase_actual;
    int tam_vector_actual;
    
    int pos_parametro_actual;
    int num_parametros_actual;
    int pos_variable_local_actual;
    int num_variables_locales_actual;
    
    tipo_atributos atributos_actuales;
    
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

%type <tipo_atributos> exp
%type <tipo_atributos> constante
%type <tipo_atributos> constante_entera
%type <tipo_atributos> constante_logica
%type <tipo_atributos> fn_name
%type <tipo_atributos> fn_declaration

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
    { clase_actual = ESCALAR; } |
    clase_vector
    { clase_actual = VECTOR; };

clase_escalar:
    tipo
    { fprintf(yyout, ";R9:\t<clase_escalar> ::= <tipo>\n"); };

tipo:
    TOK_INT 
    { tipo_actual = INT; } |
    TOK_BOOLEAN
    { tipo_actual = BOOLEAN; };

clase_vector:
    TOK_ARRAY tipo TOK_CORCHETEIZQUIERDO TOK_CONSTANTE_ENTERA TOK_CORCHETEDERECHO { 
        tam_vector_actual = $4.valor_entero;
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
        if (TablaSimbolos_existe_global(tabla_simbolos, $3.lexema)) {
            printf("ERROR: nombre de funcion %s ya utilizado.\n", $3.lexema);
            return PARAR_COMPILADOR;
        }

        local = true;
        num_parametros_actual = 0;
        pos_parametro_actual = 0;
        num_variables_locales_actual = 0;
        pos_variable_local_actual = 1;

        strcpy(atributos_actuales.lexema, $3.lexema);
        atributos_actuales.clase = FUNCION;
        atributos_actuales.tipo = $2.tipo;

        TablaSimbolos_declarar_global(tabla_simbolos, $3.lexema, &atributos_actuales);
        TablaSimbolos_declarar_local(tabla_simbolos, $3.lexema, &atributos_actuales);

        strcpy($$.lexema, $3.lexema);
    };

fn_declaration:
    fn_name TOK_PARENTESISIZQUIERDO parametro_funcion TOK_PARENTESISDERECHO TOK_CORCHETEIZQUIERDO declaraciones_funcion {
        TablaSimbolos_uso_global(tabla_simbolos, $1.lexema)->num_parametros = num_parametros_actual;
        TablaSimbolos_uso_local(tabla_simbolos, $1.lexema)->num_parametros = num_parametros_actual;
        strcpy($$.lexema, $1.lexema);
    };

funcion:
    fn_declaration sentencias TOK_CORCHETEDERECHO {
        local = false;
        TablaSimbolos_uso_global(tabla_simbolos, $1.lexema)->num_variables_locales = num_variables_locales_actual;
        TablaSimbolos_uso_local(tabla_simbolos, $1.lexema)->num_variables_locales = num_variables_locales_actual;
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
    TOK_IDENTIFICADOR TOK_ASIGNACION exp { 
        if ((local && !TablaSimbolos_existe_local(tabla_simbolos, $1.lexema)) || (!local && !TablaSimbolos_existe_global(tabla_simbolos, $1.lexema))) {
            printf("ERROR: El identificador %s no ha sido declarado.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        atributos_actuales = (local ? TablaSimbolos_uso_local(tabla_simbolos, $1.lexema) : TablaSimbolos_uso_global(tabla_simbolos, $1.lexema));
        if (atributos_actuales.tipo == FUNCION) {
            printf("ERROR: El identificador %s corresponde a una función, por lo que no es asignable.\n", $1.lexema);
            return PARAR_COMPILADOR;
        } else if (atributos_actuales.tipo == VECTOR) {
            printf("ERROR: El identificador %s corresponde a un vector, por lo que no es asignable.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        /* GENERACIÓN DE CÓDIGO ASIGNACIÓN */
    } |
    elemento_vector TOK_ASIGNACION exp
    { fprintf(yyout, ";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n"); };

elemento_vector:
    TOK_IDENTIFICADOR TOK_CORCHETEIZQUIERDO exp TOK_CORCHETEDERECHO {
        if ((local && !TablaSimbolos_existe_local(tabla_simbolos, $1.lexema)) || (!local && !TablaSimbolos_existe_global(tabla_simbolos, $1.lexema))) {
            printf("ERROR: El identificador %s no ha sido declarado.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        atributos_actuales = (local ? TablaSimbolos_uso_local(tabla_simbolos, $1.lexema) : TablaSimbolos_uso_global(tabla_simbolos, $1.lexema));
        if (atributos_actuales.tipo == FUNCION) {
            printf("ERROR: El identificador %s corresponde a una función, por lo que no es indexable.\n", $1.lexema);
            return PARAR_COMPILADOR;
        } else if (atributos_actuales.tipo == ESCALAR) {
            printf("ERROR: El identificador %s corresponde a un escalar, por lo que no es indexable.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        /* GENERACIÓN DE CÓDIGO APILAR ELEMENTO (?) */
    };

condicional:
    TOK_IF TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA 
    { fprintf(yyout, ";RMAX_LONGITUD_ID:\t<condicional> ::= if ( <exp> ) { <sentencias> }\n"); } |
    TOK_IF TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA TOK_ELSE TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA
    { fprintf(yyout, ";RMAX_LONGITUD_ID+1:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n"); };

bucle:
    TOK_WHILE TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA
    { fprintf(yyout, ";R52:\t<bucle> ::= while ( <exp> ) { <sentencias> }\n"); };

lectura:
    TOK_SCANF TOK_IDENTIFICADOR {
        if ((local && !TablaSimbolos_existe_local(tabla_simbolos, $1.lexema)) || (!local && !TablaSimbolos_existe_global(tabla_simbolos, $1.lexema))) {
            printf("ERROR: El identificador %s no ha sido declarado.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        atributos_actuales = (local ? TablaSimbolos_uso_local(tabla_simbolos, $1.lexema) : TablaSimbolos_uso_global(tabla_simbolos, $1.lexema));
        if (atributos_actuales.tipo == FUNCION) {
            printf("ERROR: El identificador %s corresponde a una función, pero scanf recibe como argumento un escalar.\n", $1.lexema);
            return PARAR_COMPILADOR;
        } else if (atributos_actuales.tipo == VECTOR) {
            printf("ERROR: El identificador %s corresponde a un vector, pero scanf recibe como argumento un escalar.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        /* GENERACIÓN DE CÓDIGO LECTURA */
    };

escritura:
    TOK_PRINTF exp
    { fprintf(yyout, ";R56:\t<escritura> ::= printf <exp>\n"); };

retorno_funcion:
    TOK_RETURN exp
    { fprintf(yyout, ";R61:\t<retorno_funcion> ::= return <exp>\n"); };

exp:
    exp TOK_MAS exp {
        if ($1.tipo == BOOLEAN) {
            printf("ERROR: la expresión %s es un booleano, pero se usa en una suma.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        if ($3.tipo == BOOLEAN) {
            printf("ERROR: la expresión %s es un booleano, pero se usa en una suma.\n", $3.lexema);
            return PARAR_COMPILADOR;
        }
        
        $$.tipo = ENTERO;
        $$.es_direccion = 0;
    } |
    exp TOK_MENOS exp {
        if ($1.tipo == BOOLEAN) {
            printf("ERROR: la expresión %s es un booleano, pero se usa en una resta.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        if ($3.tipo == BOOLEAN) {
            printf("ERROR: la expresión %s es un booleano, pero se usa en una resta.\n", $3.lexema);
            return PARAR_COMPILADOR;
        }
        
        $$.tipo = ENTERO;
        $$.es_direccion = 0;
    } |
    exp TOK_DIVISION exp {
        if ($1.tipo == BOOLEAN) {
            printf("ERROR: la expresión %s es un booleano, pero se usa en una división.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        if ($3.tipo == BOOLEAN) {
            printf("ERROR: la expresión %s es un booleano, pero se usa en una división.\n", $3.lexema);
            return PARAR_COMPILADOR;
        }
        
        $$.tipo = ENTERO;
        $$.es_direccion = 0;
    } |
    exp TOK_ASTERISCO exp {
        if ($1.tipo == BOOLEAN) {
            printf("ERROR: la expresión %s es un booleano, pero se usa en una multiplicación.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        if ($3.tipo == BOOLEAN) {
            printf("ERROR: la expresión %s es un booleano, pero se usa en una multiplicación.\n", $3.lexema);
            return PARAR_COMPILADOR;
        }
        
        $$.tipo = ENTERO;
        $$.es_direccion = 0;
    } |
    TOK_MENOS exp {
        if ($2.tipo == BOOLEAN) {
            printf("ERROR: la expresión %s es un booleano, pero se usa en un cambio de signo.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        
        $$.tipo = ENTERO;
        $$.es_direccion = 0;
    } |
    exp TOK_AND exp {
        if ($1.tipo == ENTERO) {
            printf("ERROR: la expresión %s es un entero, pero se usa en un Y lógico.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        if ($3.tipo == ENTERO) {
            printf("ERROR: la expresión %s es un entero, pero se usa en un Y lógico.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }

        $$.tipo = BOOLEAN;
        $$.es_direccion = 0;
    } |
    exp TOK_OR exp {
        if ($1.tipo == ENTERO) {
            printf("ERROR: la expresión %s es un entero, pero se usa en un O lógico.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        if ($3.tipo == ENTERO) {
            printf("ERROR: la expresión %s es un entero, pero se usa en un O lógico.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }

        $$.tipo = BOOLEAN;
        $$.es_direccion = 0;
    } |
    TOK_NOT exp {
        if ($2.tipo == ENTERO) {
            printf("ERROR: la expresión %s es un entero, pero se usa en una negación lógica.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }

        $$.tipo = BOOLEAN;
        $$.es_direccion = 0;
    } |
    TOK_IDENTIFICADOR {
        if ((local && !TablaSimbolos_existe_local(tabla_simbolos, $1.lexema)) || (!local && !TablaSimbolos_existe_global(tabla_simbolos, $1.lexema))) {
            printf("ERROR: El identificador %s no ha sido declarado.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        atributos_actuales = (local ? TablaSimbolos_uso_local(tabla_simbolos, $1.lexema) : TablaSimbolos_uso_global(tabla_simbolos, $1.lexema));
        if (atributos_actuales.tipo == FUNCION) {
            printf("ERROR: El identificador %s corresponde a una función, por lo que no se puede acceder a su valor.\n", $1.lexema);
            return PARAR_COMPILADOR;
        } else if (atributos_actuales.tipo == VECTOR) {
            printf("ERROR: El identificador %s corresponde a un vector, por lo que no se puede acceder a su valor.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }

        $$.tipo = atributos_actuales.tipo;
        $$.es_direccion = TRUE;
        /* GENERACIÓN DE CÓDIGO APILAR (?) */
    } |
    constante { 
        $$.tipo = $1.tipo;
        $$.es_direccion = $1.es_direccion; 
    } |
    TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO {
        $$.tipo = $2.tipo;
        $$.es_direccion = $2.es_direccion; 
    } |
    TOK_PARENTESISIZQUIERDO comparacion TOK_PARENTESISDERECHO {
        $$.tipo = $2.tipo;
        $$.es_direccion = $2.es_direccion; 
    } |
    elemento_vector { 
        $$.tipo = $1.tipo;
        $$.es_direccion = $1.es_direccion; 
    } |
    idf_llamada_funcion TOK_PARENTESISIZQUIERDO lista_expresiones TOK_PARENTESISDERECHO {
        if ((local && !TablaSimbolos_existe_local(tabla_simbolos, $1.lexema)) || (!local && !TablaSimbolos_existe_global(tabla_simbolos, $1.lexema))) {
            printf("ERROR: El identificador %s no ha sido declarado.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        atributos_actuales = (local ? TablaSimbolos_uso_local(tabla_simbolos, $1.lexema) : TablaSimbolos_uso_global(tabla_simbolos, $1.lexema));
        if (atributos_actuales.tipo == ESCALAR) {
            printf("ERROR: El identificador %s corresponde a un escalar, por lo que no es invocable.\n", $1.lexema);
            return PARAR_COMPILADOR;
        } else if (atributos_actuales.tipo == VECTOR) {
            printf("ERROR: El identificador %s corresponde a un vector, por lo que no es invocable.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        /* GENERACIÓN DE CÓDIGO LLAMADA A FUNCIÓN (?) */
        en_explist = FALSE;
    };

idf_llamada_funcion:
    TOK_IDENTIFICADOR {
        if ((local && !TablaSimbolos_existe_local(tabla_simbolos, $1.lexema)) || (!local && !TablaSimbolos_existe_global(tabla_simbolos, $1.lexema))) {
            printf("ERROR: El identificador %s no ha sido declarado.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        atributos_actuales = (local ? TablaSimbolos_uso_local(tabla_simbolos, $1.lexema) : TablaSimbolos_uso_global(tabla_simbolos, $1.lexema));
        if (atributos_actuales.tipo == ESCALAR) {
            printf("ERROR: El identificador %s corresponde a un escalar, por lo que no es invocable.\n", $1.lexema);
            return PARAR_COMPILADOR;
        } else if (atributos_actuales.tipo == VECTOR) {
            printf("ERROR: El identificador %s corresponde a un vector, por lo que no es invocable.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }

        if (en_explist == TRUE) {
            printf("ERROR: Se están anidando las llamadas a función.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }

        num_parametro_llamada_actual = 0;
        en_explist = TRUE;
        $$.lexema = $1.lexema;
    };

lista_expresiones:
    exp resto_lista_expresiones
    { printf(yyout, ";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n"); } |
    /* lambda */
    { fprintf(yyout, ";R90:\t<lista_expresiones> ::=\n"); };

resto_lista_expresiones:
    TOK_COMA exp resto_lista_expresiones
    { fprintf(yyout, ";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>\n"); } |
    /* lambda */
    { fprintf(yyout, ";R92:\t<resto_lista_expresiones> ::=\n"); };

comparacion:
    exp TOK_IGUAL exp { 
        if ($1.tipo == BOOLEAN) {
            printf("ERROR: la expresión %s es un booleano, pero se usa en una comparación.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        if ($3.tipo == BOOLEAN) {
            printf("ERROR: la expresión %s es un booleano, pero se usa en una comparación.\n", $3.lexema);
            return PARAR_COMPILADOR;
        }
        
        $$.tipo = BOOLEAN;
        $$.es_direccion = 0;
    } |
    exp TOK_DISTINTO exp { 
        if ($1.tipo == BOOLEAN) {
            printf("ERROR: la expresión %s es un booleano, pero se usa en una comparación.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        if ($3.tipo == BOOLEAN) {
            printf("ERROR: la expresión %s es un booleano, pero se usa en una comparación.\n", $3.lexema);
            return PARAR_COMPILADOR;
        }
        
        $$.tipo = BOOLEAN;
        $$.es_direccion = 0;
    } |
    exp TOK_MENORIGUAL exp { 
        if ($1.tipo == BOOLEAN) {
            printf("ERROR: la expresión %s es un booleano, pero se usa en una comparación.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        if ($3.tipo == BOOLEAN) {
            printf("ERROR: la expresión %s es un booleano, pero se usa en una comparación.\n", $3.lexema);
            return PARAR_COMPILADOR;
        }
        
        $$.tipo = BOOLEAN;
        $$.es_direccion = 0;
    } |
    exp TOK_MAYORIGUAL exp { 
        if ($1.tipo == BOOLEAN) {
            printf("ERROR: la expresión %s es un booleano, pero se usa en una comparación.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        if ($3.tipo == BOOLEAN) {
            printf("ERROR: la expresión %s es un booleano, pero se usa en una comparación.\n", $3.lexema);
            return PARAR_COMPILADOR;
        }
        
        $$.tipo = BOOLEAN;
        $$.es_direccion = 0;
    } |
    exp TOK_MENOR exp { 
        if ($1.tipo == BOOLEAN) {
            printf("ERROR: la expresión %s es un booleano, pero se usa en una comparación.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        if ($3.tipo == BOOLEAN) {
            printf("ERROR: la expresión %s es un booleano, pero se usa en una comparación.\n", $3.lexema);
            return PARAR_COMPILADOR;
        }
        
        $$.tipo = BOOLEAN;
        $$.es_direccion = 0;
    } |
    exp TOK_MAYOR exp { 
        if ($1.tipo == BOOLEAN) {
            printf("ERROR: la expresión %s es un booleano, pero se usa en una comparación.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        if ($3.tipo == BOOLEAN) {
            printf("ERROR: la expresión %s es un booleano, pero se usa en una comparación.\n", $3.lexema);
            return PARAR_COMPILADOR;
        }
        
        $$.tipo = BOOLEAN;
        $$.es_direccion = 0;
    }

constante:
    constante_logica { 
        $$.tipo = $1.tipo;
        $$.es_direccion = $1.es_direccion;
    } |
    constante_entera { 
        $$.tipo = $1.tipo;
        $$.es_direccion = $1.es_direccion;
    };

constante_logica:
    TOK_TRUE { 
        $$.tipo = BOOLEAN;
        $$.es_direccion = FALSE;
    } |
    TOK_FALSE { 
        $$.tipo = BOOLEAN;
        $$.es_direccion = FALSE;
    }

constante_entera:
    TOK_CONSTANTE_ENTERA {
        $$.tipo = ENTERO;
        $$.es_direccion = FALSE;
    };

identificador:
    TOK_IDENTIFICADOR {
        strcpy(atributos_actuales.lexema, $1.lexema);
        atributos_actuales.clase = clase_actual;
        atributos_actuales.tipo = tipo_actual;

        if (local) {
            if (TablaSimbolos_existe_local(tabla_simbolos, $1.lexema)) {
                printf("ERROR: Identificador %s duplicado.\n", $1.lexema);
                return PARAR_COMPILADOR;
            } else {
                TablaSimbolos_declarar_local(tabla_simbolos, $1.lexema, &atributos_actuales);
            }
        } else {
            if (TablaSimbolos_existe_global(tabla_simbolos, $1.lexema)) {
                printf("ERROR: Identificador %s duplicado.\n", $1.lexema);
                return PARAR_COMPILADOR;
            } else {
                TablaSimbolos_declarar_global(tabla_simbolos, $1.lexema, &atributos_actuales);
            }
        }
    };

idpf:
    TOK_IDENTIFICADOR {
        strcpy(atributos_actuales.lexema, $1.lexema);
        if (TablaSimbolos_existe_local(tabla_simbolos, $1.lexema)) {
            printf("ERROR: Identificador %s duplicado en la declaración de la función.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        atributos_actuales.posicion = pos_parametro_actual;
        TablaSimbolos_declarar_local(tabla_simbolos, $1.lexema, &atributos_actuales);
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