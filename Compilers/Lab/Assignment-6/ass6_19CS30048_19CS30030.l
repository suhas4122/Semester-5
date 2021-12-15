/* Suhas Jain | 19CS30048    */
/* Monal Prasad  | 19CS30030    */
/* Lex Specifications File	*/
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Definitions and Declarations */
%{
	#include<stdio.h>

	#include "ass6_19CS30048_19CS30030_translator.h"
	#include "y.tab.h"

	extern void yyerror(const char *);
	static void comment(void);
%}

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Regular Expression Definitions */

DIGIT [0-9]
NONZERODIG [1-9]
IDENT_ND [A-Za-z_]
IDENT ({IDENT_ND}({IDENT_ND}|{DIGIT})*)
WHITESPACE [ \n\t]
SIGN [+-]
DIGIT_SEQ {DIGIT}+
EXPONENT_PART ([eE]{SIGN}?{DIGIT_SEQ})
ZERO "0"
INT_CONST (({NONZERODIG}({DIGIT}*))|{ZERO}+)
DOT "."
FRACT_CONST (({DIGIT_SEQ}?{DOT}{DIGIT_SEQ})|({DIGIT_SEQ}{DOT}))
FLOAT_CONST (({FRACT_CONST}{EXPONENT_PART}?)|({DIGIT_SEQ}{EXPONENT_PART}))
ESC_SEQ ([\\][\'\"\?\\abfnrtv])
C_CHAR [^\'\\\n]|{ESC_SEQ}
C_CHAR_SEQ {C_CHAR}+
C_CHAR_CONST (\'{C_CHAR_SEQ}\')
CONST ({INT_CONST}|{FLOAT_CONST}|{C_CHAR_CONST})
S_CHAR [^\"\\\n]|{ESC_SEQ}
S_CHAR_SEQ {S_CHAR}+
STRING_LITERAL (\"{S_CHAR_SEQ}*\")
SINGLE_COMMENT [/][/].*
MULTI_END [\*]+[/]
MULTI_START [/][\*]+
NON_STAR (([^\*]).*)
NON_FS ([^/].*)
AVOID_MULTI_END (NON_STAR|([\*]{NON_FS}))
MULTI_COMMENT ({MULTI_START}(([^\*])|((\*)+[^/\*]))*{MULTI_END})
COMMENT {SINGLE_COMMENT}|{MULTI_COMMENT}


/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Translation Rules Section */
%%

"break"			{ return BREAK; }
"case"			{ return CASE; }
"char"		  	{ return CHAR; }
"const"		  	{ return CONST; }
"continue"		{ return CONTINUE; }
"default"		{ return DEFAULT; }
"do"			{ return DO; }
"double"		{ return DOUBLE; }
"else"			{ return ELSE; }
"extern"		{ return EXTERN; }
"float"			{ return FLOAT; }
"for"			{ return FOR; }
"goto"			{ return GOTO; }
"if"			{ return IF; }
"int"			{ return INT; }
"inline"		{ return INLINE; }
"long"			{ return LONG; }
"return"		{ return RETURN; }
"restrict"		{ return RESTRICT; }
"short"			{ return SHORT; }
"sizeof"		{ return SIZEOF; }
"static"		{ return STATIC; }
"struct"		{ return STRUCT; }
"switch"		{ return SWITCH; }
"typedef"		{ return TYPEDEF; }
"union"			{ return UNION; }
"void"			{ return VOID; }
"volatile"		{ return VOLATILE; }
"while"			{ return WHILE; }


"["                 {return '[';  }
"]"                 { return ']'; }
"("                 { return '('; }
")"                 { return ')'; }
"{"                 { return '{'; }
"}"                 { return '}'; }
"."                 { return '.'; }
"->"                { return (POINTER); }
"++"                { return (INCREMENT); }
"--"                { return (DECREMENT); }
"&"                 { return '&'; }
"*"                 { return '*'; }
"+"                 { return '+'; }
"-"                 { return '-'; }
"~"                 { return '~'; }
"!"                 { return '!'; }
"/"                 { return '/'; }
"%"                 { return '%'; }
"<<"                { return (LEFT_SHIFT); }
">>"                { return (RIGHT_SHIFT); }
"<"                 { return '<'; }
">"                 { return '>'; }
"<="                { return (LESS_EQUALS); }
">="                { return (GREATER_EQUALS); }
"=="                { return (EQUALS); }
"!="                { return (NOT_EQUALS); }
"^"                 { return '^'; }
"|"                 { return '|'; }
"&&"                { return (AND); }
"||"                { return (OR); }
"?"                 { return '?'; }
":"                 { return ':'; }
";"                 { return ';'; }
"..."               { return (ELLIPSIS); }
"="                 { return '='; }
"*="                { return MULTIPLY_ASSIGN; }
"/="                { return DIVIDE_ASSIGN; }
"%="                { return MODULO_ASSIGN; }
"+="                { return ADD_ASSIGN; }
"-="                { return SUBTRACT_ASSIGN; }
"<<="               { return LEFT_SHIFT_ASSIGN; }
">>="               { return RIGHT_SHIFT_ASSIGN; }
"&="                { return AND_ASSIGN; }
"^="                { return XOR_ASSIGN; }
"|="                { return OR_ASSIGN; }
","                 { return ','; }
"#"                 { return '#'; }

{COMMENT}           {;}

{IDENT}             { yylval.idl.name=new string(yytext);return IDENTIFIER;}
{INT_CONST}         { yylval.intval=atoi(yytext); return INTEGER_CONSTANT;}
{FLOAT_CONST}		{ yylval.floatval=atof(yytext); return FLOATING_CONSTANT;}
{C_CHAR_CONST}		{ yylval.charval=yytext[1]; return CHAR_CONST;}
{STRING_LITERAL}    { yylval.strval = new string(yytext);return STRING_LITERAL;}


{WHITESPACE}        {;}

%%
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
