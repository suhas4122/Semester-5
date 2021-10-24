/* Suhas Jain | 19CS30048    */
/* Monal Prasad | 19CS30030    */
/* Bison Specifications File    */
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Definitions and Declarations */

%{
    //Header Files Needed
    #include <iostream>              
    #include <cstdlib>
    #include <string>
    #include <stdio.h>
    #include <sstream>

    //Translator file
    #include "ass5_19CS30048_19CS30030_translator.h"

    //yylex for lexer, yyerror for error recovery, var_type for last encountered type
    extern int yylex();
    void yyerror(string s);
    extern string var_type;

    using namespace std;
%}

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

%union {                                                    // yylval is a union of all these types

    char unaryOp;                                           // Unary operator       
    char* char_value;                                       // Char value

    int instr_number;                                       // Instruction number: for backpatching
    int intval;                                             // Integer value    
    int num_params;                                         // Number of parameters

    Expression* expr;                                       // Expression
    Statement* stat;                                        // Statement        

    symboltype* sym_type;                                   // Symbol type  
    sym* symp;                                              // Symbol
    Array* A;                                               // Array type
        
} 

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Tokens */

%token BREAK CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE ELSE EXTERN FLOAT FOR GOTO IF INT LONG RETURN RESTRICT SHORT SIZEOF STATIC SWITCH VOID VOLATILE WHILE INLINE

// Identifiers are treated with type symbol*
%token <symp> IDENTIFIER            

// Integer constants have a type intval
%token <intval> INTEGER_CONSTANT            

// Floating constants have a type charval
%token <char_value> FLOATING_CONSTANT           

// Character constants have a type charval
%token <char_value> CHARACTER_CONSTANT  

// String literals have a type charval
%token <char_value> STRING_LITERAL 

%token SQUARE_BRACKET_OPEN SQUARE_BRACKET_CLOSE ROUND_BRACKET_OPEN ROUND_BRACKET_CLOSE CURLY_BRACKET_OPEN CURLY_BRACKET_CLOSE 
%token DOT IMPLIES INC DEC BITWISE_AND MUL ADD SUB BITWISE_NOT EXCLAIM DIV MOD SHIFT_LEFT SHIFT_RIGHT LT GT LTE GTE 
%token EQ NEQ BITWISE_XOR BITWISE_OR AND OR QUESTION COLON SEMICOLON DOTS ASSIGN MUL_EQ DIV_EQ MOD_EQ ADD_EQ SUB_EQ SL_EQ  
%token SR_EQ BITWISE_AND_EQ BITWISE_XOR_EQ BITWISE_OR_EQ COMMA  
%token SIGNED UNSIGNED BOOL COMPLEX IMAGINARY ENUM 
%start translation_unit

// To remove dangling else problem
%right THEN ELSE


// Unary operator
%type <unaryOp> unary_operator

// Number of parameters
%type <num_params> argument_expression_list argument_expression_list_opt


// Expressions
%type <expr>
    expression
    primary_expression 
    multiplicative_expression
    additive_expression
    shift_expression
    relational_expression
    equality_expression
    and_expression
    exclusive_or_expression
    inclusive_or_expression
    logical_and_expression
    logical_or_expression
    conditional_expression
    assignment_expression
    expression_statement

// Statements
%type <stat>  
    statement
    compound_statement
    loop_statement
    selection_statement
    iteration_statement
    labeled_statement 
    jump_statement
    block_item
    block_item_list
    block_item_list_opt

// The pointer non-terminal is treated with type symbolType
%type <sym_type> pointer

// Non-terminals of type symp (symbol*)
%type <symp> initializer
%type <symp> direct_declarator init_declarator declarator

// arr1s
%type <A> 
    postfix_expression
    unary_expression
    cast_expression

// Auxillary non-terminals M and N
%type <instr_number> M

// Auxiliary non-terminal N of type stmt to help in control flow statements
%type <stat> N

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Grammar Productions */

%%

M: /* empty */
    {
        // backpatching,stores the index of the next quad to be generated
        // Used in various control statements
        $$  =  nextinstr();
    }   
    ;

F: /* empty */ 
    {
        // rule for identifying the start of the for statement
        loop_name  =  "FOR";
    }   
    ;

W: /* empty */ 
    {
        // rule for identifying the start of a while loop
        loop_name  =  "WHILE";
    }   
    ;

D: /* empty */ 
    {
        // rule for identifyiong the start of the do while statement
        loop_name  =  "DO_WHILE";
    }   
    ;

X: /* empty */ 
    {
        /**
          * change the current symbol pointer
          * This will be used for nested block statements
        */
        // give name for nested table  
        string name  =  ST->name+"."+loop_name+"$"+to_string(table_count); 
        table_count++;                                          // increment the table count
        sym* s  =  ST->lookup(name);                            // lookup the table for new entry
        s->nested  =  new symtable(name);
        s->nested->parent  =  ST;
        s->name  =  name;
        s->type  =  new symboltype("block");
        currSymbolPtr  =  s;
    }   
    ;

N: /* empty */
    {
        /** 
          * For backpatching, which inserts a goto 
          * and stores the index of the next goto 
          * statement to guard against fallthrough

          * N->nextlist  =  makelist(nextinstr) we have defined nextlist for Statements
          */
        $$  =  new Statement();
        $$->nextlist = makelist(nextinstr());
        emit("goto","");
    }
    ;

changetable: /* empty */ 
    {    
        if(currSymbolPtr->nested  ==  NULL) 
        {
            changeTable(new symtable(""));                  // Function symbol table doesn't already exist  
        }
        else 
        {
            changeTable(currSymbolPtr->nested);             // Function symbol table already exists 
            emit("label", ST->name);
        }
    }
    ;

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Expressions */

primary_expression
    : IDENTIFIER                                            // Identifier
    { 
        $$  =  new Expression();                            // Create new expression and store pointer to ST entry in the location          
        $$->loc  =  $1;
        $$->type  =  "not-boolean";
    }
    | INTEGER_CONSTANT                                      // Create new expression and store the value of the constant in a temporary
    { 
        $$  =  new Expression();    
        string p  =  convertIntToString($1);
        $$->loc  =  gentemp(new symboltype("int"),p);
        emit("=",$$->loc->name,p);
    }
    | FLOATING_CONSTANT                                     // Create new expression and store the value of the constant in a temporary
    {    
        $$  =  new Expression();
        $$->loc  =  gentemp(new symboltype("float"),$1);
        emit("=",$$->loc->name,string($1));
    }
    | CHARACTER_CONSTANT                                    // Create new expression and store the value of the constant in a temporary
    {    
        $$  =  new Expression();
        $$->loc  =  gentemp(new symboltype("char"),$1);
        emit("=",$$->loc->name,string($1));
    }
    | STRING_LITERAL                                        // Create new expression and store the value of the constant in a temporary 
    {   
        $$ = new Expression();
        $$->loc = gentemp(new symboltype("ptr"),$1);            
        $$->loc->type->arrtype = new symboltype("char");
    }
    | ROUND_BRACKET_OPEN expression ROUND_BRACKET_CLOSE     // Simply equal to expression
    { 
        $$ = $2;
    }
    ;


postfix_expression
    : primary_expression                                    
    { 
        $$ = new Array();                                   // Create a new Array
        $$->Array = $1->loc;                                // Store the location of the primary expression
        $$->type = $1->loc->type;                           // Update the type
        $$->loc = $$->Array;
    }
    | postfix_expression SQUARE_BRACKET_OPEN expression SQUARE_BRACKET_CLOSE 
    {   
        $$ = new Array();
        $$->type = $1->type->arrtype;                       // type  =  type of element 
        $$->Array = $1->Array;                              // Copy the base
        $$->loc = gentemp(new symboltype("int"));           // Store computed address
        $$->atype = "arr";                                  // atype is arr.
        if($1->atype == "arr") 
        {                                                   // If already arr, multiply the size of the sub-type of Array with the expression value and add
            sym* t = gentemp(new symboltype("int"));
            int p = computeSize($$->type);
            string str = convertIntToString(p);
            emit("*",t->name,$3->loc->name,str);
            emit("+",$$->loc->name,$1->loc->name,t->name);
        }
        else 
        {                                                   // If a 1D Array, simply calculate size
            int p = computeSize($$->type);
            string str = convertIntToString(p);
            emit("*",$$->loc->name,$3->loc->name,str);
        }
    }
    | postfix_expression ROUND_BRACKET_OPEN argument_expression_list_opt ROUND_BRACKET_CLOSE       
    {                                                       // Call the function with number of parameters from argument_expression_list_opt
        $$ = new Array();   
        $$->Array = gentemp($1->type);
        string str = convertIntToString($3);
        emit("call",$$->Array->name,$1->Array->name,str);
    }
    | postfix_expression DOT IDENTIFIER 
    { /* Ignored */ }
    | postfix_expression IMPLIES IDENTIFIER  
    { /* Ignored */ }
    | postfix_expression INC                                // Generate new temporary, equate it to old one and then add 1
    { 
        $$ = new Array();
        $$->Array = gentemp($1->Array->type);
        emit("=",$$->Array->name,$1->Array->name);
        emit("+",$1->Array->name,$1->Array->name,"1");
    }
    | postfix_expression DEC                                // Generate new temporary, equate it to old one and then subtract 1
    {
        $$ = new Array();   
        $$->Array = gentemp($1->Array->type);
        emit("=",$$->Array->name,$1->Array->name);
        emit("-",$1->Array->name,$1->Array->name,"1");
    }
    | ROUND_BRACKET_OPEN type_name ROUND_BRACKET_CLOSE CURLY_BRACKET_OPEN initializer_list CURLY_BRACKET_CLOSE 
    {  /* Ignored */ }
    | ROUND_BRACKET_OPEN type_name ROUND_BRACKET_CLOSE CURLY_BRACKET_OPEN initializer_list COMMA CURLY_BRACKET_CLOSE 
    {  /* Ignored */ }
    ;

argument_expression_list_opt
    : /* empty */ 
    { 
        $$ = 0;                                                 // No arguments
    }             
    | argument_expression_list    
    { 
        $$ = $1;                                                // Equate $$ and $1
    }       
    ;


argument_expression_list
    : assignment_expression    
    {
        $$ = 1;                                                 // One argument and emit param
        emit("param",$1->loc->name);    
    }
    | argument_expression_list COMMA assignment_expression     
    {
        $$ = $1+1;                                              // One more argument and emit param 
        emit("param",$3->loc->name);
    }
    ;

unary_expression
    : postfix_expression   
    { 
        $$ = $1;                                                // Assign
    }               
    | INC unary_expression                                      // Simply add 1
    {   
        emit("+",$2->Array->name,$2->Array->name,"1");
        $$ = $2;                                                // Assign
    }
    | DEC unary_expression                                      // Simply subtract 1
    {
        emit("-",$2->Array->name,$2->Array->name,"1");
        $$ = $2;                                                // Assign
    }
    | unary_operator cast_expression                            // If it is of this type, where unary operator is involved
    {           
        $$ = new Array();
        switch($1)
        {
            case '&':   // Address
                $$->Array = gentemp(new symboltype("ptr"));    // Generate a pointer temporary
                $$->Array->type->arrtype = $2->Array->type;    // Assign corresponding type
                emit("=&", $$->Array->name, $2->Array->name); // Emit the quad
                break;
            case '*':   // De-referencing
                $$->atype = "ptr";
                $$->loc = gentemp($2->Array->type->arrtype);   // Generate a temporary of the appropriate type
                $$->Array = $2->Array;                         // Assign
                emit("=*", $$->loc->name, $2->Array->name);   // Emit the quad
                break;
            case '+':   // Unary plus
                $$ = $2;                                                    // Simple assignment
                break;
            case '-':   // Unary minus
                $$->Array = gentemp(new symboltype($2->Array->type->type));    // Generate temporary of the same base type
                emit("=-", $$->Array->name, $2->Array->name);                 // Emit the quad
                break;
            case '~':   // Bitwise not
                $$->Array = gentemp(new symboltype($2->Array->type->type));    // Generate temporary of the same base type
                emit("=~", $$->Array->name, $2->Array->name);                 // Emit the quad
                break;
            case '!':   // Logical not 
                $$->Array = gentemp(new symboltype($2->Array->type->type));    // Generate temporary of the same base type
                emit("=!", $$->Array->name, $2->Array->name);                 // Emit the quad
                break;
        }
    }
    | SIZEOF unary_expression  
    {  /* Ignored */ }
    | SIZEOF ROUND_BRACKET_OPEN type_name ROUND_BRACKET_CLOSE   
    {  /* Ignored */ }
    ;

unary_operator                  
    : BITWISE_AND               // Simply equate to the corresponding operator
    { 
        $$ = '&'; 
    }                                                       
    | MUL       
    {
        $$ = '*'; 
    }
    | ADD       
    { 
        $$ = '+'; 
    }
    | SUB       
    { 
        $$ = '-'; 
    }
    | BITWISE_NOT  
    { 
        $$ = '~'; 
    } 
    | EXCLAIM  
    {
        $$ = '!'; 
    }
    ;

cast_expression
    : unary_expression  
    { 
        $$ = $1;                                                // Unary expression, simply equate
    }                       
    | ROUND_BRACKET_OPEN type_name ROUND_BRACKET_CLOSE cast_expression          
    // If cast type is given
    { 
        $$ = new Array();   
        $$->Array = convertType($4->Array,var_type);            // Generate a new symbol of the given type
    }
    ;

multiplicative_expression
    : cast_expression  
    {
        $$  =  new Expression();                                // Generate new expression  
        if($1->atype == "arr")                                  // If it is of type arr
        {
            $$->loc  =  gentemp($1->loc->type); 
            emit("=[]", $$->loc->name, $1->Array->name, $1->loc->name);     
            //emit with Array right
        }
        else if($1->atype == "ptr")                             // If it is of type ptr
            $$->loc  =  $1->loc;                                // Equate the locs
        else
            $$->loc  =  $1->Array;
    }
    | multiplicative_expression MUL cast_expression             // If we have multiplication
    { 
        if(!compareSymbolType($1->loc, $3->Array))         
            cout<<"Type Error in Program"<< endl;               // Error
        else                                                    // If types are compatible, generate new temporary and equate to the product
        {
            $$  =  new Expression();    
            $$->loc  =  gentemp(new symboltype($1->loc->type->type));
            emit("*", $$->loc->name, $1->loc->name, $3->Array->name);
        }
    }
    | multiplicative_expression DIV cast_expression             // If we have division
    {
        if(!compareSymbolType($1->loc, $3->Array))
            cout << "Type Error in Program"<< endl;
        else                                                    // If types are compatible, generate new temporary and equate to the quotient
        {
            $$  =  new Expression();
            $$->loc  =  gentemp(new symboltype($1->loc->type->type));
            emit("/", $$->loc->name, $1->loc->name, $3->Array->name);
        }
    }
    | multiplicative_expression MOD cast_expression             // If we have mod
    {
        if(!compareSymbolType($1->loc, $3->Array))
            cout << "Type Error in Program"<< endl;     
        else                                                    // If types are compatible, generate new temporary and equate to the quotient
        {
            $$  =  new Expression();
            $$->loc  =  gentemp(new symboltype($1->loc->type->type));
            emit("%", $$->loc->name, $1->loc->name, $3->Array->name);   
        }
    }
    ;

additive_expression
    : multiplicative_expression   
    { 
        $$ = $1;                                                // Simply equate
    }            
    | additive_expression ADD multiplicative_expression         // If we have addition
    {
        if(!compareSymbolType($1->loc, $3->loc))
            cout << "Type Error in Program"<< endl;
        else                                                    // If types are compatible, generate new temporary and equate to the sum
        {
            $$  =  new Expression();    
            $$->loc  =  gentemp(new symboltype($1->loc->type->type));
            emit("+", $$->loc->name, $1->loc->name, $3->loc->name);
        }
    }
    | additive_expression SUB multiplicative_expression         // If we have subtraction
    {   
        if(!compareSymbolType($1->loc, $3->loc))
            cout << "Type Error in Program"<< endl;     
        else                                                    // If types are compatible, generate new temporary and equate to the difference
        {   
            $$  =  new Expression();    
            $$->loc  =  gentemp(new symboltype($1->loc->type->type));
            emit("-", $$->loc->name, $1->loc->name, $3->loc->name);
        }
    }
;

shift_expression
    : additive_expression   
    { 
        $$ = $1;                                                // Simply equate
    }              
    | shift_expression SHIFT_LEFT additive_expression   
    { 
        if(!($3->loc->type->type  ==  "int"))
            cout << "Type Error in Program"<< endl;         
        else                                                    // If base type is int, generate new temporary and equate to the shifted value
        {       
            $$  =  new Expression();    
            $$->loc  =  gentemp(new symboltype("int"));
            emit("<<", $$->loc->name, $1->loc->name, $3->loc->name);
        }
    }
    | shift_expression SHIFT_RIGHT additive_expression
    {   
        if(!($3->loc->type->type  ==  "int"))
        {
            cout << "Type Error in Program"<< endl;         
        }
        else                                                    // If base type is int, generate new temporary and equate to the shifted value
        {       
            $$  =  new Expression();    
            $$->loc  =  gentemp(new symboltype("int"));
            emit(">>", $$->loc->name, $1->loc->name, $3->loc->name);
        }
    }
    ;

relational_expression
    : shift_expression   { $$ = $1; }                           // Simply equate
    | relational_expression LT shift_expression
    {
        if(!compareSymbolType($1->loc, $3->loc)) 
        {
            cout << "Type Error in Program"<< endl;
        }
        else 
        {   // Check compatible types       
            $$ = new Expression();                          // Generate new expression of type bool
            $$->type = "bool";
            $$->truelist = makelist(nextinstr());           // Create truelist for boolean expression
            $$->falselist = makelist(nextinstr() + 1);      // Create falselist for boolean expression
            emit("<", "", $1->loc->name, $3->loc->name);    // Emit "if x < y goto ..."
            emit("goto", "");                               // Emit "goto ..."  
        }
    }
    | relational_expression GT shift_expression             // Similar to above, check compatible types,make new lists and emit
    {
        if(!compareSymbolType($1->loc, $3->loc)) 
        {
            cout << "Type Error in Program"<< endl;
        }
        else 
        {
            $$ = new Expression();                          // Generate new expression of type bool
            $$->type = "bool";
            $$->truelist = makelist(nextinstr());           // Create truelist for boolean expression
            $$->falselist = makelist(nextinstr() + 1);      // Create falselist for boolean expression
            emit(">", "", $1->loc->name, $3->loc->name);    // Emit "if x > y goto ..."
            emit("goto", "");                               // Emit "goto ..."
        }   
    }
    | relational_expression LTE shift_expression            // Similar to above, check compatible types,make new lists and emit
    {
        if(!compareSymbolType($1->loc, $3->loc)) 
        {
            cout << "Type Error in Program"<< endl;
        }
        else 
        {       
            $$ = new Expression();                          // Generate new expression of type bool
            $$->type = "bool";
            $$->truelist = makelist(nextinstr());           // Create truelist for boolean expression
            $$->falselist = makelist(nextinstr() + 1);      // Create falselist for boolean expression
            emit("<=", "", $1->loc->name, $3->loc->name);   // Emit "if x <= y goto ..."
            emit("goto", "");                               // Emit "goto ..."
        }       
    }
    | relational_expression GTE shift_expression            // Similar to above, check compatible types,make new lists and emit
    {
        if(!compareSymbolType($1->loc, $3->loc))
        {
            cout << "Type Error in Program"<< endl;
        }
        else 
        {
            $$ = new Expression();                          // Generate new expression of type bool
            $$->type = "bool";
            $$->truelist = makelist(nextinstr());           // Create truelist for boolean expression
            $$->falselist = makelist(nextinstr() + 1);      // Create falselist for boolean expression
            emit(">=", "", $1->loc->name, $3->loc->name);   // Emit "if x >= y goto ..."
            emit("goto", "");                               // Emit "goto ..."
        }
    }
    ;

equality_expression
    : relational_expression  { $$ = $1; }                   // Simply equate
    | equality_expression EQ relational_expression 
    {
        if(!compareSymbolType($1->loc, $3->loc))            // Check compatible types
        {
            cout << "Type Error in Program"<< endl;
        }
        else 
        {
            convertBoolToInt($1);                           // Convert bool to int
            convertBoolToInt($3);
            $$ = new Expression();                          // Generate new expression of type bool
            $$->type = "bool";
            $$->truelist = makelist(nextinstr());           // Create truelist for boolean expression
            $$->falselist = makelist(nextinstr() + 1);      // Create falselist for boolean expression
            emit("==", "", $1->loc->name, $3->loc->name);   // Emit "if x == y goto ..."
            emit("goto", "");                               // Emit "goto ..."
        }
        
    }
    | equality_expression NEQ relational_expression         // Similar to above, check compatibility, convert bool to int, make list and emit
    {
        if(!compareSymbolType($1->loc, $3->loc)) 
        {
            cout << "Type Error in Program"<< endl;
        }
        else 
        {
            convertBoolToInt($1);                           // Convert bool to int
            convertBoolToInt($3);
            $$ = new Expression();                          // Generate new expression of type bool
            $$->type = "bool";
            $$->truelist = makelist(nextinstr());           // Create truelist for boolean expression
            $$->falselist = makelist(nextinstr() + 1);      // Create falselist for boolean expression
            emit("!=", "", $1->loc->name, $3->loc->name);   // Emit "if x == y goto ..."
            emit("goto", "");                               // Emit "goto ..."
        }
    }
    ;

and_expression
    : equality_expression  { $$ = $1; }                     // Simply equate
    | and_expression BITWISE_AND equality_expression 
    {
        if(!compareSymbolType($1->loc, $3->loc))            // Check compatible types 
        {
            cout << "Type Error in Program"<< endl;
        }
        else 
        {
            convertBoolToInt($1);                           // Convert bool to int
            convertBoolToInt($3);
            $$  =  new Expression();
            $$->type  =  "not-boolean";                     // Result is not boolean
            $$->loc  =  gentemp(new symboltype("int"));
            emit("&", $$->loc->name, $1->loc->name, $3->loc->name);               
            //emit the quad
        }
    }
    ;

exclusive_or_expression
    : and_expression  { $$ = $1; }                          // Simply equate
    | exclusive_or_expression BITWISE_XOR and_expression    
    {
        if(!compareSymbolType($1->loc, $3->loc))            // Same as and_expression: check compatible types, make non-boolean expression and convert bool to int and emit
        {
            cout << "Type Error in Program"<< endl;
        }
        else 
        {
            convertBoolToInt($1);   
            convertBoolToInt($3);
            $$  =  new Expression();
            $$->type  =  "not-boolean";
            $$->loc  =  gentemp(new symboltype("int"));
            emit("^", $$->loc->name, $1->loc->name, $3->loc->name);
        }
    }
    ;

inclusive_or_expression
    : exclusive_or_expression { $$ = $1; }                  // Simply equate
    | inclusive_or_expression BITWISE_OR exclusive_or_expression          
    { 
        if(!compareSymbolType($1->loc, $3->loc))            // Same as and_expression: check compatible types, make non-boolean expression and convert bool to int and emit
        {
            cout << "Type Error in Program"<< endl;
        }
        else 
        {
            convertBoolToInt($1);       
            convertBoolToInt($3);
            $$  =  new Expression();
            $$->type  =  "not-boolean";
            $$->loc  =  gentemp(new symboltype("int"));
            emit("|", $$->loc->name, $1->loc->name, $3->loc->name);
        } 
    }
    ;

logical_and_expression
    : inclusive_or_expression  { $$ = $1; }                 // Simply equate
    | logical_and_expression N AND M inclusive_or_expression 
    // Backpatching involved here
    { 
        convertIntToBool($5);                               // Convert inclusive_or_expression int to bool
        backpatch($2->nextlist, nextinstr());               // $2->nextlist goes to next instruction
        convertIntToBool($1);                               // Convert logical_and_expression to bool
        $$  =  new Expression();                            // Make new boolean expression 
        $$->type  =  "bool";
        backpatch($1->truelist, $4);                        // If $1 is true, we move to $5
        $$->truelist  =  $5->truelist;                      // If $5 is also true, we get truelist for $$
        $$->falselist  =  merge($1->falselist, $5->falselist);    
        // Merge their falselists
    }
    ;

logical_or_expression
    : logical_and_expression   { $$ = $1; }                 // Simply equate
    | logical_or_expression N OR M logical_and_expression   // Backpatching involved here
    { 
        convertIntToBool($5);                               // Convert logical_and_expression int to bool
        backpatch($2->nextlist, nextinstr());               // $2->nextlist goes to next instruction
        convertIntToBool($1);                               // Convert logical_or_expression to bool
        $$  =  new Expression();                            // Make new boolean expression
        $$->type  =  "bool";
        backpatch($1->falselist, $4);                       // If $1 is true, we move to $5
        $$->truelist  =  merge($1->truelist, $5->truelist); // Merge their truelists
        $$->falselist  =  $5->falselist;                    // If $5 is also false, we get falselist for $$
    }
    ;

conditional_expression 
    : logical_or_expression {$$ = $1;}                      // Simply equate
    | logical_or_expression N QUESTION M expression N COLON M conditional_expression 
    {
        // Normal conversion method to get conditional expressions
        $$->loc  =  gentemp($5->loc->type);                 // Generate temporary for expression
        $$->loc->update($5->loc->type);
        emit("=", $$->loc->name, $9->loc->name);            // Make it equal to sconditional_expression
        list<int> l  =  makelist(nextinstr());              // Makelist next instruction
        emit("goto", "");                                   // Prevent fallthrough
        backpatch($6->nextlist, nextinstr());               // After N, go to next instruction
        emit("=", $$->loc->name, $5->loc->name);
        list<int> m  =  makelist(nextinstr());              // Makelist next instruction
        l  =  merge(l, m);                                  // Merge the two lists
        emit("goto", "");                                   // Prevent fallthrough
        backpatch($2->nextlist, nextinstr());               // Backpatching
        convertIntToBool($1);                               // Convert expression to boolean
        backpatch($1->truelist, $4);                        // $1 true goes to expression
        backpatch($1->falselist, $8);                       // $1 false goes to conditional_expression
        backpatch(l, nextinstr());
    }
    ;

assignment_expression
    : conditional_expression 
    {
        $$ = $1;                                                // Simply equate
    }         
    | unary_expression assignment_operator assignment_expression 
    {
        if($1->atype == "arr")                                  // If type is arr, simply check if we need to convert and emit
        {
            $3->loc  =  convertType($3->loc, $1->type->type);
            emit("[]=", $1->Array->name, $1->loc->name, $3->loc->name);     
        }
        else if($1->atype == "ptr")                             // If type is ptr, simply emit
        {
            emit("*=", $1->Array->name, $3->loc->name);     
        }
        else                                                    // Otherwise assignment
        {
            $3->loc  =  convertType($3->loc, $1->Array->type->type);
            emit("=", $1->Array->name, $3->loc->name);
        }
        
        $$  =  $3;
        
    }
    ;

assignment_operator
    : ASSIGN   
    {  /* Ignored */ }
    | MUL_EQ    
    {  /* Ignored */ }
    | DIV_EQ    
    {  /* Ignored */ }
    | MOD_EQ    
    {  /* Ignored */ }
    | ADD_EQ    
    {  /* Ignored */ }
    | SUB_EQ    
    {  /* Ignored */ }
    | SL_EQ    
    {  /* Ignored */ }
    | SR_EQ    
    {  /* Ignored */ }
    | BITWISE_AND_EQ    
    {  /* Ignored */ }
    | BITWISE_XOR_EQ    
    {  /* Ignored */ }
    | BITWISE_OR_EQ        
    {  /* Ignored */ }
    ;

expression
    : assignment_expression 
    {  $$ = $1;  }
    | expression COMMA assignment_expression     
    {  /* Ignored */ }
    ;

constant_expression
    : conditional_expression     
    {  /* Ignored */ }
    ;


/* Declarations ---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

declaration
    : declaration_specifiers init_declarator_list SEMICOLON     
    {  /* Ignored */ }
    | declaration_specifiers SEMICOLON     
    {  /* Ignored */ }
    ;


declaration_specifiers
    : storage_class_specifier declaration_specifiers     
    {  /* Ignored */ }
    | storage_class_specifier     
    {  /* Ignored */ }
    | type_specifier declaration_specifiers     
    {  /* Ignored */ }
    | type_specifier     
    {  /* Ignored */ }
    | type_qualifier declaration_specifiers     
    {  /* Ignored */ }
    | type_qualifier     
    {  /* Ignored */ }
    | function_specifier declaration_specifiers     
    {  /* Ignored */ }
    | function_specifier     
    {  /* Ignored */ }
    ;

init_declarator_list
    : init_declarator     
    {  /* Ignored */ }
    | init_declarator_list COMMA init_declarator     
    {  /* Ignored */ }
    ;

init_declarator
    : declarator {$$ = $1;}
    | declarator ASSIGN initializer 
    {
        if($3->val!= "") $1->val = $3->val;                 // Get the initial value and  emit it
        emit("=", $1->name, $3->name);
    }
    ;

storage_class_specifier
    : EXTERN      
    {  /* Ignored */ }
    | STATIC      
    {  /* Ignored */ }
    ;

type_specifier
    : VOID   { var_type = "void"; }                         // Store the latest type in var_type
    | CHAR   { var_type = "char"; }
    | SHORT      
    {  /* Ignored */ }
    | INT   { var_type = "int"; }
    | LONG   
    {  /* Ignored */ }
    | FLOAT   { var_type = "float"; }
    | DOUBLE       
    {  /* Ignored */ }
    | SIGNED   
    {  /* Ignored */ }
    | UNSIGNED       
    {  /* Ignored */ }
    | BOOL   
    {  /* Ignored */ }
    | COMPLEX   
    {  /* Ignored */ }
    | IMAGINARY   
    {  /* Ignored */ }
    | ENUM   
    {  /* Ignored */ }
    ;

specifier_qualifier_list
    : type_specifier specifier_qualifier_list_opt   
    {  /* Ignored */ }
    | type_qualifier specifier_qualifier_list_opt  
    {  /* Ignored */ }
    ;

specifier_qualifier_list_opt
    : /* empty */ 
    {  /* Ignored */ }
    | specifier_qualifier_list  
    {  /* Ignored */ }
    ;

    
type_qualifier
    : CONST   
    {  /* Ignored */ }
    | RESTRICT   
    {  /* Ignored */ }
    | VOLATILE   
    {  /* Ignored */ }
    ;

function_specifier
    : INLINE   
    {  /* Ignored */ }
    ;

declarator
    : pointer direct_declarator 
    {
        symboltype *t  =  $1;
        while(t->arrtype!= NULL) t  =  t->arrtype;              // For multidimensional arr1s, move in depth till you get the base type
        t->arrtype  =  $2->type;                                // Add the base type 
        $$  =  $2->update($1);                                  // Update
    }
    | direct_declarator     
    {  /* Ignored */ }
    ;

direct_declarator
    : IDENTIFIER                                                // If ID, simply add a new variable of var_type
    {
        $$  =  $1->update(new symboltype(var_type));
        currSymbolPtr  =  $$;
        
    }
    | ROUND_BRACKET_OPEN declarator ROUND_BRACKET_CLOSE {$$ = $2;}        // Simply equate
    | direct_declarator SQUARE_BRACKET_OPEN type_qualifier_list assignment_expression SQUARE_BRACKET_CLOSE     
    {  /* Ignored */ }
    | direct_declarator SQUARE_BRACKET_OPEN type_qualifier_list SQUARE_BRACKET_CLOSE     
    {  /* Ignored */ }
    | direct_declarator SQUARE_BRACKET_OPEN assignment_expression SQUARE_BRACKET_CLOSE 
    {
        symboltype *t  =  $1 -> type;
        symboltype *prev  =  NULL;
        while(t->type  ==  "arr") 
        {
            prev  =  t; 
            t  =  t->arrtype;                                   // Keep moving recursively to get basetype
        }
        if(prev == NULL) 
        {
            int temp  =  atoi($3->loc->val.c_str());            // Get initial value
            // Create new symbol with that initial value
            symboltype* s  =  new symboltype("arr", $1->type, temp);        
            $$  =  $1->update(s);                               // Update the symbol table
        }
        else 
        {
            // Similar arguments as above       
            prev->arrtype  =   new symboltype("arr", t, atoi($3->loc->val.c_str()));     
            $$  =  $1->update($1->type);
        }
    }
    | direct_declarator SQUARE_BRACKET_OPEN SQUARE_BRACKET_CLOSE 
    {
        symboltype *t  =  $1 -> type;
        symboltype *prev  =  NULL;
        while(t->type  ==  "arr") 
        {
            prev  =  t; 
            t  =  t->arrtype;                                   // Keep moving recursively to base type
        }
        if(prev == NULL) 
        {
            // No initial values, simply keep 0
            symboltype* s  =  new symboltype("arr", $1->type, 0);    
            $$  =  $1->update(s);
        }
        else 
        {
            prev->arrtype  =   new symboltype("arr", t, 0);
            $$  =  $1->update($1->type);
        }
    }
    | direct_declarator SQUARE_BRACKET_OPEN STATIC type_qualifier_list assignment_expression SQUARE_BRACKET_CLOSE     
    {  /* Ignored */ }
    | direct_declarator SQUARE_BRACKET_OPEN STATIC assignment_expression SQUARE_BRACKET_CLOSE     
    {  /* Ignored */ }
    | direct_declarator SQUARE_BRACKET_OPEN type_qualifier_list MUL SQUARE_BRACKET_CLOSE     
    {  /* Ignored */ }
    | direct_declarator SQUARE_BRACKET_OPEN MUL SQUARE_BRACKET_CLOSE     
    {  /* Ignored */ }
    | direct_declarator ROUND_BRACKET_OPEN changetable parameter_type_list ROUND_BRACKET_CLOSE 
    {
        ST->name  =  $1->name;
        if($1->type->type != "void") 
        {
            sym *s  =  ST->lookup("return");                    // Lookup for return value  
            s->update($1->type);
        }
        $1->nested = ST;       
        ST->parent  =  globalST;
        changeTable(globalST);                                  // Come back to globalsymbol table
        currSymbolPtr  =  $$;
    }
    | direct_declarator ROUND_BRACKET_OPEN identifier_list ROUND_BRACKET_CLOSE     
    {  /* Ignored */ }
    | direct_declarator ROUND_BRACKET_OPEN changetable ROUND_BRACKET_CLOSE 
    {                                                           // Similar as above
        ST->name  =  $1->name;
        if($1->type->type != "void") 
        {
            sym *s  =  ST->lookup("return");
            s->update($1->type);
        }
        $1->nested = ST;
        ST->parent  =  globalST;
        changeTable(globalST);                                  // Come back to globalsymbol table
        currSymbolPtr  =  $$;
    }
    ;


type_qualifier_list_opt
    : /* empty */  
    {  /* Ignored */ }
    | type_qualifier_list      
    {  /* Ignored */ }
    ;

pointer
    : MUL type_qualifier_list_opt   
    { 
        $$  =  new symboltype("ptr");
    }          // Create new pointer
    | MUL type_qualifier_list_opt pointer 
    { 
        $$  =  new symboltype("ptr",$3);
    }
    ;

type_qualifier_list
    : type_qualifier   
    {  /* Ignored */ }
    | type_qualifier_list type_qualifier   
    {  /* Ignored */ }
    ;

parameter_type_list
    : parameter_list   
    {  /* Ignored */ }
    | parameter_list COMMA DOTS   
    {  /* Ignored */ }
    ;

parameter_list
    : parameter_declaration   
    {  /* Ignored */ }
    | parameter_list COMMA parameter_declaration    
    {  /* Ignored */ }
    ;

parameter_declaration
    : declaration_specifiers declarator   
    {  /* Ignored */ }
    | declaration_specifiers    
    {  /* Ignored */ }
    ;

identifier_list
    : IDENTIFIER    
    {  /* Ignored */ }        
    | identifier_list COMMA IDENTIFIER   
    {  /* Ignored */ }
    ;

type_name
    : specifier_qualifier_list   
    {  /* Ignored */ }
    ;

initializer
    : assignment_expression   { $$ = $1->loc; }             // Assignment
    | CURLY_BRACKET_OPEN initializer_list CURLY_BRACKET_CLOSE  
    {  /* Ignored */ }
    | CURLY_BRACKET_OPEN initializer_list COMMA CURLY_BRACKET_CLOSE  
    {  /* Ignored */ }
    ;

initializer_list
    : designation_opt initializer  
    {  /* Ignored */ }
    | initializer_list COMMA designation_opt initializer   
    {  /* Ignored */ }
    ;

designation_opt
    : /* empty */   
    {  /* Ignored */ }
    | designation   
    {  /* Ignored */ }
    ;

designation
    : designator_list ASSIGN   
    {  /* Ignored */ }
    ;

designator_list
    : designator    
    {  /* Ignored */ }
    | designator_list designator   
    {  /* Ignored */ }
    ;

designator
    : SQUARE_BRACKET_OPEN constant_expression SQUARE_BRACKET_CLOSE   
    {  /* Ignored */ }
    | DOT IDENTIFIER 
    {  /* Ignored */ }
    ;


/* Statements------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

statement
    : labeled_statement   
    {  /* Ignored */ }
    | compound_statement   { $$ = $1; }
    | expression_statement   
    { 
        $$ = new Statement();                               // Create new statement with same nextlist
        $$->nextlist = $1->nextlist; 
    }
    | selection_statement   { $$ = $1; }
    | iteration_statement   { $$ = $1; }
    | jump_statement   { $$ = $1; }
    ;

loop_statement: labeled_statement   
    {  /* Ignored */ }
    | expression_statement   
    { 
        $$ = new Statement();                               // Create new statement with same nextlist
        $$->nextlist = $1->nextlist; 
    }
    | selection_statement   { $$ = $1; }
    | iteration_statement   { $$ = $1; }
    | jump_statement   { $$ = $1; }
    ;

labeled_statement
    : IDENTIFIER COLON M statement   
    {  
        $$  =  $4;
        label *s  =  find_label($1->name);
        if(s!= nullptr){
            s->addr  =  $3;
            backpatch(s->nextlist,s->addr);
        }else{
            s  =  new label($1->name);
            s->addr  =  nextinstr();
            s->nextlist  =  makelist($3);
            label_table.push_back(*s);
        }
    }
    | CASE constant_expression COLON statement   
    {  /* Ignored */ }
    | DEFAULT COLON statement   
    {  /* Ignored */ }
    ;

compound_statement
    : CURLY_BRACKET_OPEN X changetable block_item_list_opt CURLY_BRACKET_CLOSE   
    { 
        $$ = $4; 
        changeTable(ST->parent); 
    }                                                       // Simply equate
    ;

block_item_list_opt
    : /* empty */  { $$ = new Statement(); }                // Create new statement
    | block_item_list   { $$ = $1; }                        // Simply equate
    ;

block_item_list
    : block_item   { $$ = $1; }                             // Simply equate
    | block_item_list M block_item    
    { 
        $$ = $3;
        backpatch($1->nextlist,$2);                         // After $1, move to block_item via $2
    }
    ;

block_item
    : declaration   { $$ = new Statement(); }               // New statement
    | statement   { $$ = $1; }                              // Simply equate
    ;

expression_statement
    : expression SEMICOLON {$$ = $1;}                       // Simply equate
    | SEMICOLON {$$  =  new Expression();}                  // New  expression
    ;

selection_statement
    : IF ROUND_BRACKET_OPEN expression N ROUND_BRACKET_CLOSE M statement N %prec THEN      // If statement without else
    {
        backpatch($4->nextlist, nextinstr());               // Nextlist of N goes to nextinstr
        convertIntToBool($3);                               // Convert expression to bool
        $$  =  new Statement();                             // Make new statement
        backpatch($3->truelist, $6);                        // Is expression is true, go to M i.e just before statement body
        // Merge falselist of expression, nextlist of statement and second N
        list<int> temp  =  merge($3->falselist, $7->nextlist);   
        $$->nextlist  =  merge($8->nextlist, temp);
    }
    // If statement with else
    | IF ROUND_BRACKET_OPEN expression N ROUND_BRACKET_CLOSE M statement N ELSE M statement   
    {
        backpatch($4->nextlist, nextinstr());               // Nextlist of N goes to nextinstr
        convertIntToBool($3);                               // Convert expression to bool
        $$  =  new Statement();                             // Make new statement
        backpatch($3->truelist, $6);                        // When expression is true, go to M1 else go to M2
        backpatch($3->falselist, $10);
        // Merge the nextlists of the statements and second N
        list<int> temp  =  merge($7->nextlist, $8->nextlist);       
        
        $$->nextlist  =  merge($11->nextlist,temp); 
    }
    | SWITCH ROUND_BRACKET_OPEN expression ROUND_BRACKET_CLOSE statement     
    {  /* Ignored */ }       // Not to be modelled
    ;

iteration_statement: 
    WHILE W ROUND_BRACKET_OPEN X changetable M expression ROUND_BRACKET_CLOSE M loop_statement      // While statement
    {   
        $$  =  new Statement();                             // Create statement
        convertIntToBool($7);                               // Convert expression to bool
        backpatch($10->nextlist, $6);                       // M1 to go back to expression again
        backpatch($7->truelist, $9);                        // M2 to go to statement if the expression is true
        $$->nextlist  =  $7->falselist;                     // When expression is false, move out of loop
        // Emit to prevent fallthrough
        string str = convertIntToString($6);        
        emit("goto",str);   
        loop_name  =  "";
        changeTable(ST->parent);
    }
    |
    WHILE W ROUND_BRACKET_OPEN X changetable M expression ROUND_BRACKET_CLOSE CURLY_BRACKET_OPEN M block_item_list_opt CURLY_BRACKET_CLOSE     // While statement
    {   
        $$  =  new Statement();                             // Create statement
        convertIntToBool($7);                               // Convert expression to bool
        backpatch($11->nextlist, $6);                       // M1 to go back to expression again
        backpatch($7->truelist, $10);                       // M2 to go to statement if the expression is true
        $$->nextlist  =  $7->falselist;                     // When expression is false, move out of loop
        // Emit to prevent fallthrough
        string str = convertIntToString($6);        
        emit("goto",str);   
        loop_name  =  "";
        changeTable(ST->parent);
    }
    | DO D M loop_statement M WHILE ROUND_BRACKET_OPEN expression ROUND_BRACKET_CLOSE SEMICOLON      //do statement
    {
        $$  =  new Statement();                             // Create statement 
        convertIntToBool($8);                               // Convert to bool
        backpatch($8->truelist, $3);                        // M1 to go back to statement if expression is true
        backpatch($4->nextlist, $5);                        // M2 to go to check expression if statement is complete
        $$->nextlist  =  $8->falselist;                     // Move out if statement is false
        loop_name  =  "";
    }
    | DO D CURLY_BRACKET_OPEN M block_item_list_opt CURLY_BRACKET_CLOSE M WHILE ROUND_BRACKET_OPEN expression ROUND_BRACKET_CLOSE SEMICOLON      // do statement
    {
        $$  =  new Statement();                             // Create statement 
        convertIntToBool($10);                              // Convert to bool
        backpatch($10->truelist, $4);                       // M1 to go back to statement if expression is true
        backpatch($5->nextlist, $7);                        // M2 to go to check expression if statement is complete
        $$->nextlist  =  $10->falselist;                    // Move out if statement is false
        loop_name  =  "";
    }
    | FOR F ROUND_BRACKET_OPEN X changetable declaration M expression_statement M expression N ROUND_BRACKET_CLOSE M loop_statement     // For loop
    {
        $$  =  new Statement();                             // Create new statement
        convertIntToBool($8);                               // Convert check expression to boolean
        backpatch($8->truelist, $13);                       // If expression is true, go to M2
        backpatch($11->nextlist, $7);                       // After N, go back to M1
        backpatch($14->nextlist, $9);                       // Statement go back to expression
        string str = convertIntToString($9);
        emit("goto", str);                                  // Prevent fallthrough
        $$->nextlist  =  $8->falselist;                     // Move out if statement is false
        loop_name  =  "";
        changeTable(ST->parent);
    }
    | FOR F ROUND_BRACKET_OPEN X changetable expression_statement M expression_statement M expression N ROUND_BRACKET_CLOSE M loop_statement     // For loop
    {
        $$  =  new Statement();                             // Create new statement
        convertIntToBool($8);                               // Convert check expression to boolean
        backpatch($8->truelist, $13);                       // If expression is true, go to M2
        backpatch($11->nextlist, $7);                       // After N, go back to M1
        backpatch($14->nextlist, $9);                       // Statement go back to expression
        string str = convertIntToString($9);
        emit("goto", str);                                  // Prevent fallthrough
        $$->nextlist  =  $8->falselist;                     // Move out if statement is false
        loop_name  =  "";
        changeTable(ST->parent);
    }
    | FOR F ROUND_BRACKET_OPEN X changetable declaration M expression_statement M expression N ROUND_BRACKET_CLOSE M CURLY_BRACKET_OPEN block_item_list_opt CURLY_BRACKET_CLOSE      // For loop
    {
        $$  =  new Statement();                             // Create new statement
        convertIntToBool($8);                               // Convert check expression to boolean
        backpatch($8->truelist, $13);                       // If expression is true, go to M2
        backpatch($11->nextlist, $7);                       // After N, go back to M1
        backpatch($15->nextlist, $9);                       // Statement go back to expression
        string str = convertIntToString($9);
        emit("goto", str);                                  // Prevent fallthrough
        $$->nextlist  =  $8->falselist;                     // Move out if statement is false
        loop_name  =  "";
        changeTable(ST->parent);
    }
    | FOR F ROUND_BRACKET_OPEN X changetable expression_statement M expression_statement M expression N ROUND_BRACKET_CLOSE M CURLY_BRACKET_OPEN block_item_list_opt CURLY_BRACKET_CLOSE
    {   
        $$  =  new Statement();                             // Create new statement
        convertIntToBool($8);                               // Convert check expression to boolean
        backpatch($8->truelist, $13);                       // If expression is true, go to M2
        backpatch($11->nextlist, $7);                       // After N, go back to M1
        backpatch($15->nextlist, $9);                       // Statement go back to expression
        string str = convertIntToString($9);
        emit("goto", str);                                  // Prevent fallthrough
        $$->nextlist  =  $8->falselist;                     // Move out if statement is false
        loop_name  =  "";
        changeTable(ST->parent);
    }
    ;

jump_statement
    : GOTO IDENTIFIER SEMICOLON 
    { 
        $$  =  new Statement(); 
        label *l  =  find_label($2->name);
        if(l){
            emit("goto","");
            list<int>lst  =  makelist(nextinstr());
            l->nextlist  =  merge(l->nextlist,lst);
            if(l->addr!= -1)
                backpatch(l->nextlist,l->addr);
        } else {
            l  =  new label($2->name);
            l->nextlist  =  makelist(nextinstr());
            emit("goto","");
            label_table.push_back(*l);
        }
    }           
    | CONTINUE SEMICOLON { $$  =  new Statement(); }        // Not to be modelled
    | BREAK SEMICOLON { $$  =  new Statement(); }           // Not to be modelled
    | RETURN expression SEMICOLON               
    {
        $$  =  new Statement();
        emit("return",$2->loc->name);                       //emit return with the name of the return value
        
    }
    | RETURN SEMICOLON 
    {
        $$  =  new Statement();
        emit("return","");                                  // Simply emit return
    }
    ;


/* External Definitions ------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

translation_unit
    : external_declaration     
    {  /* Ignored */ }
    | translation_unit external_declaration     
    {  /* Ignored */ } 
    ;

external_declaration
    : function_definition 
    {  /* Ignored */ }
    | declaration   
    {  /* Ignored */ }
    ;

function_definition
    :declaration_specifiers declarator declaration_list_opt changetable CURLY_BRACKET_OPEN block_item_list_opt CURLY_BRACKET_CLOSE
    {
        int next_instr = 0;     
        ST->parent = globalST;
        table_count  =  0;
        label_table.clear();
        changeTable(globalST);                              // Once we come back to this at the end, change the table to global Symbol table
    }
    ;

declaration_list
    : declaration   
    {  /* Ignored */ }
    | declaration_list declaration    
    {  /* Ignored */ }
    ;                                                                          

declaration_list_opt
    : /* empty */ 
    {  /* Ignored */ }
    | declaration_list   
    {  /* Ignored */ }
    ;

%%
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Auxillary Functions */

void yyerror(string s) {                                    // Print syntax error
    cout<<s<<endl;
}

