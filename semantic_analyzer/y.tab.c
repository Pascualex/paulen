/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "alfa.y" /* yacc.c:339  */

    #include "alfa.h"
    #include "generacion.h"
    #include "TablaSimbolos.h"
    #include "y.tab.h"
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

    int etiqueta = 1;
    
    int yyerror(char *s);

#line 106 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 41 "alfa.y" /* yacc.c:355  */

    #include "alfa.h"

#line 140 "y.tab.c" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOK_MAIN = 258,
    TOK_INT = 259,
    TOK_BOOLEAN = 260,
    TOK_ARRAY = 261,
    TOK_FUNCTION = 262,
    TOK_IF = 263,
    TOK_ELSE = 264,
    TOK_WHILE = 265,
    TOK_SCANF = 266,
    TOK_PRINTF = 267,
    TOK_RETURN = 268,
    TOK_PUNTOYCOMA = 269,
    TOK_COMA = 270,
    TOK_PARENTESISIZQUIERDO = 271,
    TOK_PARENTESISDERECHO = 272,
    TOK_CORCHETEIZQUIERDO = 273,
    TOK_CORCHETEDERECHO = 274,
    TOK_LLAVEIZQUIERDA = 275,
    TOK_LLAVEDERECHA = 276,
    TOK_ASIGNACION = 277,
    TOK_MAS = 278,
    TOK_MENOS = 279,
    TOK_DIVISION = 280,
    TOK_ASTERISCO = 281,
    TOK_AND = 282,
    TOK_OR = 283,
    TOK_NOT = 284,
    TOK_IGUAL = 285,
    TOK_DISTINTO = 286,
    TOK_MENORIGUAL = 287,
    TOK_MAYORIGUAL = 288,
    TOK_MENOR = 289,
    TOK_MAYOR = 290,
    TOK_IDENTIFICADOR = 291,
    TOK_CONSTANTE_ENTERA = 292,
    TOK_TRUE = 293,
    TOK_FALSE = 294,
    TOK_ERROR = 295
  };
#endif
/* Tokens.  */
#define TOK_MAIN 258
#define TOK_INT 259
#define TOK_BOOLEAN 260
#define TOK_ARRAY 261
#define TOK_FUNCTION 262
#define TOK_IF 263
#define TOK_ELSE 264
#define TOK_WHILE 265
#define TOK_SCANF 266
#define TOK_PRINTF 267
#define TOK_RETURN 268
#define TOK_PUNTOYCOMA 269
#define TOK_COMA 270
#define TOK_PARENTESISIZQUIERDO 271
#define TOK_PARENTESISDERECHO 272
#define TOK_CORCHETEIZQUIERDO 273
#define TOK_CORCHETEDERECHO 274
#define TOK_LLAVEIZQUIERDA 275
#define TOK_LLAVEDERECHA 276
#define TOK_ASIGNACION 277
#define TOK_MAS 278
#define TOK_MENOS 279
#define TOK_DIVISION 280
#define TOK_ASTERISCO 281
#define TOK_AND 282
#define TOK_OR 283
#define TOK_NOT 284
#define TOK_IGUAL 285
#define TOK_DISTINTO 286
#define TOK_MENORIGUAL 287
#define TOK_MAYORIGUAL 288
#define TOK_MENOR 289
#define TOK_MAYOR 290
#define TOK_IDENTIFICADOR 291
#define TOK_CONSTANTE_ENTERA 292
#define TOK_TRUE 293
#define TOK_FALSE 294
#define TOK_ERROR 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 45 "alfa.y" /* yacc.c:355  */

    tipo_atributos atributos;

#line 236 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 253 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   156

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  155

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   124,   124,   129,   136,   141,   142,   145,   148,   150,
     154,   157,   161,   167,   176,   177,   180,   180,   184,   208,
     215,   222,   222,   226,   226,   230,   233,   233,   237,   238,
     241,   242,   245,   246,   247,   248,   251,   252,   255,   277,
     290,   315,   318,   323,   335,   341,   353,   358,   369,   376,
     394,   399,   420,   435,   450,   465,   480,   491,   506,   521,
     533,   553,   557,   561,   565,   570,   596,   621,   623,   627,
     629,   633,   649,   665,   681,   697,   713,   731,   735,   741,
     746,   753,   761,   784
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_MAIN", "TOK_INT", "TOK_BOOLEAN",
  "TOK_ARRAY", "TOK_FUNCTION", "TOK_IF", "TOK_ELSE", "TOK_WHILE",
  "TOK_SCANF", "TOK_PRINTF", "TOK_RETURN", "TOK_PUNTOYCOMA", "TOK_COMA",
  "TOK_PARENTESISIZQUIERDO", "TOK_PARENTESISDERECHO",
  "TOK_CORCHETEIZQUIERDO", "TOK_CORCHETEDERECHO", "TOK_LLAVEIZQUIERDA",
  "TOK_LLAVEDERECHA", "TOK_ASIGNACION", "TOK_MAS", "TOK_MENOS",
  "TOK_DIVISION", "TOK_ASTERISCO", "TOK_AND", "TOK_OR", "TOK_NOT",
  "TOK_IGUAL", "TOK_DISTINTO", "TOK_MENORIGUAL", "TOK_MAYORIGUAL",
  "TOK_MENOR", "TOK_MAYOR", "TOK_IDENTIFICADOR", "TOK_CONSTANTE_ENTERA",
  "TOK_TRUE", "TOK_FALSE", "TOK_ERROR", "$accept", "programa",
  "escritura_TS", "escritura_main", "declaraciones", "declaracion",
  "clase", "clase_escalar", "tipo", "clase_vector", "identificadores",
  "funciones", "fn_name", "fn_declaration", "funcion",
  "parametros_funcion", "resto_parametros_funcion", "parametro_funcion",
  "declaraciones_funcion", "sentencias", "sentencia", "sentencia_simple",
  "bloque", "asignacion", "elemento_vector", "condicional", "if_exp",
  "if_else_then_else_exp", "if_else_then_exp", "bucle", "while_exp",
  "while_tok", "lectura", "escritura", "retorno_funcion", "exp",
  "idf_llamada_funcion", "lista_expresiones", "resto_lista_expresiones",
  "comparacion", "constante", "constante_logica", "constante_entera",
  "identificador", "idpf", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

#define YYPACT_NINF -37

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-37)))

#define YYTABLE_NINF -67

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      16,     5,    46,    17,   -37,   -37,   -37,    27,   -37,    17,
      13,   -37,   -37,   -37,    32,    44,   -37,   -37,    40,    56,
      18,    27,   -37,    57,     2,    44,   -37,    13,    53,    38,
       2,    27,    59,   -37,    41,    24,    24,    -2,    78,     2,
      62,   -37,   -37,    76,   -37,    79,    86,    89,   -37,    90,
      95,   -37,   -37,   -37,   -37,   -37,   -37,   -37,    99,    92,
     112,    98,    24,   -37,    24,    24,    24,    23,   -37,   -37,
     -37,   -37,   -19,   114,   -37,   -37,   -37,   -19,    24,    24,
     -37,   -37,   -37,    24,     2,     2,     2,     2,    24,   -37,
     -37,   -37,   113,    27,   -37,   110,    91,   115,    19,    11,
      24,    24,    24,    24,    24,    24,    24,    77,   -19,   -19,
     119,   120,   121,   123,   122,    17,    98,   -37,   -37,    24,
      24,    24,    24,    24,    24,   -37,    19,    19,   -37,   -37,
      11,    11,    67,   126,   -37,   -37,   -37,   142,   -37,   -37,
     -37,   -37,   -37,   -19,   -19,   -19,   -19,   -19,   -19,    24,
     -37,   -37,   -37,    67,   -37
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,    11,    12,     0,     3,     5,
       0,     8,    10,     9,     0,    17,     6,    82,     0,    14,
       0,     0,     4,     0,     0,    17,     7,     0,     0,     0,
       0,    22,     0,    48,     0,     0,     0,     0,     0,    28,
       0,    31,    32,     0,    36,     0,     0,     0,    37,     0,
       0,    33,    34,    35,    16,    15,    13,    18,     0,     0,
       0,    24,     0,    49,     0,     0,     0,    60,    81,    79,
      80,    64,    50,     0,    61,    77,    78,    51,     0,     0,
      20,    29,    30,     0,     0,     0,     0,     0,     0,     2,
      83,    25,     0,     0,    21,     0,     0,     0,    56,    59,
       0,     0,     0,     0,     0,     0,    68,     0,    38,    39,
       0,     0,     0,     0,     0,    27,    24,    43,    62,     0,
       0,     0,     0,     0,     0,    63,    52,    53,    54,    55,
      57,    58,    70,     0,    40,    41,    42,     0,    46,    47,
      26,    19,    23,    71,    72,    73,    74,    75,    76,     0,
      67,    65,    44,    70,    69
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -37,   -37,   -37,   -37,    -8,   -37,   -37,   -37,    -4,   -37,
     125,   128,   -37,   -37,   -37,   -37,    39,    61,   -37,   -28,
     -37,   -37,   -37,   -37,    -6,   -37,   -37,   -37,   -37,   -37,
     -37,   -37,   -37,   -37,   -37,   -36,   -37,   -37,     3,   -37,
     -37,   -37,   -37,   -37,   -37
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    15,    30,     8,     9,    10,    11,    12,    13,
      18,    22,    23,    24,    25,    60,    94,    61,   141,    38,
      39,    40,    41,    42,    71,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    72,    73,   133,   150,    97,
      74,    75,    76,    19,    91
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      77,    16,    58,    14,   100,   101,   102,   103,   104,   105,
      32,    81,    33,    34,    35,    36,    78,    29,    43,     1,
      79,     5,     6,     7,    43,     3,    95,    59,    96,    98,
      99,     5,     6,    43,   100,   101,   102,   103,    37,   -66,
      64,    78,   107,   108,   102,   103,     4,   109,    65,    17,
      20,    21,   114,    66,    26,    28,   110,   111,   112,   113,
      67,    68,    69,    70,   126,   127,   128,   129,   130,   131,
     132,    27,    56,    31,    57,    62,    82,    63,    43,    43,
      43,    43,   149,   143,   144,   145,   146,   147,   148,    59,
     100,   101,   102,   103,   104,   105,   134,    80,    83,    84,
     100,   101,   102,   103,   104,   105,    85,   140,   118,    86,
      87,    88,    93,   153,   100,   101,   102,   103,   104,   105,
      89,   119,   120,   121,   122,   123,   124,   117,    90,    92,
     106,   115,   125,   100,   101,   102,   103,   104,   105,   139,
     135,   136,   137,   151,   138,   100,   101,   102,   103,   104,
     105,   152,    55,    54,   116,   142,   154
};

static const yytype_uint8 yycheck[] =
{
      36,     9,    30,     7,    23,    24,    25,    26,    27,    28,
       8,    39,    10,    11,    12,    13,    18,    21,    24,     3,
      22,     4,     5,     6,    30,    20,    62,    31,    64,    65,
      66,     4,     5,    39,    23,    24,    25,    26,    36,    16,
      16,    18,    78,    79,    25,    26,     0,    83,    24,    36,
      18,     7,    88,    29,    14,    37,    84,    85,    86,    87,
      36,    37,    38,    39,   100,   101,   102,   103,   104,   105,
     106,    15,    19,    16,    36,    16,    14,    36,    84,    85,
      86,    87,    15,   119,   120,   121,   122,   123,   124,    93,
      23,    24,    25,    26,    27,    28,    19,    19,    22,    20,
      23,    24,    25,    26,    27,    28,    20,   115,    17,    20,
      20,    16,    14,   149,    23,    24,    25,    26,    27,    28,
      21,    30,    31,    32,    33,    34,    35,    17,    36,    17,
      16,    18,    17,    23,    24,    25,    26,    27,    28,    17,
      21,    21,    21,    17,    21,    23,    24,    25,    26,    27,
      28,     9,    27,    25,    93,   116,   153
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    42,    20,     0,     4,     5,     6,    45,    46,
      47,    48,    49,    50,    49,    43,    45,    36,    51,    84,
      18,     7,    52,    53,    54,    55,    14,    15,    37,    49,
      44,    16,     8,    10,    11,    12,    13,    36,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    52,    51,    19,    36,    60,    49,
      56,    58,    16,    36,    16,    24,    29,    36,    37,    38,
      39,    65,    76,    77,    81,    82,    83,    76,    18,    22,
      19,    60,    14,    22,    20,    20,    20,    20,    16,    21,
      36,    85,    17,    14,    57,    76,    76,    80,    76,    76,
      23,    24,    25,    26,    27,    28,    16,    76,    76,    76,
      60,    60,    60,    60,    76,    18,    58,    17,    17,    30,
      31,    32,    33,    34,    35,    17,    76,    76,    76,    76,
      76,    76,    76,    78,    19,    21,    21,    21,    21,    17,
      45,    59,    57,    76,    76,    76,    76,    76,    76,    15,
      79,    17,     9,    76,    79
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    44,    45,    45,    46,    47,    47,
      48,    49,    49,    50,    51,    51,    52,    52,    53,    54,
      55,    56,    56,    57,    57,    58,    59,    59,    60,    60,
      61,    61,    62,    62,    62,    62,    63,    63,    64,    64,
      65,    66,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    77,    78,    78,    79,
      79,    80,    80,    80,    80,    80,    80,    81,    81,    82,
      82,    83,    84,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     0,     0,     1,     2,     3,     1,     1,
       1,     1,     1,     5,     1,     3,     2,     0,     3,     6,
       3,     2,     0,     3,     0,     2,     1,     0,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       4,     4,     4,     4,     5,     4,     4,     4,     1,     2,
       2,     2,     3,     3,     3,     3,     2,     3,     3,     2,
       1,     1,     3,     3,     1,     4,     1,     2,     0,     3,
       0,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 124 "alfa.y" /* yacc.c:1646  */
    {
        escribir_fin(yyout);
    }
#line 1454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 129 "alfa.y" /* yacc.c:1646  */
    {
        escribir_cabecera_bss(yyout, tabla_simbolos);
        escribir_subseccion_data(yyout);
        escribir_segmento_codigo(yyout);
    }
#line 1464 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 136 "alfa.y" /* yacc.c:1646  */
    {
        escribir_inicio_main(yyout);
    }
#line 1472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 149 "alfa.y" /* yacc.c:1646  */
    { clase_actual = ESCALAR; }
#line 1478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 151 "alfa.y" /* yacc.c:1646  */
    { clase_actual = VECTOR; }
#line 1484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 157 "alfa.y" /* yacc.c:1646  */
    { 
        tipo_actual = INT;
        (yyval.atributos).tipo = INT;
    }
#line 1493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 161 "alfa.y" /* yacc.c:1646  */
    {
        tipo_actual = BOOLEAN; 
        (yyval.atributos).tipo = BOOLEAN;
    }
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 167 "alfa.y" /* yacc.c:1646  */
    { 
        tam_vector_actual = (yyvsp[-1].atributos).valor_entero;
        if (tam_vector_actual < 1 || tam_vector_actual > MAX_TAM_VECTOR) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: Tamaño de vector inválido.\n", row, col);
            return PARAR_COMPILADOR;
        }
    }
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 184 "alfa.y" /* yacc.c:1646  */
    {
        if (TablaSimbolos_existe_global(tabla_simbolos, (yyvsp[0].atributos).lexema)) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: nombre de funcion %s ya utilizado.\n", row, col, (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }

        local = true;
        num_parametros_actual = 0;
        pos_parametro_actual = 0;
        num_variables_locales_actual = 0;
        pos_variable_local_actual = 1;
        tipo_retorno_funcion_actual = (yyvsp[-1].atributos).tipo;

        strcpy(atributos_actuales.lexema, (yyvsp[0].atributos).lexema);
        atributos_actuales.clase = FUNCION;
        atributos_actuales.tipo = (yyvsp[-1].atributos).tipo;

        TablaSimbolos_declarar_global(tabla_simbolos, (yyvsp[0].atributos).lexema, &atributos_actuales);
        TablaSimbolos_declarar_local(tabla_simbolos, (yyvsp[0].atributos).lexema, &atributos_actuales);

        strcpy((yyval.atributos).lexema, (yyvsp[0].atributos).lexema);
    }
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 208 "alfa.y" /* yacc.c:1646  */
    {
        TablaSimbolos_uso_global(tabla_simbolos, (yyvsp[-5].atributos).lexema)->num_parametros = num_parametros_actual;
        TablaSimbolos_uso_local(tabla_simbolos, (yyvsp[-5].atributos).lexema)->num_parametros = num_parametros_actual;
        strcpy((yyval.atributos).lexema, (yyvsp[-5].atributos).lexema);
    }
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 215 "alfa.y" /* yacc.c:1646  */
    {
        local = false;
        TablaSimbolos_uso_global(tabla_simbolos, (yyvsp[-2].atributos).lexema)->num_variables_locales = num_variables_locales_actual;
        TablaSimbolos_uso_local(tabla_simbolos, (yyvsp[-2].atributos).lexema)->num_variables_locales = num_variables_locales_actual;
    }
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 255 "alfa.y" /* yacc.c:1646  */
    { 
        if ((local && !TablaSimbolos_existe_local(tabla_simbolos, (yyvsp[-2].atributos).lexema)) || (!local && !TablaSimbolos_existe_global(tabla_simbolos, (yyvsp[-2].atributos).lexema))) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: El identificador %s no ha sido declarado.\n", row, col, (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        atributos_actuales = *(local ? TablaSimbolos_uso_local(tabla_simbolos, (yyvsp[-2].atributos).lexema) : TablaSimbolos_uso_global(tabla_simbolos, (yyvsp[-2].atributos).lexema));
        if (atributos_actuales.clase == FUNCION) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: El identificador %s corresponde a una función, por lo que no es asignable.\n", row, col, (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;
        } else if (atributos_actuales.clase == VECTOR) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: El identificador %s corresponde a un vector, por lo que no es asignable.\n", row, col, (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;
        } else if (atributos_actuales.tipo == BOOLEAN && (yyvsp[0].atributos).tipo == INT) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: Se intenta asignar a %s, de tipo booleano, una expresión de tipo entero.\n", row, col, (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;            
        } else if (atributos_actuales.tipo == INT && (yyvsp[0].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: Se intenta asignar a %s, de tipo entero, una expresión de tipo booleano.\n", row, col, (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;            
        }

        asignar(yyout, (yyvsp[-2].atributos).lexema, (yyvsp[0].atributos).es_direccion);
    }
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 277 "alfa.y" /* yacc.c:1646  */
    { 
        if ((yyvsp[-2].atributos).tipo == BOOLEAN && (yyvsp[0].atributos).tipo == INT) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: Se intenta asignar a %s, de tipo booleano, una expresión de tipo entero.\n", row, col, (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;            
        } else if ((yyvsp[-2].atributos).tipo == INT && (yyvsp[0].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: Se intenta asignar a %s, de tipo entero, una expresión de tipo booleano.\n", row, col, (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;            
        }

        asignar_vector(yyout, (yyvsp[0].atributos).es_direccion);
    }
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 290 "alfa.y" /* yacc.c:1646  */
    {
        if ((local && !TablaSimbolos_existe_local(tabla_simbolos, (yyvsp[-3].atributos).lexema)) || (!local && !TablaSimbolos_existe_global(tabla_simbolos, (yyvsp[-3].atributos).lexema))) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: El identificador %s no ha sido declarado.\n", row, col, (yyvsp[-3].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        atributos_actuales = *(local ? TablaSimbolos_uso_local(tabla_simbolos, (yyvsp[-3].atributos).lexema) : TablaSimbolos_uso_global(tabla_simbolos, (yyvsp[-3].atributos).lexema));
        if (atributos_actuales.clase == FUNCION) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: El identificador %s corresponde a una función, por lo que no es indexable.\n", row, col, (yyvsp[-3].atributos).lexema);
            return PARAR_COMPILADOR;
        } else if (atributos_actuales.clase == ESCALAR) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: El identificador %s corresponde a un escalar, por lo que no es indexable.\n", row, col, (yyvsp[-3].atributos).lexema);
            return PARAR_COMPILADOR;
        } else if ((yyvsp[-1].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: Se está indexando el vector %s con una expresión booleana, debería ser una expresión de tipo entero.\n", row, col, (yyvsp[-3].atributos).lexema);
            return PARAR_COMPILADOR;
        }

        strcpy((yyval.atributos).lexema, (yyvsp[-3].atributos).lexema);
        (yyval.atributos).tipo = atributos_actuales.tipo;
        (yyval.atributos).es_direccion = TRUE;

        escribir_elemento_vector(yyout, (yyvsp[-3].atributos).lexema, atributos_actuales.numero_elementos, (yyvsp[-1].atributos).es_direccion);
    }
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 315 "alfa.y" /* yacc.c:1646  */
    {
        ifthen_fin(yyout, (yyvsp[-3].atributos).etiqueta);
    }
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 318 "alfa.y" /* yacc.c:1646  */
    {
        ifthenelse_fin(yyout, (yyvsp[-3].atributos).etiqueta);
    }
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 323 "alfa.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-1].atributos).tipo == INT) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: Se está usando una expresión entera como condicional en un IF, debería ser una expresión booleana.\n", row, col);
            return PARAR_COMPILADOR;
        }

        ifthen_inicio(yyout, (yyvsp[-1].atributos).es_direccion, etiqueta);
        (yyval.atributos).etiqueta = etiqueta;
        etiqueta++;
    }
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 335 "alfa.y" /* yacc.c:1646  */
    {
        ifthenelse_fin_then(yyout, (yyvsp[-4].atributos).etiqueta);
        (yyval.atributos).etiqueta = (yyvsp[-4].atributos).etiqueta;
    }
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 341 "alfa.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-1].atributos).tipo == INT) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: Se está usando una expresión entera como condicional en un IF-ELSE, debería ser una expresión booleana.\n", row, col);
            return PARAR_COMPILADOR;
        }

        ifthenelse_inicio(yyout, (yyvsp[-1].atributos).es_direccion, etiqueta);
        (yyval.atributos).etiqueta = etiqueta;
        etiqueta++;
    }
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 353 "alfa.y" /* yacc.c:1646  */
    {
        while_fin(yyout, (yyvsp[-3].atributos).etiqueta);
    }
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 358 "alfa.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-1].atributos).tipo == INT) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: Se está usando una expresión entera como condicional en un WHILE, debería ser una expresión booleana.\n", row, col);
            return PARAR_COMPILADOR;
        }

        while_exp_pila(yyout, (yyvsp[-1].atributos).es_direccion, (yyvsp[-3].atributos).etiqueta);
        (yyval.atributos).etiqueta = (yyvsp[-3].atributos).etiqueta;
    }
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 369 "alfa.y" /* yacc.c:1646  */
    {
        while_inicio(yyout, etiqueta);
        (yyval.atributos).etiqueta = etiqueta;
        etiqueta++;
    }
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 376 "alfa.y" /* yacc.c:1646  */
    {
        if ((local && !TablaSimbolos_existe_local(tabla_simbolos, (yyvsp[0].atributos).lexema)) || (!local && !TablaSimbolos_existe_global(tabla_simbolos, (yyvsp[0].atributos).lexema))) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: El identificador %s no ha sido declarado.\n", row, col, (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        atributos_actuales = *(local ? TablaSimbolos_uso_local(tabla_simbolos, (yyvsp[0].atributos).lexema) : TablaSimbolos_uso_global(tabla_simbolos, (yyvsp[0].atributos).lexema));
        if (atributos_actuales.clase == FUNCION) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: El identificador %s corresponde a una función, pero scanf recibe como argumento un escalar.\n", row, col, (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        } else if (atributos_actuales.clase == VECTOR) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: El identificador %s corresponde a un vector, pero scanf recibe como argumento un escalar.\n", row, col, (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }

        leer(yyout, (yyvsp[0].atributos).lexema, atributos_actuales.tipo);
    }
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 394 "alfa.y" /* yacc.c:1646  */
    {
        escribir(yyout, (yyvsp[0].atributos).es_direccion, (yyvsp[0].atributos).tipo);
    }
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 399 "alfa.y" /* yacc.c:1646  */
    { 
        if (!local) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: Se ha declarado un RETURN fuera de una función, debería estar declarado dentro de una función.\n", row, col);
            return PARAR_COMPILADOR;
        } else if (tipo_retorno_funcion_actual == INT && (yyvsp[0].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: El tipo de retorno de una función es INT, pero se está devolviendo un parámetro de tipo BOOLEAN.\n", row, col);
            return PARAR_COMPILADOR;
        } else if (tipo_retorno_funcion_actual == BOOLEAN && (yyvsp[0].atributos).tipo == INT) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: El tipo de retorno de una función es BOOLEAN, pero se está devolviendo un parámetro de tipo INT.\n", row, col);
            return PARAR_COMPILADOR;
        }

        /*
            FALTA COMPROBAR:
                En el cuerpo de una función obligatoriamente tiene que aparecer al menos una sentencia de retorno. (?)
        */

        retornarFuncion(yyout, (yyvsp[0].atributos).es_direccion);
    }
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 420 "alfa.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: la expresión %s es un booleano, pero se usa en una suma.\n", row, col, (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        if ((yyvsp[0].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: la expresión %s es un booleano, pero se usa en una suma.\n", row, col, (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        
        (yyval.atributos).tipo = INT;
        (yyval.atributos).es_direccion = FALSE;

        sumar(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
    }
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 435 "alfa.y" /* yacc.c:1646  */
    { 
        if ((yyvsp[-2].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: la expresión %s es un booleano, pero se usa en una resta.\n", row, col, (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        if ((yyvsp[0].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: la expresión %s es un booleano, pero se usa en una resta.\n", row, col, (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        
        (yyval.atributos).tipo = INT;
        (yyval.atributos).es_direccion = FALSE;

        restar(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
    }
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 450 "alfa.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: la expresión %s es un booleano, pero se usa en una división.\n", row, col, (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        if ((yyvsp[0].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: la expresión %s es un booleano, pero se usa en una división.\n", row, col, (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        
        (yyval.atributos).tipo = INT;
        (yyval.atributos).es_direccion = FALSE;

        dividir(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
    }
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 465 "alfa.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: la expresión %s es un booleano, pero se usa en una multiplicación.\n", row, col, (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        if ((yyvsp[0].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: la expresión %s es un booleano, pero se usa en una multiplicación.\n", row, col, (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        
        (yyval.atributos).tipo = INT;
        (yyval.atributos).es_direccion = FALSE;

        multiplicar(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
    }
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 480 "alfa.y" /* yacc.c:1646  */
    {
        if ((yyvsp[0].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: la expresión %s es un booleano, pero se usa en un cambio de signo.\n", row, col, (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        
        (yyval.atributos).tipo = INT;
        (yyval.atributos).es_direccion = FALSE;

        cambiar_signo(yyout, (yyvsp[0].atributos).es_direccion);
    }
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 491 "alfa.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == INT) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: la expresión %s es un entero, pero se usa en un Y lógico.\n", row, col, (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        if ((yyvsp[0].atributos).tipo == INT) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: la expresión %s es un entero, pero se usa en un Y lógico.\n", row, col, (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;
        }

        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).es_direccion = FALSE;

        y(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
    }
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 506 "alfa.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).tipo == INT) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: la expresión %s es un entero, pero se usa en un O lógico.\n", row, col, (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        if ((yyvsp[0].atributos).tipo == INT) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: la expresión %s es un entero, pero se usa en un O lógico.\n", row, col, (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;
        }

        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).es_direccion = FALSE;

        o(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
    }
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 521 "alfa.y" /* yacc.c:1646  */
    {
        if ((yyvsp[0].atributos).tipo == INT) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: la expresión %s es un entero, pero se usa en una negación lógica.\n", row, col, (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }

        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).es_direccion = FALSE;

        no(yyout, (yyvsp[0].atributos).es_direccion, etiqueta);
        etiqueta++;
    }
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 533 "alfa.y" /* yacc.c:1646  */
    {
        if ((local && !TablaSimbolos_existe_local(tabla_simbolos, (yyvsp[0].atributos).lexema)) || (!local && !TablaSimbolos_existe_global(tabla_simbolos, (yyvsp[0].atributos).lexema))) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: El identificador %s no ha sido declarado.\n", row, col, (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        atributos_actuales = *(local ? TablaSimbolos_uso_local(tabla_simbolos, (yyvsp[0].atributos).lexema) : TablaSimbolos_uso_global(tabla_simbolos, (yyvsp[0].atributos).lexema));
        if (atributos_actuales.clase == FUNCION) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: El identificador %s corresponde a una función, por lo que no se puede acceder a su valor.\n", row, col, (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        } else if (atributos_actuales.clase == VECTOR) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: El identificador %s corresponde a un vector, por lo que no se puede acceder a su valor.\n", row, col, (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }

        (yyval.atributos).tipo = atributos_actuales.tipo;
        (yyval.atributos).es_direccion = TRUE;

        escribir_operando(yyout, (yyvsp[0].atributos).lexema, TRUE);
        if (en_explist) operandoEnPilaAArgumento(yyout, TRUE);
    }
#line 1950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 553 "alfa.y" /* yacc.c:1646  */
    { 
        (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
        (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion; 
    }
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 557 "alfa.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
        (yyval.atributos).es_direccion = (yyvsp[-1].atributos).es_direccion; 
    }
#line 1968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 561 "alfa.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
        (yyval.atributos).es_direccion = (yyvsp[-1].atributos).es_direccion; 
    }
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 565 "alfa.y" /* yacc.c:1646  */
    { 
        (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
        (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion; 
        if (en_explist) operandoEnPilaAArgumento(yyout, TRUE);
    }
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 570 "alfa.y" /* yacc.c:1646  */
    {
        if ((local && !TablaSimbolos_existe_local(tabla_simbolos, (yyvsp[-3].atributos).lexema)) || (!local && !TablaSimbolos_existe_global(tabla_simbolos, (yyvsp[-3].atributos).lexema))) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: El identificador %s no ha sido declarado.\n", row, col, (yyvsp[-3].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        atributos_actuales = *(local ? TablaSimbolos_uso_local(tabla_simbolos, (yyvsp[-3].atributos).lexema) : TablaSimbolos_uso_global(tabla_simbolos, (yyvsp[-3].atributos).lexema));
        if (atributos_actuales.clase == ESCALAR) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: El identificador %s corresponde a un escalar, por lo que no es invocable.\n", row, col, (yyvsp[-3].atributos).lexema);
            return PARAR_COMPILADOR;
        } else if (atributos_actuales.clase == VECTOR) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: El identificador %s corresponde a un vector, por lo que no es invocable.\n", row, col, (yyvsp[-3].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        en_explist = FALSE;
        (yyval.atributos).es_direccion = FALSE;
        (yyval.atributos).tipo = atributos_actuales.tipo;

        if (num_parametros_actual != atributos_actuales.num_parametros) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: En la llamada a la función %s se esperaban %d argumentos, pero se obtuvieron %d.\n", row, col, (yyvsp[-3].atributos).lexema, atributos_actuales.num_parametros, num_parametros_actual);
            return PARAR_COMPILADOR;
        }

        llamarFuncion(yyout, (yyvsp[-3].atributos).lexema, num_parametros_actual);
    }
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 596 "alfa.y" /* yacc.c:1646  */
    {
        if ((local && !TablaSimbolos_existe_local(tabla_simbolos, (yyvsp[0].atributos).lexema)) || (!local && !TablaSimbolos_existe_global(tabla_simbolos, (yyvsp[0].atributos).lexema))) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: El identificador %s no ha sido declarado.\n", row, col, (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        atributos_actuales = *(local ? TablaSimbolos_uso_local(tabla_simbolos, (yyvsp[0].atributos).lexema) : TablaSimbolos_uso_global(tabla_simbolos, (yyvsp[0].atributos).lexema));
        if (atributos_actuales.clase == ESCALAR) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: El identificador %s corresponde a un escalar, por lo que no es invocable.\n", row, col, (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        } else if (atributos_actuales.clase == VECTOR) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: El identificador %s corresponde a un vector, por lo que no es invocable.\n", row, col, (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }

        if (en_explist == TRUE) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: Se están anidando las llamadas a función.\n", row, col);
            return PARAR_COMPILADOR;
        }

        num_parametros_actual = 0;
        en_explist = TRUE;
        strcpy((yyval.atributos).lexema, (yyvsp[0].atributos).lexema);
    }
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 621 "alfa.y" /* yacc.c:1646  */
    {
        num_parametros_actual++;
    }
#line 2052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 627 "alfa.y" /* yacc.c:1646  */
    {
        num_parametros_actual++;
    }
#line 2060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 633 "alfa.y" /* yacc.c:1646  */
    { 
        if ((yyvsp[-2].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: la expresión %s es un booleano, pero se usa en una comparación.\n", row, col, (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        if ((yyvsp[0].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: la expresión %s es un booleano, pero se usa en una comparación.\n", row, col, (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).es_direccion = FALSE;

        igual(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, etiqueta);
        etiqueta++;
    }
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 649 "alfa.y" /* yacc.c:1646  */
    { 
        if ((yyvsp[-2].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: la expresión %s es un booleano, pero se usa en una comparación.\n", row, col, (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        if ((yyvsp[0].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: la expresión %s es un booleano, pero se usa en una comparación.\n", row, col, (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).es_direccion = FALSE;

        distinto(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, etiqueta);
        etiqueta++;
    }
#line 2102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 665 "alfa.y" /* yacc.c:1646  */
    { 
        if ((yyvsp[-2].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: la expresión %s es un booleano, pero se usa en una comparación.\n", row, col, (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        if ((yyvsp[0].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: la expresión %s es un booleano, pero se usa en una comparación.\n", row, col, (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).es_direccion = FALSE;

        menor_igual(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, etiqueta);
        etiqueta++;
    }
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 681 "alfa.y" /* yacc.c:1646  */
    { 
        if ((yyvsp[-2].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: la expresión %s es un booleano, pero se usa en una comparación.\n", row, col, (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        if ((yyvsp[0].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: la expresión %s es un booleano, pero se usa en una comparación.\n", row, col, (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).es_direccion = FALSE;

        mayor_igual(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, etiqueta);
        etiqueta++;
    }
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 697 "alfa.y" /* yacc.c:1646  */
    { 
        if ((yyvsp[-2].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: la expresión %s es un booleano, pero se usa en una comparación.\n", row, col, (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        if ((yyvsp[0].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: la expresión %s es un booleano, pero se usa en una comparación.\n", row, col, (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).es_direccion = FALSE;

        menor(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, etiqueta);
        etiqueta++;
    }
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 713 "alfa.y" /* yacc.c:1646  */
    { 
        if ((yyvsp[-2].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: la expresión %s es un booleano, pero se usa en una comparación.\n", row, col, (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        if ((yyvsp[0].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: la expresión %s es un booleano, pero se usa en una comparación.\n", row, col, (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).es_direccion = FALSE;

        mayor(yyout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, etiqueta);
        etiqueta++;
    }
#line 2186 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 731 "alfa.y" /* yacc.c:1646  */
    { 
        (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
        (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
    }
#line 2195 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 735 "alfa.y" /* yacc.c:1646  */
    { 
        (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
        (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
    }
#line 2204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 741 "alfa.y" /* yacc.c:1646  */
    { 
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).es_direccion = FALSE;
        escribir_operando(yyout, "1", false);
    }
#line 2214 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 746 "alfa.y" /* yacc.c:1646  */
    { 
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).es_direccion = FALSE;
        escribir_operando(yyout, "0", false);
    }
#line 2224 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 753 "alfa.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = INT;
        (yyval.atributos).es_direccion = FALSE;
        sprintf(atributos_actuales.lexema, "%d", (yyvsp[0].atributos).valor_entero);
        escribir_operando(yyout, atributos_actuales.lexema, false);
    }
#line 2235 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 761 "alfa.y" /* yacc.c:1646  */
    {
        strcpy(atributos_actuales.lexema, (yyvsp[0].atributos).lexema);
        atributos_actuales.clase = clase_actual;
        atributos_actuales.tipo = tipo_actual;

        if (local) {
            if (TablaSimbolos_existe_local(tabla_simbolos, (yyvsp[0].atributos).lexema)) {
                fprintf(stderr, "Error semántico [lin %d, col %d]: Identificador %s duplicado.\n", row, col, (yyvsp[0].atributos).lexema);
                return PARAR_COMPILADOR;
            } else {
                TablaSimbolos_declarar_local(tabla_simbolos, (yyvsp[0].atributos).lexema, &atributos_actuales);
            }
        } else {
            if (TablaSimbolos_existe_global(tabla_simbolos, (yyvsp[0].atributos).lexema)) {
                fprintf(stderr, "Error semántico [lin %d, col %d]: Identificador %s duplicado.\n", row, col, (yyvsp[0].atributos).lexema);
                return PARAR_COMPILADOR;
            } else {
                TablaSimbolos_declarar_global(tabla_simbolos, (yyvsp[0].atributos).lexema, &atributos_actuales);
            }
        }
    }
#line 2261 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 784 "alfa.y" /* yacc.c:1646  */
    {
        strcpy(atributos_actuales.lexema, (yyvsp[0].atributos).lexema);
        if (TablaSimbolos_existe_local(tabla_simbolos, (yyvsp[0].atributos).lexema)) {
            fprintf(stderr, "Error semántico [lin %d, col %d]: Identificador %s duplicado en la declaración de la función.\n", row, col, (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        atributos_actuales.posicion = pos_parametro_actual;
        TablaSimbolos_declarar_local(tabla_simbolos, (yyvsp[0].atributos).lexema, &atributos_actuales);
        pos_parametro_actual++;
        num_parametros_actual++;
    }
#line 2277 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2281 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 796 "alfa.y" /* yacc.c:1906  */


int main(int argc, char **argv) {
    int status;

    if (argc != 3) {
        fprintf(stderr, "Error: Número incorrecto de argumentos.\n");
        return -1;
    }

    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
        fprintf(stderr, "Error: No se ha podido abrir el fichero %s.\n", argv[1]);
        return -1;
    }

    yyout = fopen(argv[2], "w");
    if (yyout == NULL) {
        fprintf(stderr, "Error: No se ha podido abrir el fichero %s.\n", argv[2]);
        fclose(yyin);
        return -1;
    }

    tabla_simbolos = TablaSimbolos_create();
    if (tabla_simbolos == NULL) {
        fprintf(stderr, "Error: No se ha podido crear la tabla de símbolos.\n");
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
        fprintf(stderr, "Error sintáctico [lin %d, col %d]\n", row, col-yyleng);
    }
    return 0;
}
