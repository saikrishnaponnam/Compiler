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
    NUM = 260,
    STRING = 261,
    ID = 262,
    PLUS = 263,
    MINUS = 264,
    MUL = 265,
    DIV = 266,
    MOD = 267,
    READ = 268,
    WRITE = 269,
    IF = 270,
    THEN = 271,
    ELSE = 272,
    ENDIF = 273,
    WHILE = 274,
    DO = 275,
    ENDWHILE = 276,
    REPEAT = 277,
    UNTIL = 278,
    BREAK = 279,
    CNTU = 280,
    LT = 281,
    LE = 282,
    GT = 283,
    GE = 284,
    EQ = 285,
    NE = 286,
    DECL = 287,
    ENDDECL = 288,
    MAIN1 = 289,
    RETURN = 290,
    INTG = 291,
    STR = 292,
    TUPLE = 293,
    POINTER = 294,
    TYPE = 295,
    ENDTYPE = 296,
    ALLOC = 297,
    FREE = 298,
    INIT = 299,
    NUL = 300,
    CLASS = 301,
    ENDCLASS = 302,
    SELF = 303,
    Extends = 304,
    NEW = 305,
    DELETE = 306,
    BRKP = 307
  };
#endif
/* Tokens.  */
#define START 258
#define END 259
#define NUM 260
#define STRING 261
#define ID 262
#define PLUS 263
#define MINUS 264
#define MUL 265
#define DIV 266
#define MOD 267
#define READ 268
#define WRITE 269
#define IF 270
#define THEN 271
#define ELSE 272
#define ENDIF 273
#define WHILE 274
#define DO 275
#define ENDWHILE 276
#define REPEAT 277
#define UNTIL 278
#define BREAK 279
#define CNTU 280
#define LT 281
#define LE 282
#define GT 283
#define GE 284
#define EQ 285
#define NE 286
#define DECL 287
#define ENDDECL 288
#define MAIN1 289
#define RETURN 290
#define INTG 291
#define STR 292
#define TUPLE 293
#define POINTER 294
#define TYPE 295
#define ENDTYPE 296
#define ALLOC 297
#define FREE 298
#define INIT 299
#define NUL 300
#define CLASS 301
#define ENDCLASS 302
#define SELF 303
#define Extends 304
#define NEW 305
#define DELETE 306
#define BRKP 307

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
