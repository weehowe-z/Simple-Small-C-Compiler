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
#line 19 "parse.y" /* yacc.c:1909  */
 
     int intValue; /* integer value */ 
     char* charValue; /* string value */ 

#line 137 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
