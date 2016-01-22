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
#line 1 "parser.y" /* yacc.c:339  */

#include "header.h"
#include "lex.yy.c"
#include "syntax_tree.h"
#include "Node.h"

using namespace std;

extern int yylineno;
/*Solve warning: implicit declaration*/
int yyerror(const char* msg);
TreeNode * root;


#line 81 "y.tab.c" /* yacc.c:339  */

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
    ADD_ASSIGN = 258,
    SUB_ASSIGN = 259,
    MUL_ASSIGN = 260,
    DIV_ASSIGN = 261,
    AND_ASSIGN = 262,
    MOD_ASSIGN = 263,
    XOR_ASSIGN = 264,
    OR_ASSIGN = 265,
    RIGHT_OP = 266,
    LEFT_OP = 267,
    AND_OP = 268,
    OR_OP = 269,
    EQ_OP = 270,
    NE_OP = 271,
    RIGHT_ASSIGN = 272,
    LEFT_ASSIGN = 273,
    LOG_NOT_OP = 274,
    BIT_NOT_OP = 275,
    READ = 276,
    WRITE = 277,
    INT = 278,
    ID = 279,
    SEMI = 280,
    COMMA = 281,
    TYPE = 282,
    LP = 283,
    RP = 284,
    LB = 285,
    RB = 286,
    LC = 287,
    RC = 288,
    STRUCT = 289,
    RETURN = 290,
    IF = 291,
    ELSE = 292,
    BREAK = 293,
    CONT = 294,
    FOR = 295,
    DOT = 296,
    ASSIGN = 297,
    IF_NO_ELSE = 298,
    ELSE_AFTER_IF = 299,
    BIT_OR_OP = 300,
    BIT_XOR_OP = 301,
    BIT_AND_OP = 302,
    GE_OP = 303,
    LE_OP = 304,
    GT_OP = 305,
    LT_OP = 306,
    PLUS_OP = 307,
    MINUS_OP = 308,
    PRODUCT_OP = 309,
    DIV_OP = 310,
    MOD_OP = 311,
    INC_OP = 312,
    DEC_OP = 313,
    UNARY = 314
  };
#endif
/* Tokens.  */
#define ADD_ASSIGN 258
#define SUB_ASSIGN 259
#define MUL_ASSIGN 260
#define DIV_ASSIGN 261
#define AND_ASSIGN 262
#define MOD_ASSIGN 263
#define XOR_ASSIGN 264
#define OR_ASSIGN 265
#define RIGHT_OP 266
#define LEFT_OP 267
#define AND_OP 268
#define OR_OP 269
#define EQ_OP 270
#define NE_OP 271
#define RIGHT_ASSIGN 272
#define LEFT_ASSIGN 273
#define LOG_NOT_OP 274
#define BIT_NOT_OP 275
#define READ 276
#define WRITE 277
#define INT 278
#define ID 279
#define SEMI 280
#define COMMA 281
#define TYPE 282
#define LP 283
#define RP 284
#define LB 285
#define RB 286
#define LC 287
#define RC 288
#define STRUCT 289
#define RETURN 290
#define IF 291
#define ELSE 292
#define BREAK 293
#define CONT 294
#define FOR 295
#define DOT 296
#define ASSIGN 297
#define IF_NO_ELSE 298
#define ELSE_AFTER_IF 299
#define BIT_OR_OP 300
#define BIT_XOR_OP 301
#define BIT_AND_OP 302
#define GE_OP 303
#define LE_OP 304
#define GT_OP 305
#define LT_OP 306
#define PLUS_OP 307
#define MINUS_OP 308
#define PRODUCT_OP 309
#define DIV_OP 310
#define MOD_OP 311
#define INC_OP 312
#define DEC_OP 313
#define UNARY 314

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 16 "parser.y" /* yacc.c:355  */

    char* string;
    TreeNode* node;

#line 244 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 259 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   686

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  197

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   314

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    49,    49,    55,    59,    64,    68,    71,    77,    78,
      79,    82,    83,    84,    85,    86,    89,    90,    91,    94,
      98,    99,   100,   103,   106,   107,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   122,   123,   124,   127,
     128,   131,   132,   135,   136,   137,   138,   141,   142,   145,
     146,   149,   150,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   190,   191,
     194,   195,   199,   200,   201,   202,   203,   204
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN",
  "DIV_ASSIGN", "AND_ASSIGN", "MOD_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "RIGHT_OP", "LEFT_OP", "AND_OP", "OR_OP", "EQ_OP", "NE_OP",
  "RIGHT_ASSIGN", "LEFT_ASSIGN", "LOG_NOT_OP", "BIT_NOT_OP", "READ",
  "WRITE", "INT", "ID", "SEMI", "COMMA", "TYPE", "LP", "RP", "LB", "RB",
  "LC", "RC", "STRUCT", "RETURN", "IF", "ELSE", "BREAK", "CONT", "FOR",
  "DOT", "ASSIGN", "IF_NO_ELSE", "ELSE_AFTER_IF", "BIT_OR_OP",
  "BIT_XOR_OP", "BIT_AND_OP", "GE_OP", "LE_OP", "GT_OP", "LT_OP",
  "PLUS_OP", "MINUS_OP", "PRODUCT_OP", "DIV_OP", "MOD_OP", "INC_OP",
  "DEC_OP", "UNARY", "$accept", "PROGRAM", "EXTDEFS", "EXTDEF", "SEXTVARS",
  "EXTVARS", "STSPEC", "FUNC", "PARAS", "STMTBLOCK", "STMTS", "STMT",
  "DEFS", "SDEFS", "SDECS", "DECS", "VAR", "INIT", "EXP", "EXPS", "ARRS",
  "ARGS", "UNARYOP", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
};
# endif

#define YYPACT_NINF -176

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-176)))

#define YYTABLE_NINF -53

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -2,    -1,    -6,    22,  -176,    -2,    28,    32,    41,    42,
     -14,    44,    50,  -176,  -176,    52,    54,    53,    58,  -176,
       0,  -176,    59,   614,    50,    64,    49,    28,  -176,    65,
      61,    62,    59,    28,   565,    93,  -176,  -176,  -176,  -176,
     -11,   628,   628,  -176,  -176,  -176,  -176,    98,   527,   628,
      92,   100,   102,  -176,  -176,   103,  -176,  -176,   106,   -13,
     109,   108,   110,   628,   111,   112,   115,   113,  -176,    95,
     565,   117,   527,   628,   628,   123,  -176,   149,  -176,   203,
     135,    59,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,   628,   628,   628,   628,   628,   628,   628,   628,   628,
     628,  -176,  -176,    64,    50,    53,     0,    59,   614,     0,
     628,   628,   257,   628,  -176,  -176,   628,  -176,  -176,  -176,
     140,   311,  -176,  -176,   628,  -176,  -176,   527,   527,   527,
     527,   527,   527,   527,   527,    17,    17,   285,    -5,   235,
     235,   527,   527,   527,   133,   501,   336,     3,     3,     3,
       3,   -18,   -18,  -176,  -176,  -176,  -176,  -176,  -176,  -176,
    -176,   144,  -176,   365,   419,  -176,   473,   146,  -176,  -176,
    -176,    59,   147,   148,   592,   628,  -176,  -176,  -176,   137,
     150,   592,   628,  -176,   161,   592,  -176
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    15,     0,     0,     2,     4,    10,    47,     0,     0,
      11,    18,    40,     1,     3,     8,     0,    22,     0,     5,
      38,     7,    15,     0,    40,     0,     0,    10,     6,     0,
       0,     0,     0,    10,    25,    47,    12,    95,    94,    87,
      89,     0,    52,    92,    93,    96,    97,    13,    49,     0,
       0,    42,     0,    17,     9,    21,    19,    48,     0,    43,
       0,     0,     0,     0,     0,     0,     0,     0,    27,     0,
      25,     0,    51,    52,     0,     0,    85,     0,    91,    51,
       0,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    82,    16,     0,    40,    22,    38,     0,     0,    38,
       0,     0,     0,     0,    33,    32,    52,    23,    24,    26,
       0,     0,    86,    83,    52,    50,    14,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    53,    54,    57,
      58,    70,    71,    59,    81,    80,    74,    56,    55,    79,
      78,    72,    73,    75,    76,    77,    41,    39,    20,    36,
      44,    46,    37,     0,     0,    28,     0,     0,    84,    88,
      90,     0,     0,     0,    52,    52,    45,    34,    35,    29,
       0,    52,    52,    30,     0,    52,    31
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -176,  -176,   171,  -176,     6,   -17,    63,  -176,    77,   168,
     152,  -175,   -95,   -23,    80,  -114,   -30,   105,   -42,    12,
    -176,   -69,  -176
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    16,     8,    33,     9,    30,    68,
      69,    70,    34,    26,    52,    58,    10,    47,    71,    72,
      76,    80,    49
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      78,    50,    59,   170,   130,    36,    90,    91,    92,   189,
      94,    95,    22,   117,    90,    91,   193,    73,    11,    74,
     196,   169,    13,     7,   172,     1,    12,    32,    23,   118,
      75,    78,     2,    54,     2,    48,   108,   109,   110,    60,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,    15,    77,    79,   106,   107,   108,   109,   110,
      17,   111,    18,     6,   136,   180,    19,   186,     6,   106,
     107,   108,   109,   110,    20,   122,    24,    25,    27,    28,
      29,    31,    53,    35,   177,    79,   131,    59,    51,    55,
      56,   167,    78,    57,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    18,    81,   112,   113,   114,   127,   115,
      48,   116,   173,   174,   119,   176,   120,   124,   121,   123,
     125,   126,   129,   190,    90,    91,    79,   132,    94,    95,
     194,    59,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,   135,   178,
     181,   185,   187,   188,   191,   192,    14,    21,   133,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     195,    98,   168,   166,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,   128,   171,     0,     0,     0,     0,     0,   134,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    98,    90,    91,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,   175,   102,   103,   104,   105,   106,   107,   108,
     109,   110,     0,     0,     0,     0,    90,    91,     0,    98,
      94,    95,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   179,     0,     0,     0,     0,    90,    91,     0,
       0,    94,    95,    98,     0,     0,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,   102,   103,   104,   105,   106,   107,
     108,   109,   110,     0,   182,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    98,     0,     0,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   183,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    98,     0,     0,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   184,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    90,    91,     0,    98,    94,    95,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    98,
       0,     0,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,    37,    38,    61,    62,    39,    40,
     -52,     0,     0,    41,     0,     0,     0,    20,     0,     0,
      63,    64,     0,    65,    66,    67,     0,     0,     0,     0,
       0,    37,    38,    61,    62,    39,    40,    43,    44,     0,
      41,     0,    45,    46,    20,     0,     0,    63,    64,     0,
      65,    66,    67,    37,    38,     0,     0,    39,    40,     0,
       0,     0,    41,     0,    43,    44,    42,    37,    38,    45,
      46,    39,    40,     0,     0,     0,    41,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    43,    44,     0,     0,
       0,    45,    46,     0,     0,     0,     0,     0,     0,     0,
      43,    44,     0,     0,     0,    45,    46
};

static const yytype_int16 yycheck[] =
{
      42,    24,    32,   117,    73,    22,    11,    12,    13,   184,
      15,    16,    26,    26,    11,    12,   191,    28,    24,    30,
     195,   116,     0,    24,   119,    27,    32,    27,    42,    42,
      41,    73,    34,    27,    34,    23,    54,    55,    56,    33,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    24,    41,    42,    52,    53,    54,    55,    56,
      28,    49,    30,     0,    81,   134,    25,   181,     5,    52,
      53,    54,    55,    56,    32,    63,    32,    27,    26,    25,
      27,    23,    33,    24,   126,    73,    74,   117,    24,    24,
      29,   114,   134,    31,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,    30,    26,    33,    26,    25,    33,    26,
     118,    25,   120,   121,    25,   123,    28,    25,    28,    28,
      25,    28,    25,   185,    11,    12,   134,    24,    15,    16,
     192,   181,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    33,    29,
      26,    25,    25,    25,    37,    25,     5,     9,    29,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      29,    42,   115,   113,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    70,   118,    -1,    -1,    -1,    -1,    -1,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    11,    12,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    11,    12,    -1,    42,
      15,    16,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    31,    -1,    -1,    -1,    -1,    11,    12,    -1,
      -1,    15,    16,    42,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    -1,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    11,    12,    -1,    42,    15,    16,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    -1,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    28,    -1,    -1,    -1,    32,    -1,    -1,
      35,    36,    -1,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    24,    52,    53,    -1,
      28,    -1,    57,    58,    32,    -1,    -1,    35,    36,    -1,
      38,    39,    40,    19,    20,    -1,    -1,    23,    24,    -1,
      -1,    -1,    28,    -1,    52,    53,    32,    19,    20,    57,
      58,    23,    24,    -1,    -1,    -1,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    -1,    -1,
      -1,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    53,    -1,    -1,    -1,    57,    58
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    27,    34,    61,    62,    63,    66,    24,    65,    67,
      76,    24,    32,     0,    62,    24,    64,    28,    30,    25,
      32,    69,    26,    42,    32,    27,    73,    26,    25,    27,
      68,    23,    27,    66,    72,    24,    65,    19,    20,    23,
      24,    28,    32,    52,    53,    57,    58,    77,    79,    82,
      73,    24,    74,    33,    64,    24,    29,    31,    75,    76,
      64,    21,    22,    35,    36,    38,    39,    40,    69,    70,
      71,    78,    79,    28,    30,    41,    80,    79,    78,    79,
      81,    26,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    42,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    79,    33,    26,    25,    26,    25,    26,    42,    25,
      28,    28,    79,    28,    25,    25,    28,    33,    70,    25,
      81,    79,    24,    29,    26,    33,    65,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    74,    73,    68,    72,
      75,    77,    72,    79,    79,    25,    79,    78,    29,    31,
      81,    26,    29,    29,    29,    25,    75,    25,    25,    71,
      78,    37,    25,    71,    78,    29,    71
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    62,    62,    63,    63,    63,    64,    64,
      64,    65,    65,    65,    65,    65,    66,    66,    66,    67,
      68,    68,    68,    69,    70,    70,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    72,    72,    72,    73,
      73,    74,    74,    75,    75,    75,    75,    76,    76,    77,
      77,    78,    78,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    80,    80,
      81,    81,    82,    82,    82,    82,    82,    82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     3,     3,     1,     3,
       0,     1,     3,     3,     5,     0,     5,     4,     2,     4,
       4,     2,     0,     4,     2,     0,     2,     1,     3,     5,
       7,     9,     2,     2,     5,     5,     4,     4,     0,     4,
       0,     3,     1,     1,     3,     5,     3,     1,     4,     1,
       3,     1,     0,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     4,     2,     3,     1,     3,     0,
       3,     1,     1,     1,     1,     1,     1,     1
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
#line 49 "parser.y" /* yacc.c:1646  */
    {
								root = (yyval.node) = getNodeInstance(yylineno,"PROGRAM","PROGRAM: EXTDEFS",1,(yyvsp[0].node));
							}
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 55 "parser.y" /* yacc.c:1646  */
    {
								(yyval.node) = getNodeInstance(yylineno,"EXTDEFS","EXTDEFS: EXTDEF EXTDEFS",2,(yyvsp[-1].node),(yyvsp[0].node));
							}
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 59 "parser.y" /* yacc.c:1646  */
    {
								(yyval.node) = getNodeInstance(yylineno,"EXTDEFS", "EXTDEFS:null", 0);
							}
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 64 "parser.y" /* yacc.c:1646  */
    { 
										(yyval.node) = getNodeInstance(yylineno,"EXTDEF", "EXTDEF: TYPE EXTVARS ;", 2, getNodeInstance(yylineno,"TYPE", (yyvsp[-2].string), 0),(yyvsp[-1].node));
									}
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 68 "parser.y" /* yacc.c:1646  */
    { 
										(yyval.node) = getNodeInstance(yylineno, "EXTDEF","EXTDEF: STSPEC SEXTVARS ;", 2, (yyvsp[-2].node),(yyvsp[-1].node)); 
									}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 71 "parser.y" /* yacc.c:1646  */
    {
										(yyval.node) = getNodeInstance(yylineno,"EXTDEF", "EXTDEF: TYPE FUNC STMTBLOCK", 3, getNodeInstance(yylineno,"TYPE", (yyvsp[-2].string), 0),(yyvsp[-1].node),(yyvsp[0].node)); 
									}
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 77 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"SEXTVARS", "SEXTVARS: ID",1,getNodeInstance(yylineno,"ID",(yyvsp[0].string),0)); }
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 78 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno, "SEXTVARS", "SEXTVARS: ID , SEXTVARS", 2, getNodeInstance(yylineno,"ID", (yyvsp[-2].string), 0),(yyvsp[0].node)); }
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 79 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getNodeInstance(yylineno,"SEXTVARS", "SEXTVARS: null", 0);}
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 82 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"EXTVARS", "EXTVARS: VAR", 1, (yyvsp[0].node)); }
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 83 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"EXTVARS", "EXTVARS:VAR , EXTVARS", 2, (yyvsp[-2].node),(yyvsp[0].node)); }
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 84 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"EXTVARS", "EXTVARS:VAR ASSIGN INIT", 3, (yyvsp[-2].node),getNodeInstance(yylineno,"ASSIGN",(yyvsp[-1].string),0),(yyvsp[0].node)); }
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 85 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"EXTVARS", "EXTVARS:VAR ASSIGN INIT , EXTVARS", 4, (yyvsp[-4].node),getNodeInstance(yylineno,"ASSIGN",(yyvsp[-3].string),0),(yyvsp[-2].node),(yyvsp[0].node)); }
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 86 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getNodeInstance(yylineno,"EXTVARS", "EXTVARS:null", 0);}
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 89 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"STSPEC", "STSPEC: STRUCT ID { SDEFS }", 3, getNodeInstance(yylineno,"STRUCT",(yyvsp[-4].string),0),getNodeInstance(yylineno,"ID", (yyvsp[-3].string), 0),(yyvsp[-1].node)); }
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 90 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno, "STSPEC","STSPEC: STRUCT { SDEFS }", 2, getNodeInstance(yylineno,"STRUCT",(yyvsp[-3].string),0),(yyvsp[-1].node)); }
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 91 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno, "STSPEC","STSPEC: STRUCT ID", 2, getNodeInstance(yylineno,"STRUCT",(yyvsp[-1].string),0),getNodeInstance(yylineno,"ID", (yyvsp[0].string), 0)); }
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 94 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno, "FUNC","FUNC: ID ( PARAS )", 2, getNodeInstance(yylineno,"ID" ,(yyvsp[-3].string), 0),(yyvsp[-1].node)); }
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 98 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"PARAS", "PARAS: TYPE ID , PARAS", 3, getNodeInstance(yylineno,"TYPE", (yyvsp[-3].string), 0), getNodeInstance(yylineno,"ID", (yyvsp[-2].string), 0),(yyvsp[0].node)); }
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 99 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno, "PARAS","PARAS: TYPE ID", 2, getNodeInstance(yylineno,"TYPE", (yyvsp[-1].string), 0), getNodeInstance(yylineno,"ID", (yyvsp[0].string), 0)); }
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 100 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getNodeInstance(yylineno, "PARAS","PARAS: null", 0);}
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 103 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"STMTBLOCK", "STMTBLOCK: { DEFS STMTS }", 2, (yyvsp[-2].node),(yyvsp[-1].node)); }
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 106 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno, "STMTS","STMTS: STMT STMTS", 2, (yyvsp[-1].node),(yyvsp[0].node)); }
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 107 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getNodeInstance(yylineno,"STMTS", "STMTS: null", 0);}
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 110 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"STMT", "STMT: EXP ;", 1, (yyvsp[-1].node)); }
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 111 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"STMT", "STMT: STMTBLOCK", 1, (yyvsp[0].node)); }
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 112 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"STMT" ,"STMT: RETURN EXPS ;", 2, getNodeInstance(yylineno,"RETURN", (yyvsp[-2].string), 0),(yyvsp[-1].node)); }
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 113 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"STMT" ,"STMT: if ( EXPS ) STMT", 2, (yyvsp[-2].node),(yyvsp[0].node)); }
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 114 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"STMT", "STMT: if ( EXPS ) STMT else STMT", 3, (yyvsp[-4].node),(yyvsp[-2].node),(yyvsp[0].node));}
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 115 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno, "STMT","STMT: for ( EXP ; EXP ; EXP ) STMT", 4, (yyvsp[-6].node),(yyvsp[-4].node),(yyvsp[-2].node),(yyvsp[0].node)); }
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 116 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"STMT", "STMT: CONT ;", 1, getNodeInstance(yylineno, "CONT",(yyvsp[-1].string), 0)); }
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 117 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno, "STMT","STMT: BREAK ;", 1, getNodeInstance(yylineno, "BREAK",(yyvsp[-1].string), 0)); }
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 118 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getNodeInstance(yylineno,"STMT", "STMT: read ( EXPS )",1, (yyvsp[-2].node));}
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 119 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getNodeInstance(yylineno,"STMT", "STMT: write ( EXPS )",1, (yyvsp[-2].node));}
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 122 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"DEFS", "DEFS: TYPE DECS ; DEFS", 3, getNodeInstance(yylineno,"TYPE", (yyvsp[-3].string), 0),(yyvsp[-2].node),(yyvsp[0].node)); }
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 123 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno, "DEFS","DEFS: STSPEC SEXTVARS ; DEFS", 3, (yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[0].node)); }
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 124 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getNodeInstance(yylineno, "DEFS","DEFS: null", 0);}
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 127 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno, "SDEFS","SDEFS: TYPE SDECS ; SDEFS", 3, getNodeInstance(yylineno, "TYPE",(yyvsp[-3].string), 0),(yyvsp[-2].node),(yyvsp[0].node)); }
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 128 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getNodeInstance(yylineno, "SDEFS", "SDEFS: null", 0);}
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 131 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"SDECS", "SDECS: ID , SDECS", 2, getNodeInstance(yylineno, "ID",(yyvsp[-2].string), 0),(yyvsp[0].node)); }
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 132 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"SDECS", "SDECS: ID ", 1,getNodeInstance(yylineno,"ID",(yyvsp[0].string),0)); }
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 135 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno, "DECS", "DECS: VAR", 1, (yyvsp[0].node)); }
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 136 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno, "DECS", "DECS: VAR, DECS", 2, (yyvsp[-2].node),(yyvsp[0].node)); }
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 137 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"DECS",  "DECS: VAR ASSIGN INIT, DECS", 4, (yyvsp[-4].node),getNodeInstance(yylineno,"ASSIGN", (yyvsp[-3].string), 0),(yyvsp[-2].node),(yyvsp[0].node)); }
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 138 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"DECS",  "DECS: VAR ASSIGN INIT", 3, (yyvsp[-2].node),getNodeInstance(yylineno,"ASSIGN", (yyvsp[-1].string), 0),(yyvsp[0].node)); }
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 141 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"VAR", "VAR: ID", 1,getNodeInstance(yylineno,"ID", (yyvsp[0].string), 0)); }
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 142 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"VAR",  "VAR: ID [ INT ]", 2, getNodeInstance(yylineno,"ID", (yyvsp[-3].string), 0) ,getNodeInstance(yylineno,"INT", (yyvsp[-1].string), 0)); }
#line 1858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 145 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"INIT",  "INIT: EXPS", 1, (yyvsp[0].node)); }
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 146 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"INIT",   "INIT: { ARGS }", 1, (yyvsp[-1].node)); }
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 149 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"EXP",   "EXP: EXPS", 1, (yyvsp[0].node)); }
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 150 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getNodeInstance(yylineno, "EXP", "EXP: null", 0);}
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 153 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"EXPS",  (yyvsp[-1].string), 2, (yyvsp[-2].node),(yyvsp[0].node)); }
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 154 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"EXPS", (yyvsp[-1].string), 2, (yyvsp[-2].node),(yyvsp[0].node)); }
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 155 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"EXPS",  (yyvsp[-1].string), 2, (yyvsp[-2].node),(yyvsp[0].node)); }
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 156 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno, "EXPS", (yyvsp[-1].string), 2, (yyvsp[-2].node),(yyvsp[0].node)); }
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 157 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno, "EXPS", (yyvsp[-1].string), 2, (yyvsp[-2].node),(yyvsp[0].node)); }
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 158 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"EXPS",  (yyvsp[-1].string), 2, (yyvsp[-2].node),(yyvsp[0].node)); }
#line 1918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 159 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno, "EXPS", (yyvsp[-1].string), 2, (yyvsp[-2].node),(yyvsp[0].node)); }
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 160 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno, "EXPS", (yyvsp[-1].string), 2, (yyvsp[-2].node),(yyvsp[0].node)); }
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 161 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno, "EXPS", (yyvsp[-1].string), 2, (yyvsp[-2].node),(yyvsp[0].node)); }
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 162 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno, "EXPS", (yyvsp[-1].string), 2, (yyvsp[-2].node),(yyvsp[0].node)); }
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 163 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno, "EXPS", (yyvsp[-1].string), 2, (yyvsp[-2].node),(yyvsp[0].node)); }
#line 1948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 164 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno, "EXPS", (yyvsp[-1].string), 2, (yyvsp[-2].node),(yyvsp[0].node)); }
#line 1954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 165 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno, "EXPS", (yyvsp[-1].string), 2, (yyvsp[-2].node),(yyvsp[0].node)); }
#line 1960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 166 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"EXPS",  (yyvsp[-1].string), 2, (yyvsp[-2].node),(yyvsp[0].node)); }
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 167 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno, "EXPS", (yyvsp[-1].string), 2, (yyvsp[-2].node),(yyvsp[0].node)); }
#line 1972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 168 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno, "EXPS", (yyvsp[-1].string), 2, (yyvsp[-2].node),(yyvsp[0].node)); }
#line 1978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 169 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"EXPS",  (yyvsp[-1].string), 2, (yyvsp[-2].node),(yyvsp[0].node)); }
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 170 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno, "EXPS", (yyvsp[-1].string), 2, (yyvsp[-2].node),(yyvsp[0].node)); }
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 171 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"EXPS",  (yyvsp[-1].string), 2, (yyvsp[-2].node),(yyvsp[0].node)); }
#line 1996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 172 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno, "EXPS", (yyvsp[-1].string), 2, (yyvsp[-2].node),(yyvsp[0].node)); }
#line 2002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 173 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"EXPS",  (yyvsp[-1].string), 2, (yyvsp[-2].node),(yyvsp[0].node)); }
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 174 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno, "EXPS", (yyvsp[-1].string), 2, (yyvsp[-2].node),(yyvsp[0].node)); }
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 175 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno, "EXPS", (yyvsp[-1].string), 2, (yyvsp[-2].node),(yyvsp[0].node)); }
#line 2020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 176 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno, "EXPS", (yyvsp[-1].string), 2, (yyvsp[-2].node),(yyvsp[0].node)); }
#line 2026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 177 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno, "EXPS", (yyvsp[-1].string), 2, (yyvsp[-2].node),(yyvsp[0].node)); }
#line 2032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 178 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"EXPS",  (yyvsp[-1].string), 2, (yyvsp[-2].node),(yyvsp[0].node)); }
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 179 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"EXPS",  (yyvsp[-1].string), 2, (yyvsp[-2].node),(yyvsp[0].node)); }
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 180 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno, "EXPS", (yyvsp[-1].string), 2, (yyvsp[-2].node),(yyvsp[0].node)); }
#line 2050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 181 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"EXPS",  (yyvsp[-1].string), 2, (yyvsp[-2].node),(yyvsp[0].node)); }
#line 2056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 182 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"EXPS",  "EXPS: UNARYOP EXPS", 2, (yyvsp[-1].node),(yyvsp[0].node)); }
#line 2062 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 183 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno, "EXPS", "EXPS: ( EXPS )", 1, (yyvsp[-1].node)); }
#line 2068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 184 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"EXPS",  "EXPS: ID ( ARGS )", 2, getNodeInstance(yylineno,"ID", (yyvsp[-3].string), 0),(yyvsp[-1].node)); }
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 185 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"EXPS",  "EXPS: ID ARRS", 2, getNodeInstance(yylineno,"ID", (yyvsp[-1].string), 0),(yyvsp[0].node)); }
#line 2080 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 186 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno, "EXPS", "EXPS: ID DOT ID", 3, getNodeInstance(yylineno,"ID", (yyvsp[-2].string), 0),getNodeInstance(yylineno,"DOT", (yyvsp[-1].string), 0),getNodeInstance(yylineno, "ID",(yyvsp[0].string), 0)); }
#line 2086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 187 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"INT",  (yyvsp[0].string), 0); }
#line 2092 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 190 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno, "ARRS", "ARRS: [ EXPS ]", 1, (yyvsp[-1].node)); }
#line 2098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 191 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getNodeInstance(yylineno, "ARRS", "ARRS: null", 0);}
#line 2104 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 194 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"ARGS",  "ARGS: EXPS, ARGS", 2, (yyvsp[-2].node),(yyvsp[0].node)); }
#line 2110 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 195 "parser.y" /* yacc.c:1646  */
    { (yyval.node) = getNodeInstance(yylineno,"ARGS", "args", 1, (yyvsp[0].node)); }
#line 2116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 199 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getNodeInstance(yylineno, "UNARYOP",(yyvsp[0].string), 0);}
#line 2122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 200 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getNodeInstance(yylineno,"UNARYOP", (yyvsp[0].string), 0);}
#line 2128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 201 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getNodeInstance(yylineno, "UNARYOP",(yyvsp[0].string), 0);}
#line 2134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 202 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getNodeInstance(yylineno, "UNARYOP",(yyvsp[0].string), 0);}
#line 2140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 203 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getNodeInstance(yylineno, "UNARYOP",(yyvsp[0].string), 0);}
#line 2146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 204 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = getNodeInstance(yylineno, "UNARYOP",(yyvsp[0].string), 0);}
#line 2152 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2156 "y.tab.c" /* yacc.c:1646  */
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
#line 207 "parser.y" /* yacc.c:1906  */


#include "header.h"
#include "syntax_tree.h"

int yyerror(const char *msg)
{
	fflush(stdout);
	fprintf(stderr, "Error: %s at line %d\n", msg,yylineno);
	fprintf(stderr, "Parser does not expect '%s\n'",yytext);
}


int main(int argc, char const *argv[])
{
	if (argc == 1){
		fprintf(stderr, "\n%s\n", "Please write your code in the shell. Input <CTRL-D> to exit.");
		fprintf(stderr, "%s\n", "Or you can specify the source code path. \nExample --> $./parser InputFile OutputFile\n");
	}

	freopen(argv[1], "r", stdin);
    	freopen(argv[2], "w", stdout);
	if(!yyparse()){
		fprintf(stderr,"Parsing complete.\n");
		//printTree(root,0);
        root->CodePrint();
        fprintf(stderr,"Translation success\n\n\n");
	}
	else{
		printf("ERROR! parse failed.\n");
	}

	return 0;
}
int yywrap()
{
	return 1;
}
