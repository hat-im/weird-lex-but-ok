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
    INT = 259,
    CHAR = 260,
    FLOAT = 261,
    DOUBLE = 262,
    LONG = 263,
    SHORT = 264,
    SIGNED = 265,
    UNSIGNED = 266,
    STRUCT = 267,
    RETURN = 268,
    MAIN = 269,
    VOID = 270,
    WHILE = 271,
    FOR = 272,
    DO = 273,
    BREAK = 274,
    ENDIF = 275,
    AUTO = 276,
    SWITCH = 277,
    CASE = 278,
    ENUM = 279,
    REG = 280,
    TYPEDEF = 281,
    EXTERN = 282,
    UNION = 283,
    CONTINUE = 284,
    STATIC = 285,
    DEFAULT = 286,
    GOTO = 287,
    VOLATILE = 288,
    CONST = 289,
    IDENTIFIER = 290,
    NUM_CONSTANT = 291,
    CHAR_CONSTANT = 292,
    STRING_CONSTANT = 293,
    ELSE = 294,
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
    or = 306,
    and = 307,
    bitOr = 308,
    xor = 309,
    bitAnd = 310,
    equality = 311,
    inequality = 312,
    lessthanAssignment = 313,
    lessthan = 314,
    greaterthanAssignment = 315,
    greaterthan = 316,
    leftshift = 317,
    rightshift = 318,
    add = 319,
    subtract = 320,
    multiplication = 321,
    divide = 322,
    modulo = 323,
    SIZEOF = 324,
    negation = 325,
    not = 326,
    increment = 327,
    decrement = 328
  };
#endif
/* Tokens.  */
#define IF 258
#define INT 259
#define CHAR 260
#define FLOAT 261
#define DOUBLE 262
#define LONG 263
#define SHORT 264
#define SIGNED 265
#define UNSIGNED 266
#define STRUCT 267
#define RETURN 268
#define MAIN 269
#define VOID 270
#define WHILE 271
#define FOR 272
#define DO 273
#define BREAK 274
#define ENDIF 275
#define AUTO 276
#define SWITCH 277
#define CASE 278
#define ENUM 279
#define REG 280
#define TYPEDEF 281
#define EXTERN 282
#define UNION 283
#define CONTINUE 284
#define STATIC 285
#define DEFAULT 286
#define GOTO 287
#define VOLATILE 288
#define CONST 289
#define IDENTIFIER 290
#define NUM_CONSTANT 291
#define CHAR_CONSTANT 292
#define STRING_CONSTANT 293
#define ELSE 294
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
#define or 306
#define and 307
#define bitOr 308
#define xor 309
#define bitAnd 310
#define equality 311
#define inequality 312
#define lessthanAssignment 313
#define lessthan 314
#define greaterthanAssignment 315
#define greaterthan 316
#define leftshift 317
#define rightshift 318
#define add 319
#define subtract 320
#define multiplication 321
#define divide 322
#define modulo 323
#define SIZEOF 324
#define negation 325
#define not 326
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
