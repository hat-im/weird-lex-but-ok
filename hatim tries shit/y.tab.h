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
    T_IDENTIFIER = 258,
    T_CONSTANT = 259,
    T_STRING_LITERAL = 260,
    T_SIZEOF = 261,
    T_PTR_OP = 262,
    T_INC_OP = 263,
    T_DEC_OP = 264,
    T_LEFT_OP = 265,
    T_RIGHT_OP = 266,
    T_LE_OP = 267,
    T_GE_OP = 268,
    T_EQ_OP = 269,
    T_NE_OP = 270,
    T_AND_OP = 271,
    T_OR_OP = 272,
    T_MUL_ASSIGN = 273,
    T_DIV_ASSIGN = 274,
    T_MOD_ASSIGN = 275,
    T_ADD_ASSIGN = 276,
    T_SUB_ASSIGN = 277,
    T_LEFT_ASSIGN = 278,
    T_RIGHT_ASSIGN = 279,
    T_AND_ASSIGN = 280,
    T_XOR_ASSIGN = 281,
    T_OR_ASSIGN = 282,
    T_TYPE_NAME = 283,
    T_TYPEDEF = 284,
    T_EXTERN = 285,
    T_STATIC = 286,
    T_AUTO = 287,
    T_REGISTER = 288,
    T_CHAR = 289,
    T_SHORT = 290,
    T_INT = 291,
    T_LONG = 292,
    T_SIGNED = 293,
    T_UNSIGNED = 294,
    T_FLOAT = 295,
    T_DOUBLE = 296,
    T_CONST = 297,
    T_VOLATILE = 298,
    T_VOID = 299,
    T_STRUCT = 300,
    T_UNION = 301,
    T_ENUM = 302,
    T_ELLIPSIS = 303,
    T_CASE = 304,
    T_DEFAULT = 305,
    T_IF = 306,
    T_ELSE = 307,
    T_SWITCH = 308,
    T_WHILE = 309,
    T_DO = 310,
    T_FOR = 311,
    T_GOTO = 312,
    T_CONTINUE = 313,
    T_BREAK = 314,
    T_RETURN = 315,
    T_LOWER_THAN_ELSE = 316
  };
#endif
/* Tokens.  */
#define T_IDENTIFIER 258
#define T_CONSTANT 259
#define T_STRING_LITERAL 260
#define T_SIZEOF 261
#define T_PTR_OP 262
#define T_INC_OP 263
#define T_DEC_OP 264
#define T_LEFT_OP 265
#define T_RIGHT_OP 266
#define T_LE_OP 267
#define T_GE_OP 268
#define T_EQ_OP 269
#define T_NE_OP 270
#define T_AND_OP 271
#define T_OR_OP 272
#define T_MUL_ASSIGN 273
#define T_DIV_ASSIGN 274
#define T_MOD_ASSIGN 275
#define T_ADD_ASSIGN 276
#define T_SUB_ASSIGN 277
#define T_LEFT_ASSIGN 278
#define T_RIGHT_ASSIGN 279
#define T_AND_ASSIGN 280
#define T_XOR_ASSIGN 281
#define T_OR_ASSIGN 282
#define T_TYPE_NAME 283
#define T_TYPEDEF 284
#define T_EXTERN 285
#define T_STATIC 286
#define T_AUTO 287
#define T_REGISTER 288
#define T_CHAR 289
#define T_SHORT 290
#define T_INT 291
#define T_LONG 292
#define T_SIGNED 293
#define T_UNSIGNED 294
#define T_FLOAT 295
#define T_DOUBLE 296
#define T_CONST 297
#define T_VOLATILE 298
#define T_VOID 299
#define T_STRUCT 300
#define T_UNION 301
#define T_ENUM 302
#define T_ELLIPSIS 303
#define T_CASE 304
#define T_DEFAULT 305
#define T_IF 306
#define T_ELSE 307
#define T_SWITCH 308
#define T_WHILE 309
#define T_DO 310
#define T_FOR 311
#define T_GOTO 312
#define T_CONTINUE 313
#define T_BREAK 314
#define T_RETURN 315
#define T_LOWER_THAN_ELSE 316

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
