/* Suhas Jain | 19CS30048    */
/* Monal Prasad  | 19CS30030    */
/* Data Structures, Function Implementations & Translator main() */
#include "ass5_19CS30048_19CS30030_translator.h"
#include <sstream>
#include <string>
#include <iostream>
using namespace std;


// Reference to global variables declared in header file                                              
symtable* globalST;                             // Global Symbol Table                       
quadArray Q;                                    // Quad Array                                
string var_type;                                // Stores latest type                
symtable* ST;                                   // Points to current symbol table            
sym* currSymbolPtr;                             // Points to current symbol                  
basicType bt;                                   // Basic types                                                   
long long int instr_count;                      // Count of instr (used for sanity check)                            
long long int table_count;                      // Count of table
bool debug_on;                                  // Bool for printing debug output                                    
void printpattern(){cout<<"";}                  // Used for debugging                                              
string loop_name;                               // Get the name of the loop
vector<label>label_table;                       // Table to store the labels


symboltype::symboltype(string type,symboltype* arrtype,int width)        // Constructor for a symbol type
{
    (*this).type = type;
    (*this).width = width;
    (*this).arrtype = arrtype;
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Implementation of the Symbol Element Class functions */
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

sym::sym(string name, string t, symboltype* arrtype, int width)
{     
                                                // Symbol table entry                                                                           
    printpattern();
    (*this).name = name;
    printpattern();
    type = new symboltype(t,arrtype,width);       // Generate type of symbol                
    printpattern();
    size = computeSize(type);                       // Find the size from the type              
    printpattern();
    offset = 0;                                   // Put offset as 0                        
    printpattern();
    val = "-";                                    // No initial value                       
    printpattern();
    nested = NULL;                                // No nested table                        
    printpattern();
}

sym* sym::update(symboltype* t)
{
    printpattern();
    type = t;                                       // Update the new type                                                                                           
    printpattern();
    (*this).size = computeSize(t);                  // New size                                      
    printpattern();
    return this;                                // Return the same variable                      
}

label::label(string _name, int _addr):name(_name),addr(_addr){}

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Implementation of the Symbol Table functions  */
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

symtable::symtable(string name)                 // Constructor for a symbol table
{
    (*this).name = name;        
    printpattern();                             // Initialize the name of the symbol table
    count = 0;       
    printpattern();                             // Put count of number of temporary variables as 0
}

sym* symtable::lookup(string name)              // Lookup an symbol in the symbol table, whether it exists or not
{
    sym* symbol;
    list<sym>::iterator it;                     // It is list iterator (pointer) for list of symbols
    it = table.begin();                         // Start a linear search from the first element in the table

    while(it != table.end()) 
    {
        if(it->name  ==  name) 
            return &(*it);                      // If the name of the symbol is found in the table then return the address of the element
        it++;                                   // Otherwise continue the search
    }

    sym *ptr = nullptr;
    if(this->parent)
        ptr = this->parent->lookup(name);

    /*
     * If the symbol has not been found 
     * in the symbol table then craete 
     * a new entry for the symbol table
     * and insert in the table
     */
    if(ST == this && !ptr){
        symbol = new sym(name);
        table.push_back(*symbol);               // Push the symbol into the table
        return &table.back();                   // Return the symbol
    }
    else if(ptr)
    {
        return ptr;
    }

    return nullptr;
}

void symtable::update()                         // Update the symbol table and the offsets in it
{
    list<symtable*> tb;                         // List of tables
    int off;
    list<sym>::iterator it;                     // List iterator for elements in the symbol table
    it = table.begin();
    while(it != table.end())                        // Traversing the symbol table
    {
        if(it != table.begin()) 
        {
            it->offset=off;
            off=it->offset+it->size;            // Subsequent offset is the sum of the current offset and the space occupied by the current element            
        }
        else 
        {
            it->offset=0;                       // Initial offset should be 0
            off = it->size;
        }
        if(it->nested != NULL) 
            tb.push_back(it->nested);
        it++;
    }

    list<symtable*>::iterator it1;              // List iterator for the nested tables
    it1 = tb.begin();
    while(it1 != tb.end())                      // Recursively update all the nested tables 
    {
        (*it1)->update();
        it1++;
    }
}

void symtable::print()                          // Print a symbol table
{
    int next_instr = 0;
    list<symtable*> tb;                         // List of tables

    for(int t1 = 0; t1 < 50; t1++) 
        cout << "--";                           // Just for design/formatting

    cout << "\n";
    cout << "Table Name: " << (*this).name;
    generateSpaces(28 - (*this).name.length()); // Table name
    cout << " Parent Name: ";          
    
    if(((*this).parent==NULL))
        cout << "NULL" << "\n";
    else
        cout << (*this).parent->name << "\n"; 

    for(int ti=0;ti<50;ti++) 
        cout << "--";

    cout << "\n";

    cout << "Name";                             // Name
    generateSpaces(16);

    cout << "Type";                             // Type
    generateSpaces(16);

    cout << "Initial Value";                    // Initial Value
    generateSpaces(7);

    cout << "Size";                             // Size
    generateSpaces(11);

    cout << "Offset";                           // Offset
    generateSpaces(9);

    cout << "Nested" << "\n";                   // Nested symbol table

    for(int t1 = 0; t1 < 50; t1++) 
        cout << "--";                           // Just for design/formatting

    cout << "\n";

    for(list<sym>::iterator it=table.begin(); it!=table.end(); it++) {          // Iterate through all the elements in the symbol table and print their details
    
        cout << it->name;                                                       // Print name of the symbol entry   
        generateSpaces(20-it->name.length());

        string rec_type=printType(it->type);                                    // Use PrintType to print type of the symbol entry
        cout << rec_type;
        generateSpaces(20-rec_type.length());

        cout << it->val;                                                        // Print initial value of the current symbol table entry
        generateSpaces(20-it->val.length());

        cout << it->size;                                                       // Print size of the current symbol table entry
        generateSpaces(15-to_string(it->size).length());

        cout << it->offset;                                                     // Print offset of the current symbol entry
        generateSpaces(15-to_string(it->offset).length());

        if(it->nested==NULL) {                                                  // Print nested table's name if it exists
            cout << "NULL" << "\n";
        }
        else {
            cout << it->nested->name << "\n";   
            tb.push_back(it->nested);                                           // Insert the names of the nested tables that need to be recursively printed
        }
    }
 
    for(int i=0;i<100;i++) 
        cout << "-";

    cout << "\n\n";

    for(list<symtable*>::iterator it=tb.begin(); it !=tb.end();++it) 
    {
        (*it)->print();         //Print symbol table
    }
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Implementation of the Quad functions  */
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

//----------------Constrtuctors overloaded----------------------

//general constructor for quad when arg1 is string
quad::quad(string res,string arg1,string op,string arg2)           
{                                                               
    //initialise class members using the paramters 
    printpattern();
    (*this).res = res;
    printpattern();
    (*this).arg1 = arg1;                            // Assign value of arg1 directly    
    printpattern();
    (*this).op = op;
    printpattern();
    (*this).arg2 = arg2;
    printpattern();
}

//general constructor for quad when arg1 is int
quad::quad(string res,int arg1,string op,string arg2)             
{
    printpattern();
    (*this).res = res;
    printpattern();
    (*this).arg2 = arg2;
    printpattern();
    (*this).op = op;
    printpattern();
    (*this).arg1 = convertIntToString(arg1);        // Convert arg1 to string and assign 
    printpattern();
}

//general constructor for quad when arg1 is float
quad::quad(string res,float arg1,string op,string arg2)          
{
    printpattern();
    (*this).res = res;
    printpattern();
    (*this).arg2 = arg2;
    printpattern();
    (*this).op = op;
    printpattern();
    (*this).arg1 = convertFloatToString(arg1);  // Convert arg1 to string and assign 
    printpattern();
}

//------------- Helper function to print the quads -----------------
void quad::print() 
{                                               // Print a quad
    // Binary Operations
    int next_instr = 0; 
    if(op == "+")
    {   
        printpattern(); 
        (*this).type1();
    }
    else if(op == "-")
    {               
        printpattern();
        (*this).type1();
    }
    else if(op == "*")
    {
        printpattern();
        (*this).type1();
    }
    else if(op == "/")
    {   
        printpattern(); 
        (*this).type1();
    }
    else if(op == "%")
    {
        printpattern();
        (*this).type1();
    }
    else if(op == "|")
    {
        printpattern();
        (*this).type1();
    }
    else if(op == "^")
    {
        printpattern(); 
        (*this).type1();
    }
    else if(op == "&")
    {
        printpattern();             
        (*this).type1();
    }

    // Relational Operations
    else if(op == "==")
    {
        printpattern();
        (*this).type2();
    }
    else if(op == "!=")
    {
        printpattern();
        (*this).type2();
    }
    else if(op == "<=")
    {
        printpattern();
        (*this).type2();
    }
    else if(op == "<")
    {   
        printpattern();         
        (*this).type2();
    }
    else if(op == ">")
    {
        printpattern();
        (*this).type2();
    }
    else if(op == ">=")
    {
        printpattern();             
        (*this).type2();
    }
    else if(op == "goto")
    {
        printpattern();             
        cout << "goto " << res;
    }   

    // Shift Operations
    else if(op == ">>")
    {
        printpattern();
        (*this).type1();
    }
    else if(op == "<<")
    {
        printpattern();             
        (*this).type1();
    }
    else if(op == "=")
    {
        printpattern();             
        cout << res << " = " << arg1 ;
    }                   
    //Unary Operators..
    else if(op == "=&")
    {
        printpattern();             
        cout << res << " = &" << arg1;
    }
    else if(op == "=*")
    {
        printpattern();
        cout << res  << " = *" << arg1 ;
    }
    else if(op == "*=")
    {   
        printpattern();         
        cout << "*" << res   << " = " << arg1 ;
    }
    else if(op == "uminus")
    {
        printpattern();
        cout << res << " = -" << arg1;
    }
    else if(op == "~")
    {
        printpattern();             
        cout << res << " = ~" << arg1;
    }
    else if(op == "!")
    {
        printpattern();
        cout << res << " = !" << arg1;
    }

    //Other operations
    else if(op == "=[]")
    {
        printpattern();
        cout << res << " = " << arg1 << "[" << arg2 << "]";
    }
    else if(op == "[]=")
    {   
        printpattern(); 
        cout << res << "[" << arg1 << "]" << " = " <<  arg2;
    }
    else if(op == "return")
    {
        printpattern();             
        cout << "return " << res;
    }
    else if(op == "param")
    {
        printpattern();             
        cout << "param " << res;
    }
    else if(op == "call")
    {
        printpattern();             
        cout << res << " = " << "call " << arg1 << ", " << arg2;
    }
    else if(op == "label")
    {
        printpattern();
        cout << res << ": ";
    }   
    else
    {   
        cout << "Can't find " << op;                // if invalid operator is entered
    }           
    cout << "\n";
    
}
void quad::type1()
{
    printpattern();
    cout << res << " = " << arg1 << " " << op << " " << arg2;
    printpattern();
}
void quad::type2()
{
    printpattern();
    cout << "if " << arg1 <<  " " << op << " " << arg2 << " goto " << res;
    printpattern();
}


/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Implementation of the Basic Type functions */
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void basicType::addType(string t, int s)        // Add new trivial type to type Symbol table
{
    printpattern();
    type.push_back(t);
    printpattern();
    size.push_back(s);
    printpattern();
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* Implementation of the Quad Array Class functions */
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void quadArray::print()                                 // Print the quad Array i.e the list of TAC
{
    for(int i=0;i<50;i++) 
        cout << "--";
    cout << "\n";
    cout << "Three Address Code (TAC):" << "\n";        // Print TAC heading 

    for(int i=0;i<50;i++){
        cout << "--";
    }
    cout << "\n";

    int j=0;
    vector<quad>::iterator it;
    it=Array.begin();
    while(it!=Array.end()) 
    {
        if(it->op == "label") 
        {                                               // Printing the labels
            cout << "\n" << "L" << j << ": ";
            it->print();
        }
        else {                                          // Otherwise give 4 spaces and then print
            cout << "L" << j << ": ";
            generateSpaces(4);
            it->print();
        }
        it++;j++;
    }

    cout << "\n";
    for(int i=0;i<50;i++) 
        cout << "--";
    cout << "\n";
    cout << "Symbol Tables: " << "\n";                  // Print symbol table heading 

    for(int i=0;i<50;i++){
        cout << "--";
    }
    cout << "\n" << "\n";
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*  Overloaded emit function used by the parser */
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

//----------------- Emit a three address code TAC and add it to the Quad Array ------------

// Function if arg1 is string 
void emit(string op, string res, string arg1, string arg2) 
{
    //Input: arguments of the new quad to be generated
    //Purpose: Emit a three address code and add it to the Quad Array
    quad *q1= new quad(res,arg1,op,arg2);
    printpattern();
    Q.Array.push_back(*q1);
}

// Function if arg1 is int 
void emit(string op, string res, int arg1, string arg2) 
{
    //Input: arguments of the new quad to be generated
    //Purpose: Emit a three address code and add it to the Quad Array
    quad *q2 = new quad(res,arg1,op,arg2);
    printpattern();
    Q.Array.push_back(*q2);
}

// Function if arg1 is float 
void emit(string op, string res, float arg1, string arg2) 
{
    //Input: arguments of the new quad to be generated
    //Purpose: Emit a three address code and add it to the Quad Array
    quad *q3 = new quad(res,arg1,op,arg2);
    printpattern();
    Q.Array.push_back(*q3);
}


sym* gentemp(symboltype* t, string str_new)     
{   
    //Purpose: Generate name of temporary variable and insert to current the symbol table                                        
    string tmp_name = "t"+convertIntToString(ST->count++);    
    sym* s = new sym(tmp_name);
    (*s).type = t;
    (*s).size=computeSize(t);                   // Calculate the size of the current symbol
    (*s).val = str_new;
    ST->table.push_back(*s);                    // Push the newly created symbol in the Symbol table
    return &ST->table.back();
}


label* find_label(string _name)
{
    // Input: Receives a string to be found 
    // Output: pointer to location of string in label table
    // Purpose:  Returns pointer to the location of _name in label_table
    for(vector<label>::iterator it=label_table.begin(); it!=label_table.end(); it++)
    {
        if(it->name == _name)
            return &(*it);
    }
    return nullptr;
}


/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*  Implementation of backpatching and related functions */
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void backpatch(list<int> list1,int addr)        // Backpatching
{
    //Input: list of integers and  size of the quad array
    string str = convertIntToString(addr);      // Get string form of the address
    list<int>::iterator it;
    it = list1.begin();
    printpattern();
    
    while( it!=list1.end()) 
    {
        Q.Array[*it].res=str;                   // Do the backpatching
        it++;
    }
}

list<int> makelist(int init) 
{
    // Input: integer argument
    // Purpose:  Make a new list containing an integer
    list<int> newlist(1,init);  
    printpattern();                             
    return newlist;                             // Return the newly created list
}

list<int> merge(list<int> &a,list<int> &b)
{
    // Input: two integer lists to be merged
    // Output: Merged integer list
    // Purpose: Merge two existing lists into a single list
    a.merge(b);      
    printpattern();                             // Merge two existing lists
    return a;                                   // Return the merged list
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*  Implementation of other helper functions */
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

//------------- Type checking and Type conversion functions -------------
string convertIntToString(int a)                        // Helper function 
{
    // Input: integer value
    // Output: string
    // Purpose :  convert int to string
    return to_string(a);
}

string convertFloatToString(float x)                    // helper function
{
    // Input: floating point value
    // Output: string
    // Purpose :  convert float to string
    std::ostringstream buff;
    buff << x;
    return buff.str();
}

Expression* convertIntToBool(Expression* e)             
{
    // Input: integer expression
    // Output: boolean expression
    // Purpose: Convert any Expression to bool using standard procedure
    if(e->type!="bool")                
    {
        e->falselist=makelist(nextinstr());             // Update the falselist
        emit("==","",e->loc->name,"0");                 // Emit general goto statements
        e->truelist=makelist(nextinstr());              // Update the truelist
        emit("goto","");
    }
    return e;
}

Expression* convertBoolToInt(Expression* e)             
{   
    // Input: Boolean expression
    // Output: Integer expression
    // Purpose: Convert any Expression to int using standard procedure
    if(e->type == "bool") 
    {
        e->loc=gentemp(new symboltype("int"));          // Use general goto statements and standard procedure
        backpatch(e->truelist,nextinstr());
        emit("=",e->loc->name,"true");
        int p=nextinstr()+1;
        string str=convertIntToString(p);
        emit("goto",str);
        backpatch(e->falselist,nextinstr());
        emit("=",e->loc->name,"false");
    }
    return e;
}

sym* convertType(sym* s, string rettype)                
{
    // input: pointer to symbol and the new type
    // Output: symbol with the updated type
    // Purpose: Convert symbol s into the required return type
    sym* temp=gentemp(new symboltype(rettype)); 

    if((*s).type->type == "float")                      // If type float
    {
        if(rettype == "char")                           // Or converting to char
        {
            emit("=",temp->name,"float2char("+(*s).name+")");
            return temp;
        }
        if(rettype == "int")                            // Converting float to int
        {
            emit("=",temp->name,"float2int("+(*s).name+")");
            return temp;
        }
        
        return s;
    }
    if((*s).type->type == "int")                        // If type int
    {
        if(rettype == "char")                           // Or converting to char
        {
            emit("=",temp->name,"int2char("+(*s).name+")");
            return temp;
        }
        if(rettype == "float")                          // Converting int to float
        {
            emit("=",temp->name,"int2float("+(*s).name+")");
            return temp;
        }
         
        return s;
    }
    if((*s).type->type == "char")                       // If type char
    {
        if(rettype == "double")                         // Or converting to double
        {
            emit("=",temp->name,"char2double("+(*s).name+")");
            return temp;
        }
        if(rettype == "int")                            // Converting char to int
        {
            emit("=",temp->name,"char2int("+(*s).name+")");
            return temp;
        }

        return s;
    }
    return s;
}

void changeTable(symtable* newtable)            
{
    //Input: receives a new symbol table as argument 
    //Purpose: Change current symbol table
    printpattern();
    ST = newtable;
    printpattern();
} 

bool compareSymbolType(sym*& s1,sym*& s2)       
{
    // Input: 2 symbols
    // Output: returns true if the types are the same
    //Purpose: Check if the symbols have same type or not
    //get the base types
    printpattern();
    symboltype* type1=s1->type;      
    printpattern();
    symboltype* type2=s2->type;

    int flag=0;

    if(compareSymbolType(type1,type2)) 
        flag=1;       
    else if(s1=convertType(s1,type2->type)) 
        flag=1;                                 // If one can be converted to the other. convert them
    else if(s2=convertType(s2,type1->type)) 
        flag=1;

    if(flag)
        return true;
    else 
        return false;                           // Else return false
}

bool compareSymbolType(symboltype* t1,symboltype* t2)                                          
{
    // Input: 2 symbol types
    // Output: returns true if the types are the same
    // Purpose: Check if the symbols types are same or not
    int flag=0;
    if(t1 == NULL && t2 == NULL)                                    // If both symbol types are NULL
        flag=1;            
    else if(t1 == NULL || t2 == NULL || t1->type!=t2->type)         // If only one of them is NULL or if base type isn't same
        flag=2;                                         
    
    if(flag == 1)                                                   // Otherwise check their Array type
        return true;
    if(flag == 2) 
        return false;
    
    return compareSymbolType(t1->arrtype,t2->arrtype);                                             
}

void generateSpaces(int n)                                          
{
    //Input: number of spaces required
    //Purpose: Generate required number of spaces
    while(n--) std::cout << " ";
}

int nextinstr() 
{
    //Purpose: returns the size of the quad array
    return Q.Array.size();                                          // Next instruction will be 1+last index and lastindex=size-1. hence return size
}

int computeSize(symboltype* t)                                      
{
    //Input: the type of symbol
    //Output: size of the the symbol type
    // Purpose: Calculate size of the required symbol type 

    if(t->type.compare("void") == 0)    
        return bt.size[1];
    if(t->type.compare("char") == 0) 
        return bt.size[2];
    if(t->type.compare("int") == 0) 
        return bt.size[3];
    if(t->type.compare("float") == 0) 
        return bt.size[4];
    if(t->type.compare("arr") == 0) 
        return t->width*computeSize(t->arrtype);                    // Recursive for arr1s(Multidimensional arr1s)
    if(t->type.compare("ptr") == 0) 
        return bt.size[5];
    if(t->type.compare("func") == 0) 
        return bt.size[6];
    
    return -1;
}

string printType(symboltype* t)                                     
{
    // Input: pointer to a symboltype
    // Output: name of basic type 
    // Purpose:  Print type of variable. This is important for multidimensional arrays
    if(t == NULL) 
        return bt.type[0];
    if(t->type.compare("void") == 0)    
        return bt.type[1];
    if(t->type.compare("char") == 0) 
        return bt.type[2];
    if(t->type.compare("int") == 0) 
        return bt.type[3];
    if(t->type.compare("float") == 0) 
        return bt.type[4];
    if(t->type.compare("ptr") == 0) 
        return bt.type[5]+"("+printType(t->arrtype)+")";            // Recursive for ptr     
    if(t->type.compare("arr") == 0)                                 
    {
        string str=convertIntToString(t->width);        
        return bt.type[6]+"("+str+","+printType(t->arrtype)+")";    // Recursive for arrays
    }
    if(t->type.compare("func") == 0) 
        return bt.type[7];
    if(t->type.compare("block") == 0)    
        return bt.type[8];
    return "NA";
}

int main()
{    
    bt.addType("null",0);                       // Add base types initially
    bt.addType("void",0);
    bt.addType("char",1);
    bt.addType("int",4);
    bt.addType("float",8);
    bt.addType("ptr",4);
    bt.addType("arr",0);
    bt.addType("func",0);
    bt.addType("block",0);

    label_table.clear();

    table_count = 0;                            // Count of nested table
    debug_on= 0;                                // Debugging is off
    globalST=new symtable("Global");            // Global Symbol Table
    ST=globalST;
    loop_name = "";

    yyparse();                                  // Initialize parse
    globalST->update();                         // Update the global Symbol Table
    cout << "\n";

    Q.print();                                  // Print the three address codes
    globalST->print();                          // Print all Symbol Tables
};
