#ifndef _TRANSLATE_H
#define _TRANSLATE_H

#include <bits/stdc++.h>

extern  char* yytext;
extern  int yyparse();

using namespace std;

#define lsit list<sym>::iterator
#define listi list<int>
#define lstsym list<sym>

class sym;                      // Stands for an entry in ST
class label;
class symboltype;               // Stands for the type of a symbol in ST
class symtable;                 // Stands for ST
class quad;                     // Stands for a single entry in the quad Array
class quadArray;                // Stands for the Array of quads
class basicType;                // Stands for the basic type data
class Expression;               // Standsfor the expression type data storage

typedef sym s;
typedef symboltype symtyp;
typedef Expression* Exps;

extern symtable* ST;                        // Denotes the current Symbol Table
extern symtable* globalST;                  // Denotes the Global Symbol Table
extern s* currSymbolPtr;                    // Denotes the latest encountered symbol
extern quadArray Q;                         // Denotes the quad Array
extern basicType bt;                        // Denotes the Type ST
extern long long int instr_count;           // Denotes count of instr
extern long long int table_count;
extern bool debug_on;                       // bool for printing debug output
extern string loop_name;                    // get the name of the loop
extern vector<label>label_table;

class sym 
{                      // For an entry in ST, we have
    public:
        string name;                // Denotes the name of the symbol
        symboltype *type;           // Denotes the type of the symbol
        int size;                   // Denotes the size of the symbol
        int offset;                 // Denotes the offset of symbol in ST
        symtable* nested;           // Points to the nested symbol table
        string val;                 // Initial value of the symbol if specified

        // Constructor
        sym (string , string t="int", symboltype* ptr = NULL, int width = 0);
        // Update the ST Entry 
        sym* update(symboltype*);   // A method to update different fields of an existing entry.
};

class label                                         // Class of label symbols
{
    public:
        string name;                                // Stores the name of the label
        int addr;                                   // Stores the address the label is pointing to
        list<int> nextlist;                         // list of dangling goto statements

        label(string _name, int _addr = -1);        // Label
};

class symboltype 
{                                                   // For the Type of Symbol, we have
    public:
        string type;                                // Stores the type of symbol. 
        int width;                                  // Stores the size of Array (if we encounter an Array) and it is 1 in default case
        symboltype* arrtype;                        // For arr1s which are multidimensional, we need this
        //Constructor
        symboltype(string , symboltype* ptr = NULL, int width = 1);
};

class symtable 
{                                                   // For the Symbol Table Class, we have
    public:
        string name;                                // Name of the Table
        int count;                                  // Count of the temporary variables
        lstsym table;                               // The table of symbols which is essentially a list of sym
        symtable* parent;                           // Parent ST of the current ST
        //Constructor
        symtable (string name="NULL");
        //Lookup for a symbol in ST
        s* lookup (string);     
        //Print the ST                      
        void print();   
        //Update the ST                                     
        void update();                                          
};

class quad 
{                                                   // A single quad has four components:
    public:
        string res;                                 // Result
        string op;                                  // Operator
        string arg1;                                // Argument 1
        string arg2;                                // Argument 2

        // Print the Quad
        void print();   
        void type1();      // Common printing types
        void type2();

        // Constructors                         
        quad (string , string , string op = "=", string arg2 = "");         
        quad (string , int , string op = "=", string arg2 = "");                
        quad (string , float , string op = "=", string arg2 = "");          
};

class quadArray 
{       //Quad Array
    public:
        vector<quad> Array;                         // Simply an Array (vector) of quads
        //Print the quadArray
        void print();                               
};

class basicType 
{                                                   // To denote a basic type
    public:
        vector<string> type;                        // Type name
        vector<int> size;                           // Size
        void addType(string ,int );
};

struct Expression {
    s* loc;                                         // Pointer to the symbol table entry
    string type;                                    // To store whether the expression is of type int or bool or float or char
    list<int> truelist;                             // Fruelist for boolean expressions
    list<int> falselist;                            // Falselist for boolean expressions
    list<int> nextlist;                             // For statement expressions
};

struct Array {
    string atype;                                   // Used for type of Array: may be "ptr" or "arr" type
    s* loc;                                         // Location used to compute address of Array
    s* Array;                                       // Pointer to the symbol table entry
    symboltype* type;                               // type of the subarr1 generated (important for multidimensional arr1s)
};

struct Statement {
    list<int> nextlist;                             // Nextlist for Statement with dangling exit
};

//Emit Functions
void emit(string , string , string arg1="", string arg2 = "");  
void emit(string , string , int, string arg2 = "");       
void emit(string , string , float , string arg2 = "");   

s* gentemp (symboltype* , string init = "");        // Generate a temporary variable and insert it in the current ST

//Backpatching and related functions
void backpatch (list <int> , int );
listi makelist (int );                              // Make a new list contaninig an integer
listi merge (list<int> &l1, list <int> &l2);        // Merge two lists into a single list

label* find_label(string name);
string convertIntToString(int );
string convertFloatToString(float );
Exps convertIntToBool(Exps);                        // Convert int expression to boolean
Exps convertBoolToInt(Exps);                        // Convert boolean expression to int


//Type checking and conversion functions
s* convertType(sym*, string);                       // For type conversion
bool compareSymbolType(sym* &s1, sym* &s2);         // Check for same type of two symbol table entries
bool compareSymbolType(symboltype*, symboltype*);   // Check for same type of two symboltype objects
int computeSize (symboltype *);                     // Calculate size of symbol type
void changeTable (symtable* );                      // To change current table

int nextinstr();                                    // Returns the next instruction number
void generateSpaces(int );
string printType(symboltype *);                     // Print type of symbol


#endif