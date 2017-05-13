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


/* Substitute the variable and function names.  */
#define yyparse         fct_pddlparse
#define yylex           fct_pddllex
#define yyerror         fct_pddlerror
#define yydebug         fct_pddldebug
#define yynerrs         fct_pddlnerrs

#define yylval          fct_pddllval
#define yychar          fct_pddlchar

/* Copy the first part of user declarations.  */
#line 53 "scan-fct_pddl.y" /* yacc.c:339  */

//#define YYDEBUG 1

#ifdef YYDEBUG
  extern int yydebug=1;
#endif

//#define YYPRINT(file, type, value)   yyprint (file, type, value)

#include <stdio.h>
#include <string.h> 
#include "ff.h"
#include "memory.h"
#include "parse.h"


#ifndef SCAN_ERR
#define SCAN_ERR
#define DEFINE_EXPECTED            0
#define PROBLEM_EXPECTED           1
#define PROBNAME_EXPECTED          2
#define LBRACKET_EXPECTED          3
#define RBRACKET_EXPECTED          4
#define DOMDEFS_EXPECTED           5
#define REQUIREM_EXPECTED          6
#define TYPEDLIST_EXPECTED         7
#define DOMEXT_EXPECTED            8
#define DOMEXTNAME_EXPECTED        9
#define TYPEDEF_EXPECTED          10
#define CONSTLIST_EXPECTED        11
#define PREDDEF_EXPECTED          12 
#define NAME_EXPECTED             13
#define VARIABLE_EXPECTED         14
#define ACTIONFUNCTOR_EXPECTED    15
#define ATOM_FORMULA_EXPECTED     16
#define EFFECT_DEF_EXPECTED       17
#define NEG_FORMULA_EXPECTED      18
#define NOT_SUPPORTED             19
#define SITUATION_EXPECTED        20
#define SITNAME_EXPECTED          21
#define BDOMAIN_EXPECTED          22
#define BADDOMAIN                 23
#define INIFACTS                  24
#define GOALDEF                   25
#define ADLGOAL                   26
#define CONSTRAINTLIST_EXPECTED	  27
#endif


static char * serrmsg[] = {
  "'define' expected",
  "'problem' expected",
  "problem name expected",
  "'(' expected",
  "')' expected",
  "additional domain definitions expected",
  "requirements (e.g. ':strips') expected",
  "typed list of <%s> expected",
  "domain extension expected",
  "domain to be extented expected",
  "type definition expected",
  "list of constants expected",
  "predicate definition expected",
  "<name> expected",
  "<variable> expected",
  "action functor expected",
  "atomic formula expected",
  "effect definition expected",
  "negated atomic formula expected",
  "requirement %s not supported by this IPP version",  
  "'situation' expected",
  "situation name expected",
  "':domain' expected",
  "this problem needs another domain file",
  "initial facts definition expected",
  "goal definition expected",
  "first order logic expression expected",
  "constraint list expected",
  NULL
};


//void fcterr( int errno, char *par );


static int sact_err;
static char *sact_err_par = NULL;
static Bool sis_negated = FALSE;
static PlOperator *scur_op = NULL;




/* 
 * call	bison -pfct -bscan-fct scan-fct.y
 */
void fcterr( int errno, char *par ) {

  sact_err = errno;

  if ( sact_err_par ) {
    free( sact_err_par );
  }
  if ( par ) {
    sact_err_par = new_Token( strlen(par)+1 );
    strcpy( sact_err_par, par);
  } else {
    sact_err_par = NULL;
  }

}



#line 189 "scan-fct_pddl.tab.c" /* yacc.c:339  */

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


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int fct_pddldebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    DEFINE_TOK = 258,
    PROBLEM_TOK = 259,
    SITUATION_TOK = 260,
    BSITUATION_TOK = 261,
    OBJECTS_TOK = 262,
    BDOMAIN_TOK = 263,
    INIT_TOK = 264,
    GOAL_TOK = 265,
    AND_TOK = 266,
    NOT_TOK = 267,
    NAME = 268,
    VARIABLE = 269,
    EQUAL_TOK = 270,
    FORALL_TOK = 271,
    IMPLY_TOK = 272,
    OR_TOK = 273,
    EXISTS_TOK = 274,
    EITHER_TOK = 275,
    OPEN_PAREN = 276,
    CLOSE_PAREN = 277,
    CONSTRAINTS_TOK = 278,
    PREFERENCE_TOK = 279,
    WITHIN_TOK = 280,
    SOMETIME_TOK = 281,
    ALWAYS_TOK = 282,
    AT_MOST_ONCE_TOK = 283,
    SOMETIME_AFTER_TOK = 284,
    SOMETIME_BEFORE_TOK = 285,
    ALWAYS_WITHIN_TOK = 286,
    HOLD_DURING_TOK = 287,
    HOLD_AFTER_TOK = 288,
    IS_VIOLATED_TOK = 289,
    REQUIREMENTS_TOK = 290,
    GREATER_OR_EQUAL_TOK = 291,
    LESS_THAN_OR_EQUAL_TOK = 292,
    INTVAL = 293,
    FLOATVAL = 294,
    PLUS_TOK = 295,
    MINUS_TOK = 296,
    MUL_TOK = 297,
    DIV_TOK = 298,
    GREATER_TOK = 299,
    LESS_THAN_TOK = 300,
    METRIC_TOK = 301,
    MINIMIZE_TOK = 302,
    MAXIMIZE_TOK = 303,
    LENGTH_TOK = 304,
    SERIAL_TOK = 305,
    PARALLEL_TOK = 306,
    TOTAL_TIME_TOK = 307,
    AT_END_TOK = 308,
    AT_TOK = 309,
    UMINUS = 310
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 172 "scan-fct_pddl.y" /* yacc.c:355  */


  char string[MAX_LENGTH];
  char* pstring;
  PlNode* pPlNode;
  FactList* pFactList;
  TokenList* pTokenList;
  TypedList* pTypedList;
  /* PDDL 3 */
  ConNode *pConNode;

    int ival;
    float fval;

#line 297 "scan-fct_pddl.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE fct_pddllval;

int fct_pddlparse (void);



/* Copy the second part of user declarations.  */

#line 314 "scan-fct_pddl.tab.c" /* yacc.c:358  */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   307

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  263

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   310

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
      55
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   313,   313,   316,   323,   322,   339,   349,   359,   363,
     366,   369,   372,   375,   378,   382,   389,   414,   413,   425,
     432,   442,   444,   455,   493,   492,   505,   510,   515,   521,
     538,   552,   569,   577,   581,   601,   606,   614,   627,   633,
     639,   649,   664,   680,   692,   707,   713,   723,   735,   748,
     760,   772,   780,   787,   809,   814,   819,   824,   829,   837,
     844,   851,   858,   865,   872,   880,   890,   902,   947,   951,
     964,   970,   979,   991,   995,  1006,  1012,  1022,  1029,  1041,
    1043,  1052,  1063,  1083,  1085,  1094,  1105,  1126,  1132,  1142,
    1152,  1162,  1174,  1176,  1188,  1197,  1202,  1209,  1219,  1231,
    1243,  1255,  1267,  1273,  1279,  1284,  1289,  1299,  1304,  1316,
    1321,  1333,  1336,  1338,  1340,  1344,  1352,  1358,  1362,  1357,
    1373,  1377,  1376
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DEFINE_TOK", "PROBLEM_TOK",
  "SITUATION_TOK", "BSITUATION_TOK", "OBJECTS_TOK", "BDOMAIN_TOK",
  "INIT_TOK", "GOAL_TOK", "AND_TOK", "NOT_TOK", "NAME", "VARIABLE",
  "EQUAL_TOK", "FORALL_TOK", "IMPLY_TOK", "OR_TOK", "EXISTS_TOK",
  "EITHER_TOK", "OPEN_PAREN", "CLOSE_PAREN", "CONSTRAINTS_TOK",
  "PREFERENCE_TOK", "WITHIN_TOK", "SOMETIME_TOK", "ALWAYS_TOK",
  "AT_MOST_ONCE_TOK", "SOMETIME_AFTER_TOK", "SOMETIME_BEFORE_TOK",
  "ALWAYS_WITHIN_TOK", "HOLD_DURING_TOK", "HOLD_AFTER_TOK",
  "IS_VIOLATED_TOK", "REQUIREMENTS_TOK", "GREATER_OR_EQUAL_TOK",
  "LESS_THAN_OR_EQUAL_TOK", "INTVAL", "FLOATVAL", "PLUS_TOK", "MINUS_TOK",
  "MUL_TOK", "DIV_TOK", "GREATER_TOK", "LESS_THAN_TOK", "METRIC_TOK",
  "MINIMIZE_TOK", "MAXIMIZE_TOK", "LENGTH_TOK", "SERIAL_TOK",
  "PARALLEL_TOK", "TOTAL_TIME_TOK", "AT_END_TOK", "AT_TOK", "UMINUS",
  "$accept", "file", "problem_definition", "$@1", "problem_name",
  "base_domain_name", "problem_defs", "objects_def", "init_def", "$@2",
  "init_el_plus", "init_el", "goal_def", "$@3", "pre_GD", "pref_GD",
  "pre_GD_star", "adl_goal_description", "adl_goal_description1", "f_comp",
  "f_exp", "f_head", "binary_comp", "num_exp", "number", "function_symbol",
  "adl_goal_description_star", "literal_term", "atomic_formula_term",
  "term_star", "term", "name_plus", "typed_list_name",
  "typed_list_variable", "predicate", "literal_name",
  "atomic_formula_name", "name_star", "metric_spec", "optimization",
  "ground_f_exp", "plus_ground_f_exp_plus", "mul_ground_f_exp_plus",
  "length_spec", "ser_par", "type", "either", "require_def", "$@4", "$@5",
  "require_key_star", "$@6", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310
};
# endif

#define YYPACT_NINF -126

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-126)))

#define YYTABLE_NINF -89

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -1,    27,    41,    -1,  -126,  -126,  -126,    90,    51,  -126,
      87,    18,    96,    28,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,   114,   119,  -126,  -126,  -126,    -2,   121,
      13,   113,   132,   135,   141,   151,  -126,  -126,    54,    34,
     146,    12,  -126,   114,   159,  -126,  -126,     6,   158,   135,
    -126,  -126,   185,   162,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,   147,  -126,  -126,  -126,  -126,  -126,  -126,   164,   153,
     154,  -126,  -126,   175,  -126,   159,   190,   192,  -126,    21,
     196,   201,  -126,  -126,   141,   197,    72,   198,   197,   197,
     199,  -126,    78,  -126,  -126,  -126,  -126,   202,    76,  -126,
     211,   212,    54,    54,    54,    54,   204,    76,  -126,   205,
     206,  -126,  -126,   114,    14,   221,   235,   112,   193,   232,
     201,   233,   141,   236,   234,   237,  -126,   238,   247,   197,
     197,   240,   247,   197,   241,    39,   202,  -126,  -126,  -126,
    -126,  -126,   244,    76,  -126,   245,   246,    54,    10,    54,
      54,  -126,   250,  -126,  -126,  -126,  -126,  -126,    79,   251,
    -126,  -126,  -126,  -126,  -126,   197,   213,  -126,  -126,     2,
     252,   253,  -126,  -126,   254,   255,  -126,   202,   202,   202,
     202,   258,  -126,  -126,   211,  -126,  -126,  -126,    74,  -126,
     259,  -126,   131,   260,  -126,   112,   112,   112,   112,  -126,
     261,   247,  -126,   247,   159,   248,  -126,   197,  -126,   202,
     112,   172,   136,   202,   112,   202,   112,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,   112,   136,   112,   112,  -126,
     262,  -126,   263,   220,   264,   265,  -126,   266,   267,   268,
    -126,   269,  -126,   270,   271,   272,   273,   274,   197,   247,
     248,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     2,     4,     1,     3,     0,     0,     8,
       0,     0,     0,     0,     5,    12,     9,    10,    11,    15,
      13,    14,     6,    79,     0,    17,    24,   117,     0,   112,
      79,     0,     0,     0,     0,     0,    95,    96,     0,     0,
       0,     0,    82,    79,     0,    16,     7,     0,     0,    19,
      21,    90,     0,     0,    27,    32,    43,    37,    71,   118,
      67,     0,    65,    66,   104,   103,   102,    53,     0,     0,
       0,   111,   115,     0,    81,    77,     0,     0,    87,    88,
       0,    92,    18,    20,    33,     0,    56,     0,     0,    68,
       0,    26,     0,    57,    58,    54,    55,     0,    73,    25,
     120,     0,     0,     0,     0,     0,     0,    73,    94,     0,
       0,   116,    78,    79,     0,     0,     0,     0,     0,     0,
      92,     0,    33,     0,     0,     0,    35,     0,    83,     0,
      68,     0,    83,     0,     0,     0,     0,    51,    45,    64,
      75,    76,     0,    73,   121,     0,     0,     0,     0,     0,
       0,   105,     0,   113,   114,    80,    88,    89,     0,     0,
      23,    93,    91,    34,    28,    68,     0,    39,    70,    83,
       0,     0,    69,    38,     0,     0,    31,     0,     0,     0,
       0,     0,    72,    74,   120,   119,   106,   107,     0,    97,
       0,   109,     0,     0,    52,     0,     0,     0,     0,    22,
       0,    83,    86,    83,     0,     0,    40,     0,    30,     0,
      45,     0,    45,     0,    45,     0,    45,    44,   122,    99,
     108,    98,   100,   110,   101,     0,     0,     0,     0,    36,
       0,    85,     0,     0,     0,     0,    32,     0,     0,     0,
      46,     0,    59,     0,     0,     0,     0,     0,     0,    83,
      33,    29,    42,    41,    48,    61,    47,    60,    49,    62,
      50,    63,    84
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -126,   294,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
     249,  -126,  -126,  -126,   -32,  -126,   177,   -82,   -34,  -126,
     -70,   -75,  -126,   -49,   -33,   -52,   -65,  -126,   215,   -90,
    -126,   -67,   -15,  -125,   -51,   222,   224,   183,  -126,  -126,
     -91,  -126,  -126,  -126,  -126,   137,   138,  -126,  -126,  -126,
     120,  -126
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,     9,    15,    11,    16,    17,    33,
      48,    49,    18,    34,   122,    54,   123,   130,   126,    56,
     136,    65,    97,   138,   139,    67,   200,    57,    58,   142,
     143,    76,    31,   170,    81,    50,    51,   121,    19,    38,
      68,   188,   192,    20,    40,    43,    44,    21,    35,   100,
     145,   184
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      55,    98,    53,   125,   117,    66,   129,   174,   112,   107,
     134,   147,   148,   149,   150,    42,   169,   152,    77,    78,
       1,    79,   137,    60,   131,    72,    30,    78,    74,   156,
       4,    61,   189,    73,    60,    23,    24,    25,    26,    13,
      14,     5,   116,    41,   202,    36,    37,   171,    62,    63,
      55,   175,    60,   183,    41,    10,   187,   190,   191,   193,
      80,   137,    64,    27,   107,   172,   181,    60,   159,    66,
      66,    66,    66,    98,    28,    61,   230,    29,   231,   177,
     178,   179,   180,   107,    69,    70,   -88,    60,    55,   140,
     141,   133,    62,    63,   -88,    61,   219,   220,   155,   124,
      12,   223,   137,   137,   137,   137,    64,   209,   211,   213,
     215,     8,    62,    63,    66,    66,    66,    66,    22,   195,
     196,   197,   198,   235,   262,   237,    64,    30,   210,   212,
     214,   216,    32,   158,   137,    45,   137,   232,   137,   238,
     137,   241,    39,   244,    60,   246,   225,   226,   227,   228,
      62,    63,    61,   222,    46,    66,    47,   158,   242,    66,
      60,   239,    52,   243,    59,   245,   235,   247,    71,    62,
      63,   236,    75,   234,    62,    63,   239,   243,   245,   247,
      82,   101,    98,    64,    99,    60,   108,   102,   103,   104,
     105,   109,   110,   135,   240,   111,    84,    85,    78,   106,
      86,    87,    88,    89,    90,    77,    78,    91,   156,    92,
      62,    63,   113,   114,   120,    60,   236,   118,   124,   128,
     132,    93,    94,   135,   144,   146,   151,   153,   154,    95,
      96,   250,    85,    78,   201,    86,    87,    88,    89,    90,
      62,    63,    91,   157,    92,   165,    85,    78,    60,    86,
     166,    88,    89,    90,   160,   162,    93,    94,   164,   167,
     168,   169,   173,   176,    95,    96,   182,   185,   186,   233,
      93,    94,   194,   199,   205,   206,   207,   208,    95,    96,
     217,   221,   224,   229,   248,   249,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,     6,    83,   163,
     127,   115,   119,   161,   218,     0,   203,   204
};

static const yytype_int16 yycheck[] =
{
      34,    52,    34,    85,    79,    38,    88,   132,    75,    61,
      92,   102,   103,   104,   105,    30,    14,   107,    12,    13,
      21,    15,    97,    13,    89,    13,    13,    13,    43,    15,
       3,    21,    22,    21,    13,     7,     8,     9,    10,    21,
      22,     0,    21,    41,   169,    47,    48,   129,    38,    39,
      84,   133,    13,   143,    41,     4,   147,   148,   149,   150,
      54,   136,    52,    35,   116,   130,   136,    13,   117,   102,
     103,   104,   105,   124,    46,    21,   201,    49,   203,    40,
      41,    42,    43,   135,    50,    51,    14,    13,   122,    13,
      14,    13,    38,    39,    22,    21,    22,   188,   113,    21,
      13,   192,   177,   178,   179,   180,    52,   177,   178,   179,
     180,    21,    38,    39,   147,   148,   149,   150,    22,    40,
      41,    42,    43,   205,   249,   207,    52,    13,   177,   178,
     179,   180,    13,    21,   209,    22,   211,   204,   213,   209,
     215,   211,    21,   213,    13,   215,   195,   196,   197,   198,
      38,    39,    21,    22,    22,   188,    21,    21,    22,   192,
      13,   210,    21,   212,    13,   214,   248,   216,    22,    38,
      39,   205,    13,   205,    38,    39,   225,   226,   227,   228,
      22,    34,   233,    52,    22,    13,    22,    40,    41,    42,
      43,    38,    38,    21,    22,    20,    11,    12,    13,    52,
      15,    16,    17,    18,    19,    12,    13,    22,    15,    24,
      38,    39,    22,    21,    13,    13,   250,    21,    21,    21,
      21,    36,    37,    21,    13,    13,    22,    22,    22,    44,
      45,    11,    12,    13,    21,    15,    16,    17,    18,    19,
      38,    39,    22,    22,    24,    11,    12,    13,    13,    15,
      16,    17,    18,    19,    22,    22,    36,    37,    22,    22,
      22,    14,    22,    22,    44,    45,    22,    22,    22,    21,
      36,    37,    22,    22,    22,    22,    22,    22,    44,    45,
      22,    22,    22,    22,    22,    22,    22,    22,    22,    22,
      22,    22,    22,    22,    22,    22,    22,     3,    49,   122,
      85,    77,    80,   120,   184,    -1,   169,   169
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    21,    57,    58,     3,     0,    57,    59,    21,    60,
       4,    62,    13,    21,    22,    61,    63,    64,    68,    94,
      99,   103,    22,     7,     8,     9,    10,    35,    46,    49,
      13,    88,    13,    65,    69,   104,    47,    48,    95,    21,
     100,    41,    88,   101,   102,    22,    22,    21,    66,    67,
      91,    92,    21,    70,    71,    74,    75,    83,    84,    13,
      13,    21,    38,    39,    52,    77,    80,    81,    96,    50,
      51,    22,    13,    21,    88,    13,    87,    12,    13,    15,
      54,    90,    22,    66,    11,    12,    15,    16,    17,    18,
      19,    22,    24,    36,    37,    44,    45,    78,    90,    22,
     105,    34,    40,    41,    42,    43,    52,    81,    22,    38,
      38,    20,    87,    22,    21,    92,    21,    77,    21,    91,
      13,    93,    70,    72,    21,    73,    74,    84,    21,    73,
      73,    82,    21,    13,    73,    21,    76,    77,    79,    80,
      13,    14,    85,    86,    13,   106,    13,    96,    96,    96,
      96,    22,    85,    22,    22,    88,    15,    22,    21,    79,
      22,    93,    22,    72,    22,    11,    16,    22,    22,    14,
      89,    73,    82,    22,    89,    73,    22,    40,    41,    42,
      43,    76,    22,    85,   107,    22,    22,    96,    97,    22,
      96,    96,    98,    96,    22,    40,    41,    42,    43,    22,
      82,    21,    89,   101,   102,    22,    22,    22,    22,    76,
      79,    76,    79,    76,    79,    76,    79,    22,   106,    22,
      96,    22,    22,    96,    22,    79,    79,    79,    79,    22,
      89,    89,    87,    21,    70,    73,    74,    73,    76,    79,
      22,    76,    22,    79,    76,    79,    76,    79,    22,    22,
      11,    22,    22,    22,    22,    22,    22,    22,    22,    22,
      22,    22,    89
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    57,    59,    58,    60,    61,    62,    62,
      62,    62,    62,    62,    62,    62,    63,    65,    64,    66,
      66,    67,    67,    67,    69,    68,    70,    70,    70,    70,
      71,    71,    71,    72,    72,    73,    73,    74,    74,    74,
      74,    74,    74,    74,    75,    76,    76,    76,    76,    76,
      76,    76,    77,    77,    78,    78,    78,    78,    78,    79,
      79,    79,    79,    79,    79,    80,    80,    81,    82,    82,
      83,    83,    84,    85,    85,    86,    86,    87,    87,    88,
      88,    88,    88,    89,    89,    89,    89,    90,    90,    91,
      91,    92,    93,    93,    94,    95,    95,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    97,    97,    98,
      98,    99,   100,   100,   100,   101,   102,   104,   105,   103,
     106,   107,   106
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     0,     6,     4,     4,     0,     2,
       2,     2,     2,     2,     2,     2,     4,     0,     5,     1,
       2,     1,     5,     4,     0,     5,     2,     1,     4,     7,
       5,     4,     1,     0,     2,     1,     4,     1,     4,     4,
       5,     7,     7,     1,     5,     1,     4,     5,     5,     5,
       5,     1,     4,     1,     1,     1,     1,     1,     1,     4,
       5,     5,     5,     5,     1,     1,     1,     1,     0,     2,
       4,     1,     4,     0,     2,     1,     1,     1,     2,     0,
       5,     3,     2,     0,     5,     3,     2,     1,     1,     4,
       1,     4,     0,     2,     5,     1,     1,     4,     5,     5,
       5,     5,     1,     1,     1,     3,     4,     1,     2,     1,
       2,     4,     0,     4,     4,     2,     3,     0,     0,     7,
       0,     0,     3
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
        case 4:
#line 323 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 
  fcterr( PROBNAME_EXPECTED, NULL ); 
}
#line 1599 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 327 "scan-fct_pddl.y" /* yacc.c:1646  */
    {  
  gproblem_name = (yyvsp[-2].pstring);
  if ( gcmd_line.display_info >= 1 ) {
    printf(" problem '%s' defined", gproblem_name);
	fflush(stdout);
  }
}
#line 1611 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 340 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 
  (yyval.pstring) = new_Token( strlen((yyvsp[-1].string))+1 );
  strcpy((yyval.pstring), (yyvsp[-1].string));
}
#line 1620 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 350 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 
  if ( SAME != strcmp((yyvsp[-1].string), gdomain_name) ) {
    fcterr( BADDOMAIN, NULL );
    yyerror();
  }
}
#line 1631 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 390 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 
  gparse_objects = (yyvsp[-1].pTypedList);
}
#line 1639 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 414 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  fcterr( INIFACTS, NULL ); 
}
#line 1647 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 418 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  gorig_initial_facts = new_PlNode(AND);
  gorig_initial_facts->sons = (yyvsp[-1].pPlNode); /*4 perche' una mid rule action conta 1*/
}
#line 1656 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 427 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode)=(yyvsp[0].pPlNode);
}
#line 1664 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 434 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode)=(yyvsp[-1].pPlNode);
  (yyval.pPlNode)->next = (yyvsp[0].pPlNode);
}
#line 1673 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 445 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  PlNode* pln;
  (yyval.pPlNode)=new_PlNode(EQUAL_CONN);
  pln = new_PlNode(FN_HEAD);
  (yyval.pPlNode)->sons = pln;
  (yyval.pPlNode)->sons->atom = (yyvsp[-2].pTokenList);
  (yyval.pPlNode)->sons->next = (yyvsp[-1].pPlNode);
}
#line 1686 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 456 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
	int n;
	char name[32];
	TimedInitial *til;
	if (gnum_tils%128 == 0)
        {
                n = (gnum_tils + 128)/128*128;
                gtils = (TimedInitial *) realloc(gtils, sizeof(TimedInitial)*n);
        }
	til = &gtils[gnum_tils++];
	sscanf((yyvsp[-2].string), "%s %f", name, &(til->time));
	if ((yyvsp[-1].pPlNode)->connective == NOT)
	{
		til->negated = TRUE;
		til->literal = (yyvsp[-1].pPlNode)->sons;
	}
	else
	{
		til->negated = FALSE;
		til->literal = (yyvsp[-1].pPlNode);
	}
        sprintf(name, "timed-initial-literals-%d", gnum_tils);
        scur_op = new_PlOperator(name); 
	scur_op->preconds = new_PlNode(TRU);
	scur_op->effects = (yyvsp[-1].pPlNode);

        scur_op->next = gloaded_ops; 
        gloaded_ops = scur_op;
        scur_op = NULL;
	(yyval.pPlNode) = new_PlNode(TRU);
}
#line 1722 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 493 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 
  fcterr( GOALDEF, NULL ); 
}
#line 1730 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 498 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  (yyvsp[-1].pPlNode)->next = gorig_goal_facts;
  gorig_goal_facts = (yyvsp[-1].pPlNode);
}
#line 1739 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 506 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
        (yyval.pPlNode) = NULL;
}
#line 1747 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 511 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
        (yyval.pPlNode) = (yyvsp[0].pPlNode);
}
#line 1755 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 516 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
        (yyval.pPlNode) = new_PlNode(AND);
        (yyval.pPlNode)->sons = (yyvsp[-1].pPlNode);
}
#line 1764 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 524 "scan-fct_pddl.y" /* yacc.c:1646  */
    {

  PlNode *pln;

  pln = new_PlNode(ALL);
  pln->parse_vars = (yyvsp[-3].pTypedList);

  (yyval.pPlNode) = pln;
  pln->sons = (yyvsp[-1].pPlNode);
 
}
#line 1780 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 539 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
        PrefNode *pref;
        ConNode *con;  
        pref = new_PrefNode((yyvsp[-2].string), "GLOBALPREFERENCE");
        con = new_ConNode(ATOM_c);
        con->sons = (yyvsp[-1].pPlNode);
        pref->body = con;
        pref->next = gloaded_preferences;
        gloaded_preferences = pref; 
        num_preference++;
        (yyval.pPlNode) = (yyvsp[-1].pPlNode);
}
#line 1797 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 553 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
        PrefNode *pref;
        ConNode *con;  
        char temp[128];
        sprintf(temp, "ANONYMOUS%d", num_preference);
        pref = new_PrefNode(temp, "GLOBALPREFERENCE");
        con = new_ConNode(ATOM_c);
        con->sons = (yyvsp[-1].pPlNode);
        pref->body = con;
        pref->weight = 1;
        pref->next = gloaded_preferences;
        gloaded_preferences = pref; 
        num_preference++;
        (yyval.pPlNode) = (yyvsp[-1].pPlNode);
}
#line 1817 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 570 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
        (yyval.pPlNode) = (yyvsp[0].pPlNode);
}
#line 1825 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 577 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
        (yyval.pPlNode) = NULL;
}
#line 1833 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 582 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-1].pPlNode))
        {
                (yyvsp[-1].pPlNode)->next = (yyvsp[0].pPlNode);
                (yyval.pPlNode) = (yyvsp[-1].pPlNode);
        }
        else
                (yyval.pPlNode) = (yyvsp[0].pPlNode);
}
#line 1847 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 602 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
	(yyval.pPlNode) = (yyvsp[0].pPlNode);
}
#line 1855 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 607 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 
  (yyval.pPlNode) = new_PlNode(AND);
  (yyval.pPlNode)->sons = (yyvsp[-1].pPlNode);
}
#line 1864 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 615 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 
  if ( sis_negated ) {
    (yyval.pPlNode) = new_PlNode(NOT);
    (yyval.pPlNode)->sons = new_PlNode(ATOM);
    (yyval.pPlNode)->sons->atom = (yyvsp[0].pTokenList);
    sis_negated = FALSE;
  } else {
    (yyval.pPlNode) = new_PlNode(ATOM);
    (yyval.pPlNode)->atom = (yyvsp[0].pTokenList);
  }
}
#line 1880 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 628 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 
  (yyval.pPlNode) = new_PlNode(OR);
  (yyval.pPlNode)->sons = (yyvsp[-1].pPlNode);
}
#line 1889 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 634 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 
  (yyval.pPlNode) = new_PlNode(NOT);
  (yyval.pPlNode)->sons = (yyvsp[-1].pPlNode);
}
#line 1898 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 640 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 
  PlNode *np = new_PlNode(NOT);
  np->sons = (yyvsp[-2].pPlNode);
  np->next = (yyvsp[-1].pPlNode);

  (yyval.pPlNode) = new_PlNode(OR);
  (yyval.pPlNode)->sons = np;
}
#line 1911 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 652 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 

  PlNode *pln;

  pln = new_PlNode(EX);
  pln->parse_vars = (yyvsp[-3].pTypedList);

  (yyval.pPlNode) = pln;
  pln->sons = (yyvsp[-1].pPlNode);

}
#line 1927 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 667 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 

  PlNode *pln;

  pln = new_PlNode(ALL);
  pln->parse_vars = (yyvsp[-3].pTypedList);

  (yyval.pPlNode) = pln;
  pln->sons = (yyvsp[-1].pPlNode);

}
#line 1943 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 693 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 
//AGGIUNTALAZZA
  //    printf("\n\nNumeric goal still not allowed in the goal definition\n\n");
    // exit(1);
//FINEAGGIUNTALAZZA
  (yyval.pPlNode) = new_PlNode(BIN_COMP);
  (yyval.pPlNode)->sons = (yyvsp[-3].pPlNode);
  (yyval.pPlNode)->sons->sons= (yyvsp[-2].pPlNode);
  (yyval.pPlNode)->sons->sons->next= (yyvsp[-1].pPlNode);
}
#line 1958 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 708 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
       (yyval.pPlNode)=new_PlNode(NUM_EXP);
       (yyval.pPlNode)->sons = (yyvsp[0].pPlNode);
}
#line 1967 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 714 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 
  PlNode *pln;

  (yyval.pPlNode)=new_PlNode(F_EXP);
  pln=new_PlNode(UMINUS_CONN); 
  (yyval.pPlNode)->sons = pln;
  (yyval.pPlNode)->sons->sons = (yyvsp[-1].pPlNode);
}
#line 1980 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 724 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 
  PlNode *pln;

  (yyval.pPlNode)=new_PlNode(F_EXP);
  pln=new_PlNode(MINUS_CONN); 
  (yyval.pPlNode)->sons = pln;
  (yyval.pPlNode)->sons->sons = (yyvsp[-2].pPlNode);
  (yyval.pPlNode)->sons->sons->next = (yyvsp[-1].pPlNode);

}
#line 1995 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 736 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 
  PlNode *pln;

  (yyval.pPlNode)=new_PlNode(F_EXP);
  pln=new_PlNode(PLUS_CONN); 
  (yyval.pPlNode)->sons = pln;
  (yyval.pPlNode)->sons->sons = (yyvsp[-2].pPlNode);
  (yyval.pPlNode)->sons->sons->next = (yyvsp[-1].pPlNode);


}
#line 2011 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 749 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 
  PlNode *pln;

  (yyval.pPlNode)=new_PlNode(F_EXP);
  pln=new_PlNode(MUL_CONN); 
  (yyval.pPlNode)->sons = pln;
  (yyval.pPlNode)->sons->sons = (yyvsp[-2].pPlNode);
  (yyval.pPlNode)->sons->sons->next = (yyvsp[-1].pPlNode);

}
#line 2026 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 761 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 
  PlNode *pln;

  (yyval.pPlNode)=new_PlNode(F_EXP);
  pln=new_PlNode(DIV_CONN); 
  (yyval.pPlNode)->sons = pln;
  (yyval.pPlNode)->sons->sons = (yyvsp[-2].pPlNode);
  (yyval.pPlNode)->sons->sons->next = (yyvsp[-1].pPlNode);

}
#line 2041 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 773 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode) = new_PlNode(FN_HEAD);
  (yyval.pPlNode)->atom = (yyvsp[0].pTokenList);
}
#line 2050 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 781 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 
  (yyval.pTokenList) = new_TokenList();
  (yyval.pTokenList)->item = (yyvsp[-2].pstring);
  (yyval.pTokenList)->next = (yyvsp[-1].pTokenList);
}
#line 2060 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 788 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 
  (yyval.pTokenList) = new_TokenList();
  (yyval.pTokenList)->item = (yyvsp[0].pstring);
}
#line 2069 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 810 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode)=new_PlNode(GREATER_THAN_CONN);
}
#line 2077 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 815 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode)=new_PlNode(LESS_THAN_CONN);
}
#line 2085 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 820 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode)=new_PlNode(EQUAL_CONN);
}
#line 2093 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 825 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode)=new_PlNode(GREATER_OR_EQUAL_CONN);
}
#line 2101 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 830 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode)=new_PlNode(LESS_THAN_OR_EQUAL_CONN);
}
#line 2109 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 838 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode)=new_PlNode(UMINUS_CONN);
  (yyval.pPlNode)->sons = (yyvsp[-1].pPlNode);
   
}
#line 2119 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 845 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode)=new_PlNode(MINUS_CONN);
  (yyval.pPlNode)->sons = (yyvsp[-2].pPlNode);
  (yyval.pPlNode)->sons->next = (yyvsp[-1].pPlNode);
}
#line 2129 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 852 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode)=new_PlNode(PLUS_CONN);
  (yyval.pPlNode)->sons = (yyvsp[-2].pPlNode);
  (yyval.pPlNode)->sons->next = (yyvsp[-1].pPlNode);
}
#line 2139 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 859 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode)=new_PlNode(MUL_CONN);
  (yyval.pPlNode)->sons = (yyvsp[-2].pPlNode);
  (yyval.pPlNode)->sons->next = (yyvsp[-1].pPlNode);
}
#line 2149 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 866 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode)=new_PlNode(DIV_CONN);
  (yyval.pPlNode)->sons = (yyvsp[-2].pPlNode);
  (yyval.pPlNode)->sons->next = (yyvsp[-1].pPlNode);
}
#line 2159 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 873 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
    (yyval.pPlNode)=new_PlNode(ATOM);
    (yyval.pPlNode)->atom = (yyvsp[0].pTokenList);
}
#line 2168 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 881 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  Token t;
  t = new_Token( strlen((yyvsp[0].string))+1 );
  strcpy (t, (yyvsp[0].string));
  (yyval.pTokenList) = new_TokenList();
  (yyval.pTokenList)->item = t;

}
#line 2181 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 891 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  Token t;
  t = new_Token( strlen((yyvsp[0].string))+1 );
  strcpy (t, (yyvsp[0].string));
  (yyval.pTokenList) = new_TokenList();
  (yyval.pTokenList)->item = t;

}
#line 2194 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 903 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 
  (yyval.pstring) = new_Token( strlen((yyvsp[0].string))+1 );
  strcpy( (yyval.pstring), (yyvsp[0].string) );
}
#line 2203 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 947 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode) = NULL;
}
#line 2211 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 952 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  (yyvsp[-1].pPlNode)->next = (yyvsp[0].pPlNode);
  (yyval.pPlNode) = (yyvsp[-1].pPlNode);
}
#line 2220 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 965 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 
  (yyval.pTokenList) = (yyvsp[-1].pTokenList);
  sis_negated = TRUE;
}
#line 2229 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 971 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pTokenList) = (yyvsp[0].pTokenList);
}
#line 2237 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 980 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 
  (yyval.pTokenList) = new_TokenList();
  (yyval.pTokenList)->item = (yyvsp[-2].pstring);
  (yyval.pTokenList)->next = (yyvsp[-1].pTokenList);
}
#line 2247 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 991 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pTokenList) = NULL;
}
#line 2255 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 996 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pTokenList) = new_TokenList();
  (yyval.pTokenList)->item = (yyvsp[-1].pstring);
  (yyval.pTokenList)->next = (yyvsp[0].pTokenList);
}
#line 2265 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1007 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 
  (yyval.pstring) = new_Token(strlen((yyvsp[0].string)) + 1);
  strcpy((yyval.pstring), (yyvsp[0].string));
}
#line 2274 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1013 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 
  (yyval.pstring) = new_Token(strlen((yyvsp[0].string)) + 1);
  strcpy((yyval.pstring), (yyvsp[0].string));
}
#line 2283 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1023 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pTokenList) = new_TokenList();
  (yyval.pTokenList)->item = new_Token(strlen((yyvsp[0].string)) + 1);
  strcpy((yyval.pTokenList)->item, (yyvsp[0].string));
}
#line 2293 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1030 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pTokenList) = new_TokenList();
  (yyval.pTokenList)->item = new_Token(strlen((yyvsp[-1].string)) + 1);
  strcpy((yyval.pTokenList)->item, (yyvsp[-1].string));
  (yyval.pTokenList)->next = (yyvsp[0].pTokenList);
}
#line 2304 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1041 "scan-fct_pddl.y" /* yacc.c:1646  */
    { (yyval.pTypedList) = NULL; }
#line 2310 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1044 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 
  (yyval.pTypedList) = new_TypedList();
  (yyval.pTypedList)->name = new_Token( strlen((yyvsp[-4].string))+1 );
  strcpy( (yyval.pTypedList)->name, (yyvsp[-4].string) );
  (yyval.pTypedList)->type = (yyvsp[-2].pTokenList);
  (yyval.pTypedList)->next = (yyvsp[0].pTypedList);
}
#line 2322 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1053 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pTypedList) = new_TypedList();
  (yyval.pTypedList)->name = new_Token( strlen((yyvsp[-2].string))+1 );
  strcpy( (yyval.pTypedList)->name, (yyvsp[-2].string) );
  (yyval.pTypedList)->type = new_TokenList();
  (yyval.pTypedList)->type->item = new_Token( strlen((yyvsp[-1].pstring))+1 );
  strcpy( (yyval.pTypedList)->type->item, (yyvsp[-1].pstring) );
  (yyval.pTypedList)->next = (yyvsp[0].pTypedList);
}
#line 2336 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1064 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pTypedList) = new_TypedList();
  (yyval.pTypedList)->name = new_Token( strlen((yyvsp[-1].string))+1 );
  strcpy( (yyval.pTypedList)->name, (yyvsp[-1].string) );
  if ( (yyvsp[0].pTypedList) ) {/* another element (already typed) is following */
    (yyval.pTypedList)->type = copy_TokenList( (yyvsp[0].pTypedList)->type );
  } else {/* no further element - it must be an untyped list */
    (yyval.pTypedList)->type = new_TokenList();
    (yyval.pTypedList)->type->item = new_Token( strlen(STANDARD_TYPE)+1 );
    strcpy( (yyval.pTypedList)->type->item, STANDARD_TYPE );
  }
  (yyval.pTypedList)->next = (yyvsp[0].pTypedList);
}
#line 2354 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1083 "scan-fct_pddl.y" /* yacc.c:1646  */
    { (yyval.pTypedList) = NULL; }
#line 2360 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1086 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 
  (yyval.pTypedList) = new_TypedList();
  (yyval.pTypedList)->name = new_Token( strlen((yyvsp[-4].string))+1 );
  strcpy( (yyval.pTypedList)->name, (yyvsp[-4].string) );
  (yyval.pTypedList)->type = (yyvsp[-2].pTokenList);
  (yyval.pTypedList)->next = (yyvsp[0].pTypedList);
}
#line 2372 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1095 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pTypedList) = new_TypedList();
  (yyval.pTypedList)->name = new_Token( strlen((yyvsp[-2].string))+1 );
  strcpy( (yyval.pTypedList)->name, (yyvsp[-2].string) );
  (yyval.pTypedList)->type = new_TokenList();
  (yyval.pTypedList)->type->item = new_Token( strlen((yyvsp[-1].pstring))+1 );
  strcpy( (yyval.pTypedList)->type->item, (yyvsp[-1].pstring) );
  (yyval.pTypedList)->next = (yyvsp[0].pTypedList);
}
#line 2386 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1106 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pTypedList) = new_TypedList();
  (yyval.pTypedList)->name = new_Token( strlen((yyvsp[-1].string))+1 );
  strcpy( (yyval.pTypedList)->name, (yyvsp[-1].string) );
  if ( (yyvsp[0].pTypedList) ) {/* another element (already typed) is following */
    (yyval.pTypedList)->type = copy_TokenList( (yyvsp[0].pTypedList)->type );
  } else {/* no further element - it must be an untyped list */
    (yyval.pTypedList)->type = new_TokenList();
    (yyval.pTypedList)->type->item = new_Token( strlen(STANDARD_TYPE)+1 );
    strcpy( (yyval.pTypedList)->type->item, STANDARD_TYPE );
  }
  (yyval.pTypedList)->next = (yyvsp[0].pTypedList);
}
#line 2404 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1127 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 
  (yyval.pstring) = new_Token(strlen((yyvsp[0].string)) + 1);
  strcpy((yyval.pstring), (yyvsp[0].string));
}
#line 2413 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1133 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 
  (yyval.pstring) = new_Token( strlen(EQ_STR)+1 );
  strcpy( (yyval.pstring), EQ_STR );
}
#line 2422 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1143 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 
  PlNode *tmp;

  tmp = new_PlNode(ATOM);
  tmp->atom = (yyvsp[-1].pTokenList);
  (yyval.pPlNode) = new_PlNode(NOT);
  (yyval.pPlNode)->sons = tmp;
}
#line 2435 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1153 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode) = new_PlNode(ATOM);
  (yyval.pPlNode)->atom = (yyvsp[0].pTokenList);
}
#line 2444 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1163 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 
  (yyval.pTokenList) = new_TokenList();
  (yyval.pTokenList)->item = (yyvsp[-2].pstring);
  (yyval.pTokenList)->next = (yyvsp[-1].pTokenList);
}
#line 2454 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1174 "scan-fct_pddl.y" /* yacc.c:1646  */
    { (yyval.pTokenList) = NULL; }
#line 2460 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1177 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pTokenList) = new_TokenList();
  (yyval.pTokenList)->item = new_Token(strlen((yyvsp[-1].string)) + 1);
  strcpy((yyval.pTokenList)->item, (yyvsp[-1].string));
  (yyval.pTokenList)->next = (yyvsp[0].pTokenList);
}
#line 2471 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1189 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  gmetric_exp = new_PlNode (METRIC_CONN);
  gmetric_exp->sons = (yyvsp[-2].pPlNode);
  gmetric_exp->sons->sons = (yyvsp[-1].pPlNode);
}
#line 2481 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1198 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode) = new_PlNode ( MINIMIZE_CONN);
}
#line 2489 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1203 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode) = new_PlNode ( MAXIMIZE_CONN);
}
#line 2497 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1210 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 
  PlNode *pln;

  (yyval.pPlNode)=new_PlNode(F_EXP);
  pln=new_PlNode(UMINUS_CONN); 
  (yyval.pPlNode)->sons = pln;
  (yyval.pPlNode)->sons->sons = (yyvsp[-1].pPlNode);
}
#line 2510 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1220 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 
  PlNode *pln;

  (yyval.pPlNode)=new_PlNode(F_EXP);
  pln=new_PlNode(MINUS_CONN); 
  (yyval.pPlNode)->sons = pln;
  (yyval.pPlNode)->sons->sons = (yyvsp[-2].pPlNode);
  (yyval.pPlNode)->sons->sons->next = (yyvsp[-1].pPlNode);

}
#line 2525 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1232 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 
  PlNode *pln;

  (yyval.pPlNode)=new_PlNode(F_EXP);
  pln=new_PlNode(PLUS_CONN); 
  (yyval.pPlNode)->sons = pln;
  (yyval.pPlNode)->sons->sons = (yyvsp[-2].pPlNode);
  (yyval.pPlNode)->sons->sons->next = (yyvsp[-1].pPlNode);

}
#line 2540 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1244 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 
  PlNode *pln;

  (yyval.pPlNode)=new_PlNode(F_EXP);
  pln=new_PlNode(MUL_CONN); 
  (yyval.pPlNode)->sons = pln;
  (yyval.pPlNode)->sons->sons = (yyvsp[-2].pPlNode);
  (yyval.pPlNode)->sons->sons->next = (yyvsp[-1].pPlNode);

}
#line 2555 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1256 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 
  PlNode *pln;

  (yyval.pPlNode)=new_PlNode(F_EXP);
  pln=new_PlNode(DIV_CONN); 
  (yyval.pPlNode)->sons = pln;
  (yyval.pPlNode)->sons->sons = (yyvsp[-2].pPlNode);
  (yyval.pPlNode)->sons->sons->next = (yyvsp[-1].pPlNode);

}
#line 2570 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1268 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
    (yyval.pPlNode)=new_PlNode(ATOM);
    (yyval.pPlNode)->atom = (yyvsp[0].pTokenList);
}
#line 2579 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1274 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode) = new_PlNode(FN_HEAD);
  (yyval.pPlNode)->atom = (yyvsp[0].pTokenList);
}
#line 2588 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1280 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode) = new_PlNode(TOTAL_TIME_CONN);
}
#line 2596 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1285 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode) = new_PlNode(TOTAL_TIME_CONN);
}
#line 2604 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1290 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode) = new_PlNode(IS_VIOLATED_CONN);
  (yyval.pPlNode)->atom = new_TokenList();
  (yyval.pPlNode)->atom->item = new_Token(strlen((yyvsp[-1].string)) + 1);
  strcpy((yyval.pPlNode)->atom->item, (yyvsp[-1].string));
}
#line 2615 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1300 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode) = (yyvsp[0].pPlNode);
}
#line 2623 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1305 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  PlNode *pln;

  (yyval.pPlNode)=new_PlNode(F_EXP);
  pln=new_PlNode(PLUS_CONN); 
  (yyval.pPlNode)->sons = pln;
  (yyval.pPlNode)->sons->sons = (yyvsp[-1].pPlNode);
  (yyval.pPlNode)->sons->sons->next = (yyvsp[0].pPlNode);
}
#line 2637 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1317 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode) = (yyvsp[0].pPlNode);
}
#line 2645 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1322 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  PlNode *pln;

  (yyval.pPlNode)=new_PlNode(F_EXP);
  pln=new_PlNode(MUL_CONN); 
  (yyval.pPlNode)->sons = pln;
  (yyval.pPlNode)->sons->sons = (yyvsp[-1].pPlNode);
  (yyval.pPlNode)->sons->sons->next = (yyvsp[0].pPlNode);
}
#line 2659 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1345 "scan-fct_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pstring) = new_Token(strlen((yyvsp[0].string)) + 1);
  strcpy((yyval.pstring), (yyvsp[0].string));
}
#line 2668 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1358 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 
  opserr( REQUIREM_EXPECTED, NULL ); 
}
#line 2676 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1362 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 
  if ( !supported( (yyvsp[0].string) ) ) {
    opserr( NOT_SUPPORTED, (yyvsp[0].string) );
    yyerror();
  }
}
#line 2687 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1377 "scan-fct_pddl.y" /* yacc.c:1646  */
    { 
  if ( !supported( (yyvsp[0].string) ) ) {
    opserr( NOT_SUPPORTED, (yyvsp[0].string) );
    yyerror();
  }
}
#line 2698 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
    break;


#line 2702 "scan-fct_pddl.tab.c" /* yacc.c:1646  */
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
#line 1388 "scan-fct_pddl.y" /* yacc.c:1906  */



#include "lex.fct_pddl.c"


/**********************************************************************
 * Functions
 **********************************************************************/



int yyerror( char *msg )

{
  fflush( stdout );
  fprintf(stderr,"\n%s: syntax error in line %d, '%s':\n", 
	  gact_filename, lineno, fct_pddltext );

  if ( sact_err_par ) {
    fprintf(stderr, "%s%s\n", serrmsg[sact_err], sact_err_par );
  } else {
    fprintf(stderr,"%s\n", serrmsg[sact_err] );
  }

  exit( 1 );

}



void load_fct_file( char *filename ) 

{

  FILE *fp;/* pointer to input files */
  char tmp[MAX_LENGTH] = "";

  /* open fact file 
   */
  if( ( fp = fopen( filename, "r" ) ) == NULL ) {
    sprintf(tmp, "\n Can't find fact file: %s\n\n", filename );
    perror(tmp);
    exit ( 1 );
  }

  gact_filename = filename;
  lineno = 1; 
  fct_pddlin = fp;

  yyparse();

  fclose( fp );/* and close file again */

}

     static void
     yyprint (thisfile, mytype, value)
         FILE *thisfile;
          int mytype;
          YYSTYPE value;
     {
         fprintf (thisfile, " %s", value.string);
	 /*
       if (type == VAR)
         fprintf (file, " %s", value.tptr->name);
       else if (type == NUM)
         fprintf (file, " %d", value.val);
	 */
     }
