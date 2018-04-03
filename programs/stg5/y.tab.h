/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
    START = 258,
    END = 259,
    NL = 260,
    NUM = 261,
    STRING = 262,
    ID = 263,
    PLUS = 264,
    MINUS = 265,
    MUL = 266,
    DIV = 267,
    INC = 268,
    DEC = 269,
    READ = 270,
    WRITE = 271,
    IF = 272,
    THEN = 273,
    ELSE = 274,
    ENDIF = 275,
    WHILE = 276,
    DO = 277,
    ENDWHILE = 278,
    REPEAT = 279,
    UNTIL = 280,
    BREAK = 281,
    CNTU = 282,
    LT = 283,
    LE = 284,
    GT = 285,
    GE = 286,
    EQ = 287,
    NE = 288,
    DECL = 289,
    ENDDECL = 290,
    MAIN1 = 291,
    RETURN = 292,
    INTG = 293,
    STR = 294,
    TUPLE = 295,
    POINTER = 296
  };
#endif
/* Tokens.  */
#define START 258
#define END 259
#define NL 260
#define NUM 261
#define STRING 262
#define ID 263
#define PLUS 264
#define MINUS 265
#define MUL 266
#define DIV 267
#define INC 268
#define DEC 269
#define READ 270
#define WRITE 271
#define IF 272
#define THEN 273
#define ELSE 274
#define ENDIF 275
#define WHILE 276
#define DO 277
#define ENDWHILE 278
#define REPEAT 279
#define UNTIL 280
#define BREAK 281
#define CNTU 282
#define LT 283
#define LE 284
#define GT 285
#define GE 286
#define EQ 287
#define NE 288
#define DECL 289
#define ENDDECL 290
#define MAIN1 291
#define RETURN 292
#define INTG 293
#define STR 294
#define TUPLE 295
#define POINTER 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
