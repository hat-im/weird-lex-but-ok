/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
