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
#line 1 "exp.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YYSTYPE tnode *
#include "abstracttree.h"
#include "abstracttree.c"
#include "symboltable.h"
#include "symboltable.c"
#include "codegen.c"
//int yydebug=1;
int yylex(void);
void yyerror(char const *s);
FILE *yyin,*target_file;
int reg,type,functype,decl=1,size=0;
char *tuplename;


#line 85 "y.tab.c" /* yacc.c:339  */

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

/* Copy the second part of user declarations.  */

#line 218 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   611

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  227

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    49,     2,
      43,    44,     2,     2,    50,     2,    48,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    42,
       2,    47,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,    52,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    29,    29,    30,    31,    35,    36,    40,    41,    44,
      45,    46,    47,    48,    49,    50,    51,    54,    57,    70,
      83,   101,   104,   135,   147,   161,   187,   214,   215,   218,
     219,   220,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   258,   271,   283,   309,
     335,   349,   368,   393,   394,   397,   398,   399,   399,   402,
     403,   406,   407,   410,   413,   414,   417,   425,   431,   437,
     443,   443,   460,   461,   464,   464,   493,   495,   496,   499,
     509,   522,   533,   534,   535,   538,   539,   542,   545,   546
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "START", "END", "NL", "NUM", "STRING",
  "ID", "PLUS", "MINUS", "MUL", "DIV", "INC", "DEC", "READ", "WRITE", "IF",
  "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "REPEAT", "UNTIL",
  "BREAK", "CNTU", "LT", "LE", "GT", "GE", "EQ", "NE", "DECL", "ENDDECL",
  "MAIN1", "RETURN", "INTG", "STR", "TUPLE", "POINTER", "';'", "'('",
  "')'", "'['", "']'", "'='", "'.'", "'&'", "','", "'{'", "'}'", "$accept",
  "program", "Body", "Slist", "Stmt", "RET", "InputStmt", "OutputStmt",
  "AsgStmt", "IfStmt", "WhileStmt", "expr", "ArgList", "Type", "$@1",
  "GDeclarations", "GDeclList", "GDecl", "GidList", "Gid", "$@2",
  "FDeclarations", "Fdef", "$@3", "ParamList", "Param", "mainblk",
  "LDeclarations", "LDecList", "LDecl", "IdList", YY_NULLPTR
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
     295,   296,    59,    40,    41,    91,    93,    61,    46,    38,
      44,   123,   125
};
# endif

#define YYPACT_NINF -97

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-97)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -23,    53,   -20,    28,     1,   -97,   -97,   -97,   -97,    44,
      74,    94,   -97,   -11,   -97,   -20,    51,     1,   -97,   -97,
      34,    30,    79,   -29,   -97,   -97,   -97,    50,    73,   -97,
     -97,   -97,   -97,   116,   -97,   -97,    74,    72,   -97,    65,
      65,    84,   -97,   119,    65,    78,   -38,   -97,    12,   129,
     181,   151,    17,   -97,   152,   -97,    65,   -97,   179,   -97,
     183,   188,   -97,   296,   165,   141,   -97,   -97,   184,   -97,
     -24,   -97,   -97,   182,   204,   217,   186,   198,   199,   205,
     542,   542,   212,   231,    47,   320,   -97,   -97,   -97,   -97,
     -97,   -97,   -97,   -97,   119,   -97,   -97,   242,   -97,    47,
      47,   271,   233,   273,    47,    47,    47,   559,   479,   -97,
     -97,   -97,   -97,    66,   274,    47,   275,   339,   243,   -97,
     151,   -97,    69,   354,   237,    47,    24,   178,   203,   228,
     256,   258,    27,    47,   278,   -97,   234,   -97,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,   -97,   -97,
     250,   208,   -97,    47,   379,   263,    47,   264,   290,   288,
      47,    47,   -97,   578,    22,   109,   -97,   -97,   347,   347,
     134,   134,   166,   166,   166,   166,   166,   166,   -97,    47,
      47,   394,   -97,   -97,   115,   -97,   542,   542,   259,   265,
     -97,    47,   269,   140,   419,   -97,    91,   462,   502,   -17,
     277,   578,    47,   268,   -97,   279,    47,   542,   283,   284,
     -97,   -97,   147,    47,   -97,   172,   525,   -97,   -97,   -97,
     434,   272,   285,   -97,   287,   -97,   -97
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     4,    60,    55,    56,     0,
       0,     0,    62,     0,     1,    55,     0,     0,    73,     3,
       0,    66,     0,     0,    65,    59,    61,     0,     0,    72,
       2,    57,    70,     0,    69,    63,     0,     0,    74,    78,
      78,     0,    64,    84,    78,     0,     0,    77,     0,    67,
       0,     0,     0,    79,     0,    58,     0,    71,     0,    83,
       0,     0,    86,     0,     0,     0,    80,    76,     0,    89,
       0,    82,    85,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     8,    16,     9,    10,
      11,    12,    13,    81,    84,    68,    87,     0,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    14,
      15,    37,    38,    45,     0,     0,     0,     0,     0,     7,
       0,    88,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,     0,    49,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    17,     5,
       0,     0,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    50,    54,     0,     0,    52,    36,    32,    33,
      34,    35,    39,    40,    41,    42,    43,    44,    75,     0,
       0,     0,    25,    18,     0,    21,     0,     0,     0,     0,
      51,     0,    46,     0,     0,    26,     0,     0,     0,     0,
       0,    53,     0,     0,    23,     0,     0,     0,     0,     0,
      30,    31,     0,     0,    19,     0,     0,    28,    29,    47,
       0,     0,     0,    24,     0,    27,    20
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -97,   -97,   210,   -79,   -85,   -97,   -97,   -97,   -97,   -97,
     -97,   -96,   -97,    13,   -97,   -97,   -97,   321,   -97,   298,
     -97,   -97,   322,   -97,   -13,   282,     3,   246,   -97,   291,
     -97
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,    64,    85,    86,    87,    88,    89,    90,    91,
      92,   117,   164,    45,    39,     4,    11,    12,    23,    24,
      40,    17,    18,    44,    46,    47,     5,    51,    61,    62,
      70
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     119,   107,   108,   122,   123,   187,    55,    19,   127,   128,
     129,     1,    56,    35,    10,     2,    13,    16,    96,   136,
      30,    36,   119,   119,    10,   210,    97,    48,    14,   154,
      16,    52,    27,   111,   112,   113,   163,   165,   114,    15,
       8,     9,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,    20,   111,   112,   113,    57,   181,   114,    28,
     184,    65,    56,    60,   188,   189,   190,    56,   155,   156,
     115,   162,   191,    32,    60,    33,   116,    31,   138,   139,
     140,   141,    21,   193,   194,    22,    53,    34,     6,    54,
     115,     7,     8,     9,    37,   201,   116,   142,   143,   144,
     145,   146,   147,     7,     8,     9,   212,   197,   198,   132,
     215,   133,   119,   119,   134,   151,    38,   220,   138,   139,
     140,   141,    41,    43,   138,   139,   140,   141,   216,    25,
      49,   119,     7,     8,     9,   205,   206,   142,   143,   144,
     145,   146,   147,   142,   143,   144,   145,   146,   147,   138,
     139,   140,   141,    50,    63,   192,   138,   139,   140,   141,
      66,   196,   142,   143,   144,   145,   146,   147,   142,   143,
     144,   145,   146,   147,    58,   142,   143,   144,   145,   146,
     147,   138,   139,   140,   141,    68,   203,   138,   139,   140,
     141,    69,    94,   219,    -1,    -1,    -1,    -1,    -1,    -1,
     142,   143,   144,   145,   146,   147,   142,   143,   144,   145,
     146,   147,   138,   139,   140,   141,    59,    93,   221,     7,
       8,     9,   157,    71,    98,   102,     7,     8,     9,   103,
      95,   142,   143,   144,   145,   146,   147,   138,   139,   140,
     141,   104,   105,   138,   139,   140,   141,   158,   106,    99,
     121,   100,   101,   179,   109,   180,   142,   143,   144,   145,
     146,   147,   142,   143,   144,   145,   146,   147,   138,   139,
     140,   141,   159,   110,   138,   139,   140,   141,   167,   124,
     125,   126,   135,   137,   153,   149,   166,   142,   143,   144,
     145,   146,   147,   142,   143,   144,   145,   146,   147,   160,
      73,   161,   178,   199,    74,   183,   185,    75,   186,   200,
     187,    76,    77,    78,   202,   213,   224,    79,    80,   211,
      81,   214,    82,    83,   118,   217,   218,   225,    74,   226,
     150,    75,    26,    84,    42,    76,    77,    78,    67,    29,
     120,    79,    80,     0,    81,     0,    82,    83,   138,   139,
     140,   141,    72,     0,     0,     0,     0,    84,   140,   141,
       0,     0,     0,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,     0,     0,   142,   143,   144,   145,   146,
     147,   148,   142,   143,   144,   145,   146,   147,   138,   139,
     140,   141,     0,     0,     0,     0,   152,     0,     0,     0,
       0,     0,     0,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,     0,     0,     0,     0,     0,     0,     0,
       0,   182,   142,   143,   144,   145,   146,   147,   138,   139,
     140,   141,     0,     0,     0,     0,   195,     0,     0,     0,
       0,     0,     0,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,     0,     0,     0,     0,     0,     0,     0,
       0,   204,   142,   143,   144,   145,   146,   147,     0,     0,
      74,     0,     0,    75,     0,     0,   223,    76,    77,    78,
       0,   207,   208,    79,    80,     0,    81,    74,    82,    83,
      75,     0,     0,     0,    76,    77,    78,     0,     0,    84,
      79,    80,     0,    81,   131,    82,    83,     0,     0,     0,
      74,     0,     0,    75,     0,     0,    84,    76,    77,    78,
       0,     0,     0,    79,    80,   209,    81,     0,    82,    83,
       0,     0,     0,    74,     0,     0,    75,     0,     0,    84,
      76,    77,    78,     0,     0,   222,    79,    80,     0,    81,
      74,    82,    83,    75,     0,     0,     0,    76,    77,    78,
       0,     0,    84,    79,    80,     0,    81,    74,    82,    83,
      75,     0,     0,     0,    76,    77,    78,     0,     0,    84,
     130,    80,     0,    81,     0,    82,    83,   138,   139,   140,
     141,     0,     0,     0,     0,     0,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   142,   143,   144,   145,
     146,   147
};

static const yytype_int16 yycheck[] =
{
      85,    80,    81,    99,   100,    22,    44,     4,   104,   105,
     106,    34,    50,    42,     1,    38,    36,     4,    42,   115,
      17,    50,   107,   108,    11,    42,    50,    40,     0,   125,
      17,    44,    43,     6,     7,     8,   132,   133,    11,    38,
      39,    40,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,     8,     6,     7,     8,    44,   153,    11,     8,
     156,    44,    50,    50,   160,   161,    44,    50,    44,    45,
      43,    44,    50,    43,    61,    45,    49,    43,     9,    10,
      11,    12,     8,   179,   180,    11,     8,     8,    35,    11,
      43,    38,    39,    40,    44,   191,    49,    28,    29,    30,
      31,    32,    33,    38,    39,    40,   202,   186,   187,    43,
     206,    45,   197,   198,    48,    46,    43,   213,     9,    10,
      11,    12,     6,    51,     9,    10,    11,    12,   207,    35,
      46,   216,    38,    39,    40,    44,    45,    28,    29,    30,
      31,    32,    33,    28,    29,    30,    31,    32,    33,     9,
      10,    11,    12,    34,     3,    46,     9,    10,    11,    12,
       8,    46,    28,    29,    30,    31,    32,    33,    28,    29,
      30,    31,    32,    33,    45,    28,    29,    30,    31,    32,
      33,     9,    10,    11,    12,     6,    46,     9,    10,    11,
      12,     8,    51,    46,    28,    29,    30,    31,    32,    33,
      28,    29,    30,    31,    32,    33,    28,    29,    30,    31,
      32,    33,     9,    10,    11,    12,    35,    52,    46,    38,
      39,    40,    44,    35,    42,     8,    38,    39,    40,    43,
      46,    28,    29,    30,    31,    32,    33,     9,    10,    11,
      12,    43,    43,     9,    10,    11,    12,    44,    43,    45,
       8,    47,    48,    45,    42,    47,    28,    29,    30,    31,
      32,    33,    28,    29,    30,    31,    32,    33,     9,    10,
      11,    12,    44,    42,     9,    10,    11,    12,    44,     8,
      47,     8,     8,     8,    47,    42,     8,    28,    29,    30,
      31,    32,    33,    28,    29,    30,    31,    32,    33,    43,
       4,    43,    52,    44,     8,    42,    42,    11,    18,    44,
      22,    15,    16,    17,    45,    47,    44,    21,    22,    42,
      24,    42,    26,    27,     4,    42,    42,    42,     8,    42,
     120,    11,    11,    37,    36,    15,    16,    17,    56,    17,
      94,    21,    22,    -1,    24,    -1,    26,    27,     9,    10,
      11,    12,    61,    -1,    -1,    -1,    -1,    37,    11,    12,
      -1,    -1,    -1,     9,    10,    11,    12,    28,    29,    30,
      31,    32,    33,    -1,    -1,    28,    29,    30,    31,    32,
      33,    42,    28,    29,    30,    31,    32,    33,     9,    10,
      11,    12,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    -1,     9,    10,    11,    12,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    28,    29,    30,    31,    32,    33,     9,    10,
      11,    12,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    -1,     9,    10,    11,    12,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    28,    29,    30,    31,    32,    33,    -1,    -1,
       8,    -1,    -1,    11,    -1,    -1,    42,    15,    16,    17,
      -1,    19,    20,    21,    22,    -1,    24,     8,    26,    27,
      11,    -1,    -1,    -1,    15,    16,    17,    -1,    -1,    37,
      21,    22,    -1,    24,    25,    26,    27,    -1,    -1,    -1,
       8,    -1,    -1,    11,    -1,    -1,    37,    15,    16,    17,
      -1,    -1,    -1,    21,    22,    23,    24,    -1,    26,    27,
      -1,    -1,    -1,     8,    -1,    -1,    11,    -1,    -1,    37,
      15,    16,    17,    -1,    -1,    20,    21,    22,    -1,    24,
       8,    26,    27,    11,    -1,    -1,    -1,    15,    16,    17,
      -1,    -1,    37,    21,    22,    -1,    24,     8,    26,    27,
      11,    -1,    -1,    -1,    15,    16,    17,    -1,    -1,    37,
      21,    22,    -1,    24,    -1,    26,    27,     9,    10,    11,
      12,    -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    34,    38,    54,    68,    79,    35,    38,    39,    40,
      66,    69,    70,    36,     0,    38,    66,    74,    75,    79,
       8,     8,    11,    71,    72,    35,    70,    43,     8,    75,
      79,    43,    43,    45,     8,    42,    50,    44,    43,    67,
      73,     6,    72,    51,    76,    66,    77,    78,    77,    46,
      34,    80,    77,     8,    11,    44,    50,    44,    45,    35,
      66,    81,    82,     3,    55,    44,     8,    78,     6,     8,
      83,    35,    82,     4,     8,    11,    15,    16,    17,    21,
      22,    24,    26,    27,    37,    56,    57,    58,    59,    60,
      61,    62,    63,    52,    51,    46,    42,    50,    42,    45,
      47,    48,     8,    43,    43,    43,    43,    56,    56,    42,
      42,     6,     7,     8,    11,    43,    49,    64,     4,    57,
      80,     8,    64,    64,     8,    47,     8,    64,    64,    64,
      21,    25,    43,    45,    48,     8,    64,     8,     9,    10,
      11,    12,    28,    29,    30,    31,    32,    33,    42,    42,
      55,    46,    42,    47,    64,    44,    45,    44,    44,    44,
      43,    43,    44,    64,    65,    64,     8,    44,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    52,    45,
      47,    64,    42,    42,    64,    42,    18,    22,    64,    64,
      44,    50,    46,    64,    64,    42,    46,    56,    56,    44,
      44,    64,    45,    46,    42,    44,    45,    19,    20,    23,
      42,    42,    64,    47,    42,    64,    56,    42,    42,    46,
      64,    46,    20,    42,    44,    42,    42
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    54,    54,    55,    55,    56,    56,    57,
      57,    57,    57,    57,    57,    57,    57,    58,    59,    59,
      59,    60,    61,    61,    61,    61,    61,    62,    62,    63,
      63,    63,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    65,    65,    66,    66,    67,    66,    68,
      68,    69,    69,    70,    71,    71,    72,    72,    72,    72,
      73,    72,    74,    74,    76,    75,    77,    77,    77,    78,
      78,    79,    80,    80,    80,    81,    81,    82,    83,    83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     1,     4,     3,     2,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     3,     5,     8,
      11,     5,     4,     7,    10,     5,     6,    10,     8,     8,
       7,     7,     3,     3,     3,     3,     3,     1,     1,     3,
       3,     3,     3,     3,     3,     1,     4,     7,     2,     2,
       3,     4,     3,     3,     1,     1,     1,     0,     6,     3,
       2,     2,     1,     3,     3,     1,     1,     4,     7,     2,
       0,     5,     2,     1,     0,    10,     3,     1,     0,     2,
       3,     8,     3,     2,     0,     2,     1,     3,     3,     1
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
#line 29 "exp.y" /* yacc.c:1646  */
    {end(target_file); printf("%d",count);}
#line 1519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 30 "exp.y" /* yacc.c:1646  */
    {end(target_file);}
#line 1525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 31 "exp.y" /* yacc.c:1646  */
    {end(target_file);}
#line 1531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 35 "exp.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-2]);}
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 36 "exp.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 40 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_NULL,type_null,NULL,(yyvsp[-1]),(yyvsp[0]),NULL);}
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 41 "exp.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 44 "exp.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 45 "exp.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 46 "exp.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 47 "exp.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 48 "exp.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 49 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_BRK,type_null,NULL,NULL,NULL,NULL);}
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 50 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_CNTU,type_null,NULL,NULL,NULL,NULL);}
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 51 "exp.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 54 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_RET,type_null,NULL,(yyvsp[-1]),NULL,NULL);}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 57 "exp.y" /* yacc.c:1646  */
    {
									Ltemp=LLookup((yyvsp[-2])->varname);
									if(Ltemp==NULL)
									{
										tempst=GLookup((yyvsp[-2])->varname);
										if(tempst==NULL)
										{yyerror("undefined Variable");printf("%s\n",(yyvsp[-2])->varname );exit(1);}
										else (yyvsp[-2])->Gentry=tempst;
									}
									else
										(yyvsp[-2])->Lentry=Ltemp;
									(yyval)=createtree(0,nodetype_READ,type_null,NULL,(yyvsp[-2]),NULL,NULL);
								}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 70 "exp.y" /* yacc.c:1646  */
    {
												Ltemp=LLookup((yyvsp[-5])->varname);
												if(Ltemp==NULL)
												{
													tempst=GLookup((yyvsp[-5])->varname);
													if(tempst==NULL)
													{yyerror("undefined Variable");printf("%s\n",(yyvsp[-5])->varname );exit(1);}
													else (yyvsp[-5])->Gentry=tempst;
												}
												else
													(yyvsp[-5])->Lentry=Ltemp;
												(yyval)=createtree(0,nodetype_ARRREAD,type_null,NULL,(yyvsp[-5]),(yyvsp[-3]),NULL);
											 }
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 83 "exp.y" /* yacc.c:1646  */
    {
															Ltemp=LLookup((yyvsp[-8])->varname);
															if(Ltemp==NULL)
															{
																tempst=GLookup((yyvsp[-8])->varname);
																if(tempst==NULL)
																{yyerror("undefined Variable");printf("%s\n",(yyvsp[-8])->varname );exit(1);}
																else (yyvsp[-8])->Gentry=tempst;
															}
															else
																(yyvsp[-8])->Lentry=Ltemp;
															struct tnode *temp=createtree(tempst->s2,nodetype_LEAF,type_int,NULL,NULL,NULL,NULL);
															(yyvsp[-6])=createtree(0,nodetype_MUL,type_int,NULL,(yyvsp[-6]),temp,NULL);
															(yyvsp[-6])=createtree(0,nodetype_PLUS,type_int,NULL,(yyvsp[-6]),(yyvsp[-3]),NULL);
															(yyval)=createtree(0,nodetype_ARRREAD,type_null,NULL,(yyvsp[-8]),(yyvsp[-6]),NULL);
														   }
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 101 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_WRITE,type_null,NULL,(yyvsp[-2]),NULL,NULL);}
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 104 "exp.y" /* yacc.c:1646  */
    {
									//printf("A0\n");
									Ltemp=LLookup((yyvsp[-3])->varname);
									//printf("A1\n");
									if(Ltemp==NULL)
									{
										tempst=GLookup((yyvsp[-3])->varname);
										if(tempst==NULL)
										{yyerror("undefined Variable");printf("%s\n",(yyvsp[-3])->varname );exit(1);}
										else 
										{	
											(yyvsp[-3])->Gentry=tempst;
											if(tempst->type==type_int||tempst->type==type_intptr)
												(yyvsp[-3])->type=type_int;
											else if(tempst->type==type_char||tempst->type==type_strptr)
												(yyvsp[-3])->type=type_char;
										}
										//printf("A2\n");
									}
									else
									{
										(yyvsp[-3])->Lentry=Ltemp;
										if(Ltemp->type==type_int||Ltemp->type==type_intptr||Ltemp->type==type_argint||Ltemp->type==type_argintref)
											(yyvsp[-3])->type=type_int;
										else if(Ltemp->type==type_char||Ltemp->type==type_strptr||Ltemp->type==type_argchar||Ltemp->type==type_argcharref)
											(yyvsp[-3])->type=type_char;
										//printf("A3\n");
									}
									(yyval)=createtree(0,nodetype_ASGN,type_null,NULL,(yyvsp[-3]),(yyvsp[-1]),NULL);
									//printf("Asgn node OK\n");
								}
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 135 "exp.y" /* yacc.c:1646  */
    {
												tempst=GLookup((yyvsp[-6])->varname);
												if(tempst==NULL)
												{yyerror("undefined Variable");printf("%s\n",(yyvsp[-6])->varname );exit(1);}
												else {	(yyvsp[-6])->Gentry=tempst;
														if(tempst->type==type_arrint)
															(yyvsp[-6])->type=type_int;
														else if(tempst->type==type_str)
															(yyvsp[-6])->type=type_char;
													 }
												(yyval)=createtree(0,nodetype_ARRASGN,type_null,NULL,(yyvsp[-6]),(yyvsp[-4]),(yyvsp[-1]));
											}
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 147 "exp.y" /* yacc.c:1646  */
    { tempst=GLookup((yyvsp[-9])->varname);
												if(tempst==NULL)
												{yyerror("undefined Variable");printf("%s\n",(yyvsp[-9])->varname );exit(1);}
												else {	(yyvsp[-9])->Gentry=tempst;
														if(tempst->type==type_arrint)
															(yyvsp[-9])->type=type_int;
														else if(tempst->type==type_str)
															(yyvsp[-9])->type=type_char;
													 }
												struct tnode *temp=createtree(tempst->s2,nodetype_LEAF,type_int,NULL,NULL,NULL,NULL);
												(yyvsp[-7])=createtree(0,nodetype_MUL,type_int,NULL,(yyvsp[-7]),temp,NULL);
												(yyvsp[-7])=createtree(0,nodetype_PLUS,type_int,NULL,(yyvsp[-7]),(yyvsp[-4]),NULL);
												(yyval)=createtree(0,nodetype_ARRASGN,type_null,NULL,(yyvsp[-9]),(yyvsp[-7]),(yyvsp[-1])); 
											}
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 161 "exp.y" /* yacc.c:1646  */
    {
											Ltemp=LLookup((yyvsp[-3])->varname);
											if(Ltemp==NULL)
											{
												tempst=GLookup((yyvsp[-3])->varname);
												if(tempst==NULL)
												{yyerror("undefined Variable");printf("%s\n",(yyvsp[-3])->varname );exit(1);}
												else 
												{	
													(yyvsp[-3])->Gentry=tempst;
													if(tempst->type==type_intptr)
														(yyvsp[-3])->type=type_int;
													else if(tempst->type==type_strptr)
														(yyvsp[-3])->type=type_char;
												}
											}
											else
											{
												(yyvsp[-3])->Lentry=Ltemp;
												if(Ltemp->type==type_intptr||Ltemp->type==type_argintref)
													(yyvsp[-3])->type=type_int;
												else if(Ltemp->type==type_strptr||Ltemp->type==type_argcharref)
													(yyvsp[-3])->type=type_char;
											}
											(yyval)=createtree(0,nodetype_PASGN,type_null,NULL,(yyvsp[-3]),(yyvsp[-1]),NULL);
										}
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 187 "exp.y" /* yacc.c:1646  */
    {
												tempst=GLookup((yyvsp[-5])->varname);
												if(tempst==NULL)
												{yyerror("undefined Variable");printf("%s\n",(yyvsp[-5])->varname );exit(1);}
												else 
												{	
													(yyvsp[-5])->Gentry=tempst;
													Ptemp=(yyvsp[-5])->Gentry->paramlist;
													int j=0;
													while(Ptemp!=NULL)
													{
														if(strcmp(Ptemp->name,(yyvsp[-3])->varname)==0)
															break;
														j++;
														Ptemp=Ptemp->next;
													}
													if(Ptemp==NULL)
														{yyerror("Invalid reference");exit(1);}
													if(Ptemp->type==type_int)
														(yyvsp[-5])->type=type_int;
													else if(Ptemp->type==type_char)
														(yyvsp[-5])->type=type_char;
												}	
											(yyval)=createtree(0,nodetype_TASGN,type_null,NULL,(yyvsp[-5]),(yyvsp[-3]),(yyvsp[-1]));
										}
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 214 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_IF,type_null,NULL,(yyvsp[-7]),(yyvsp[-4]),(yyvsp[-2]));}
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 215 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_IF,type_null,NULL,(yyvsp[-5]),(yyvsp[-2]),NULL);}
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 218 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_WHILE,type_null,NULL,(yyvsp[-5]),(yyvsp[-2]),NULL);}
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 219 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_DOWHILE,type_null,NULL,(yyvsp[-2]),(yyvsp[-5]),NULL);}
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 220 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_REPEAT,type_null,NULL,(yyvsp[-2]),(yyvsp[-5]),NULL);}
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 224 "exp.y" /* yacc.c:1646  */
    {(yyval) =createtree(0,nodetype_PLUS,type_int,NULL,(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 225 "exp.y" /* yacc.c:1646  */
    {(yyval) =createtree(0,nodetype_MINUS,type_int,NULL,(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 226 "exp.y" /* yacc.c:1646  */
    {(yyval) =createtree(0,nodetype_MUL,type_int,NULL,(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 227 "exp.y" /* yacc.c:1646  */
    {(yyval) =createtree(0,nodetype_DIV,type_int,NULL,(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 228 "exp.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 229 "exp.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 230 "exp.y" /* yacc.c:1646  */
    {(yyval)	= (yyvsp[0]);}
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 231 "exp.y" /* yacc.c:1646  */
    {(yyval) =createtree(0,nodetype_LT,type_bool,NULL,(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 232 "exp.y" /* yacc.c:1646  */
    {(yyval) =createtree(0,nodetype_LE,type_bool,NULL,(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 233 "exp.y" /* yacc.c:1646  */
    {(yyval) =createtree(0,nodetype_GT,type_bool,NULL,(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 234 "exp.y" /* yacc.c:1646  */
    {(yyval) =createtree(0,nodetype_GE,type_bool,NULL,(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 235 "exp.y" /* yacc.c:1646  */
    {(yyval) =createtree(0,nodetype_EQ,type_bool,NULL,(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 236 "exp.y" /* yacc.c:1646  */
    {(yyval) =createtree(0,nodetype_NE,type_bool,NULL,(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 237 "exp.y" /* yacc.c:1646  */
    {
								Ltemp=LLookup((yyvsp[0])->varname);
								if(Ltemp==NULL)
								{
									tempst=GLookup((yyvsp[0])->varname);
									if(tempst==NULL)
									{yyerror("undefined Variable ");printf(" %s\n",(yyvsp[0])->varname );exit(1);}
									else {(yyvsp[0])->Gentry=tempst; (yyvsp[0])->type=tempst->type;}
								}
								else
								{
									(yyvsp[0])->Lentry=Ltemp;
									if(Ltemp->type==type_argint||Ltemp->type==type_argintref)
										(yyvsp[0])->type=type_int;
									else if(Ltemp->type==type_argchar||Ltemp->type==type_argcharref)
										(yyvsp[0])->type=type_char;
									else
										(yyvsp[0])->type=Ltemp->type;	
								}
								(yyval) = (yyvsp[0]);
							}
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 258 "exp.y" /* yacc.c:1646  */
    {
								tempst=GLookup((yyvsp[-3])->varname);
								if(tempst==NULL)
								{yyerror("undefined Variable");printf("%s\n",(yyvsp[-3])->varname );exit(1);}
								else {	(yyvsp[-3])->Gentry=tempst; 
										if(tempst->type==type_arrint)
											(yyvsp[-3])->type=type_int;
										else if(tempst->type==type_str)
											(yyvsp[-3])->type=type_char;
									 }
								(yyval) = createtree(0,nodetype_ARRID,(yyvsp[-3])->type,NULL,(yyvsp[-3]),(yyvsp[-1]),NULL);
							}
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 271 "exp.y" /* yacc.c:1646  */
    {
								tempst=GLookup((yyvsp[-6])->varname);
								if(tempst==NULL)
								{yyerror("undefined Variable");printf("%s\n",(yyvsp[-6])->varname );exit(1);}
								else {	(yyvsp[-6])->Gentry=tempst; 
										if(tempst->type==type_arrint)
											(yyvsp[-6])->type=type_int;
										else if(tempst->type==type_str)
											(yyvsp[-6])->type=type_char;
									 }
								(yyval) = createtree(0,nodetype_ARRID,(yyvsp[-6])->type,NULL,(yyvsp[-6]),(yyvsp[-4]),(yyvsp[-1]));
							}
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 283 "exp.y" /* yacc.c:1646  */
    {
								Ltemp=LLookup((yyvsp[0])->varname);
								if(Ltemp==NULL)
								{
									tempst=GLookup((yyvsp[0])->varname);
									if(tempst==NULL)
									{yyerror("undefined Variable");printf("%s\n",(yyvsp[0])->varname );exit(1);}
									else 
									{	
										(yyvsp[0])->Gentry=tempst; 
										if(tempst->type==type_intptr)
											(yyvsp[0])->type=type_int;
										else if(tempst->type==type_strptr)
											(yyvsp[0])->type=type_char; 
									}
								}
								else
								{
									(yyvsp[0])->Lentry=Ltemp; 
									if(Ltemp->type==type_intptr||Ltemp->type==type_argintref)
										(yyvsp[0])->type=type_int;
									else if(Ltemp->type==type_strptr||Ltemp->type==type_argcharref)
										(yyvsp[0])->type=type_char;
								}
								(yyval) = createtree(0,nodetype_POINTER,(yyvsp[0])->type,NULL,(yyvsp[0]),NULL,NULL);
							}
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 309 "exp.y" /* yacc.c:1646  */
    {
								Ltemp=LLookup((yyvsp[0])->varname);
								if(Ltemp==NULL)
								{
									tempst=GLookup((yyvsp[0])->varname);
									if(tempst==NULL)
									{yyerror("undefined Variable");printf("%s\n",(yyvsp[0])->varname );exit(1);}
									else
									{
										(yyvsp[0])->Gentry=tempst; 
										if(tempst->type==type_int||tempst->type==type_intptr)
											(yyvsp[0])->type=type_int;
										else if(tempst->type==type_char||tempst->type==type_strptr)
											(yyvsp[0])->type=type_char;
									}
								}
								else
								{
									(yyvsp[0])->Lentry=Ltemp; 
									if(Ltemp->type==type_int||Ltemp->type==type_intptr||Ltemp->type==type_argint||Ltemp->type==type_argintref)
										(yyvsp[0])->type=type_int;
									else if(Ltemp->type==type_char||Ltemp->type==type_strptr||Ltemp->type==type_argchar||Ltemp->type==type_argcharref)
										(yyvsp[0])->type=type_char;	
								}
								(yyval) = createtree(0,nodetype_ADDR,(yyvsp[0])->type,NULL,(yyvsp[0]),NULL,NULL);
							}
#line 2035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 335 "exp.y" /* yacc.c:1646  */
    {	
								tempst=GLookup((yyvsp[-2])->varname);
								if(tempst==NULL)
								{
									yyerror("undefined function");
									exit(1);
								}
								(yyvsp[-2])->Gentry=tempst;
								if(tempst->type==type_function_int)
									(yyvsp[-2])->type=type_int;
								else if(tempst->type==type_function_char)
									(yyvsp[-2])->type=type_char;
								(yyval)=createtree(0,nodetype_funcall,(yyvsp[-2])->type,(yyvsp[-2])->varname,(yyvsp[-2]),NULL,NULL);
							}
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 349 "exp.y" /* yacc.c:1646  */
    {
								tempst=GLookup((yyvsp[-3])->varname);
								if(tempst==NULL)
								{
									yyerror("undefined function");
									exit(1);
								}
								(yyvsp[-3])->Gentry=tempst;
								if(tempst->type==type_function_int)
									(yyvsp[-3])->type=type_int;
								else if(tempst->type==type_function_char)
									(yyvsp[-3])->type=type_char;
								else
								{
									yyerror("Variable is not a function");
									exit(1);
								}
								(yyval)=createtree(0,nodetype_funcall,(yyvsp[-3])->type,(yyvsp[-3])->varname,(yyvsp[-3]),(yyvsp[-1]),NULL);
							}
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 368 "exp.y" /* yacc.c:1646  */
    {
								tempst=GLookup((yyvsp[-2])->varname);
								if(tempst==NULL)
								{
									yyerror("undefined function");
									exit(1);
								}
								(yyvsp[-2])->Gentry=tempst;
								Ptemp=(yyvsp[-2])->Gentry->paramlist;
								while(Ptemp!=NULL)
								{
									if(strcmp(Ptemp->name,(yyvsp[0])->varname)==0)
										break;
									Ptemp=Ptemp->next;
								}
								if(Ptemp==NULL)
								{yyerror("Invalid reference");exit(1);}
								if(Ptemp->type==type_int)
									(yyvsp[-2])->type=type_int;
								else if(Ptemp->type==type_char)
									(yyvsp[-2])->type=type_char;
								(yyval)=createtree(0,nodetype_tuple,(yyvsp[-2])->type,NULL,(yyvsp[-2]),(yyvsp[0]),NULL);
							}
#line 2106 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 393 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_ARG,type_null,NULL,(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 2112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 394 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_ARG,type_null,NULL,NULL,(yyvsp[0]),NULL);}
#line 2118 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 397 "exp.y" /* yacc.c:1646  */
    {type=type_int;}
#line 2124 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 398 "exp.y" /* yacc.c:1646  */
    {type=type_char;}
#line 2130 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 399 "exp.y" /* yacc.c:1646  */
    {functype=type;}
#line 2136 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 399 "exp.y" /* yacc.c:1646  */
    { Ptemp=Phead;Phead=NULL;type=type_tuple; }
#line 2142 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 402 "exp.y" /* yacc.c:1646  */
    {printf("Global Symbol Table\n");printsymtab();decl=0;generate(target_file);printf("GDeclarations ok\n");}
#line 2148 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 403 "exp.y" /* yacc.c:1646  */
    {decl=0;}
#line 2154 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 406 "exp.y" /* yacc.c:1646  */
    {}
#line 2160 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 407 "exp.y" /* yacc.c:1646  */
    {}
#line 2166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 410 "exp.y" /* yacc.c:1646  */
    {}
#line 2172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 413 "exp.y" /* yacc.c:1646  */
    {}
#line 2178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 414 "exp.y" /* yacc.c:1646  */
    {}
#line 2184 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 417 "exp.y" /* yacc.c:1646  */
    {
									if(type==type_tuple)
									{
										GInstall((yyvsp[0])->varname,type,size,1,Ptemp);
									}
									else
										GInstall((yyvsp[0])->varname,type,1,1,NULL);
								}
#line 2197 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 425 "exp.y" /* yacc.c:1646  */
    {
									if(type==type_int)
										GInstall((yyvsp[-3])->varname,type_arrint,(yyvsp[-1])->val,1,NULL);
									else if(type==type_char)
										GInstall((yyvsp[-3])->varname,type_str,(yyvsp[-1])->val,1,NULL);
								}
#line 2208 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 431 "exp.y" /* yacc.c:1646  */
    {
											if(type==type_int)
												GInstall((yyvsp[-6])->varname,type_arrint,(yyvsp[-4])->val,(yyvsp[-1])->val,NULL);
											else if(type==type_char)
												GInstall((yyvsp[-6])->varname,type_str,(yyvsp[-4])->val,(yyvsp[-1])->val,NULL);
										}
#line 2219 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 437 "exp.y" /* yacc.c:1646  */
    {
									if(type==type_int)
										GInstall((yyvsp[0])->varname,type_intptr,1,1,NULL);
									else if(type==type_char)
										GInstall((yyvsp[0])->varname,type_strptr,1,1,NULL);
								}
#line 2230 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 443 "exp.y" /* yacc.c:1646  */
    {functype=type;}
#line 2236 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 443 "exp.y" /* yacc.c:1646  */
    {
									//printf("function to enter Gtable %d\n",type);
									if(functype==type_int)
										{GInstall((yyvsp[-4])->varname,type_function_int,0,1,Phead);printf("installed fun\n");}
									else if(functype==type_char)
										{GInstall((yyvsp[-4])->varname,type_function_char,0,1,Phead);printf("installed fun\n");}
									else if(functype==type_tuple)
										{Ptemp=Phead;type=type_tuple;}
									Phead=NULL;
								}
#line 2251 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 460 "exp.y" /* yacc.c:1646  */
    {}
#line 2257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 461 "exp.y" /* yacc.c:1646  */
    {}
#line 2263 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 464 "exp.y" /* yacc.c:1646  */
    {functype=type;}
#line 2269 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 464 "exp.y" /* yacc.c:1646  */
    {
																//printf("%d %s\n",$9->nodetype,$9->varname);
																validateparams(functype,(yyvsp[-8])->varname,Phead);
																//printf("f1\n");
																(yyvsp[-8])->Lentry=Lhead;
																//printf("f2\n");
																tempst=GLookup((yyvsp[-8])->varname);
																//printf("f3\n");
																(yyvsp[-8])->Gentry=tempst;
																//printf("f4\n");
																codegen_func((yyvsp[-8]),(yyvsp[-1]),target_file);
																//printf("f9\n");															
																Ltemp=Lhead;						//clear LSymbol table
																while(Ltemp!=NULL)
																{
																	Lhead=Ltemp;
																	Ltemp=Ltemp->next;
																	free(Lhead->name);
																	free(Lhead);
																}
																//printf("f10\n");
																Lhead=NULL;
																lvaradrs=1;
																padrs=-3;
																Phead=NULL;
																printf("FDefinition %d ok\n",tempst->flabel);
															 }
#line 2301 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 493 "exp.y" /* yacc.c:1646  */
    {//printf("parameter installed ok\n");
										}
#line 2308 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 495 "exp.y" /* yacc.c:1646  */
    {size=1;}
#line 2314 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 499 "exp.y" /* yacc.c:1646  */
    {
								if(type==type_int) 
									type=type_argint;
								else 
									type=type_argchar;
								PInstall((yyvsp[0])->varname,type,passtype_val);
								if(decl==0)
									LInstall((yyvsp[0])->varname,type);
								size++;
							}
#line 2329 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 509 "exp.y" /* yacc.c:1646  */
    {
								if(type==type_int) 
									type=type_argintref;
								else 
									type=type_argcharref;
								PInstall((yyvsp[0])->varname,type,passtype_ref);
								if(decl==0)
									LInstall((yyvsp[0])->varname,type);
								size++;
							}
#line 2344 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 522 "exp.y" /* yacc.c:1646  */
    {	
															GInstall("main",type_function_int,0,1,NULL);
															//printf("m1\n");
															(yyval)=createtree(0,nodetype_MAIN,type_int,NULL,(yyvsp[-1]),NULL,NULL);
															//printf("m2\n");
															codegen((yyval),target_file);
															printf("Main function ok\n");
														}
#line 2357 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 533 "exp.y" /* yacc.c:1646  */
    {}
#line 2363 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 534 "exp.y" /* yacc.c:1646  */
    {}
#line 2369 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 535 "exp.y" /* yacc.c:1646  */
    {}
#line 2375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 538 "exp.y" /* yacc.c:1646  */
    {}
#line 2381 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 539 "exp.y" /* yacc.c:1646  */
    {}
#line 2387 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 542 "exp.y" /* yacc.c:1646  */
    {}
#line 2393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 545 "exp.y" /* yacc.c:1646  */
    {LInstall((yyvsp[0])->varname,type);}
#line 2399 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 546 "exp.y" /* yacc.c:1646  */
    {LInstall((yyvsp[0])->varname,type);}
#line 2405 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2409 "y.tab.c" /* yacc.c:1646  */
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
#line 550 "exp.y" /* yacc.c:1906  */



void yyerror(char const *s)
{
	printf("yyerror %s at line %d\n",s,lcnt);
}


int main(void) 
{
	FILE *fp=fopen("input","r");
	if(fp)
		yyin=fp;
	else
		printf("Input file error\n");
	target_file=fopen("intermediate.xsm","w");
	
	lcnt=1;
	Ghead=NULL;
	Lhead=NULL;
	Phead=NULL;

	varadrs=4096;
	flabel=1;
	lvaradrs=1;
	padrs=-3;

	yyparse();
	return 0;
}
