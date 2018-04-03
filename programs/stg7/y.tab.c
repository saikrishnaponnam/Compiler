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
struct Classtable *Cptr;
#include "abstracttree.c"
#include "symboltable.c"
#include "codegen.c"
//int yydebug=1;
int yylex(void);
FILE *yyin,*target_file;
int reg,decl=1,size=0;
struct Typetable *type,*functype;
char *tuplename;



#line 89 "y.tab.c" /* yacc.c:339  */

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
    NUL = 300,
    CLASS = 301,
    ENDCLASS = 302,
    SELF = 303,
    Extends = 304,
    NEW = 305,
    DELETE = 306
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

#line 242 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   822

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  135
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  347

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    61,     2,
      55,    56,     2,     2,    62,     2,    60,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    54,
       2,    59,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,    58,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,    53,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    34,    34,    37,    38,    41,    42,    45,    45,    48,
      49,    52,    54,    55,    56,    67,    68,    71,    72,    75,
      75,    78,    79,    82,    83,    86,    87,    88,    91,    92,
      95,    96,    97,   100,   101,   105,   106,   110,   111,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   125,   128,
     144,   158,   175,   178,   181,   216,   228,   242,   272,   293,
     294,   315,   316,   324,   325,   328,   349,   352,   361,   397,
     414,   415,   418,   419,   420,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   455,   468,   480,   506,   536,   547,   548,   555,   556,
     557,   560,   574,   605,   616,   617,   618,   621,   622,   625,
     628,   629,   632,   635,   641,   647,   653,   653,   667,   668,
     671,   671,   713,   715,   716,   719,   724,   736,   747,   748,
     749,   752,   753,   756,   759,   760
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
  "FREE", "INIT", "NUL", "CLASS", "ENDCLASS", "SELF", "Extends", "NEW",
  "DELETE", "'{'", "'}'", "';'", "'('", "')'", "'['", "']'", "'='", "'.'",
  "'&'", "','", "$accept", "program", "TypeDefBlock", "TypeDefList",
  "TypeDef", "$@1", "FieldDeclList", "FieldDecl", "TypeName",
  "ClassDefBlock", "ClassDefList", "ClassDef", "$@2", "Cname",
  "Fieldlists", "Fld", "MethodDecl", "MDecl", "MethodDefns", "Body",
  "Slist", "Stmt", "RET", "InputStmt", "OutputStmt", "AsgStmt", "FreeStmt",
  "FIELD", "IfStmt", "WhileStmt", "expr", "ArgList", "FieldFunction",
  "GDeclarations", "GDeclList", "GDecl", "GidList", "Gid", "$@3",
  "FDeclarations", "Fdef", "$@4", "ParamList", "Param", "mainblk",
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   123,   125,    59,    40,    41,    91,    93,    61,
      46,    38,    44
};
# endif

#define YYPACT_NINF -141

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-141)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -16,    61,    98,     6,     9,     5,  -141,  -141,   127,   109,
    -141,  -141,  -141,   132,     0,  -141,    95,    92,  -141,    30,
     149,  -141,  -141,   155,  -141,  -141,  -141,  -141,    63,   125,
    -141,   107,    19,  -141,   191,  -141,  -141,   -21,   193,   -43,
    -141,  -141,  -141,   157,   225,  -141,  -141,  -141,  -141,   185,
     141,  -141,   242,  -141,  -141,    63,   196,   238,  -141,   283,
     294,   295,  -141,   147,  -141,    30,   256,  -141,   250,  -141,
     -40,    34,   228,   308,   315,   316,   299,  -141,   129,   -46,
    -141,   267,   281,    30,  -141,    30,  -141,    30,  -141,    30,
     279,   302,   303,    30,  -141,   339,  -141,    30,   349,   323,
      31,    54,    93,   151,    67,  -141,  -141,  -141,   320,   138,
     376,   328,   327,   330,   331,  -141,  -141,  -141,  -141,   375,
     143,  -141,   393,   334,   323,  -141,  -141,  -141,  -141,   -41,
    -141,  -141,   332,    64,   381,   343,   344,   346,   347,   718,
     718,   350,   351,   112,   354,   356,   355,   433,  -141,  -141,
    -141,  -141,  -141,  -141,    49,  -141,  -141,  -141,   376,  -141,
     404,  -141,   112,    52,   407,   360,    -6,   112,   112,   112,
     757,   601,  -141,  -141,  -141,  -141,   -22,   420,  -141,   378,
     112,   428,   379,   461,  -141,    -5,   435,    -3,   391,  -141,
      85,   442,   397,  -141,   194,   396,   399,   401,   490,  -141,
     112,   139,    15,   269,   300,   309,   405,   406,   112,   112,
     452,  -141,   455,   333,  -141,   456,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,  -141,    45,   103,
    -141,   414,   110,  -141,   409,   410,   496,  -141,  -141,   235,
     411,   419,   459,  -141,   502,   423,   112,  -141,   424,   463,
     460,   112,   112,   785,   184,   200,   427,   430,  -141,   431,
     791,   791,   395,   395,   395,   403,   403,   403,   403,   403,
     403,   429,   439,   440,   441,   488,  -141,   112,   112,   449,
     480,   453,  -141,  -141,   207,  -141,   718,   718,   340,   364,
    -141,   112,   478,   112,   112,   112,  -141,  -141,  -141,   482,
     481,   233,   531,  -141,  -141,   484,   248,   562,   640,    10,
     497,   785,   112,   251,   291,   321,  -141,   498,   437,  -141,
    -141,   499,   112,   718,   500,   501,  -141,  -141,   245,  -141,
    -141,  -141,  -141,   112,  -141,   258,   679,  -141,  -141,  -141,
     537,   514,   517,  -141,   519,  -141,  -141
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,    16,     0,     0,     6,     1,     0,   106,
       7,     3,     5,    21,     0,    18,     0,     0,   119,     0,
       0,    15,    17,     0,    14,   105,    12,    13,     0,     0,
     108,     0,     0,    10,     0,    22,    24,   112,     0,     0,
     111,   104,   107,    12,     0,   118,     2,     8,     9,     0,
       0,   116,     0,   115,   109,     0,     0,     0,    11,     0,
       0,     0,    23,    19,    29,   124,     0,   110,     0,   120,
       0,     0,     0,     0,     0,     0,     0,    28,     0,     0,
     123,   113,     0,   124,    25,   124,    26,   124,    27,   124,
       0,     0,     0,     0,   125,     0,   117,     0,     0,   130,
       0,     0,     0,     0,     0,    34,   126,   122,     0,     0,
       0,     0,     0,     0,     0,    20,    33,   114,   129,     0,
       0,   132,     0,     0,   130,    30,    31,    32,   135,     0,
     128,   131,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,    46,
      39,    40,    41,    47,     0,    42,    43,   127,     0,   133,
       0,    36,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    44,    45,    81,    82,    90,     0,    83,     0,
       0,     0,    96,     0,    97,     0,     0,     0,     0,    37,
       0,     0,     0,   134,     0,     0,     0,     0,     0,    68,
       0,     0,     0,     0,     0,     0,     0,     0,   100,     0,
       0,    93,     0,     0,    94,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,     0,     0,
      69,     0,     0,    35,     0,     0,     0,    67,   121,     0,
       0,     0,     0,    54,     0,     0,     0,    52,     0,     0,
       0,     0,     0,    99,     0,     0,    68,    69,    80,    67,
      75,    76,    77,    78,    79,    84,    85,    86,    87,    88,
      89,     0,     0,     0,     0,     0,    61,     0,     0,     0,
       0,     0,    57,    49,     0,    53,     0,     0,     0,     0,
      95,     0,    91,   100,   100,   100,    65,    66,    64,     0,
       0,     0,     0,    58,    60,     0,     0,     0,     0,     0,
       0,    98,     0,     0,     0,     0,    59,     0,     0,    55,
      62,     0,     0,     0,     0,     0,    73,    74,     0,   102,
     101,   103,    63,     0,    50,     0,     0,    71,    72,    92,
       0,     0,     0,    56,     0,    70,    51
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -141,  -141,  -141,  -141,   569,  -141,  -141,   546,    22,  -141,
    -141,   574,  -141,  -141,  -141,  -141,  -141,   520,  -141,   432,
    -134,  -139,  -141,  -141,  -141,  -141,  -141,  -122,  -141,  -141,
    -140,   -45,  -141,  -141,  -141,   560,  -141,   538,  -141,  -141,
     -84,  -141,   105,   495,  -141,   470,  -141,   475,  -141
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     5,     6,    19,    32,    33,    78,     9,
      14,    15,    76,    16,    50,    62,    63,    64,   104,   123,
     147,   148,   149,   150,   151,   152,   153,   182,   155,   156,
     253,   254,   184,    18,    29,    30,    39,    40,    65,    31,
      45,    83,    79,    80,    46,   110,   120,   121,   129
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     154,   201,   228,   183,   231,   170,   171,    13,   189,   105,
      96,    54,     4,   159,    84,    85,    97,   154,   154,    55,
     116,   160,   194,   198,     1,   154,    24,   203,   204,   205,
     287,   189,   189,   208,    51,   209,    52,    24,   210,    28,
     213,    34,   145,   145,   202,   145,    11,    21,   154,   154,
     236,    28,     8,    44,    34,    26,    27,   174,   175,   176,
     244,    10,   177,   229,   326,   232,    26,    27,     4,   255,
      37,   247,    47,    38,    24,   191,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   111,    86,    87,
     174,   175,   176,    97,   195,   177,   196,   178,     7,    24,
     179,   271,   197,    26,    27,   164,   284,   180,   190,   191,
     112,   288,   289,   181,    24,    44,    97,   174,   175,   176,
     115,   162,   177,   163,   164,    25,    44,   234,    26,    27,
     178,   119,    24,   179,    13,   235,    94,   301,   302,    95,
     180,    17,   119,    43,    27,    24,   181,    23,    59,   113,
      24,   311,   307,   308,    73,    97,    35,   178,    41,   272,
     179,    26,    27,   191,   154,   154,   273,   180,   189,   189,
     191,   118,   328,   181,    26,    27,   130,    60,    61,    26,
      27,    20,   335,    74,    75,   154,   154,    36,   100,   336,
     101,    56,   102,   340,   103,   245,   246,   189,    49,   164,
      53,   154,   216,   217,   218,   219,   220,   114,   216,   217,
     218,   219,   220,    97,   154,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   221,   222,   223,   224,
     225,   226,    57,   221,   222,   223,   224,   225,   226,    58,
     290,   216,   217,   218,   219,   220,   291,    66,   313,   314,
     315,    68,   239,   216,   217,   218,   219,   220,   292,   221,
     222,   223,   224,   225,   226,   306,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   216,   217,   218,
     219,   220,    88,    89,   221,   222,   223,   224,   225,   226,
      70,   318,   277,    69,   278,   221,   222,   223,   224,   225,
     226,    71,    72,   339,   321,   322,    82,   329,   216,   217,
     218,   219,   220,   291,    81,    90,   341,   216,   217,   218,
     219,   220,    91,    92,    98,   248,   221,   222,   223,   224,
     225,   226,    93,    99,    85,   221,   222,   223,   224,   225,
     226,   216,   217,   218,   219,   220,   106,   330,   216,   217,
     218,   219,   220,   291,   108,   109,   249,    87,    89,   221,
     222,   223,   224,   225,   226,   250,   221,   222,   223,   224,
     225,   226,   216,   217,   218,   219,   220,   331,   117,   122,
     124,   125,   128,   291,   126,   127,   161,   157,   165,   258,
     221,   222,   223,   224,   225,   226,   309,   132,   166,   167,
     133,   168,   169,   134,   172,   173,   135,   136,   137,   185,
     187,   193,   138,   139,   199,   140,   186,   141,   142,   200,
     310,   221,   222,   223,   224,   225,   226,   211,   143,    -1,
      -1,    -1,    -1,    -1,    -1,   214,   144,   188,   212,   215,
     133,   145,   230,   134,   146,   233,   135,   136,   137,   237,
     238,   240,   138,   139,   241,   140,   242,   141,   142,   256,
     251,   252,   257,   259,   274,   275,   281,   279,   143,   216,
     217,   218,   219,   220,   164,   280,   144,   283,   285,   286,
     287,   145,   293,   296,   146,   294,   295,   221,   222,   223,
     224,   225,   226,   297,   298,   300,   333,   299,   216,   217,
     218,   219,   220,   303,   216,   217,   218,   219,   220,   305,
     216,   217,   218,   219,   220,   227,   221,   222,   223,   224,
     225,   226,   221,   222,   223,   224,   225,   226,   221,   222,
     223,   224,   225,   226,   304,   312,   316,   317,   320,   216,
     217,   218,   219,   220,   243,   216,   217,   218,   219,   220,
     276,   327,   332,   334,   337,   338,   282,   221,   222,   223,
     224,   225,   226,   221,   222,   223,   224,   225,   226,   133,
     344,   345,   134,   346,    12,   135,   136,   137,    48,   323,
     324,   138,   139,    77,   140,   319,   141,   142,    22,    42,
     192,   343,   107,    67,   158,   131,     0,   143,     0,     0,
       0,     0,     0,     0,     0,   144,     0,     0,   133,     0,
     145,   134,     0,   146,   135,   136,   137,     0,     0,     0,
     138,   139,     0,   140,   207,   141,   142,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   143,     0,     0,     0,
       0,     0,     0,     0,   144,     0,     0,   133,     0,   145,
     134,     0,   146,   135,   136,   137,     0,     0,     0,   138,
     139,   325,   140,     0,   141,   142,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   143,     0,     0,     0,     0,
       0,     0,     0,   144,     0,     0,   133,     0,   145,   134,
       0,   146,   135,   136,   137,     0,     0,   342,   138,   139,
       0,   140,     0,   141,   142,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   143,     0,     0,     0,     0,     0,
       0,     0,   144,     0,     0,   133,     0,   145,   134,     0,
     146,   135,   136,   137,     0,     0,     0,   138,   139,     0,
     140,     0,   141,   142,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   143,     0,     0,     0,     0,     0,     0,
       0,   144,     0,     0,   133,     0,   145,   134,     0,   146,
     135,   136,   137,     0,     0,     0,   206,   139,     0,   140,
       0,   141,   142,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   143,   216,   217,   218,   219,   220,     0,     0,
     144,   218,   219,   220,     0,   145,     0,     0,   146,     0,
       0,   221,   222,   223,   224,   225,   226,   221,   222,   223,
     224,   225,   226
};

static const yytype_int16 yycheck[] =
{
     122,     7,     7,   143,     7,   139,   140,     7,   147,    93,
      56,    54,     7,    54,    54,    55,    62,   139,   140,    62,
     104,    62,   162,   163,    40,   147,     7,   167,   168,   169,
      20,   170,   171,    55,    55,    57,    57,     7,    60,    17,
     180,    19,    48,    48,   166,    48,    41,    47,   170,   171,
     190,    29,    46,    31,    32,    36,    37,     5,     6,     7,
     200,    52,    10,   185,    54,   187,    36,    37,     7,   209,
       7,    56,    53,    10,     7,    60,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,    56,    54,    55,
       5,     6,     7,    62,    42,    10,    44,    45,     0,     7,
      48,    56,    50,    36,    37,    60,   246,    55,    59,    60,
      56,   251,   252,    61,     7,    93,    62,     5,     6,     7,
      53,    57,    10,    59,    60,    33,   104,    42,    36,    37,
      45,   109,     7,    48,     7,    50,     7,   277,   278,    10,
      55,    32,   120,    36,    37,     7,    61,    52,     7,    56,
       7,   291,   286,   287,     7,    62,     7,    45,    33,    56,
      48,    36,    37,    60,   286,   287,    56,    55,   307,   308,
      60,    33,   312,    61,    36,    37,    33,    36,    37,    36,
      37,    49,   322,    36,    37,   307,   308,    32,    83,   323,
      85,    34,    87,   333,    89,    56,    57,   336,     7,    60,
       7,   323,     8,     9,    10,    11,    12,    56,     8,     9,
      10,    11,    12,    62,   336,     8,     9,    10,    11,    12,
      26,    27,    28,    29,    30,    31,    26,    27,    28,    29,
      30,    31,     7,    26,    27,    28,    29,    30,    31,    54,
      56,     8,     9,    10,    11,    12,    62,     5,   293,   294,
     295,    55,    58,     8,     9,    10,    11,    12,    58,    26,
      27,    28,    29,    30,    31,    58,     8,     9,    10,    11,
      12,    26,    27,    28,    29,    30,    31,     8,     9,    10,
      11,    12,    54,    55,    26,    27,    28,    29,    30,    31,
       7,    58,    57,    55,    59,    26,    27,    28,    29,    30,
      31,     7,     7,    58,    56,    57,    56,    56,     8,     9,
      10,    11,    12,    62,    58,     7,    58,     8,     9,    10,
      11,    12,     7,     7,    57,    56,    26,    27,    28,    29,
      30,    31,    33,    52,    55,    26,    27,    28,    29,    30,
      31,     8,     9,    10,    11,    12,     7,    56,     8,     9,
      10,    11,    12,    62,     5,    32,    56,    55,    55,    26,
      27,    28,    29,    30,    31,    56,    26,    27,    28,    29,
      30,    31,     8,     9,    10,    11,    12,    56,    58,     3,
      52,    54,     7,    62,    54,    54,    54,    53,     7,    56,
      26,    27,    28,    29,    30,    31,    56,     4,    55,    55,
       7,    55,    55,    10,    54,    54,    13,    14,    15,    55,
      55,     7,    19,    20,     7,    22,    60,    24,    25,    59,
      56,    26,    27,    28,    29,    30,    31,     7,    35,    26,
      27,    28,    29,    30,    31,     7,    43,     4,    60,    60,
       7,    48,     7,    10,    51,    54,    13,    14,    15,     7,
      53,    55,    19,    20,    55,    22,    55,    24,    25,     7,
      55,    55,     7,     7,    55,    55,     7,    56,    35,     8,
       9,    10,    11,    12,    60,    56,    43,    54,    54,    16,
      20,    48,    55,    54,    51,    55,    55,    26,    27,    28,
      29,    30,    31,    54,    54,     7,    59,    56,     8,     9,
      10,    11,    12,    54,     8,     9,    10,    11,    12,    56,
       8,     9,    10,    11,    12,    54,    26,    27,    28,    29,
      30,    31,    26,    27,    28,    29,    30,    31,    26,    27,
      28,    29,    30,    31,    54,    57,    54,    56,    54,     8,
       9,    10,    11,    12,    54,     8,     9,    10,    11,    12,
      54,    54,    54,    54,    54,    54,    54,    26,    27,    28,
      29,    30,    31,    26,    27,    28,    29,    30,    31,     7,
      56,    54,    10,    54,     5,    13,    14,    15,    32,    17,
      18,    19,    20,    63,    22,    54,    24,    25,    14,    29,
     158,    54,    97,    55,   124,   120,    -1,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,     7,    -1,
      48,    10,    -1,    51,    13,    14,    15,    -1,    -1,    -1,
      19,    20,    -1,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    -1,    -1,     7,    -1,    48,
      10,    -1,    51,    13,    14,    15,    -1,    -1,    -1,    19,
      20,    21,    22,    -1,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    -1,    -1,     7,    -1,    48,    10,
      -1,    51,    13,    14,    15,    -1,    -1,    18,    19,    20,
      -1,    22,    -1,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    -1,    -1,     7,    -1,    48,    10,    -1,
      51,    13,    14,    15,    -1,    -1,    -1,    19,    20,    -1,
      22,    -1,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    -1,    -1,     7,    -1,    48,    10,    -1,    51,
      13,    14,    15,    -1,    -1,    -1,    19,    20,    -1,    22,
      -1,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,     8,     9,    10,    11,    12,    -1,    -1,
      43,    10,    11,    12,    -1,    48,    -1,    -1,    51,    -1,
      -1,    26,    27,    28,    29,    30,    31,    26,    27,    28,
      29,    30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    40,    64,    65,     7,    66,    67,     0,    46,    72,
      52,    41,    67,     7,    73,    74,    76,    32,    96,    68,
      49,    47,    74,    52,     7,    33,    36,    37,    71,    97,
      98,   102,    69,    70,    71,     7,    32,     7,    10,    99,
     100,    33,    98,    36,    71,   103,   107,    53,    70,     7,
      77,    55,    57,     7,    54,    62,    34,     7,    54,     7,
      36,    37,    78,    79,    80,   101,     5,   100,    55,    55,
       7,     7,     7,     7,    36,    37,    75,    80,    71,   105,
     106,    58,    56,   104,    54,    55,    54,    55,    54,    55,
       7,     7,     7,    33,     7,    10,    56,    62,    57,    52,
     105,   105,   105,   105,    81,   103,     7,   106,     5,    32,
     108,    56,    56,    56,    56,    53,   103,    58,    33,    71,
     109,   110,     3,    82,    52,    54,    54,    54,     7,   111,
      33,   110,     4,     7,    10,    13,    14,    15,    19,    20,
      22,    24,    25,    35,    43,    48,    51,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    53,   108,    54,
      62,    54,    57,    59,    60,     7,    55,    55,    55,    55,
      83,    83,    54,    54,     5,     6,     7,    10,    45,    48,
      55,    61,    90,    93,    95,    55,    60,    55,     4,    84,
      59,    60,    82,     7,    93,    42,    44,    50,    93,     7,
      59,     7,    90,    93,    93,    93,    19,    23,    55,    57,
      60,     7,    60,    93,     7,    60,     8,     9,    10,    11,
      12,    26,    27,    28,    29,    30,    31,    54,     7,    90,
       7,     7,    90,    54,    42,    50,    93,     7,    53,    58,
      55,    55,    55,    54,    93,    56,    57,    56,    56,    56,
      56,    55,    55,    93,    94,    93,     7,     7,    56,     7,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    56,    56,    56,    55,    55,    54,    57,    59,    56,
      56,     7,    54,    54,    93,    54,    16,    20,    93,    93,
      56,    62,    58,    55,    55,    55,    54,    54,    54,    56,
       7,    93,    93,    54,    54,    56,    58,    83,    83,    56,
      56,    93,    57,    94,    94,    94,    54,    56,    58,    54,
      54,    56,    57,    17,    18,    21,    54,    54,    93,    56,
      56,    56,    54,    59,    54,    93,    83,    54,    54,    58,
      93,    58,    18,    54,    56,    54,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    65,    65,    66,    66,    68,    67,    69,
      69,    70,    71,    71,    71,    72,    72,    73,    73,    75,
      74,    76,    76,    77,    77,    78,    78,    78,    79,    79,
      80,    80,    80,    81,    81,    82,    82,    83,    83,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    85,    86,
      86,    86,    86,    87,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    89,    89,    90,    90,    90,
      91,    91,    92,    92,    92,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    94,    94,
      94,    95,    95,    95,    96,    96,    96,    97,    97,    98,
      99,    99,   100,   100,   100,   100,   101,   100,   102,   102,
     104,   103,   105,   105,   105,   106,   106,   107,   108,   108,
     108,   109,   109,   110,   111,   111
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     3,     0,     2,     1,     0,     5,     2,
       1,     3,     1,     1,     1,     3,     0,     2,     1,     0,
       9,     1,     3,     2,     0,     3,     3,     3,     2,     1,
       6,     6,     6,     2,     1,     4,     3,     2,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     3,     5,
       8,    11,     4,     5,     4,     7,    10,     5,     6,     6,
       6,     4,     7,     7,     5,     5,     5,     3,     3,     3,
      10,     8,     8,     7,     7,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       1,     4,     7,     2,     2,     4,     1,     1,     3,     1,
       0,     6,     6,     6,     3,     2,     0,     2,     1,     3,
       3,     1,     1,     4,     7,     2,     0,     5,     2,     0,
       0,    10,     3,     1,     0,     2,     3,     8,     3,     2,
       0,     2,     1,     3,     3,     1
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
#line 34 "exp.y" /* yacc.c:1646  */
    {end(target_file); printf("%d",count);}
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 37 "exp.y" /* yacc.c:1646  */
    {print1();generate(target_file);}
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 38 "exp.y" /* yacc.c:1646  */
    {generate(target_file);}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 41 "exp.y" /* yacc.c:1646  */
    {}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 42 "exp.y" /* yacc.c:1646  */
    {}
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 45 "exp.y" /* yacc.c:1646  */
    {Tptr = TInstall((yyvsp[-1])->varname,0,NULL);}
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 45 "exp.y" /* yacc.c:1646  */
    { Tptr->fields=Fhead;Tptr->size=size;size=0;Fhead=NULL;}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 48 "exp.y" /* yacc.c:1646  */
    {}
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 49 "exp.y" /* yacc.c:1646  */
    {}
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 52 "exp.y" /* yacc.c:1646  */
    {FInstall((yyvsp[-1])->varname,size,type);size++;}
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 54 "exp.y" /* yacc.c:1646  */
    {type=typeint;}
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 55 "exp.y" /* yacc.c:1646  */
    {type=typestr;}
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 56 "exp.y" /* yacc.c:1646  */
    {
	             					type=TLookup((yyvsp[0])->varname);
	             					if(type==NULL) 
	             					{
	             						Cptr=CLookup((yyvsp[0])->varname); 
	             						if(Cptr==NULL)
	             						{printf("Invalid Type %s at line %d\n",(yyvsp[0])->varname,lcnt);exit(1);}
             						}
             					}
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 67 "exp.y" /* yacc.c:1646  */
    {Cptr=NULL;print2();}
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 68 "exp.y" /* yacc.c:1646  */
    {Cptr=NULL;}
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 71 "exp.y" /* yacc.c:1646  */
    {}
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 72 "exp.y" /* yacc.c:1646  */
    {}
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 75 "exp.y" /* yacc.c:1646  */
    {decl=0;}
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 75 "exp.y" /* yacc.c:1646  */
    {printf("Class OK\n");decl=1;}
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 78 "exp.y" /* yacc.c:1646  */
    {Cptr = CInstall((yyvsp[0])->varname,NULL);printf("Class installed\n");}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 79 "exp.y" /* yacc.c:1646  */
    {Cptr = CInstall((yyvsp[-2])->varname,(yyvsp[0])->varname);}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 82 "exp.y" /* yacc.c:1646  */
    {}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 86 "exp.y" /* yacc.c:1646  */
    {Class_Finstall(Cptr,(yyvsp[-2])->varname,(yyvsp[-1])->varname);}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 87 "exp.y" /* yacc.c:1646  */
    {Class_Finstall(Cptr,"int",(yyvsp[-1])->varname);}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 88 "exp.y" /* yacc.c:1646  */
    {Class_Finstall(Cptr,"str",(yyvsp[-1])->varname);}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 91 "exp.y" /* yacc.c:1646  */
    {}
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 92 "exp.y" /* yacc.c:1646  */
    {}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 95 "exp.y" /* yacc.c:1646  */
    {Class_Minstall(Cptr,(yyvsp[-4])->varname,TLookup((yyvsp[-5])->varname),Phead);Phead=NULL;}
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 96 "exp.y" /* yacc.c:1646  */
    {Class_Minstall(Cptr,(yyvsp[-4])->varname,typeint,Phead);Phead=NULL;}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 97 "exp.y" /* yacc.c:1646  */
    {Class_Minstall(Cptr,(yyvsp[-4])->varname,typestr,Phead);Phead=NULL;}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 100 "exp.y" /* yacc.c:1646  */
    {}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 101 "exp.y" /* yacc.c:1646  */
    {}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 105 "exp.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-2]);}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 106 "exp.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 110 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_NULL,typevoid,NULL,(yyvsp[-1]),(yyvsp[0]),NULL);}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 111 "exp.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 114 "exp.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 115 "exp.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 116 "exp.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 117 "exp.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 118 "exp.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 119 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_BRK,typevoid,NULL,NULL,NULL,NULL);}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 120 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_CNTU,typevoid,NULL,NULL,NULL,NULL);}
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 121 "exp.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 122 "exp.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 125 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_RET,typevoid,NULL,(yyvsp[-1]),NULL,NULL);}
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 128 "exp.y" /* yacc.c:1646  */
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
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 144 "exp.y" /* yacc.c:1646  */
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
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 158 "exp.y" /* yacc.c:1646  */
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
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 175 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_UREAD,typevoid,NULL,(yyvsp[-1]),NULL,NULL);}
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 178 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_WRITE,typevoid,NULL,(yyvsp[-2]),NULL,NULL);}
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 181 "exp.y" /* yacc.c:1646  */
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
#line 2037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 216 "exp.y" /* yacc.c:1646  */
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
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 228 "exp.y" /* yacc.c:1646  */
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
#line 2073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 242 "exp.y" /* yacc.c:1646  */
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
#line 2108 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 272 "exp.y" /* yacc.c:1646  */
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
#line 2134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 293 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_ALLOCFIELD,typevoid,NULL,(yyvsp[-5]),NULL,NULL);}
#line 2140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 294 "exp.y" /* yacc.c:1646  */
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
#line 2166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 315 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_ASGN,typevoid,NULL,(yyvsp[-3]),(yyvsp[-1]),NULL);}
#line 2172 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 316 "exp.y" /* yacc.c:1646  */
    {
												tempst=GLookup((yyvsp[-6])->varname);
												if(tempst==NULL)
													{yyerror("undefined Variable");exit(1);}
												(yyvsp[-6])->Gentry=tempst;
												(yyvsp[-6])->cptr=tempst->cptr;
												(yyval)=createtree(0,nodetype_NEW,typevoid,NULL,(yyvsp[-6]),(yyvsp[-2]),NULL);
											}
#line 2185 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 324 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_NEW,typevoid,NULL,(yyvsp[-6]),(yyvsp[-2]),NULL);}
#line 2191 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 325 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_DELETE,typevoid,NULL,(yyvsp[-2]),NULL,NULL);}
#line 2197 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 328 "exp.y" /* yacc.c:1646  */
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
#line 2223 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 349 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_FREE,typevoid,NULL,(yyvsp[-2]),NULL,NULL);}
#line 2229 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 352 "exp.y" /* yacc.c:1646  */
    {	//right most of Field can't be a class variable it must be a type variable
								if((yyvsp[-2])->type==NULL)
									{yyerror("Invalid Reference");exit(1);}
								Ftemp=FLookup((yyvsp[-2])->type,(yyvsp[0])->varname);
								if(Ftemp==NULL)
									{yyerror("Invalid Member");exit(1);}
								(yyvsp[0])->type=Ftemp->type;
								(yyval)=createtree(0,nodetype_FIELD,(yyvsp[0])->type,NULL,(yyvsp[-2]),(yyvsp[0]),NULL);
							}
#line 2243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 361 "exp.y" /* yacc.c:1646  */
    {	//will not occur for class variables ID1 can't be class variable
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
											{yyerror("Invalid Member");exit(1);}
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
										{yyerror("Invalid Member");exit(1);}
									(yyvsp[0])->type=Ftemp->type;
									//printf("A3\n");
								}
	  							(yyval)=createtree(0,nodetype_FIELD,(yyvsp[0])->type,NULL,(yyvsp[-2]),(yyvsp[0]),NULL);
	  						}
#line 2284 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 397 "exp.y" /* yacc.c:1646  */
    {	//ID can be class or type variable
	  							//printf("%s %s S1\n",$1->varname,$3->varname);
	  							Ltemp=LLookup("self");
	  							if(Ltemp==NULL)
	  								{yyerror("Invalid Refernce");exit(1);}
	  							(yyvsp[-2])->Lentry=Ltemp;
	  							(yyvsp[-2])->cptr=Cptr;
	  							Ftemp=CFLookup(Cptr,(yyvsp[0])->varname);
	  							if(Ftemp==NULL)
									{yyerror("Invalid Member Field");exit(1);}
								(yyvsp[0])->cptr=Ftemp->cptr;
								(yyvsp[0])->type=Ftemp->type;
								(yyval)=createtree(0,nodetype_FIELD,(yyvsp[0])->type,NULL,(yyvsp[-2]),(yyvsp[0]),NULL);
								(yyval)->cptr=(yyvsp[0])->cptr;
	  						}
#line 2304 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 414 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_IF,typevoid,NULL,(yyvsp[-7]),(yyvsp[-4]),(yyvsp[-2]));}
#line 2310 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 415 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_IF,typevoid,NULL,(yyvsp[-5]),(yyvsp[-2]),NULL);}
#line 2316 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 418 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_WHILE,typevoid,NULL,(yyvsp[-5]),(yyvsp[-2]),NULL);}
#line 2322 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 419 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_DOWHILE,typevoid,NULL,(yyvsp[-2]),(yyvsp[-5]),NULL);}
#line 2328 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 420 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_REPEAT,typevoid,NULL,(yyvsp[-2]),(yyvsp[-5]),NULL);}
#line 2334 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 424 "exp.y" /* yacc.c:1646  */
    {(yyval) =createtree(0,nodetype_PLUS,typeint,NULL,(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 2340 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 425 "exp.y" /* yacc.c:1646  */
    {(yyval) =createtree(0,nodetype_MINUS,typeint,NULL,(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 2346 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 426 "exp.y" /* yacc.c:1646  */
    {(yyval) =createtree(0,nodetype_MUL,typeint,NULL,(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 2352 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 427 "exp.y" /* yacc.c:1646  */
    {(yyval) =createtree(0,nodetype_DIV,typeint,NULL,(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 2358 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 428 "exp.y" /* yacc.c:1646  */
    {(yyval) =createtree(0,nodetype_MOD,typeint,NULL,(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 2364 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 429 "exp.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]);}
#line 2370 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 430 "exp.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2376 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 431 "exp.y" /* yacc.c:1646  */
    {(yyval)	= (yyvsp[0]);}
#line 2382 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 432 "exp.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 2388 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 433 "exp.y" /* yacc.c:1646  */
    {(yyval) =createtree(0,nodetype_LT,TLookup("bool"),NULL,(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 2394 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 434 "exp.y" /* yacc.c:1646  */
    {(yyval) =createtree(0,nodetype_LE,TLookup("bool"),NULL,(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 2400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 435 "exp.y" /* yacc.c:1646  */
    {(yyval) =createtree(0,nodetype_GT,TLookup("bool"),NULL,(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 2406 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 436 "exp.y" /* yacc.c:1646  */
    {(yyval) =createtree(0,nodetype_GE,TLookup("bool"),NULL,(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 2412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 437 "exp.y" /* yacc.c:1646  */
    {(yyval) =createtree(0,nodetype_EQ,TLookup("bool"),NULL,(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 2418 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 438 "exp.y" /* yacc.c:1646  */
    {(yyval) =createtree(0,nodetype_NE,TLookup("bool"),NULL,(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 2424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 439 "exp.y" /* yacc.c:1646  */
    {
								Ltemp=LLookup((yyvsp[0])->varname);
								if(Ltemp==NULL)
								{
									tempst=GLookup((yyvsp[0])->varname);
									if(tempst==NULL)
									{yyerror("undefined Variable 2");printf(" %s\n",(yyvsp[0])->varname );exit(1);}
									else {(yyvsp[0])->Gentry=tempst; (yyvsp[0])->type=tempst->type;}
								}
								else
								{
									(yyvsp[0])->Lentry=Ltemp;
									(yyvsp[0])->type=Ltemp->type;
								}
								(yyval) = (yyvsp[0]);
							}
#line 2445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 455 "exp.y" /* yacc.c:1646  */
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
#line 2462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 468 "exp.y" /* yacc.c:1646  */
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
#line 2479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 480 "exp.y" /* yacc.c:1646  */
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
#line 2510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 506 "exp.y" /* yacc.c:1646  */
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
#line 2545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 536 "exp.y" /* yacc.c:1646  */
    {
								tempst=GLookup((yyvsp[-3])->varname);
								if(tempst==NULL)
								{
									yyerror("Undefined function");
									exit(1);
								}
								(yyvsp[-3])->Gentry=tempst;
								(yyvsp[-3])->type=tempst->type;
								(yyval)=createtree(0,nodetype_funcall,(yyvsp[-3])->type,NULL,(yyvsp[-3]),(yyvsp[-1]),NULL);
							}
#line 2561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 547 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_FIELDexpr,(yyvsp[0])->type,NULL,(yyvsp[0]),NULL,NULL);}
#line 2567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 548 "exp.y" /* yacc.c:1646  */
    {
								printf("method call %s\n",(yyvsp[0])->right->varname);
								(yyval)=createtree(0,nodetype_funcall,(yyvsp[0])->type,NULL,(yyvsp[0])->right,(yyvsp[0])->end,(yyvsp[0])->left);
								//printf("ff7\n");
							}
#line 2577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 555 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_ARG,typevoid,NULL,(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 2583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 556 "exp.y" /* yacc.c:1646  */
    {(yyval)=createtree(0,nodetype_ARG,typevoid,NULL,NULL,(yyvsp[0]),NULL);}
#line 2589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 557 "exp.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 2595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 560 "exp.y" /* yacc.c:1646  */
    {	//Occurs only in class function
													Ltemp=LLookup("self");
						  							if(Ltemp==NULL)
						  								{yyerror("Invalid Refernce");exit(1);}
						  							(yyvsp[-5])->Lentry=Ltemp;
						  							(yyvsp[-5])->cptr=Cptr;
						  							Mtemp=CMLookup(Cptr,(yyvsp[-3])->varname);
						  							if(Mtemp==NULL)
														{yyerror("Invalid Method");exit(1);}
													(yyvsp[-3])->cptr=Cptr;
													(yyvsp[-3])->type=Mtemp->type;
													(yyval)=createtree(0,nodetype_FIELDFUNC,(yyvsp[-3])->type,NULL,(yyvsp[-5]),(yyvsp[-3]),(yyvsp[-1]));
													(yyval)->cptr=(yyvsp[-3])->cptr;
												}
#line 2614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 574 "exp.y" /* yacc.c:1646  */
    {	//This will not occur inside a class.
                									//ID1 is a class
                									//printf("met1 %s\n",$3->varname );
                									Ltemp=LLookup((yyvsp[-5])->varname);
													if(Ltemp==NULL)
													{
														tempst=GLookup((yyvsp[-5])->varname);
														if(tempst==NULL)
														{yyerror("undefined Variable");printf("%s\n",(yyvsp[-5])->varname );exit(1);}
														else 
														{	
															(yyvsp[-5])->Gentry=tempst;
															Ctemp=tempst->cptr;
															(yyvsp[-5])->cptr=Ctemp;
															Mtemp=CMLookup(Ctemp,(yyvsp[-3])->varname);
															if(Mtemp==NULL)
																{yyerror("Invalid Member Function");exit(1);}
															(yyvsp[-3])->type=Mtemp->type;
														}
													}
													else
													{
														(yyvsp[-5])->Lentry=Ltemp;
														//Ctemp=Ltemp->cptr;
														Mtemp=CMLookup(Ctemp,(yyvsp[-3])->varname);
														if(Mtemp==NULL)
															{yyerror("Invalid Member Function");exit(1);}
														(yyvsp[-3])->type=Mtemp->type;
													}
						  							(yyval)=createtree(0,nodetype_FIELDFUNC,(yyvsp[-3])->type,NULL,(yyvsp[-5]),(yyvsp[-3]),(yyvsp[-1]));
                								}
#line 2650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 605 "exp.y" /* yacc.c:1646  */
    {
                									if((yyvsp[-5])->cptr==NULL)
                										{yyerror("Invalid Refernce");exit(1);}
                									Mtemp=CMLookup((yyvsp[-5])->cptr,(yyvsp[-3])->varname);
                									if(Mtemp==NULL)
                										{yyerror("Invalid Member Function");exit(1);}
                									(yyvsp[-3])->type=Mtemp->type;
                									(yyval)=createtree(0,nodetype_FIELDFUNC,(yyvsp[-3])->type,NULL,(yyvsp[-5]),(yyvsp[-3]),(yyvsp[-1]));
                								}
#line 2664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 616 "exp.y" /* yacc.c:1646  */
    {printsymtab();decl=0;printf("GDeclarations ok\n");}
#line 2670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 617 "exp.y" /* yacc.c:1646  */
    {decl=0;}
#line 2676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 618 "exp.y" /* yacc.c:1646  */
    {decl=0;}
#line 2682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 621 "exp.y" /* yacc.c:1646  */
    {}
#line 2688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 622 "exp.y" /* yacc.c:1646  */
    {}
#line 2694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 625 "exp.y" /* yacc.c:1646  */
    {}
#line 2700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 628 "exp.y" /* yacc.c:1646  */
    {}
#line 2706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 629 "exp.y" /* yacc.c:1646  */
    {}
#line 2712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 632 "exp.y" /* yacc.c:1646  */
    {
									GInstall((yyvsp[0])->varname,type,Cptr,1,1,NULL);
								}
#line 2720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 635 "exp.y" /* yacc.c:1646  */
    {
									if(type==typeint)
										GInstall((yyvsp[-3])->varname,TLookup("arrint"),NULL,(yyvsp[-1])->val,1,NULL);
									else if(type==typestr)
										GInstall((yyvsp[-3])->varname,TLookup("arrstr"),NULL,(yyvsp[-1])->val,1,NULL);
								}
#line 2731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 641 "exp.y" /* yacc.c:1646  */
    {
											if(type==typeint)
												GInstall((yyvsp[-6])->varname,TLookup("arrint"),NULL,(yyvsp[-4])->val,(yyvsp[-1])->val,NULL);
											else if(type==typestr)
												GInstall((yyvsp[-6])->varname,TLookup("arrstr"),NULL,(yyvsp[-4])->val,(yyvsp[-1])->val,NULL);
										}
#line 2742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 647 "exp.y" /* yacc.c:1646  */
    {
									if(type==typeint)
										GInstall((yyvsp[0])->varname,TLookup("intptr"),NULL,1,1,NULL);
									else if(type==typestr)
										GInstall((yyvsp[0])->varname,TLookup("strptr"),NULL,1,1,NULL);
								}
#line 2753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 653 "exp.y" /* yacc.c:1646  */
    {functype=type;}
#line 2759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 653 "exp.y" /* yacc.c:1646  */
    {
									//printf("function to enter Gtable %d\n",type);
									func=1;
									GInstall((yyvsp[-4])->varname,functype,NULL,0,1,Phead);printf("installed fun\n");
									func=0;
									Phead=NULL;
								}
#line 2771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 667 "exp.y" /* yacc.c:1646  */
    {}
#line 2777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 668 "exp.y" /* yacc.c:1646  */
    {}
#line 2783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 671 "exp.y" /* yacc.c:1646  */
    {functype=type;}
#line 2789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 671 "exp.y" /* yacc.c:1646  */
    {
																//printf("%d %s\n",$9->nodetype,$9->varname);
																//printf("f0\n");
																validateparams(functype,Cptr,(yyvsp[-8])->varname,Phead);
																(yyvsp[-8])->Lentry=Lhead;
																//printf("f1\n");
																if(Cptr==NULL)
																{
																	//printf("f2\n");
																	tempst=GLookup((yyvsp[-8])->varname);
																	(yyvsp[-8])->Gentry=tempst;
																	codegen_func((yyvsp[-8])->Gentry->flabel,(yyvsp[-1]),target_file);
																}
																else
																{
																	//printf("f3\n");
																	Mtemp=CMLookup(Cptr,(yyvsp[-8])->varname);
																	//printf("f4\n");
																	codegen_func(Mtemp->flabel,(yyvsp[-1]),target_file);
																}
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

																if(Cptr==NULL)
																	printf("FDefinition %d ok\n",tempst->flabel);
																else
																	printf("FDefinition %d ok\n",Mtemp->flabel);
															 }
#line 2834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 713 "exp.y" /* yacc.c:1646  */
    {arg=0;//printf("parameter installed ok\n");
										}
#line 2841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 715 "exp.y" /* yacc.c:1646  */
    {arg=0;}
#line 2847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 719 "exp.y" /* yacc.c:1646  */
    {
									PInstall((yyvsp[0])->varname,type,passtype_val);
									if(decl==0)
									{arg=1;LInstall((yyvsp[0])->varname,type);arg=0;}
								}
#line 2857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 724 "exp.y" /* yacc.c:1646  */
    {
									if(type==typeint)
										type=TLookup("intptr");
									else if(type==typestr)	
										type=TLookup("strptr");
									PInstall((yyvsp[0])->varname,type,passtype_ref);
									if(decl==0)
									{arg=1;	LInstall((yyvsp[0])->varname,type);arg=0;}
								}
#line 2871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 736 "exp.y" /* yacc.c:1646  */
    {	
															GInstall("main",typeint,NULL,0,1,NULL);
															//printf("m1\n");
															(yyval)=createtree(0,nodetype_MAIN,typeint,NULL,(yyvsp[-1]),NULL,NULL);
															//printf("m2\n");
															codegen((yyval),target_file);
															printf("Main function ok\n");
														}
#line 2884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 747 "exp.y" /* yacc.c:1646  */
    {if(Cptr!=NULL) {arg=1;LInstall("self",typevoid);arg=0;}printL();}
#line 2890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 748 "exp.y" /* yacc.c:1646  */
    {if(Cptr!=NULL) {arg=1;LInstall("self",typevoid);arg=0;}printL();}
#line 2896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 749 "exp.y" /* yacc.c:1646  */
    {if(Cptr!=NULL) {arg=1;LInstall("self",typevoid);arg=0;}printL();}
#line 2902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 752 "exp.y" /* yacc.c:1646  */
    {}
#line 2908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 753 "exp.y" /* yacc.c:1646  */
    {}
#line 2914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 756 "exp.y" /* yacc.c:1646  */
    {}
#line 2920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 759 "exp.y" /* yacc.c:1646  */
    {arg=0;LInstall((yyvsp[0])->varname,type);}
#line 2926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 760 "exp.y" /* yacc.c:1646  */
    {arg=0;LInstall((yyvsp[0])->varname,type);}
#line 2932 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2936 "y.tab.c" /* yacc.c:1646  */
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
#line 764 "exp.y" /* yacc.c:1906  */



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
	type=NULL;
	functype=NULL;
	Cptr=NULL;


	varadrs=4096;
	flabel=1;
	lvaradrs=1;
	padrs=-3;
	clscnt=0;

	TypeTableCreate();
	typeint=TLookup("int");
	typevoid=TLookup("void");
	typestr=TLookup("str");
	
	yyparse();
	return 0;
}
