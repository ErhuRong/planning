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
#define yyparse         ops_pddlparse
#define yylex           ops_pddllex
#define yyerror         ops_pddlerror
#define yydebug         ops_pddldebug
#define yynerrs         ops_pddlnerrs

#define yylval          ops_pddllval
#define yychar          ops_pddlchar

/* Copy the first part of user declarations.  */
#line 53 "scan-ops_pddl.y" /* yacc.c:339  */

//#define YYDEBUG 1
#ifdef YYDEBUG
  extern int yydebug=1;


//#define YYPRINT(file, type, value)   yyprint (file, type, value)
#endif
   
#include <stdio.h>
#include <string.h> 
#include "ff.h"
#include "memory.h"
#include "parse.h"
#include "lpg.h"

#ifndef SCAN_ERR
#define SCAN_ERR
#define DOMDEF_EXPECTED            0
#define DOMAIN_EXPECTED            1
#define DOMNAME_EXPECTED           2
#define LBRACKET_EXPECTED          3
#define RBRACKET_EXPECTED          4
#define DOMDEFS_EXPECTED           5
#define REQUIREM_EXPECTED          6
#define TYPEDLIST_EXPECTED         7
#define LITERAL_EXPECTED           8
#define PRECONDDEF_UNCORRECT       9
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
#define ACTION                    20
#define CONSTRAINTLIST_EXPECTED	  21
#endif


#define NAME_STR "name\0"
#define VARIABLE_STR "variable\0"
#define STANDARD_TYPE "OBJECT\0"
 

static char *serrmsg[] = {
  "domain definition expected",
  "'domain' expected",
  "domain name expected",
  "'(' expected",
  "')' expected",
  "additional domain definitions expected",
  "requirements (e.g. ':STRIPS') expected",
  "typed list of <%s> expected",
  "literal expected",
  "uncorrect precondition definition",
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
  "action definition is not correct",
  "constraint definition is not correct",
  NULL
};


//void opserr( int errno, char *par );


static int sact_err;
static char *sact_err_par = NULL;
static PlOperator *scur_op = NULL, *scur_op1 = NULL;
static Bool sis_negated = FALSE;
static Bool in_durative_action = FALSE;
static int preference_flag = 0;


/* 
 * call	bison -pops -bscan-ops scan-ops.y
 */

void opserr( int errno, char *par )

{

  sact_err = errno;

  if ( sact_err_par ) {
    free(sact_err_par);
  }
  if ( par ) {
    sact_err_par = new_Token(strlen(par)+1);
    strcpy(sact_err_par, par);
  } else {
    sact_err_par = NULL;
  }

}
  
int supported( char *str )

{
  
  int i;
  
/*sositituito per pddl2 (negative-precontions oltre a negation*/
  /*  char * sup[] = { ":STRIPS", ":NEGATION", ":EQUALITY",":TYPING", 
		   ":CONDITIONAL-EFFECTS", ":DISJUNCTIVE-PRECONDITIONS", 
		   ":EXISTENTIAL-PRECONDITIONS", ":UNIVERSAL-PRECONDITIONS", 
		   ":QUANTIFIED-PRECONDITIONS", ":ADL",
		   NULL };     */
	/* derived predicates */
	/* timed initial literals */
  char * sup[] = { ":STRIPS", ":TYPING", ":NEGATIVE-PRECONDITIONS",
		   ":DISJUNCTIVE-PRECONDITIONS", ":EQUALITY", 
		   ":EXISTENTIAL-PRECONDITIONS", ":UNIVERSAL-PRECONDITIONS", 
		   ":QUANTIFIED-PRECONDITIONS", ":CONDITIONAL-EFFECTS", 
		   ":FLUENTS", ":ADL", ":DURATIVE-ACTIONS", 
		   ":DERIVED-PREDICATES", ":TIMED-INITIAL-LITERALS", 
		   ":PREFERENCES", ":CONSTRAINTS", NULL };    

  for (i=0; NULL != sup[i]; i++) {
    if ( SAME == strcmp(sup[i], str) ) {
	switch(i)
	{
	case 2:
		GpG.is_negative = TRUE;
		break;
/*	case 3:
		GpG.is_disjunctive = TRUE;
		break;
	case 4:
		GpG.is_equality = TRUE;
		break;
	case 5:
		GpG.is_existential = TRUE;
		break;
	case 6:
		GpG.is_universal = TRUE;
		break;
	case 7:
		GpG.is_existential = GpG.is_universal = TRUE;
		break;
	case 8:
		GpG.is_conditional = TRUE;
		break;*/
	case 9:
		GpG.is_fluents = TRUE;
		break;
/*	case 10:
		GpG.is_negative = GpG.is_disjunctive = GpG.is_equality = 
		GpG.is_conditional = TRUE;
		break;*/
	case 11:
		GpG.is_durative = TRUE;
		break;
	case 12:
		GpG.is_deripred = TRUE;
		break;
	case 13:
		GpG.is_til = TRUE;
		break;
	case 14:
		GpG.is_preferences = TRUE;
		break;
	case 15:
		GpG.is_constraints = TRUE;
		break;
	}
      return TRUE;
    }
  }
  return TRUE;

}


 

#line 263 "scan-ops_pddl.tab.c" /* yacc.c:339  */

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
extern int ops_pddldebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    DEFINE_TOK = 258,
    DOMAIN_TOK = 259,
    REQUIREMENTS_TOK = 260,
    TYPES_TOK = 261,
    EITHER_TOK = 262,
    CONSTANTS_TOK = 263,
    PREDICATES_TOK = 264,
    FUNCTIONS_TOK = 265,
    DURATIVE_ACTION_TOK = 266,
    CONDITION_TOK = 267,
    DURATION_TOK = 268,
    DERIVED_TOK = 269,
    DURATION_VAR_TOK = 270,
    AT_START = 271,
    AT_END = 272,
    OVER_ALL = 273,
    INCREASE_TOK = 274,
    DECREASE_TOK = 275,
    TIME_TOK = 276,
    GREATER_OR_EQUAL_TOK = 277,
    LESS_THAN_OR_EQUAL_TOK = 278,
    INTVAL = 279,
    FLOATVAL = 280,
    ASSIGN_TOK = 281,
    SCALE_UP_TOK = 282,
    SCALE_DOWN_TOK = 283,
    PLUS_TOK = 284,
    MINUS_TOK = 285,
    MUL_TOK = 286,
    DIV_TOK = 287,
    EQUAL_TOK = 288,
    GREATER_TOK = 289,
    LESS_THAN_TOK = 290,
    ACTION_TOK = 291,
    VARS_TOK = 292,
    PRECONDITION_TOK = 293,
    PARAMETERS_TOK = 294,
    EFFECT_TOK = 295,
    AND_TOK = 296,
    NOT_TOK = 297,
    WHEN_TOK = 298,
    FORALL_TOK = 299,
    IMPLY_TOK = 300,
    OR_TOK = 301,
    EXISTS_TOK = 302,
    NAME = 303,
    VARIABLE = 304,
    OPEN_PAREN = 305,
    CLOSE_PAREN = 306,
    UMINUS = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 246 "scan-ops_pddl.y" /* yacc.c:355  */


  char string[MAX_LENGTH];
  char *pstring;
  PlNode *pPlNode;
  FactList *pFactList;
  TokenList *pTokenList;
  TypedList *pTypedList;
  /* PDDL 3 */
  ConNode *pConNode;
  TypedListList *pTypedListList;

    int ival;
    float fval;

#line 369 "scan-ops_pddl.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE ops_pddllval;

int ops_pddlparse (void);



/* Copy the second part of user declarations.  */

#line 386 "scan-ops_pddl.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   413

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  79
/* YYNRULES -- Number of rules.  */
#define YYNRULES  172
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  379

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

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
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   380,   380,   380,   391,   390,   407,   416,   420,   423,
     426,   429,   432,   436,   439,   442,   450,   449,   487,   489,
     518,   517,   528,   530,   545,   562,   571,   609,   613,   608,
     624,   628,   627,   641,   640,   654,   653,   669,   676,   668,
     706,   710,   723,   726,   747,   746,   753,   752,   760,   765,
     770,   776,   795,   799,   853,   865,   870,   878,   897,   903,
     909,   919,   934,   950,   961,   972,   978,   990,  1004,  1019,
    1033,  1047,  1056,  1067,  1074,  1084,  1089,  1094,  1099,  1104,
    1111,  1120,  1129,  1138,  1147,  1156,  1164,  1174,  1186,  1230,
    1235,  1240,  1245,  1250,  1261,  1265,  1277,  1290,  1296,  1311,
    1326,  1340,  1344,  1356,  1362,  1371,  1383,  1385,  1396,  1402,
    1412,  1419,  1430,  1436,  1447,  1449,  1462,  1473,  1493,  1495,
    1507,  1521,  1540,  1558,  1563,  1557,  1591,  1594,  1613,  1612,
    1622,  1621,  1628,  1627,  1635,  1640,  1645,  1651,  1669,  1673,
    1686,  1699,  1705,  1713,  1718,  1726,  1732,  1738,  1750,  1756,
    1763,  1776,  1791,  1803,  1808,  1816,  1822,  1828,  1834,  1856,
    1871,  1878,  1888,  1897,  1902,  1912,  1922,  1932,  1989,  2010,
    2055,  2066,  2074
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DEFINE_TOK", "DOMAIN_TOK",
  "REQUIREMENTS_TOK", "TYPES_TOK", "EITHER_TOK", "CONSTANTS_TOK",
  "PREDICATES_TOK", "FUNCTIONS_TOK", "DURATIVE_ACTION_TOK",
  "CONDITION_TOK", "DURATION_TOK", "DERIVED_TOK", "DURATION_VAR_TOK",
  "AT_START", "AT_END", "OVER_ALL", "INCREASE_TOK", "DECREASE_TOK",
  "TIME_TOK", "GREATER_OR_EQUAL_TOK", "LESS_THAN_OR_EQUAL_TOK", "INTVAL",
  "FLOATVAL", "ASSIGN_TOK", "SCALE_UP_TOK", "SCALE_DOWN_TOK", "PLUS_TOK",
  "MINUS_TOK", "MUL_TOK", "DIV_TOK", "EQUAL_TOK", "GREATER_TOK",
  "LESS_THAN_TOK", "ACTION_TOK", "VARS_TOK", "PRECONDITION_TOK",
  "PARAMETERS_TOK", "EFFECT_TOK", "AND_TOK", "NOT_TOK", "WHEN_TOK",
  "FORALL_TOK", "IMPLY_TOK", "OR_TOK", "EXISTS_TOK", "NAME", "VARIABLE",
  "OPEN_PAREN", "CLOSE_PAREN", "UMINUS", "$accept", "file", "$@1",
  "domain_definition", "$@2", "domain_name", "optional_domain_defs",
  "predicates_def", "$@3", "predicates_list", "functions_def", "$@4",
  "functions_list", "atomic_function_skeleton_plus", "require_def", "$@5",
  "$@6", "require_key_star", "$@7", "types_def", "$@8", "constants_def",
  "$@9", "action_def", "$@10", "$@11", "param_def", "action_def_body",
  "$@12", "$@13", "pre_GD", "pre_GD_star", "pref_GD",
  "adl_goal_description", "adl_goal_description1", "f_comp", "f_exp",
  "f_head", "binary_comp", "num_exp", "number", "function_symbol",
  "assign_op", "adl_goal_description_star", "adl_effect",
  "adl_effect_star", "literal_term", "atomic_formula_term", "term_star",
  "term", "name_plus", "predicate", "typed_list_name",
  "typed_list_variable", "derived_def", "durative_action_def", "$@14",
  "$@15", "durative_action_def_body", "$@16", "$@17", "$@18", "da_GD",
  "da_GD_star", "pref_timed_GD", "da_adl_goal_description",
  "timed_adl_goal_description_plus", "timed_adl_goal_description",
  "da_adl_effect", "timed_adl_effect_plus", "timed_adl_effect",
  "f_assign_da", "f_exp_da", "binary_op", "duration_constraint",
  "simple_duration_constraint", "d_op", "type", "either", YY_NULLPTR
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
     305,   306,   307
};
# endif

#define YYPACT_NINF -246

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-246)))

#define YYTABLE_NINF -114

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -246,    40,    -3,  -246,    63,  -246,    47,    96,  -246,    42,
    -246,    53,    33,  -246,   137,  -246,  -246,  -246,  -246,  -246,
    -246,  -246,  -246,  -246,  -246,  -246,  -246,  -246,    58,  -246,
      78,  -246,    83,    87,    87,    88,   102,  -246,   125,   108,
      -9,   109,   113,  -246,   -14,   111,   119,   124,   123,   130,
     131,   145,  -246,  -246,  -246,    73,   303,   146,  -246,  -246,
    -246,  -246,  -246,   152,   -20,  -246,    87,   158,  -246,  -246,
     130,  -246,    -4,   156,  -246,    58,   175,  -246,  -246,   166,
      73,  -246,  -246,     9,  -246,  -246,   109,   109,   181,   109,
     109,   191,   151,  -246,   175,  -246,   196,  -246,   241,  -246,
     158,   198,   203,  -246,   130,   158,    58,  -246,   213,    30,
    -246,  -246,   109,   215,   219,   220,   130,   109,   222,   130,
    -246,  -246,  -246,   194,   151,  -246,  -246,  -246,  -246,    76,
     152,  -246,  -246,  -246,    87,  -246,  -246,   223,  -246,   130,
     227,   236,   237,   238,   239,  -246,  -246,  -246,  -246,   240,
     242,  -246,   246,   151,   151,   151,   151,    73,   247,   249,
     250,   251,   253,  -246,  -246,   130,   262,    89,  -246,  -246,
    -246,  -246,   231,  -246,  -246,   130,   161,  -246,  -246,  -246,
     109,  -246,   109,   151,    99,   171,    27,   151,    99,   151,
      99,   264,  -246,   130,   234,  -246,  -246,  -246,   291,  -246,
    -246,  -246,  -246,  -246,   109,   109,   109,   227,   266,  -246,
      30,  -246,   274,    30,   269,   271,   271,  -246,  -246,  -246,
    -246,  -246,   272,   273,   277,    45,    30,   278,   279,   280,
     208,   289,  -246,  -246,   290,  -246,   292,   295,   301,   302,
     304,  -246,   305,   250,   307,  -246,    76,   251,    78,   109,
     308,    45,    76,   309,   310,   311,   227,   312,   313,   315,
     130,  -246,   151,  -246,    30,   291,   316,   317,   318,   319,
     136,   320,   272,   174,   272,   130,   217,    86,  -246,  -246,
    -246,  -246,    99,    99,    99,    99,  -246,  -246,  -246,  -246,
    -246,  -246,  -246,    76,   250,   321,   130,  -246,   251,   322,
     220,   251,   130,   151,  -246,  -246,  -246,  -246,  -246,  -246,
    -246,   211,  -246,   315,   323,   324,  -246,    45,  -246,  -246,
    -246,  -246,  -246,  -246,   315,   325,   326,  -246,   214,  -246,
     327,    99,    27,    99,    99,  -246,  -246,  -246,   328,  -246,
    -246,   329,   330,   331,   227,  -246,    86,  -246,   238,   151,
      86,   151,   151,    86,  -246,   333,  -246,   251,  -246,   334,
     331,   335,   336,   171,   337,    86,   261,   338,  -246,   339,
    -246,  -246,  -246,  -246,   340,   333,  -246,  -246,  -246
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     3,     0,     0,     4,     0,
       7,     0,     0,     6,     0,     5,    12,    14,     8,    10,
       9,    11,    15,    13,    27,    33,    35,    18,    22,   123,
       0,    37,     0,   114,   114,    16,     0,    20,    24,     0,
       0,     0,     0,    28,   114,     0,     0,     0,     0,   118,
       0,     0,   124,   113,   112,   106,     0,     0,    55,    63,
      57,   104,    38,    30,     0,   117,   114,     0,    34,    36,
     118,    17,   118,     0,    21,    22,    40,   108,   109,     0,
     106,    78,    79,    77,    75,    76,    94,     0,     0,     0,
      94,     0,     0,   122,    40,    31,     0,   171,     0,   116,
     110,     0,     0,   121,   118,     0,    25,    23,     0,   126,
     105,   107,    94,     0,     0,     0,   118,     0,     0,   118,
      86,    87,    88,     0,     0,    71,    65,    72,    74,    42,
      30,    29,   172,   111,   114,    19,   120,     0,    26,   118,
       0,     0,     0,     0,     0,    95,    56,    59,   103,     0,
       0,    58,     0,     0,     0,     0,     0,   106,     0,     0,
       0,     0,     0,    32,   115,   118,     0,     0,   130,   135,
     140,   141,     0,   128,   168,   118,     0,   132,   149,   125,
       0,    60,     0,     0,    65,     0,    65,     0,    65,     0,
      65,     0,    64,   118,     0,    44,    49,    54,     0,    46,
      96,    39,   119,    41,     0,     0,     0,   138,     0,   134,
     126,   170,     0,   126,     0,     0,     0,    92,    93,    89,
      90,    91,     0,     0,     0,     0,   126,     0,     0,     0,
       0,     0,    85,    66,     0,    80,     0,     0,     0,     0,
       0,    73,     0,    52,     0,    48,    42,   101,     0,     0,
       0,     0,    42,     0,     0,     0,   138,     0,     0,   141,
     118,   131,     0,   129,   126,     0,     0,     0,     0,     0,
       0,     0,   153,     0,     0,   118,     0,     0,   133,    62,
      61,    68,     0,     0,     0,     0,    82,    67,    81,    69,
      83,    70,    84,    42,    52,     0,   118,    45,   101,     0,
       0,     0,   118,     0,    47,   145,   146,   147,   139,   136,
     142,     0,   144,   143,     0,     0,   127,     0,   155,   157,
     156,   158,   148,   154,     0,     0,     0,   162,     0,   163,
       0,     0,     0,     0,     0,    43,    53,    50,     0,   102,
      97,     0,     0,     0,     0,   169,     0,   151,     0,   164,
       0,   166,   167,     0,   152,     0,    99,     0,   100,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    54,     0,
     137,   159,   150,   161,     0,    52,    51,    98,   160
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -246,  -246,  -246,  -246,  -246,  -246,  -246,  -246,  -246,  -246,
    -246,  -246,   267,   186,  -246,  -246,  -246,   224,  -246,  -246,
    -246,  -246,  -246,  -246,  -246,  -246,   265,  -211,  -246,  -246,
    -152,    34,  -246,   -41,  -157,  -246,   -91,  -215,  -246,   -99,
    -165,  -118,  -185,   -63,  -141,    68,  -144,   -28,   -69,  -246,
     -68,  -246,   -22,   -66,  -246,  -246,  -246,  -246,  -195,  -246,
    -246,  -246,  -133,   128,  -246,   169,  -245,  -198,    46,   121,
    -193,   179,  -221,  -246,  -246,  -246,  -246,   332,   341
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,    10,     8,    12,    16,    48,    35,
      17,    50,    37,    38,    18,    32,    63,    96,   130,    19,
      33,    20,    34,    21,    42,    94,   109,   162,   246,   252,
     294,   295,   196,   112,    58,    59,   329,   125,    92,   126,
     127,   128,   225,   113,   298,   299,    60,    61,    79,    80,
     101,    55,    45,    73,    22,    23,    39,    76,   144,   213,
     210,   226,   256,   257,   169,   170,   258,   171,   177,   271,
     178,   267,   330,   353,   173,   174,   212,    66,    67
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      57,   124,    41,   197,   102,   157,   103,   168,   195,   259,
     277,   111,    46,   251,   312,   261,    64,   200,   263,   232,
     199,   232,    65,   232,    53,   232,    64,   118,    97,   272,
      98,   278,   133,   158,    44,   297,   303,   137,   136,    54,
       3,   304,   140,   141,    99,    72,   114,     4,   117,   145,
     149,   120,   121,   152,   184,   186,   188,   190,  -113,   115,
    -113,   313,   183,   185,   187,   189,     6,   142,   312,   316,
     143,   200,   200,   166,   266,   268,   150,   230,   235,   272,
     317,   325,   335,    14,    15,   231,   197,   236,   191,   238,
      11,   240,   229,   122,   234,   276,   237,     7,   239,   202,
       9,   327,   346,   200,    13,   204,   205,   206,    36,   214,
     120,   121,   164,   159,   160,   313,   161,   232,   232,   232,
     232,    77,    78,   120,   121,   361,   313,   242,    40,   364,
     207,    43,   365,   208,   122,    44,   328,   197,    47,   227,
     209,   228,    24,    25,   374,    26,    27,    28,    29,   230,
      49,    30,   215,   216,   200,    51,    52,   200,   157,    56,
     341,    62,    68,   253,   254,   255,   232,   232,   232,   232,
      69,   315,    70,    31,    71,   120,   121,   215,   216,    72,
     217,   218,    74,   331,   332,   333,   334,   219,   220,   221,
     204,   205,   206,    75,   314,   120,   121,    93,   368,   122,
      95,   123,   222,   367,   223,   224,   100,   106,   301,   326,
     157,   359,   343,   200,   108,   324,   369,   110,   368,   122,
     300,   123,   233,   153,   154,   155,   156,   204,   205,   206,
     338,   116,   231,   236,   238,   240,   342,   282,   283,   284,
     285,   119,   122,   349,   350,   351,   352,   131,   132,   134,
     184,   186,   188,   190,   135,   360,    81,    82,   183,   363,
     187,   189,   122,   139,   211,   122,   146,    83,    84,    85,
     147,   148,   234,   151,   165,   243,    87,   167,   244,    89,
      90,    91,    54,    81,    82,   245,   172,   175,   176,   262,
     179,   180,   138,   181,    83,    84,    85,   182,   192,   193,
     194,   198,   375,    87,   201,   244,    89,    90,    91,    54,
     217,   218,   245,   203,   227,   241,   260,   219,   220,   221,
     264,   265,   270,   273,    53,    81,    82,   275,   336,   279,
     280,   281,   247,   248,   249,   250,    83,    84,    85,    54,
     286,   287,   107,   288,    86,    87,   289,    88,    89,    90,
      91,    54,   290,   291,   163,   292,   293,   296,   302,   129,
     305,   306,   307,   309,   310,   311,   339,   318,   319,   320,
     321,   322,   337,   340,   344,   345,   347,   348,   354,   355,
     356,   357,   358,   366,   308,   370,   371,   372,   373,   376,
     377,   378,   274,   323,   362,   269,     0,     0,     0,     0,
       0,     0,     0,     0,   104,     0,     0,     0,     0,     0,
       0,     0,     0,   105
};

static const yytype_int16 yycheck[] =
{
      41,    92,    30,   160,    70,   123,    72,   140,   160,   207,
     225,    80,    34,   198,   259,   210,    30,   161,   213,   184,
     161,   186,    44,   188,    33,   190,    30,    90,    48,   222,
      50,   226,   100,   124,    48,   246,   251,   105,   104,    48,
       0,   252,    12,    13,    66,    49,    87,    50,    89,   112,
     116,    24,    25,   119,   153,   154,   155,   156,    49,    87,
      51,   259,   153,   154,   155,   156,     3,    37,   313,   264,
      40,   215,   216,   139,   215,   216,   117,    50,    51,   272,
     265,   274,   293,    50,    51,   184,   243,   186,   157,   188,
      48,   190,   183,    48,   185,    50,   187,    50,   189,   165,
       4,    15,   317,   247,    51,    16,    17,    18,    50,   175,
      24,    25,   134,    37,    38,   313,    40,   282,   283,   284,
     285,    48,    49,    24,    25,   346,   324,   193,    50,   350,
      41,    48,   353,    44,    48,    48,    50,   294,    50,   180,
      51,   182,     5,     6,   365,     8,     9,    10,    11,    50,
      48,    14,    16,    17,   298,    30,    48,   301,   276,    50,
     301,    48,    51,   204,   205,   206,   331,   332,   333,   334,
      51,   262,    48,    36,    51,    24,    25,    16,    17,    49,
      19,    20,    51,   282,   283,   284,   285,    26,    27,    28,
      16,    17,    18,    48,   260,    24,    25,    51,   355,    48,
      48,    50,    41,   355,    43,    44,    48,    51,   249,   275,
     328,   344,   303,   357,    39,    41,   357,    51,   375,    48,
     248,    50,    51,    29,    30,    31,    32,    16,    17,    18,
     296,    50,   331,   332,   333,   334,   302,    29,    30,    31,
      32,    50,    48,    29,    30,    31,    32,    51,     7,    51,
     349,   350,   351,   352,    51,   346,    22,    23,   349,   350,
     351,   352,    48,    50,    33,    48,    51,    33,    34,    35,
      51,    51,   363,    51,    51,    41,    42,    50,    44,    45,
      46,    47,    48,    22,    23,    51,    50,    50,    50,    15,
      51,    51,   106,    51,    33,    34,    35,    51,    51,    50,
      50,    50,    41,    42,    51,    44,    45,    46,    47,    48,
      19,    20,    51,    51,   355,    51,    50,    26,    27,    28,
      51,    50,    50,    50,    33,    22,    23,    50,   294,    51,
      51,    51,    41,    42,    43,    44,    33,    34,    35,    48,
      51,    51,    75,    51,    41,    42,    51,    44,    45,    46,
      47,    48,    51,    51,   130,    51,    51,    50,    50,    94,
      51,    51,    51,    51,    51,    50,   298,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    50,   256,    51,    51,    51,    51,    51,
      51,    51,   223,   272,   348,   216,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    54,    55,     0,    50,    56,     3,    50,    58,     4,
      57,    48,    59,    51,    50,    51,    60,    63,    67,    72,
      74,    76,   107,   108,     5,     6,     8,     9,    10,    11,
      14,    36,    68,    73,    75,    62,    50,    65,    66,   109,
      50,   100,    77,    48,    48,   105,   105,    50,    61,    48,
      64,    30,    48,    33,    48,   104,    50,    86,    87,    88,
      99,   100,    48,    69,    30,   105,   130,   131,    51,    51,
      48,    51,    49,   106,    51,    48,   110,    48,    49,   101,
     102,    22,    23,    33,    34,    35,    41,    42,    44,    45,
      46,    47,    91,    51,    78,    48,    70,    48,    50,   105,
      48,   103,   106,   106,   130,   131,    51,    65,    39,    79,
      51,   101,    86,    96,    86,   100,    50,    86,    96,    50,
      24,    25,    48,    50,    89,    90,    92,    93,    94,    79,
      71,    51,     7,   103,    51,    51,   106,   103,    66,    50,
      12,    13,    37,    40,   111,    96,    51,    51,    51,   106,
      86,    51,   106,    29,    30,    31,    32,    94,    89,    37,
      38,    40,    80,    70,   105,    51,   106,    50,   115,   117,
     118,   120,    50,   127,   128,    50,    50,   121,   123,    51,
      51,    51,    51,    89,    92,    89,    92,    89,    92,    89,
      92,   101,    51,    50,    50,    83,    85,    87,    50,    97,
      99,    51,   106,    51,    16,    17,    18,    41,    44,    51,
     113,    33,   129,   112,   106,    16,    17,    19,    20,    26,
      27,    28,    41,    43,    44,    95,   114,    86,    86,    89,
      50,    92,    93,    51,    89,    51,    92,    89,    92,    89,
      92,    51,   106,    41,    44,    51,    81,    41,    42,    43,
      44,    95,    82,    86,    86,    86,   115,   116,   119,   120,
      50,   111,    15,   111,    51,    50,    97,   124,    97,   124,
      50,   122,   123,    50,   118,    50,    50,    90,   111,    51,
      51,    51,    29,    30,    31,    32,    51,    51,    51,    51,
      51,    51,    51,    51,    83,    84,    50,    80,    97,    98,
     100,    86,    50,    90,    80,    51,    51,    51,   116,    51,
      51,    50,   119,   120,   106,    89,   111,    95,    51,    51,
      51,    51,    51,   122,    41,   123,   106,    15,    50,    89,
     125,    92,    92,    92,    92,    80,    84,    51,   106,    98,
      51,    97,   106,    89,    51,    51,    90,    51,    51,    29,
      30,    31,    32,   126,    51,    51,    51,    51,    51,   115,
      89,   125,   121,    89,   125,   125,    50,    83,    87,    97,
      51,    51,    51,    51,   125,    41,    51,    51,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    55,    54,    57,    56,    58,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    61,    60,    62,    62,
      64,    63,    65,    65,    65,    66,    66,    68,    69,    67,
      70,    71,    70,    73,    72,    75,    74,    77,    78,    76,
      79,    79,    80,    80,    81,    80,    82,    80,    83,    83,
      83,    83,    84,    84,    85,    86,    86,    87,    87,    87,
      87,    87,    87,    87,    88,    89,    89,    89,    89,    89,
      89,    89,    89,    90,    90,    91,    91,    91,    91,    91,
      92,    92,    92,    92,    92,    92,    93,    93,    94,    95,
      95,    95,    95,    95,    96,    96,    97,    97,    97,    97,
      97,    98,    98,    99,    99,   100,   101,   101,   102,   102,
     103,   103,   104,   104,   105,   105,   105,   105,   106,   106,
     106,   106,   107,   109,   110,   108,   111,   111,   112,   111,
     113,   111,   114,   111,   115,   115,   115,   115,   116,   116,
     117,   118,   118,   119,   119,   120,   120,   120,   121,   121,
     121,   121,   121,   122,   122,   123,   123,   123,   123,   124,
     125,   125,   125,   125,   126,   126,   126,   126,   127,   128,
     129,   130,   131
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     0,     6,     4,     0,     2,     2,
       2,     2,     2,     2,     2,     2,     0,     5,     0,     5,
       0,     5,     0,     4,     1,     4,     5,     0,     0,     7,
       0,     0,     3,     0,     5,     0,     5,     0,     0,     8,
       0,     4,     0,     5,     0,     4,     0,     4,     2,     1,
       4,     7,     0,     2,     1,     1,     4,     1,     4,     4,
       5,     7,     7,     1,     5,     1,     4,     5,     5,     5,
       5,     1,     1,     4,     1,     1,     1,     1,     1,     1,
       4,     5,     5,     5,     5,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     2,     1,     4,     7,     5,
       5,     0,     2,     4,     1,     4,     0,     2,     1,     1,
       1,     2,     1,     1,     0,     5,     3,     2,     0,     5,
       3,     2,     5,     0,     0,     8,     0,     5,     0,     4,
       0,     4,     0,     4,     2,     1,     4,     7,     0,     2,
       1,     1,     4,     1,     2,     4,     4,     4,     4,     1,
       7,     5,     5,     1,     2,     4,     4,     4,     4,     5,
       5,     4,     1,     1,     1,     1,     1,     1,     1,     5,
       1,     2,     3
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
#line 380 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
  opserr( DOMDEF_EXPECTED, NULL ); 
}
#line 1749 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 391 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
}
#line 1756 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 394 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  static int once=0;
  if ( gcmd_line.display_info >= 1 && once==0) {
    printf(" domain '%s' defined", gdomain_name);
	fflush(stdout);
    once=1;
  }
}
#line 1769 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 408 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
  gdomain_name = new_Token( strlen((yyvsp[-1].string))+1 );
  strcpy( gdomain_name, (yyvsp[-1].string));
}
#line 1778 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 450 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
}
#line 1785 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 453 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
}
#line 1792 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 487 "scan-ops_pddl.y" /* yacc.c:1646  */
    {}
#line 1798 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 490 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
 
  TypedListList *tll;

  if ( gparse_predicates ) {
    tll = gparse_predicates;
    while ( tll->next ) {
      tll = tll->next;
    }
    tll->next = new_TypedListList();
    tll = tll->next;
  } else {
    tll = new_TypedListList();
    gparse_predicates = tll;
  }

  tll->predicate = new_Token( strlen( (yyvsp[-2].string) ) + 1);
  strcpy( tll->predicate, (yyvsp[-2].string) );

  tll->args = (yyvsp[-1].pTypedList);
}
#line 1824 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 518 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
}
#line 1831 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 521 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
}
#line 1838 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 528 "scan-ops_pddl.y" /* yacc.c:1646  */
    {}
#line 1844 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 531 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  TypedListList *tll;
 
  if ( gparse_functions )
  {
    tll = gparse_functions;
    while (tll->next)
      tll = tll->next;
    tll->next = (yyvsp[-3].pTypedListList);   
  }
  else
    gparse_functions = (yyvsp[-3].pTypedListList);
}
#line 1862 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 546 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  TypedListList *tll;
  
  if ( gparse_functions ) 
  {
    tll = gparse_functions;
    while (tll->next)
      tll = tll->next;
    tll->next = (yyvsp[0].pTypedListList);   
  }
  else
    gparse_functions = (yyvsp[0].pTypedListList);
}
#line 1880 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 563 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pTypedListList) = new_TypedListList();
  (yyval.pTypedListList)->predicate = new_Token(strlen((yyvsp[-2].string))+1);
  strcpy((yyval.pTypedListList)->predicate, (yyvsp[-2].string));
  (yyval.pTypedListList)->args = (yyvsp[-1].pTypedList);
  (yyval.pTypedListList)->next = NULL;
}
#line 1892 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 572 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pTypedListList) = new_TypedListList();
  (yyval.pTypedListList)->predicate = new_Token(strlen((yyvsp[-3].string))+1);
  strcpy((yyval.pTypedListList)->predicate, (yyvsp[-3].string));
  (yyval.pTypedListList)->args = (yyvsp[-2].pTypedList);
  (yyval.pTypedListList)->next = (yyvsp[0].pTypedListList);
}
#line 1904 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 609 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
  opserr( REQUIREM_EXPECTED, NULL ); 
}
#line 1912 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 613 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
  if ( !supported( (yyvsp[0].string) ) ) {
    opserr( NOT_SUPPORTED, (yyvsp[0].string) );
    yyerror();
  }
}
#line 1923 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 628 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
  if ( !supported( (yyvsp[0].string) ) ) {
    opserr( NOT_SUPPORTED, (yyvsp[0].string) );
    yyerror();
  }
}
#line 1934 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 641 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
  opserr( TYPEDEF_EXPECTED, NULL ); 
}
#line 1942 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 645 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  gparse_types = (yyvsp[-1].pTypedList);
}
#line 1950 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 654 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
  opserr( CONSTLIST_EXPECTED, NULL ); 
}
#line 1958 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 658 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  gparse_constants = (yyvsp[-1].pTypedList);
}
#line 1966 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 669 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
#if YYDEBUG != 0
  printf("\n\nin action_def rule\n\n\n"); 
#endif
  opserr( ACTION, NULL );
}
#line 1977 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 676 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  scur_op = new_PlOperator( (yyvsp[0].string) );
  preference_flag = 0;
}
#line 1986 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 681 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  char temp[128]; 
  if (preference_flag)
  {
    sprintf(temp, "PREF_%s", scur_op->name);
    scur_op1 = new_PlOperator( temp );
    scur_op1->params = scur_op->params;
    scur_op1->number_of_real_params = scur_op->number_of_real_params;
    scur_op1->parse_params = copy_TypedList(scur_op->parse_params);
    scur_op1->effects = copy_PlNode(scur_op->effects);
    scur_op1->preconds = scur_op->preconds;
    scur_op->preconds = copy_PlNode(scur_op->preconds);
    scur_op1->next = gloaded_ops;
    gloaded_ops = scur_op1; 
  }
  scur_op->next = gloaded_ops;
  gloaded_ops = scur_op; 
  scur_op = NULL;
}
#line 2010 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 706 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
  scur_op->params = NULL; 
}
#line 2018 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 711 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  TypedList *tl;
  scur_op->parse_params = (yyvsp[-1].pTypedList);
  for (tl = scur_op->parse_params; tl; tl = tl->next) {
    /* to be able to distinguish params from :VARS 
     */
    scur_op->number_of_real_params++;
  }
}
#line 2032 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 727 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  TypedList *tl = NULL;

  /* add vars as parameters 
   */
  if ( scur_op->parse_params ) {
    for( tl = scur_op->parse_params; tl->next; tl = tl->next ) {
      /* empty, get to the end of list 
       */
    }
    tl->next = (yyvsp[-2].pTypedList);
    tl = tl->next;
  } else {
    scur_op->parse_params = (yyvsp[-2].pTypedList);
  }
}
#line 2053 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 747 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
  scur_op->preconds = (yyvsp[0].pPlNode); 
}
#line 2061 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 753 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
  scur_op->effects = (yyvsp[0].pPlNode); 
}
#line 2069 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 761 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
	(yyval.pPlNode) = NULL;
}
#line 2077 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 766 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
	(yyval.pPlNode) = (yyvsp[0].pPlNode);
}
#line 2085 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 771 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
	(yyval.pPlNode) = new_PlNode(AND);  
	(yyval.pPlNode)->sons = (yyvsp[-1].pPlNode);
}
#line 2094 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 779 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 

  PlNode *pln;

  pln = new_PlNode(ALL);
  pln->parse_vars = (yyvsp[-3].pTypedList);

  (yyval.pPlNode) = pln;
  pln->sons = (yyvsp[-1].pPlNode);
  (yyval.pPlNode) = pln;

}
#line 2111 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 795 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
	(yyval.pPlNode) = NULL;
}
#line 2119 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 800 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
	if ((yyvsp[-1].pPlNode))
	{
		(yyvsp[-1].pPlNode)->next = (yyvsp[0].pPlNode);
		(yyval.pPlNode) = (yyvsp[-1].pPlNode);
	}
	else
		(yyval.pPlNode) = (yyvsp[0].pPlNode);
}
#line 2133 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 854 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
	(yyval.pPlNode) = (yyvsp[0].pPlNode);
}
#line 2141 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 866 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
	(yyval.pPlNode) = (yyvsp[0].pPlNode);
}
#line 2149 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 871 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
  (yyval.pPlNode) = new_PlNode(AND);
  (yyval.pPlNode)->sons = (yyvsp[-1].pPlNode);
}
#line 2158 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 879 "scan-ops_pddl.y" /* yacc.c:1646  */
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
#line 2174 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 898 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
  (yyval.pPlNode) = new_PlNode(OR);
  (yyval.pPlNode)->sons = (yyvsp[-1].pPlNode);
}
#line 2183 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 904 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
  (yyval.pPlNode) = new_PlNode(NOT);
  (yyval.pPlNode)->sons = (yyvsp[-1].pPlNode);
}
#line 2192 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 910 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
  PlNode *np = new_PlNode(NOT);
  np->sons = (yyvsp[-2].pPlNode);
  np->next = (yyvsp[-1].pPlNode);

  (yyval.pPlNode) = new_PlNode(OR);
  (yyval.pPlNode)->sons = np;
}
#line 2205 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 922 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 

  PlNode *pln;

  pln = new_PlNode(EX);
  pln->parse_vars = (yyvsp[-3].pTypedList);

  (yyval.pPlNode) = pln;
  pln->sons = (yyvsp[-1].pPlNode);

}
#line 2221 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 937 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 

  PlNode *pln;

  pln = new_PlNode(ALL);
  pln->parse_vars = (yyvsp[-3].pTypedList);

  (yyval.pPlNode) = pln;
  pln->sons = (yyvsp[-1].pPlNode);

}
#line 2237 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 962 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
  (yyval.pPlNode) = new_PlNode(BIN_COMP);
  (yyval.pPlNode)->sons = (yyvsp[-3].pPlNode);
  (yyval.pPlNode)->sons->sons= (yyvsp[-2].pPlNode);
  (yyval.pPlNode)->sons->sons->next= (yyvsp[-1].pPlNode);
}
#line 2248 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 973 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
       (yyval.pPlNode)=new_PlNode(NUM_EXP);
       (yyval.pPlNode)->sons = (yyvsp[0].pPlNode);
}
#line 2257 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 979 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
  PlNode *pln;

  (yyval.pPlNode)=new_PlNode(F_EXP);
  pln=new_PlNode(UMINUS_CONN); 
  (yyval.pPlNode)->sons = pln;
  (yyval.pPlNode)->sons->sons = (yyvsp[-1].pPlNode);
if (in_durative_action)
	num_dur++;
}
#line 2272 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 991 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
  PlNode *pln;

  (yyval.pPlNode)=new_PlNode(F_EXP);
  pln=new_PlNode(MINUS_CONN); 
  (yyval.pPlNode)->sons = pln;
  (yyval.pPlNode)->sons->sons = (yyvsp[-2].pPlNode);
  (yyval.pPlNode)->sons->sons->next = (yyvsp[-1].pPlNode);

if (in_durative_action)
	num_dur++;
}
#line 2289 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1005 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
  PlNode *pln;

  (yyval.pPlNode)=new_PlNode(F_EXP);
  pln=new_PlNode(PLUS_CONN); 
  (yyval.pPlNode)->sons = pln;
  (yyval.pPlNode)->sons->sons = (yyvsp[-2].pPlNode);
  (yyval.pPlNode)->sons->sons->next = (yyvsp[-1].pPlNode);


if (in_durative_action)
	num_dur++;
}
#line 2307 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1020 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
  PlNode *pln;

  (yyval.pPlNode)=new_PlNode(F_EXP);
  pln=new_PlNode(MUL_CONN); 
  (yyval.pPlNode)->sons = pln;
  (yyval.pPlNode)->sons->sons = (yyvsp[-2].pPlNode);
  (yyval.pPlNode)->sons->sons->next = (yyvsp[-1].pPlNode);

if (in_durative_action)
	num_dur++;
}
#line 2324 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1034 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
  PlNode *pln;

  (yyval.pPlNode)=new_PlNode(F_EXP);
  pln=new_PlNode(DIV_CONN); 
  (yyval.pPlNode)->sons = pln;
  (yyval.pPlNode)->sons->sons = (yyvsp[-2].pPlNode);
  (yyval.pPlNode)->sons->sons->next = (yyvsp[-1].pPlNode);

if (in_durative_action)
	num_dur++;
}
#line 2341 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1048 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode) = new_PlNode(FN_HEAD);
  (yyval.pPlNode)->atom = (yyvsp[0].pTokenList);
if (in_durative_action)
	num_dur++;
}
#line 2352 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1057 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
    (yyval.pPlNode)=new_PlNode(ATOM);
    (yyval.pPlNode)->atom = (yyvsp[0].pTokenList);
}
#line 2361 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1068 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
  (yyval.pTokenList) = new_TokenList();
  (yyval.pTokenList)->item = (yyvsp[-2].pstring);
  (yyval.pTokenList)->next = (yyvsp[-1].pTokenList);
}
#line 2371 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1075 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
  (yyval.pTokenList) = new_TokenList();
  (yyval.pTokenList)->item = (yyvsp[0].pstring);
}
#line 2380 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1085 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode)=new_PlNode(GREATER_THAN_CONN);
}
#line 2388 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1090 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode)=new_PlNode(LESS_THAN_CONN);
}
#line 2396 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1095 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode)=new_PlNode(EQUAL_CONN);
}
#line 2404 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1100 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode)=new_PlNode(GREATER_OR_EQUAL_CONN);
}
#line 2412 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1105 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode)=new_PlNode(LESS_THAN_OR_EQUAL_CONN);
}
#line 2420 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1112 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode)=new_PlNode(UMINUS_CONN);
  (yyval.pPlNode)->sons = (yyvsp[-1].pPlNode);
   
if (in_durative_action)
	num_dur++;
}
#line 2432 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1121 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode)=new_PlNode(MINUS_CONN);
  (yyval.pPlNode)->sons = (yyvsp[-2].pPlNode);
  (yyval.pPlNode)->sons->next = (yyvsp[-1].pPlNode);
if (in_durative_action)
	num_dur++;
}
#line 2444 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1130 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode)=new_PlNode(PLUS_CONN);
  (yyval.pPlNode)->sons = (yyvsp[-2].pPlNode);
  (yyval.pPlNode)->sons->next = (yyvsp[-1].pPlNode);
if (in_durative_action)
	num_dur++;
}
#line 2456 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1139 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode)=new_PlNode(MUL_CONN);
  (yyval.pPlNode)->sons = (yyvsp[-2].pPlNode);
  (yyval.pPlNode)->sons->next = (yyvsp[-1].pPlNode);
if (in_durative_action)
	num_dur++;
}
#line 2468 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1148 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode)=new_PlNode(DIV_CONN);
  (yyval.pPlNode)->sons = (yyvsp[-2].pPlNode);
  (yyval.pPlNode)->sons->next = (yyvsp[-1].pPlNode);
if (in_durative_action)
	num_dur++;
}
#line 2480 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1157 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
    (yyval.pPlNode)=new_PlNode(ATOM);
    (yyval.pPlNode)->atom = (yyvsp[0].pTokenList);
}
#line 2489 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1165 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  Token t;
  t = new_Token( strlen((yyvsp[0].string))+1 );
  strcpy (t, (yyvsp[0].string));
  (yyval.pTokenList) = new_TokenList();
  (yyval.pTokenList)->item = t;

}
#line 2502 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1175 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  Token t;
  t = new_Token( strlen((yyvsp[0].string))+1 );
  strcpy (t, (yyvsp[0].string));
  (yyval.pTokenList) = new_TokenList();
  (yyval.pTokenList)->item = t;

}
#line 2515 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1187 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
  (yyval.pstring) = new_Token( strlen((yyvsp[0].string))+1 );
  strcpy( (yyval.pstring), (yyvsp[0].string) );
}
#line 2524 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1231 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode)=new_PlNode(ASSIGN_CONN);
}
#line 2532 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1236 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode)=new_PlNode(SCALE_UP_CONN);
}
#line 2540 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1241 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode)=new_PlNode(SCALE_DOWN_CONN);
}
#line 2548 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1246 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode)=new_PlNode(INCREASE_CONN);
}
#line 2556 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1251 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode)=new_PlNode(DECREASE_CONN);
}
#line 2564 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1261 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode) = NULL;
}
#line 2572 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1266 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyvsp[-1].pPlNode)->next = (yyvsp[0].pPlNode);
  (yyval.pPlNode) = (yyvsp[-1].pPlNode);
}
#line 2581 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1278 "scan-ops_pddl.y" /* yacc.c:1646  */
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
#line 2597 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1291 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
  (yyval.pPlNode) = new_PlNode(AND);
  (yyval.pPlNode)->sons = (yyvsp[-1].pPlNode);
}
#line 2606 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1299 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 

  PlNode *pln;

  pln = new_PlNode(ALL);
  pln->parse_vars = (yyvsp[-3].pTypedList);

  (yyval.pPlNode) = pln;
  pln->sons = (yyvsp[-1].pPlNode);

}
#line 2622 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1312 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  /* This will be conditional effects in FF representation, but here
   * a formula like (WHEN p q) will be saved as:
   *  [WHEN]
   *  [sons]
   *   /  \
   * [p]  [q]
   * That means, the first son is p, and the second one is q. 
   */
  (yyval.pPlNode) = new_PlNode(WHEN);
  (yyvsp[-2].pPlNode)->next = (yyvsp[-1].pPlNode);
  (yyval.pPlNode)->sons = (yyvsp[-2].pPlNode);
}
#line 2640 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1327 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  PlNode* pln;
  (yyval.pPlNode)=(yyvsp[-3].pPlNode);
  pln = new_PlNode(FN_HEAD);
  (yyval.pPlNode)->sons = pln;
  (yyval.pPlNode)->sons->atom = (yyvsp[-2].pTokenList);
  (yyval.pPlNode)->sons->next = (yyvsp[-1].pPlNode);
}
#line 2653 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1340 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
  (yyval.pPlNode) = NULL; 
}
#line 2661 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1345 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyvsp[-1].pPlNode)->next = (yyvsp[0].pPlNode);
  (yyval.pPlNode) = (yyvsp[-1].pPlNode);
}
#line 2670 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1357 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
  (yyval.pTokenList) = (yyvsp[-1].pTokenList);
  sis_negated = TRUE;
}
#line 2679 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1363 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pTokenList) = (yyvsp[0].pTokenList);
}
#line 2687 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1372 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
  (yyval.pTokenList) = new_TokenList();
  (yyval.pTokenList)->item = (yyvsp[-2].pstring);
  (yyval.pTokenList)->next = (yyvsp[-1].pTokenList);
}
#line 2697 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1383 "scan-ops_pddl.y" /* yacc.c:1646  */
    { (yyval.pTokenList) = NULL; }
#line 2703 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1386 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pTokenList) = new_TokenList();
  (yyval.pTokenList)->item = (yyvsp[-1].pstring);
  (yyval.pTokenList)->next = (yyvsp[0].pTokenList);
}
#line 2713 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1397 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
  (yyval.pstring) = new_Token( strlen((yyvsp[0].string))+1 );
  strcpy( (yyval.pstring), (yyvsp[0].string) );
}
#line 2722 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1403 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
  (yyval.pstring) = new_Token( strlen((yyvsp[0].string))+1 );
  strcpy( (yyval.pstring), (yyvsp[0].string) );
}
#line 2731 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1413 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pTokenList) = new_TokenList();
  (yyval.pTokenList)->item = new_Token( strlen((yyvsp[0].string))+1 );
  strcpy( (yyval.pTokenList)->item, (yyvsp[0].string) );
}
#line 2741 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1420 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pTokenList) = new_TokenList();
  (yyval.pTokenList)->item = new_Token( strlen((yyvsp[-1].string))+1 );
  strcpy( (yyval.pTokenList)->item, (yyvsp[-1].string) );
  (yyval.pTokenList)->next = (yyvsp[0].pTokenList);
}
#line 2752 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1431 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
  (yyval.pstring) = new_Token( strlen((yyvsp[0].string))+1 );
  strcpy( (yyval.pstring), (yyvsp[0].string) );
}
#line 2761 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1437 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
  (yyval.pstring) = new_Token( strlen(EQ_STR)+1 );
  strcpy( (yyval.pstring), EQ_STR );
}
#line 2770 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1447 "scan-ops_pddl.y" /* yacc.c:1646  */
    { (yyval.pTypedList) = NULL; }
#line 2776 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1453 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 

  (yyval.pTypedList) = new_TypedList();
  (yyval.pTypedList)->name = new_Token( strlen((yyvsp[-4].string))+1 );
  strcpy( (yyval.pTypedList)->name, (yyvsp[-4].string) );
  (yyval.pTypedList)->type = (yyvsp[-2].pTokenList);
  (yyval.pTypedList)->next = (yyvsp[0].pTypedList);
}
#line 2789 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1463 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pTypedList) = new_TypedList();
  (yyval.pTypedList)->name = new_Token( strlen((yyvsp[-2].string))+1 );
  strcpy( (yyval.pTypedList)->name, (yyvsp[-2].string) );
  (yyval.pTypedList)->type = new_TokenList();
  (yyval.pTypedList)->type->item = new_Token( strlen((yyvsp[-1].pstring))+1 );
  strcpy( (yyval.pTypedList)->type->item, (yyvsp[-1].pstring) );
  (yyval.pTypedList)->next = (yyvsp[0].pTypedList);
}
#line 2803 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1474 "scan-ops_pddl.y" /* yacc.c:1646  */
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
#line 2821 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1493 "scan-ops_pddl.y" /* yacc.c:1646  */
    { (yyval.pTypedList) = NULL; }
#line 2827 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1499 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
  (yyval.pTypedList) = new_TypedList();
  (yyval.pTypedList)->name = new_Token( strlen((yyvsp[-4].string))+1 );
  strcpy( (yyval.pTypedList)->name, (yyvsp[-4].string) );
  (yyval.pTypedList)->type = (yyvsp[-2].pTokenList);
  (yyval.pTypedList)->next = (yyvsp[0].pTypedList);
}
#line 2839 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1511 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pTypedList) = new_TypedList();
  (yyval.pTypedList)->name = new_Token( strlen((yyvsp[-2].string))+1 );
  strcpy( (yyval.pTypedList)->name, (yyvsp[-2].string) );
  (yyval.pTypedList)->type = new_TokenList();
  (yyval.pTypedList)->type->item = new_Token( strlen((yyvsp[-1].pstring))+1 );
  strcpy( (yyval.pTypedList)->type->item, (yyvsp[-1].pstring) );
  (yyval.pTypedList)->next = (yyvsp[0].pTypedList);
}
#line 2853 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1522 "scan-ops_pddl.y" /* yacc.c:1646  */
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
#line 2871 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1541 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
	PlDP *deri_def = (PlDP *) malloc(sizeof(PlDP));
	deri_def->atom = (yyvsp[-2].pTokenList);
	deri_def->preconds = (yyvsp[-1].pPlNode);
	if ((yyvsp[-1].pPlNode)->connective != ATOM && (yyvsp[-1].pPlNode)->connective != AND)
	{
		printf("Not implemented\n");
		exit(1);
	}
	gnum_deripreds++;
	deri_def->next = gloaded_dps;
	gloaded_dps = deri_def;
}
#line 2889 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1558 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
in_durative_action = TRUE;
  opserr( ACTION, NULL ); 
}
#line 2898 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1563 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
  scur_op = new_PlOperator( (yyvsp[0].string) );
  preference_flag = 0;
}
#line 2907 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1568 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  char temp[128]; 
  if (preference_flag)
  {
    sprintf(temp, "PREF_%s", scur_op->name);
    scur_op1 = new_PlOperator( temp );
    scur_op1->params = scur_op->params;
    scur_op1->number_of_real_params = scur_op->number_of_real_params;
    scur_op1->parse_params = copy_TypedList(scur_op->parse_params);
    scur_op1->effects = copy_PlNode(scur_op->effects);
    scur_op1->duration = copy_PlNode(scur_op->duration);
    scur_op1->preconds = scur_op->preconds;
    scur_op->preconds = copy_PlNode(scur_op->preconds);
    scur_op1->next = gloaded_ops;
    gloaded_ops = scur_op1; 
  }
  scur_op->next = gloaded_ops;
  gloaded_ops = scur_op;
  scur_op = NULL;
in_durative_action = FALSE; 
}
#line 2933 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1595 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  TypedList *tl = NULL;

  /* add vars as parameters 
   */
  if ( scur_op->parse_params ) {
    for( tl = scur_op->parse_params; tl->next; tl = tl->next ) {
      /* empty, get to the end of list 
       */
    }
    tl->next = (yyvsp[-2].pTypedList);
    tl = tl->next;
  } else {
    scur_op->parse_params = (yyvsp[-2].pTypedList);
  }
}
#line 2954 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1613 "scan-ops_pddl.y" /* yacc.c:1646  */
    {

scur_op->duration = (yyvsp[0].pPlNode)
  
}
#line 2964 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1622 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
  scur_op->preconds = (yyvsp[0].pPlNode); 
}
#line 2972 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1628 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 
  scur_op->effects = (yyvsp[0].pPlNode); 
}
#line 2980 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1636 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
	(yyval.pPlNode) = NULL;
}
#line 2988 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1641 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
	(yyval.pPlNode) = (yyvsp[0].pPlNode);
}
#line 2996 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1646 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
	(yyval.pPlNode) = new_PlNode(AND);  
	(yyval.pPlNode)->sons = (yyvsp[-1].pPlNode);
}
#line 3005 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1654 "scan-ops_pddl.y" /* yacc.c:1646  */
    { 

  PlNode *pln;

  pln = new_PlNode(ALL);
  pln->parse_vars = (yyvsp[-3].pTypedList);

  (yyval.pPlNode) = pln;
  pln->sons = (yyvsp[-1].pPlNode);

}
#line 3021 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1669 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
	(yyval.pPlNode) = NULL;
}
#line 3029 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1674 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
	if ((yyvsp[-1].pPlNode))
	{
		(yyvsp[-1].pPlNode)->next = (yyvsp[0].pPlNode);
		(yyval.pPlNode) = (yyvsp[-1].pPlNode);
	}
	else
		(yyval.pPlNode) = (yyvsp[0].pPlNode);
}
#line 3043 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1687 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
	(yyval.pPlNode) = (yyvsp[0].pPlNode);
}
#line 3051 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1700 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode) = new_PlNode(AND);
  (yyval.pPlNode)->sons = (yyvsp[0].pPlNode);
}
#line 3060 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1706 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode) = new_PlNode(AND);
  (yyval.pPlNode)->sons = (yyvsp[-1].pPlNode);
}
#line 3069 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1714 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode)=(yyvsp[0].pPlNode);
}
#line 3077 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1719 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode) = (yyvsp[-1].pPlNode);
  (yyval.pPlNode)->next = (yyvsp[0].pPlNode);
}
#line 3086 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1727 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode) = new_PlNode(AT_START_CONN);
  (yyval.pPlNode)->sons = (yyvsp[-1].pPlNode);
}
#line 3095 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1733 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode) = new_PlNode(AT_END_CONN);
  (yyval.pPlNode)->sons = (yyvsp[-1].pPlNode);
}
#line 3104 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1739 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode) = new_PlNode(OVER_ALL_CONN);
  (yyval.pPlNode)->sons = (yyvsp[-1].pPlNode);
}
#line 3113 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1751 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode) = new_PlNode(AND);
  (yyval.pPlNode)->sons = (yyvsp[-1].pPlNode);
}
#line 3122 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1757 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode) = new_PlNode(AND);
  (yyval.pPlNode)->sons = (yyvsp[0].pPlNode);
}
#line 3131 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1766 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  PlNode *pln;

  pln = new_PlNode(ALL);
  pln->parse_vars = (yyvsp[-3].pTypedList);

  (yyval.pPlNode) = pln;
  pln->sons = (yyvsp[-1].pPlNode);
}
#line 3145 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1777 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  /* This will be conditional effects in FF representation, but here
   * a formula like (WHEN p q) will be saved as:
   *  [WHEN]
   *  [sons]
   *   /  \
   * [p]  [q]
   * That means, the first son is p, and the second one is q. 
   */
  (yyval.pPlNode) = new_PlNode(WHEN);
  (yyvsp[-2].pPlNode)->next = (yyvsp[-1].pPlNode);
  (yyval.pPlNode)->sons = (yyvsp[-2].pPlNode);
}
#line 3163 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1792 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  PlNode* pln;
  (yyval.pPlNode)=(yyvsp[-3].pPlNode);
  pln = new_PlNode(FN_HEAD);
  (yyval.pPlNode)->sons = pln;
  (yyval.pPlNode)->sons->atom = (yyvsp[-2].pTokenList);
  (yyval.pPlNode)->sons->next = (yyvsp[-1].pPlNode);
}
#line 3176 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1804 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode) = (yyvsp[0].pPlNode);
}
#line 3184 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1809 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode) = (yyvsp[-1].pPlNode);
  (yyval.pPlNode)->next = (yyvsp[0].pPlNode);
}
#line 3193 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 1817 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode) = new_PlNode(AT_START_CONN);
  (yyval.pPlNode)->sons = (yyvsp[-1].pPlNode);
}
#line 3202 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 1823 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode) = new_PlNode(AT_END_CONN);
  (yyval.pPlNode)->sons = (yyvsp[-1].pPlNode);
}
#line 3211 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 1829 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode) = new_PlNode(AT_START_CONN);
  (yyval.pPlNode)->sons = (yyvsp[-1].pPlNode);
}
#line 3220 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 1835 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode) = new_PlNode(AT_END_CONN);
  (yyval.pPlNode)->sons = (yyvsp[-1].pPlNode);
}
#line 3229 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 1857 "scan-ops_pddl.y" /* yacc.c:1646  */
    {

  PlNode* pln;
  (yyval.pPlNode)=(yyvsp[-3].pPlNode);
  pln = new_PlNode(FN_HEAD);
  (yyval.pPlNode)->sons = pln;
  (yyval.pPlNode)->sons->atom = (yyvsp[-2].pTokenList);
  (yyval.pPlNode)->sons->next = (yyvsp[-1].pPlNode);

}
#line 3244 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1872 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode) = (yyvsp[-3].pPlNode);
  (yyval.pPlNode)->sons->sons = (yyvsp[-2].pPlNode);
  (yyval.pPlNode)->sons->sons->next = (yyvsp[-1].pPlNode);
}
#line 3254 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1879 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  PlNode *pln;

  (yyval.pPlNode)=new_PlNode(F_EXP);
  pln=new_PlNode(UMINUS_CONN); 
  (yyval.pPlNode)->sons = pln;
  (yyval.pPlNode)->sons->sons = (yyvsp[-1].pPlNode);
}
#line 3267 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1889 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  PlNode *pln;

  (yyval.pPlNode)=new_PlNode(F_EXP);
  pln=new_PlNode(DURATION_VAR_ATOM); 
  (yyval.pPlNode)->sons = pln;
}
#line 3279 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1903 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  PlNode *pln;

  (yyval.pPlNode)=new_PlNode(F_EXP);
  pln=new_PlNode(PLUS_CONN); 
  (yyval.pPlNode)->sons = pln;

}
#line 3292 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1913 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  PlNode *pln;

  (yyval.pPlNode)=new_PlNode(F_EXP);
  pln=new_PlNode(MINUS_CONN); 
  (yyval.pPlNode)->sons = pln;

}
#line 3305 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1923 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  PlNode *pln;

  (yyval.pPlNode)=new_PlNode(F_EXP);
  pln=new_PlNode(MUL_CONN); 
  (yyval.pPlNode)->sons = pln;

}
#line 3318 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1933 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  PlNode *pln;

  (yyval.pPlNode)=new_PlNode(F_EXP);
  pln=new_PlNode(DIV_CONN); 
  (yyval.pPlNode)->sons = pln;

}
#line 3331 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1990 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pPlNode) = new_PlNode(AND);
  (yyval.pPlNode)->sons = (yyvsp[0].pPlNode);
}
#line 3340 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 2015 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  PlNode *pln;

  (yyval.pPlNode) = (yyvsp[-3].pPlNode);
  pln = new_PlNode(DURATION_VAR_ATOM);
  (yyval.pPlNode)->sons->sons = pln;
  (yyval.pPlNode)->sons->sons->next = (yyvsp[-1].pPlNode);
}
#line 3353 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 2056 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  PlNode *pln;

  (yyval.pPlNode)=new_PlNode(DURATION_CONSTRAINT_CONN);
  pln=new_PlNode(EQUAL_CONN); 
  (yyval.pPlNode)->sons = pln;
}
#line 3365 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 2067 "scan-ops_pddl.y" /* yacc.c:1646  */
    {
  (yyval.pstring) = new_Token(strlen((yyvsp[0].string)) + 1);
  strcpy((yyval.pstring), (yyvsp[0].string));
}
#line 3374 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
    break;


#line 3378 "scan-ops_pddl.tab.c" /* yacc.c:1646  */
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
#line 2077 "scan-ops_pddl.y" /* yacc.c:1906  */

#include "lex.ops_pddl.c"


/**********************************************************************
 * Functions
 **********************************************************************/



int yyerror( char *msg )

{

  fflush(stdout);
  fprintf(stderr, "\n%s: syntax error in line %d, '%s':\n", 
	  gact_filename, lineno, ops_pddltext);

  if ( NULL != sact_err_par ) {
    fprintf(stderr, "%s %s\n", serrmsg[sact_err], sact_err_par);
  } else {
    fprintf(stderr, "%s\n", serrmsg[sact_err]);
  }

  exit( 1 );

}



void load_ops_file( char *filename )

{

  FILE * fp;/* pointer to input files */
  char tmp[MAX_LENGTH] = "";

  /* open operator file 
   */
  if( ( fp = fopen( filename, "r" ) ) == NULL ) {
    sprintf(tmp, "\n Can't find operator file: %s\n\n", filename );
    perror(tmp);
    exit( 1 );
  }

  gact_filename = filename;
  lineno = 1; 
  ops_pddlin = fp;

  yyparse();

  fclose( fp );/* and close file again */

}

#ifdef YYDEBUG
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
#endif
