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
int arg=0,func=0;
void yyerror(char const *s);
#include "symboltable.h"
#include "abstracttree.h"
#include "abstracttree.c"
#include "symboltable.c"
#include "codegen.c"
//int yydebug=1;
int yylex(void);
FILE *yyin,*target_file;
int reg,decl=1,size=0;
struct Typetable *type,*functype;
char *tuplename;


#line 87 "y.tab.c" /* yacc.c:339  */

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
    NUL = 300
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

#line 228 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   657

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  264

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    55,     2,
      49,    50,     2,     2,    56,     2,    54,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    48,
       2,    53,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    52,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,    47,     2,     2,     2,     2,
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
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    31,    31,    32,    33,    36,    37,    40,    41,    44,
      44,    47,    48,    51,    53,    54,    55,    59,    60,    64,
      65,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      79,    82,    98,   112,   129,   132,   135,   170,   182,   196,
     226,   247,   248,   269,   272,   293,   296,   303,   341,   342,
     345,   346,   347,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,   365,   381,   394,
     406,   432,   462,   473,   484,   487,   488,   492,   493,   496,
     497,   500,   503,   504,   507,   510,   516,   522,   528,   528,
     542,   543,   546,   546,   574,   576,   577,   580,   585,   597,
     608,   609,   610,   613,   614,   617,   620,   621
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "START", "END", "NUM", "STRING", "ID",
  "PLUS", "MINUS", "MUL", "DIV", "MOD", "READ", "WRITE", "IF", "THEN",
  "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "REPEAT", "UNTIL", "BREAK",
  "CNTU", "LT", "LE", "GT", "GE", "EQ", "NE", "DECL", "ENDDECL", "MAIN1",
  "RETURN", "INTG", "STR", "TUPLE", "POINTER", "TYPE", "ENDTYPE", "ALLOC",
  "FREE", "INIT", "NUL", "'{'", "'}'", "';'", "'('", "')'", "'['", "']'",
  "'='", "'.'", "'&'", "','", "$accept", "program", "TypeDefBlock",
  "TypeDefList", "TypeDef", "$@1", "FieldDeclList", "FieldDecl",
  "TypeName", "Body", "Slist", "Stmt", "RET", "InputStmt", "OutputStmt",
  "AsgStmt", "FreeStmt", "FIELD", "IfStmt", "WhileStmt", "expr", "ArgList",
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
     295,   296,   297,   298,   299,   300,   123,   125,    59,    40,
      41,    91,    93,    61,    46,    38,    44
};
# endif

#define YYPACT_NINF -88

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-88)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      12,   -16,    35,    65,    78,   -88,    67,    75,    -3,   -88,
     -88,     3,    94,    76,   -88,   -88,   -88,   -88,   -88,   -88,
     -88,    54,    87,   -88,   -16,   127,    94,   -88,   -88,    93,
     112,    48,   144,   -42,   -88,   -88,   -88,   125,   -88,   -88,
     150,    -2,   -88,   181,   -88,   178,   -88,   -88,    54,   -88,
     108,   186,   -88,   -88,   147,   112,   156,   -88,   112,   -88,
     214,   136,   -88,   425,   175,   -88,   155,   -39,   -88,   145,
     -35,   -88,   -32,   -88,   -88,   192,   247,   227,   174,   180,
     211,   217,   582,   582,   219,   225,    80,   226,   451,   -88,
     -88,   -88,   -88,   -88,   -88,    20,   -88,   -88,   -88,   -88,
     258,   -88,   112,   271,   231,   -88,   278,   -88,    80,     2,
     279,   240,   292,    80,    80,    80,   608,   504,   -88,   -88,
     -88,   -88,    42,   295,   -88,    80,   301,   255,   329,   303,
     270,   -88,    53,   312,   -88,   -88,   268,   150,   -88,   149,
     272,   284,   353,   -88,    80,    38,    59,   228,   253,   261,
     285,   293,    62,    80,   -88,   286,   -88,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,   -88,    82,   113,
     -88,   294,   359,   -88,   -88,   186,    99,   291,   304,   -88,
     365,   280,    80,   -88,   287,   328,   325,    80,    80,   -88,
     626,   -28,   176,   -88,   452,   452,   479,   479,   505,   505,
     505,   505,   505,   505,   305,   317,   316,   -88,   331,    80,
      80,   324,   354,   -88,   -88,   183,   -88,   582,   582,   296,
     321,   -88,    80,   357,   -88,   -88,   361,   -88,   189,   389,
     -88,   -88,     5,   478,   530,    -7,   362,   626,    80,   -88,
     358,   -88,   364,    80,   582,   366,   379,   -88,   -88,   216,
      80,   -88,   222,   556,   -88,   -88,   -88,   395,   378,   382,
     -88,   383,   -88,   -88
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     0,     0,     0,     4,     0,     0,     0,     8,
       1,     0,     0,     0,     9,     5,     7,    16,    78,    14,
      15,     0,     0,    80,    14,     0,     0,    91,     3,     0,
       0,    84,     0,     0,    83,    77,    79,     0,    90,     2,
     102,     0,    12,     0,    88,     0,    87,    81,     0,    92,
       0,     0,    10,    11,     0,    96,     0,    82,    96,   101,
       0,     0,   104,     0,     0,    13,     0,     0,    95,    85,
       0,   107,     0,   100,   103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    20,
      28,    21,    22,    23,    29,     0,    24,    25,    99,    97,
       0,    89,     0,     0,     0,   105,     0,    18,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,    27,
      58,    59,    67,     0,    60,     0,     0,    74,     0,     0,
       0,    19,     0,     0,    98,    94,     0,   102,   106,     0,
       0,     0,     0,    47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    70,     0,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    30,     0,     0,
      17,     0,     0,    46,    86,     0,     0,     0,     0,    36,
       0,     0,     0,    34,     0,     0,     0,     0,     0,    72,
      76,     0,     0,    57,    53,    54,    55,    56,    61,    62,
      63,    64,    65,    66,     0,     0,     0,    43,     0,     0,
       0,     0,     0,    39,    31,     0,    35,     0,     0,     0,
       0,    73,     0,    68,    44,    45,     0,    93,     0,     0,
      40,    42,     0,     0,     0,     0,     0,    75,     0,    41,
       0,    37,     0,     0,     0,     0,     0,    51,    52,     0,
       0,    32,     0,     0,    49,    50,    69,     0,     0,     0,
      38,     0,    48,    33
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -88,   -88,   -88,   -88,   426,   -88,   -88,   392,    92,   266,
     -80,   -87,   -88,   -88,   -88,   -88,   -88,   -63,   -88,   -88,
     -82,   -88,   -88,   -88,   414,   -88,   394,   -88,   -88,   420,
     -88,   390,   349,    11,   315,   -88,   393,   -88
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     8,     9,    30,    41,    42,    66,    64,
      88,    89,    90,    91,    92,    93,    94,   127,    96,    97,
     128,   191,    12,    22,    23,    33,    34,    55,    26,    27,
      58,    67,    68,     5,    51,    61,    62,    72
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      95,   131,   116,   117,     7,    17,    47,   120,   121,   122,
      17,   101,   123,   218,    48,   104,   105,   102,     6,    95,
      95,   102,   221,    28,   106,    95,   139,   142,   222,   131,
     131,   147,   148,   149,    19,    20,    18,    39,    15,    19,
      20,   247,     7,   155,   140,    52,   141,   124,     1,   146,
     172,   125,     2,    95,    95,   242,   243,   126,   120,   121,
     122,    31,   180,   123,    32,    10,   169,   120,   121,   122,
     190,   192,   123,   132,   133,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   120,   121,   122,   181,   182,
     123,   152,   110,   153,    17,   171,   110,    44,   124,    45,
     215,    17,   125,    21,    25,   219,   220,   124,   126,   183,
      11,   125,   189,   133,    21,    17,    13,   126,    25,    17,
      35,    14,    43,    19,    20,   124,    29,   228,   229,   125,
      24,    20,   204,    43,    37,   126,   110,   233,   234,    40,
     237,    59,    60,    17,    19,    20,   131,   131,    19,    20,
     209,    46,   210,    60,    95,    95,   249,   157,   158,   159,
     160,   252,    99,   205,   253,   100,   131,   133,   257,    73,
      95,    95,    19,    20,    49,   161,   162,   163,   164,   165,
     166,    95,    50,    56,   157,   158,   159,   160,    54,    63,
      95,   157,   158,   159,   160,    65,   103,   157,   158,   159,
     160,   176,   161,   162,   163,   164,   165,   166,    69,   161,
     162,   163,   164,   165,   166,   161,   162,   163,   164,   165,
     166,    71,    98,   112,   157,   158,   159,   160,   223,   113,
     157,   158,   159,   160,   111,   232,   157,   158,   159,   160,
     107,   240,   161,   162,   163,   164,   165,   166,   161,   162,
     163,   164,   165,   166,   161,   162,   163,   164,   165,   166,
     114,   157,   158,   159,   160,   134,   115,   118,   256,   157,
     158,   159,   160,   119,   258,   129,   136,   137,   184,   161,
     162,   163,   164,   165,   166,   138,   143,   161,   162,   163,
     164,   165,   166,   144,   157,   158,   159,   160,   108,   145,
     109,   110,   154,   185,   157,   158,   159,   160,   156,   133,
     168,   186,   161,   162,   163,   164,   165,   166,   170,   173,
     174,   177,   161,   162,   163,   164,   165,   166,   214,   157,
     158,   159,   160,   178,   187,   216,   193,   157,   158,   159,
     160,   211,   188,   206,   217,   218,   235,   161,   162,   163,
     164,   165,   166,   224,   212,   161,   162,   163,   164,   165,
     166,   157,   158,   159,   160,   225,   226,   157,   158,   159,
     160,   236,   230,   157,   158,   159,   160,   167,   227,   161,
     162,   163,   164,   165,   166,   161,   162,   163,   164,   165,
     166,   161,   162,   163,   164,   165,   166,   157,   158,   159,
     160,   179,   231,   157,   158,   159,   160,   207,   238,   239,
     248,   250,   251,   213,   254,   161,   162,   163,   164,   165,
     166,   161,   162,   163,   164,   165,   166,   255,   261,    75,
     262,   263,    76,    53,    16,    77,    36,   241,    78,    79,
      80,   208,    57,   260,    81,    82,    38,    83,    70,    84,
      85,   135,   175,     0,    74,   130,     0,     0,    76,     0,
      86,    77,   159,   160,    78,    79,    80,     0,    87,     0,
      81,    82,     0,    83,     0,    84,    85,     0,   161,   162,
     163,   164,   165,   166,     0,    76,    86,     0,    77,     0,
       0,    78,    79,    80,    87,   244,   245,    81,    82,     0,
      83,     0,    84,    85,     0,   161,   162,   163,   164,   165,
     166,    76,     0,    86,    77,     0,     0,    78,    79,    80,
       0,    87,     0,    81,    82,     0,    83,   151,    84,    85,
       0,    -1,    -1,    -1,    -1,    -1,    -1,    76,     0,    86,
      77,     0,     0,    78,    79,    80,     0,    87,     0,    81,
      82,   246,    83,     0,    84,    85,     0,     0,     0,     0,
       0,     0,     0,    76,     0,    86,    77,     0,     0,    78,
      79,    80,     0,    87,   259,    81,    82,     0,    83,     0,
      84,    85,     0,     0,     0,     0,     0,     0,     0,    76,
       0,    86,    77,     0,     0,    78,    79,    80,     0,    87,
       0,    81,    82,     0,    83,     0,    84,    85,     0,     0,
       0,     0,     0,     0,     0,    76,     0,    86,    77,     0,
       0,    78,    79,    80,     0,    87,     0,   150,    82,     0,
      83,     0,    84,    85,   157,   158,   159,   160,     0,     0,
       0,     0,     0,    86,     0,     0,     0,     0,     0,     0,
       0,    87,   161,   162,   163,   164,   165,   166
};

static const yytype_int16 yycheck[] =
{
      63,    88,    82,    83,     7,     7,    48,     5,     6,     7,
       7,    50,    10,    20,    56,    50,    48,    56,    34,    82,
      83,    56,    50,    12,    56,    88,   108,   109,    56,   116,
     117,   113,   114,   115,    36,    37,    33,    26,    41,    36,
      37,    48,     7,   125,    42,    47,    44,    45,    36,   112,
     132,    49,    40,   116,   117,    50,    51,    55,     5,     6,
       7,     7,   144,    10,    10,     0,   129,     5,     6,     7,
     152,   153,    10,    53,    54,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,     5,     6,     7,    50,    51,
      10,    49,    54,    51,     7,    42,    54,    49,    45,    51,
     182,     7,    49,    11,    12,   187,   188,    45,    55,    50,
      32,    49,    50,    54,    22,     7,    49,    55,    26,     7,
      33,    46,    30,    36,    37,    45,    50,   209,   210,    49,
      36,    37,    50,    41,     7,    55,    54,   217,   218,    46,
     222,    33,    50,     7,    36,    37,   233,   234,    36,    37,
      51,     7,    53,    61,   217,   218,   238,     8,     9,    10,
      11,   243,     7,    50,   244,    10,   253,    54,   250,    33,
     233,   234,    36,    37,    49,    26,    27,    28,    29,    30,
      31,   244,    32,     5,     8,     9,    10,    11,     7,     3,
     253,     8,     9,    10,    11,    48,    51,     8,     9,    10,
      11,    52,    26,    27,    28,    29,    30,    31,    52,    26,
      27,    28,    29,    30,    31,    26,    27,    28,    29,    30,
      31,     7,    47,    49,     8,     9,    10,    11,    52,    49,
       8,     9,    10,    11,     7,    52,     8,     9,    10,    11,
      48,    52,    26,    27,    28,    29,    30,    31,    26,    27,
      28,    29,    30,    31,    26,    27,    28,    29,    30,    31,
      49,     8,     9,    10,    11,     7,    49,    48,    52,     8,
       9,    10,    11,    48,    52,    49,     5,    46,    50,    26,
      27,    28,    29,    30,    31,     7,     7,    26,    27,    28,
      29,    30,    31,    53,     8,     9,    10,    11,    51,     7,
      53,    54,     7,    50,     8,     9,    10,    11,     7,    54,
       7,    50,    26,    27,    28,    29,    30,    31,    48,     7,
      52,    49,    26,    27,    28,    29,    30,    31,    48,     8,
       9,    10,    11,    49,    49,    48,    50,     8,     9,    10,
      11,    50,    49,    49,    16,    20,    50,    26,    27,    28,
      29,    30,    31,    48,    50,    26,    27,    28,    29,    30,
      31,     8,     9,    10,    11,    48,    50,     8,     9,    10,
      11,    50,    48,     8,     9,    10,    11,    48,    47,    26,
      27,    28,    29,    30,    31,    26,    27,    28,    29,    30,
      31,    26,    27,    28,    29,    30,    31,     8,     9,    10,
      11,    48,    48,     8,     9,    10,    11,    48,    51,    48,
      48,    53,    48,    48,    48,    26,    27,    28,    29,    30,
      31,    26,    27,    28,    29,    30,    31,    48,    50,     4,
      48,    48,     7,    41,     8,    10,    22,    48,    13,    14,
      15,   175,    48,    48,    19,    20,    26,    22,    58,    24,
      25,   102,   137,    -1,    61,     4,    -1,    -1,     7,    -1,
      35,    10,    10,    11,    13,    14,    15,    -1,    43,    -1,
      19,    20,    -1,    22,    -1,    24,    25,    -1,    26,    27,
      28,    29,    30,    31,    -1,     7,    35,    -1,    10,    -1,
      -1,    13,    14,    15,    43,    17,    18,    19,    20,    -1,
      22,    -1,    24,    25,    -1,    26,    27,    28,    29,    30,
      31,     7,    -1,    35,    10,    -1,    -1,    13,    14,    15,
      -1,    43,    -1,    19,    20,    -1,    22,    23,    24,    25,
      -1,    26,    27,    28,    29,    30,    31,     7,    -1,    35,
      10,    -1,    -1,    13,    14,    15,    -1,    43,    -1,    19,
      20,    21,    22,    -1,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     7,    -1,    35,    10,    -1,    -1,    13,
      14,    15,    -1,    43,    18,    19,    20,    -1,    22,    -1,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     7,
      -1,    35,    10,    -1,    -1,    13,    14,    15,    -1,    43,
      -1,    19,    20,    -1,    22,    -1,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     7,    -1,    35,    10,    -1,
      -1,    13,    14,    15,    -1,    43,    -1,    19,    20,    -1,
      22,    -1,    24,    25,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    26,    27,    28,    29,    30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    36,    40,    58,    59,    90,    34,     7,    60,    61,
       0,    32,    79,    49,    46,    41,    61,     7,    33,    36,
      37,    65,    80,    81,    36,    65,    85,    86,    90,    50,
      62,     7,    10,    82,    83,    33,    81,     7,    86,    90,
      46,    63,    64,    65,    49,    51,     7,    48,    56,    49,
      32,    91,    47,    64,     7,    84,     5,    83,    87,    33,
      65,    92,    93,     3,    66,    48,    65,    88,    89,    52,
      88,     7,    94,    33,    93,     4,     7,    10,    13,    14,
      15,    19,    20,    22,    24,    25,    35,    43,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    47,     7,
      10,    50,    56,    51,    50,    48,    56,    48,    51,    53,
      54,     7,    49,    49,    49,    49,    67,    67,    48,    48,
       5,     6,     7,    10,    45,    49,    55,    74,    77,    49,
       4,    68,    53,    54,     7,    89,     5,    46,     7,    77,
      42,    44,    77,     7,    53,     7,    74,    77,    77,    77,
      19,    23,    49,    51,     7,    77,     7,     8,     9,    10,
      11,    26,    27,    28,    29,    30,    31,    48,     7,    74,
      48,    42,    77,     7,    52,    91,    52,    49,    49,    48,
      77,    50,    51,    50,    50,    50,    50,    49,    49,    50,
      77,    78,    77,    50,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    50,    50,    49,    48,    66,    51,
      53,    50,    50,    48,    48,    77,    48,    16,    20,    77,
      77,    50,    56,    52,    48,    48,    50,    47,    77,    77,
      48,    48,    52,    67,    67,    50,    50,    77,    51,    48,
      52,    48,    50,    51,    17,    18,    21,    48,    48,    77,
      53,    48,    77,    67,    48,    48,    52,    77,    52,    18,
      48,    50,    48,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    58,    58,    59,    59,    60,    60,    62,
      61,    63,    63,    64,    65,    65,    65,    66,    66,    67,
      67,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      69,    70,    70,    70,    70,    71,    72,    72,    72,    72,
      72,    72,    72,    72,    73,    73,    74,    74,    75,    75,
      76,    76,    76,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    78,    78,    79,    79,    80,
      80,    81,    82,    82,    83,    83,    83,    83,    84,    83,
      85,    85,    87,    86,    88,    88,    88,    89,    89,    90,
      91,    91,    91,    92,    92,    93,    94,    94
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     3,     1,     3,     0,     2,     1,     0,
       5,     2,     1,     3,     1,     1,     1,     4,     3,     2,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       3,     5,     8,    11,     4,     5,     4,     7,    10,     5,
       6,     6,     6,     4,     5,     5,     3,     3,    10,     8,
       8,     7,     7,     3,     3,     3,     3,     3,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     1,     4,     7,
       2,     2,     3,     4,     1,     3,     1,     3,     2,     2,
       1,     3,     3,     1,     1,     4,     7,     2,     0,     5,
       2,     1,     0,    10,     3,     1,     0,     2,     3,     8,
       3,     2,     0,     2,     1,     3,     3,     1
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
#line 31 "exp.y" /* yacc.c:1646  */
    {end(target_file); printf("%d",count);}
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 32 "exp.y" /* yacc.c:1646  */
    {end(target_file);}
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 33 "exp.y" /* yacc.c:1646  */
    {end(target_file);}
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 36 "exp.y" /* yacc.c:1646  */
    {print1();}
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 40 "exp.y" /* yacc.c:1646  */
    {}
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 44 "exp.y" /* yacc.c:1646  */
    {Tptr = TInstall((yyvsp[-1])->varname,0,NULL);}
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 44 "exp.y" /* yacc.c:1646  */
    { Tptr->fields=Fhead;Tptr->size=size;size=0;Fhead=NULL;}
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 47 "exp.y" /* yacc.c:1646  */
    {}
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 48 "exp.y" /* yacc.c:1646  */
    {}
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 51 "exp.y" /* yacc.c:1646  */
    {FInstall((yyvsp[-1])->varname,size,type);size++;}
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 53 "exp.y" /* yacc.c:1646  */
    {type=typeint;}
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 54 "exp.y" /* yacc.c:1646  */
    {type=typestr;}
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 55 "exp.y" /* yacc.c:1646  */
    {type=TLookup((yyvsp[0])->varname);if(type==NULL) {printf("Invalid Type %s at line %d\n",(yyvsp[0])->type->name,lcnt);exit(1);}}
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 59 "exp.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-2]);}
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 60 "exp.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 64 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_NULL,typevoid,NULL,(yyvsp[-1]),(yyvsp[0]),NULL);}
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 65 "exp.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 68 "exp.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 69 "exp.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 70 "exp.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 71 "exp.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 72 "exp.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 73 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_BRK,typevoid,NULL,NULL,NULL,NULL);}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 74 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_CNTU,typevoid,NULL,NULL,NULL,NULL);}
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 75 "exp.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 76 "exp.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 79 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_RET,typevoid,NULL,(yyvsp[-1]),NULL,NULL);}
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 82 "exp.y" /* yacc.c:1646  */
    {
									Ltemp=LLookup((yyvsp[-2])->varname);
									if(Ltemp==NULL)
									{
										tempst=GLookup((yyvsp[-2])->varname);
										if(tempst==NULL)
										{yyerror("undefined Variable");printf("%s\n",(yyvsp[-2])->varname );exit(1);}
										else {(yyvsp[-2])->Gentry=tempst;(yyvsp[-2])->type=tempst->type;}
									}
									else
									{
										(yyvsp[-2])->Lentry=Ltemp;
										(yyvsp[-2])->type=Ltemp->type;
									}
									(yyval)=createtree(0,nodetype_READ,typevoid,NULL,(yyvsp[-2]),NULL,NULL);
								}
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 98 "exp.y" /* yacc.c:1646  */
    {
												tempst=GLookup((yyvsp[-5])->varname);
												if(tempst==NULL)
												{yyerror("undefined Variable");printf("%s\n",(yyvsp[-5])->varname );exit(1);}
												else 
												{
													(yyvsp[-5])->Gentry=tempst;
													if(tempst->type==TLookup("arrint"))
														(yyvsp[-5])->type=typeint;
													else if(tempst->type==TLookup("arrstr"))
														(yyvsp[-5])->type=typestr;
												}
												(yyval)=createtree(0,nodetype_ARRREAD,typevoid,NULL,(yyvsp[-5]),(yyvsp[-3]),NULL);
											 }
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 112 "exp.y" /* yacc.c:1646  */
    {
															tempst=GLookup((yyvsp[-8])->varname);
															if(tempst==NULL)
															{yyerror("undefined Variable");printf("%s\n",(yyvsp[-8])->varname );exit(1);}
															else
															{ 
																(yyvsp[-8])->Gentry=tempst;
																if(tempst->type==TLookup("arrint"))
																	(yyvsp[-8])->type=typeint;
																else if(tempst->type==TLookup("arrstr"))
																	(yyvsp[-8])->type=typestr;
															}
															struct tnode *temp=createtree(tempst->s2,nodetype_LEAF,typeint,NULL,NULL,NULL,NULL);
															(yyvsp[-6])=createtree(0,nodetype_MUL,typeint,NULL,(yyvsp[-6]),temp,NULL);
															(yyvsp[-6])=createtree(0,nodetype_PLUS,typeint,NULL,(yyvsp[-6]),(yyvsp[-3]),NULL);
															(yyval)=createtree(0,nodetype_ARRREAD,typevoid,NULL,(yyvsp[-8]),(yyvsp[-6]),NULL);
														   }
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 129 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_UREAD,typevoid,NULL,(yyvsp[-1]),NULL,NULL);}
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 132 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_WRITE,typevoid,NULL,(yyvsp[-2]),NULL,NULL);}
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 135 "exp.y" /* yacc.c:1646  */
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
											if(tempst->type==TLookup("intptr"))
												(yyvsp[-3])->type=typeint;
											else if(tempst->type==TLookup("strptr"))
												(yyvsp[-3])->type=typestr;
											else
												(yyvsp[-3])->type=tempst->type;
										}
										//printf("A2\n");
									}
									else
									{
										(yyvsp[-3])->Lentry=Ltemp;
										if(Ltemp->type==TLookup("intptr"))
											(yyvsp[-3])->type=typeint;
										else if(Ltemp->type==TLookup("strptr"))
											(yyvsp[-3])->type=typestr;
										else
											(yyvsp[-3])->type=Ltemp->type;
										//printf("A3\n");
									}
									(yyval)=createtree(0,nodetype_ASGN,typevoid,NULL,(yyvsp[-3]),(yyvsp[-1]),NULL);
									//printf("Asgn node OK\n");
								}
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 170 "exp.y" /* yacc.c:1646  */
    {
												tempst=GLookup((yyvsp[-6])->varname);
												if(tempst==NULL)
												{yyerror("undefined Variable");printf("%s\n",(yyvsp[-6])->varname );exit(1);}
												else {	(yyvsp[-6])->Gentry=tempst;
														if(tempst->type==TLookup("arrint"))
															(yyvsp[-6])->type=typeint;
														else if(tempst->type==TLookup("arrstr"))
															(yyvsp[-6])->type=typestr;
													 }
												(yyval)=createtree(0,nodetype_ARRASGN,typevoid,NULL,(yyvsp[-6]),(yyvsp[-4]),(yyvsp[-1]));
											}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 182 "exp.y" /* yacc.c:1646  */
    { tempst=GLookup((yyvsp[-9])->varname);
												if(tempst==NULL)
												{yyerror("undefined Variable");printf("%s\n",(yyvsp[-9])->varname );exit(1);}
												else {	(yyvsp[-9])->Gentry=tempst;
														if(tempst->type==TLookup("arrint"))
															(yyvsp[-9])->type=typeint;
														else if(tempst->type==TLookup("arrstr"))
															(yyvsp[-9])->type=typestr;
													 }
												struct tnode *temp=createtree(tempst->s2,nodetype_LEAF,typeint,NULL,NULL,NULL,NULL);
												(yyvsp[-7])=createtree(0,nodetype_MUL,typeint,NULL,(yyvsp[-7]),temp,NULL);
												(yyvsp[-7])=createtree(0,nodetype_PLUS,typeint,NULL,(yyvsp[-7]),(yyvsp[-4]),NULL);
												(yyval)=createtree(0,nodetype_ARRASGN,typevoid,NULL,(yyvsp[-9]),(yyvsp[-7]),(yyvsp[-1])); 
											}
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 196 "exp.y" /* yacc.c:1646  */
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
													if(tempst->type==TLookup("intptr"))
														(yyvsp[-3])->type=typeint;
													else if(tempst->type==TLookup("strptr"))
														(yyvsp[-3])->type=typestr;
													else
														(yyvsp[-4])->type=tempst->type;
												}
											}
											else
											{
												(yyvsp[-3])->Lentry=Ltemp;
												if(Ltemp->type==TLookup("intptr"))
													(yyvsp[-3])->type=typeint;
												else if(Ltemp->type==TLookup("strptr"))
													(yyvsp[-3])->type=typestr;
												else
													(yyvsp[-4])->type=tempst->type;
											}
											(yyval)=createtree(0,nodetype_PASGN,typevoid,NULL,(yyvsp[-3]),(yyvsp[-1]),NULL);
										}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 226 "exp.y" /* yacc.c:1646  */
    {
											Ltemp=LLookup((yyvsp[-5])->varname);
											//printf("A1\n");
											if(Ltemp==NULL)
											{
												tempst=GLookup((yyvsp[-5])->varname);
												if(tempst==NULL)
												{yyerror("undefined Variable");printf("%s\n",(yyvsp[-5])->varname );exit(1);}
												else 
												{	
													(yyvsp[-5])->Gentry=tempst;
													(yyvsp[-5])->type=tempst->type;
												}
											}
											else
											{
												(yyvsp[-5])->Lentry=Ltemp;
												(yyvsp[-5])->type=Ltemp->type;
											}
											(yyval)=createtree(0,nodetype_ALLOCID,typevoid,NULL,(yyvsp[-5]),NULL,NULL);
										}
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 247 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_ALLOCFIELD,typevoid,NULL,(yyvsp[-5]),NULL,NULL);}
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 248 "exp.y" /* yacc.c:1646  */
    {
											Ltemp=LLookup((yyvsp[-5])->varname);
											//printf("A1\n");
											if(Ltemp==NULL)
											{
												tempst=GLookup((yyvsp[-5])->varname);
												if(tempst==NULL)
												{yyerror("undefined Variable");printf("%s\n",(yyvsp[-5])->varname );exit(1);}
												else 
												{	
													(yyvsp[-5])->Gentry=tempst;
													(yyvsp[-5])->type=tempst->type;
												}
											}
											else
											{
												(yyvsp[-5])->Lentry=Ltemp;
												(yyvsp[-5])->type=Ltemp->type;
											}
											(yyval)=createtree(0,nodetype_INIT,typevoid,NULL,(yyvsp[-5]),(yyvsp[-3]),NULL);
										}
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 269 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_ASGN,typevoid,NULL,(yyvsp[-3]),(yyvsp[-1]),NULL);}
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 272 "exp.y" /* yacc.c:1646  */
    {
										Ltemp=LLookup((yyvsp[-2])->varname);
											//printf("A1\n");
										if(Ltemp==NULL)
										{
											tempst=GLookup((yyvsp[-2])->varname);
											if(tempst==NULL)
											{yyerror("undefined Variable");printf("%s\n",(yyvsp[-2])->varname );exit(1);}
											else 
											{	
												(yyvsp[-2])->Gentry=tempst;
												(yyvsp[-2])->type=tempst->type;
											}
										}
										else
										{
											(yyvsp[-2])->Lentry=Ltemp;
											(yyvsp[-2])->type=Ltemp->type;
										}
										(yyval)=createtree(0,nodetype_FREE,typevoid,NULL,(yyvsp[-2]),NULL,NULL);
									}
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 293 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_FREE,typevoid,NULL,(yyvsp[-2]),NULL,NULL);}
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 296 "exp.y" /* yacc.c:1646  */
    {
								Ftemp=FLookup((yyvsp[-2])->type,(yyvsp[0])->varname);
								if(Ftemp==NULL)
									{yyerror("Invalid member");exit(1);}
								(yyvsp[0])->type=Ftemp->type;
								(yyval)=createtree(0,nodetype_FIELD,(yyvsp[0])->type,NULL,(yyvsp[-2]),(yyvsp[0]),NULL);
							}
#line 2007 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 303 "exp.y" /* yacc.c:1646  */
    {
	  							Ltemp=LLookup((yyvsp[-2])->varname);
									//printf("A1\n");
								if(Ltemp==NULL)
								{
									tempst=GLookup((yyvsp[-2])->varname);
									if(tempst==NULL)
									{yyerror("undefined Variable");printf("%s\n",(yyvsp[-2])->varname );exit(1);}
									else 
									{	
										(yyvsp[-2])->Gentry=tempst;
										if(tempst->type==TLookup("intptr"))
											(yyvsp[-2])->type=typeint;
										else if(tempst->type==TLookup("strptr"))
											(yyvsp[-2])->type=typestr;
										else
											(yyvsp[-2])->type=tempst->type;
										Ftemp=FLookup(tempst->type,(yyvsp[0])->varname);
										if(Ftemp==NULL)
											{yyerror("Invalid member");exit(1);}
										(yyvsp[0])->type=Ftemp->type;
									}
										//printf("A2\n");
								}
								else
								{
									(yyvsp[-2])->Lentry=Ltemp;
									(yyvsp[-2])->type=Ltemp->type;
									Ftemp=FLookup(Ltemp->type,(yyvsp[0])->varname);
									if(Ftemp==NULL)
										{yyerror("Invalid member");exit(1);}
									(yyvsp[0])->type=Ftemp->type;
									//printf("A3\n");
								}
	  							(yyval)=createtree(0,nodetype_FIELD,(yyvsp[0])->type,NULL,(yyvsp[-2]),(yyvsp[0]),NULL);
	  						}
#line 2048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 341 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_IF,typevoid,NULL,(yyvsp[-7]),(yyvsp[-4]),(yyvsp[-2]));}
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 342 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_IF,typevoid,NULL,(yyvsp[-5]),(yyvsp[-2]),NULL);}
#line 2060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 345 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_WHILE,typevoid,NULL,(yyvsp[-5]),(yyvsp[-2]),NULL);}
#line 2066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 346 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_DOWHILE,typevoid,NULL,(yyvsp[-2]),(yyvsp[-5]),NULL);}
#line 2072 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 347 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_REPEAT,typevoid,NULL,(yyvsp[-2]),(yyvsp[-5]),NULL);}
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 351 "exp.y" /* yacc.c:1646  */
    {(yyval) =createtree(0,nodetype_PLUS,typeint,NULL,(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 352 "exp.y" /* yacc.c:1646  */
    {(yyval) =createtree(0,nodetype_MINUS,typeint,NULL,(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 2090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 353 "exp.y" /* yacc.c:1646  */
    {(yyval) =createtree(0,nodetype_MUL,typeint,NULL,(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 2096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 354 "exp.y" /* yacc.c:1646  */
    {(yyval) =createtree(0,nodetype_DIV,typeint,NULL,(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 2102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 355 "exp.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 2108 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 356 "exp.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 357 "exp.y" /* yacc.c:1646  */
    {(yyval)	= (yyvsp[0]);}
#line 2120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 358 "exp.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2126 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 359 "exp.y" /* yacc.c:1646  */
    {(yyval) =createtree(0,nodetype_LT,TLookup("bool"),NULL,(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 2132 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 360 "exp.y" /* yacc.c:1646  */
    {(yyval) =createtree(0,nodetype_LE,TLookup("bool"),NULL,(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 2138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 361 "exp.y" /* yacc.c:1646  */
    {(yyval) =createtree(0,nodetype_GT,TLookup("bool"),NULL,(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 362 "exp.y" /* yacc.c:1646  */
    {(yyval) =createtree(0,nodetype_GE,TLookup("bool"),NULL,(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 2150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 363 "exp.y" /* yacc.c:1646  */
    {(yyval) =createtree(0,nodetype_EQ,TLookup("bool"),NULL,(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 2156 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 364 "exp.y" /* yacc.c:1646  */
    {(yyval) =createtree(0,nodetype_NE,TLookup("bool"),NULL,(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 2162 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 365 "exp.y" /* yacc.c:1646  */
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
									(yyvsp[0])->type=Ltemp->type;
								}
								(yyval) = (yyvsp[0]);
							}
#line 2183 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 381 "exp.y" /* yacc.c:1646  */
    {
								tempst=GLookup((yyvsp[-3])->varname);
								if(tempst==NULL)
								{yyerror("undefined Variable");printf("%s\n",(yyvsp[-3])->varname );exit(1);}
								else {	(yyvsp[-3])->Gentry=tempst; 
										if(tempst->type==TLookup("arrint"))
											(yyvsp[-3])->type=typeint;
										else if(tempst->type==TLookup("arrstr"))
											(yyvsp[-3])->type=typestr;
									 }
								(yyval) = createtree(0,nodetype_ARRID,(yyvsp[-3])->type,NULL,(yyvsp[-3]),(yyvsp[-1]),NULL);
							}
#line 2200 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 394 "exp.y" /* yacc.c:1646  */
    {
								tempst=GLookup((yyvsp[-6])->varname);
								if(tempst==NULL)
								{yyerror("undefined Variable");printf("%s\n",(yyvsp[-6])->varname );exit(1);}
								else {	(yyvsp[-6])->Gentry=tempst; 
										if(tempst->type==TLookup("arrint"))
											(yyvsp[-6])->type=typeint;
										else if(tempst->type==TLookup("arrstr"))
											(yyvsp[-6])->type=typestr;
									 }
								(yyval) = createtree(0,nodetype_ARRID,(yyvsp[-6])->type,NULL,(yyvsp[-6]),(yyvsp[-4]),(yyvsp[-1]));
							}
#line 2217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 406 "exp.y" /* yacc.c:1646  */
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
										if(tempst->type==TLookup("intptr"))
											(yyvsp[0])->type=typeint;
										else if(tempst->type==TLookup("strptr"))
											(yyvsp[0])->type=typestr;
									}
								}
								else
								{
									(yyvsp[0])->Lentry=Ltemp; 
									if(Ltemp->type==TLookup("intptr"))
										(yyvsp[0])->type=typeint;
									else if(Ltemp->type==TLookup("strptr"))
										(yyvsp[0])->type=typestr;
								}
								(yyval) = createtree(0,nodetype_POINTER,(yyvsp[0])->type,NULL,(yyvsp[0]),NULL,NULL);
							}
#line 2248 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 432 "exp.y" /* yacc.c:1646  */
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
										if(tempst->type==TLookup("intptr"))
											(yyvsp[0])->type=typeint;
										else if(tempst->type==TLookup("strptr"))
											(yyvsp[0])->type=typestr;
										else
											(yyvsp[0])->type=tempst->type;
									}
								}
								else
								{
									(yyvsp[0])->Lentry=Ltemp; 
									if(Ltemp->type==TLookup("intptr"))
										(yyvsp[0])->type=typeint;
									else if(Ltemp->type==TLookup("strptr"))
										(yyvsp[0])->type=typestr;
									else
										(yyvsp[0])->type=Ltemp->type;	
								}
								(yyval) = createtree(0,nodetype_ADDR,(yyvsp[0])->type,NULL,(yyvsp[0]),NULL,NULL);
							}
#line 2283 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 462 "exp.y" /* yacc.c:1646  */
    {	
								tempst=GLookup((yyvsp[-2])->varname);
								if(tempst==NULL)
								{
									yyerror("undefined function");
									exit(1);
								}
								(yyvsp[-2])->Gentry=tempst;
								(yyvsp[-2])->type=tempst->type;
								(yyval)=createtree(0,nodetype_funcall,(yyvsp[-2])->type,NULL,(yyvsp[-2]),NULL,NULL);
							}
#line 2299 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 473 "exp.y" /* yacc.c:1646  */
    {
								tempst=GLookup((yyvsp[-3])->varname);
								if(tempst==NULL)
								{
									yyerror("undefined function");
									exit(1);
								}
								(yyvsp[-3])->Gentry=tempst;
								(yyvsp[-3])->type=tempst->type;
								(yyval)=createtree(0,nodetype_funcall,(yyvsp[-3])->type,NULL,(yyvsp[-3]),(yyvsp[-1]),NULL);
							}
#line 2315 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 484 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_FIELDexpr,(yyvsp[0])->type,NULL,(yyvsp[0]),NULL,NULL);}
#line 2321 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 487 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_ARG,typevoid,NULL,(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 2327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 488 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_ARG,typevoid,NULL,NULL,(yyvsp[0]),NULL);}
#line 2333 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 492 "exp.y" /* yacc.c:1646  */
    {printf("Global Symbol Table\n");printsymtab();decl=0;generate(target_file);printf("GDeclarations ok\n");}
#line 2339 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 493 "exp.y" /* yacc.c:1646  */
    {decl=0;}
#line 2345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 496 "exp.y" /* yacc.c:1646  */
    {}
#line 2351 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 497 "exp.y" /* yacc.c:1646  */
    {}
#line 2357 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 500 "exp.y" /* yacc.c:1646  */
    {}
#line 2363 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 503 "exp.y" /* yacc.c:1646  */
    {}
#line 2369 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 504 "exp.y" /* yacc.c:1646  */
    {}
#line 2375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 507 "exp.y" /* yacc.c:1646  */
    {
									GInstall((yyvsp[0])->varname,type,1,1,NULL);
								}
#line 2383 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 510 "exp.y" /* yacc.c:1646  */
    {
									if(type==typeint)
										GInstall((yyvsp[-3])->varname,TLookup("arrint"),(yyvsp[-1])->val,1,NULL);
									else if(type==typestr)
										GInstall((yyvsp[-3])->varname,TLookup("arrstr"),(yyvsp[-1])->val,1,NULL);
								}
#line 2394 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 516 "exp.y" /* yacc.c:1646  */
    {
											if(type==typeint)
												GInstall((yyvsp[-6])->varname,TLookup("arrint"),(yyvsp[-4])->val,(yyvsp[-1])->val,NULL);
											else if(type==typestr)
												GInstall((yyvsp[-6])->varname,TLookup("arrstr"),(yyvsp[-4])->val,(yyvsp[-1])->val,NULL);
										}
#line 2405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 522 "exp.y" /* yacc.c:1646  */
    {
									if(type==typeint)
										GInstall((yyvsp[0])->varname,TLookup("intptr"),1,1,NULL);
									else if(type==typestr)
										GInstall((yyvsp[0])->varname,TLookup("strptr"),1,1,NULL);
								}
#line 2416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 528 "exp.y" /* yacc.c:1646  */
    {functype=type;}
#line 2422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 528 "exp.y" /* yacc.c:1646  */
    {
									//printf("function to enter Gtable %d\n",type);
									func=1;
									GInstall((yyvsp[-4])->varname,functype,0,1,Phead);printf("installed fun\n");
									func=0;
									Phead=NULL;
								}
#line 2434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 542 "exp.y" /* yacc.c:1646  */
    {}
#line 2440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 543 "exp.y" /* yacc.c:1646  */
    {}
#line 2446 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 546 "exp.y" /* yacc.c:1646  */
    {functype=type;}
#line 2452 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 546 "exp.y" /* yacc.c:1646  */
    {
																//printf("%d %s\n",$9->nodetype,$9->varname);
																validateparams(functype,(yyvsp[-8])->varname,Phead);
																//printf("f1\n");
																(yyvsp[-8])->Lentry=Lhead;
																//printf("f2\n");
																tempst=GLookup((yyvsp[-8])->varname);
																//printf("f3\n");
																(yyvsp[-8])->Gentry=tempst;
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
#line 2483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 574 "exp.y" /* yacc.c:1646  */
    {//printf("parameter installed ok\n");
										}
#line 2490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 576 "exp.y" /* yacc.c:1646  */
    {arg=0;}
#line 2496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 580 "exp.y" /* yacc.c:1646  */
    {
									PInstall((yyvsp[0])->varname,type,passtype_val);
									if(decl==0)
									{arg=1;LInstall((yyvsp[0])->varname,type);arg=0;}
								}
#line 2506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 585 "exp.y" /* yacc.c:1646  */
    {
									if(type==typeint)
										type=TLookup("intptr");
									else if(type==typestr)	
										type=TLookup("strptr");
									PInstall((yyvsp[0])->varname,type,passtype_ref);
									if(decl==0)
									{arg=1;	LInstall((yyvsp[0])->varname,type);arg=0;}
								}
#line 2520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 597 "exp.y" /* yacc.c:1646  */
    {	
															GInstall("main",typeint,0,1,NULL);
															//printf("m1\n");
															(yyval)=createtree(0,nodetype_MAIN,typeint,NULL,(yyvsp[-1]),NULL,NULL);
															//printf("m2\n");
															codegen((yyval),target_file);
															printf("Main function ok\n");
														}
#line 2533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 608 "exp.y" /* yacc.c:1646  */
    {}
#line 2539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 609 "exp.y" /* yacc.c:1646  */
    {}
#line 2545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 610 "exp.y" /* yacc.c:1646  */
    {}
#line 2551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 613 "exp.y" /* yacc.c:1646  */
    {}
#line 2557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 614 "exp.y" /* yacc.c:1646  */
    {}
#line 2563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 617 "exp.y" /* yacc.c:1646  */
    {}
#line 2569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 620 "exp.y" /* yacc.c:1646  */
    {arg=0;LInstall((yyvsp[0])->varname,type);}
#line 2575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 621 "exp.y" /* yacc.c:1646  */
    {arg=0;LInstall((yyvsp[0])->varname,type);}
#line 2581 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2585 "y.tab.c" /* yacc.c:1646  */
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
#line 625 "exp.y" /* yacc.c:1906  */



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

	TypeTableCreate();
	typeint=TLookup("int");
	typevoid=TLookup("void");
	typestr=TLookup("str");
	
	yyparse();
	return 0;
}
