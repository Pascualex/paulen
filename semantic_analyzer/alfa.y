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
    
    int tipo_retorno_funcion_actual;
    
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
%token <atributos> TOK_IDENTIFICADOR

/* Constantes */ 
%token <atributos> TOK_CONSTANTE_ENTERA
%token TOK_TRUE
%token TOK_FALSE

/* Errores */
%token TOK_ERROR

%type <atributos> exp
%type <atributos> constante
%type <atributos> constante_entera
%type <atributos> constante_logica
%type <atributos> fn_name
%type <atributos> fn_declaration
%type <atributos> tipo
%type <atributos> comparacion
%type <atributos> idf_llamada_funcion
%type <atributos> elemento_vector

/* Precedencia de operadores */
%left TOK_OR TOK_AND TOK_NOT
%left TOK_MENOR TOK_MAYOR TOK_IGUAL TOK_DISTINTO TOK_MENORIGUAL TOK_MAYORIGUAL
%left TOK_MAS TOK_MENOS
%left TOK_ASTERISCO TOK_DIVISION

%start programa

%%

programa:
    TOK_MAIN TOK_LLAVEIZQUIERDA declaraciones funciones sentencias TOK_LLAVEDERECHA;

declaraciones:
    declaracion |
    declaracion declaraciones;

declaracion:
    clase identificadores TOK_PUNTOYCOMA;

clase:
    clase_escalar
    { clase_actual = ESCALAR; } |
    clase_vector
    { clase_actual = VECTOR; };

clase_escalar:
    tipo;

tipo:
    TOK_INT { 
        tipo_actual = INT;
        $$.tipo = INT;
    } |
    TOK_BOOLEAN {
        tipo_actual = BOOLEAN; 
        $$.tipo = BOOLEAN;
    };

clase_vector:
    TOK_ARRAY tipo TOK_CORCHETEIZQUIERDO TOK_CONSTANTE_ENTERA TOK_CORCHETEDERECHO { 
        tam_vector_actual = $4.valor_entero;
        if (tam_vector_actual < 1 || tam_vector_actual > MAX_TAM_VECTOR) {
            fprintf(stderr, "ERROR: Tamaño de vector inválido.\n");
            return PARAR_COMPILADOR;
        }
    };

identificadores:
    identificador |
    identificador TOK_COMA identificadores;

funciones:
    funcion funciones |
    /* lambda */;

fn_name:
    TOK_FUNCTION tipo TOK_IDENTIFICADOR {
        if (TablaSimbolos_existe_global(tabla_simbolos, $3.lexema)) {
            fprintf(stderr, "ERROR: nombre de funcion %s ya utilizado.\n", $3.lexema);
            return PARAR_COMPILADOR;
        }

        local = true;
        num_parametros_actual = 0;
        pos_parametro_actual = 0;
        num_variables_locales_actual = 0;
        pos_variable_local_actual = 1;
        tipo_retorno_funcion_actual = $2.tipo;

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
    parametro_funcion resto_parametros_funcion |
    /* lambda */;

resto_parametros_funcion:
    TOK_PUNTOYCOMA parametro_funcion resto_parametros_funcion |
    /* lambda */;

parametro_funcion:
    tipo idpf;

declaraciones_funcion:
    declaraciones |
    /* lambda */;

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
    TOK_IDENTIFICADOR TOK_ASIGNACION exp { 
        if ((local && !TablaSimbolos_existe_local(tabla_simbolos, $1.lexema)) || (!local && !TablaSimbolos_existe_global(tabla_simbolos, $1.lexema))) {
            fprintf(stderr, "ERROR: El identificador %s no ha sido declarado.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        atributos_actuales = *(local ? TablaSimbolos_uso_local(tabla_simbolos, $1.lexema) : TablaSimbolos_uso_global(tabla_simbolos, $1.lexema));
        if (atributos_actuales.tipo == FUNCION) {
            fprintf(stderr, "ERROR: El identificador %s corresponde a una función, por lo que no es asignable.\n", $1.lexema);
            return PARAR_COMPILADOR;
        } else if (atributos_actuales.tipo == VECTOR) {
            fprintf(stderr, "ERROR: El identificador %s corresponde a un vector, por lo que no es asignable.\n", $1.lexema);
            return PARAR_COMPILADOR;
        } else if (atributos_actuales.clase == BOOLEAN && $3.clase == INT) {
            fprintf(stderr, "ERROR: Se intenta asignar a %s, de tipo booleano, una expresión de tipo entero.\n", $1.lexema);
            return PARAR_COMPILADOR;            
        } else if (atributos_actuales.clase == INT && $3.clase == BOOLEAN) {
            fprintf(stderr, "ERROR: Se intenta asignar a %s, de tipo entero, una expresión de tipo booleano.\n", $1.lexema);
            return PARAR_COMPILADOR;            
        }

        /* GENERACIÓN DE CÓDIGO ASIGNACIÓN */
    } |
    elemento_vector TOK_ASIGNACION exp { 
        if ($1.clase == BOOLEAN && $3.clase == INT) {
            fprintf(stderr, "ERROR: Se intenta asignar a %s, de tipo booleano, una expresión de tipo entero.\n", $1.lexema);
            return PARAR_COMPILADOR;            
        } else if ($1.clase == INT && $3.clase == BOOLEAN) {
            fprintf(stderr, "ERROR: Se intenta asignar a %s, de tipo entero, una expresión de tipo booleano.\n", $1.lexema);
            return PARAR_COMPILADOR;            
        }

        /* GENERACIÓN DE CÓDIGO ASIGNACIÓN */
    };

elemento_vector:
    TOK_IDENTIFICADOR TOK_CORCHETEIZQUIERDO exp TOK_CORCHETEDERECHO {
        if ((local && !TablaSimbolos_existe_local(tabla_simbolos, $1.lexema)) || (!local && !TablaSimbolos_existe_global(tabla_simbolos, $1.lexema))) {
            fprintf(stderr, "ERROR: El identificador %s no ha sido declarado.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        atributos_actuales = *(local ? TablaSimbolos_uso_local(tabla_simbolos, $1.lexema) : TablaSimbolos_uso_global(tabla_simbolos, $1.lexema));
        if (atributos_actuales.tipo == FUNCION) {
            fprintf(stderr, "ERROR: El identificador %s corresponde a una función, por lo que no es indexable.\n", $1.lexema);
            return PARAR_COMPILADOR;
        } else if (atributos_actuales.tipo == ESCALAR) {
            fprintf(stderr, "ERROR: El identificador %s corresponde a un escalar, por lo que no es indexable.\n", $1.lexema);
            return PARAR_COMPILADOR;
        } else if ($3.clase == BOOLEAN) {
            fprintf(stderr, "ERROR: Se está indexando el vector %s con una expresión booleana, debería ser una expresión de tipo entero.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }

        strcpy($$.lexema, $1.lexema);
        $$.tipo = atributos_actuales.tipo;
        $$.es_direccion = TRUE;
        /* GENERACIÓN DE CÓDIGO APILAR ELEMENTO (?) */
    };

if_exp:
    TOK_IF TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO {
        if ($3.tipo == INT) {
            fprintf(stderr, "ERROR: Se está usando una expresión entera como condicional en un IF, debería ser una expresión booleana.\n");
            return PARAR_COMPILADOR;
        }
    };

condicional:
    if_exp TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA { } |
    if_exp TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA TOK_ELSE TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA { };

while_exp:
    TOK_WHILE TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO {
        if ($3.tipo == INT) {
            fprintf(stderr, "ERROR: Se está usando una expresión entera como condicional en un WHILE, debería ser una expresión booleana.\n");
            return PARAR_COMPILADOR;
        }
    };

bucle:
    while_exp TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA { };

lectura:
    TOK_SCANF TOK_IDENTIFICADOR {
        if ((local && !TablaSimbolos_existe_local(tabla_simbolos, $2.lexema)) || (!local && !TablaSimbolos_existe_global(tabla_simbolos, $2.lexema))) {
            fprintf(stderr, "ERROR: El identificador %s no ha sido declarado.\n", $2.lexema);
            return PARAR_COMPILADOR;
        }
        atributos_actuales = *(local ? TablaSimbolos_uso_local(tabla_simbolos, $2.lexema) : TablaSimbolos_uso_global(tabla_simbolos, $2.lexema));
        if (atributos_actuales.tipo == FUNCION) {
            fprintf(stderr, "ERROR: El identificador %s corresponde a una función, pero scanf recibe como argumento un escalar.\n", $2.lexema);
            return PARAR_COMPILADOR;
        } else if (atributos_actuales.tipo == VECTOR) {
            fprintf(stderr, "ERROR: El identificador %s corresponde a un vector, pero scanf recibe como argumento un escalar.\n", $2.lexema);
            return PARAR_COMPILADOR;
        }
        /* GENERACIÓN DE CÓDIGO LECTURA */
    };

escritura:
    TOK_PRINTF exp;

retorno_funcion:
    TOK_RETURN exp { 
        if (!local) {
            fprintf(stderr, "ERROR: Se ha declarado un RETURN fuera de una función, debería estar declarado dentro de una función.\n");
            return PARAR_COMPILADOR;
        } else if (tipo_retorno_funcion_actual == INT && $2.tipo == BOOLEAN) {
            fprintf(stderr, "ERROR: El tipo de retorno de una función es INT, pero se está devolviendo un parámetro de tipo BOOLEAN.\n");
            return PARAR_COMPILADOR;
        } else if (tipo_retorno_funcion_actual == BOOLEAN && $2.tipo == INT) {
            fprintf(stderr, "ERROR: El tipo de retorno de una función es BOOLEAN, pero se está devolviendo un parámetro de tipo INT.\n");
            return PARAR_COMPILADOR;
        }

        /*
            FALTA COMPROBAR:
                En el cuerpo de una función obligatoriamente tiene que aparecer al menos una sentencia de retorno. (?)
        */
    };

exp:
    exp TOK_MAS exp {
        if ($1.clase == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una suma.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        if ($3.clase == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una suma.\n", $3.lexema);
            return PARAR_COMPILADOR;
        }
        
        $$.clase = INT;
        $$.es_direccion = 0;
    } |
    exp TOK_MENOS exp {
        if ($1.clase == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una resta.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        if ($3.clase == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una resta.\n", $3.lexema);
            return PARAR_COMPILADOR;
        }
        
        $$.clase = INT;
        $$.es_direccion = 0;
    } |
    exp TOK_DIVISION exp {
        if ($1.clase == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una división.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        if ($3.clase == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una división.\n", $3.lexema);
            return PARAR_COMPILADOR;
        }
        
        $$.clase = INT;
        $$.es_direccion = 0;
    } |
    exp TOK_ASTERISCO exp {
        if ($1.clase == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una multiplicación.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        if ($3.clase == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una multiplicación.\n", $3.lexema);
            return PARAR_COMPILADOR;
        }
        
        $$.clase = INT;
        $$.es_direccion = 0;
    } |
    TOK_MENOS exp {
        if ($2.clase == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en un cambio de signo.\n", $2.lexema);
            return PARAR_COMPILADOR;
        }
        
        $$.clase = INT;
        $$.es_direccion = 0;
    } |
    exp TOK_AND exp {
        if ($1.clase == INT) {
            fprintf(stderr, "ERROR: la expresión %s es un entero, pero se usa en un Y lógico.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        if ($3.clase == INT) {
            fprintf(stderr, "ERROR: la expresión %s es un entero, pero se usa en un Y lógico.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }

        $$.clase = BOOLEAN;
        $$.es_direccion = 0;
    } |
    exp TOK_OR exp {
        if ($1.clase == INT) {
            fprintf(stderr, "ERROR: la expresión %s es un entero, pero se usa en un O lógico.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        if ($3.clase == INT) {
            fprintf(stderr, "ERROR: la expresión %s es un entero, pero se usa en un O lógico.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }

        $$.clase = BOOLEAN;
        $$.es_direccion = 0;
    } |
    TOK_NOT exp {
        if ($2.clase == INT) {
            fprintf(stderr, "ERROR: la expresión %s es un entero, pero se usa en una negación lógica.\n", $2.lexema);
            return PARAR_COMPILADOR;
        }

        $$.clase = BOOLEAN;
        $$.es_direccion = 0;
    } |
    TOK_IDENTIFICADOR {
        if ((local && !TablaSimbolos_existe_local(tabla_simbolos, $1.lexema)) || (!local && !TablaSimbolos_existe_global(tabla_simbolos, $1.lexema))) {
            fprintf(stderr, "ERROR: El identificador %s no ha sido declarado.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        atributos_actuales = *(local ? TablaSimbolos_uso_local(tabla_simbolos, $1.lexema) : TablaSimbolos_uso_global(tabla_simbolos, $1.lexema));
        if (atributos_actuales.tipo == FUNCION) {
            fprintf(stderr, "ERROR: El identificador %s corresponde a una función, por lo que no se puede acceder a su valor.\n", $1.lexema);
            return PARAR_COMPILADOR;
        } else if (atributos_actuales.tipo == VECTOR) {
            fprintf(stderr, "ERROR: El identificador %s corresponde a un vector, por lo que no se puede acceder a su valor.\n", $1.lexema);
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
            fprintf(stderr, "ERROR: El identificador %s no ha sido declarado.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        atributos_actuales = *(local ? TablaSimbolos_uso_local(tabla_simbolos, $1.lexema) : TablaSimbolos_uso_global(tabla_simbolos, $1.lexema));
        if (atributos_actuales.tipo == ESCALAR) {
            fprintf(stderr, "ERROR: El identificador %s corresponde a un escalar, por lo que no es invocable.\n", $1.lexema);
            return PARAR_COMPILADOR;
        } else if (atributos_actuales.tipo == VECTOR) {
            fprintf(stderr, "ERROR: El identificador %s corresponde a un vector, por lo que no es invocable.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        /* GENERACIÓN DE CÓDIGO LLAMADA A FUNCIÓN (?) */
        en_explist = FALSE;
        $$.es_direccion = FALSE;
        $$.tipo = atributos_actuales.tipo;
    };

idf_llamada_funcion:
    TOK_IDENTIFICADOR {
        if ((local && !TablaSimbolos_existe_local(tabla_simbolos, $1.lexema)) || (!local && !TablaSimbolos_existe_global(tabla_simbolos, $1.lexema))) {
            fprintf(stderr, "ERROR: El identificador %s no ha sido declarado.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        atributos_actuales = *(local ? TablaSimbolos_uso_local(tabla_simbolos, $1.lexema) : TablaSimbolos_uso_global(tabla_simbolos, $1.lexema));
        if (atributos_actuales.tipo == ESCALAR) {
            fprintf(stderr, "ERROR: El identificador %s corresponde a un escalar, por lo que no es invocable.\n", $1.lexema);
            return PARAR_COMPILADOR;
        } else if (atributos_actuales.tipo == VECTOR) {
            fprintf(stderr, "ERROR: El identificador %s corresponde a un vector, por lo que no es invocable.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }

        if (en_explist == TRUE) {
            fprintf(stderr, "ERROR: Se están anidando las llamadas a función.\n");
            return PARAR_COMPILADOR;
        }

        num_parametros_actual = 0;
        en_explist = TRUE;
        strcpy($$.lexema, $1.lexema);
    };

lista_expresiones:
    exp resto_lista_expresiones {
        num_parametros_actual++;
    } |
    /* lambda */;

resto_lista_expresiones:
    TOK_COMA exp resto_lista_expresiones {
        num_parametros_actual++;
    } |
    /* lambda */;

comparacion:
    exp TOK_IGUAL exp { 
        if ($1.tipo == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una comparación.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        if ($3.tipo == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una comparación.\n", $3.lexema);
            return PARAR_COMPILADOR;
        }
        
        $$.tipo = BOOLEAN;
        $$.es_direccion = 0;
    } |
    exp TOK_DISTINTO exp { 
        if ($1.tipo == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una comparación.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        if ($3.tipo == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una comparación.\n", $3.lexema);
            return PARAR_COMPILADOR;
        }
        
        $$.tipo = BOOLEAN;
        $$.es_direccion = 0;
    } |
    exp TOK_MENORIGUAL exp { 
        if ($1.tipo == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una comparación.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        if ($3.tipo == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una comparación.\n", $3.lexema);
            return PARAR_COMPILADOR;
        }
        
        $$.tipo = BOOLEAN;
        $$.es_direccion = 0;
    } |
    exp TOK_MAYORIGUAL exp { 
        if ($1.tipo == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una comparación.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        if ($3.tipo == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una comparación.\n", $3.lexema);
            return PARAR_COMPILADOR;
        }
        
        $$.tipo = BOOLEAN;
        $$.es_direccion = 0;
    } |
    exp TOK_MENOR exp { 
        if ($1.tipo == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una comparación.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        if ($3.tipo == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una comparación.\n", $3.lexema);
            return PARAR_COMPILADOR;
        }
        
        $$.tipo = BOOLEAN;
        $$.es_direccion = 0;
    } |
    exp TOK_MAYOR exp { 
        if ($1.tipo == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una comparación.\n", $1.lexema);
            return PARAR_COMPILADOR;
        }
        if ($3.tipo == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una comparación.\n", $3.lexema);
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
        $$.tipo = INT;
        $$.es_direccion = FALSE;
    };

identificador:
    TOK_IDENTIFICADOR {
        strcpy(atributos_actuales.lexema, $1.lexema);
        atributos_actuales.clase = clase_actual;
        atributos_actuales.tipo = tipo_actual;

        if (local) {
            if (TablaSimbolos_existe_local(tabla_simbolos, $1.lexema)) {
                fprintf(stderr, "ERROR: Identificador %s duplicado.\n", $1.lexema);
                return PARAR_COMPILADOR;
            } else {
                TablaSimbolos_declarar_local(tabla_simbolos, $1.lexema, &atributos_actuales);
            }
        } else {
            if (TablaSimbolos_existe_global(tabla_simbolos, $1.lexema)) {
                fprintf(stderr, "ERROR: Identificador %s duplicado.\n", $1.lexema);
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
            fprintf(stderr, "ERROR: Identificador %s duplicado en la declaración de la función.\n", $1.lexema);
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
        fprintf(stderr, "Número incorrecto de argumentos.\n");
        return -1;
    }

    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
        fprintf(stderr, "No se ha podido abrir el fichero %s.\n", argv[1]);
        return -1;
    }

    yyout = fopen(argv[2], "w");
    if (yyout == NULL) {
        fprintf(stderr, "No se ha podido abrir el fichero %s.\n", argv[2]);
        fclose(yyin);
        return -1;
    }

    tabla_simbolos = TablaSimbolos_create();
    if (tabla_simbolos == NULL) {
        fprintf(stderr, "No se ha podido crear la tabla de símbolos.\n");
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