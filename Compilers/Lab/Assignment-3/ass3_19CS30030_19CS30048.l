/*-------------------------------------------------------------------
    Compilers Laboratory: CS39003 | Assignment - 3: Lexer for tinyC
    Suhas Jain | 19CS0048 | Monal Prasad | 19CS30030 | Testing File
--------------------------------------------------------------------*/

%{
	#define KEYWORD 1
	#define IDENTIFIER 2
	#define INTEGER_CONSTANT 3
	#define FLOATING_CONSTANT 4
	#define CHARACTER_CONSTANT 5
	#define STRING_LITERAL 6
	#define PUNCTUATOR 7
	#define SINGLE_LINE_COMMENT 8
	#define MULTI_LINE_COMMENT 9
	#define ENUMERATION_CONSTANT 10	
%}

/* Regular Expression Definitions */

/*KEYWORDS*/
KEYWORD						"auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"register"|"float"|"for"|"goto"|"if"|"inline"|"int"|"long"|"restrict"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"|"_Bool"|"_Complex"|"_Imaginary"
	
/*IDENTIFIERS*/
NONDIGIT 					[a-zA-Z]|"_"
DIGIT						[0-9]
IDENTIFIER 					{NONDIGIT}({NONDIGIT}|{DIGIT})*
 
/*CONSTANTS*/
NONZERO_DIGIT				[1-9]
NONZERO_INTEGER_CONSTANT	{NONZERO_DIGIT}{DIGIT}*
INTEGER_CONSTANT			{NONZERO_INTEGER_CONSTANT}|"0"
FRACTIONAL_CONSTANT			({DIGIT_SEQUENCE}?"."{DIGIT_SEQUENCE})|({DIGIT_SEQUENCE}".")

SIGN 						"+"|"-"
DIGIT_SEQUENCE				[0-9]{DIGIT}*
EXPONENT_PART				("e"{SIGN}?{DIGIT_SEQUENCE})|("E"{SIGN}?{DIGIT_SEQUENCE})
FLOATING_CONSTANT			({FRACTIONAL_CONSTANT}{EXPONENT_PART}?)|({DIGIT_SEQUENCE}{EXPONENT_PART})
ENUMERATION_CONSTANT		{IDENTIFIER}
ESCAPE_SEQUENCE				\\['"?\\abfnrtv]
C_CHAR 						{ESCAPE_SEQUENCE}|[^("\'"|"\\"|"\n")]
C_CHAR_SEQUENCE				{C_CHAR}+
CHARACTER_CONSTANT			"\'"{C_CHAR_SEQUENCE}"\'"
CONSTANT					{INTEGER_CONSTANT}|{FLOATING_CONSTANT}|{ENUMERATION_CONSTANT}|{CHARACTER_CONSTANT}

/*STRING_LITERALS*/
S_CHAR  					{ESCAPE_SEQUENCE}|[^("\""|"\\"|"\n")]
S_CHAR_SEQUENCE				{S_CHAR}+
STRING_LITERAL 				"\""{S_CHAR_SEQUENCE}?"\""

/*PUNCTUATORS*/
PUNCTUATOR 					"["|"]"|"("|")"|"{"|"}"|"."|"->"|"++"|"--"|"&"|"*"|"+"|"-"|"~"|"!"|"/"|"%"|"<<"|">>"|"<"|">"|"<="|">="|"=="|"!="|"^"|"|"|"&&"|"||"|"?"|":"|";"|"..."|"="|"*="|"/="|"%="|"+="|"-="|"<<="|">>="|"&="|"^="|"|="|","|"#" 

/*COMMENTS*/
MULTI_LINE_COMMENT			"/*"[^"*"]*"*"("*"|([^"/*"]*[^"*"]*"*"))*"/"
SINGLE_LINE_COMMENT			"//"[^("\n")]*

/* WHITESPACE */
SPACES                       [ \t\v\n\f]

%%

{KEYWORD}                       { return KEYWORD; }
{IDENTIFIER}	                { return IDENTIFIER; }
{INTEGER_CONSTANT}	        	{ return INTEGER_CONSTANT; }
{CHARACTER_CONSTANT}            { return CHARACTER_CONSTANT; }
{FLOATING_CONSTANT}	        	{ return FLOATING_CONSTANT; }
{STRING_LITERAL}                { return STRING_LITERAL; }
{PUNCTUATOR}	                { return PUNCTUATOR; }
{SINGLE_LINE_COMMENT}			{ return SINGLE_LINE_COMMENT;}
{MULTI_LINE_COMMENT} 			{ return MULTI_LINE_COMMENT;}
{SPACES}                        {}

%%
