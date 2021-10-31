/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    BREAK = 258,                   /* BREAK  */
    CASE = 259,                    /* CASE  */
    CHAR = 260,                    /* CHAR  */
    CONST = 261,                   /* CONST  */
    CONTINUE = 262,                /* CONTINUE  */
    DEFAULT = 263,                 /* DEFAULT  */
    DO = 264,                      /* DO  */
    DOUBLE = 265,                  /* DOUBLE  */
    ELSE = 266,                    /* ELSE  */
    EXTERN = 267,                  /* EXTERN  */
    FLOAT = 268,                   /* FLOAT  */
    FOR = 269,                     /* FOR  */
    GOTO = 270,                    /* GOTO  */
    IF = 271,                      /* IF  */
    INLINE = 272,                  /* INLINE  */
    INT = 273,                     /* INT  */
    LONG = 274,                    /* LONG  */
    RESTRICT = 275,                /* RESTRICT  */
    RETURN = 276,                  /* RETURN  */
    SHORT = 277,                   /* SHORT  */
    SIZEOF = 278,                  /* SIZEOF  */
    STATIC = 279,                  /* STATIC  */
    STRUCT = 280,                  /* STRUCT  */
    SWITCH = 281,                  /* SWITCH  */
    TYPEDEF = 282,                 /* TYPEDEF  */
    UNION = 283,                   /* UNION  */
    VOID = 284,                    /* VOID  */
    VOLATILE = 285,                /* VOLATILE  */
    WHILE = 286,                   /* WHILE  */
    ARROW = 287,                   /* ARROW  */
    DECREMENT = 288,               /* DECREMENT  */
    INCREMENT = 289,               /* INCREMENT  */
    RIGHT_SHIFT = 290,             /* RIGHT_SHIFT  */
    LEFT_SHIFT = 291,              /* LEFT_SHIFT  */
    GREATER_THAN_EQUAL = 292,      /* GREATER_THAN_EQUAL  */
    LESS_THAN_EQUAL = 293,         /* LESS_THAN_EQUAL  */
    NOT_EQUAL = 294,               /* NOT_EQUAL  */
    EQUALITY = 295,                /* EQUALITY  */
    OR = 296,                      /* OR  */
    AND = 297,                     /* AND  */
    ELLIPSIS = 298,                /* ELLIPSIS  */
    PLUS_EQUAL = 299,              /* PLUS_EQUAL  */
    MINUS_EQUAL = 300,             /* MINUS_EQUAL  */
    MULTIPLY_EQUAL = 301,          /* MULTIPLY_EQUAL  */
    MOD_EQUAL = 302,               /* MOD_EQUAL  */
    DIVIDE_EQUAL = 303,            /* DIVIDE_EQUAL  */
    AND_EQUAL = 304,               /* AND_EQUAL  */
    OR_EQUAL = 305,                /* OR_EQUAL  */
    XOR_EQUAL = 306,               /* XOR_EQUAL  */
    RIGHT_SHIFT_EQUAL = 307,       /* RIGHT_SHIFT_EQUAL  */
    LEFT_SHIFT_EQUAL = 308,        /* LEFT_SHIFT_EQUAL  */
    WHITESPACE = 309,              /* WHITESPACE  */
    COMMENT = 310,                 /* COMMENT  */
    INTEGER_CONSTANT = 311,        /* INTEGER_CONSTANT  */
    FLOATING_CONSTANT = 312,       /* FLOATING_CONSTANT  */
    CHAR_CONST = 313,              /* CHAR_CONST  */
    STRING_LITERAL = 314,          /* STRING_LITERAL  */
    IDENTIFIER = 315,              /* IDENTIFIER  */
    UNARY = 316,                   /* UNARY  */
    IF_CONFLICT = 317              /* IF_CONFLICT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define BREAK 258
#define CASE 259
#define CHAR 260
#define CONST 261
#define CONTINUE 262
#define DEFAULT 263
#define DO 264
#define DOUBLE 265
#define ELSE 266
#define EXTERN 267
#define FLOAT 268
#define FOR 269
#define GOTO 270
#define IF 271
#define INLINE 272
#define INT 273
#define LONG 274
#define RESTRICT 275
#define RETURN 276
#define SHORT 277
#define SIZEOF 278
#define STATIC 279
#define STRUCT 280
#define SWITCH 281
#define TYPEDEF 282
#define UNION 283
#define VOID 284
#define VOLATILE 285
#define WHILE 286
#define ARROW 287
#define DECREMENT 288
#define INCREMENT 289
#define RIGHT_SHIFT 290
#define LEFT_SHIFT 291
#define GREATER_THAN_EQUAL 292
#define LESS_THAN_EQUAL 293
#define NOT_EQUAL 294
#define EQUALITY 295
#define OR 296
#define AND 297
#define ELLIPSIS 298
#define PLUS_EQUAL 299
#define MINUS_EQUAL 300
#define MULTIPLY_EQUAL 301
#define MOD_EQUAL 302
#define DIVIDE_EQUAL 303
#define AND_EQUAL 304
#define OR_EQUAL 305
#define XOR_EQUAL 306
#define RIGHT_SHIFT_EQUAL 307
#define LEFT_SHIFT_EQUAL 308
#define WHITESPACE 309
#define COMMENT 310
#define INTEGER_CONSTANT 311
#define FLOATING_CONSTANT 312
#define CHAR_CONST 313
#define STRING_LITERAL 314
#define IDENTIFIER 315
#define UNARY 316
#define IF_CONFLICT 317

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 25 "ass6_18CS10033_18CS30036.y"

	int _int_value;   //to hold the value of integer constant
	char _char_value; //to hold the value of character constant
	float _float_value; //to hold the value of floating constant
	string* _string_literal; // to hold the value of string literal
	declarator _declarator;   //to define the declarators
	identifier _identifier;    // to define the type for Identifier
	argList _paramList; //to define the argumnets list
	int _instruction;  // to defin the type used by M->(epsilon)
	expression _expression;   // to define the structure of expression
	list *_nextlist;  //to define the _nextlist type for N->(epsilon)

#line 204 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
