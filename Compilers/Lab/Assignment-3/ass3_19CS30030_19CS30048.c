/*-------------------------------------------------------------------
    Compilers Laboratory: CS39003 | Assignment - 3: Lexer for tinyC
    Suhas Jain | 19CS0048 | Monal Prasad | 19CS30030
--------------------------------------------------------------------*/

#include <stdio.h>

extern char* yytext;

// Main function
int main(){
	int token_val;
  	while(token_val = yylex()){
		switch(token_val){
			case KEYWORD:
				printf("\nKEYWORD, %d, %s\n",token_val, yytext);
				break;
			case IDENTIFIER:
				printf("\nIDENTIFIER, %d, %s\n",token_val, yytext);
				break;
			case INTEGER_CONSTANT: 
				printf("\nINTEGER CONSTANT, %d, %s\n",token_val, yytext); 
				break;
			case FLOATING_CONSTANT: 
				printf("\nFLOAT CONSTANT, %d, %s\n",token_val, yytext); 
				break;
			case CHARACTER_CONSTANT: 
				printf("\nCHARACTER CONSTANT, %d, %s\n",token_val, yytext); 
				break;
			case STRING_LITERAL: 
				printf("\nSTRING LITERAL, %d, %s\n",token_val, yytext); 
				break;
			case PUNCTUATOR:
				printf("\nPUNCTUATOR, %d, %s\n",token_val, yytext); 
				break;
			case SINGLE_LINE_COMMENT:
				printf("\nSINGLE_LINE_COMMENT, %d, %s\n",token_val, yytext);
				break;
			case MULTI_LINE_COMMENT:
				printf("\nMULTI_LINE_COMMENT, %d, %s\n",token_val, yytext);
				break;
			default:
				printf("\nNot a valid C literal"); 
				break;
		}
  	}
}
