/* SUHAS JAIN | 19CS30048 */
/* MONAL PRASAD | 19CS30030 */
/* Bison Specifications File    */

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Definitions and Declarations */
%{
	#include <stdio.h>
	extern int yylex();
	extern char* yytext;
	void yyerror(char *mssg);
%}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

%union {  int intval; }

%token BREAK CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE ELSE EXTERN FLOAT FOR GOTO IF INT LONG RETURN RESTRICT SHORT SIZEOF STATIC STRUCT  
%token SWITCH TYPEDEF UNION VOID VOLATILE WHILE IDENTIFIER INLINE INTEGER_CONSTANT FLOATING_CONSTANT CHARACTER_CONSTANT STRING_LITERAL
%token SQUARE_BRACKET_OPEN SQUARE_BRACKET_CLOSE ROUND_BRACKET_OPEN ROUND_BRACKET_CLOSE CURLY_BRACKET_OPEN CURLY_BRACKET_CLOSE 
%token DOT ARROW INCREMENT DECREMENT BITWISE_AND MUL ADD SUB BITWISE_NOT EXCLAIM DIV MOD SHIFT_LEFT SHIFT_RIGHT LT GT LTE GTE 
%token EQ NEQ BITWISE_XOR BITWISE_OR AND OR QUESTION COLON SEMICOLON ELIPSIS ASSIGN MUL_EQ DIV_EQ MOD_EQ ADD_EQ SUB_EQ SL_EQ  
%token SR_EQ BITWISE_AND_EQ BITWISE_XOR_EQ BITWISE_OR_EQ COMMA HASH 

%start translation_unit
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Grammar Productions */

%%

primary_expression
	: IDENTIFIER
	| constant
	| STRING_LITERAL
	| ROUND_BRACKET_OPEN expression ROUND_BRACKET_CLOSE
	  { printf("Rule: Expression --> primary_expression \n"); };

constant
	: INTEGER_CONSTANT 
	| FLOATING_CONSTANT 
	| CHARACTER_CONSTANT
	;

postfix_expression
	: primary_expression
	| postfix_expression SQUARE_BRACKET_OPEN expression SQUARE_BRACKET_CLOSE
	| postfix_expression ROUND_BRACKET_OPEN argument_expression_list_opt ROUND_BRACKET_CLOSE
	| postfix_expression DOT IDENTIFIER
	| postfix_expression ARROW IDENTIFIER
	| postfix_expression INCREMENT
	| postfix_expression DECREMENT
	| ROUND_BRACKET_OPEN type_name ROUND_BRACKET_CLOSE CURLY_BRACKET_OPEN initializer_list CURLY_BRACKET_CLOSE
	| ROUND_BRACKET_OPEN type_name ROUND_BRACKET_CLOSE CURLY_BRACKET_OPEN initializer_list COMMA CURLY_BRACKET_CLOSE
	  { printf("Rule: Expression --> postfix_expression \n"); }
	;

argument_expression_list_opt
	: argument_expression_list
	| /*epsilon*/
    ;

argument_expression_list
	: assignment_expression
	| argument_expression_list COMMA assignment_expression
	  { printf("Rule: Expression --> argument_expression_list \n"); }
	;

unary_expression
	: postfix_expression
	| INCREMENT unary_expression
	| DECREMENT unary_expression
	| unary_operator cast_expression
	| SIZEOF unary_expression
	| SIZEOF ROUND_BRACKET_OPEN type_name ROUND_BRACKET_CLOSE
	  { printf("Rule: Expression --> unary_expression \n"); }
	;

unary_operator
	: BITWISE_AND
	| MUL
	| ADD
	| SUB
	| BITWISE_NOT
	| EXCLAIM
	  { printf("Rule: Expression --> unary_operator \n"); }
	;

cast_expression
	: unary_expression
	| ROUND_BRACKET_OPEN type_name ROUND_BRACKET_CLOSE cast_expression
	  { printf("Rule: Expression --> cast_expression \n"); }
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression MUL cast_expression
	| multiplicative_expression DIV cast_expression
	| multiplicative_expression MOD cast_expression
	  { printf("Rule: Expression --> multiplicative_expression \n"); }
	;

additive_expression
	: multiplicative_expression
	| additive_expression ADD multiplicative_expression
	| additive_expression SUB multiplicative_expression
	  { printf("Rule: Expression --> additive_expression \n"); }
	;

shift_expression
	: additive_expression
	| shift_expression SHIFT_LEFT additive_expression
	| shift_expression SHIFT_RIGHT additive_expression
	  { printf("Rule: Expression --> shift_expression \n"); }
	;

relational_expression
	: shift_expression
	| relational_expression LT shift_expression
	| relational_expression GT shift_expression
	| relational_expression LTE shift_expression
	| relational_expression GTE shift_expression
	  { printf("Rule: Expression --> relational_expression \n"); }
	;

equality_expression
	: relational_expression
	| equality_expression EQ relational_expression
	| equality_expression NEQ relational_expression
	  { printf("Rule: Expression --> equality_expression \n"); }
	;

and_expression
	: equality_expression
	| and_expression BITWISE_AND equality_expression
	  { printf("Rule: Expression --> and_expression \n"); }
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression BITWISE_XOR and_expression
	  { printf("Rule: Expression --> exclusive_or_expression \n"); }
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression BITWISE_OR exclusive_or_expression
	  { printf("Rule: Expression --> inclusive_or_expression \n"); }
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND inclusive_or_expression
	  { printf("Rule: Expression --> logical_and_expression \n"); }
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR logical_and_expression
	  { printf("Rule: Expression --> logical_or_expression \n"); }
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression QUESTION expression COLON conditional_expression
	  { printf("Rule: Expression --> conditional_expression \n"); }
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
	  { printf("Rule: Expression --> assignment_expression \n"); }
	;

assignment_operator
	: ASSIGN
	| MUL_EQ
	| DIV_EQ
	| MOD_EQ
	| ADD_EQ
	| SUB_EQ
	| SL_EQ
	| SR_EQ
	| BITWISE_AND_EQ
	| BITWISE_XOR_EQ
	| BITWISE_OR_EQ
	  { printf("Rule: Expression --> assignment_operator \n"); }
	;

expression
	: assignment_expression
	| expression COMMA assignment_expression
	  { printf("Rule: Expression --> expression \n"); }
	;

constant_expression
	: conditional_expression
	  { printf("Rule: Expression --> constant_expression \n"); }
	;


/* Declarations ---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

declaration
	: declaration_specifiers init_declarator_list_opt SEMICOLON
	  { printf("Rule: Declarations --> declaration \n"); }
	;

declaration_specifiers
	: storage_class_specifier declaration_specifiers_opt
	| type_specifier declaration_specifiers_opt
	| type_qualifier declaration_specifiers_opt
	| function_specifier declaration_specifiers_opt
	  { printf("Rule: Declarations --> declaration_specifiers \n"); }
	;

declaration_specifiers_opt
	: declaration_specifiers
	| /*epsilon*/
	;

init_declarator_list
	: init_declarator
	| init_declarator_list COMMA init_declarator
	  { printf("Rule: Declarations --> init_declarator_list \n"); }
	;

init_declarator_list_opt
	: init_declarator_list
	| /*epsilon*/
	;

init_declarator
	: declarator
	| declarator ASSIGN initializer
	  { printf("Rule: Declarations --> init_declarator \n"); }
	;

storage_class_specifier
	: EXTERN
	| STATIC
	  { printf("Rule: Declarations --> storage_class_specifier \n"); }
	;

type_specifier
	: VOID
	| CHAR
	| SHORT
	| INT
	| LONG
	| FLOAT
	| DOUBLE
	  { printf("Rule: Declarations --> type_specifier \n"); }
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list_opt
	| type_qualifier specifier_qualifier_list_opt
	  { printf("Rule: Declarations --> specifier_qualifier_list \n"); }
	;

specifier_qualifier_list_opt
	: specifier_qualifier_list
	| /*epsilon*/
	;

type_qualifier
	: CONST
	| VOLATILE
	| RESTRICT
	  { printf("Rule: Declarations --> type_qualifier \n"); }
	;

function_specifier
	: INLINE
	  { printf("Rule: Declarations --> function_specifier \n"); }
	;

declarator
	: pointer_opt direct_declarator
	  { printf("Rule: Declarations --> declarator \n"); }
	;

direct_declarator
	: IDENTIFIER
	| ROUND_BRACKET_OPEN declarator ROUND_BRACKET_CLOSE
	| direct_declarator SQUARE_BRACKET_OPEN  type_qualifier_list_opt assignment_expression_opt SQUARE_BRACKET_CLOSE
	| direct_declarator SQUARE_BRACKET_OPEN STATIC type_qualifier_list_opt assignment_expression SQUARE_BRACKET_CLOSE
	| direct_declarator SQUARE_BRACKET_OPEN type_qualifier_list STATIC assignment_expression SQUARE_BRACKET_CLOSE
	| direct_declarator SQUARE_BRACKET_OPEN type_qualifier_list_opt MUL SQUARE_BRACKET_CLOSE
	| direct_declarator ROUND_BRACKET_OPEN parameter_type_list ROUND_BRACKET_CLOSE
	| direct_declarator ROUND_BRACKET_OPEN identifier_list_opt ROUND_BRACKET_CLOSE
	  { printf("Rule: Declarations --> direct_declarator \n"); }
	;

type_qualifier_list_opt
	: type_qualifier_list
	| /*epsilon*/
	;

pointer_opt
	: pointer
	| /*epsilon*/
	;

assignment_expression_opt
	: assignment_expression
	| /*epsilon*/
	;

identifier_list_opt
	: identifier_list
	| /*epsilon*/
	;

pointer
	: MUL type_qualifier_list_opt
	| MUL type_qualifier_list_opt pointer
	  { printf("Rule: Declarations --> pointer \n"); }
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	  { printf("Rule: Declarations --> type_qualifier_list \n"); }
	;


parameter_type_list
	: parameter_list
	| parameter_list COMMA ELIPSIS
	  { printf("Rule: Declarations --> parameter_type_list \n"); }
	;

parameter_list
	: parameter_declaration
	| parameter_list COMMA parameter_declaration
	  { printf("Rule: Declarations --> parameter_list \n"); }
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers
	  { printf("Rule: Declarations --> parameter_declaration \n"); }
	;

identifier_list
	: IDENTIFIER
	| identifier_list COMMA IDENTIFIER
	  { printf("Rule: Declarations --> identifier_list \n"); }
	;

type_name
	: specifier_qualifier_list
	  { printf("Rule: Declarations --> type_name \n"); }
	;

initializer
	: assignment_expression
	| CURLY_BRACKET_OPEN initializer_list CURLY_BRACKET_CLOSE
	| CURLY_BRACKET_OPEN initializer_list COMMA CURLY_BRACKET_CLOSE
	  { printf("Rule: Declarations --> initializer \n"); }
	;

initializer_list
	: designation_opt initializer
	| initializer_list COMMA designation_opt initializer
	  { printf("Rule: Declarations --> initializer_list \n"); }
	;

designation_opt
	: designation
	| /*epsilon*/
	;

designation
	: designator_list ASSIGN
	  { printf("Rule: Declarations --> designation \n"); }
	;

designator_list
	: designator
	| designator_list designator
	  { printf("Rule: Declarations --> designator_list \n"); }
	;

designator
	: SQUARE_BRACKET_OPEN constant_expression SQUARE_BRACKET_CLOSE
	| DOT IDENTIFIER
	  { printf("Rule: Declarations --> designator \n"); }
	;


/* Statements------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

statement
	: labeled_statement
	| compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	  { printf("Rule: Statements --> statement \n"); }
	;

labeled_statement
	: IDENTIFIER COLON statement
	| CASE constant_expression COLON statement
	| DEFAULT COLON statement
	  { printf("Rule: Statements --> labeled_statement \n"); }
	;

compound_statement
	: CURLY_BRACKET_OPEN block_item_list_opt CURLY_BRACKET_CLOSE
	  { printf("Rule: Statements --> compound_statement \n"); }
	;

block_item_list_opt
	: block_item_list
	| /*epsilon*/
	;

block_item_list
	: block_item
	| block_item_list block_item
	  { printf("Rule: Statements --> block_item_list \n"); }
	;

block_item
	: declaration
	| statement
	  { printf("Rule: Statements --> block_item \n"); }
	;

expression_statement
	: expression_opt SEMICOLON
	  { printf("Rule: Statements --> expression_statement \n"); }
	;

expression_opt
	: expression
	| /*epsilon*/
	;

selection_statement
	: IF ROUND_BRACKET_OPEN expression ROUND_BRACKET_CLOSE statement
	| IF ROUND_BRACKET_OPEN expression ROUND_BRACKET_CLOSE statement ELSE statement
	| SWITCH ROUND_BRACKET_OPEN expression ROUND_BRACKET_CLOSE statement
	  { printf("Rule: Statements --> selection_statement \n"); }
	;

iteration_statement
	: WHILE ROUND_BRACKET_OPEN expression ROUND_BRACKET_CLOSE statement
	| DO statement WHILE ROUND_BRACKET_OPEN expression ROUND_BRACKET_CLOSE SEMICOLON
	| FOR ROUND_BRACKET_OPEN expression_opt SEMICOLON expression_opt SEMICOLON expression_opt ROUND_BRACKET_CLOSE statement
	| FOR ROUND_BRACKET_OPEN declaration expression_opt SEMICOLON expression_opt ROUND_BRACKET_CLOSE statement
	  { printf("Rule: Statements --> iteration_statement \n"); }
	;

jump_statement
	: GOTO IDENTIFIER SEMICOLON
	| CONTINUE SEMICOLON
	| BREAK SEMICOLON
	| RETURN expression_opt SEMICOLON
	  { printf("Rule: Statements --> jump_statement \n"); }
	;

/* External Definitions ------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

translation_unit
	: external_declaration
	| translation_unit external_declaration
	  { printf("Rule: External Definitions --> translation_unit \n"); }
	;

external_declaration
	: function_definition
	| declaration
	  { printf("Rule: External Definitions --> external_declaration \n"); }
	;

function_definition
	: declaration_specifiers declarator declaration_list_opt compound_statement
	  { printf("Rule: External Definitions --> function_definition \n"); }
	;

declaration_list_opt
	: declaration_list
	| /*epsilon*/
	;

declaration_list
	: declaration
	| declaration_list declaration
	  { printf("Rule: External Definitions --> declaration_list \n"); }
	;
%%
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Auxillary Functions */

void yyerror(char* s)
{
    printf("Found error: %s\n", s);
}

