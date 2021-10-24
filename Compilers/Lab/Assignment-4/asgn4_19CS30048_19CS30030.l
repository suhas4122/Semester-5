/* SUHAS JAIN | 19CS30048 */
/* MONAL PRASAD | 19CS30030 */
/* Lex Specifications File	*/
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Definitions and Declarations */
%{
	#include"y.tab.h"
	void yyerror(char *mssg);
%}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Regular Expression Definitions */

KEYWORD  "break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"extern"|"float"|"for"|"goto"|"if"|"int"|"inline"|"long"|"return"|"restrict"|"short"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"void"|"volatile"|"while"|"enum"

/*Identifiers*/
DIGIT					            [0-9]
IDENTIFIER_NONDIGIT 			    [a-zA-Z_]
IDENTIFIER							{IDENTIFIER_NONDIGIT}({IDENTIFIER_NONDIGIT}|{DIGIT})*

/*Constants*/
CONSTANT 				          	{INTEGER_CONSTANT}|{FLOATING_CONSTANT}|{CHARACTER_CONSTANT}

/*Integer Constants*/
NONZERO_DIGIT 				        [1-9]
INTEGER_CONSTANT					{NONZERO_DIGIT}|{DIGIT}* 	

/*Floating Constants*/
SIGN 					            "+"|"-"
SIGN_OPT				            {SIGN}?
DIGIT_SEQUENCE  			        {DIGIT}({DIGIT})*
DIGIT_SEQUENCE_OPT			        {DIGIT_SEQUENCE}?
EXPONENT_PART 				        "e"{SIGN_OPT}{DIGIT_SEQUENCE}|"E"{SIGN_OPT}{DIGIT_SEQUENCE}
EXPONENT_PART_OPT 			        {EXPONENT_PART}?
FRACTIONAL_CONSTANT			        {DIGIT_SEQUENCE_OPT}"."{DIGIT_SEQUENCE}|{DIGIT_SEQUENCE}"."
FLOATING_CONSTANT			        {FRACTIONAL_CONSTANT}{EXPONENT_PART_OPT}|{DIGIT_SEQUENCE}{EXPONENT_PART}

/*Character Constants*/
ESCAPE_SEQUENCE 			        "\'"|"\''"|"\?"|"\\"|"\a"|"\b"|"\f"|"\n"|"\r"|"\t"|"\v"
C_CHAR 					            {ESCAPE_SEQUENCE}|[^("\'"|"\\"|"\n")]
C_CHAR_SEQUENCE 			        {C_CHAR}+
CHARACTER_CONSTANT			        "\'"{C_CHAR_SEQUENCE}"\'"

/*String Literals*/
S_CHAR  				            {ESCAPE_SEQUENCE}|[^("\""|"\\"|"\n")]
S_CHAR_SEQUENCE 			        {S_CHAR}+
S_CHAR_SEQUENCE_OPT 			    {S_CHAR_SEQUENCE}?
STRING_LITERAL 				        "\""{S_CHAR_SEQUENCE_OPT}"\""

/*Punctuators*/
PUNCTUATOR 				            "++"|"/"|"?"|"="|","|"["|"]"|"("|")"|"{"|"}"|"."|"->"|"*"|"+"|"-"|"~"|"!"|"%"|"<<"|">>"|"<"|">"|"<="|">="|":"|";"|"..."|"*="|"/="|"%="|"+="|"-="|"<<="|"#"|"--"|"&"|"=="|">>="|"!="|"&="|"^"|"|"|"^="|"&&"|"||"|"|="

/*Comments*/
SINGLE_LINE_COMMENT			        "//"[^("\n")]*
MULTI_LINE_COMMENT			        \/\*([^\*]|(\*)+[^\/\*])*(\*)*\/
WS 					                [ \t\n]
	

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Translation Rules Section */
%%

"break"			                    { return BREAK; }
"case"			                    { return CASE; }
"char"		  	                    { return CHAR; }
"const"		  	                    { return CONST; }
"continue"		                    { return CONTINUE; }
"default"		                    { return DEFAULT; }
"do"			                    { return DO; }
"double"		                    { return DOUBLE; }
"else"			                    { return ELSE; }
"extern"		                    { return EXTERN; }
"float"			                    { return FLOAT; }
"signed"							{ return SIGNED; }
"unsigned"							{ return UNSIGNED; }
"for"			                    { return FOR; }
"goto"			                    { return GOTO; }
"if"			                    { return IF; }
"int"			                    { return INT; }
"inline"		                    { return INLINE; }
"long"			                    { return LONG; }
"return"		                    { return RETURN; }
"restrict"		                    { return RESTRICT; }
"short"			                    { return SHORT; }
"sizeof"		                    { return SIZEOF; }
"_Bool"								{ return BOOL; }
"_Complex"							{ return COMPLEX; }
"_Imaginary"						{ return IMAGINARY; }
"static"		                    { return STATIC; }
"struct"		                    { return STRUCT; }
"switch"		                    { return SWITCH; }
"typedef"		                    { return TYPEDEF; }
"union"			                    { return UNION; }
"void"			                    { return VOID; }
"volatile"		                    { return VOLATILE; }
"while"			                    { return WHILE; }
"enum"								{ return ENUM; }
"auto" 								{ return AUTO; }
"register"                          { return REGISTER; }

{IDENTIFIER}		                { return IDENTIFIER;}
{INTEGER_CONSTANT}                  { return INTEGER_CONSTANT;}
{FLOATING_CONSTANT}	                { return FLOATING_CONSTANT;}
{CHARACTER_CONSTANT} 	            { return CHARACTER_CONSTANT;}
{STRING_LITERAL} 	                { return STRING_LITERAL;}

"[" 			                    { return SQUARE_BRACKET_OPEN; }
"]" 			                    { return SQUARE_BRACKET_CLOSE; }
"(" 			                    { return ROUND_BRACKET_OPEN; }
")" 			                    { return ROUND_BRACKET_CLOSE; }
"{" 			                    { return CURLY_BRACKET_OPEN; }
"}" 			                    { return CURLY_BRACKET_CLOSE; }
"." 			                    { return DOT; }
"->" 			                    { return ARROW; }
"++" 			                    { return INCREMENT; }
"--" 			                    { return DECREMENT; }
"&" 			                    { return BITWISE_AND; }
"*" 			                    { return MUL; }
"+" 			                    { return ADD; }
"-" 			                    { return SUB; }
"~" 			                    { return BITWISE_NOT; }
"!" 			                    { return EXCLAIM; }
"/" 			                    { return DIV; }
"%" 			                    { return MOD; }
"<<" 			                    { return SHIFT_LEFT; }
">>" 			                    { return SHIFT_RIGHT; }
"<" 			                    { return LT; }
">" 			                    { return GT; }
"<=" 			                    { return LTE; }
">=" 			                    { return GTE; }
"==" 			                    { return EQ; }
"!=" 			                    { return NEQ; }
"^" 			                    { return BITWISE_XOR; }
"|" 			                    { return BITWISE_OR; }
"&&" 			                    { return AND; }
"||" 			                    { return OR; }
"?" 			                    { return QUESTION; }
":" 			                    { return COLON; }
";" 			                    { return SEMICOLON; }
"..." 			                    { return ELIPSIS; }
"=" 			                    { return ASSIGN; }
"*=" 			                    { return MUL_EQ; }
"/=" 			                    { return DIV_EQ; }
"%=" 			                    { return MOD_EQ; }
"+=" 			                    { return ADD_EQ; }
"-=" 			                    { return SUB_EQ; }
"<<=" 			                    { return SL_EQ; }
">>=" 			                    { return SR_EQ; }
"&=" 			                    { return BITWISE_AND_EQ; }
"^=" 			                    { return BITWISE_XOR_EQ; }
"|=" 			                    { return BITWISE_OR_EQ; }
"," 			                    { return COMMA; }
"#" 			                    { return HASH; }

{SINGLE_LINE_COMMENT}				{/*Do nothing, Ignore single line comments*/}
{MULTI_LINE_COMMENT} 				{/*Do nothing, Ignore multi line comments*/}
{WS}	                        	{/*Do nothing, Ignore white spaces*/ }

%%
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
