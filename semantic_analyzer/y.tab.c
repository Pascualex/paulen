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

#line 103 "y.tab.c" /* yacc.c:339  */

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
#line 38 "alfa.y" /* yacc.c:355  */

    tipo_atributos atributos;

#line 227 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 244 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   149

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  142

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
       0,   112,   112,   115,   116,   119,   122,   124,   128,   131,
     135,   141,   150,   151,   154,   154,   158,   182,   189,   204,
     207,   207,   211,   212,   215,   216,   219,   220,   221,   222,
     225,   226,   229,   251,   264,   288,   296,   297,   300,   308,
     311,   328,   331,   350,   363,   376,   389,   402,   411,   424,
     437,   446,   464,   468,   472,   476,   480,   500,   525,   527,
     531,   533,   537,   550,   563,   576,   589,   602,   617,   621,
     627,   631,   637,   643,   666
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
  "declaraciones", "declaracion", "clase", "clase_escalar", "tipo",
  "clase_vector", "identificadores", "funciones", "fn_name",
  "fn_declaration", "funcion", "parametro_funcion",
  "declaraciones_funcion", "sentencias", "sentencia", "sentencia_simple",
  "bloque", "asignacion", "elemento_vector", "if_exp", "condicional",
  "while_exp", "bucle", "lectura", "escritura", "retorno_funcion", "exp",
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

#define YYPACT_NINF -26

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-26)))

#define YYTABLE_NINF -58

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      15,     6,    43,    31,   -26,   -26,   -26,    35,    45,    31,
      17,   -26,   -26,   -26,    40,    35,     2,    60,     2,    45,
     -26,   -26,    63,    64,    41,    44,    72,    73,    54,    18,
      18,    11,    71,     2,    77,   -26,   -26,    91,    94,   -26,
      95,   -26,   -26,   -26,   -26,    35,    98,   -26,   -26,    17,
      99,   -26,    18,    18,   -26,    18,    18,    18,    30,   -26,
     -26,   -26,   -26,    47,   104,   -26,   -26,   -26,    47,    18,
      18,   -26,   -26,   -26,    18,     2,     2,    85,   106,   -26,
     -26,   -26,   102,   114,    70,   115,    25,   -17,    18,    18,
      18,    18,    18,    18,    18,    -3,    47,    47,   112,   113,
     -26,   -26,   117,   -26,   -26,   -26,    18,    18,    18,    18,
      18,    18,   -26,    25,    25,   -26,   -26,   -17,   -17,    84,
     119,   -26,   134,   -26,    31,    47,    47,    47,    47,    47,
      47,    18,   -26,   -26,   124,   -26,   -26,    84,     2,   -26,
     125,   -26
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     9,    10,     0,    15,     3,
       0,     6,     8,     7,     0,     0,     0,     0,     0,    15,
       4,    73,     0,    12,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,     0,    25,    26,     0,     0,    30,
       0,    31,    27,    28,    29,     0,     0,    14,     5,     0,
       0,    16,     0,     0,    40,     0,     0,     0,    51,    72,
      70,    71,    55,    41,     0,    52,    68,    69,    42,     0,
       0,     2,    23,    24,     0,     0,     0,     0,     0,    18,
      13,    11,     0,     0,     0,     0,    47,    50,     0,     0,
       0,     0,     0,     0,    59,     0,    32,    33,     0,     0,
      74,    19,     0,    35,    38,    53,     0,     0,     0,     0,
       0,     0,    54,    43,    44,    45,    46,    48,    49,    61,
       0,    34,    36,    39,    21,    62,    63,    64,    65,    66,
      67,     0,    58,    56,     0,    20,    17,    61,     0,    60,
       0,    37
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -26,   -26,    -8,   -26,   -26,   -26,    -4,   -26,    96,   128,
     -26,   -26,   -26,   -26,   -26,   -14,   -26,   -26,   -26,   -26,
     -16,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -25,   -26,
     -26,    12,   -26,   -26,   -26,   -26,   -26,   -26
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,     9,    10,    11,    12,    13,    22,    16,
      17,    18,    19,    78,   136,    32,    33,    34,    35,    36,
      62,    38,    39,    40,    41,    42,    43,    44,    63,    64,
     120,   132,    85,    65,    66,    67,    23,   101
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      37,    20,    37,    14,    46,    68,    88,    89,    90,    91,
      26,    25,    27,    28,    29,    30,   121,    37,     1,    72,
      88,    89,    90,    91,    92,    93,     3,    82,    83,    69,
      84,    86,    87,    70,    55,     5,     6,     7,    31,     5,
       6,    77,    56,     4,    95,    96,   -57,    57,    69,    97,
      90,    91,    15,    21,    58,    59,    60,    61,    24,    37,
      37,    98,    99,   113,   114,   115,   116,   117,   118,   119,
      88,    89,    90,    91,    92,    93,    45,    48,    50,    49,
      51,   125,   126,   127,   128,   129,   130,   105,    52,    53,
      54,    73,    71,    88,    89,    90,    91,    92,    93,   131,
     106,   107,   108,   109,   110,   111,   137,    88,    89,    90,
      91,    92,    93,    74,    75,    76,   135,    79,    81,   103,
      94,   100,    37,   102,   140,    88,    89,    90,    91,    92,
      93,   104,   112,   122,   123,   124,   133,    88,    89,    90,
      91,    92,    93,   134,   138,    80,   141,    47,     0,   139
};

static const yytype_int16 yycheck[] =
{
      16,     9,    18,     7,    18,    30,    23,    24,    25,    26,
       8,    15,    10,    11,    12,    13,    19,    33,     3,    33,
      23,    24,    25,    26,    27,    28,    20,    52,    53,    18,
      55,    56,    57,    22,    16,     4,     5,     6,    36,     4,
       5,    45,    24,     0,    69,    70,    16,    29,    18,    74,
      25,    26,     7,    36,    36,    37,    38,    39,    18,    75,
      76,    75,    76,    88,    89,    90,    91,    92,    93,    94,
      23,    24,    25,    26,    27,    28,    16,    14,    37,    15,
      36,   106,   107,   108,   109,   110,   111,    17,    16,    16,
      36,    14,    21,    23,    24,    25,    26,    27,    28,    15,
      30,    31,    32,    33,    34,    35,   131,    23,    24,    25,
      26,    27,    28,    22,    20,    20,   124,    19,    19,    17,
      16,    36,   138,    17,   138,    23,    24,    25,    26,    27,
      28,    17,    17,    21,    21,    18,    17,    23,    24,    25,
      26,    27,    28,     9,    20,    49,    21,    19,    -1,   137
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    42,    20,     0,     4,     5,     6,    43,    44,
      45,    46,    47,    48,    47,     7,    50,    51,    52,    53,
      43,    36,    49,    77,    18,    47,     8,    10,    11,    12,
      13,    36,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    16,    56,    50,    14,    15,
      37,    36,    16,    16,    36,    16,    24,    29,    36,    37,
      38,    39,    61,    69,    70,    74,    75,    76,    69,    18,
      22,    21,    56,    14,    22,    20,    20,    47,    54,    19,
      49,    19,    69,    69,    69,    73,    69,    69,    23,    24,
      25,    26,    27,    28,    16,    69,    69,    69,    56,    56,
      36,    78,    17,    17,    17,    17,    30,    31,    32,    33,
      34,    35,    17,    69,    69,    69,    69,    69,    69,    69,
      71,    19,    21,    21,    18,    69,    69,    69,    69,    69,
      69,    15,    72,    17,     9,    43,    55,    69,    20,    72,
      56,    21
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    45,    45,    46,    47,
      47,    48,    49,    49,    50,    50,    51,    52,    53,    54,
      55,    55,    56,    56,    57,    57,    58,    58,    58,    58,
      59,    59,    60,    60,    61,    62,    63,    63,    64,    65,
      66,    67,    68,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    70,    71,    71,
      72,    72,    73,    73,    73,    73,    73,    73,    74,    74,
      75,    75,    76,    77,    78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     1,     2,     3,     1,     1,     1,     1,
       1,     5,     1,     3,     2,     0,     3,     6,     3,     2,
       1,     0,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     4,     4,     4,     8,     4,     4,
       2,     2,     2,     3,     3,     3,     3,     2,     3,     3,
       2,     1,     1,     3,     3,     1,     4,     1,     2,     0,
       3,     0,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     1
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
        case 6:
#line 123 "alfa.y" /* yacc.c:1646  */
    { clase_actual = ESCALAR; }
#line 1431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 125 "alfa.y" /* yacc.c:1646  */
    { clase_actual = VECTOR; }
#line 1437 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 131 "alfa.y" /* yacc.c:1646  */
    { 
        tipo_actual = INT;
        (yyval.atributos).tipo = INT;
    }
#line 1446 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 135 "alfa.y" /* yacc.c:1646  */
    {
        tipo_actual = BOOLEAN; 
        (yyval.atributos).tipo = BOOLEAN;
    }
#line 1455 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 141 "alfa.y" /* yacc.c:1646  */
    { 
        tam_vector_actual = (yyvsp[-1].atributos).valor_entero;
        if (tam_vector_actual < 1 || tam_vector_actual > MAX_TAM_VECTOR) {
            fprintf(stderr, "ERROR: Tamaño de vector inválido.\n");
            return PARAR_COMPILADOR;
        }
    }
#line 1467 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 158 "alfa.y" /* yacc.c:1646  */
    {
        if (TablaSimbolos_existe_global(tabla_simbolos, (yyvsp[0].atributos).lexema)) {
            fprintf(stderr, "ERROR: nombre de funcion %s ya utilizado.\n", (yyvsp[0].atributos).lexema);
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
#line 1494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 182 "alfa.y" /* yacc.c:1646  */
    {
        TablaSimbolos_uso_global(tabla_simbolos, (yyvsp[-5].atributos).lexema)->num_parametros = num_parametros_actual;
        TablaSimbolos_uso_local(tabla_simbolos, (yyvsp[-5].atributos).lexema)->num_parametros = num_parametros_actual;
        strcpy((yyval.atributos).lexema, (yyvsp[-5].atributos).lexema);
    }
#line 1504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 189 "alfa.y" /* yacc.c:1646  */
    {
        local = false;
        TablaSimbolos_uso_global(tabla_simbolos, (yyvsp[-2].atributos).lexema)->num_variables_locales = num_variables_locales_actual;
        TablaSimbolos_uso_local(tabla_simbolos, (yyvsp[-2].atributos).lexema)->num_variables_locales = num_variables_locales_actual;
    }
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 229 "alfa.y" /* yacc.c:1646  */
    { 
        if ((local && !TablaSimbolos_existe_local(tabla_simbolos, (yyvsp[-2].atributos).lexema)) || (!local && !TablaSimbolos_existe_global(tabla_simbolos, (yyvsp[-2].atributos).lexema))) {
            fprintf(stderr, "ERROR: El identificador %s no ha sido declarado.\n", (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        atributos_actuales = *(local ? TablaSimbolos_uso_local(tabla_simbolos, (yyvsp[-2].atributos).lexema) : TablaSimbolos_uso_global(tabla_simbolos, (yyvsp[-2].atributos).lexema));
        if (atributos_actuales.tipo == FUNCION) {
            fprintf(stderr, "ERROR: El identificador %s corresponde a una función, por lo que no es asignable.\n", (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;
        } else if (atributos_actuales.tipo == VECTOR) {
            fprintf(stderr, "ERROR: El identificador %s corresponde a un vector, por lo que no es asignable.\n", (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;
        } else if (atributos_actuales.clase == BOOLEAN && (yyvsp[0].atributos).clase == INT) {
            fprintf(stderr, "ERROR: Se intenta asignar a %s, de tipo booleano, una expresión de tipo entero.\n", (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;            
        } else if (atributos_actuales.clase == INT && (yyvsp[0].atributos).clase == BOOLEAN) {
            fprintf(stderr, "ERROR: Se intenta asignar a %s, de tipo entero, una expresión de tipo booleano.\n", (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;            
        }

        /* GENERACIÓN DE CÓDIGO ASIGNACIÓN */
    }
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 251 "alfa.y" /* yacc.c:1646  */
    { 
        if ((yyvsp[-2].atributos).clase == BOOLEAN && (yyvsp[0].atributos).clase == INT) {
            fprintf(stderr, "ERROR: Se intenta asignar a %s, de tipo booleano, una expresión de tipo entero.\n", (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;            
        } else if ((yyvsp[-2].atributos).clase == INT && (yyvsp[0].atributos).clase == BOOLEAN) {
            fprintf(stderr, "ERROR: Se intenta asignar a %s, de tipo entero, una expresión de tipo booleano.\n", (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;            
        }

        /* GENERACIÓN DE CÓDIGO ASIGNACIÓN */
    }
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 264 "alfa.y" /* yacc.c:1646  */
    {
        if ((local && !TablaSimbolos_existe_local(tabla_simbolos, (yyvsp[-3].atributos).lexema)) || (!local && !TablaSimbolos_existe_global(tabla_simbolos, (yyvsp[-3].atributos).lexema))) {
            fprintf(stderr, "ERROR: El identificador %s no ha sido declarado.\n", (yyvsp[-3].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        atributos_actuales = *(local ? TablaSimbolos_uso_local(tabla_simbolos, (yyvsp[-3].atributos).lexema) : TablaSimbolos_uso_global(tabla_simbolos, (yyvsp[-3].atributos).lexema));
        if (atributos_actuales.tipo == FUNCION) {
            fprintf(stderr, "ERROR: El identificador %s corresponde a una función, por lo que no es indexable.\n", (yyvsp[-3].atributos).lexema);
            return PARAR_COMPILADOR;
        } else if (atributos_actuales.tipo == ESCALAR) {
            fprintf(stderr, "ERROR: El identificador %s corresponde a un escalar, por lo que no es indexable.\n", (yyvsp[-3].atributos).lexema);
            return PARAR_COMPILADOR;
        } else if ((yyvsp[-1].atributos).clase == BOOLEAN) {
            fprintf(stderr, "ERROR: Se está indexando el vector %s con una expresión booleana, debería ser una expresión de tipo entero.\n", (yyvsp[-3].atributos).lexema);
            return PARAR_COMPILADOR;
        }

        strcpy((yyval.atributos).lexema, (yyvsp[-3].atributos).lexema);
        (yyval.atributos).tipo = atributos_actuales.tipo;
        (yyval.atributos).es_direccion = TRUE;
        /* GENERACIÓN DE CÓDIGO APILAR ELEMENTO (?) */
    }
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 288 "alfa.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-1].atributos).tipo == INT) {
            fprintf(stderr, "ERROR: Se está usando una expresión entera como condicional en un IF, debería ser una expresión booleana.\n");
            return PARAR_COMPILADOR;
        }
    }
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 296 "alfa.y" /* yacc.c:1646  */
    { }
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 297 "alfa.y" /* yacc.c:1646  */
    { }
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 300 "alfa.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-1].atributos).tipo == INT) {
            fprintf(stderr, "ERROR: Se está usando una expresión entera como condicional en un WHILE, debería ser una expresión booleana.\n");
            return PARAR_COMPILADOR;
        }
    }
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 308 "alfa.y" /* yacc.c:1646  */
    { }
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 311 "alfa.y" /* yacc.c:1646  */
    {
        if ((local && !TablaSimbolos_existe_local(tabla_simbolos, (yyvsp[0].atributos).lexema)) || (!local && !TablaSimbolos_existe_global(tabla_simbolos, (yyvsp[0].atributos).lexema))) {
            fprintf(stderr, "ERROR: El identificador %s no ha sido declarado.\n", (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        atributos_actuales = *(local ? TablaSimbolos_uso_local(tabla_simbolos, (yyvsp[0].atributos).lexema) : TablaSimbolos_uso_global(tabla_simbolos, (yyvsp[0].atributos).lexema));
        if (atributos_actuales.tipo == FUNCION) {
            fprintf(stderr, "ERROR: El identificador %s corresponde a una función, pero scanf recibe como argumento un escalar.\n", (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        } else if (atributos_actuales.tipo == VECTOR) {
            fprintf(stderr, "ERROR: El identificador %s corresponde a un vector, pero scanf recibe como argumento un escalar.\n", (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        /* GENERACIÓN DE CÓDIGO LECTURA */
    }
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 331 "alfa.y" /* yacc.c:1646  */
    { 
        if (!local) {
            fprintf(stderr, "ERROR: Se ha declarado un RETURN fuera de una función, debería estar declarado dentro de una función.\n");
            return PARAR_COMPILADOR;
        } else if (tipo_retorno_funcion_actual == INT && (yyvsp[0].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "ERROR: El tipo de retorno de una función es INT, pero se está devolviendo un parámetro de tipo BOOLEAN.\n");
            return PARAR_COMPILADOR;
        } else if (tipo_retorno_funcion_actual == BOOLEAN && (yyvsp[0].atributos).tipo == INT) {
            fprintf(stderr, "ERROR: El tipo de retorno de una función es BOOLEAN, pero se está devolviendo un parámetro de tipo INT.\n");
            return PARAR_COMPILADOR;
        }

        /*
            FALTA COMPROBAR:
                En el cuerpo de una función obligatoriamente tiene que aparecer al menos una sentencia de retorno. (?)
        */
    }
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 350 "alfa.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).clase == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una suma.\n", (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        if ((yyvsp[0].atributos).clase == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una suma.\n", (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        
        (yyval.atributos).clase = INT;
        (yyval.atributos).es_direccion = 0;
    }
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 363 "alfa.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).clase == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una resta.\n", (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        if ((yyvsp[0].atributos).clase == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una resta.\n", (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        
        (yyval.atributos).clase = INT;
        (yyval.atributos).es_direccion = 0;
    }
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 376 "alfa.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).clase == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una división.\n", (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        if ((yyvsp[0].atributos).clase == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una división.\n", (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        
        (yyval.atributos).clase = INT;
        (yyval.atributos).es_direccion = 0;
    }
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 389 "alfa.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).clase == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una multiplicación.\n", (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        if ((yyvsp[0].atributos).clase == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una multiplicación.\n", (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        
        (yyval.atributos).clase = INT;
        (yyval.atributos).es_direccion = 0;
    }
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 402 "alfa.y" /* yacc.c:1646  */
    {
        if ((yyvsp[0].atributos).clase == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en un cambio de signo.\n", (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        
        (yyval.atributos).clase = INT;
        (yyval.atributos).es_direccion = 0;
    }
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 411 "alfa.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).clase == INT) {
            fprintf(stderr, "ERROR: la expresión %s es un entero, pero se usa en un Y lógico.\n", (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        if ((yyvsp[0].atributos).clase == INT) {
            fprintf(stderr, "ERROR: la expresión %s es un entero, pero se usa en un Y lógico.\n", (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;
        }

        (yyval.atributos).clase = BOOLEAN;
        (yyval.atributos).es_direccion = 0;
    }
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 424 "alfa.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].atributos).clase == INT) {
            fprintf(stderr, "ERROR: la expresión %s es un entero, pero se usa en un O lógico.\n", (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        if ((yyvsp[0].atributos).clase == INT) {
            fprintf(stderr, "ERROR: la expresión %s es un entero, pero se usa en un O lógico.\n", (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;
        }

        (yyval.atributos).clase = BOOLEAN;
        (yyval.atributos).es_direccion = 0;
    }
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 437 "alfa.y" /* yacc.c:1646  */
    {
        if ((yyvsp[0].atributos).clase == INT) {
            fprintf(stderr, "ERROR: la expresión %s es un entero, pero se usa en una negación lógica.\n", (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }

        (yyval.atributos).clase = BOOLEAN;
        (yyval.atributos).es_direccion = 0;
    }
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 446 "alfa.y" /* yacc.c:1646  */
    {
        if ((local && !TablaSimbolos_existe_local(tabla_simbolos, (yyvsp[0].atributos).lexema)) || (!local && !TablaSimbolos_existe_global(tabla_simbolos, (yyvsp[0].atributos).lexema))) {
            fprintf(stderr, "ERROR: El identificador %s no ha sido declarado.\n", (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        atributos_actuales = *(local ? TablaSimbolos_uso_local(tabla_simbolos, (yyvsp[0].atributos).lexema) : TablaSimbolos_uso_global(tabla_simbolos, (yyvsp[0].atributos).lexema));
        if (atributos_actuales.tipo == FUNCION) {
            fprintf(stderr, "ERROR: El identificador %s corresponde a una función, por lo que no se puede acceder a su valor.\n", (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        } else if (atributos_actuales.tipo == VECTOR) {
            fprintf(stderr, "ERROR: El identificador %s corresponde a un vector, por lo que no se puede acceder a su valor.\n", (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }

        (yyval.atributos).tipo = atributos_actuales.tipo;
        (yyval.atributos).es_direccion = TRUE;
        /* GENERACIÓN DE CÓDIGO APILAR (?) */
    }
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 464 "alfa.y" /* yacc.c:1646  */
    { 
        (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
        (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion; 
    }
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 468 "alfa.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
        (yyval.atributos).es_direccion = (yyvsp[-1].atributos).es_direccion; 
    }
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 472 "alfa.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
        (yyval.atributos).es_direccion = (yyvsp[-1].atributos).es_direccion; 
    }
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 476 "alfa.y" /* yacc.c:1646  */
    { 
        (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
        (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion; 
    }
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 480 "alfa.y" /* yacc.c:1646  */
    {
        if ((local && !TablaSimbolos_existe_local(tabla_simbolos, (yyvsp[-3].atributos).lexema)) || (!local && !TablaSimbolos_existe_global(tabla_simbolos, (yyvsp[-3].atributos).lexema))) {
            fprintf(stderr, "ERROR: El identificador %s no ha sido declarado.\n", (yyvsp[-3].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        atributos_actuales = *(local ? TablaSimbolos_uso_local(tabla_simbolos, (yyvsp[-3].atributos).lexema) : TablaSimbolos_uso_global(tabla_simbolos, (yyvsp[-3].atributos).lexema));
        if (atributos_actuales.tipo == ESCALAR) {
            fprintf(stderr, "ERROR: El identificador %s corresponde a un escalar, por lo que no es invocable.\n", (yyvsp[-3].atributos).lexema);
            return PARAR_COMPILADOR;
        } else if (atributos_actuales.tipo == VECTOR) {
            fprintf(stderr, "ERROR: El identificador %s corresponde a un vector, por lo que no es invocable.\n", (yyvsp[-3].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        /* GENERACIÓN DE CÓDIGO LLAMADA A FUNCIÓN (?) */
        en_explist = FALSE;
        (yyval.atributos).es_direccion = FALSE;
        (yyval.atributos).tipo = atributos_actuales.tipo;
    }
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 500 "alfa.y" /* yacc.c:1646  */
    {
        if ((local && !TablaSimbolos_existe_local(tabla_simbolos, (yyvsp[0].atributos).lexema)) || (!local && !TablaSimbolos_existe_global(tabla_simbolos, (yyvsp[0].atributos).lexema))) {
            fprintf(stderr, "ERROR: El identificador %s no ha sido declarado.\n", (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        atributos_actuales = *(local ? TablaSimbolos_uso_local(tabla_simbolos, (yyvsp[0].atributos).lexema) : TablaSimbolos_uso_global(tabla_simbolos, (yyvsp[0].atributos).lexema));
        if (atributos_actuales.tipo == ESCALAR) {
            fprintf(stderr, "ERROR: El identificador %s corresponde a un escalar, por lo que no es invocable.\n", (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        } else if (atributos_actuales.tipo == VECTOR) {
            fprintf(stderr, "ERROR: El identificador %s corresponde a un vector, por lo que no es invocable.\n", (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }

        if (en_explist == TRUE) {
            fprintf(stderr, "ERROR: Se están anidando las llamadas a función.\n");
            return PARAR_COMPILADOR;
        }

        num_parametros_actual = 0;
        en_explist = TRUE;
        strcpy((yyval.atributos).lexema, (yyvsp[0].atributos).lexema);
    }
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 525 "alfa.y" /* yacc.c:1646  */
    {
        num_parametros_actual++;
    }
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 531 "alfa.y" /* yacc.c:1646  */
    {
        num_parametros_actual++;
    }
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 537 "alfa.y" /* yacc.c:1646  */
    { 
        if ((yyvsp[-2].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una comparación.\n", (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        if ((yyvsp[0].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una comparación.\n", (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).es_direccion = 0;
    }
#line 1946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 550 "alfa.y" /* yacc.c:1646  */
    { 
        if ((yyvsp[-2].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una comparación.\n", (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        if ((yyvsp[0].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una comparación.\n", (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).es_direccion = 0;
    }
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 563 "alfa.y" /* yacc.c:1646  */
    { 
        if ((yyvsp[-2].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una comparación.\n", (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        if ((yyvsp[0].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una comparación.\n", (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).es_direccion = 0;
    }
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 576 "alfa.y" /* yacc.c:1646  */
    { 
        if ((yyvsp[-2].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una comparación.\n", (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        if ((yyvsp[0].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una comparación.\n", (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).es_direccion = 0;
    }
#line 2000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 589 "alfa.y" /* yacc.c:1646  */
    { 
        if ((yyvsp[-2].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una comparación.\n", (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        if ((yyvsp[0].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una comparación.\n", (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).es_direccion = 0;
    }
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 602 "alfa.y" /* yacc.c:1646  */
    { 
        if ((yyvsp[-2].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una comparación.\n", (yyvsp[-2].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        if ((yyvsp[0].atributos).tipo == BOOLEAN) {
            fprintf(stderr, "ERROR: la expresión %s es un booleano, pero se usa en una comparación.\n", (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).es_direccion = 0;
    }
#line 2036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 617 "alfa.y" /* yacc.c:1646  */
    { 
        (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
        (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
    }
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 621 "alfa.y" /* yacc.c:1646  */
    { 
        (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
        (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
    }
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 627 "alfa.y" /* yacc.c:1646  */
    { 
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).es_direccion = FALSE;
    }
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 631 "alfa.y" /* yacc.c:1646  */
    { 
        (yyval.atributos).tipo = BOOLEAN;
        (yyval.atributos).es_direccion = FALSE;
    }
#line 2072 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 637 "alfa.y" /* yacc.c:1646  */
    {
        (yyval.atributos).tipo = INT;
        (yyval.atributos).es_direccion = FALSE;
    }
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 643 "alfa.y" /* yacc.c:1646  */
    {
        strcpy(atributos_actuales.lexema, (yyvsp[0].atributos).lexema);
        atributos_actuales.clase = clase_actual;
        atributos_actuales.tipo = tipo_actual;

        if (local) {
            if (TablaSimbolos_existe_local(tabla_simbolos, (yyvsp[0].atributos).lexema)) {
                fprintf(stderr, "ERROR: Identificador %s duplicado.\n", (yyvsp[0].atributos).lexema);
                return PARAR_COMPILADOR;
            } else {
                TablaSimbolos_declarar_local(tabla_simbolos, (yyvsp[0].atributos).lexema, &atributos_actuales);
            }
        } else {
            if (TablaSimbolos_existe_global(tabla_simbolos, (yyvsp[0].atributos).lexema)) {
                fprintf(stderr, "ERROR: Identificador %s duplicado.\n", (yyvsp[0].atributos).lexema);
                return PARAR_COMPILADOR;
            } else {
                TablaSimbolos_declarar_global(tabla_simbolos, (yyvsp[0].atributos).lexema, &atributos_actuales);
            }
        }
    }
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 666 "alfa.y" /* yacc.c:1646  */
    {
        strcpy(atributos_actuales.lexema, (yyvsp[0].atributos).lexema);
        if (TablaSimbolos_existe_local(tabla_simbolos, (yyvsp[0].atributos).lexema)) {
            fprintf(stderr, "ERROR: Identificador %s duplicado en la declaración de la función.\n", (yyvsp[0].atributos).lexema);
            return PARAR_COMPILADOR;
        }
        atributos_actuales.posicion = pos_parametro_actual;
        TablaSimbolos_declarar_local(tabla_simbolos, (yyvsp[0].atributos).lexema, &atributos_actuales);
        pos_parametro_actual++;
        num_parametros_actual++;
    }
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2127 "y.tab.c" /* yacc.c:1646  */
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
#line 678 "alfa.y" /* yacc.c:1906  */


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
