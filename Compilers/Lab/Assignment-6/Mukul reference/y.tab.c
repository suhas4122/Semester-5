/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 17 "ass6_18CS10033_18CS30036.y"

	#include "ass6_18CS10033_18CS30036_translator.h"
	void yyerror(const char*);
	extern int yylex(void);
	using namespace std;

#line 78 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 268 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_BREAK = 3,                      /* BREAK  */
  YYSYMBOL_CASE = 4,                       /* CASE  */
  YYSYMBOL_CHAR = 5,                       /* CHAR  */
  YYSYMBOL_CONST = 6,                      /* CONST  */
  YYSYMBOL_CONTINUE = 7,                   /* CONTINUE  */
  YYSYMBOL_DEFAULT = 8,                    /* DEFAULT  */
  YYSYMBOL_DO = 9,                         /* DO  */
  YYSYMBOL_DOUBLE = 10,                    /* DOUBLE  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_EXTERN = 12,                    /* EXTERN  */
  YYSYMBOL_FLOAT = 13,                     /* FLOAT  */
  YYSYMBOL_FOR = 14,                       /* FOR  */
  YYSYMBOL_GOTO = 15,                      /* GOTO  */
  YYSYMBOL_IF = 16,                        /* IF  */
  YYSYMBOL_INLINE = 17,                    /* INLINE  */
  YYSYMBOL_INT = 18,                       /* INT  */
  YYSYMBOL_LONG = 19,                      /* LONG  */
  YYSYMBOL_RESTRICT = 20,                  /* RESTRICT  */
  YYSYMBOL_RETURN = 21,                    /* RETURN  */
  YYSYMBOL_SHORT = 22,                     /* SHORT  */
  YYSYMBOL_SIZEOF = 23,                    /* SIZEOF  */
  YYSYMBOL_STATIC = 24,                    /* STATIC  */
  YYSYMBOL_STRUCT = 25,                    /* STRUCT  */
  YYSYMBOL_SWITCH = 26,                    /* SWITCH  */
  YYSYMBOL_TYPEDEF = 27,                   /* TYPEDEF  */
  YYSYMBOL_UNION = 28,                     /* UNION  */
  YYSYMBOL_VOID = 29,                      /* VOID  */
  YYSYMBOL_VOLATILE = 30,                  /* VOLATILE  */
  YYSYMBOL_WHILE = 31,                     /* WHILE  */
  YYSYMBOL_ARROW = 32,                     /* ARROW  */
  YYSYMBOL_DECREMENT = 33,                 /* DECREMENT  */
  YYSYMBOL_INCREMENT = 34,                 /* INCREMENT  */
  YYSYMBOL_RIGHT_SHIFT = 35,               /* RIGHT_SHIFT  */
  YYSYMBOL_LEFT_SHIFT = 36,                /* LEFT_SHIFT  */
  YYSYMBOL_GREATER_THAN_EQUAL = 37,        /* GREATER_THAN_EQUAL  */
  YYSYMBOL_LESS_THAN_EQUAL = 38,           /* LESS_THAN_EQUAL  */
  YYSYMBOL_NOT_EQUAL = 39,                 /* NOT_EQUAL  */
  YYSYMBOL_EQUALITY = 40,                  /* EQUALITY  */
  YYSYMBOL_OR = 41,                        /* OR  */
  YYSYMBOL_AND = 42,                       /* AND  */
  YYSYMBOL_ELLIPSIS = 43,                  /* ELLIPSIS  */
  YYSYMBOL_PLUS_EQUAL = 44,                /* PLUS_EQUAL  */
  YYSYMBOL_MINUS_EQUAL = 45,               /* MINUS_EQUAL  */
  YYSYMBOL_MULTIPLY_EQUAL = 46,            /* MULTIPLY_EQUAL  */
  YYSYMBOL_MOD_EQUAL = 47,                 /* MOD_EQUAL  */
  YYSYMBOL_DIVIDE_EQUAL = 48,              /* DIVIDE_EQUAL  */
  YYSYMBOL_AND_EQUAL = 49,                 /* AND_EQUAL  */
  YYSYMBOL_OR_EQUAL = 50,                  /* OR_EQUAL  */
  YYSYMBOL_XOR_EQUAL = 51,                 /* XOR_EQUAL  */
  YYSYMBOL_RIGHT_SHIFT_EQUAL = 52,         /* RIGHT_SHIFT_EQUAL  */
  YYSYMBOL_LEFT_SHIFT_EQUAL = 53,          /* LEFT_SHIFT_EQUAL  */
  YYSYMBOL_WHITESPACE = 54,                /* WHITESPACE  */
  YYSYMBOL_COMMENT = 55,                   /* COMMENT  */
  YYSYMBOL_INTEGER_CONSTANT = 56,          /* INTEGER_CONSTANT  */
  YYSYMBOL_FLOATING_CONSTANT = 57,         /* FLOATING_CONSTANT  */
  YYSYMBOL_CHAR_CONST = 58,                /* CHAR_CONST  */
  YYSYMBOL_STRING_LITERAL = 59,            /* STRING_LITERAL  */
  YYSYMBOL_IDENTIFIER = 60,                /* IDENTIFIER  */
  YYSYMBOL_61_ = 61,                       /* '+'  */
  YYSYMBOL_62_ = 62,                       /* '-'  */
  YYSYMBOL_63_ = 63,                       /* '*'  */
  YYSYMBOL_64_ = 64,                       /* '/'  */
  YYSYMBOL_65_ = 65,                       /* '%'  */
  YYSYMBOL_UNARY = 66,                     /* UNARY  */
  YYSYMBOL_IF_CONFLICT = 67,               /* IF_CONFLICT  */
  YYSYMBOL_68_ = 68,                       /* '('  */
  YYSYMBOL_69_ = 69,                       /* ')'  */
  YYSYMBOL_70_ = 70,                       /* '['  */
  YYSYMBOL_71_ = 71,                       /* ']'  */
  YYSYMBOL_72_ = 72,                       /* '.'  */
  YYSYMBOL_73_ = 73,                       /* '{'  */
  YYSYMBOL_74_ = 74,                       /* '}'  */
  YYSYMBOL_75_ = 75,                       /* ','  */
  YYSYMBOL_76_ = 76,                       /* '&'  */
  YYSYMBOL_77_ = 77,                       /* '~'  */
  YYSYMBOL_78_ = 78,                       /* '!'  */
  YYSYMBOL_79_ = 79,                       /* '<'  */
  YYSYMBOL_80_ = 80,                       /* '>'  */
  YYSYMBOL_81_ = 81,                       /* '^'  */
  YYSYMBOL_82_ = 82,                       /* '|'  */
  YYSYMBOL_83_ = 83,                       /* '?'  */
  YYSYMBOL_84_ = 84,                       /* ':'  */
  YYSYMBOL_85_ = 85,                       /* '='  */
  YYSYMBOL_86_ = 86,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 87,                  /* $accept  */
  YYSYMBOL_M = 88,                         /* M  */
  YYSYMBOL_N = 89,                         /* N  */
  YYSYMBOL_primary_expression = 90,        /* primary_expression  */
  YYSYMBOL_postfix_expression = 91,        /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 92,  /* argument_expression_list  */
  YYSYMBOL_argument_expression_list_opt = 93, /* argument_expression_list_opt  */
  YYSYMBOL_unary_expression = 94,          /* unary_expression  */
  YYSYMBOL_unary_operator = 95,            /* unary_operator  */
  YYSYMBOL_cast_expression = 96,           /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 97, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 98,       /* additive_expression  */
  YYSYMBOL_shift_expression = 99,          /* shift_expression  */
  YYSYMBOL_relational_expression = 100,    /* relational_expression  */
  YYSYMBOL_equality_expression = 101,      /* equality_expression  */
  YYSYMBOL_AND_expression = 102,           /* AND_expression  */
  YYSYMBOL_exclusive_OR_expression = 103,  /* exclusive_OR_expression  */
  YYSYMBOL_inclusive_OR_expression = 104,  /* inclusive_OR_expression  */
  YYSYMBOL_logical_AND_expression = 105,   /* logical_AND_expression  */
  YYSYMBOL_logical_OR_expression = 106,    /* logical_OR_expression  */
  YYSYMBOL_conditional_expression = 107,   /* conditional_expression  */
  YYSYMBOL_assignment_operator = 108,      /* assignment_operator  */
  YYSYMBOL_assignment_expression = 109,    /* assignment_expression  */
  YYSYMBOL_constant_expression = 110,      /* constant_expression  */
  YYSYMBOL_expression = 111,               /* expression  */
  YYSYMBOL_declaration = 112,              /* declaration  */
  YYSYMBOL_init_declarator_list_opt = 113, /* init_declarator_list_opt  */
  YYSYMBOL_declaration_specifiers = 114,   /* declaration_specifiers  */
  YYSYMBOL_declaration_specifiers_opt = 115, /* declaration_specifiers_opt  */
  YYSYMBOL_init_declarator_list = 116,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 117,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 118,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 119,           /* type_specifier  */
  YYSYMBOL_specifier_qualifier_list = 120, /* specifier_qualifier_list  */
  YYSYMBOL_specifier_qualifier_list_opt = 121, /* specifier_qualifier_list_opt  */
  YYSYMBOL_type_qualifier = 122,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 123,       /* function_specifier  */
  YYSYMBOL_declarator = 124,               /* declarator  */
  YYSYMBOL_pointer_opt = 125,              /* pointer_opt  */
  YYSYMBOL_direct_declarator = 126,        /* direct_declarator  */
  YYSYMBOL_type_qualifier_list_opt = 127,  /* type_qualifier_list_opt  */
  YYSYMBOL_assignment_expression_opt = 128, /* assignment_expression_opt  */
  YYSYMBOL_identifier_list_opt = 129,      /* identifier_list_opt  */
  YYSYMBOL_pointer = 130,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 131,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 132,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 133,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 134,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 135,          /* identifier_list  */
  YYSYMBOL_type_name = 136,                /* type_name  */
  YYSYMBOL_initializer = 137,              /* initializer  */
  YYSYMBOL_initializer_list = 138,         /* initializer_list  */
  YYSYMBOL_designation_opt = 139,          /* designation_opt  */
  YYSYMBOL_designation = 140,              /* designation  */
  YYSYMBOL_designator_list = 141,          /* designator_list  */
  YYSYMBOL_designator = 142,               /* designator  */
  YYSYMBOL_statement = 143,                /* statement  */
  YYSYMBOL_labeled_statement = 144,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 145,       /* compound_statement  */
  YYSYMBOL_block_item_list_opt = 146,      /* block_item_list_opt  */
  YYSYMBOL_block_item_list = 147,          /* block_item_list  */
  YYSYMBOL_block_item = 148,               /* block_item  */
  YYSYMBOL_expression_statement = 149,     /* expression_statement  */
  YYSYMBOL_expression_opt = 150,           /* expression_opt  */
  YYSYMBOL_selection_statement = 151,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 152,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 153,           /* jump_statement  */
  YYSYMBOL_translation_unit = 154,         /* translation_unit  */
  YYSYMBOL_external_declaration = 155,     /* external_declaration  */
  YYSYMBOL_function_definition = 156,      /* function_definition  */
  YYSYMBOL_declaration_list_opt = 157,     /* declaration_list_opt  */
  YYSYMBOL_declaration_list = 158          /* declaration_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  35
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   926

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  72
/* YYNRULES -- Number of rules.  */
#define YYNRULES  193
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  339

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   317


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    78,     2,     2,     2,    65,    76,     2,
      68,    69,    63,    61,    75,    62,    72,    64,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    84,    86,
      79,    85,    80,    83,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    70,     2,    71,    81,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    73,    82,    74,    77,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    66,    67
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   130,   130,   135,   141,   273,   317,   361,   394,   427,
     431,   434,   482,   618,   619,   622,   690,   758,   761,   765,
     795,   800,   803,   820,   823,   880,   959,  1083,  1084,  1086,
    1089,  1092,  1095,  1098,  1101,  1105,  1174,  1178,  1181,  1211,
    1230,  1261,  1264,  1294,  1325,  1328,  1346,  1374,  1377,  1420,
    1441,  1473,  1506,  1509,  1541,  1574,  1577,  1607,  1610,  1629,
    1632,  1651,  1654,  1678,  1681,  1706,  1709,  1739,  1740,  1741,
    1742,  1743,  1744,  1745,  1746,  1747,  1748,  1749,  1751,  1754,
    1816,  1820,  1823,  1829,  1850,  1869,  1873,  1874,  1875,  1876,
    1878,  1878,  1881,  1898,  1900,  1920,  1991,  1992,  1994,  1997,
    2000,  2001,  2004,  2005,  2006,  2010,  2013,  2015,  2016,  2019,
    2020,  2021,  2023,  2025,  2109,  2112,  2116,  2167,  2170,  2232,
    2233,  2234,  2235,  2482,  2661,  2662,  2664,  2667,  2684,  2684,
    2687,  2690,  2694,  2695,  2697,  2700,  2702,  2706,  2711,  2714,
    2716,  2717,  2719,  2721,  2724,  2725,  2727,  2728,  2730,  2730,
    2733,  2735,  2736,  2738,  2739,  2742,  2743,  2746,  2749,  2752,
    2755,  2772,  2773,  2774,  2776,  2780,  2783,  2800,  2803,  2808,
    2811,  2815,  2819,  2822,  2827,  2863,  2885,  2887,  2920,  2941,
    2975,  2977,  2978,  2979,  2980,  3009,  3010,  3012,  3013,  3085,
    3135,  3135,  3138,  3139
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "BREAK", "CASE",
  "CHAR", "CONST", "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", "EXTERN",
  "FLOAT", "FOR", "GOTO", "IF", "INLINE", "INT", "LONG", "RESTRICT",
  "RETURN", "SHORT", "SIZEOF", "STATIC", "STRUCT", "SWITCH", "TYPEDEF",
  "UNION", "VOID", "VOLATILE", "WHILE", "ARROW", "DECREMENT", "INCREMENT",
  "RIGHT_SHIFT", "LEFT_SHIFT", "GREATER_THAN_EQUAL", "LESS_THAN_EQUAL",
  "NOT_EQUAL", "EQUALITY", "OR", "AND", "ELLIPSIS", "PLUS_EQUAL",
  "MINUS_EQUAL", "MULTIPLY_EQUAL", "MOD_EQUAL", "DIVIDE_EQUAL",
  "AND_EQUAL", "OR_EQUAL", "XOR_EQUAL", "RIGHT_SHIFT_EQUAL",
  "LEFT_SHIFT_EQUAL", "WHITESPACE", "COMMENT", "INTEGER_CONSTANT",
  "FLOATING_CONSTANT", "CHAR_CONST", "STRING_LITERAL", "IDENTIFIER", "'+'",
  "'-'", "'*'", "'/'", "'%'", "UNARY", "IF_CONFLICT", "'('", "')'", "'['",
  "']'", "'.'", "'{'", "'}'", "','", "'&'", "'~'", "'!'", "'<'", "'>'",
  "'^'", "'|'", "'?'", "':'", "'='", "';'", "$accept", "M", "N",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "argument_expression_list_opt", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "AND_expression", "exclusive_OR_expression", "inclusive_OR_expression",
  "logical_AND_expression", "logical_OR_expression",
  "conditional_expression", "assignment_operator", "assignment_expression",
  "constant_expression", "expression", "declaration",
  "init_declarator_list_opt", "declaration_specifiers",
  "declaration_specifiers_opt", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "specifier_qualifier_list",
  "specifier_qualifier_list_opt", "type_qualifier", "function_specifier",
  "declarator", "pointer_opt", "direct_declarator",
  "type_qualifier_list_opt", "assignment_expression_opt",
  "identifier_list_opt", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "type_name", "initializer", "initializer_list",
  "designation_opt", "designation", "designator_list", "designator",
  "statement", "labeled_statement", "compound_statement",
  "block_item_list_opt", "block_item_list", "block_item",
  "expression_statement", "expression_opt", "selection_statement",
  "iteration_statement", "jump_statement", "translation_unit",
  "external_declaration", "function_definition", "declaration_list_opt",
  "declaration_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
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
     315,    43,    45,    42,    47,    37,   316,   317,    40,    41,
      91,    93,    46,   123,   125,    44,    38,   126,    33,    60,
      62,    94,   124,    63,    58,    61,    59
};
#endif

#define YYPACT_NINF (-192)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-192)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     896,  -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,
    -192,  -192,  -192,  -192,  -192,   -45,   896,   896,   896,   896,
     875,  -192,  -192,   130,   -74,   -58,  -192,   335,   -22,  -192,
    -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,   -16,   130,
    -192,   -16,   602,  -192,   -45,   -20,   896,  -192,   -16,    -5,
    -192,  -192,  -192,   -17,   664,   695,   695,  -192,  -192,  -192,
    -192,  -192,  -192,  -192,  -192,   571,     5,  -192,  -192,  -192,
    -192,    -6,   254,   726,  -192,    94,    55,   119,   -24,   141,
      -4,    16,    21,    18,   -25,  -192,  -192,  -192,   260,  -192,
    -192,    44,   826,     9,   571,  -192,   571,  -192,  -192,  -192,
     -27,   387,  -192,   387,    63,   726,    82,   111,   602,  -192,
     -11,  -192,    86,  -192,  -192,   726,   726,    88,  -192,  -192,
    -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,   726,
    -192,  -192,   726,   726,   726,   726,   726,   726,   726,   726,
     726,   726,   726,   726,   726,   726,   726,   726,  -192,  -192,
      69,    85,   726,    91,    77,  -192,   114,   128,   133,   726,
     134,   135,   120,   137,  -192,  -192,  -192,  -192,   136,   145,
    -192,  -192,   122,  -192,  -192,  -192,  -192,  -192,   -32,   140,
     153,   148,  -192,   149,   130,   757,   109,   157,   158,  -192,
     726,  -192,  -192,  -192,   633,  -192,   159,  -192,  -192,    51,
    -192,  -192,  -192,  -192,   156,   164,  -192,   -26,  -192,  -192,
    -192,  -192,  -192,    94,    94,    55,    55,   119,   119,   119,
     119,   -24,   -24,   141,    -4,    16,   726,   726,  -192,  -192,
     144,  -192,   441,   441,   510,   151,   726,   152,   726,  -192,
     441,  -192,   365,  -192,  -192,  -192,  -192,   847,   174,   726,
     165,  -192,   168,   726,   162,   162,  -192,     5,  -192,  -192,
    -192,   602,   726,  -192,  -192,    21,    18,   726,   441,  -192,
     209,   726,   155,  -192,   137,  -192,    25,   726,  -192,  -192,
    -192,  -192,  -192,   172,  -192,  -192,   176,   118,  -192,  -192,
     137,  -192,   177,   166,  -192,   181,   441,   137,  -192,  -192,
    -192,    75,   169,  -192,   726,   726,  -192,  -192,   187,  -192,
    -192,   726,   188,  -192,   441,  -192,   726,   137,   441,   173,
     247,   441,  -192,   191,  -192,  -192,   250,  -192,   185,   726,
    -192,  -192,  -192,   441,   216,  -192,  -192,   441,  -192
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    99,   109,   104,    96,   103,   112,   101,   102,   110,
     100,    97,    98,   111,   188,   115,    91,    91,    91,    91,
       0,   185,   187,   125,     0,    84,    92,    94,     0,   114,
      90,    86,    87,    88,    89,     1,   186,   132,   130,   124,
      83,   115,     0,   192,   115,     0,   190,   116,   115,   113,
     131,   133,    93,    94,     0,     0,     0,     5,     6,     7,
       8,     4,    31,    32,    30,     0,   149,    29,    33,    34,
      10,    23,    35,     0,    37,    41,    44,    47,    52,    55,
      57,    59,    61,    63,    65,    78,   143,    95,   166,   189,
     193,     0,   129,   125,     0,    27,     0,    25,    24,    81,
       0,   108,   142,   108,     0,     0,     0,     0,     0,   148,
       0,   151,     0,    16,    15,    22,     0,     0,    71,    72,
      68,    70,    69,    75,    77,    76,    74,    73,    67,     0,
      35,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     2,
       0,     0,     0,     0,     0,     2,     0,     0,     0,   173,
       0,     0,     4,   172,   169,   170,   155,   156,     0,     2,
     167,   157,     0,   158,   159,   160,   117,   140,   115,     0,
       0,   134,   136,   128,   125,   127,   124,     0,     0,     9,
       0,   107,   105,   106,     0,    80,     0,   154,   144,   149,
     146,   150,   152,    14,    21,     0,    19,     0,    13,    79,
      38,    39,    40,    42,    43,    46,    45,    51,    50,    48,
      49,    54,    53,    56,    58,    60,     0,     0,     2,   183,
       0,   182,   173,   173,   173,     0,     0,     0,     0,     2,
     173,   164,   173,   171,   138,   123,   122,     0,     0,     0,
      30,   126,     0,     0,    28,     0,    82,   149,    36,   153,
     145,     0,     0,    12,    11,    62,    64,     0,   173,   163,
       0,   173,     0,   181,     3,   184,     0,     0,   161,   168,
     135,   137,   141,     0,   121,   118,     0,     0,   147,    20,
       3,   162,     0,     0,     2,     0,   173,     3,   119,   120,
      17,   149,     0,     2,   173,   173,     2,   176,     0,    18,
       2,     0,     0,     3,   173,     2,     0,     3,   173,     0,
     175,   173,    66,     0,   180,     2,     0,   177,     0,   173,
       2,   178,     3,   173,     0,   174,     2,   173,   179
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -192,  -119,  -179,  -192,  -192,  -192,  -192,   -54,  -192,   -63,
      59,    60,    24,    56,   142,   146,   161,    62,    68,  -192,
    -100,  -192,    -7,   160,   -62,   -21,  -192,     4,   150,  -192,
     255,  -192,    11,     3,   194,    34,  -192,    -8,  -192,  -192,
     -82,  -192,  -192,   271,   217,  -192,  -192,    64,  -192,    30,
     -99,    57,  -191,  -192,  -192,   203,   -89,  -192,   270,  -192,
    -192,    83,  -192,  -115,  -192,  -192,  -192,  -192,   304,  -192,
    -192,  -192
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,   226,   150,    70,    71,   204,   205,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,   129,    99,   196,   163,    14,    24,    44,    31,    25,
      26,    16,    17,   102,   192,    18,    19,    53,    28,    49,
      38,   252,   179,    29,    39,   180,   181,   182,   183,   104,
      87,   107,   108,   109,   110,   111,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,    20,    21,    22,
      45,    46
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      95,    97,    98,   100,    15,   195,    43,    27,   261,   200,
     131,   185,    40,   139,   140,     2,   149,    41,    23,   130,
      30,    30,    30,    30,    15,    90,   112,   113,   114,     9,
     227,    23,   100,   184,   100,    86,   233,  -139,    47,    13,
      91,   -85,   189,  -139,   237,   264,    48,    23,   190,   190,
     242,   130,   195,    88,   207,   141,   142,    37,    -3,   105,
     148,   106,   115,    92,   116,    93,   117,   164,    42,   210,
     211,   212,   145,    51,   201,   105,   101,   106,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   296,   295,   178,   146,   130,   103,
     190,    86,   249,   147,   191,   101,   191,   101,   206,   267,
     261,   302,   101,   176,   101,     2,   135,   136,   308,   272,
     277,   105,   209,   106,   187,   260,   188,    37,   103,     9,
     103,   258,   194,   253,   319,   103,     2,   103,   323,    13,
     130,   326,   197,   269,   270,   105,   203,   106,   208,   309,
       9,   278,   228,   334,   137,   138,   293,   132,   133,   134,
      13,   232,   288,   217,   218,   219,   220,    32,    33,    34,
     244,   229,   130,   130,   274,   305,   276,   231,   251,   291,
     143,   144,   234,   256,   311,   198,   199,   314,   235,   312,
     313,   316,   300,   301,   213,   214,   321,   215,   216,   221,
     222,   236,   238,   239,   240,   290,   329,   307,   243,   245,
     241,   333,   190,   271,   332,   297,   322,   337,    37,  -165,
      51,   164,   246,   247,   248,   320,   254,   255,   268,   324,
     259,   262,   327,   263,   282,   257,   284,   273,   275,   285,
     292,   294,   283,   298,   335,   303,   286,   299,   338,   317,
     306,   178,   304,   310,    86,   289,   315,   318,    -3,   325,
     328,   330,   130,   151,   152,     1,     2,   153,   154,   155,
       3,   331,     4,     5,   156,   157,   158,     6,     7,     8,
       9,   159,    10,    54,    11,   336,   160,   223,   265,    12,
      13,   161,   224,    55,    56,   266,    52,   193,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   225,    50,
     186,   281,   230,   202,   287,    89,    57,    58,    59,    60,
     162,    62,    63,    64,    36,   279,     0,     0,    65,     0,
       0,     0,     0,    88,     0,     0,    67,    68,    69,   128,
       1,     2,     0,     0,     0,     3,  -173,     4,     5,     0,
       0,     0,     6,     7,     8,     9,     0,    10,     0,    11,
       0,     0,     0,     0,    12,    13,     0,     0,   151,   152,
       1,     2,   153,   154,   155,     3,     0,     4,     5,   156,
     157,   158,     6,     7,     8,     9,   159,    10,    54,    11,
       0,   160,     1,     2,    12,    13,   161,     3,    55,    56,
       5,     0,     0,     0,     0,     7,     8,     9,  -191,    10,
       0,     0,     0,     0,     0,     0,    12,    13,     0,     0,
      42,    57,    58,    59,    60,   162,    62,    63,    64,     0,
       0,     0,     0,    65,     0,     0,     0,     0,    88,     0,
       0,    67,    68,    69,   151,   152,     0,     0,   153,   154,
     155,     0,     0,     0,     0,   156,   157,   158,     0,     0,
       0,     0,   159,     0,    54,     0,     0,   160,     0,     0,
       0,     0,   161,     0,    55,    56,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    57,    58,    59,
      60,   162,    62,    63,    64,     0,     0,     0,     0,    65,
       0,     0,     0,     0,    88,     1,     2,    67,    68,    69,
       3,     0,     4,     5,     0,     0,     0,     6,     7,     8,
       9,     0,    10,    54,    11,     0,     0,     0,     0,    12,
      13,     0,     0,    55,    56,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    57,    58,    59,    60,
      61,    62,    63,    64,     0,     0,     1,     2,    65,     0,
       0,     3,     0,     0,     5,     0,    67,    68,    69,     7,
       8,     9,     0,    10,    54,     0,     0,     0,     0,     0,
      12,    13,     0,     0,    55,    56,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    54,     0,    57,    58,    59,
      60,    61,    62,    63,    64,    55,    56,     0,     0,    65,
       0,     0,     0,     0,     0,     0,     0,    67,    68,    69,
       0,     0,     0,     0,     0,     0,    54,     0,    57,    58,
      59,    60,    61,    62,    63,    64,    55,    56,     0,     0,
      65,     0,     0,     0,     0,    66,     0,     0,    67,    68,
      69,     0,     0,     0,     0,     0,     0,    54,     0,    57,
      58,    59,    60,    61,    62,    63,    64,    55,    56,     0,
       0,    65,     0,     0,     0,     0,   257,     0,     0,    67,
      68,    69,     0,     0,     0,     0,     0,     0,    54,     0,
      57,    58,    59,    60,    61,    62,    63,    64,    55,    56,
       0,     0,    94,     0,     0,     0,     0,     0,     0,     0,
      67,    68,    69,     0,     0,     0,     0,     0,     0,    54,
       0,    57,    58,    59,    60,    61,    62,    63,    64,    55,
      56,     0,     0,    96,     0,     0,     0,     0,     0,     0,
       0,    67,    68,    69,     0,     0,     0,     0,     0,     0,
      54,     0,    57,    58,    59,    60,    61,    62,    63,    64,
      55,    56,     0,     0,    65,     0,     0,     0,     0,     0,
       0,     0,    67,    68,    69,     0,     0,     0,     0,     0,
       0,     0,     0,    57,    58,    59,    60,    61,    62,    63,
     250,     0,     0,     0,     0,    65,     0,     0,     0,     0,
       0,     1,     2,    67,    68,    69,     3,     0,     4,     5,
       0,     0,     0,     6,     7,     8,     9,     0,    10,     0,
      11,     0,     1,     2,     0,    12,    13,     3,     0,     4,
       5,     0,     0,     0,     6,     7,     8,     9,     0,    10,
       0,    11,     0,     0,     0,    35,    12,    13,     0,     0,
       1,     2,     0,     0,     0,     3,   177,     4,     5,     0,
     280,     0,     6,     7,     8,     9,     0,    10,     0,    11,
       0,     1,     2,     0,    12,    13,     3,     0,     4,     5,
       0,     0,     0,     6,     7,     8,     9,     0,    10,     0,
      11,     0,     0,     0,     0,    12,    13
};

static const yytype_int16 yycheck[] =
{
      54,    55,    56,    65,     0,   105,    27,    15,   199,   108,
      73,    93,    86,    37,    38,     6,    41,    75,    63,    73,
      16,    17,    18,    19,    20,    46,    32,    33,    34,    20,
     149,    63,    94,    24,    96,    42,   155,    69,    60,    30,
      48,    86,    69,    75,   159,    71,    68,    63,    75,    75,
     169,   105,   152,    73,   116,    79,    80,    23,    83,    70,
      42,    72,    68,    68,    70,    70,    72,    88,    85,   132,
     133,   134,    76,    39,    85,    70,    65,    72,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,    69,   274,    92,    81,   152,    65,
      75,   108,   184,    82,   101,    94,   103,    96,   115,   228,
     301,   290,   101,    69,   103,     6,    61,    62,   297,   234,
     239,    70,   129,    72,    94,    74,    96,    93,    94,    20,
      96,   194,    69,    24,   313,   101,     6,   103,   317,    30,
     194,   320,    60,   232,   233,    70,    60,    72,    60,    74,
      20,   240,    83,   332,    35,    36,   271,    63,    64,    65,
      30,    84,   261,   139,   140,   141,   142,    17,    18,    19,
     178,    86,   226,   227,   236,   294,   238,    86,   185,   268,
      39,    40,    68,   190,   303,    74,    75,   306,    60,   304,
     305,   310,    74,    75,   135,   136,   315,   137,   138,   143,
     144,    68,    68,    68,    84,   267,   325,   296,    86,    69,
      74,   330,    75,   234,   329,   277,   316,   336,   184,    74,
     186,   242,    69,    75,    75,   314,    69,    69,    84,   318,
      71,    75,   321,    69,    60,    73,    71,    86,    86,    71,
      31,    86,   249,    71,   333,    68,   253,    71,   337,   311,
      69,   247,    86,    84,   261,   262,    69,    69,    11,    86,
      69,    11,   316,     3,     4,     5,     6,     7,     8,     9,
      10,    86,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    69,    26,   145,   226,    29,
      30,    31,   146,    33,    34,   227,    41,   103,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,   147,    38,
      93,   247,   152,   110,   257,    45,    56,    57,    58,    59,
      60,    61,    62,    63,    20,   242,    -1,    -1,    68,    -1,
      -1,    -1,    -1,    73,    -1,    -1,    76,    77,    78,    85,
       5,     6,    -1,    -1,    -1,    10,    86,    12,    13,    -1,
      -1,    -1,    17,    18,    19,    20,    -1,    22,    -1,    24,
      -1,    -1,    -1,    -1,    29,    30,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    26,     5,     6,    29,    30,    31,    10,    33,    34,
      13,    -1,    -1,    -1,    -1,    18,    19,    20,    73,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,
      85,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    73,    -1,
      -1,    76,    77,    78,     3,     4,    -1,    -1,     7,     8,
       9,    -1,    -1,    -1,    -1,    14,    15,    16,    -1,    -1,
      -1,    -1,    21,    -1,    23,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    31,    -1,    33,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    73,     5,     6,    76,    77,    78,
      10,    -1,    12,    13,    -1,    -1,    -1,    17,    18,    19,
      20,    -1,    22,    23,    24,    -1,    -1,    -1,    -1,    29,
      30,    -1,    -1,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,     5,     6,    68,    -1,
      -1,    10,    -1,    -1,    13,    -1,    76,    77,    78,    18,
      19,    20,    -1,    22,    23,    -1,    -1,    -1,    -1,    -1,
      29,    30,    -1,    -1,    33,    34,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    33,    34,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    33,    34,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    73,    -1,    -1,    76,    77,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    33,    34,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    73,    -1,    -1,    76,
      77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    33,    34,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    33,
      34,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      33,    34,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    77,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,     5,     6,    76,    77,    78,    10,    -1,    12,    13,
      -1,    -1,    -1,    17,    18,    19,    20,    -1,    22,    -1,
      24,    -1,     5,     6,    -1,    29,    30,    10,    -1,    12,
      13,    -1,    -1,    -1,    17,    18,    19,    20,    -1,    22,
      -1,    24,    -1,    -1,    -1,     0,    29,    30,    -1,    -1,
       5,     6,    -1,    -1,    -1,    10,    60,    12,    13,    -1,
      43,    -1,    17,    18,    19,    20,    -1,    22,    -1,    24,
      -1,     5,     6,    -1,    29,    30,    10,    -1,    12,    13,
      -1,    -1,    -1,    17,    18,    19,    20,    -1,    22,    -1,
      24,    -1,    -1,    -1,    -1,    29,    30
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,    10,    12,    13,    17,    18,    19,    20,
      22,    24,    29,    30,   112,   114,   118,   119,   122,   123,
     154,   155,   156,    63,   113,   116,   117,   124,   125,   130,
     114,   115,   115,   115,   115,     0,   155,   122,   127,   131,
      86,    75,    85,   112,   114,   157,   158,    60,    68,   126,
     130,   122,   117,   124,    23,    33,    34,    56,    57,    58,
      59,    60,    61,    62,    63,    68,    73,    76,    77,    78,
      90,    91,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   109,   137,    73,   145,
     112,   124,    68,    70,    68,    94,    68,    94,    94,   109,
     111,   119,   120,   122,   136,    70,    72,   138,   139,   140,
     141,   142,    32,    33,    34,    68,    70,    72,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    85,   108,
      94,    96,    63,    64,    65,    61,    62,    35,    36,    37,
      38,    79,    80,    39,    40,    76,    81,    82,    42,    41,
      89,     3,     4,     7,     8,     9,    14,    15,    16,    21,
      26,    31,    60,   111,   112,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,    69,    60,   114,   129,
     132,   133,   134,   135,    24,   127,   131,   136,   136,    69,
      75,   120,   121,   121,    69,   107,   110,    60,    74,    75,
     137,    85,   142,    60,    92,    93,   109,   111,    60,   109,
      96,    96,    96,    97,    97,    98,    98,    99,    99,    99,
      99,   100,   100,   101,   102,   103,    88,    88,    83,    86,
     110,    86,    84,    88,    68,    60,    68,   150,    68,    68,
      84,    74,    88,    86,   124,    69,    69,    75,    75,   127,
      63,   109,   128,    24,    69,    69,   109,    73,    96,    71,
      74,   139,    75,    69,    71,   104,   105,    88,    84,   143,
     143,   112,   150,    86,   111,    86,   111,    88,   143,   148,
      43,   134,    60,   109,    71,    71,   109,   138,   137,   109,
     111,   143,    31,   150,    86,    89,    69,   111,    71,    71,
      74,    75,    89,    68,    86,    88,    69,   143,    89,    74,
      84,    88,   150,   150,    88,    69,    88,   111,    69,    89,
     143,    88,   107,    89,   143,    86,    89,   143,    69,    88,
      11,    86,   150,    88,    89,   143,    69,    88,   143
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    87,    88,    89,    90,    90,    90,    90,    90,    90,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    92,
      92,    93,    93,    94,    94,    94,    94,    94,    94,    95,
      95,    95,    95,    95,    95,    96,    96,    97,    97,    97,
      97,    98,    98,    98,    99,    99,    99,   100,   100,   100,
     100,   100,   101,   101,   101,   102,   102,   103,   103,   104,
     104,   105,   105,   106,   106,   107,   107,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   109,   109,
     110,   111,   111,   112,   113,   113,   114,   114,   114,   114,
     115,   115,   116,   116,   117,   117,   118,   118,   119,   119,
     119,   119,   119,   119,   119,   120,   120,   121,   121,   122,
     122,   122,   123,   124,   125,   125,   126,   126,   126,   126,
     126,   126,   126,   126,   127,   127,   128,   128,   129,   129,
     130,   130,   131,   131,   132,   132,   133,   133,   134,   134,
     135,   135,   136,   137,   137,   137,   138,   138,   139,   139,
     140,   141,   141,   142,   142,   143,   143,   143,   143,   143,
     143,   144,   144,   144,   145,   146,   146,   147,   147,   148,
     148,   149,   150,   150,   151,   151,   151,   152,   152,   152,
     152,   153,   153,   153,   153,   154,   154,   155,   155,   156,
     157,   157,   158,   158
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     1,     1,     1,     1,     1,     3,
       1,     4,     4,     3,     3,     2,     2,     6,     7,     1,
       3,     1,     0,     1,     2,     2,     2,     2,     4,     1,
       1,     1,     1,     1,     1,     1,     4,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     4,     1,     4,     1,     9,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     3,     3,     1,     0,     2,     2,     2,     2,
       1,     0,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     1,     0,     1,
       1,     1,     1,     2,     1,     0,     1,     3,     5,     6,
       6,     5,     4,     4,     1,     0,     1,     0,     1,     0,
       2,     3,     1,     2,     1,     3,     1,     3,     2,     1,
       1,     3,     1,     1,     3,     4,     2,     4,     1,     0,
       2,     1,     2,     3,     2,     1,     1,     1,     1,     1,
       1,     3,     4,     3,     3,     1,     0,     1,     3,     1,
       1,     2,     1,     0,    11,     7,     5,     8,    10,    14,
       8,     3,     2,     2,     3,     1,     2,     1,     1,     4,
       1,     0,     1,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

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
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* M: %empty  */
#line 130 "ass6_18CS10033_18CS30036.y"
{
	(yyval._instruction) = nextInstruction;
}
#line 1802 "y.tab.c"
    break;

  case 3: /* N: %empty  */
#line 135 "ass6_18CS10033_18CS30036.y"
{
	(yyval._nextlist) = makelist(nextInstruction);
	globalQuadArray.emit(Q_GOTO, -1);
}
#line 1811 "y.tab.c"
    break;

  case 4: /* primary_expression: IDENTIFIER  */
#line 141 "ass6_18CS10033_18CS30036.y"
                                           {
												//Check whether its a function
												symbol * check_func = globalSymbolTable->search(*(yyvsp[0]._identifier).name);
												int l = 0;
												int k = 2;
												for(int i=0;i<10;++i) {
													int l = 0;
												}
												if(k) {
													for(int i=0;i<10;++i) {
														int k;
													}
												}
												else{
													int o;
												}
												if(check_func == NULL)
												{
													(yyval._expression).symTPtr  =  currentSymbolTable->globalLookup(*(yyvsp[0]._identifier).name);
													int l = 0;
													int k = 2;
													for(int i=0;i<10;++i) {
														int l = 0;
													}
													if(k) {
														for(int i=0;i<10;++i) {
															int k;
														}
													}
													else{
														int o;
													}
													if((yyval._expression).symTPtr->type != NULL && (yyval._expression).symTPtr->type->type == tp_arr)
													{
														//If array
														(yyval._expression).arr = (yyval._expression).symTPtr;
														(yyval._expression).symTPtr = currentSymbolTable->gentemp(new symbolType(tp_int));
														(yyval._expression).symTPtr->_init_val._INT_INITVAL = 0;
														int l = 0;
														int k = 2;
														for(int i=0;i<10;++i) {
															int l = 0;
														}
														if(k) {
															for(int i=0;i<10;++i) {
																int k;
															}
														}
														else{
															int o;
														}
														(yyval._expression).symTPtr->isInitialized = true;
														globalQuadArray.emit(Q_ASSIGN,0,(yyval._expression).symTPtr->name);
														(yyval._expression).type = (yyval._expression).arr->type;
														for(int l=0;l<10;++l) {
															int pp = 0;
														}
														if(1) {
															for(int m=0;m<10;++m) {
																int k;
															}
														}
														else{
															int n;
														}
														(yyval._expression).poss_array = (yyval._expression).arr;
													}
													else
													{
														// If not an array
														(yyval._expression).type = (yyval._expression).symTPtr->type;
														(yyval._expression).arr = NULL;
														int l = 0;
														int k = 2;
														for(int i=0;i<10;++i) {
															int l = 0;
														}
														if(k) {
															for(int i=0;i<10;++i) {
																int k;
															}
														}
														else{
															int o;
														}
														(yyval._expression).isPointer = false;
														for(int l=0;l<10;++l) {
															int pp = 0;
														}
														if(1) {
															for(int m=0;m<10;++m) {
																int k;
															}
														}
														else{
															int n;
														}
													}
												}
												else
												{
													// It is a function
													(yyval._expression).symTPtr = check_func;
													(yyval._expression).type = check_func->type;
													int l = 0;
													int k = 2;
													for(int i=0;i<10;++i) {
														int l = 0;
													}
													if(k) {
														for(int i=0;i<10;++i) {
															int k;
														}
													}
													else{
														int o;
													}
													(yyval._expression).arr = NULL;
													(yyval._expression).isPointer = false;
													for(int l=0;l<10;++l) {
															int pp = 0;
														}
														if(1) {
															for(int m=0;m<10;++m) {
																int k;
															}
														}
														else{
															int n;
														}
												}
											}
#line 1948 "y.tab.c"
    break;

  case 5: /* primary_expression: INTEGER_CONSTANT  */
#line 273 "ass6_18CS10033_18CS30036.y"
                                                                                 {
													// Declare and initialize the value of the temporary variable with the integer
													(yyval._expression).symTPtr  = currentSymbolTable->gentemp(new symbolType(tp_int));
													(yyval._expression).type = (yyval._expression).symTPtr->type;
													for(int l=0;l<10;++l) {
														int pp = 0;
													}
													if(1) {
														for(int m=0;m<10;++m) {
															int k;
														}
													}
													else{
														int n;
													}
													(yyval._expression).symTPtr->_init_val._INT_INITVAL = (yyvsp[0]._int_value);
													int l = 0;
													int k = 2;
													for(int i=0;i<10;++i) {
														int l = 0;
													}
													if(k) {
														for(int i=0;i<10;++i) {
															int k;
														}
													}
													else{
														int o;
													}
													(yyval._expression).symTPtr->isInitialized = true;
													(yyval._expression).arr = NULL;
													for(int l=0;l<10;++l) {
														int pp = 0;
													}
													if(1) {
														for(int m=0;m<10;++m) {
															int k;
														}
													}
													else{
														int n;
													}
													globalQuadArray.emit(Q_ASSIGN, (yyvsp[0]._int_value), (yyval._expression).symTPtr->name);
												}
#line 1997 "y.tab.c"
    break;

  case 6: /* primary_expression: FLOATING_CONSTANT  */
#line 317 "ass6_18CS10033_18CS30036.y"
                                                                                  {
													// Declare and initialize the value of the temporary variable with the _float_value
													(yyval._expression).symTPtr  = currentSymbolTable->gentemp(new symbolType(tp_double));
													(yyval._expression).type = (yyval._expression).symTPtr->type;
													for(int l=0;l<10;++l) {
														int pp = 0;
													}
													if(1) {
														for(int m=0;m<10;++m) {
															int k;
														}
													}
													else{
														int n;
													}
													(yyval._expression).symTPtr->_init_val._DOUBLE_INITVAL = (yyvsp[0]._float_value);
													int l = 0;
													int k = 2;
													for(int i=0;i<10;++i) {
														int l = 0;
													}
													if(k) {
														for(int i=0;i<10;++i) {
															int k;
														}
													}
													else{
														int o;
													}
													(yyval._expression).symTPtr->isInitialized = true;
													(yyval._expression).arr = NULL;
													for(int l=0;l<10;++l) {
														int pp = 0;
													}
													if(1) {
														for(int m=0;m<10;++m) {
															int k;
														}
													}
													else{
														int n;
													}
													globalQuadArray.emit(Q_ASSIGN, (yyvsp[0]._float_value), (yyval._expression).symTPtr->name);
												  }
#line 2046 "y.tab.c"
    break;

  case 7: /* primary_expression: CHAR_CONST  */
#line 361 "ass6_18CS10033_18CS30036.y"
                                                                           {
												// Declare and initialize the value of the temporary variable with the character
												(yyval._expression).symTPtr  = currentSymbolTable->gentemp(new symbolType(tp_char));
												(yyval._expression).type = (yyval._expression).symTPtr->type;
												for(int l=0;l<10;++l) {
													int pp = 0;
												}
												if(1) {
													for(int m=0;m<10;++m) {
														int k;
													}
												}
												else{
													int n;
												}
												(yyval._expression).symTPtr->_init_val._CHAR_INITVAL = (yyvsp[0]._char_value);
												(yyval._expression).symTPtr->isInitialized = true;
												int l = 0;
												int k = 2;
												for(int i=0;i<10;++i) {
													int l = 0;
												}
												if(k) {
													for(int i=0;i<10;++i) {
														int k;
													}
												}
												else{
													int o;
												}
												(yyval._expression).arr = NULL;
												globalQuadArray.emit(Q_ASSIGN, (yyvsp[0]._char_value), (yyval._expression).symTPtr->name);
											}
#line 2084 "y.tab.c"
    break;

  case 8: /* primary_expression: STRING_LITERAL  */
#line 394 "ass6_18CS10033_18CS30036.y"
                                                                               {

													_string_labels.push_back(*(yyvsp[0]._string_literal));
													(yyval._expression).symTPtr = NULL;
													for(int l=0;l<10;++l) {
														int pp = 0;
													}
													if(1) {
														for(int m=0;m<10;++m) {
															int k;
														}
													}
													else{
														int n;
													}
													(yyval._expression).isString = true;
													int l = 0;
													int k = 2;
													for(int i=0;i<10;++i) {
														int l = 0;
													}
													if(k) {
														for(int i=0;i<10;++i) {
															int k;
														}
													}
													else{
														int o;
													}
													(yyval._expression).ind_str = _string_labels.size()-1;
													(yyval._expression).arr = NULL;
													(yyval._expression).isPointer = false;
												}
#line 2122 "y.tab.c"
    break;

  case 9: /* primary_expression: '(' expression ')'  */
#line 427 "ass6_18CS10033_18CS30036.y"
                                                                                   {
														(yyval._expression) = (yyvsp[-1]._expression);
												   }
#line 2130 "y.tab.c"
    break;

  case 10: /* postfix_expression: primary_expression  */
#line 431 "ass6_18CS10033_18CS30036.y"
                                                   {
														 (yyval._expression) = (yyvsp[0]._expression);
													}
#line 2138 "y.tab.c"
    break;

  case 11: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 434 "ass6_18CS10033_18CS30036.y"
                                                                                                      {
																		//Explanation of Array handling

																		(yyval._expression).symTPtr = currentSymbolTable->gentemp(new symbolType(tp_int));
																		for(int l=0;l<10;++l) {
																			int pp = 0;
																		}
																		if(1) {
																			for(int m=0;m<10;++m) {
																				int k;
																			}
																		}
																		else{
																			int n;
																		}

																		symbol* temporary = currentSymbolTable->gentemp(new symbolType(tp_int));

																		char temp[10];
																		//printf("hoooooooooooooooooooooooooooooooooo %s\n",$1.symTPtr->name.c_str());
																		sprintf(temp,"%d",(yyvsp[-3]._expression).type->next->sizeOfType());
																		int l = 0;
																		int k = 2;
																		for(int i=0;i<10;++i) {
																			int l = 0;
																		}
																		if(k) {
																			for(int i=0;i<10;++i) {
																				int k;
																			}
																		}
																		else{
																			int o;
																		}
																		globalQuadArray.emit(Q_MULT,(yyvsp[-1]._expression).symTPtr->name,temp,temporary->name);
																		globalQuadArray.emit(Q_PLUS,(yyvsp[-3]._expression).symTPtr->name,temporary->name,(yyval._expression).symTPtr->name);

																		// the new size will be calculated and the temporary variable storing the size will be passed on a $$.symTPtr

																		//$$.arr <= base pointer
																		(yyval._expression).arr = (yyvsp[-3]._expression).arr;

																		//$$.type <= type(arr)
																		(yyval._expression).type = (yyvsp[-3]._expression).type->next;
																		(yyval._expression).poss_array = NULL;

																		//$$.arr->type has the full type of the arr which will be used for size calculations
																	 }
#line 2191 "y.tab.c"
    break;

  case 12: /* postfix_expression: postfix_expression '(' argument_expression_list_opt ')'  */
#line 482 "ass6_18CS10033_18CS30036.y"
                                                                                                                        {
																							//Explanation of Function Handling
																							if(!(yyvsp[-3]._expression).isPointer && !(yyvsp[-3]._expression).isString && ((yyvsp[-3]._expression).type) && ((yyvsp[-3]._expression).type->type==tp_void))
																							{
																								int l = 0;
																								int k = 2;
																								for(int i=0;i<10;++i) {
																									int l = 0;
																								}
																								if(k) {
																									for(int i=0;i<10;++i) {
																										int k;
																									}
																								}
																								else{
																									int o;
																								}
																							}
																							else
																								(yyval._expression).symTPtr = currentSymbolTable->gentemp(CopyType((yyvsp[-3]._expression).type));
																							//temporary is created
																							char str[10];
																							if((yyvsp[-1]._paramList).args == NULL)
																							{
																								for(int l=0;l<10;++l) {
																									int pp = 0;
																								}
																								if(1) {
																									for(int m=0;m<10;++m) {
																										int k;
																									}
																								}
																								else{
																									int n;
																								}
																								//No function Parameters
																								sprintf(str,"0");
																								int l = 0;
																								int k = 2;
																								for(int i=0;i<10;++i) {
																									int l = 0;
																								}
																								if(k) {
																									for(int i=0;i<10;++i) {
																										int k;
																									}
																								}
																								else{
																									int o;
																								}
																								if((yyvsp[-3]._expression).type->type!=tp_void)
																									globalQuadArray.emit(Q_CALL,(yyvsp[-3]._expression).symTPtr->name,str,(yyval._expression).symTPtr->name);
																								else
																									globalQuadArray.emitG(Q_CALL,(yyvsp[-3]._expression).symTPtr->name,str);
																							}
																							else
																							{
																								if((*(yyvsp[-1]._paramList).args)[0]->isString)
																								{
																									str[0] = '_';
																									for(int l=0;l<10;++l) {
																										int pp = 0;
																									}
																									if(1) {
																										for(int m=0;m<10;++m) {
																											int k;
																										}
																									}
																									else{
																										int n;
																									}
																									sprintf(str+1,"%d",(*(yyvsp[-1]._paramList).args)[0]->ind_str);
																									globalQuadArray.emit(Q_PARAM,str);
																									int l = 0;
																									int k = 2;
																									for(int i=0;i<10;++i) {
																										int l = 0;
																									}
																									if(k) {
																										for(int i=0;i<10;++i) {
																											int k;
																										}
																									}
																									else{
																										int o;
																									}
																									globalQuadArray.emit(Q_CALL,(yyvsp[-3]._expression).symTPtr->name,"1",(yyval._expression).symTPtr->name);
																								}
																								else
																								{
																									for(int i=0;i<(yyvsp[-1]._paramList).args->size();i++)
																									{
																										// To print the parameters
																										int l = 0;
																										int k = 2;
																										for(int pp=0;pp<10;++pp) {
																											int l = 0;
																										}
																										if(k) {
																											for(int pp=0;pp<10;++pp) {
																												int k;
																											}
																										}
																										else{
																											int o;
																										}
																										if((*(yyvsp[-1]._paramList).args)[i]->poss_array != NULL && (yyvsp[-3]._expression).symTPtr->name != "printInt")
																											globalQuadArray.emit(Q_PARAM,(*(yyvsp[-1]._paramList).args)[i]->poss_array->name);
																										else
																											globalQuadArray.emit(Q_PARAM,(*(yyvsp[-1]._paramList).args)[i]->symTPtr->name);

																									}
																									sprintf(str,"%ld",(yyvsp[-1]._paramList).args->size());
																									//printf("function %s-->%d\n",$1.symTPtr->name.c_str(),$1.type->type);
																									if((yyvsp[-3]._expression).type->type!=tp_void) {
																										globalQuadArray.emit(Q_CALL,(yyvsp[-3]._expression).symTPtr->name,str,(yyval._expression).symTPtr->name);
																										for(int l=0;l<10;++l) {
																											int pp = 0;
																										}
																										if(1) {
																											for(int m=0;m<10;++m) {
																												int k;
																											}
																										}
																										else{
																											int n;
																										}
																									}
																									else
																										globalQuadArray.emitG(Q_CALL,(yyvsp[-3]._expression).symTPtr->name,str);
																								}
																							}

																							(yyval._expression).arr = NULL;
																							(yyval._expression).type = (yyval._expression).symTPtr->type;
																						 }
#line 2332 "y.tab.c"
    break;

  case 13: /* postfix_expression: postfix_expression '.' IDENTIFIER  */
#line 618 "ass6_18CS10033_18CS30036.y"
                                                                                                  {/*Struct Logic to be Skipped*/}
#line 2338 "y.tab.c"
    break;

  case 14: /* postfix_expression: postfix_expression ARROW IDENTIFIER  */
#line 619 "ass6_18CS10033_18CS30036.y"
                                                                                                    {
																			/*----*/
																	  }
#line 2346 "y.tab.c"
    break;

  case 15: /* postfix_expression: postfix_expression INCREMENT  */
#line 622 "ass6_18CS10033_18CS30036.y"
                                                                                             {
																(yyval._expression).symTPtr = currentSymbolTable->gentemp(CopyType((yyvsp[-1]._expression).type));
																if((yyvsp[-1]._expression).arr != NULL)
																{
																	// Post increment of an array element
																	symbol * temp_elem = currentSymbolTable->gentemp(CopyType((yyvsp[-1]._expression).type));
																	globalQuadArray.emit(Q_RINDEX,(yyvsp[-1]._expression).arr->name,(yyvsp[-1]._expression).symTPtr->name,(yyval._expression).symTPtr->name);
																	for(int l=0;l<10;++l) {
																		int pp = 0;
																	}
																	if(1) {
																		for(int m=0;m<10;++m) {
																			int k;
																		}
																	}
																	else{
																		int n;
																	}
																	globalQuadArray.emit(Q_RINDEX,(yyvsp[-1]._expression).arr->name,(yyvsp[-1]._expression).symTPtr->name,temp_elem->name);
																	int l = 0;
																	int k = 2;
																	for(int i=0;i<10;++i) {
																		int l = 0;
																	}
																	if(k) {
																		for(int i=0;i<10;++i) {
																			int k;
																		}
																	}
																	else{
																		int o;
																	}
																	globalQuadArray.emit(Q_PLUS,temp_elem->name,"1",temp_elem->name);
																	globalQuadArray.emit(Q_LINDEX,(yyvsp[-1]._expression).symTPtr->name,temp_elem->name,(yyvsp[-1]._expression).arr->name);
																	(yyval._expression).arr = NULL;
																}
																else
																{
																	//post increment of an simple element
																	for(int l=0;l<10;++l) {
																		int pp = 0;
																	}
																	if(1) {
																		for(int m=0;m<10;++m) {
																			int k;
																		}
																	}
																	else{
																		int n;
																	}
																	globalQuadArray.emit(Q_ASSIGN,(yyvsp[-1]._expression).symTPtr->name,(yyval._expression).symTPtr->name);
																	int l = 0;
																	int k = 2;
																	for(int i=0;i<10;++i) {
																		int l = 0;
																	}
																	if(k) {
																		for(int i=0;i<10;++i) {
																			int k;
																		}
																	}
																	else{
																		int o;
																	}
																	globalQuadArray.emit(Q_PLUS,(yyvsp[-1]._expression).symTPtr->name,"1",(yyvsp[-1]._expression).symTPtr->name);
																}
																(yyval._expression).type = (yyval._expression).symTPtr->type;
															 }
#line 2419 "y.tab.c"
    break;

  case 16: /* postfix_expression: postfix_expression DECREMENT  */
#line 690 "ass6_18CS10033_18CS30036.y"
                                                                                             {
																(yyval._expression).symTPtr = currentSymbolTable->gentemp(CopyType((yyvsp[-1]._expression).type));
																if((yyvsp[-1]._expression).arr != NULL)
																{
																	// Post decrement of an array element
																	for(int l=0;l<10;++l) {
																		int pp = 0;
																	}
																	if(1) {
																		for(int m=0;m<10;++m) {
																			int k;
																		}
																	}
																	else{
																		int n;
																	}
																	symbol * temp_elem = currentSymbolTable->gentemp(CopyType((yyvsp[-1]._expression).type));
																	globalQuadArray.emit(Q_RINDEX,(yyvsp[-1]._expression).arr->name,(yyvsp[-1]._expression).symTPtr->name,(yyval._expression).symTPtr->name);
																	int l = 0;
																	int k = 2;
																	for(int i=0;i<10;++i) {
																		int l = 0;
																	}
																	if(k) {
																		for(int i=0;i<10;++i) {
																			int k;
																		}
																	}
																	else{
																		int o;
																	}
																	globalQuadArray.emit(Q_RINDEX,(yyvsp[-1]._expression).arr->name,(yyvsp[-1]._expression).symTPtr->name,temp_elem->name);
																	globalQuadArray.emit(Q_MINUS,temp_elem->name,"1",temp_elem->name);
																	for(int l=0;l<10;++l) {
																		int pp = 0;
																	}
																	if(1) {
																		for(int m=0;m<10;++m) {
																			int k;
																		}
																	}
																	else{
																		int n;
																	}
																	globalQuadArray.emit(Q_LINDEX,(yyvsp[-1]._expression).symTPtr->name,temp_elem->name,(yyvsp[-1]._expression).arr->name);
																	(yyval._expression).arr = NULL;
																}
																else
																{
																	//post decrement of an simple element
																	globalQuadArray.emit(Q_ASSIGN,(yyvsp[-1]._expression).symTPtr->name,(yyval._expression).symTPtr->name);
																	int l = 0;
																	int k = 2;
																	for(int i=0;i<10;++i) {
																		int l = 0;
																	}
																	if(k) {
																		for(int i=0;i<10;++i) {
																			int k;
																		}
																	}
																	else{
																		int o;
																	}
																	globalQuadArray.emit(Q_MINUS,(yyvsp[-1]._expression).symTPtr->name,"1",(yyvsp[-1]._expression).symTPtr->name);
																}
																(yyval._expression).type = (yyval._expression).symTPtr->type;
															  }
#line 2492 "y.tab.c"
    break;

  case 17: /* postfix_expression: '(' type_name ')' '{' initializer_list '}'  */
#line 758 "ass6_18CS10033_18CS30036.y"
                                                                                                           {
																				/*------*/
																		   }
#line 2500 "y.tab.c"
    break;

  case 18: /* postfix_expression: '(' type_name ')' '{' initializer_list ',' '}'  */
#line 761 "ass6_18CS10033_18CS30036.y"
                                                                                                               {
																					/*------*/
																			   }
#line 2508 "y.tab.c"
    break;

  case 19: /* argument_expression_list: assignment_expression  */
#line 765 "ass6_18CS10033_18CS30036.y"
                                                      {
														(yyval._paramList).args = new vector<expression*>;
														for(int l=0;l<10;++l) {
															int pp = 0;
														}
														if(1) {
															for(int m=0;m<10;++m) {
																int k;
															}
														}
														else{
															int n;
														}
														expression * tex = new expression((yyvsp[0]._expression));
														int l = 0;
														int k = 2;
														for(int i=0;i<10;++i) {
															int l = 0;
														}
														if(k) {
															for(int i=0;i<10;++i) {
																int k;
															}
														}
														else{
															int o;
														}
														(yyval._paramList).args->push_back(tex);
														//printf("name2-->%s\n",tex->symTPtr->name.c_str());
													 }
#line 2543 "y.tab.c"
    break;

  case 20: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 795 "ass6_18CS10033_18CS30036.y"
                                                                                                                   {
																						expression * tex = new expression((yyvsp[0]._expression));
																						(yyval._paramList).args->push_back(tex);
																					}
#line 2552 "y.tab.c"
    break;

  case 21: /* argument_expression_list_opt: argument_expression_list  */
#line 800 "ass6_18CS10033_18CS30036.y"
                                                         {
															(yyval._paramList) = (yyvsp[0]._paramList);
														  }
#line 2560 "y.tab.c"
    break;

  case 22: /* argument_expression_list_opt: %empty  */
#line 803 "ass6_18CS10033_18CS30036.y"
                                                                            {
												(yyval._paramList).args = NULL;
												int l = 0;
												int k = 2;
												for(int i=0;i<10;++i) {
													int l = 0;
												}
												if(k) {
													for(int i=0;i<10;++i) {
														int k;
													}
												}
												else{
													int o;
												}
											}
#line 2581 "y.tab.c"
    break;

  case 23: /* unary_expression: postfix_expression  */
#line 820 "ass6_18CS10033_18CS30036.y"
                                                   {
														(yyval._expression) = (yyvsp[0]._expression);
												   }
#line 2589 "y.tab.c"
    break;

  case 24: /* unary_expression: INCREMENT unary_expression  */
#line 823 "ass6_18CS10033_18CS30036.y"
                                                                                           {
																(yyval._expression).symTPtr = currentSymbolTable->gentemp((yyvsp[0]._expression).type);
																if((yyvsp[0]._expression).arr != NULL)
																{
																	// pre increment of an Array element
																	symbol * temp_elem = currentSymbolTable->gentemp(CopyType((yyvsp[0]._expression).type));
																	globalQuadArray.emit(Q_RINDEX,(yyvsp[0]._expression).arr->name,(yyvsp[0]._expression).symTPtr->name,temp_elem->name);
																	int l = 0;
																	int k = 2;
																	for(int i=0;i<10;++i) {
																		int l = 0;
																	}
																	if(k) {
																		for(int i=0;i<10;++i) {
																			int k;
																		}
																	}
																	else{
																		int o;
																	}
																	globalQuadArray.emit(Q_PLUS,temp_elem->name,"1",temp_elem->name);
																	globalQuadArray.emit(Q_LINDEX,(yyvsp[0]._expression).symTPtr->name,temp_elem->name,(yyvsp[0]._expression).arr->name);
																	globalQuadArray.emit(Q_RINDEX,(yyvsp[0]._expression).arr->name,(yyvsp[0]._expression).symTPtr->name,(yyval._expression).symTPtr->name);
																	(yyval._expression).arr = NULL;
																}
																else
																{
																	// pre increment
																	globalQuadArray.emit(Q_PLUS,(yyvsp[0]._expression).symTPtr->name,"1",(yyvsp[0]._expression).symTPtr->name);
																	int l = 0;
																	int k = 2;
																	for(int i=0;i<10;++i) {
																		int l = 0;
																	}
																	if(k) {
																		for(int i=0;i<10;++i) {
																			int k;
																		}
																	}
																	else{
																		int o;
																	}
																	globalQuadArray.emit(Q_ASSIGN,(yyvsp[0]._expression).symTPtr->name,(yyval._expression).symTPtr->name);
																	for(int l=0;l<10;++l) {
																		int pp = 0;
																	}
																	if(1) {
																		for(int m=0;m<10;++m) {
																			int k;
																		}
																	}
																	else{
																		int n;
																	}
																}
																(yyval._expression).type = (yyval._expression).symTPtr->type;
															}
#line 2651 "y.tab.c"
    break;

  case 25: /* unary_expression: DECREMENT unary_expression  */
#line 880 "ass6_18CS10033_18CS30036.y"
                                                                                           {
																(yyval._expression).symTPtr = currentSymbolTable->gentemp(CopyType((yyvsp[0]._expression).type));
																if((yyvsp[0]._expression).arr != NULL)
																{
																	//pre decrement of  Array Element
																	for(int l=0;l<10;++l) {
																		int pp = 0;
																	}
																	if(1) {
																		for(int m=0;m<10;++m) {
																			int k;
																		}
																	}
																	else{
																		int n;
																	}
																	symbol * temp_elem = currentSymbolTable->gentemp(CopyType((yyvsp[0]._expression).type));
																	globalQuadArray.emit(Q_RINDEX,(yyvsp[0]._expression).arr->name,(yyvsp[0]._expression).symTPtr->name,temp_elem->name);
																	globalQuadArray.emit(Q_MINUS,temp_elem->name,"1",temp_elem->name);
																	int l = 0;
																	int k = 2;
																	for(int i=0;i<10;++i) {
																		int l = 0;
																	}
																	if(k) {
																		for(int i=0;i<10;++i) {
																			int k;
																		}
																	}
																	else{
																		int o;
																	}
																	globalQuadArray.emit(Q_LINDEX,(yyvsp[0]._expression).symTPtr->name,temp_elem->name,(yyvsp[0]._expression).arr->name);
																	globalQuadArray.emit(Q_RINDEX,(yyvsp[0]._expression).arr->name,(yyvsp[0]._expression).symTPtr->name,(yyval._expression).symTPtr->name);
																	for(int l=0;l<10;++l) {
																		int pp = 0;
																	}
																	if(1) {
																		for(int m=0;m<10;++m) {
																			int k;
																		}
																	}
																	else{
																		int n;
																	}
																	(yyval._expression).arr = NULL;
																}
																else
																{
																	// pre decrement
																	globalQuadArray.emit(Q_MINUS,(yyvsp[0]._expression).symTPtr->name,"1",(yyvsp[0]._expression).symTPtr->name);
																	int l = 0;
																	int k = 2;
																	for(int i=0;i<10;++i) {
																		int l = 0;
																	}
																	if(k) {
																		for(int i=0;i<10;++i) {
																			int k;
																		}
																	}
																	else{
																		int o;
																	}
																	globalQuadArray.emit(Q_ASSIGN,(yyvsp[0]._expression).symTPtr->name,(yyval._expression).symTPtr->name);
																}
																(yyval._expression).type = (yyval._expression).symTPtr->type;
																for(int l=0;l<10;++l) {
																	int pp = 0;
																}
																if(1) {
																	for(int m=0;m<10;++m) {
																		int k;
																	}
																}
																else{
																	int n;
																}
															}
#line 2735 "y.tab.c"
    break;

  case 26: /* unary_expression: unary_operator cast_expression  */
#line 960 "ass6_18CS10033_18CS30036.y"
                                                                                                                                {
																	symbolType * temp_type;
																	switch((yyvsp[-1]._char_value))
																	{
																		case '&':
																			//create a temporary type store the type
																			temp_type = new symbolType(tp_ptr,1,(yyvsp[0]._expression).type);
																			for(int l=0;l<10;++l) {
																				int pp = 0;
																			}
																			if(1) {
																				for(int m=0;m<10;++m) {
																					int k;
																				}
																			}
																			else{
																				int n;
																			}
																			(yyval._expression).symTPtr = currentSymbolTable->gentemp(CopyType(temp_type));
																			(yyval._expression).type = (yyval._expression).symTPtr->type;
																			// int l = 0;
																			// int k = 2;
																			for(int i=0;i<10;++i) {
																				int l = 0;
																			}
																			if(1) {
																				for(int i=0;i<10;++i) {
																					int k;
																				}
																			}
																			else{
																				int o;
																			}
																			globalQuadArray.emit(Q_ADDR,(yyvsp[0]._expression).symTPtr->name,(yyval._expression).symTPtr->name);
																			(yyval._expression).arr = NULL;
																			break;
																		case '*':
																			(yyval._expression).isPointer = true;
																			(yyval._expression).type = (yyvsp[0]._expression).symTPtr->type->next;
																			(yyval._expression).symTPtr = (yyvsp[0]._expression).symTPtr;
																			for(int i=0;i<10;++i) {
																				int ll = 0;
																			}
																			if(1) {
																				for(int i=0;i<10;++i) {
																					int kk;
																				}
																			}
																			else{
																				int o;
																			}
																			(yyval._expression).arr = NULL;
																			break;
																		case '+':
																			(yyval._expression).symTPtr = currentSymbolTable->gentemp(CopyType((yyvsp[0]._expression).type));
																			(yyval._expression).type = (yyval._expression).symTPtr->type;
																			for(int i=0;i<10;++i) {
																				int lll = 0;
																			}
																			if(1) {
																				for(int i=0;i<10;++i) {
																					int k;
																				}
																			}
																			else{
																				int o;
																			}
																			globalQuadArray.emit(Q_ASSIGN,(yyvsp[0]._expression).symTPtr->name,(yyval._expression).symTPtr->name);
																			break;
																		case '-':
																			(yyval._expression).symTPtr = currentSymbolTable->gentemp(CopyType((yyvsp[0]._expression).type));
																			(yyval._expression).type = (yyval._expression).symTPtr->type;
																			for(int i=0;i<10;++i) {
																				int l = 0;
																			}
																			if(1) {
																				for(int i=0;i<10;++i) {
																					int k;
																				}
																			}
																			else{
																				int o;
																			}
																			globalQuadArray.emit(Q_UNARY_MINUS,(yyvsp[0]._expression).symTPtr->name,(yyval._expression).symTPtr->name);
																			break;
																		case '~':
																			/*Bitwise Not to be implemented Later on*/
																			(yyval._expression).symTPtr = currentSymbolTable->gentemp(CopyType((yyvsp[0]._expression).type));
																			(yyval._expression).type = (yyval._expression).symTPtr->type;
																			for(int i=0;i<10;++i) {
																				int l = 0;
																			}
																			if(1) {
																				for(int i=0;i<10;++i) {
																					int k;
																				}
																			}
																			else{
																				int o;
																			}
																			globalQuadArray.emit(Q_NOT,(yyvsp[0]._expression).symTPtr->name,(yyval._expression).symTPtr->name);
																			break;
																		case '!':
																			(yyval._expression).symTPtr = currentSymbolTable->gentemp(CopyType((yyvsp[0]._expression).type));
																			(yyval._expression).type = (yyval._expression).symTPtr->type;
																			for(int i=0;i<10;++i) {
																				int l = 0;
																			}
																			if(1) {
																				for(int i=0;i<10;++i) {
																					int k;
																				}
																			}
																			else{
																				int o;
																			}
																			(yyval._expression).truelist = (yyvsp[0]._expression).falselist;
																			(yyval._expression).falselist = (yyvsp[0]._expression).truelist;
																			break;
																		default:
																			break;
																	}
																}
#line 2863 "y.tab.c"
    break;

  case 27: /* unary_expression: SIZEOF unary_expression  */
#line 1083 "ass6_18CS10033_18CS30036.y"
                                                                                        {}
#line 2869 "y.tab.c"
    break;

  case 28: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 1084 "ass6_18CS10033_18CS30036.y"
                                                                                         {}
#line 2875 "y.tab.c"
    break;

  case 29: /* unary_operator: '&'  */
#line 1086 "ass6_18CS10033_18CS30036.y"
                                    {
										(yyval._char_value) = '&';
									}
#line 2883 "y.tab.c"
    break;

  case 30: /* unary_operator: '*'  */
#line 1089 "ass6_18CS10033_18CS30036.y"
                                                                    {
										(yyval._char_value) = '*';
									}
#line 2891 "y.tab.c"
    break;

  case 31: /* unary_operator: '+'  */
#line 1092 "ass6_18CS10033_18CS30036.y"
                                                                    {
										(yyval._char_value) = '+';
									}
#line 2899 "y.tab.c"
    break;

  case 32: /* unary_operator: '-'  */
#line 1095 "ass6_18CS10033_18CS30036.y"
                                                                    {
										(yyval._char_value) = '-';
									}
#line 2907 "y.tab.c"
    break;

  case 33: /* unary_operator: '~'  */
#line 1098 "ass6_18CS10033_18CS30036.y"
                                                                    {
										(yyval._char_value) = '~';
									}
#line 2915 "y.tab.c"
    break;

  case 34: /* unary_operator: '!'  */
#line 1101 "ass6_18CS10033_18CS30036.y"
                                                                    {
										(yyval._char_value) = '!';
									}
#line 2923 "y.tab.c"
    break;

  case 35: /* cast_expression: unary_expression  */
#line 1105 "ass6_18CS10033_18CS30036.y"
                                                 {
													if((yyvsp[0]._expression).arr != NULL && (yyvsp[0]._expression).arr->type != NULL&& (yyvsp[0]._expression).poss_array==NULL)
													{
														//Right Indexing of an array element as unary expression is converted into cast expression
														(yyval._expression).symTPtr = currentSymbolTable->gentemp(new symbolType((yyvsp[0]._expression).type->type));
														for(int l=0;l<10;++l) {
															int pp = 0;
														}
														if(1) {
															for(int m=0;m<10;++m) {
																int k;
															}
														}
														else{
															int n;
														}
														globalQuadArray.emit(Q_RINDEX,(yyvsp[0]._expression).arr->name,(yyvsp[0]._expression).symTPtr->name,(yyval._expression).symTPtr->name);
														(yyval._expression).arr = NULL;
														int l = 0;
														int k = 2;
														for(int i=0;i<10;++i) {
															int l = 0;
														}
														if(k) {
															for(int i=0;i<10;++i) {
																int k;
															}
														}
														else{
															int o;
														}
														(yyval._expression).type = (yyval._expression).symTPtr->type;
														//$$.poss_array=$1.arr;
														//printf("name --> %s\n",$$.symTPtr->name.c_str());
													}
													else if((yyvsp[0]._expression).isPointer == true)
													{
														//RDereferencing as its a pointer
														(yyval._expression).symTPtr = currentSymbolTable->gentemp(CopyType((yyvsp[0]._expression).type));
														for(int l=0;l<10;++l) {
															int pp = 0;
														}
														if(1) {
															for(int m=0;m<10;++m) {
																int k;
															}
														}
														else{
															int n;
														}
														(yyval._expression).isPointer = false;
														int l = 0;
														int k = 2;
														for(int i=0;i<10;++i) {
															int l = 0;
														}
														if(k) {
															for(int i=0;i<10;++i) {
																int k;
															}
														}
														else{
															int o;
														}
														globalQuadArray.emit(Q_RDEREF,(yyvsp[0]._expression).symTPtr->name,(yyval._expression).symTPtr->name);
													}
													else
														(yyval._expression) = (yyvsp[0]._expression);
												}
#line 2997 "y.tab.c"
    break;

  case 36: /* cast_expression: '(' type_name ')' cast_expression  */
#line 1174 "ass6_18CS10033_18CS30036.y"
                                                                                                 {
																	/*--------*/
																 }
#line 3005 "y.tab.c"
    break;

  case 37: /* multiplicative_expression: cast_expression  */
#line 1178 "ass6_18CS10033_18CS30036.y"
                                                {
													(yyval._expression) = (yyvsp[0]._expression);
												}
#line 3013 "y.tab.c"
    break;

  case 38: /* multiplicative_expression: multiplicative_expression '*' cast_expression  */
#line 1181 "ass6_18CS10033_18CS30036.y"
                                                                                                              {
																					typecheck(&(yyvsp[-2]._expression),&(yyvsp[0]._expression));
																					(yyval._expression).symTPtr = currentSymbolTable->gentemp((yyvsp[-2]._expression).type);
																					(yyval._expression).type = (yyval._expression).symTPtr->type;
																					int l = 0;
																					int k = 2;
																					for(int i=0;i<10;++i) {
																						int l = 0;
																					}
																					if(k) {
																						for(int i=0;i<10;++i) {
																							int k;
																						}
																					}
																					else{
																						int o;
																					}
																					for(int l=0;l<10;++l) {
																						int pp = 0;
																					}
																					if(1) {
																						for(int m=0;m<10;++m) {
																							int k;
																						}
																					}
																					else{
																						int n;
																					}
																					globalQuadArray.emit(Q_MULT,(yyvsp[-2]._expression).symTPtr->name,(yyvsp[0]._expression).symTPtr->name,(yyval._expression).symTPtr->name);
																			  }
#line 3048 "y.tab.c"
    break;

  case 39: /* multiplicative_expression: multiplicative_expression '/' cast_expression  */
#line 1211 "ass6_18CS10033_18CS30036.y"
                                                                                                              {
																					typecheck(&(yyvsp[-2]._expression),&(yyvsp[0]._expression));
																					(yyval._expression).symTPtr = currentSymbolTable->gentemp((yyvsp[-2]._expression).type);
																					(yyval._expression).type = (yyval._expression).symTPtr->type;
																					int l = 0;
																					int k = 2;
																					for(int i=0;i<10;++i) {
																						int l = 0;
																					}
																					if(k) {
																						for(int i=0;i<10;++i) {
																							int k;
																						}
																					}
																					else{
																						int o;
																					}
																					globalQuadArray.emit(Q_DIVIDE,(yyvsp[-2]._expression).symTPtr->name,(yyvsp[0]._expression).symTPtr->name,(yyval._expression).symTPtr->name);
																			  }
#line 3072 "y.tab.c"
    break;

  case 40: /* multiplicative_expression: multiplicative_expression '%' cast_expression  */
#line 1230 "ass6_18CS10033_18CS30036.y"
                                                                                                             {
																					typecheck(&(yyvsp[-2]._expression),&(yyvsp[0]._expression));
																					for(int l=0;l<10;++l) {
																						int pp = 0;
																					}
																					if(1) {
																						for(int m=0;m<10;++m) {
																							int k;
																						}
																					}
																					else{
																						int n;
																					}
																					(yyval._expression).symTPtr = currentSymbolTable->gentemp((yyvsp[-2]._expression).type);
																					(yyval._expression).type = (yyval._expression).symTPtr->type;
																					int l = 0;
																					int k = 2;
																					for(int i=0;i<10;++i) {
																						int l = 0;
																					}
																					if(k) {
																						for(int i=0;i<10;++i) {
																							int k;
																						}
																					}
																					else{
																						int o;
																					}
																					globalQuadArray.emit(Q_MODULO,(yyvsp[-2]._expression).symTPtr->name,(yyvsp[0]._expression).symTPtr->name,(yyval._expression).symTPtr->name);
																			 }
#line 3107 "y.tab.c"
    break;

  case 41: /* additive_expression: multiplicative_expression  */
#line 1261 "ass6_18CS10033_18CS30036.y"
                                                          {
																(yyval._expression) = (yyvsp[0]._expression);
														  }
#line 3115 "y.tab.c"
    break;

  case 42: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 1264 "ass6_18CS10033_18CS30036.y"
                                                                                                                  {
																						typecheck(&(yyvsp[-2]._expression),&(yyvsp[0]._expression));
																						for(int l=0;l<10;++l) {
																							int pp = 0;
																						}
																						if(1) {
																							for(int m=0;m<10;++m) {
																								int k;
																							}
																						}
																						else{
																							int n;
																						}
																						(yyval._expression).symTPtr = currentSymbolTable->gentemp((yyvsp[-2]._expression).type);
																						(yyval._expression).type = (yyval._expression).symTPtr->type;
																						int l = 0;
																						int k = 2;
																						for(int i=0;i<10;++i) {
																							int l = 0;
																						}
																						if(k) {
																							for(int i=0;i<10;++i) {
																								int k;
																							}
																						}
																						else{
																							int o;
																						}
																						globalQuadArray.emit(Q_PLUS,(yyvsp[-2]._expression).symTPtr->name,(yyvsp[0]._expression).symTPtr->name,(yyval._expression).symTPtr->name);
																				  }
#line 3150 "y.tab.c"
    break;

  case 43: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 1294 "ass6_18CS10033_18CS30036.y"
                                                                                                                  {
																						typecheck(&(yyvsp[-2]._expression),&(yyvsp[0]._expression));
																						for(int l=0;l<10;++l) {
																							int pp = 0;
																						}
																						if(1) {
																							for(int m=0;m<10;++m) {
																								int k;
																							}
																						}
																						else{
																							int n;
																						}
																						(yyval._expression).symTPtr = currentSymbolTable->gentemp((yyvsp[-2]._expression).type);
																						(yyval._expression).type = (yyval._expression).symTPtr->type;
																						int l = 0;
																						int k = 2;
																						for(int i=0;i<10;++i) {
																							int l = 0;
																						}
																						if(k) {
																							for(int i=0;i<10;++i) {
																								int k;
																							}
																						}
																						else{
																							int o;
																						}
																						globalQuadArray.emit(Q_MINUS,(yyvsp[-2]._expression).symTPtr->name,(yyvsp[0]._expression).symTPtr->name,(yyval._expression).symTPtr->name);
																				  }
#line 3185 "y.tab.c"
    break;

  case 44: /* shift_expression: additive_expression  */
#line 1325 "ass6_18CS10033_18CS30036.y"
                                                    {
														(yyval._expression) = (yyvsp[0]._expression);
													}
#line 3193 "y.tab.c"
    break;

  case 45: /* shift_expression: shift_expression LEFT_SHIFT additive_expression  */
#line 1328 "ass6_18CS10033_18CS30036.y"
                                                                                                                {
																					(yyval._expression).symTPtr = currentSymbolTable->gentemp((yyvsp[-2]._expression).type);
																					(yyval._expression).type = (yyval._expression).symTPtr->type;
																					int l = 0;
																					int k = 2;
																					for(int i=0;i<10;++i) {
																						int l = 0;
																					}
																					if(k) {
																						for(int i=0;i<10;++i) {
																							int k;
																						}
																					}
																					else{
																						int o;
																					}
																					globalQuadArray.emit(Q_LEFT_OP,(yyvsp[-2]._expression).symTPtr->name,(yyvsp[0]._expression).symTPtr->name,(yyval._expression).symTPtr->name);
																				}
#line 3216 "y.tab.c"
    break;

  case 46: /* shift_expression: shift_expression RIGHT_SHIFT additive_expression  */
#line 1346 "ass6_18CS10033_18CS30036.y"
                                                                                                                {
																					(yyval._expression).symTPtr = currentSymbolTable->gentemp((yyvsp[-2]._expression).type);
																					for(int l=0;l<10;++l) {
																						int pp = 0;
																					}
																					if(1) {
																						for(int m=0;m<10;++m) {
																							int k;
																						}
																					}
																					else{
																						int n;
																					}
																					(yyval._expression).type = (yyval._expression).symTPtr->type;
																					for(int l=0;l<10;++l) {
																						int pp = 0;
																					}
																					if(1) {
																						for(int m=0;m<10;++m) {
																							int k;
																						}
																					}
																					else{
																						int n;
																					}
																					globalQuadArray.emit(Q_RIGHT_OP,(yyvsp[-2]._expression).symTPtr->name,(yyvsp[0]._expression).symTPtr->name,(yyval._expression).symTPtr->name);
																				}
#line 3248 "y.tab.c"
    break;

  case 47: /* relational_expression: shift_expression  */
#line 1374 "ass6_18CS10033_18CS30036.y"
                                                 {
														(yyval._expression) = (yyvsp[0]._expression);
												 }
#line 3256 "y.tab.c"
    break;

  case 48: /* relational_expression: relational_expression '<' shift_expression  */
#line 1377 "ass6_18CS10033_18CS30036.y"
                                                                                                           {
																				typecheck(&(yyvsp[-2]._expression),&(yyvsp[0]._expression));
																				for(int l=0;l<10;++l) {
																					int pp = 0;
																				}
																				if(1) {
																					for(int m=0;m<10;++m) {
																						int k;
																					}
																				}
																				else{
																					int n;
																				}
																				(yyval._expression).type = new symbolType(tp_bool);
																				(yyval._expression).truelist = makelist(nextInstruction);
																				int l = 0;
																				int k = 2;
																				for(int i=0;i<10;++i) {
																					int l = 0;
																				}
																				if(k) {
																					for(int i=0;i<10;++i) {
																						int k;
																					}
																				}
																				else{
																					int o;
																				}
																				(yyval._expression).falselist = makelist(nextInstruction+1);
																				for(int l=0;l<10;++l) {
																					int pp = 0;
																				}
																				if(1) {
																					for(int m=0;m<10;++m) {
																						int k;
																					}
																				}
																				else{
																					int n;
																				}
																				globalQuadArray.emit(Q_IF_LESS,(yyvsp[-2]._expression).symTPtr->name,(yyvsp[0]._expression).symTPtr->name,"-1");
																				globalQuadArray.emit(Q_GOTO,"-1");
																		   }
#line 3304 "y.tab.c"
    break;

  case 49: /* relational_expression: relational_expression '>' shift_expression  */
#line 1420 "ass6_18CS10033_18CS30036.y"
                                                                                                           {
																				typecheck(&(yyvsp[-2]._expression),&(yyvsp[0]._expression));
																				(yyval._expression).type = new symbolType(tp_bool);
																				(yyval._expression).truelist = makelist(nextInstruction);
																				int l = 0;
																				int k = 2;
																				for(int i=0;i<10;++i) {
																					int l = 0;
																				}
																				if(k) {
																					for(int i=0;i<10;++i) {
																						int k;
																					}
																				}
																				else{
																					int o;
																				}
																				(yyval._expression).falselist = makelist(nextInstruction+1);
																				globalQuadArray.emit(Q_IF_GREATER,(yyvsp[-2]._expression).symTPtr->name,(yyvsp[0]._expression).symTPtr->name,"-1");
																				globalQuadArray.emit(Q_GOTO,"-1");
																		   }
#line 3330 "y.tab.c"
    break;

  case 50: /* relational_expression: relational_expression LESS_THAN_EQUAL shift_expression  */
#line 1441 "ass6_18CS10033_18CS30036.y"
                                                                                                                       {
																						typecheck(&(yyvsp[-2]._expression),&(yyvsp[0]._expression));
																						(yyval._expression).type = new symbolType(tp_bool);
																						for(int l=0;l<10;++l) {
																							int pp = 0;
																						}
																						if(1) {
																							for(int m=0;m<10;++m) {
																								int k;
																							}
																						}
																						else{
																							int n;
																						}
																						(yyval._expression).truelist = makelist(nextInstruction);
																						int l = 0;
																						int k = 2;
																						for(int i=0;i<10;++i) {
																							int l = 0;
																						}
																						if(k) {
																							for(int i=0;i<10;++i) {
																								int k;
																							}
																						}
																						else{
																							int o;
																						}
																						(yyval._expression).falselist = makelist(nextInstruction+1);
																						globalQuadArray.emit(Q_IF_LESS_OR_EQUAL,(yyvsp[-2]._expression).symTPtr->name,(yyvsp[0]._expression).symTPtr->name,"-1");
																						globalQuadArray.emit(Q_GOTO,"-1");
																					}
#line 3367 "y.tab.c"
    break;

  case 51: /* relational_expression: relational_expression GREATER_THAN_EQUAL shift_expression  */
#line 1473 "ass6_18CS10033_18CS30036.y"
                                                                                                                          {
																							typecheck(&(yyvsp[-2]._expression),&(yyvsp[0]._expression));
																							for(int l=0;l<10;++l) {
																								int pp = 0;
																							}
																							if(1) {
																								for(int m=0;m<10;++m) {
																									int k;
																								}
																							}
																							else{
																								int n;
																							}
																							(yyval._expression).type = new symbolType(tp_bool);
																							(yyval._expression).truelist = makelist(nextInstruction);
																							int l = 0;
																							int k = 2;
																							for(int i=0;i<10;++i) {
																								int l = 0;
																							}
																							if(k) {
																								for(int i=0;i<10;++i) {
																									int k;
																								}
																							}
																							else{
																								int o;
																							}
																							(yyval._expression).falselist = makelist(nextInstruction+1);
																							globalQuadArray.emit(Q_IF_GREATER_OR_EQUAL,(yyvsp[-2]._expression).symTPtr->name,(yyvsp[0]._expression).symTPtr->name,"-1");
																							globalQuadArray.emit(Q_GOTO,"-1");
																					  }
#line 3404 "y.tab.c"
    break;

  case 52: /* equality_expression: relational_expression  */
#line 1506 "ass6_18CS10033_18CS30036.y"
                                                      {
															(yyval._expression) = (yyvsp[0]._expression);
													  }
#line 3412 "y.tab.c"
    break;

  case 53: /* equality_expression: equality_expression EQUALITY relational_expression  */
#line 1509 "ass6_18CS10033_18CS30036.y"
                                                                                                                   {
																						typecheck(&(yyvsp[-2]._expression),&(yyvsp[0]._expression));
																						(yyval._expression).type = new symbolType(tp_bool);
																						(yyval._expression).truelist = makelist(nextInstruction);
																						int l = 0;
																						int k = 2;
																						for(int i=0;i<10;++i) {
																							int l = 0;
																						}
																						if(k) {
																							for(int i=0;i<10;++i) {
																								int k;
																							}
																						}
																						else{
																							int o;
																						}
																						(yyval._expression).falselist = makelist(nextInstruction+1);
																						globalQuadArray.emit(Q_IF_EQUAL,(yyvsp[-2]._expression).symTPtr->name,(yyvsp[0]._expression).symTPtr->name,"-1");
																						globalQuadArray.emit(Q_GOTO,"-1");
																						for(int l=0;l<10;++l) {
																							int pp = 0;
																						}
																						if(1) {
																							for(int m=0;m<10;++m) {
																								int k;
																							}
																						}
																						else{
																							int n;
																						}
																				 }
#line 3449 "y.tab.c"
    break;

  case 54: /* equality_expression: equality_expression NOT_EQUAL relational_expression  */
#line 1541 "ass6_18CS10033_18CS30036.y"
                                                                                                                    {
																							typecheck(&(yyvsp[-2]._expression),&(yyvsp[0]._expression));
																							(yyval._expression).type = new symbolType(tp_bool);
																							int l = 0;
																							int k = 2;
																							for(int i=0;i<10;++i) {
																								int l = 0;
																							}
																							if(k) {
																								for(int i=0;i<10;++i) {
																									int k;
																								}
																							}
																							else{
																								int o;
																							}
																							(yyval._expression).truelist = makelist(nextInstruction);
																							(yyval._expression).falselist = makelist(nextInstruction+1);
																							for(int l=0;l<10;++l) {
																								int pp = 0;
																							}
																							if(1) {
																								for(int m=0;m<10;++m) {
																									int k;
																								}
																							}
																							else{
																								int n;
																							}
																							globalQuadArray.emit(Q_IF_NOT_EQUAL,(yyvsp[-2]._expression).symTPtr->name,(yyvsp[0]._expression).symTPtr->name,"-1");
																							globalQuadArray.emit(Q_GOTO,"-1");
																					 }
#line 3486 "y.tab.c"
    break;

  case 55: /* AND_expression: equality_expression  */
#line 1574 "ass6_18CS10033_18CS30036.y"
                                                    {
														(yyval._expression) = (yyvsp[0]._expression);
													}
#line 3494 "y.tab.c"
    break;

  case 56: /* AND_expression: AND_expression '&' equality_expression  */
#line 1577 "ass6_18CS10033_18CS30036.y"
                                                                                                       {
																			(yyval._expression).symTPtr = currentSymbolTable->gentemp((yyvsp[-2]._expression).type);
																			(yyval._expression).type = (yyval._expression).symTPtr->type;
																			int l = 0;
																			int k = 2;
																			for(int i=0;i<10;++i) {
																				int l = 0;
																			}
																			if(k) {
																				for(int i=0;i<10;++i) {
																					int k;
																				}
																			}
																			else{
																				int o;
																			}
																			globalQuadArray.emit(Q_LOG_AND,(yyvsp[-2]._expression).symTPtr->name,(yyvsp[0]._expression).symTPtr->name,(yyval._expression).symTPtr->name);
																			for(int l=0;l<10;++l) {
																				int pp = 0;
																			}
																			if(1) {
																				for(int m=0;m<10;++m) {
																					int k;
																				}
																			}
																			else{
																				int n;
																			}
																		}
#line 3528 "y.tab.c"
    break;

  case 57: /* exclusive_OR_expression: AND_expression  */
#line 1607 "ass6_18CS10033_18CS30036.y"
                                               {
													(yyval._expression) = (yyvsp[0]._expression);
											   }
#line 3536 "y.tab.c"
    break;

  case 58: /* exclusive_OR_expression: exclusive_OR_expression '^' AND_expression  */
#line 1610 "ass6_18CS10033_18CS30036.y"
                                                                                                           {
																				(yyval._expression).symTPtr = currentSymbolTable->gentemp((yyvsp[-2]._expression).type);
																				(yyval._expression).type = (yyval._expression).symTPtr->type;
																				int l = 0;
																				int k = 2;
																				for(int i=0;i<10;++i) {
																					int l = 0;
																				}
																				if(k) {
																					for(int i=0;i<10;++i) {
																						int k;
																					}
																				}
																				else{
																					int o;
																				}
																				globalQuadArray.emit(Q_XOR,(yyvsp[-2]._expression).symTPtr->name,(yyvsp[0]._expression).symTPtr->name,(yyval._expression).symTPtr->name);
																		   }
#line 3559 "y.tab.c"
    break;

  case 59: /* inclusive_OR_expression: exclusive_OR_expression  */
#line 1629 "ass6_18CS10033_18CS30036.y"
                                                        {
															(yyval._expression) = (yyvsp[0]._expression);
														}
#line 3567 "y.tab.c"
    break;

  case 60: /* inclusive_OR_expression: inclusive_OR_expression '|' exclusive_OR_expression  */
#line 1632 "ass6_18CS10033_18CS30036.y"
                                                                                                                    {
																						(yyval._expression).symTPtr = currentSymbolTable->gentemp((yyvsp[-2]._expression).type);
																						(yyval._expression).type = (yyval._expression).symTPtr->type;
																						int l = 0;
																						int k = 2;
																						for(int i=0;i<10;++i) {
																							int l = 0;
																						}
																						if(k) {
																							for(int i=0;i<10;++i) {
																								int k;
																							}
																						}
																						else{
																							int o;
																						}
																						globalQuadArray.emit(Q_LOG_OR,(yyvsp[-2]._expression).symTPtr->name,(yyvsp[0]._expression).symTPtr->name,(yyval._expression).symTPtr->name);
																					}
#line 3590 "y.tab.c"
    break;

  case 61: /* logical_AND_expression: inclusive_OR_expression  */
#line 1651 "ass6_18CS10033_18CS30036.y"
                                                        {
															(yyval._expression) = (yyvsp[0]._expression);
														}
#line 3598 "y.tab.c"
    break;

  case 62: /* logical_AND_expression: logical_AND_expression AND M inclusive_OR_expression  */
#line 1654 "ass6_18CS10033_18CS30036.y"
                                                                                                                     {
																						if((yyvsp[-3]._expression).type->type != tp_bool)
																							CONV2BOOL(&(yyvsp[-3]._expression));
																						if((yyvsp[0]._expression).type->type != tp_bool)
																							CONV2BOOL(&(yyvsp[0]._expression));
																						backpatch((yyvsp[-3]._expression).truelist,(yyvsp[-1]._instruction));
																						(yyval._expression).type = new symbolType(tp_bool);
																						int l = 0;
																						int k = 2;
																						for(int i=0;i<10;++i) {
																							int l = 0;
																						}
																						if(k) {
																							for(int i=0;i<10;++i) {
																								int k;
																							}
																						}
																						else{
																							int o;
																						}
																						(yyval._expression).falselist = merge((yyvsp[-3]._expression).falselist,(yyvsp[0]._expression).falselist);
																						(yyval._expression).truelist = (yyvsp[0]._expression).truelist;
																					}
#line 3626 "y.tab.c"
    break;

  case 63: /* logical_OR_expression: logical_AND_expression  */
#line 1678 "ass6_18CS10033_18CS30036.y"
                                                       {
															(yyval._expression) = (yyvsp[0]._expression);
													   }
#line 3634 "y.tab.c"
    break;

  case 64: /* logical_OR_expression: logical_OR_expression OR M logical_AND_expression  */
#line 1681 "ass6_18CS10033_18CS30036.y"
                                                                                                                    {
																						if((yyvsp[-3]._expression).type->type != tp_bool)
																							CONV2BOOL(&(yyvsp[-3]._expression));
																						if((yyvsp[0]._expression).type->type != tp_bool)
																							CONV2BOOL(&(yyvsp[0]._expression));
																						backpatch((yyvsp[-3]._expression).falselist,(yyvsp[-1]._instruction));
																						(yyval._expression).type = new symbolType(tp_bool);
																						int l = 0;
																						int k = 2;
																						for(int i=0;i<10;++i) {
																							int l = 0;
																						}
																						if(k) {
																							for(int i=0;i<10;++i) {
																								int k;
																							}
																						}
																						else{
																							int o;
																						}
																						(yyval._expression).truelist = merge((yyvsp[-3]._expression).truelist,(yyvsp[0]._expression).truelist);
																						(yyval._expression).falselist = (yyvsp[0]._expression).falselist;
																					}
#line 3662 "y.tab.c"
    break;

  case 65: /* conditional_expression: logical_OR_expression  */
#line 1706 "ass6_18CS10033_18CS30036.y"
                                                      {
															(yyval._expression) = (yyvsp[0]._expression);
													  }
#line 3670 "y.tab.c"
    break;

  case 66: /* conditional_expression: logical_OR_expression N '?' M expression N ':' M conditional_expression  */
#line 1709 "ass6_18CS10033_18CS30036.y"
                                                                                                                                        {
																											(yyval._expression).symTPtr = currentSymbolTable->gentemp((yyvsp[-4]._expression).type);
																											(yyval._expression).type = (yyval._expression).symTPtr->type;
																											globalQuadArray.emit(Q_ASSIGN,(yyvsp[0]._expression).symTPtr->name,(yyval._expression).symTPtr->name);
																											list* TEMP_LIST = makelist(nextInstruction);
																											globalQuadArray.emit(Q_GOTO,"-1");
																											int l = 0;
																											int k = 2;
																											for(int i=0;i<10;++i) {
																												int l = 0;
																											}
																											if(k) {
																												for(int i=0;i<10;++i) {
																													int k;
																												}
																											}
																											else{
																												int o;
																											}
																											backpatch((yyvsp[-3]._nextlist),nextInstruction);
																											globalQuadArray.emit(Q_ASSIGN,(yyvsp[-4]._expression).symTPtr->name,(yyval._expression).symTPtr->name);
																											TEMP_LIST = merge(TEMP_LIST,makelist(nextInstruction));
																											globalQuadArray.emit(Q_GOTO,"-1");
																											backpatch((yyvsp[-7]._nextlist),nextInstruction);
																											CONV2BOOL(&(yyvsp[-8]._expression));
																											backpatch((yyvsp[-8]._expression).truelist,(yyvsp[-5]._instruction));
																											backpatch((yyvsp[-8]._expression).falselist,(yyvsp[-1]._instruction));
																											backpatch(TEMP_LIST,nextInstruction);
																										}
#line 3704 "y.tab.c"
    break;

  case 78: /* assignment_expression: conditional_expression  */
#line 1751 "ass6_18CS10033_18CS30036.y"
                                                       {
															(yyval._expression) = (yyvsp[0]._expression);
														}
#line 3712 "y.tab.c"
    break;

  case 79: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 1754 "ass6_18CS10033_18CS30036.y"
                                                                                                                           {
																								//LDereferencing
																								//printf("hoboo --> %s\n",$1.symTPtr->name.c_str());
																								if((yyvsp[-2]._expression).isPointer)
																								{
																									//printf("Hookah bar\n");
																									int l = 0;
																									int k = 2;
																									for(int i=0;i<10;++i) {
																										int l = 0;
																									}
																									if(k) {
																										for(int i=0;i<10;++i) {
																											int k;
																										}
																									}
																									else{
																										int o;
																									}
																									globalQuadArray.emit(Q_LDEREF,(yyvsp[0]._expression).symTPtr->name,(yyvsp[-2]._expression).symTPtr->name);
																								}
																								typecheck(&(yyvsp[-2]._expression),&(yyvsp[0]._expression),true);
																								if((yyvsp[-2]._expression).arr != NULL)
																								{
																									int l = 0;
																									int k = 2;
																									for(int i=0;i<10;++i) {
																										int l = 0;
																									}
																									if(k) {
																										for(int i=0;i<10;++i) {
																											int k;
																										}
																									}
																									else{
																										int o;
																									}
																									globalQuadArray.emit(Q_LINDEX,(yyvsp[-2]._expression).symTPtr->name,(yyvsp[0]._expression).symTPtr->name,(yyvsp[-2]._expression).arr->name);
																								}
																								else if(!(yyvsp[-2]._expression).isPointer)
																									globalQuadArray.emit(Q_ASSIGN,(yyvsp[0]._expression).symTPtr->name,(yyvsp[-2]._expression).symTPtr->name);
																								(yyval._expression).symTPtr = currentSymbolTable->gentemp((yyvsp[0]._expression).type);
																								(yyval._expression).type = (yyval._expression).symTPtr->type;
																								//printf("assgi hobobob %s == %s\n",)
																								globalQuadArray.emit(Q_ASSIGN,(yyvsp[0]._expression).symTPtr->name,(yyval._expression).symTPtr->name);
																								int l = 0;
																								int k = 2;
																								for(int i=0;i<10;++i) {
																									int l = 0;
																								}
																								if(k) {
																									for(int i=0;i<10;++i) {
																										int k;
																									}
																								}
																								else{
																									int o;
																								}
																								//printf("assign %s = %s\n",$3.symTPtr->name.c_str(),$$.symTPtr->name.c_str());
																							}
#line 3777 "y.tab.c"
    break;

  case 80: /* constant_expression: conditional_expression  */
#line 1816 "ass6_18CS10033_18CS30036.y"
                                                       {
															(yyval._expression) = (yyvsp[0]._expression);
													   }
#line 3785 "y.tab.c"
    break;

  case 81: /* expression: assignment_expression  */
#line 1820 "ass6_18CS10033_18CS30036.y"
                                                      {
															(yyval._expression) = (yyvsp[0]._expression);
													  }
#line 3793 "y.tab.c"
    break;

  case 82: /* expression: expression ',' assignment_expression  */
#line 1823 "ass6_18CS10033_18CS30036.y"
                                                                                                     {
																		(yyval._expression) = (yyvsp[0]._expression);
																	 }
#line 3801 "y.tab.c"
    break;

  case 83: /* declaration: declaration_specifiers init_declarator_list_opt ';'  */
#line 1829 "ass6_18CS10033_18CS30036.y"
                                                                                    {
																						if((yyvsp[-1]._expression).symTPtr != NULL && (yyvsp[-1]._expression).type != NULL && (yyvsp[-1]._expression).type->type == tp_func)
																						{
																							/*Delete currentSymbolTable*/
																							int l = 0;
																							int k = 2;
																							for(int i=0;i<10;++i) {
																								int l = 0;
																							}
																							if(k) {
																								for(int i=0;i<10;++i) {
																									int k;
																								}
																							}
																							else{
																								int o;
																							}
																							currentSymbolTable = new symbolTable();
																						}
																					}
#line 3826 "y.tab.c"
    break;

  case 84: /* init_declarator_list_opt: init_declarator_list  */
#line 1850 "ass6_18CS10033_18CS30036.y"
                                                     {
														if((yyvsp[0]._expression).type != NULL && (yyvsp[0]._expression).type->type == tp_func)
														{
															(yyval._expression) = (yyvsp[0]._expression);
															int l = 0;
															int k = 2;
															for(int i=0;i<10;++i) {
																int l = 0;
															}
															if(k) {
																for(int i=0;i<10;++i) {
																	int k;
																}
															}
															else{
																int o;
															}
														}
													 }
#line 3850 "y.tab.c"
    break;

  case 85: /* init_declarator_list_opt: %empty  */
#line 1869 "ass6_18CS10033_18CS30036.y"
                                                                            {
												(yyval._expression).symTPtr = NULL;
											}
#line 3858 "y.tab.c"
    break;

  case 86: /* declaration_specifiers: storage_class_specifier declaration_specifiers_opt  */
#line 1873 "ass6_18CS10033_18CS30036.y"
                                                                                   {}
#line 3864 "y.tab.c"
    break;

  case 88: /* declaration_specifiers: type_qualifier declaration_specifiers_opt  */
#line 1875 "ass6_18CS10033_18CS30036.y"
                                                                                                          {}
#line 3870 "y.tab.c"
    break;

  case 89: /* declaration_specifiers: function_specifier declaration_specifiers_opt  */
#line 1876 "ass6_18CS10033_18CS30036.y"
                                                                                                              {}
#line 3876 "y.tab.c"
    break;

  case 92: /* init_declarator_list: init_declarator  */
#line 1881 "ass6_18CS10033_18CS30036.y"
                                                {
													/*Expecting only function declaration*/
													(yyval._expression) = (yyvsp[0]._expression);
													int l = 0;
													int k = 2;
													for(int i=0;i<10;++i) {
														int l = 0;
													}
													if(k) {
														for(int i=0;i<10;++i) {
															int k;
														}
													}
													else{
														int o;
													}
												}
#line 3898 "y.tab.c"
    break;

  case 94: /* init_declarator: declarator  */
#line 1900 "ass6_18CS10033_18CS30036.y"
                                           {
												/*Nothing to be done here*/
												if((yyvsp[0]._expression).type != NULL && (yyvsp[0]._expression).type->type == tp_func)
												{
													(yyval._expression) = (yyvsp[0]._expression);
													int l = 0;
													int k = 2;
													for(int i=0;i<10;++i) {
														int l = 0;
													}
													if(k) {
														for(int i=0;i<10;++i) {
															int k;
														}
													}
													else{
														int o;
													}
												}
											}
#line 3923 "y.tab.c"
    break;

  case 95: /* init_declarator: declarator '=' initializer  */
#line 1920 "ass6_18CS10033_18CS30036.y"
                                                                                           {
																//initializations of declarators
																if((yyvsp[0]._expression).type!=NULL)
																{
																if((yyvsp[0]._expression).type->type==tp_int)
																{
																	(yyvsp[-2]._expression).symTPtr->_init_val._INT_INITVAL= (yyvsp[0]._expression).symTPtr->_init_val._INT_INITVAL;
																	(yyvsp[-2]._expression).symTPtr->isInitialized = true;
																	int l = 0;
																	int k = 2;
																	for(int i=0;i<10;++i) {
																		int l = 0;
																	}
																	if(k) {
																		for(int i=0;i<10;++i) {
																			int k;
																		}
																	}
																	else{
																		int o;
																	}
																	symbol *temp_ver=currentSymbolTable->search((yyvsp[-2]._expression).symTPtr->name);
																	if(temp_ver!=NULL)
																	{
																	//printf("po %s = %s\n",$1.symTPtr->name.c_str(),$3.symTPtr->name.c_str());
																	temp_ver->_init_val._INT_INITVAL= (yyvsp[0]._expression).symTPtr->_init_val._INT_INITVAL;
																	int l = 0;
																	int k = 2;
																	for(int i=0;i<10;++i) {
																		int l = 0;
																	}
																	if(k) {
																		for(int i=0;i<10;++i) {
																			int k;
																		}
																	}
																	else{
																		int o;
																	}
																	temp_ver->isInitialized = true;
																	}
																}
																else if((yyvsp[0]._expression).type->type==tp_char)
																{
																	(yyvsp[-2]._expression).symTPtr->_init_val._CHAR_INITVAL= (yyvsp[0]._expression).symTPtr->_init_val._CHAR_INITVAL;
																	(yyvsp[-2]._expression).symTPtr->isInitialized = true;
																	int l = 0;
																	int k = 2;
																	for(int i=0;i<10;++i) {
																		int l = 0;
																	}
																	if(k) {
																		for(int i=0;i<10;++i) {
																			int k;
																		}
																	}
																	else{
																		int o;
																	}
																	symbol *temp_ver=currentSymbolTable->search((yyvsp[-2]._expression).symTPtr->name);
																	if(temp_ver!=NULL)
																	{temp_ver->_init_val._CHAR_INITVAL= (yyvsp[0]._expression).symTPtr->_init_val._CHAR_INITVAL;
																		temp_ver->isInitialized = true;
																	}
																}
																}
																//printf("%s = %s\n",$1.symTPtr->name.c_str(),$3.symTPtr->name.c_str());
																//typecheck(&$1,&$3,true);
																globalQuadArray.emit(Q_ASSIGN,(yyvsp[0]._expression).symTPtr->name,(yyvsp[-2]._expression).symTPtr->name);
															}
#line 3998 "y.tab.c"
    break;

  case 96: /* storage_class_specifier: EXTERN  */
#line 1991 "ass6_18CS10033_18CS30036.y"
                                       {}
#line 4004 "y.tab.c"
    break;

  case 97: /* storage_class_specifier: STATIC  */
#line 1992 "ass6_18CS10033_18CS30036.y"
                                                                       {}
#line 4010 "y.tab.c"
    break;

  case 98: /* type_specifier: VOID  */
#line 1994 "ass6_18CS10033_18CS30036.y"
                                     {
										globalType = new symbolType(tp_void);
									}
#line 4018 "y.tab.c"
    break;

  case 99: /* type_specifier: CHAR  */
#line 1997 "ass6_18CS10033_18CS30036.y"
                                                                     {
										globalType = new symbolType(tp_char);
									}
#line 4026 "y.tab.c"
    break;

  case 100: /* type_specifier: SHORT  */
#line 2000 "ass6_18CS10033_18CS30036.y"
                                                                      {}
#line 4032 "y.tab.c"
    break;

  case 101: /* type_specifier: INT  */
#line 2001 "ass6_18CS10033_18CS30036.y"
                                                                    {
										globalType = new symbolType(tp_int);
									}
#line 4040 "y.tab.c"
    break;

  case 102: /* type_specifier: LONG  */
#line 2004 "ass6_18CS10033_18CS30036.y"
                                                                     {}
#line 4046 "y.tab.c"
    break;

  case 103: /* type_specifier: FLOAT  */
#line 2005 "ass6_18CS10033_18CS30036.y"
                                                                      {}
#line 4052 "y.tab.c"
    break;

  case 104: /* type_specifier: DOUBLE  */
#line 2006 "ass6_18CS10033_18CS30036.y"
                                                                       {
											globalType = new symbolType(tp_double);
										}
#line 4060 "y.tab.c"
    break;

  case 105: /* specifier_qualifier_list: type_specifier specifier_qualifier_list_opt  */
#line 2010 "ass6_18CS10033_18CS30036.y"
                                                                            {
																				/*----------*/
																			}
#line 4068 "y.tab.c"
    break;

  case 106: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list_opt  */
#line 2013 "ass6_18CS10033_18CS30036.y"
                                                                                                            {}
#line 4074 "y.tab.c"
    break;

  case 107: /* specifier_qualifier_list_opt: specifier_qualifier_list  */
#line 2015 "ass6_18CS10033_18CS30036.y"
                                                         {}
#line 4080 "y.tab.c"
    break;

  case 108: /* specifier_qualifier_list_opt: %empty  */
#line 2016 "ass6_18CS10033_18CS30036.y"
                                                                            {}
#line 4086 "y.tab.c"
    break;

  case 109: /* type_qualifier: CONST  */
#line 2019 "ass6_18CS10033_18CS30036.y"
                                      {}
#line 4092 "y.tab.c"
    break;

  case 110: /* type_qualifier: RESTRICT  */
#line 2020 "ass6_18CS10033_18CS30036.y"
                                                                         {}
#line 4098 "y.tab.c"
    break;

  case 111: /* type_qualifier: VOLATILE  */
#line 2021 "ass6_18CS10033_18CS30036.y"
                                                                         {}
#line 4104 "y.tab.c"
    break;

  case 112: /* function_specifier: INLINE  */
#line 2023 "ass6_18CS10033_18CS30036.y"
                                       {}
#line 4110 "y.tab.c"
    break;

  case 113: /* declarator: pointer_opt direct_declarator  */
#line 2025 "ass6_18CS10033_18CS30036.y"
                                                              {
																if((yyvsp[-1]._declarator).type == NULL)
																{
																	/*--------------*/
																	int l = 0;
																	int k = 2;
																	for(int i=0;i<10;++i) {
																		int l = 0;
																	}
																	if(k) {
																		for(int i=0;i<10;++i) {
																			int k;
																		}
																	}
																	else{
																		int o;
																	}
																}
																else
																{
																	if((yyvsp[0]._expression).symTPtr->type->type != tp_ptr)
																	{
																		symbolType * test = (yyvsp[-1]._declarator).type;

																		int k = 2;
																		for(int i=0;i<10;++i) {
																			int l = 0;
																		}
																		if(k) {
																			for(int i=0;i<10;++i) {
																				int k;
																			}
																		}
																		else{
																			int o;
																		}
																		while(test->next != NULL)
																		{
																			test = test->next;
																		}
																		test->next = (yyvsp[0]._expression).symTPtr->type;
																		(yyvsp[0]._expression).symTPtr->type = (yyvsp[-1]._declarator).type;
																	}
																}

																if((yyvsp[0]._expression).type != NULL && (yyvsp[0]._expression).type->type == tp_func)
																{
																	(yyval._expression) = (yyvsp[0]._expression);
																}
																else
																{
																	//its not a function
																	(yyvsp[0]._expression).symTPtr->width = (yyvsp[0]._expression).symTPtr->type->sizeOfType();
																	for(int l=0;l<10;++l) {
																		int pp = 0;
																	}
																	if(1) {
																		for(int m=0;m<10;++m) {
																			int k;
																		}
																	}
																	else{
																		int n;
																	}
																	(yyvsp[0]._expression).symTPtr->offset = currentSymbolTable->offset;
																	currentSymbolTable->offset += (yyvsp[0]._expression).symTPtr->width;
																	int l = 0;
																	int k = 2;
																	for(int i=0;i<10;++i) {
																		int l = 0;
																	}
																	if(k) {
																		for(int i=0;i<10;++i) {
																			int k;
																		}
																	}
																	else{
																		int o;
																	}
																	(yyval._expression) = (yyvsp[0]._expression);
																	(yyval._expression).type = (yyval._expression).symTPtr->type;
																}
															}
#line 4198 "y.tab.c"
    break;

  case 114: /* pointer_opt: pointer  */
#line 2109 "ass6_18CS10033_18CS30036.y"
                                        {
											(yyval._declarator) = (yyvsp[0]._declarator);
										}
#line 4206 "y.tab.c"
    break;

  case 115: /* pointer_opt: %empty  */
#line 2112 "ass6_18CS10033_18CS30036.y"
                                                                            {
												(yyval._declarator).type = NULL;
											}
#line 4214 "y.tab.c"
    break;

  case 116: /* direct_declarator: IDENTIFIER  */
#line 2116 "ass6_18CS10033_18CS30036.y"
                                           {
													(yyval._expression).symTPtr = currentSymbolTable->lookup(*(yyvsp[0]._identifier).name);
													for(int l=0;l<10;++l) {
														int pp = 0;
													}
													if(1) {
														for(int m=0;m<10;++m) {
															int k;
														}
													}
													else{
														int n;
													}
													//printf("name: %s\n",currentSymbolTable->name.c_str());
													//printf("2nd %s\n",(*$1.name).c_str());
													int l = 0;
													int k = 2;
													for(int i=0;i<10;++i) {
														int l = 0;
													}
													if(k) {
														for(int i=0;i<10;++i) {
															int k;
														}
													}
													else{
														int o;
													}
													//printf("Hello5\n");
													if((yyval._expression).symTPtr->var_type == "")
													{
														//Type initialization
														int l = 0;
														int k = 2;
														for(int i=0;i<10;++i) {
															int l = 0;
														}
														if(k) {
															for(int i=0;i<10;++i) {
																int k;
															}
														}
														else{
															int o;
														}
														(yyval._expression).symTPtr->var_type = "local";
														(yyval._expression).symTPtr->type = new symbolType(globalType->type);
														//$$.symTPtr->type->print();
													}
													(yyval._expression).type = (yyval._expression).symTPtr->type;
											}
#line 4270 "y.tab.c"
    break;

  case 117: /* direct_declarator: '(' declarator ')'  */
#line 2167 "ass6_18CS10033_18CS30036.y"
                                                                                   {
														(yyval._expression) = (yyvsp[-1]._expression);
													}
#line 4278 "y.tab.c"
    break;

  case 118: /* direct_declarator: direct_declarator '[' type_qualifier_list_opt assignment_expression_opt ']'  */
#line 2170 "ass6_18CS10033_18CS30036.y"
                                                                                                                                            {
																												//printf("Hello\n");
																												if((yyvsp[-4]._expression).type->type == tp_arr)
																												{
																													/*if type is already an arr*/
																													symbolType * typ1 = (yyvsp[-4]._expression).type,*typ = (yyvsp[-4]._expression).type;
																													typ1 = typ1->next;
																													int l = 0;
																													int k = 2;
																													for(int i=0;i<10;++i) {
																														int l = 0;
																													}
																													if(k) {
																														for(int i=0;i<10;++i) {
																															int k;
																														}
																													}
																													else{
																														int o;
																													}
																													while(typ1->next != NULL)
																													{
																														typ1 = typ1->next;
																														typ = typ->next;
																													}
																													typ->next = new symbolType(tp_arr,(yyvsp[-1]._expression).symTPtr->_init_val._INT_INITVAL,typ1);
																												}
																												else
																												{
																													for(int l=0;l<10;++l) {
																														int pp = 0;
																													}
																													if(1) {
																														for(int m=0;m<10;++m) {
																															int k;
																														}
																													}
																													else{
																														int n;
																													}
																													//add the type of array to list
																													int l = 0;
																													int k = 2;
																													for(int i=0;i<10;++i) {
																														int l = 0;
																													}
																													if(k) {
																														for(int i=0;i<10;++i) {
																															int k;
																														}
																													}
																													else{
																														int o;
																													}
																													if((yyvsp[-1]._expression).symTPtr == NULL)
																														(yyvsp[-4]._expression).type = new symbolType(tp_arr,-1,(yyvsp[-4]._expression).type);
																													else
																														(yyvsp[-4]._expression).type = new symbolType(tp_arr,(yyvsp[-1]._expression).symTPtr->_init_val._INT_INITVAL,(yyvsp[-4]._expression).type);
																												}
																												(yyval._expression) = (yyvsp[-4]._expression);
																												(yyval._expression).symTPtr->type = (yyval._expression).type;
																											}
#line 4345 "y.tab.c"
    break;

  case 119: /* direct_declarator: direct_declarator '[' STATIC type_qualifier_list_opt assignment_expression ']'  */
#line 2232 "ass6_18CS10033_18CS30036.y"
                                                                                                                                               {}
#line 4351 "y.tab.c"
    break;

  case 120: /* direct_declarator: direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'  */
#line 2233 "ass6_18CS10033_18CS30036.y"
                                                                                                                                           {}
#line 4357 "y.tab.c"
    break;

  case 121: /* direct_declarator: direct_declarator '[' type_qualifier_list_opt '*' ']'  */
#line 2234 "ass6_18CS10033_18CS30036.y"
                                                                                                                      {/*Not sure but mostly we don't have to implement this*/}
#line 4363 "y.tab.c"
    break;

  case 122: /* direct_declarator: direct_declarator '(' parameter_type_list ')'  */
#line 2235 "ass6_18CS10033_18CS30036.y"
                                                                                                              {
																				   int params_no=currentSymbolTable->emptyArgList;
																				   //printf("no.ofparameters-->%d\n",params_no);
																				   currentSymbolTable->emptyArgList=0;
																				   int dec_params=0;
																				   int l = 0;
																					int k = 2;
																					for(int i=0;i<10;++i) {
																						int l = 0;
																					}
																					if(k) {
																						for(int i=0;i<10;++i) {
																							int k;
																						}
																					}
																					else{
																						int o;
																					}
																				   int over_params=params_no;
																				   for(int i=currentSymbolTable->symbolTabList.size()-1;i>=0;i--)
																				   {
																						//printf("what-->%s\n",currentSymbolTable->symbolTabList[i]->name.c_str());
																					}
																				   for(int i=currentSymbolTable->symbolTabList.size()-1;i>=0;i--)
																				   {
																						//printf("mazaknaminST-->%s\n",currentSymbolTable->symbolTabList[i]->name.c_str());
																						string detect=currentSymbolTable->symbolTabList[i]->name;
																						if(over_params==0)
																						{
																							int l = 0;
																							int k = 2;
																							for(int i=0;i<10;++i) {
																								int l = 0;
																							}
																							if(k) {
																								for(int i=0;i<10;++i) {
																									int k;
																								}
																							}
																							else{
																								int o;
																							}
																							break;
																						}
																						if(detect.size()==4)
																						{
																							if(detect[0]=='t')
																							{
																								int l = 0;
																								int k = 2;
																								for(int i=0;i<10;++i) {
																									int l = 0;
																								}
																								if(k) {
																									for(int i=0;i<10;++i) {
																										int k;
																									}
																								}
																								else{
																									int o;
																								}
																								if('0'<=detect[1]&&detect[1]<='9')
																								{
																									if('0'<=detect[2]&&detect[2]<='9')
																									{
																										if('0'<=detect[3]&&detect[3]<='9')
																											dec_params++;
																									}
																								}
																							}
																						}
																						else
																							over_params--;

																				   }
																				   params_no+=dec_params;
																				   //printf("no.ofparameters-->%d\n",params_no);
																				   int temp_i=currentSymbolTable->symbolTabList.size()-params_no;
																				   symbol * new_func = globalSymbolTable->search(currentSymbolTable->symbolTabList[temp_i-1]->name);
																					//printf("Hello1\n");
																					for(int i=0;i<10;++i) {
																						int l = 0;
																					}
																					if(k) {
																						for(int i=0;i<10;++i) {
																							int k;
																						}
																					}
																					else{
																						int o;
																					}
																					//printf("%s\n",currentSymbolTable->symbolTabList[0]->name.c_str());
																					//printf("no. of params-> %d\n",currentSymbolTable->emptyArgList);
																					if(new_func == NULL)
																					{
																						new_func = globalSymbolTable->lookup(currentSymbolTable->symbolTabList[temp_i-1]->name);
																						(yyval._expression).symTPtr = currentSymbolTable->symbolTabList[temp_i-1];
																						int l = 0;
																						int k = 2;
																						for(int i=0;i<10;++i) {
																							int l = 0;
																						}
																						if(k) {
																							for(int i=0;i<10;++i) {
																								int k;
																							}
																						}
																						else{
																							int o;
																						}
																						for(int i=0;i<(temp_i-1);i++)
																						{
																							currentSymbolTable->symbolTabList[i]->isValid=false;
																							if(currentSymbolTable->symbolTabList[i]->var_type=="local"||currentSymbolTable->symbolTabList[i]->var_type=="temp")
																							{
																								symbol *glob_var=globalSymbolTable->search(currentSymbolTable->symbolTabList[i]->name);
																								if(glob_var==NULL)
																								{
																									//printf("glob_var-->%s\n",currentSymbolTable->symbolTabList[i]->name.c_str());
																									for(int l=0;l<10;++l) {
																										int pp = 0;
																									}
																									if(1) {
																										for(int m=0;m<10;++m) {
																											int k;
																										}
																									}
																									else{
																										int n;
																									}
																									glob_var=globalSymbolTable->lookup(currentSymbolTable->symbolTabList[i]->name);
																									int t_size=currentSymbolTable->symbolTabList[i]->type->sizeOfType();
																									glob_var->offset=globalSymbolTable->offset;
																									glob_var->width=t_size;
																									globalSymbolTable->offset+=t_size;
																									int l = 0;
																									int k = 2;
																									for(int i1=0;i1<10;++i1) {
																										int l = 0;
																									}
																									if(k) {
																										for(int i1=0;i1<10;++i1) {
																											int k;
																										}
																									}
																									else{
																										int o;
																									}
																									glob_var->nested=globalSymbolTable;
																									glob_var->var_type=currentSymbolTable->symbolTabList[i]->var_type;
																									glob_var->type=currentSymbolTable->symbolTabList[i]->type;
																									if(currentSymbolTable->symbolTabList[i]->isInitialized)
																									{
																										glob_var->isInitialized=currentSymbolTable->symbolTabList[i]->isInitialized;
																										glob_var->_init_val=currentSymbolTable->symbolTabList[i]->_init_val;
																										int l = 0;
																										int k = 2;
																										for(int i2=0;i2<10;++i2) {
																											int l = 0;
																										}
																										if(k) {
																											for(int i2=0;i2<10;++i2) {
																												int k;
																											}
																										}
																										else{
																											int o;
																										}
																									}

																								}
																							}
																						}
																						if(new_func->var_type == "")
																						{
																							// Declaration of the function for the first time
																							new_func->type = CopyType(currentSymbolTable->symbolTabList[temp_i-1]->type);
																							for(int l=0;l<10;++l) {
																								int pp = 0;
																							}
																							if(1) {
																								for(int m=0;m<10;++m) {
																									int k;
																								}
																							}
																							else{
																								int n;
																							}
																							new_func->var_type = "func";
																							new_func->isInitialized = false;
																							new_func->nested = currentSymbolTable;
																							int l = 0;
																							int k = 2;
																							for(int i=0;i<10;++i) {
																								int l = 0;
																							}
																							if(k) {
																								for(int i=0;i<10;++i) {
																									int k;
																								}
																							}
																							else{
																								int o;
																							}
																							currentSymbolTable->name = currentSymbolTable->symbolTabList[temp_i-1]->name;
																							//printf("naminST-->%s\n",currentSymbolTable->symbolTabList[temp_i-1]->name.c_str());
																							//printf("oye\n");
																							/*for(int i=0;i<currentSymbolTable->symbolTabList.size();i++)
																							{
																								printf("naminST-->%s\n",currentSymbolTable->symbolTabList[i]->name.c_str());
																							}*/
																							currentSymbolTable->symbolTabList[temp_i-1]->name = "retVal";
																							currentSymbolTable->symbolTabList[temp_i-1]->var_type = "return";
																							currentSymbolTable->symbolTabList[temp_i-1]->width = currentSymbolTable->symbolTabList[temp_i-1]->type->sizeOfType();
																							currentSymbolTable->symbolTabList[temp_i-1]->offset = 0;
																							currentSymbolTable->offset = 16;
																							int count=0;
																							for(int i=(currentSymbolTable->symbolTabList.size())-params_no;i<currentSymbolTable->symbolTabList.size();i++)
																							{
																								//printf("%s -> %s\n",currentSymbolTable->symbolTabList[i]->name.c_str(),currentSymbolTable->symbolTabList[i]->var_type.c_str());
																								currentSymbolTable->symbolTabList[i]->var_type = "param";
																								currentSymbolTable->symbolTabList[i]->offset = count- currentSymbolTable->symbolTabList[i]->width;
																								count=count-currentSymbolTable->symbolTabList[i]->width;
																							}
																						}
																					}
																					else
																					{
																						currentSymbolTable = new_func->nested;
																						int l = 0;
																						int k = 2;
																						for(int i=0;i<10;++i) {
																							int l = 0;
																						}
																						if(k) {
																							for(int i=0;i<10;++i) {
																								int k;
																							}
																						}
																						else{
																							int o;
																						}
																					}
																					currentSymbolTable->initQuad = nextInstruction;
																					(yyval._expression).symTPtr = new_func;
																					(yyval._expression).type = new symbolType(tp_func);
																				}
#line 4615 "y.tab.c"
    break;

  case 123: /* direct_declarator: direct_declarator '(' identifier_list_opt ')'  */
#line 2482 "ass6_18CS10033_18CS30036.y"
                                                                                                              {
																				int temp_i=currentSymbolTable->symbolTabList.size();
																				symbol * new_func = globalSymbolTable->search(currentSymbolTable->symbolTabList[temp_i-1]->name);
																				//printf("Hello3\n");
																				int l = 0;
																				int k = 2;
																				for(int i=0;i<10;++i) {
																					int l = 0;
																				}
																				if(k) {
																					for(int i=0;i<10;++i) {
																						int k;
																					}
																				}
																				else{
																					int o;
																				}
																				//printf("globalSymbolTable %s\n",currentSymbolTable->symbolTabList[temp_i-1]->name.c_str());
																				//printf("symbol_tabsize %d\n",currentSymbolTable->symbolTabList.size());
																				/*if(currentSymbolTable->symbolTabList.size()>2)
																				{
																					//printf("Namestarted\n");
																					printf("%s\n",currentSymbolTable->symbolTabList[0]->name.c_str());
																					int l = 0;
																					int k = 2;
																					for(int i=0;i<10;++i) {
																						int l = 0;
																					}
																					if(k) {
																						for(int i=0;i<10;++i) {
																							int k;
																						}
																					}
																					else{
																						int o;
																					}
																					printf("%s\n",currentSymbolTable->symbolTabList[1]->name.c_str());
																					printf("%s\n",currentSymbolTable->symbolTabList[2]->name.c_str());
																				}*/
																				if(new_func == NULL)
																				{
																					for(int l=0;l<10;++l) {
																						int pp = 0;
																					}
																					if(1) {
																						for(int m=0;m<10;++m) {
																							int k;
																						}
																					}
																					else{
																						int n;
																					}
																					new_func = globalSymbolTable->lookup(currentSymbolTable->symbolTabList[temp_i-1]->name);
																					(yyval._expression).symTPtr = currentSymbolTable->symbolTabList[temp_i-1];
																					int l = 0;
																					int k = 2;
																					for(int i=0;i<10;++i) {
																						int l = 0;
																					}
																					if(k) {
																						for(int i=0;i<10;++i) {
																							int k;
																						}
																					}
																					else{
																						int o;
																					}
																					for(int i=0;i<temp_i-1;i++)
																					{
																						currentSymbolTable->symbolTabList[i]->isValid=false;
																						if(currentSymbolTable->symbolTabList[i]->var_type=="local"||currentSymbolTable->symbolTabList[i]->var_type=="temp")
																						{
																							symbol *glob_var=globalSymbolTable->search(currentSymbolTable->symbolTabList[i]->name);
																							if(glob_var==NULL)
																							{
																								//printf("glob_var-->%s\n",currentSymbolTable->symbolTabList[i]->name.c_str());
																								glob_var=globalSymbolTable->lookup(currentSymbolTable->symbolTabList[i]->name);
																								int t_size=currentSymbolTable->symbolTabList[i]->type->sizeOfType();
																								for(int l=0;l<10;++l) {
																									int pp = 0;
																								}
																								if(1) {
																									for(int m=0;m<10;++m) {
																										int k;
																									}
																								}
																								else{
																									int n;
																								}
																								glob_var->offset=globalSymbolTable->offset;
																								glob_var->width=t_size;
																								globalSymbolTable->offset+=t_size;
																								int l = 0;
																								int k = 2;
																								for(int i3=0;i3<10;++i3) {
																									int l = 0;
																								}
																								if(k) {
																									for(int i3=0;i3<10;++i3) {
																										int k;
																									}
																								}
																								else{
																									int o;
																								}
																								glob_var->nested=globalSymbolTable;
																								glob_var->var_type=currentSymbolTable->symbolTabList[i]->var_type;
																								glob_var->type=currentSymbolTable->symbolTabList[i]->type;
																								if(currentSymbolTable->symbolTabList[i]->isInitialized)
																								{
																									glob_var->isInitialized=currentSymbolTable->symbolTabList[i]->isInitialized;
																									glob_var->_init_val=currentSymbolTable->symbolTabList[i]->_init_val;
																								}
																							}
																						}
																					}
																					if(new_func->var_type == "")
																					{
																						/*Function is being declared here for the first time*/
																						new_func->type = CopyType(currentSymbolTable->symbolTabList[temp_i-1]->type);
																						new_func->var_type = "func";
																						new_func->isInitialized = false;
																						new_func->nested = currentSymbolTable;
																						int l = 0;
																						int k = 2;
																						for(int i=0;i<10;++i) {
																							int l = 0;
																						}
																						if(k) {
																							for(int i=0;i<10;++i) {
																								int k;
																							}
																						}
																						else{
																							int o;
																						}
																						/*Change the first element to retval and change the rest to param*/
																						currentSymbolTable->name = currentSymbolTable->symbolTabList[temp_i-1]->name;
																						currentSymbolTable->symbolTabList[temp_i-1]->name = "retVal";
																						currentSymbolTable->symbolTabList[temp_i-1]->var_type = "return";
																						currentSymbolTable->symbolTabList[temp_i-1]->width = currentSymbolTable->symbolTabList[0]->type->sizeOfType();
																						currentSymbolTable->symbolTabList[temp_i-1]->offset = 0;
																						currentSymbolTable->offset = 16;
																					}
																				}
																				else
																				{
																					// Already declared function. Therefore drop the new table and connect current symbol table pointer to the previously created funciton symbol table
																					currentSymbolTable = new_func->nested;
																					int l = 0;
																					int k = 2;
																					for(int i=0;i<10;++i) {
																						int l = 0;
																					}
																					if(k) {
																						for(int i=0;i<10;++i) {
																							int k;
																						}
																					}
																					else{
																						int o;
																					}
																				}
																				currentSymbolTable->initQuad = nextInstruction;
																				(yyval._expression).symTPtr = new_func;
																				for(int l=0;l<10;++l) {
																					int pp = 0;
																				}
																				if(1) {
																					for(int m=0;m<10;++m) {
																						int k;
																					}
																				}
																				else{
																					int n;
																				}
																				(yyval._expression).type = new symbolType(tp_func);
																			}
#line 4798 "y.tab.c"
    break;

  case 124: /* type_qualifier_list_opt: type_qualifier_list  */
#line 2661 "ass6_18CS10033_18CS30036.y"
                                                    {}
#line 4804 "y.tab.c"
    break;

  case 125: /* type_qualifier_list_opt: %empty  */
#line 2662 "ass6_18CS10033_18CS30036.y"
                                                                            {}
#line 4810 "y.tab.c"
    break;

  case 126: /* assignment_expression_opt: assignment_expression  */
#line 2664 "ass6_18CS10033_18CS30036.y"
                                                      {
															(yyval._expression) = (yyvsp[0]._expression);
														}
#line 4818 "y.tab.c"
    break;

  case 127: /* assignment_expression_opt: %empty  */
#line 2667 "ass6_18CS10033_18CS30036.y"
                                                                            {
												(yyval._expression).symTPtr = NULL;
												int l = 0;
												int k = 2;
												for(int i=0;i<10;++i) {
													int l = 0;
												}
												if(k) {
													for(int i=0;i<10;++i) {
														int k;
													}
												}
												else{
													int o;
												}
											}
#line 4839 "y.tab.c"
    break;

  case 130: /* pointer: '*' type_qualifier_list_opt  */
#line 2687 "ass6_18CS10033_18CS30036.y"
                                                            {
																(yyval._declarator).type = new symbolType(tp_ptr);
															}
#line 4847 "y.tab.c"
    break;

  case 131: /* pointer: '*' type_qualifier_list_opt pointer  */
#line 2690 "ass6_18CS10033_18CS30036.y"
                                                                                                    {
																		(yyval._declarator).type = new symbolType(tp_ptr,1,(yyvsp[0]._declarator).type);
																	}
#line 4855 "y.tab.c"
    break;

  case 132: /* type_qualifier_list: type_qualifier  */
#line 2694 "ass6_18CS10033_18CS30036.y"
                                               {}
#line 4861 "y.tab.c"
    break;

  case 133: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 2695 "ass6_18CS10033_18CS30036.y"
                                                                                                   {}
#line 4867 "y.tab.c"
    break;

  case 134: /* parameter_type_list: parameter_list  */
#line 2697 "ass6_18CS10033_18CS30036.y"
                                               {
													/*-------*/
												}
#line 4875 "y.tab.c"
    break;

  case 135: /* parameter_type_list: parameter_list ',' ELLIPSIS  */
#line 2700 "ass6_18CS10033_18CS30036.y"
                                                                                            {}
#line 4881 "y.tab.c"
    break;

  case 136: /* parameter_list: parameter_declaration  */
#line 2702 "ass6_18CS10033_18CS30036.y"
                                                      {
															/*---------*/
															(currentSymbolTable->emptyArgList)++;
														}
#line 4890 "y.tab.c"
    break;

  case 137: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 2706 "ass6_18CS10033_18CS30036.y"
                                                                                                         {
																			/*------------*/
																			(currentSymbolTable->emptyArgList)++;
																		}
#line 4899 "y.tab.c"
    break;

  case 138: /* parameter_declaration: declaration_specifiers declarator  */
#line 2711 "ass6_18CS10033_18CS30036.y"
                                                                  {
																		/*The parameter is already added to the current Symbol Table*/
																  }
#line 4907 "y.tab.c"
    break;

  case 139: /* parameter_declaration: declaration_specifiers  */
#line 2714 "ass6_18CS10033_18CS30036.y"
                                                                                       {}
#line 4913 "y.tab.c"
    break;

  case 143: /* initializer: assignment_expression  */
#line 2721 "ass6_18CS10033_18CS30036.y"
                                                      {
									(yyval._expression) = (yyvsp[0]._expression);
								}
#line 4921 "y.tab.c"
    break;

  case 144: /* initializer: '{' initializer_list '}'  */
#line 2724 "ass6_18CS10033_18CS30036.y"
                                                                                         {}
#line 4927 "y.tab.c"
    break;

  case 145: /* initializer: '{' initializer_list ',' '}'  */
#line 2725 "ass6_18CS10033_18CS30036.y"
                                                                                             {}
#line 4933 "y.tab.c"
    break;

  case 154: /* designator: '.' IDENTIFIER  */
#line 2739 "ass6_18CS10033_18CS30036.y"
                                                                               {}
#line 4939 "y.tab.c"
    break;

  case 155: /* statement: labeled_statement  */
#line 2742 "ass6_18CS10033_18CS30036.y"
                                                  {/*Switch Case*/}
#line 4945 "y.tab.c"
    break;

  case 156: /* statement: compound_statement  */
#line 2743 "ass6_18CS10033_18CS30036.y"
                                                                                   {
														(yyval._nextlist) = (yyvsp[0]._nextlist);
													}
#line 4953 "y.tab.c"
    break;

  case 157: /* statement: expression_statement  */
#line 2746 "ass6_18CS10033_18CS30036.y"
                                                                                     {
														(yyval._nextlist) = NULL;
													}
#line 4961 "y.tab.c"
    break;

  case 158: /* statement: selection_statement  */
#line 2749 "ass6_18CS10033_18CS30036.y"
                                                                                    {
														(yyval._nextlist) = (yyvsp[0]._nextlist);
													}
#line 4969 "y.tab.c"
    break;

  case 159: /* statement: iteration_statement  */
#line 2752 "ass6_18CS10033_18CS30036.y"
                                                                                    {
														(yyval._nextlist) = (yyvsp[0]._nextlist);
													}
#line 4977 "y.tab.c"
    break;

  case 160: /* statement: jump_statement  */
#line 2755 "ass6_18CS10033_18CS30036.y"
                                                                               {
													(yyval._nextlist) = (yyvsp[0]._nextlist);
													int l = 0;
													int k = 2;
													for(int i=0;i<10;++i) {
														int l = 0;
													}
													if(k) {
														for(int i=0;i<10;++i) {
															int k;
														}
													}
													else{
														int o;
													}
												}
#line 4998 "y.tab.c"
    break;

  case 161: /* labeled_statement: IDENTIFIER ':' statement  */
#line 2772 "ass6_18CS10033_18CS30036.y"
                                                         {}
#line 5004 "y.tab.c"
    break;

  case 162: /* labeled_statement: CASE constant_expression ':' statement  */
#line 2773 "ass6_18CS10033_18CS30036.y"
                                                                                                       {}
#line 5010 "y.tab.c"
    break;

  case 163: /* labeled_statement: DEFAULT ':' statement  */
#line 2774 "ass6_18CS10033_18CS30036.y"
                                                                                      {}
#line 5016 "y.tab.c"
    break;

  case 164: /* compound_statement: '{' block_item_list_opt '}'  */
#line 2776 "ass6_18CS10033_18CS30036.y"
                                                            {
																(yyval._nextlist) = (yyvsp[-1]._nextlist);
															}
#line 5024 "y.tab.c"
    break;

  case 165: /* block_item_list_opt: block_item_list  */
#line 2780 "ass6_18CS10033_18CS30036.y"
                                                {
													(yyval._nextlist) = (yyvsp[0]._nextlist);
												}
#line 5032 "y.tab.c"
    break;

  case 166: /* block_item_list_opt: %empty  */
#line 2783 "ass6_18CS10033_18CS30036.y"
                                                                            {
												(yyval._nextlist) = NULL;
												int l = 0;
												int k = 2;
												for(int i=0;i<10;++i) {
													int l = 0;
												}
												if(k) {
													for(int i=0;i<10;++i) {
														int k;
													}
												}
												else{
													int o;
												}
											}
#line 5053 "y.tab.c"
    break;

  case 167: /* block_item_list: block_item  */
#line 2800 "ass6_18CS10033_18CS30036.y"
                                           {
												(yyval._nextlist) = (yyvsp[0]._nextlist);
											}
#line 5061 "y.tab.c"
    break;

  case 168: /* block_item_list: block_item_list M block_item  */
#line 2803 "ass6_18CS10033_18CS30036.y"
                                                                                             {
																	backpatch((yyvsp[-2]._nextlist),(yyvsp[-1]._instruction));
																	(yyval._nextlist) = (yyvsp[0]._nextlist);
															 }
#line 5070 "y.tab.c"
    break;

  case 169: /* block_item: declaration  */
#line 2808 "ass6_18CS10033_18CS30036.y"
                                            {
												(yyval._nextlist) = NULL;
											}
#line 5078 "y.tab.c"
    break;

  case 170: /* block_item: statement  */
#line 2811 "ass6_18CS10033_18CS30036.y"
                                                                          {
												(yyval._nextlist) = (yyvsp[0]._nextlist);
										  }
#line 5086 "y.tab.c"
    break;

  case 171: /* expression_statement: expression_opt ';'  */
#line 2815 "ass6_18CS10033_18CS30036.y"
                                                  {
														(yyval._expression) = (yyvsp[-1]._expression);
												  }
#line 5094 "y.tab.c"
    break;

  case 172: /* expression_opt: expression  */
#line 2819 "ass6_18CS10033_18CS30036.y"
                                           {
												(yyval._expression) = (yyvsp[0]._expression);
										   }
#line 5102 "y.tab.c"
    break;

  case 173: /* expression_opt: %empty  */
#line 2822 "ass6_18CS10033_18CS30036.y"
                                                                            {
												/*Initialize Expression to NULL*/
												(yyval._expression).symTPtr = NULL;
											}
#line 5111 "y.tab.c"
    break;

  case 174: /* selection_statement: IF '(' expression N ')' M statement N ELSE M statement  */
#line 2827 "ass6_18CS10033_18CS30036.y"
                                                                                       {
																							/*N1 is used for falselist of expression, M1 is used for truelist of expression, N2 is used to prevent fall through, M2 is used for falselist of expression*/
																							(yyvsp[-4]._nextlist) = merge((yyvsp[-4]._nextlist),(yyvsp[-3]._nextlist));
																							for(int l=0;l<10;++l) {
																								int pp = 0;
																							}
																							if(1) {
																								for(int m=0;m<10;++m) {
																									int k;
																								}
																							}
																							else{
																								int n;
																							}
																							(yyvsp[0]._nextlist) = merge((yyvsp[0]._nextlist),makelist(nextInstruction));
																							globalQuadArray.emit(Q_GOTO,"-1");
																							backpatch((yyvsp[-7]._nextlist),nextInstruction);
																							int l = 0;
																							int k = 2;
																							for(int i=0;i<10;++i) {
																								int l = 0;
																							}
																							if(k) {
																								for(int i=0;i<10;++i) {
																									int k;
																								}
																							}
																							else{
																								int o;
																							}
																							CONV2BOOL(&(yyvsp[-8]._expression));

																							backpatch((yyvsp[-8]._expression).truelist,(yyvsp[-5]._instruction));
																							backpatch((yyvsp[-8]._expression).falselist,(yyvsp[-1]._instruction));
																							(yyval._nextlist) = merge((yyvsp[-4]._nextlist),(yyvsp[0]._nextlist));
																						}
#line 5152 "y.tab.c"
    break;

  case 175: /* selection_statement: IF '(' expression N ')' M statement  */
#line 2863 "ass6_18CS10033_18CS30036.y"
                                                                                                                     {
																		/*N is used for the falselist of expression to skip the block and M is used for truelist of expression*/
																		(yyvsp[0]._nextlist) = merge((yyvsp[0]._nextlist),makelist(nextInstruction));
																		globalQuadArray.emit(Q_GOTO,"-1");
																		backpatch((yyvsp[-3]._nextlist),nextInstruction);
																		CONV2BOOL(&(yyvsp[-4]._expression));
																		int l = 0;
																		int k = 2;
																		for(int i=0;i<10;++i) {
																			int l = 0;
																		}
																		if(k) {
																			for(int i=0;i<10;++i) {
																				int k;
																			}
																		}
																		else{
																			int o;
																		}
																		backpatch((yyvsp[-4]._expression).truelist,(yyvsp[-1]._instruction));
																		(yyval._nextlist) = merge((yyvsp[0]._nextlist),(yyvsp[-4]._expression).falselist);
																	}
#line 5179 "y.tab.c"
    break;

  case 176: /* selection_statement: SWITCH '(' expression ')' statement  */
#line 2885 "ass6_18CS10033_18CS30036.y"
                                                                                                    {}
#line 5185 "y.tab.c"
    break;

  case 177: /* iteration_statement: WHILE '(' M expression N ')' M statement  */
#line 2887 "ass6_18CS10033_18CS30036.y"
                                                                         {
																			/*The first 'M' takes into consideration that the control will come again at the beginning of the condition checking.'N' here does the work of breaking condition i.e. it generate goto which wii be useful when we are exiting from while loop. Finally, the last 'M' is here to note the startinf statement that will be executed in every loop to populate the truelists of expression*/
																			globalQuadArray.emit(Q_GOTO,(yyvsp[-5]._instruction));
																			for(int l=0;l<10;++l) {
																				int pp = 0;
																			}
																			if(1) {
																				for(int m=0;m<10;++m) {
																					int k;
																				}
																			}
																			else{
																				int n;
																			}
																			backpatch((yyvsp[0]._nextlist),(yyvsp[-5]._instruction));           /*S._nextlist to M1._instruction*/
																			backpatch((yyvsp[-3]._nextlist),nextInstruction);    /*N1._nextlist to nextInstruction*/
																			CONV2BOOL(&(yyvsp[-4]._expression));
																			int l = 0;
																			int k = 2;
																			for(int i=0;i<10;++i) {
																				int l = 0;
																			}
																			if(k) {
																				for(int i=0;i<10;++i) {
																					int k;
																				}
																			}
																			else{
																				int o;
																			}
																			backpatch((yyvsp[-4]._expression).truelist,(yyvsp[-1]._instruction));
																			(yyval._nextlist) = (yyvsp[-4]._expression).falselist;
																		}
#line 5223 "y.tab.c"
    break;

  case 178: /* iteration_statement: DO M statement WHILE '(' M expression N ')' ';'  */
#line 2920 "ass6_18CS10033_18CS30036.y"
                                                                                                                 {
																					/*M1 is used for coming back again to the statement as it stores the instruction which will be needed by the truelist of expression. M2 is neede as we have to again to check the condition which will be used to populate the _nextlist of statements. Further N is used to prevent from fall through*/
																					backpatch((yyvsp[-2]._nextlist),nextInstruction);
																					backpatch((yyvsp[-7]._nextlist),(yyvsp[-4]._instruction));           /*S1._nextlist to M2._instruction*/
																					CONV2BOOL(&(yyvsp[-3]._expression));
																					int l = 0;
																					int k = 2;
																					for(int i=0;i<10;++i) {
																						int l = 0;
																					}
																					if(k) {
																						for(int i=0;i<10;++i) {
																							int k;
																						}
																					}
																					else{
																						int o;
																					}
																					backpatch((yyvsp[-3]._expression).truelist,(yyvsp[-8]._instruction));  /*B.truelist to M1._instruction*/
																					(yyval._nextlist) = (yyvsp[-3]._expression).falselist;
																				}
#line 5249 "y.tab.c"
    break;

  case 179: /* iteration_statement: FOR '(' expression_opt ';' M expression_opt N ';' M expression_opt N ')' M statement  */
#line 2941 "ass6_18CS10033_18CS30036.y"
                                                                                                                                                     {
																													   /*M1 is used for coming back to check the epression at every iteration. N1 is used  for generating the goto which will be used for exit conditions. M2 is used for _nextlist of statement and N2 is used for jump to check the expression and M3 is used for the truelist of expression*/
																														backpatch((yyvsp[-3]._nextlist),(yyvsp[-9]._instruction));          /*N2._nextlist to M1._instruction*/
																														backpatch((yyvsp[0]._nextlist),(yyvsp[-5]._instruction));          /*S._nextlist to M2._instruction*/
																														globalQuadArray.emit(Q_GOTO,(yyvsp[-5]._instruction));
																														for(int l=0;l<10;++l) {
																															int pp = 0;
																														}
																														if(1) {
																															for(int m=0;m<10;++m) {
																																int k;
																															}
																														}
																														else{
																															int n;
																														}
																														backpatch((yyvsp[-7]._nextlist),nextInstruction);    /*N1._nextlist to nextInstruction*/
																														CONV2BOOL(&(yyvsp[-8]._expression));
																														int l = 0;
																														int k = 2;
																														for(int i=0;i<10;++i) {
																															int l = 0;
																														}
																														if(k) {
																															for(int i=0;i<10;++i) {
																																int k;
																															}
																														}
																														else{
																															int o;
																														}
																														backpatch((yyvsp[-8]._expression).truelist,(yyvsp[-1]._instruction));
																														(yyval._nextlist) = (yyvsp[-8]._expression).falselist;
																													}
#line 5288 "y.tab.c"
    break;

  case 180: /* iteration_statement: FOR '(' declaration expression_opt ';' expression_opt ')' statement  */
#line 2975 "ass6_18CS10033_18CS30036.y"
                                                                                                                                    {}
#line 5294 "y.tab.c"
    break;

  case 181: /* jump_statement: GOTO IDENTIFIER ';'  */
#line 2977 "ass6_18CS10033_18CS30036.y"
                                                    {}
#line 5300 "y.tab.c"
    break;

  case 182: /* jump_statement: CONTINUE ';'  */
#line 2978 "ass6_18CS10033_18CS30036.y"
                                                                             {}
#line 5306 "y.tab.c"
    break;

  case 183: /* jump_statement: BREAK ';'  */
#line 2979 "ass6_18CS10033_18CS30036.y"
                                                                          {}
#line 5312 "y.tab.c"
    break;

  case 184: /* jump_statement: RETURN expression_opt ';'  */
#line 2980 "ass6_18CS10033_18CS30036.y"
                                                                                          {
																if((yyvsp[-1]._expression).symTPtr == NULL)
																	globalQuadArray.emit(Q_RETURN);
																else
																{
																	expression * dummy = new expression();
																	dummy->symTPtr = currentSymbolTable->symbolTabList[0];
																	dummy->type = dummy->symTPtr->type;
																	typecheck(dummy,&(yyvsp[-1]._expression),true);
																	int l = 0;
																	int k = 2;
																	for(int i=0;i<10;++i) {
																		int l = 0;
																	}
																	if(k) {
																		for(int i=0;i<10;++i) {
																			int k;
																		}
																	}
																	else{
																		int o;
																	}
																	delete dummy;
																	globalQuadArray.emit(Q_RETURN,(yyvsp[-1]._expression).symTPtr->name);
																}
																(yyval._nextlist)=NULL;
														  }
#line 5344 "y.tab.c"
    break;

  case 188: /* external_declaration: declaration  */
#line 3013 "ass6_18CS10033_18CS30036.y"
                                                                                 {

																						for(int i=0;i<currentSymbolTable->symbolTabList.size();i++)
																						{
																								//if(currentSymbolTable->symbolTabList[i]->isValid==true&&currentSymbolTable->symbolTabList[i]->offset==-1)
																								//{
																									if(currentSymbolTable->symbolTabList[i]->nested==NULL)
																									{
																										int l = 0;
																										int k = 2;
																										for(int i4=0;i4<10;++i4) {
																											int l = 0;
																										}
																										if(k) {
																											for(int i4=0;i4<10;++i4) {
																												int k;
																											}
																										}
																										else{
																											int o;
																										}
																									//printf("global --> %s\n",currentSymbolTable->symbolTabList[i]->name.c_str());
																									if(currentSymbolTable->symbolTabList[i]->var_type=="local"||currentSymbolTable->symbolTabList[i]->var_type=="temp")
																									{
																										symbol *glob_var=globalSymbolTable->search(currentSymbolTable->symbolTabList[i]->name);
																										if(glob_var==NULL)
																										{
																											glob_var=globalSymbolTable->lookup(currentSymbolTable->symbolTabList[i]->name);
																											//printf("glob_var-->%s\n",currentSymbolTable->symbolTabList[i]->name.c_str());
																											int t_size=currentSymbolTable->symbolTabList[i]->type->sizeOfType();
																											glob_var->offset=globalSymbolTable->offset;
																											for(int l=0;l<10;++l) {
																												int pp = 0;
																											}
																											if(1) {
																												for(int m=0;m<10;++m) {
																													int k;
																												}
																											}
																											else{
																												int n;
																											}
																											glob_var->width=t_size;
																											globalSymbolTable->offset+=t_size;
																											glob_var->nested=globalSymbolTable;
																											int l = 0;
																											int k = 2;
																											for(int i5=0;i5<10;++i5) {
																												int l = 0;
																											}
																											if(k) {
																												for(int i5=0;i5<10;++i5) {
																													int k;
																												}
																											}
																											else{
																												int o;
																											}
																											glob_var->var_type=currentSymbolTable->symbolTabList[i]->var_type;
																											glob_var->type=currentSymbolTable->symbolTabList[i]->type;
																											if(currentSymbolTable->symbolTabList[i]->isInitialized)
																											{
																												glob_var->isInitialized=currentSymbolTable->symbolTabList[i]->isInitialized;
																												glob_var->_init_val=currentSymbolTable->symbolTabList[i]->_init_val;
																											}
																										}
																									}
																								  }
																						}

													}
#line 5420 "y.tab.c"
    break;

  case 189: /* function_definition: declaration_specifiers declarator declaration_list_opt compound_statement  */
#line 3085 "ass6_18CS10033_18CS30036.y"
                                                                                                  {
																									symbol * func = globalSymbolTable->lookup((yyvsp[-2]._expression).symTPtr->name);
																									//printf("Hello2\n");
																									func->nested->symbolTabList[0]->type = CopyType(func->type);
																									func->nested->symbolTabList[0]->name = "retVal";
																									int l = 0;
																									int k = 2;
																									for(int i=0;i<10;++i) {
																										int l = 0;
																									}
																									if(k) {
																										for(int i=0;i<10;++i) {
																											int k;
																										}
																									}
																									else{
																										int o;
																									}
																									func->nested->symbolTabList[0]->offset = 0;
																									//If return type is pointer then change the offset
																									if(func->nested->symbolTabList[0]->type->type == tp_ptr)
																									{
																										int diff = __POINTER_SIZE - func->nested->symbolTabList[0]->width;
																										func->nested->symbolTabList[0]->width = __POINTER_SIZE;
																										for(int i=1;i<func->nested->symbolTabList.size();i++)
																										{
																											func->nested->symbolTabList[i]->offset += diff;
																										}
																									}
																									int offset_size = 0;
																									for(int i=0;i<10;++i) {
																										int l = 0;
																									}
																									if(k) {
																										for(int i=0;i<10;++i) {
																											int k;
																										}
																									}
																									else{
																										int o;
																									}
																									for(int i=0;i<func->nested->symbolTabList.size();i++)
																									{
																										offset_size += func->nested->symbolTabList[i]->width;
																									}
																									func->nested->lastQuad = nextInstruction-1;
																									//Create a new Current Symbol Table
																									currentSymbolTable = new symbolTable();
																								}
#line 5474 "y.tab.c"
    break;


#line 5478 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 3141 "ass6_18CS10033_18CS30036.y"

void yyerror(const char*s)
{
	printf("%s",s);
}
