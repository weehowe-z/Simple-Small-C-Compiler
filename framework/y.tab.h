/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
#line 16 "parser.y" /* yacc.c:1909  */

    char* string;
    TreeNode* node;

#line 177 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
