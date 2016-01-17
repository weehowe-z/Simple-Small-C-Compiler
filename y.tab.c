/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parse.y" /* yacc.c:339  */

#include <stdio.h>
#include <queue>
#include <vector>
#include "node.h"
extern FILE *yyin;
extern FILE *yyout;
extern int yylineno;
extern char *yytext;
/*Solve warning: implicit declaration*/
int yyerror (const char *msg);
int yylex();
bool printFlag = true;
parseTree pTree;
vector<tokenNode*> vec;

#line 83 "y.tab.c" /* yacc.c:339  */

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
    INT = 258,
    HEXINT = 259,
    ID = 260,
    UNARYOP = 261,
    BINARYOP = 262,
    PLUS = 263,
    MINUS = 264,
    SHIFTOP = 265,
    COMPAREOP = 266,
    EQUALOP = 267,
    BITAND = 268,
    BITXOR = 269,
    BITOR = 270,
    LOGICALAND = 271,
    LOGICALOR = 272,
    BINASSIGNOP = 273,
    TYPE = 274,
    SEMI = 275,
    COMMA = 276,
    DOT = 277,
    ASSIGNOP = 278,
    LP = 279,
    RP = 280,
    LB = 281,
    RB = 282,
    LC = 283,
    RC = 284,
    STRUCT = 285,
    RETURN = 286,
    IF = 287,
    THEN = 288,
    ELSE = 289,
    BREAK = 290,
    CONT = 291,
    FOR = 292,
    NOELSE = 293,
    UNMINUS = 294
  };
#endif
/* Tokens.  */
#define INT 258
#define HEXINT 259
#define ID 260
#define UNARYOP 261
#define BINARYOP 262
#define PLUS 263
#define MINUS 264
#define SHIFTOP 265
#define COMPAREOP 266
#define EQUALOP 267
#define BITAND 268
#define BITXOR 269
#define BITOR 270
#define LOGICALAND 271
#define LOGICALOR 272
#define BINASSIGNOP 273
#define TYPE 274
#define SEMI 275
#define COMMA 276
#define DOT 277
#define ASSIGNOP 278
#define LP 279
#define RP 280
#define LB 281
#define RB 282
#define LC 283
#define RC 284
#define STRUCT 285
#define RETURN 286
#define IF 287
#define THEN 288
#define ELSE 289
#define BREAK 290
#define CONT 291
#define FOR 292
#define NOELSE 293
#define UNMINUS 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 19 "parse.y" /* yacc.c:355  */
 
     int intValue; /* integer value */ 
     char* charValue; /* string value */ 

#line 206 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 221 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   293

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  135

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

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
      35,    36,    37,    38,    39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    62,    62,    71,    82,    91,   105,   118,   126,   139,
     148,   156,   166,   179,   189,   197,   206,   214,   225,   239,
     252,   261,   268,   277,   290,   302,   310,   319,   328,   334,
     345,   357,   372,   380,   390,   397,   410,   419,   428,   439,
     450,   459,   466,   480,   488,   501,   511,   523,   532,   544,
     552,   560,   570,   580,   588,   599,   610,   620,   631,   642,
     652,   662,   672,   682,   692,   702,   713,   719,   727,   739,
     748,   760
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "HEXINT", "ID", "UNARYOP",
  "BINARYOP", "PLUS", "MINUS", "SHIFTOP", "COMPAREOP", "EQUALOP", "BITAND",
  "BITXOR", "BITOR", "LOGICALAND", "LOGICALOR", "BINASSIGNOP", "TYPE",
  "SEMI", "COMMA", "DOT", "ASSIGNOP", "LP", "RP", "LB", "RB", "LC", "RC",
  "STRUCT", "RETURN", "IF", "THEN", "ELSE", "BREAK", "CONT", "FOR",
  "NOELSE", "UNMINUS", "$accept", "PROGRAM", "EXTDEFS", "EXTDEF",
  "EXTVARS", "SPEC", "STSPEC", "OPTTAG", "VAR", "FUNC", "PARAS", "PARA",
  "STMTBLOCK", "STMTS", "STMT", "ESTMT", "DEFS", "DEF", "DECS", "DEC",
  "INIT", "EXP", "FEXP", "ARRS", "ARGS", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

#define YYPACT_NINF -98

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-98)))

#define YYTABLE_NINF -15

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -10,   -98,    -3,    12,   -98,   -10,    13,   -98,    -9,     0,
     -98,   -98,    14,    35,    76,    33,    47,   -10,   -10,   -98,
       1,    97,   -10,   -98,    64,    64,    66,   -10,    64,    78,
      69,   -98,   -98,    60,    54,    54,    54,    54,   -98,   214,
      77,    79,    61,   -98,   -98,    87,    88,   -98,   -98,    82,
     -98,   -10,    54,    54,   -98,   101,   101,   125,   163,    95,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,   120,    54,   -98,   -98,    54,   105,   108,   110,
     121,   -98,   115,    61,   180,   -98,    64,   -98,   124,   104,
     -98,    54,   -98,   101,     4,     4,    15,   241,    72,    65,
     271,   263,   247,   231,   214,   -98,   214,   197,    54,   -98,
     -98,    54,   -98,   -98,   -98,   -98,   -98,   137,   -98,   -98,
     144,   214,   126,   -98,    61,    54,   130,   145,    61,   -98,
      54,   -98,   143,    61,   -98
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    10,    15,     0,     2,     4,     9,    11,    13,     0,
       1,     3,    16,     0,    41,     0,     7,    37,    22,     5,
       0,     0,    37,     6,     9,     0,     0,    37,     0,     0,
      21,    49,    50,    69,     0,     0,     0,     0,    42,    43,
       0,     0,    26,    16,     8,     0,    40,    12,    36,    23,
      19,    22,     0,     0,    47,    51,    53,     0,    71,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    17,    18,     0,     0,     0,     0,
       0,    28,     0,    26,     0,    38,     0,    20,     0,     0,
      45,     0,    44,    52,    55,    54,    56,    57,    58,    61,
      59,    60,    62,    63,    64,    48,    65,     0,     0,    33,
      32,    67,    24,    25,    27,    39,    46,    69,    70,    29,
       0,    66,     0,    68,     0,    67,    35,     0,     0,    30,
      67,    34,     0,     0,    31
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -98,   -98,   177,   -98,   159,     3,   -98,   -98,   171,   -98,
     150,   -98,   201,   135,   -97,   -98,     8,   -98,   147,   -24,
     -98,   -20,   -91,   117,   -39
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    13,    25,     7,     9,    14,    15,
      29,    30,    81,    82,    83,   129,    26,    27,    45,    16,
      38,    84,   122,    54,    59
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,    46,     8,     6,    31,    32,    33,    34,     6,     1,
      35,    60,    10,    88,    55,    56,    57,    58,    12,   -14,
       2,    28,    60,    61,    62,    36,    72,   126,    17,    37,
      42,   131,    58,    89,   127,    48,   134,    72,    18,   132,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   118,   106,    28,    19,   107,    31,    32,    33,
      34,    22,    46,    35,    31,    32,    33,    34,    24,    43,
      35,    58,    60,    61,    62,    63,    64,    65,    36,    60,
      61,    62,    63,    64,    52,    36,    53,    72,   120,    22,
      51,   121,    76,    77,    72,    47,    78,    79,    80,    20,
      40,    41,    21,    50,    74,   121,    75,    85,    21,    86,
     121,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    92,   105,    72,    73,   109,   108,
     110,   117,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,   112,   111,   125,    72,    73,   116,
      90,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    53,   128,   130,    72,    73,   133,   124,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    11,    44,    91,    72,    73,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    49,
     114,    87,    72,    73,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    23,   119,   113,    72,
      73,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,   115,   123,     0,    72,    73,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    60,    61,
      62,    63,     0,    72,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    72,     0,     0,     0,     0,     0,    72,
      60,    61,    62,    63,    64,    65,    66,    67,    60,    61,
      62,    63,    64,    65,    66,    72,     0,     0,     0,     0,
       0,     0,     0,    72
};

static const yytype_int16 yycheck[] =
{
      20,    25,     5,     0,     3,     4,     5,     6,     5,    19,
       9,     7,     0,    52,    34,    35,    36,    37,     5,    28,
      30,    18,     7,     8,     9,    24,    22,   124,    28,    28,
      22,   128,    52,    53,   125,    27,   133,    22,    24,   130,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    91,    73,    51,    20,    76,     3,     4,     5,
       6,    28,    86,     9,     3,     4,     5,     6,    21,     5,
       9,    91,     7,     8,     9,    10,    11,    12,    24,     7,
       8,     9,    10,    11,    24,    24,    26,    22,   108,    28,
      21,   111,    31,    32,    22,    29,    35,    36,    37,    23,
       3,     4,    26,    25,    27,   125,    27,    20,    26,    21,
     130,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    22,    29,     5,    22,    23,    20,    24,
      20,    27,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    29,    24,    20,    22,    23,    25,
      25,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    26,    34,    20,    22,    23,    25,    25,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,     5,    24,    21,    22,    23,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    28,
      20,    51,    22,    23,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    15,    20,    83,    22,
      23,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    86,   117,    -1,    22,    23,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,     7,     8,
       9,    10,    -1,    22,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    22,    -1,    -1,    -1,    -1,    -1,    22,
       7,     8,     9,    10,    11,    12,    13,    14,     7,     8,
       9,    10,    11,    12,    13,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    19,    30,    41,    42,    43,    45,    46,     5,    47,
       0,    42,     5,    44,    48,    49,    59,    28,    24,    20,
      23,    26,    28,    52,    21,    45,    56,    57,    45,    50,
      51,     3,     4,     5,     6,     9,    24,    28,    60,    61,
       3,     4,    56,     5,    44,    58,    59,    29,    56,    48,
      25,    21,    24,    26,    63,    61,    61,    61,    61,    64,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    22,    23,    27,    27,    31,    32,    35,    36,
      37,    52,    53,    54,    61,    20,    21,    50,    64,    61,
      25,    21,    29,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,     5,    61,    61,    24,    20,
      20,    24,    29,    53,    20,    58,    25,    27,    64,    20,
      61,    61,    62,    63,    25,    20,    54,    62,    34,    55,
      20,    54,    62,    25,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    44,    44,    44,
      45,    45,    46,    46,    47,    47,    48,    48,    48,    49,
      50,    50,    50,    51,    52,    53,    53,    54,    54,    54,
      54,    54,    54,    54,    55,    55,    56,    56,    57,    58,
      58,    59,    59,    60,    60,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    62,    62,    63,    63,
      64,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     3,     1,     3,     0,
       1,     1,     5,     2,     1,     0,     1,     4,     4,     4,
       3,     1,     0,     2,     4,     2,     0,     2,     1,     3,
       6,     9,     2,     2,     2,     0,     2,     0,     3,     3,
       1,     1,     3,     1,     3,     3,     4,     2,     3,     1,
       1,     2,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     0,     4,     0,
       3,     1
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
#line 62 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with PROGRAM -> extdefs\n";
								tokenNode* extdefs = vec.back();vec.pop_back();
								tokenNode* program = new tokenNode("PROGRAM",extdefs,NULL);
								pTree.changeRoot(program);
							}
#line 1427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 71 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with extdefs -> extdef extdefs\n";
								tokenNode* extdefs = vec.back();
								vec.pop_back();
								tokenNode* extdef = vec.back();
								extdef->pnextSubling = extdefs;
								vec.pop_back();
								extdefs = new tokenNode("EXTDEFS",extdef,NULL);
								vec.push_back(extdefs);
							}
#line 1442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 82 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with extdefs -> empty\n";
								tokenNode* empty = new tokenNode("ϵ");
								tokenNode* extdefs = new tokenNode("EXTDEFS",empty,NULL);
								vec.push_back(extdefs);
							}
#line 1453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 91 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with extdef -> spec extvars semi\n";
								tokenNode* semi= new tokenNode(";");
								tokenNode* extvars = vec.back();
								vec.pop_back();
								tokenNode* spec = vec.back();
								vec.pop_back();
								extvars->pnextSubling = semi;
								spec->pnextSubling = extvars;
								tokenNode* extdef = new tokenNode("EXTDEF",spec,NULL);
								vec.push_back(extdef);

							}
#line 1471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 105 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with extdef -> spec func stmtblock\n";
								tokenNode* stmtblock= vec.back();vec.pop_back();
								tokenNode* func = vec.back();vec.pop_back();
								tokenNode* spec = vec.back();vec.pop_back();
								func->pnextSubling = stmtblock;
								spec->pnextSubling = func;
								tokenNode* extdef = new tokenNode("EXTDEF",spec,NULL);
								vec.push_back(extdef);	
							}
#line 1486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 118 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with extvars -> dec\n";
								tokenNode* dec = vec.back();
								vec.pop_back();
								tokenNode* extvars = new tokenNode("EXTVARS",dec,NULL);
								vec.push_back(extvars);
							}
#line 1498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 126 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with extvars -> dec comma extvars\n";
								tokenNode* extvars = vec.back();
								vec.pop_back();
								tokenNode* comma = new tokenNode(",");
								tokenNode* dec = vec.back();
								vec.pop_back();
								dec->pnextSubling = comma;
								comma->pnextSubling = extvars;
								extvars = new tokenNode("EXTVARS",dec,NULL);
								vec.push_back(extvars);
							}
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 139 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with extvars -> empty\n";
								tokenNode* empty = new tokenNode("ϵ");
								tokenNode* extvars = new tokenNode("EXTVARS",empty,NULL);
								vec.push_back(extvars);
							}
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 148 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with spec -> type\n";
								tokenNode* typeVal = new tokenNode((yyvsp[0].charValue));
								tokenNode* type = new tokenNode("TYPE",typeVal,NULL);
								tokenNode* spec = new tokenNode("SPEC",type,NULL);
								vec.push_back(spec);
							}
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 156 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with spec -> stspec\n";
								tokenNode* stspec = vec.back();
								vec.pop_back();
								tokenNode* spec = new tokenNode("SPEC",stspec,NULL);
								vec.push_back(spec);
							}
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 166 "parse.y" /* yacc.c:1646  */
    {
										//cout<<"deal with stspec -> struct opttag lc defs rc\n";
										tokenNode* rc = new tokenNode("}");
										tokenNode* defs = vec.back();vec.pop_back();
										defs->pnextSubling = rc;
										tokenNode* lc = new tokenNode("{",NULL,defs);
										tokenNode* opttag = vec.back();vec.pop_back();
										opttag->pnextSubling = lc;
										tokenNode* structToken = new tokenNode("STRUCT",NULL,opttag);
										tokenNode* stspec = new tokenNode("STSPEC",structToken,NULL);
										vec.push_back(stspec);
									}
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 179 "parse.y" /* yacc.c:1646  */
    {
										//cout<<"deal with stspec -> struct id\n";					
										tokenNode* idval= new tokenNode((yyvsp[0].charValue));
										tokenNode* id = new tokenNode("ID",idval,NULL);
										tokenNode* structToken = new tokenNode("STRUCT",NULL,id);
										tokenNode* stspec = new tokenNode("STSPEC",structToken,NULL);
										vec.push_back(stspec);										
									}
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 189 "parse.y" /* yacc.c:1646  */
    {
										//cout<<"deal with opttag -> id\n";
										tokenNode* idval= new tokenNode((yyvsp[0].charValue));
										tokenNode* id = new tokenNode("ID",idval,NULL);
										tokenNode* opttag = new tokenNode("OPTTAG",id,NULL);
										vec.push_back(opttag);
									}
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 197 "parse.y" /* yacc.c:1646  */
    {
										//cout<<"deal with opttag -> empty\n";
										tokenNode* empty = new tokenNode("ϵ");
										tokenNode* opttag = new tokenNode("OPTTAG",empty,NULL);
										vec.push_back(opttag);
									}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 206 "parse.y" /* yacc.c:1646  */
    {
										//cout<<"deal with var -> id \n";
										tokenNode* idval= new tokenNode((yyvsp[0].charValue));
										tokenNode* id = new tokenNode("ID",idval,NULL);
										tokenNode* var = new tokenNode("VAR",id,NULL);
										vec.push_back(var);
									}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 214 "parse.y" /* yacc.c:1646  */
    {
										//cout<<"deal with var -> var lb int rb\n";
										tokenNode* rb = new tokenNode("]");
										tokenNode* integer = new tokenNode((yyvsp[-1].intValue),NULL,rb);
										tokenNode* lb = new tokenNode("[",NULL,integer);
										tokenNode* var = vec.back();vec.pop_back();
										var->pnextSubling = lb;
										var = new tokenNode("VAR",var,NULL);
										vec.push_back(var);
									}
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 225 "parse.y" /* yacc.c:1646  */
    {
										//cout<<"deal with var -> var lb hexint rb\n";
										tokenNode* rb = new tokenNode("]");
										tokenNode* integer = new tokenNode((yyvsp[-1].charValue),NULL,rb);
										tokenNode* lb = new tokenNode("[",NULL,integer);
										tokenNode* var = vec.back();vec.pop_back();
										var->pnextSubling = lb;
										var = new tokenNode("VAR",var,NULL);
										vec.push_back(var);
									}
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 239 "parse.y" /* yacc.c:1646  */
    {
										//cout<<"deal with func -> id lp paras rp\n";
										tokenNode* rp = new tokenNode(")");
										tokenNode* paras = vec.back();vec.pop_back();paras->pnextSubling = rp;
										tokenNode* lp = new tokenNode("(",NULL,paras);
										tokenNode* idval= new tokenNode((yyvsp[-3].charValue));
										tokenNode* id = new tokenNode("ID",idval,lp);
										tokenNode* func = new tokenNode("FUNC",id,NULL);
										vec.push_back(func);
									}
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 252 "parse.y" /* yacc.c:1646  */
    {
										//cout<<"deal with paras -> para comma paras\n";
										tokenNode* paras = vec.back();vec.pop_back();
										tokenNode* comma = new tokenNode(",",NULL,paras);
										tokenNode* para = vec.back();vec.pop_back();para->pnextSubling = comma;
										paras = new tokenNode("PARAS",para,NULL);
										vec.push_back(paras);
									}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 261 "parse.y" /* yacc.c:1646  */
    {
										//cout<<"deal with paras -> para\n";
										tokenNode* para = vec.back();
										vec.pop_back();
										tokenNode* paras = new tokenNode("PARAS",para,NULL);
										vec.push_back(paras);
									}
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 268 "parse.y" /* yacc.c:1646  */
    {
										//cout<<"deal with paras -> empty\n";
										tokenNode* empty = new tokenNode("ϵ");
										tokenNode* paras = new tokenNode("PARAS",empty,NULL);
										vec.push_back(paras);									
									}
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 277 "parse.y" /* yacc.c:1646  */
    {
										//cout<<"deal with para -> spec var\n";
										tokenNode* var = vec.back();
										vec.pop_back();
										tokenNode* spec = vec.back();
										vec.pop_back();
										spec->pnextSubling = var;
										tokenNode* para = new tokenNode("PARA",spec,NULL);
										vec.push_back(para);
									}
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 290 "parse.y" /* yacc.c:1646  */
    {
										//cout<<"deal with stmtblock -> lc defs stmts rc\n";
										tokenNode* rc = new tokenNode("}");
										tokenNode* stmts = vec.back();vec.pop_back();stmts->pnextSubling = rc;
										tokenNode* defs = vec.back();vec.pop_back();defs->pnextSubling = stmts;
										tokenNode* lc = new tokenNode("{",NULL,defs);
										tokenNode* stmtblock = new tokenNode("STMTBLOCK",lc,NULL);
										vec.push_back(stmtblock);
									}
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 302 "parse.y" /* yacc.c:1646  */
    {
										//cout<<"deal with stmts -> stmt stmts\n";
										tokenNode* stmts = vec.back();vec.pop_back();
										tokenNode* stmt = vec.back();vec.pop_back();stmt->pnextSubling = stmts;
										stmts = new tokenNode("STMTS",stmt,NULL);
										vec.push_back(stmts);
									}
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 310 "parse.y" /* yacc.c:1646  */
    {
										//cout<<"deal with stmts -> empty\n";
										tokenNode* empty = new tokenNode("ϵ");
										tokenNode* stmts = new tokenNode("STMTS",empty,NULL);
										vec.push_back(stmts);										
									}
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 319 "parse.y" /* yacc.c:1646  */
    {
															//cout<<"deal with stmt -> exp semi\n";
															tokenNode* semi = new tokenNode(";");
															tokenNode* exp = vec.back();
															vec.pop_back();
															exp->pnextSubling = semi;
															tokenNode* stmt = new tokenNode("STMT",exp,NULL);
															vec.push_back(stmt);
														}
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 328 "parse.y" /* yacc.c:1646  */
    {
															//cout<<"deal with stmt -> stmtblock\n";
															tokenNode* stmtblock = vec.back();vec.pop_back();
															tokenNode* stmt = new tokenNode("STMT",stmtblock,NULL);
															vec.push_back(stmt);
														}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 334 "parse.y" /* yacc.c:1646  */
    {
															//cout<<"deal with stmt -> stmtblock\n";
															tokenNode* semi = new tokenNode(";");
															tokenNode* exp = vec.back();
															vec.pop_back();
															exp->pnextSubling = semi;
															tokenNode* returnToken = new tokenNode("RETURN",NULL,exp);
															tokenNode* stmt = new tokenNode("STMT",returnToken,NULL);
															vec.push_back(stmt);
														}
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 345 "parse.y" /* yacc.c:1646  */
    {
															//cout<<"deal with stmt -> if lp exp rp stmt estmt\n";
															tokenNode* estmt = vec.back();vec.pop_back();
															tokenNode* stmt = vec.back();vec.pop_back();stmt->pnextSubling = estmt;
															tokenNode* rp = new tokenNode(")",NULL,stmt);
															tokenNode* exp = vec.back();vec.pop_back();exp->pnextSubling = rp;
															tokenNode* lp = new tokenNode("(",NULL,exp);
															tokenNode* ifToken = new tokenNode("IF",NULL,lp);
															stmt = new tokenNode("STMT",ifToken,NULL);
															vec.push_back(stmt);
														}
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 357 "parse.y" /* yacc.c:1646  */
    {
															//cout<<"deal with stmt -> for loop \n";
															tokenNode* stmt = vec.back();vec.pop_back();
															tokenNode* rp = new tokenNode(")",NULL,stmt);
															tokenNode* fexp = vec.back();vec.pop_back();fexp->pnextSubling = rp;
															tokenNode* semi = new tokenNode(";",NULL,fexp);
															fexp = vec.back();vec.pop_back();fexp->pnextSubling = semi;
															semi = new tokenNode(";",NULL,fexp);
															fexp = vec.back();vec.pop_back();fexp->pnextSubling = semi;
															tokenNode* lp = new tokenNode("(",NULL,fexp);
															tokenNode* forToken = new tokenNode("FOR",NULL,lp);
															stmt = new tokenNode("STMT",forToken,NULL);
															vec.push_back(stmt);
														}
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 372 "parse.y" /* yacc.c:1646  */
    {
															//cout<<"deal with stmt -> cont semi\n";
															tokenNode* semi = new tokenNode(";");
															tokenNode* cont = new tokenNode("CONTINUE",NULL,semi);
															tokenNode* stmt = new tokenNode("STMT",NULL,cont);
															vec.push_back(stmt);
														}
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 380 "parse.y" /* yacc.c:1646  */
    {
															//cout<<"deal with stmt -> break semi\n";
															tokenNode* semi = new tokenNode(";");
															tokenNode* breakToken = new tokenNode("BREAK",NULL,semi);
															tokenNode* stmt = new tokenNode("STMT",NULL,breakToken);
															vec.push_back(stmt);
														}
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 390 "parse.y" /* yacc.c:1646  */
    {
															//cout<<"deal with estmt -> else stmt\n";
															tokenNode* stmt = vec.back();vec.pop_back();
															tokenNode* elseToken = new tokenNode("ELSE",NULL,stmt);
															tokenNode* estmt = new tokenNode("ESTMT",elseToken,NULL);
															vec.push_back(estmt);
														}
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 397 "parse.y" /* yacc.c:1646  */
    {
															//cout<<"deal with estmt -> empty\n";
															tokenNode* empty = new tokenNode("ϵ");
															tokenNode* estmt = new tokenNode("ESTMT",empty,NULL);
															vec.push_back(estmt);
														}
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 410 "parse.y" /* yacc.c:1646  */
    {
															//cout<<"deal with defs -> def defs\n";
															tokenNode* defs = vec.back();vec.pop_back();
															tokenNode* def = vec.back();vec.pop_back();
															def->pnextSubling = defs;
															defs = new tokenNode("DEFS",def,NULL);
															vec.push_back(defs);
														}
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 419 "parse.y" /* yacc.c:1646  */
    {
															//cout<<"deal with defs -> empty\n";
															tokenNode* empty = new tokenNode("ϵ");
															tokenNode* defs = new tokenNode("DEFS",empty,NULL);
															vec.push_back(defs);										
														}
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 428 "parse.y" /* yacc.c:1646  */
    {
															//cout<<"deal with def -> spec decs semi\n";
															tokenNode* semi = new tokenNode(";");
															tokenNode* decs = vec.back();vec.pop_back();decs->pnextSubling = semi;
															tokenNode* spec = vec.back();vec.pop_back();spec->pnextSubling = decs;
															tokenNode* def = new tokenNode("DEF",spec,NULL);
															vec.push_back(def);
														}
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 439 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with decs -> dec comma decs\n";
								tokenNode* decs = vec.back();
								vec.pop_back();
								tokenNode* comma = new tokenNode(",",NULL,decs);
								tokenNode* dec = vec.back();
								vec.pop_back();
								dec->pnextSubling = comma;
								decs = new tokenNode("DECS",dec,NULL);
								vec.push_back(decs);
							}
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 450 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with decs -> dec\n";
								tokenNode* dec = vec.back();vec.pop_back();
								tokenNode* decs = new tokenNode("DECS",dec,NULL);
								vec.push_back(decs);								
							}
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 459 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with dec -> var\n";
								tokenNode* var = vec.back();vec.pop_back();
								tokenNode* dec = new tokenNode("DEC",var,NULL);
								vec.push_back(dec);
							}
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 466 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with dec -> var assignop init\n";
								tokenNode* init = vec.back();
								vec.pop_back();
								tokenNode* assignop = new tokenNode("=",NULL,init);
								tokenNode* var = vec.back();
								vec.pop_back();
								var->pnextSubling = assignop;
								tokenNode* dec = new tokenNode("DEC",var,NULL);
								vec.push_back(dec);
							}
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 480 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with init -> exp\n";
								tokenNode* exp = vec.back();
								vec.pop_back();
								tokenNode* init = new tokenNode("INIT",exp,NULL);
								vec.push_back(init);
		                    }
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 488 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with init -> lc args rc\n";
								tokenNode* rc = new tokenNode("}");
								tokenNode* args = vec.back();
								vec.pop_back();
								args->pnextSubling = rc;
								tokenNode* lc = new tokenNode("{",NULL,args);
								tokenNode* init = new tokenNode("INIT",lc,NULL);
								vec.push_back(init);
							}
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 501 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with exp -> lp exp rp\n";
								tokenNode* rp = new tokenNode(")");
								tokenNode* exp = vec.back();
								vec.pop_back();
								exp->pnextSubling = rp;
								tokenNode* lp = new tokenNode("(",NULL,exp);
								exp = new tokenNode("EXP",lp,NULL);
								vec.push_back(exp);
							}
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 511 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with exp -> id lp args rp\n";
								tokenNode* rp = new tokenNode(")");
								tokenNode* args = vec.back();
								vec.pop_back();
								args->pnextSubling = rp;
								tokenNode* lp = new tokenNode("(",NULL,args);
								tokenNode* idval= new tokenNode((yyvsp[-3].charValue));
								tokenNode* id = new tokenNode("ID",idval,lp);
								tokenNode* exp = new tokenNode("EXP",id,NULL);
								vec.push_back(exp);						
							}
#line 2020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 523 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with exp -> id arrs\n";
								tokenNode* arrs = vec.back();
								vec.pop_back();
								tokenNode* idval= new tokenNode((yyvsp[-1].charValue));
								tokenNode* id = new tokenNode("ID",idval,arrs);
								tokenNode* exp = new tokenNode("EXP",id,NULL);
								vec.push_back(exp);
							}
#line 2034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 532 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with exp -> exp dot id\n";
								tokenNode* idval= new tokenNode((yyvsp[0].charValue));
								tokenNode* id = new tokenNode("ID",idval,NULL);
								tokenNode* dot = new tokenNode(".",NULL,id);
								tokenNode* exp = vec.back();
								vec.pop_back();
								exp->pnextSubling = dot;
								exp = new tokenNode("EXP",exp,NULL);
								vec.push_back(exp);								
							}
#line 2050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 544 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with exp -> int\n";
								tokenNode* intVal = new tokenNode((yyvsp[0].intValue));
								tokenNode* intToken = new tokenNode("INT",intVal,NULL);
								tokenNode* exp = new tokenNode("EXP",intToken,NULL);
								vec.push_back(exp);								
							}
#line 2062 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 552 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with exp -> HEXint\n";
								tokenNode* intVal = new tokenNode((yyvsp[0].charValue));
								tokenNode* intToken = new tokenNode("INT",intVal,NULL);
								tokenNode* exp = new tokenNode("EXP",intToken,NULL);
								vec.push_back(exp);								
							}
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 560 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with exp -> unaryop exp\n";
								tokenNode* exp = vec.back();
								vec.pop_back();
								tokenNode* unaryopVal = new tokenNode((yyvsp[-1].charValue));
								tokenNode* unaryop = new tokenNode("UNARYOP",unaryopVal,exp);
								exp = new tokenNode("EXP",unaryop,NULL);
								vec.push_back(exp);
	                        }
#line 2088 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 570 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with exp -> exp BINARYOP exp\n";
								tokenNode* exp = vec.back();vec.pop_back();
								tokenNode* binaryop = new tokenNode((yyvsp[-1].charValue),NULL,exp);
								exp = vec.back();vec.pop_back();
								exp->pnextSubling = binaryop;
								exp = new tokenNode("EXP",exp,NULL);
								vec.push_back(exp);	
							}
#line 2102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 580 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with exp -> MINUS exp\n";
								tokenNode* exp = vec.back();vec.pop_back();
								tokenNode* binaryop = new tokenNode((yyvsp[-1].charValue),NULL,exp);
								exp = new tokenNode("EXP",binaryop,NULL);
								vec.push_back(exp);	
							}
#line 2114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 588 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with exp -> exp MINUS exp\n";
								tokenNode* exp = vec.back();vec.pop_back();
								tokenNode* binaryop = new tokenNode((yyvsp[-1].charValue),NULL,exp);
								exp = vec.back();vec.pop_back();
								exp->pnextSubling = binaryop;
								exp = new tokenNode("EXP",exp,NULL);
								vec.push_back(exp);	
							}
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 599 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with exp -> exp PLUS exp\n";
								tokenNode* exp = vec.back();vec.pop_back();
								tokenNode* binaryop = new tokenNode((yyvsp[-1].charValue),NULL,exp);
								exp = vec.back();vec.pop_back();
								exp->pnextSubling = binaryop;
								exp = new tokenNode("EXP",exp,NULL);
								vec.push_back(exp);	
							}
#line 2142 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 610 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with exp -> exp SHIFTOP exp\n";
								tokenNode* exp = vec.back();vec.pop_back();
								tokenNode* binaryop = new tokenNode((yyvsp[-1].charValue),NULL,exp);
								exp = vec.back();vec.pop_back();
								exp->pnextSubling = binaryop;
								exp = new tokenNode("EXP",exp,NULL);
								vec.push_back(exp);	
							}
#line 2156 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 620 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with exp -> exp COMPAREOP exp\n";
								tokenNode* exp = vec.back();vec.pop_back();
								tokenNode* binaryop = new tokenNode((yyvsp[-1].charValue),NULL,exp);
								exp = vec.back();vec.pop_back();
								exp->pnextSubling = binaryop;
								exp = new tokenNode("EXP",exp,NULL);
								vec.push_back(exp);	
							}
#line 2170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 631 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with exp -> exp EQUALOP exp\n";
								tokenNode* exp = vec.back();vec.pop_back();
								tokenNode* binaryop = new tokenNode((yyvsp[-1].charValue),NULL,exp);
								exp = vec.back();vec.pop_back();
								exp->pnextSubling = binaryop;
								exp = new tokenNode("EXP",exp,NULL);
								vec.push_back(exp);	
							}
#line 2184 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 642 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with exp -> exp BITXOR exp\n";
								tokenNode* exp = vec.back();vec.pop_back();
								tokenNode* binaryop = new tokenNode((yyvsp[-1].charValue),NULL,exp);
								exp = vec.back();vec.pop_back();
								exp->pnextSubling = binaryop;
								exp = new tokenNode("EXP",exp,NULL);
								vec.push_back(exp);	
							}
#line 2198 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 652 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with exp -> exp BITOR exp\n";
								tokenNode* exp = vec.back();vec.pop_back();
								tokenNode* binaryop = new tokenNode((yyvsp[-1].charValue),NULL,exp);
								exp = vec.back();vec.pop_back();
								exp->pnextSubling = binaryop;
								exp = new tokenNode("EXP",exp,NULL);
								vec.push_back(exp);	
							}
#line 2212 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 662 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with exp -> exp BITAND exp\n";
								tokenNode* exp = vec.back();vec.pop_back();
								tokenNode* binaryop = new tokenNode((yyvsp[-1].charValue),NULL,exp);
								exp = vec.back();vec.pop_back();
								exp->pnextSubling = binaryop;
								exp = new tokenNode("EXP",exp,NULL);
								vec.push_back(exp);	
							}
#line 2226 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 672 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with exp -> exp LOGICALAND exp\n";
								tokenNode* exp = vec.back();vec.pop_back();
								tokenNode* binaryop = new tokenNode((yyvsp[-1].charValue),NULL,exp);
								exp = vec.back();vec.pop_back();
								exp->pnextSubling = binaryop;
								exp = new tokenNode("EXP",exp,NULL);
								vec.push_back(exp);		
	                        }
#line 2240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 682 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with exp -> exp LOGICALOR exp\n";
								tokenNode* exp = vec.back();vec.pop_back();
								tokenNode* binaryop = new tokenNode((yyvsp[-1].charValue),NULL,exp);
								exp = vec.back();vec.pop_back();
								exp->pnextSubling = binaryop;
								exp = new tokenNode("EXP",exp,NULL);
								vec.push_back(exp);		
	                        }
#line 2254 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 692 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with exp -> exp BINASSIGNOP exp\n";
								tokenNode* exp = vec.back();vec.pop_back();
								tokenNode* binaryop = new tokenNode((yyvsp[-1].charValue),NULL,exp);
								exp = vec.back();vec.pop_back();
								exp->pnextSubling = binaryop;
								exp = new tokenNode("EXP",exp,NULL);
								vec.push_back(exp);		
	                        }
#line 2268 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 702 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with exp -> exp assignop exp\n";
								tokenNode* exp = vec.back();vec.pop_back();
								tokenNode* assignop = new tokenNode("=",NULL,exp);
								exp = vec.back();vec.pop_back();
								exp->pnextSubling = assignop;
								exp = new tokenNode("EXP",exp,NULL);
								vec.push_back(exp);
							}
#line 2282 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 713 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with fexp -> exp\n";
								tokenNode* exp = vec.back();vec.pop_back();
								tokenNode* fexp = new tokenNode("FEXP",exp,NULL);
								vec.push_back(fexp);
							}
#line 2293 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 719 "parse.y" /* yacc.c:1646  */
    {   //cout<<"deal with fexp -> empty\n";
								tokenNode* empty = new tokenNode("ϵ");
								tokenNode* fexp = new tokenNode("FEXP",empty,NULL);
								vec.push_back(fexp);
							}
#line 2303 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 727 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with arrs -> lb exp rb arrs\n";
								tokenNode* arrs = vec.back();
								vec.pop_back();
								tokenNode* rb = new tokenNode("]",NULL,arrs);
								tokenNode* exp = vec.back();
								vec.pop_back();
								exp->pnextSubling = rb;
								tokenNode* lb = new tokenNode("[",NULL,exp);
								arrs = new tokenNode("ARRS",lb,NULL);
								vec.push_back(arrs);
							}
#line 2320 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 739 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with arrs -> empty\n";
								tokenNode* empty = new tokenNode("ϵ");
								tokenNode* arrs = new tokenNode("ARRS",empty,NULL);
								vec.push_back(arrs);						
							}
#line 2331 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 748 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with args -> exp comma args\n";
								tokenNode* args = vec.back();
								vec.pop_back();
								tokenNode* comma = new tokenNode(",",NULL,args);
								tokenNode* exp = vec.back();
								vec.pop_back();
								exp->pnextSubling = comma;							
								args = new tokenNode("ARGS",exp,NULL);
								vec.push_back(args);
							}
#line 2347 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 760 "parse.y" /* yacc.c:1646  */
    {
								//cout<<"deal with args -> exp\n";
								tokenNode* exp = vec.back();
								vec.pop_back();
								tokenNode* args = new tokenNode("ARGS",exp,NULL);
								vec.push_back(args);
							}
#line 2359 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2363 "y.tab.c" /* yacc.c:1646  */
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
#line 770 "parse.y" /* yacc.c:1906  */



int main (int argc, char const *argv[]) {

	if (argc == 1){
		fprintf(stderr, "%s\n", "YACC: please write your code in the shell. input CTRL-D to exit.");
		fprintf(stderr, "%s\n", "YACC: or you can specify the source code path. \nexample --> $./a.out  inputFile outputFile\n");
		yyparse();
		if (printFlag) {
			pTree.printQueue(yyout);
		}
		return 0;
	}

	else if (argc == 2){
		FILE *fin = fopen(argv[1],"r");
		if (!fin) { 
			return fprintf (stderr, "YACC: Input file %s does not exist!\n", argv[1]);
		}
		yyin = fin;
		while(!feof(yyin)){
			yyparse();
		}
		if (printFlag) {
			pTree.printQueue(yyout);
		}
		fclose(fin);
	}

	else if (argc == 3){
		FILE *fin = fopen(argv[1], "r");
		FILE *fout = fopen(argv[2],"w");
		if (!fin) {
			return fprintf (stderr, "YACC: Input file %s does not exist!\n", argv[1]);
		}
		if (!fout) {
			return fprintf (stderr, "YACC: Output file %s does not exist!\n", argv[2]);
		}
		yyin = fin;
		yyout = fout;
		while (!feof(yyin)){
			yyparse();
		}
		if (printFlag) {
			pTree.printQueue(yyout);
		}
		fclose(fin);
		fclose(fout);
	}

	else {
		fprintf(stderr, "%s\n" , "YACC: Wrong fromat.");
		fprintf(stderr, "%s\n" , "YACC: or you can specify the source code path. \nexample --> $./a.out  inputFile outputFile\n");
	}
	return 0;
}

/* Added because panther doesn't have liby.a installed. */
int yyerror (const char *msg) {
	printFlag = false;
	fprintf(stderr, "YACC: %s at line %d\n", msg,yylineno);
	fprintf(stderr, "YACC: does not expect %s\n",yytext);
	//fprintf(yyout, "YACC: %s at line %d\n", msg,yylineno);
	//fprintf(yyout, "YACC: does not expect %s\n",yytext);
	return -1;
}
