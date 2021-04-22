/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

    void yyerror(char* s);
    int yylex();
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    void ins();
    void insV();
    int flag=1;
    FILE* fp;
    int T_cnt = 0, valtop = 0, lbltop = 0, L_cnt = 0;
    extern char Match_str[20];
    extern char Match_type[20];
    extern char curval[20];
    extern char cur_identifier[20];
    extern char cur_function[20];
    extern int cur_scope;
    extern int params_cnt;
    extern int funccall_params_cnt;
    void insert_symbol_table_scope(char*, int);
    void insert_symbol_table_params_cnt(char*, int);
    void remove_scope(int);
    int verify_funccall_cnt(char*, int);
    int check_arg_type(int , char* , int);
    void insert_arg_type(char*, char*, int);
    void insert_func_table(char* );
    char get_identifier_type(char* );
    struct labl {
        char value[500];
        int id;
    } val_stack[100], labl_stack[100];
    void val_push(char* );
    void TAC();
    void reassign_TAC();
    void identifier_TAC();
    void constant_TAC();
    void if_not_goto();
    void if_end_goto();
    void if_end_label();
    void iter_label();
    void iter_loop_label(); 
    void TAC_assign();

#line 114 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    IF = 258,
    ELSE = 259,
    INT = 260,
    CHAR = 261,
    FLOAT = 262,
    DOUBLE = 263,
    LONG = 264,
    SHORT = 265,
    SIGNED = 266,
    UNSIGNED = 267,
    STRUCT = 268,
    RETURN = 269,
    MAIN = 270,
    VOID = 271,
    WHILE = 272,
    FOR = 273,
    DO = 274,
    BREAK = 275,
    ENDIF = 276,
    AUTO = 277,
    SWITCH = 278,
    CASE = 279,
    ENUM = 280,
    REG = 281,
    TYPEDEF = 282,
    EXTERN = 283,
    UNION = 284,
    CONTINUE = 285,
    STATIC = 286,
    DEFAULT = 287,
    GOTO = 288,
    VOLATILE = 289,
    CONST = 290,
    IDENTIFIER = 291,
    NUM_CONSTANT = 292,
    CHAR_CONSTANT = 293,
    STRING_CONSTANT = 294,
    leftshiftAssignment = 295,
    rightshiftAssignment = 296,
    xorAssignment = 297,
    orAssignment = 298,
    andAssignment = 299,
    moduloAssignment = 300,
    multiplicationAssignment = 301,
    divisionAssignment = 302,
    additionAssignment = 303,
    subtractionAssignment = 304,
    assignment = 305,
    SIZEOF = 306,
    negation = 307,
    not = 308,
    or = 309,
    and = 310,
    bitOr = 311,
    xor = 312,
    bitAnd = 313,
    equality = 314,
    inequality = 315,
    lessthanAssignment = 316,
    lessthan = 317,
    greaterthanAssignment = 318,
    greaterthan = 319,
    leftshift = 320,
    rightshift = 321,
    add = 322,
    subtract = 323,
    multiplication = 324,
    divide = 325,
    modulo = 326,
    increment = 327,
    decrement = 328
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define INT 260
#define CHAR 261
#define FLOAT 262
#define DOUBLE 263
#define LONG 264
#define SHORT 265
#define SIGNED 266
#define UNSIGNED 267
#define STRUCT 268
#define RETURN 269
#define MAIN 270
#define VOID 271
#define WHILE 272
#define FOR 273
#define DO 274
#define BREAK 275
#define ENDIF 276
#define AUTO 277
#define SWITCH 278
#define CASE 279
#define ENUM 280
#define REG 281
#define TYPEDEF 282
#define EXTERN 283
#define UNION 284
#define CONTINUE 285
#define STATIC 286
#define DEFAULT 287
#define GOTO 288
#define VOLATILE 289
#define CONST 290
#define IDENTIFIER 291
#define NUM_CONSTANT 292
#define CHAR_CONSTANT 293
#define STRING_CONSTANT 294
#define leftshiftAssignment 295
#define rightshiftAssignment 296
#define xorAssignment 297
#define orAssignment 298
#define andAssignment 299
#define moduloAssignment 300
#define multiplicationAssignment 301
#define divisionAssignment 302
#define additionAssignment 303
#define subtractionAssignment 304
#define assignment 305
#define SIZEOF 306
#define negation 307
#define not 308
#define or 309
#define and 310
#define bitOr 311
#define xor 312
#define bitAnd 313
#define equality 314
#define inequality 315
#define lessthanAssignment 316
#define lessthan 317
#define greaterthanAssignment 318
#define greaterthan 319
#define leftshift 320
#define rightshift 321
#define add 322
#define subtract 323
#define multiplication 324
#define divide 325
#define modulo 326
#define increment 327
#define decrement 328

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  33
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   265

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  83
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  99
/* YYNRULES -- Number of rules.  */
#define YYNRULES  182
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  273

#define YYUNDEFTOK  2
#define YYMAXUTOK   328


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      80,    81,     2,     2,    75,     2,    82,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    74,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    76,     2,    77,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    78,     2,    79,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    80,    80,    83,    86,    87,    90,    91,    92,    95,
      98,   101,   104,   107,   110,   110,   121,   121,   126,   127,
     130,   131,   131,   132,   135,   136,   137,   140,   140,   140,
     140,   141,   142,   143,   144,   145,   148,   148,   148,   148,
     151,   151,   151,   151,   154,   154,   157,   157,   160,   160,
     162,   162,   165,   169,   172,   175,   178,   178,   181,   181,
     184,   187,   188,   191,   191,   194,   195,   198,   198,   199,
     199,   200,   200,   201,   204,   204,   207,   208,   211,   212,
     215,   215,   215,   218,   219,   222,   222,   222,   223,   223,
     223,   224,   224,   224,   227,   239,   240,   243,   246,   249,
     252,   255,   256,   259,   269,   274,   278,   278,   282,   282,
     286,   286,   290,   290,   293,   293,   297,   297,   301,   301,
     305,   305,   309,   309,   313,   313,   319,   325,   325,   325,
     328,   334,   334,   335,   338,   339,   344,   354,   357,   360,
     360,   360,   360,   360,   360,   363,   372,   375,   375,   378,
     387,   390,   390,   390,   390,   390,   393,   393,   393,   396,
     396,   399,   408,   411,   418,   427,   428,   431,   434,   437,
     442,   442,   458,   458,   461,   461,   461,   464,   464,   465,
     468,   469,   470
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "INT", "CHAR", "FLOAT",
  "DOUBLE", "LONG", "SHORT", "SIGNED", "UNSIGNED", "STRUCT", "RETURN",
  "MAIN", "VOID", "WHILE", "FOR", "DO", "BREAK", "ENDIF", "AUTO", "SWITCH",
  "CASE", "ENUM", "REG", "TYPEDEF", "EXTERN", "UNION", "CONTINUE",
  "STATIC", "DEFAULT", "GOTO", "VOLATILE", "CONST", "IDENTIFIER",
  "NUM_CONSTANT", "CHAR_CONSTANT", "STRING_CONSTANT",
  "leftshiftAssignment", "rightshiftAssignment", "xorAssignment",
  "orAssignment", "andAssignment", "moduloAssignment",
  "multiplicationAssignment", "divisionAssignment", "additionAssignment",
  "subtractionAssignment", "assignment", "SIZEOF", "negation", "not", "or",
  "and", "bitOr", "xor", "bitAnd", "equality", "inequality",
  "lessthanAssignment", "lessthan", "greaterthanAssignment", "greaterthan",
  "leftshift", "rightshift", "add", "subtract", "multiplication", "divide",
  "modulo", "increment", "decrement", "';'", "','", "'['", "']'", "'{'",
  "'}'", "'('", "')'", "'.'", "$accept", "program", "declaration_list",
  "D", "declaration", "variable_declaration", "variable_declaration_list",
  "V", "variable_declaration_identifier", "$@1", "vdi",
  "identifier_array_type", "init_params", "$@2", "initilization",
  "type_specifier", "unsigned_grammar", "signed_grammar", "long_grammar",
  "short_grammar", "structure_definition", "$@3", "V1",
  "structure_declaration", "function_declaration",
  "function_declaration_type", "function_declaration_param_statement",
  "params", "parameters_list", "$@4", "parameters_identifier_list",
  "parameters_identifier_list_breakup", "param_identifier", "$@5",
  "param_identifier_breakup", "statement", "compound_statement", "$@6",
  "statment_list", "expression_statment", "conditional_statements", "$@7",
  "$@8", "conditional_statements_breakup", "iterative_statements", "$@9",
  "$@10", "$@11", "$@12", "$@13", "$@14", "return_statement",
  "return_statement_breakup", "break_statement", "string_initilization",
  "array_initialization", "array_int_declarations",
  "array_int_declarations_breakup", "expression", "expression_breakup",
  "@15", "@16", "@17", "@18", "@19", "@20", "@21", "@22", "$@23", "$@24",
  "simp_ex", "simp_ex_breakup", "$@25", "and_expression",
  "and_expression_breakup", "$@26", "unary_relation_expression",
  "regular_expression", "regular_expression_breakup", "RELOP",
  "sum_expression", "ADDOP", "term", "BITOP", "MULOP", "factor", "bit_exp",
  "mutable", "mutable_breakup", "immutable", "call", "$@27", "arguments",
  "arguments_list", "$@28", "$@29", "A", "$@30", "constant", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,    59,    44,    91,    93,   123,   125,
      40,    41,    46
};
# endif

#define YYPACT_NINF (-111)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-174)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     138,  -111,  -111,  -111,  -111,    13,    19,    17,    82,    -4,
    -111,    33,  -111,   138,  -111,     5,  -111,  -111,  -111,   240,
    -111,  -111,  -111,  -111,  -111,    13,    19,  -111,  -111,    13,
      19,  -111,    29,  -111,  -111,  -111,    -9,    -8,     2,  -111,
    -111,    14,  -111,  -111,  -111,  -111,  -111,  -111,  -111,    18,
    -111,   -42,  -111,    29,  -111,    62,    37,   224,    -1,    51,
    -111,  -111,  -111,  -111,  -111,    24,    20,    65,    44,    23,
      26,    34,    30,  -111,  -111,  -111,    -1,  -111,    -1,  -111,
      29,  -111,  -111,    36,  -111,  -111,  -111,   101,  -111,  -111,
      47,  -111,    68,    70,  -111,   148,   -40,  -111,    28,   146,
    -111,  -111,  -111,   224,    50,  -111,  -111,    86,    76,  -111,
      55,   240,  -111,    -1,    29,  -111,  -111,    58,  -111,    -1,
    -111,  -111,  -111,   -67,    52,   164,    37,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,    22,    22,  -111,  -111,  -111,    22,  -111,  -111,  -111,
    -111,  -111,    22,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,    -1,  -111,  -111,    -1,    98,  -111,  -111,  -111,    78,
      79,    80,   114,  -111,    83,  -111,  -111,  -111,  -111,    -1,
      81,    84,  -111,   164,    85,   142,    -1,    -1,   -55,   -40,
      28,  -111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -111,  -111,  -111,    91,  -111,  -111,   111,   111,  -111,  -111,
     104,  -111,  -111,   109,  -111,    -1,  -111,  -111,   118,    68,
      70,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
     -14,  -111,  -111,  -111,  -111,    37,   125,    -1,  -111,  -111,
      -1,  -111,  -111,   162,  -111,    37,  -111,    87,  -111,   145,
     134,   217,  -111,   149,    -1,  -111,   143,   162,  -111,  -111,
      37,  -111,    -1,  -111,   151,  -111,  -111,   158,    87,  -111,
      37,  -111,  -111
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    27,    28,    29,    30,    45,    47,    43,    39,     0,
      35,     0,     2,     5,     6,     0,     8,    10,     7,    57,
      44,    31,    46,    32,    40,    45,    47,    34,    36,    45,
      47,    33,    48,     1,     4,     3,    14,     0,    13,    58,
      53,     0,    56,    41,    42,    37,    38,    14,    52,     0,
      54,    19,     9,     0,    11,     0,    74,    51,     0,     0,
      15,    16,    12,    63,    59,    62,     0,     0,     0,     0,
       0,     0,   163,   180,   182,   181,     0,    79,     0,    73,
       0,    55,    68,     0,    67,    69,    70,     0,    71,    72,
       0,   104,   129,   133,   135,   138,   146,   162,   150,   160,
     159,   168,   169,    51,     0,    17,    21,     0,     0,    18,
      66,     0,    60,     0,     0,    95,    94,     0,    85,     0,
      97,   170,   134,   160,     0,    74,    74,    78,   127,   126,
     131,   130,   143,   144,   140,   142,   139,   141,   147,   148,
     136,     0,     0,   156,   157,   158,     0,   154,   155,   153,
     151,   152,     0,   118,   116,   120,   114,   110,   112,   106,
     108,     0,   122,   124,     0,     0,   103,   164,    50,     0,
       0,     0,     0,    23,     0,    64,    61,    80,    96,     0,
       0,   174,   167,    74,     0,     0,     0,     0,   137,   145,
     149,   161,     0,     0,     0,     0,     0,     0,     0,     0,
     105,   123,   125,     0,   166,    49,    26,    26,    98,    65,
       0,    86,    88,     0,   172,     0,    76,    75,     0,   129,
     133,   119,   117,   121,   115,   111,   113,   107,   109,   165,
       0,    22,    24,    25,    20,    74,     0,     0,   171,   175,
       0,   128,   132,     0,    81,    74,    89,   179,    92,   102,
       0,    84,    87,     0,     0,   176,     0,     0,   100,    99,
      74,    82,     0,   177,     0,   101,    83,     0,   179,    93,
      74,   178,    90
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -111,  -111,   213,  -111,  -111,     6,   -25,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,    35,     4,  -111,  -111,   -15,   -10,
    -111,  -111,   124,  -111,  -111,  -111,  -111,  -111,   130,  -111,
    -111,  -111,  -111,  -111,  -111,   -56,  -111,  -111,    71,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,   147,  -111,     0,  -111,   -57,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
    -110,    39,  -111,    67,    40,  -111,   -71,  -111,  -111,  -111,
     120,  -111,   117,  -111,  -111,   110,   119,   -74,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,    -5,  -111,  -111
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,    35,    13,    79,    37,    54,    38,    51,
      60,    61,   109,   170,   231,    80,    31,    27,    21,    23,
      16,    49,   104,    17,    18,    19,    40,    41,    42,    55,
      64,   112,    65,   110,   175,   183,    82,    83,   184,    84,
      85,   210,   251,   261,    86,   179,   236,   237,   253,    87,
     256,    88,   116,    89,   232,   233,   250,   258,    90,   166,
     198,   199,   196,   197,   195,   193,   192,   194,   201,   202,
      91,   129,   186,    92,   131,   187,    93,    94,   140,   141,
      95,   142,    96,   152,   146,    97,    98,    99,   167,   100,
     101,   181,   213,   214,   215,   247,   255,   268,   102
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      81,   105,   123,   177,    15,   122,    14,    48,    58,   164,
      43,   117,   138,   139,    45,   165,    44,    15,    20,    14,
      46,   124,    24,    39,    22,   208,    25,    26,    62,   143,
     144,   145,    32,    33,    59,    72,    73,    74,    75,   123,
      66,    36,     1,     2,     3,     4,     5,     6,     7,     8,
      67,    68,    76,    10,    69,    70,   -91,    71,    72,    73,
      74,    75,   180,   103,   243,    47,    52,   123,   123,   211,
     185,    50,   123,    72,    73,    74,    75,    53,   123,    78,
      72,    73,    74,    75,   147,   148,   149,    28,   106,    48,
      76,    29,    30,   150,   151,    56,    57,    76,    63,   111,
     113,   114,    78,   118,   200,   123,   119,   203,   120,   103,
     121,    77,   123,   123,   125,    39,   220,    78,   115,   107,
     126,   127,   128,   171,    78,   130,   172,   246,   108,   169,
     248,   174,   178,   182,   204,   221,   222,   223,   224,   225,
     226,   227,   228,     1,     2,     3,     4,     5,     6,     7,
       8,     9,   205,   208,    10,   212,   206,   207,   239,   218,
     209,   230,   254,   123,   217,  -173,   123,    66,   229,     1,
       2,     3,     4,     5,     6,     7,     8,    67,    68,   244,
      10,    69,    70,   -91,    71,   235,   153,   154,   155,   252,
     238,   156,   157,   158,   159,   160,   161,   263,   240,   249,
      72,    73,    74,    75,   266,   267,   245,   132,   133,   134,
     135,   136,   137,   259,   272,   138,   139,    76,   162,   163,
     257,   260,   164,   262,   264,   269,    34,   168,   165,     1,
       2,     3,     4,     5,     6,     7,     8,    67,    77,   270,
      10,   176,   234,   -77,    78,     1,     2,     3,     4,     5,
       6,     7,     8,   219,   216,   173,    10,   265,   241,   189,
     242,   188,   191,   271,     0,   190
};

static const yytype_int16 yycheck[] =
{
      56,    58,    76,   113,     0,    76,     0,    32,    50,    76,
      25,    68,    67,    68,    29,    82,    26,    13,     5,    13,
      30,    78,     5,    19,     5,    39,     9,    10,    53,    69,
      70,    71,    36,     0,    76,    36,    37,    38,    39,   113,
       3,    36,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    53,    16,    17,    18,    19,    20,    36,    37,
      38,    39,   119,    57,    78,    36,    74,   141,   142,   179,
     126,    80,   146,    36,    37,    38,    39,    75,   152,    80,
      36,    37,    38,    39,    56,    57,    58,     5,    37,   114,
      53,     9,    10,    65,    66,    81,    78,    53,    36,    75,
      80,    36,    80,    80,   161,   179,    80,   164,    74,   103,
      80,    74,   186,   187,    78,   111,   187,    80,    74,    68,
      19,    74,    54,    37,    80,    55,    50,   237,    77,    79,
     240,    76,    74,    81,    36,   192,   193,   194,   195,   196,
     197,   198,   199,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    74,    39,    16,    74,    77,    77,   215,    17,
      77,    50,    75,   237,    79,    81,   240,     3,    77,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,   235,
      16,    17,    18,    19,    20,    81,    40,    41,    42,   245,
      81,    45,    46,    47,    48,    49,    50,   254,    80,    37,
      36,    37,    38,    39,   260,   262,    81,    59,    60,    61,
      62,    63,    64,    79,   270,    67,    68,    53,    72,    73,
      75,     4,    76,    74,    81,    74,    13,   103,    82,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    74,    81,
      16,   111,   207,    79,    80,     5,     6,     7,     8,     9,
      10,    11,    12,   186,   183,   108,    16,   257,   219,   142,
     220,   141,   152,   268,    -1,   146
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      16,    84,    85,    87,    88,    98,   103,   106,   107,   108,
       5,   101,     5,   102,     5,     9,    10,   100,     5,     9,
      10,    99,    36,     0,    85,    86,    36,    89,    91,    98,
     109,   110,   111,   101,   102,   101,   102,    36,    89,   104,
      80,    92,    74,    75,    90,   112,    81,    78,    50,    76,
      93,    94,    89,    36,   113,   115,     3,    13,    14,    17,
      18,    20,    36,    37,    38,    39,    53,    74,    80,    88,
      98,   118,   119,   120,   122,   123,   127,   132,   134,   136,
     141,   153,   156,   159,   160,   163,   165,   168,   169,   170,
     172,   173,   181,    88,   105,   141,    37,    68,    77,    95,
     116,    75,   114,    80,    36,    74,   135,   141,    80,    80,
      74,    80,   159,   170,   141,    78,    19,    74,    54,   154,
      55,   157,    59,    60,    61,    62,    63,    64,    67,    68,
     161,   162,   164,    69,    70,    71,   167,    56,    57,    58,
      65,    66,   166,    40,    41,    42,    45,    46,    47,    48,
      49,    50,    72,    73,    76,    82,   142,   171,   105,    79,
      96,    37,    50,   137,    76,   117,   111,   153,    74,   128,
     141,   174,    81,   118,   121,   118,   155,   158,   163,   165,
     169,   168,   149,   148,   150,   147,   145,   146,   143,   144,
     141,   151,   152,   141,    36,    74,    77,    77,    39,    77,
     124,   153,    74,   175,   176,   177,   121,    79,    17,   156,
     159,   141,   141,   141,   141,   141,   141,   141,   141,    77,
      50,    97,   137,   138,    97,    81,   129,   130,    81,   141,
      80,   154,   157,    78,   118,    81,   153,   178,   153,    37,
     139,   125,   118,   131,    75,   179,   133,    75,   140,    79,
       4,   126,    74,   141,    81,   139,   118,   141,   180,    74,
      81,   179,   118
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    83,    84,    85,    86,    86,    87,    87,    87,    88,
      88,    89,    90,    90,    92,    91,    93,    93,    94,    94,
      95,    96,    95,    95,    97,    97,    97,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    99,    99,    99,    99,
     100,   100,   100,   100,   101,   101,   102,   102,   104,   103,
     105,   105,   106,   107,   108,   109,   110,   110,   112,   111,
     113,   114,   114,   116,   115,   117,   117,   118,   118,   118,
     118,   118,   118,   118,   120,   119,   121,   121,   122,   122,
     124,   125,   123,   126,   126,   128,   129,   127,   130,   131,
     127,   132,   133,   127,   134,   135,   135,   136,   137,   138,
     139,   140,   140,   141,   141,   142,   143,   142,   144,   142,
     145,   142,   146,   142,   147,   142,   148,   142,   149,   142,
     150,   142,   151,   142,   152,   142,   153,   155,   154,   154,
     156,   158,   157,   157,   159,   159,   160,   161,   161,   162,
     162,   162,   162,   162,   162,   163,   163,   164,   164,   165,
     165,   166,   166,   166,   166,   166,   167,   167,   167,   168,
     168,   169,   169,   170,   170,   171,   171,   172,   172,   172,
     174,   173,   175,   175,   177,   178,   176,   180,   179,   179,
     181,   181,   181
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     0,     1,     1,     1,     3,
       1,     2,     2,     0,     0,     3,     1,     2,     2,     0,
       4,     0,     4,     2,     1,     1,     0,     1,     1,     1,
       1,     2,     2,     2,     2,     1,     1,     2,     2,     0,
       1,     2,     2,     0,     1,     0,     1,     0,     0,     7,
       2,     0,     3,     2,     3,     3,     1,     0,     0,     3,
       2,     2,     0,     0,     3,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     0,     4,     2,     0,     2,     1,
       0,     0,     8,     2,     0,     0,     0,     7,     0,     0,
      11,     0,     0,     9,     2,     1,     2,     2,     2,     4,
       2,     2,     0,     2,     1,     2,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     2,     0,     2,     2,     0,     4,     0,
       2,     0,     4,     0,     2,     1,     2,     2,     0,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     2,     3,     2,     3,     1,     1,
       0,     5,     1,     0,     0,     0,     4,     0,     4,     0,
       1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 9:
#line 95 "parser.y"
                                                           {
                
            }
#line 1727 "y.tab.c"
    break;

  case 12:
#line 104 "parser.y"
                                            {
                yyval = yyvsp[0];
            }
#line 1735 "y.tab.c"
    break;

  case 14:
#line 110 "parser.y"
                         {ins(), insert_symbol_table_scope(cur_identifier, cur_scope); val_push(cur_identifier);}
#line 1741 "y.tab.c"
    break;

  case 15:
#line 110 "parser.y"
                                                                                                                      {
                if(yyvsp[0] != 127) reassign_TAC();
                char type = get_identifier_type(cur_identifier);
                if(type == 'i' && yyvsp[0] == 5) yyval = 5;
                else if(type == 'c' && yyvsp[0] == 6) yyval = 6;
                else if(yyvsp[0] != 127) {
                    puts("ERROR:  Declaration type Mismatch.\n");
                    yyerror("");
                }
            }
#line 1756 "y.tab.c"
    break;

  case 16:
#line 121 "parser.y"
                            {yyval = 127;}
#line 1762 "y.tab.c"
    break;

  case 17:
#line 121 "parser.y"
                                                                {
    yyval = yyvsp[0];    
}
#line 1770 "y.tab.c"
    break;

  case 20:
#line 130 "parser.y"
                                                      {puts("ERROR: Array size negative!!"); yyerror("");}
#line 1776 "y.tab.c"
    break;

  case 21:
#line 131 "parser.y"
                           {if(atoi(curval) == 0) {puts("ERROR: Array Size is 0!!"); yyerror("");}}
#line 1782 "y.tab.c"
    break;

  case 27:
#line 140 "parser.y"
                  {yyval = 5;}
#line 1788 "y.tab.c"
    break;

  case 28:
#line 140 "parser.y"
                                  {yyval = 6;}
#line 1794 "y.tab.c"
    break;

  case 29:
#line 140 "parser.y"
                                                   {yyval = 5;}
#line 1800 "y.tab.c"
    break;

  case 48:
#line 160 "parser.y"
                                { ins(); }
#line 1806 "y.tab.c"
    break;

  case 54:
#line 172 "parser.y"
                                             { params_cnt = 0; ins(); strcpy(cur_function, cur_identifier); insert_symbol_table_scope(cur_identifier, cur_scope); insert_func_table(cur_function); fprintf(fp, "function %s:\n", cur_function);}
#line 1812 "y.tab.c"
    break;

  case 58:
#line 181 "parser.y"
                             {insert_arg_type(Match_type, cur_function, params_cnt);}
#line 1818 "y.tab.c"
    break;

  case 59:
#line 181 "parser.y"
                                                                                                                 {insert_symbol_table_params_cnt(cur_function, params_cnt);}
#line 1824 "y.tab.c"
    break;

  case 63:
#line 191 "parser.y"
                         { ins(); insert_symbol_table_scope(cur_identifier, cur_scope+1); params_cnt++;}
#line 1830 "y.tab.c"
    break;

  case 74:
#line 204 "parser.y"
              {cur_scope++;}
#line 1836 "y.tab.c"
    break;

  case 75:
#line 204 "parser.y"
                                                   {remove_scope(cur_scope); cur_scope--;}
#line 1842 "y.tab.c"
    break;

  case 80:
#line 215 "parser.y"
                             {if_not_goto();}
#line 1848 "y.tab.c"
    break;

  case 81:
#line 215 "parser.y"
                                                            {if_end_goto();}
#line 1854 "y.tab.c"
    break;

  case 82:
#line 215 "parser.y"
                                                                                                            {if_end_label();}
#line 1860 "y.tab.c"
    break;

  case 85:
#line 222 "parser.y"
                        {iter_label();}
#line 1866 "y.tab.c"
    break;

  case 86:
#line 222 "parser.y"
                                                {if_not_goto();}
#line 1872 "y.tab.c"
    break;

  case 87:
#line 222 "parser.y"
                                                                               {iter_loop_label();}
#line 1878 "y.tab.c"
    break;

  case 88:
#line 223 "parser.y"
                                     {iter_label();}
#line 1884 "y.tab.c"
    break;

  case 89:
#line 223 "parser.y"
                                                             {if_not_goto();}
#line 1890 "y.tab.c"
    break;

  case 90:
#line 223 "parser.y"
                                                                                                          {iter_loop_label();}
#line 1896 "y.tab.c"
    break;

  case 91:
#line 224 "parser.y"
              {iter_label();}
#line 1902 "y.tab.c"
    break;

  case 92:
#line 224 "parser.y"
                                                             {if_not_goto(); iter_loop_label();}
#line 1908 "y.tab.c"
    break;

  case 94:
#line 227 "parser.y"
                                              {
                if(yyvsp[0] == 5 && get_identifier_type(cur_function) == 'i') {

                } else if(yyvsp[0] == 6 && get_identifier_type(cur_function) == 'c') {

                } else if(!(yyvsp[0] == 127 && get_identifier_type(cur_function) == 'v')){
                    puts("ERROR: RETURN Type mismatch!");
                    yyerror(cur_function);
                }
            }
#line 1923 "y.tab.c"
    break;

  case 95:
#line 239 "parser.y"
                  {yyval = 127;}
#line 1929 "y.tab.c"
    break;

  case 96:
#line 240 "parser.y"
                             {yyval = yyvsp[-1];}
#line 1935 "y.tab.c"
    break;

  case 98:
#line 246 "parser.y"
                                         { insV(); }
#line 1941 "y.tab.c"
    break;

  case 103:
#line 259 "parser.y"
                                         {
                if(yyvsp[-1] != yyvsp[0]) {
                    printf("ERROR: Type Mismatch.\n");
                    yyerror("");
                } else if(yyvsp[-1] == 5) {
                    yyval = 5;
                } else if(yyvsp[-1] == 6) {
                    yyval = 6;
                }
            }
#line 1956 "y.tab.c"
    break;

  case 104:
#line 269 "parser.y"
                      {
                yyval = yyvsp[0];
            }
#line 1964 "y.tab.c"
    break;

  case 105:
#line 274 "parser.y"
                                    {
                reassign_TAC();
                yyval = yyvsp[0];
            }
#line 1973 "y.tab.c"
    break;

  case 106:
#line 278 "parser.y"
                                 {val_push("+");}
#line 1979 "y.tab.c"
    break;

  case 107:
#line 278 "parser.y"
                                                             {
                TAC_assign();
                yyval = yyvsp[-1];
            }
#line 1988 "y.tab.c"
    break;

  case 108:
#line 282 "parser.y"
                                    {val_push("-");}
#line 1994 "y.tab.c"
    break;

  case 109:
#line 282 "parser.y"
                                                                {
                TAC_assign();
                yyval = yyvsp[-1];
            }
#line 2003 "y.tab.c"
    break;

  case 110:
#line 286 "parser.y"
                                       {val_push("*");}
#line 2009 "y.tab.c"
    break;

  case 111:
#line 286 "parser.y"
                                                                   {
                TAC_assign();
                yyval = yyvsp[-1];
            }
#line 2018 "y.tab.c"
    break;

  case 112:
#line 290 "parser.y"
                                 {val_push("/");}
#line 2024 "y.tab.c"
    break;

  case 113:
#line 290 "parser.y"
                                                             {
                yyval = yyvsp[-1];
            }
#line 2032 "y.tab.c"
    break;

  case 114:
#line 293 "parser.y"
                               {val_push("/");}
#line 2038 "y.tab.c"
    break;

  case 115:
#line 293 "parser.y"
                                                           {
                TAC_assign();
                yyval = yyvsp[-1];
            }
#line 2047 "y.tab.c"
    break;

  case 116:
#line 297 "parser.y"
                                   {val_push(">>");}
#line 2053 "y.tab.c"
    break;

  case 117:
#line 297 "parser.y"
                                                                {
                TAC_assign();
                yyval = yyvsp[-1];
            }
#line 2062 "y.tab.c"
    break;

  case 118:
#line 301 "parser.y"
                                  {val_push("<<");}
#line 2068 "y.tab.c"
    break;

  case 119:
#line 301 "parser.y"
                                                               {
                TAC_assign();
                yyval = yyvsp[-1];
            }
#line 2077 "y.tab.c"
    break;

  case 120:
#line 305 "parser.y"
                            {val_push("^");}
#line 2083 "y.tab.c"
    break;

  case 121:
#line 305 "parser.y"
                                                        {
                TAC_assign();
                yyval = yyvsp[-1];
            }
#line 2092 "y.tab.c"
    break;

  case 122:
#line 309 "parser.y"
                        {val_push("+"); val_push("1");}
#line 2098 "y.tab.c"
    break;

  case 123:
#line 309 "parser.y"
                                                       {
                TAC_assign();
                yyval = 5;
            }
#line 2107 "y.tab.c"
    break;

  case 124:
#line 313 "parser.y"
                        {val_push("-"); val_push("1");}
#line 2113 "y.tab.c"
    break;

  case 125:
#line 313 "parser.y"
                                                       {
                TAC_assign();
                yyval  = 5;
            }
#line 2122 "y.tab.c"
    break;

  case 126:
#line 319 "parser.y"
                                             {
                if(yyvsp[-1] != -98 && yyvsp[0] != -98) TAC();
                yyval = yyvsp[-1];
            }
#line 2131 "y.tab.c"
    break;

  case 127:
#line 325 "parser.y"
                 {val_push("||");}
#line 2137 "y.tab.c"
    break;

  case 128:
#line 325 "parser.y"
                                                                  {}
#line 2143 "y.tab.c"
    break;

  case 129:
#line 325 "parser.y"
                                                                      {yyval = -98;}
#line 2149 "y.tab.c"
    break;

  case 130:
#line 328 "parser.y"
                                                               {
                if(yyvsp[0] != -98 && yyvsp[-1] != -98) TAC();
                yyval = yyvsp[-1];
            }
#line 2158 "y.tab.c"
    break;

  case 131:
#line 334 "parser.y"
                  {val_push("&&");}
#line 2164 "y.tab.c"
    break;

  case 133:
#line 335 "parser.y"
              {yyval = -98;}
#line 2170 "y.tab.c"
    break;

  case 135:
#line 339 "parser.y"
                                 {
                yyval = yyvsp[0];
            }
#line 2178 "y.tab.c"
    break;

  case 136:
#line 344 "parser.y"
                                                        {
                {
                    if(yyvsp[0] != -98 && yyvsp[-1] != -98) TAC();
                }
                if(yyvsp[-1] == yyvsp[0]) {
                    yyval = yyvsp[-1];
                }
            }
#line 2191 "y.tab.c"
    break;

  case 137:
#line 354 "parser.y"
                                   {
                yyval = yyvsp[0];
            }
#line 2199 "y.tab.c"
    break;

  case 138:
#line 357 "parser.y"
              {yyval = -98;}
#line 2205 "y.tab.c"
    break;

  case 139:
#line 360 "parser.y"
                                    {val_push(">=");}
#line 2211 "y.tab.c"
    break;

  case 140:
#line 360 "parser.y"
                                                                           {val_push("<=");}
#line 2217 "y.tab.c"
    break;

  case 141:
#line 360 "parser.y"
                                                                                                           {val_push(">");}
#line 2223 "y.tab.c"
    break;

  case 142:
#line 360 "parser.y"
                                                                                                                                       {val_push("<");}
#line 2229 "y.tab.c"
    break;

  case 143:
#line 360 "parser.y"
                                                                                                                                                                  {val_push("==");}
#line 2235 "y.tab.c"
    break;

  case 144:
#line 360 "parser.y"
                                                                                                                                                                                                {val_push("!=");}
#line 2241 "y.tab.c"
    break;

  case 145:
#line 363 "parser.y"
                                        {
                TAC();
                if(yyvsp[-2] == yyvsp[0])
                    yyval = yyvsp[-2];
                else {
                    printf("ERROR: Type mismatch.\n");
                    yyerror("");
                }
            }
#line 2255 "y.tab.c"
    break;

  case 146:
#line 372 "parser.y"
                   {yyval = yyvsp[0];}
#line 2261 "y.tab.c"
    break;

  case 147:
#line 375 "parser.y"
                  {val_push("+");}
#line 2267 "y.tab.c"
    break;

  case 148:
#line 375 "parser.y"
                                              {val_push("-");}
#line 2273 "y.tab.c"
    break;

  case 149:
#line 378 "parser.y"
                                 {
                TAC();
                if(yyvsp[-2] == yyvsp[0])
                    yyval = yyvsp[-2];
                else {
                    printf("ERROR: Type mismatch");
                    yyerror("");
                };
            }
#line 2287 "y.tab.c"
    break;

  case 150:
#line 387 "parser.y"
                      {yyval = yyvsp[0];}
#line 2293 "y.tab.c"
    break;

  case 151:
#line 390 "parser.y"
                        { val_push("<<");}
#line 2299 "y.tab.c"
    break;

  case 152:
#line 390 "parser.y"
                                                        { val_push(">>");}
#line 2305 "y.tab.c"
    break;

  case 153:
#line 390 "parser.y"
                                                                                    {val_push("&");}
#line 2311 "y.tab.c"
    break;

  case 154:
#line 390 "parser.y"
                                                                                                             {val_push("|");}
#line 2317 "y.tab.c"
    break;

  case 155:
#line 390 "parser.y"
                                                                                                                                    {val_push("^");}
#line 2323 "y.tab.c"
    break;

  case 156:
#line 393 "parser.y"
                             {val_push("*");}
#line 2329 "y.tab.c"
    break;

  case 157:
#line 393 "parser.y"
                                                      {val_push("/");}
#line 2335 "y.tab.c"
    break;

  case 158:
#line 393 "parser.y"
                                                                                {val_push("%");}
#line 2341 "y.tab.c"
    break;

  case 159:
#line 396 "parser.y"
                        {yyval = yyvsp[0];}
#line 2347 "y.tab.c"
    break;

  case 161:
#line 399 "parser.y"
                                   {
                TAC();
                if(yyvsp[-2] == yyvsp[0])
                    yyval = yyvsp[-2];
                else {
                    printf("ERROR: Type mismatch");
                    yyerror("");
                };
            }
#line 2361 "y.tab.c"
    break;

  case 162:
#line 408 "parser.y"
                     {yyval = yyvsp[0];}
#line 2367 "y.tab.c"
    break;

  case 163:
#line 411 "parser.y"
                         {
                val_push(cur_identifier);
                
                char type = get_identifier_type(cur_identifier);
                if(type == 'i') yyval = 5;
                if(type == 'c') yyval = 6;
            }
#line 2379 "y.tab.c"
    break;

  case 164:
#line 418 "parser.y"
                                      {
                if(yyvsp[0] == 5 || yyvsp[-1] == 5) 
                    yyval = 5;
                else 
                    printf("ERROR: Type Mismatch");
                    yyerror("");
            }
#line 2391 "y.tab.c"
    break;

  case 166:
#line 428 "parser.y"
                             {if( yyvsp[0] == 5) yyval = 5;}
#line 2397 "y.tab.c"
    break;

  case 167:
#line 431 "parser.y"
                                 {
                if(yyvsp[-1] == 5) yyval = 5;
            }
#line 2405 "y.tab.c"
    break;

  case 168:
#line 434 "parser.y"
                   {
                if(yyvsp[0] == 5) yyval = 5;
            }
#line 2413 "y.tab.c"
    break;

  case 169:
#line 437 "parser.y"
                       {
                if(yyvsp[0] == 5) yyval = 5;
            }
#line 2421 "y.tab.c"
    break;

  case 170:
#line 442 "parser.y"
                             {strcpy(cur_function, cur_identifier);}
#line 2427 "y.tab.c"
    break;

  case 171:
#line 442 "parser.y"
                                                                                   {
                char type = get_identifier_type(cur_function);
                fprintf(fp, "goto %s\n", cur_function);
                if(type == 'i') yyval = 5;
                if(type == 'c') yyval = 6;

                if(!verify_funccall_cnt(cur_function, funccall_params_cnt)) {
                    puts("ERROR: Function Call arguments count mismatch");
                    yyerror(cur_function);
                }
                char tmp[100] = {0};
                sprintf(tmp, "%d", funccall_params_cnt);
                fprintf(fp, "pop_params %s\n", tmp);
            }
#line 2446 "y.tab.c"
    break;

  case 174:
#line 461 "parser.y"
              {funccall_params_cnt = 0;}
#line 2452 "y.tab.c"
    break;

  case 175:
#line 461 "parser.y"
                                                    {fprintf(fp, "push_param %s\n", val_stack[valtop].value); check_arg_type(yyvsp[0], cur_function, funccall_params_cnt);funccall_params_cnt++;}
#line 2458 "y.tab.c"
    break;

  case 177:
#line 464 "parser.y"
                             {fprintf(fp, "push_param %s\n", val_stack[valtop].value); check_arg_type(yyvsp[0], cur_function, funccall_params_cnt);;funccall_params_cnt++;}
#line 2464 "y.tab.c"
    break;

  case 180:
#line 468 "parser.y"
                            { insV(); constant_TAC(); yyval=5;}
#line 2470 "y.tab.c"
    break;

  case 181:
#line 469 "parser.y"
                                { insV(); constant_TAC();}
#line 2476 "y.tab.c"
    break;

  case 182:
#line 470 "parser.y"
                           { insV(); constant_TAC(); yyval=6;}
#line 2482 "y.tab.c"
    break;


#line 2486 "y.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 472 "parser.y"


extern FILE *yyin;
extern int yylineno;
extern char *yytext;
extern int cbracketsopen;
extern int cbracketsclose;
extern int bbracketsopen;
extern int bbracketsclose;
extern int fbracketsopen;
extern int fbracketsclose;
void insert_symbol_table_type(char *,char *);
void insert_symbol_table_value(char *, char *);
void insert_constantsTable(char *, char *);
void print_constant_table();
void print_symbol_table();
void print_func_table();
void val_push(char* str) {
    strcpy(val_stack[++valtop].value, str);
}

void if_end_label() {
    char code[100] = {0};
    strcpy(code, "L");
    sprintf(code + 1, "%d", labl_stack[lbltop].id);
    printf( "%s: \n" , code);
    fprintf(fp, "%s: \n", code);
    lbltop--;
}

void if_not_goto() {
    char code[100] = {0};
    strcpy(code, "L");
    sprintf(code + 1, "%d", L_cnt);
    printf( "if not %s goto %s\n" , val_stack[valtop].value, code);
    fprintf(fp, "if not %s goto %s\n", val_stack[valtop].value, code);
    labl_stack[++lbltop].id = L_cnt++;
}

void if_end_goto() {
    char code[100] = {0};
    strcpy(code, "L");
    sprintf(code + 1, "%d", L_cnt);
    printf( "goto %s\n" , code);
    fprintf(fp,  "goto %s\n" , code);
    code[0] = 'L';
    sprintf(code + 1, "%d", labl_stack[lbltop].id);
    printf( "%s: \n" , code);
    fprintf(fp, "%s: \n", code);
    labl_stack[lbltop].id = L_cnt++;
}

void iter_label() {
    char code[100] = {0};
    strcpy(code, "L");
    sprintf(code + 1, "%d", L_cnt);
    fprintf(fp, "%s:\n", code);
    labl_stack[++lbltop].id = L_cnt++;
}

void iter_loop_label()  {
    char code[100] = {0};
    strcpy(code, "L");
    sprintf(code + 1, "%d", labl_stack[lbltop-1].id);
    fprintf(fp, "goto %s\n", code);
    sprintf(code + 1, "%d", labl_stack[lbltop].id);
    fprintf(fp, "%s: \n", code);
    lbltop -= 2;
}

void identifier_TAC()  {
    char code[100] = {0};
    strcpy(code, "T");
    sprintf(code + 1, "%d", T_cnt);
    printf( "= %s NULL %s\n" , cur_identifier, code);
    fprintf(fp, "= %s NULL %s\n" , cur_identifier, code);
    T_cnt++;
    val_push(code);
}
void constant_TAC() {
    char code[100] = {0};
    strcpy(code, "T");
    sprintf(code + 1, "%d", T_cnt);
    printf( "= %s NULL %s\n" , curval , code);
    fprintf(fp, "= %s NULL %s\n"  , curval , code);
    T_cnt++;
    val_push(code);
}

void reassign_TAC() {
    if(valtop-1 < 0) return;
    printf( "= %s NULL %s\n" , val_stack[valtop].value, val_stack[valtop-1].value);
    fprintf(fp, "= %s NULL %s\n", val_stack[valtop].value, val_stack[valtop-1].value);
    valtop -= 2;
}

void TAC() {
    char code[100] = {0};
    strcpy(code, "T");
    if(valtop-2 < 0) return;
    sprintf(code + 1, "%d", T_cnt);
    printf( "%s %s %s %s\n" , val_stack[valtop-1].value, val_stack[valtop-2].value, val_stack[valtop].value, code);
    fprintf(fp, "%s %s %s %s\n", val_stack[valtop-1].value, val_stack[valtop-2].value, val_stack[valtop].value, code);
    valtop -= 2;
    strcpy(val_stack[valtop].value, code);
    T_cnt++;
}
void TAC_assign() {
    char code[100] = {0};
    strcpy(code, "T");

    sprintf(code + 1, "%d", T_cnt);
    printf( "%s %s %s %s\n" , val_stack[valtop-1].value, val_stack[valtop-2].value, val_stack[valtop].value, code);
    fprintf(fp, "%s %s %s %s\n", val_stack[valtop-1].value, val_stack[valtop-2].value, val_stack[valtop].value, code);
    valtop -= 2;
}

int main(int argc , char **argv)
{
    fp = fopen("TAC.txt", "w");
    yyin = fopen(argv[1], "r");
    yyparse();
    if((bbracketsopen-bbracketsclose)){
        printf("ERROR: brackets error [\n");
        flag = 1;
    }
    if((fbracketsopen-fbracketsclose)){
        printf("ERROR: brackets error {\n");
        flag = 1;
    }
    if((cbracketsopen-cbracketsclose)){
        printf("ERROR: brackets error (\n");
        flag = 1;
    }


    if(flag == 0)
    {
        printf("Status: Parsing Complete - Valid\n");
        printf("SYMBOL TABLE\n");
        printf("%30s %s\n", " ", "------------");
        print_symbol_table();
        printf("\n\nCONSTANT TABLE\n");
        printf("%30s %s\n", " ", "--------------");
        print_constant_table();
        printf("%30s %s\n", " ", "--------------");
        print_func_table();
    }
    fclose(fp);
}


void yyerror(char *s)
{
    puts("=========================================================================");
    printf("Parsing Failed at line no: %d\n", yylineno);
    printf("Error: %s\n", yytext);
}

void ins()
{
    insert_symbol_table_type(Match_str,Match_type);
}

void insV()
{
    insert_symbol_table_value(Match_str,curval);
} 
