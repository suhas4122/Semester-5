#include "ass6_19CS30048_19CS30030_translator.h"
#include "y.tab.h"
#include <iomanip>
#include <iostream>

using namespace std;

type_n *glob_type;
int glob_width;
int next_instr;
int temp_count=0;
symtab *glob_st =new symtab();
symtab *curr_st = new symtab();
quad_arr glob_quad;
vector <string> vs;
vector <string> cs;
int size_int=4;
int size_double=8;
int size_pointer=8;
int size_char=1;
int size_bool=1;
vector<string> strings_label;

type_n::type_n(types t,int sz,type_n *n)
// Constructor for type_n
{
	basetp=t;
	size=sz;
	next=n;
}

int type_n::getSize()
{
	if(this==NULL)
		return 0;
	//return the size of the Array by calling the recursive function 
	//here we are not checking for null as if it will reach the final type it will enter the below conditions
	if((this->basetp) == tp_arr)
		return ((this->size)*(this->next->getSize()));
	if((this->basetp) == tp_void)
		return 0;
	if((this->basetp) == tp_int)
		return size_int;
	if((this->basetp) == tp_double)
		return size_double;
	if((this->basetp) == tp_bool)
		return size_bool;
	if((this->basetp) == tp_char)
		return size_char;
	if((this->basetp) == tp_ptr)
		return size_pointer;
	return 0;
}

types type_n::getBasetp()
{
	// returns the base type
	if(this!=NULL)
		return this->basetp;
	else
		return tp_void;
}

void type_n::printSize()
{
	// prints the size
	printf("%d\n",size);
}

void type_n::print()
{
	// prints the data type
	switch(basetp){
		case tp_void:
				printf("Void");
				break;
		case tp_bool:
				printf("Bool");
				break;
		case tp_int:
				printf("Int");
				break;
		case tp_char:
				printf("Char");
				break;
		case tp_double:
				printf("Double");
				break;
		case tp_ptr:
				printf("ptr(");
				if(this->next!=NULL)
					this->next->print();
				printf(")");
				break;
		case tp_arr:
				printf("Array(%d,",size);
				if(this->next!=NULL)
					this->next->print();
				printf(")");
				break;
		case tp_func:
				printf("Function()");
				break;
		default:
			printf("TYPE NOT FOUND\n");
			exit(-1);
	}

}

Array::Array(string s,int sz,types t)
{
	// constructor for Array
	this->base_arr=s;
	this->tp=t;
	this->bsize=sz;
	this->dimension_size=1;
}

void Array::addindex(int i)
{
	// Adds an Array index for Array accessing 
	this->dimension_size=this->dimension_size+1;
	this->dims.push_back(i);
}

void funct::print()
{
	// Prints details in suitable format
	printf("Funct(");
	int i;
	for(i=0;i<typelist.size();i++)
	{
		if(i!=0)
			printf(",");
		printf("%d ",typelist[i]);
	}
	printf(")");
}

funct::funct(vector<types> tpls)
{
	// Constructor
	typelist=tpls;
}
symdata::symdata(string n)
{
	// Constructor
	name=n;
	size=0;
	tp_n=NULL;
	offset=-1;
	var_type="";
	isInitialized=false;
	isFunction=false;
	isArray=false;
	ispresent=true;
	arr=NULL;
	fun=NULL;
	nest_tab=NULL;
	isdone=false;
	isptrarr=false;
	isGlobal=false;
}

void symdata::createarray()
{
	// creates a new array
	arr=new Array(this->name,this->size,tp_arr);
}


symtab::symtab()
{
	// constructor for symtab
	name="";
	offset=0;
	no_params=0;
}

symtab::~symtab()
{
	// destructor for symtab
	int i;
	for(i=0;i<symbol_tab.size();i++)
	{
		type_n *p1=symbol_tab[i]->tp_n;
		type_n *p2;
		while(true)
		{
			if(p1 == NULL)
				break;
			p2=p1;
			p1=p1->next;
			delete p2;
		}
	}
}
int symtab::findg(string n)
{
	for(int i=0;i<vs.size();i++)
	{
		if(vs[i]==n)
			return 1;
	}
	for(int i=0;i<cs.size();i++)
	{
		if(cs[i]==n)
			return 2;
	}
	return 0;
}
type_n *CopyType(type_n *t)
{
	/*Duplicates the input type and returns the pointer to the newly created type*/
	if(t == NULL) return t;
	type_n *ret = new type_n(t->basetp);

	ret->size = t->size;
	ret->basetp = t->basetp;

	ret->next = CopyType(t->next);
	return ret;
}

symdata* symtab::lookup(string n)
{
	// Lookup function searches the variable with name. 
	// If the variable is present then returns its pointer location 
	// else creates a new entry with its name and returns that pointer
	int i;
	for(i=0;i<symbol_tab.size();i++)
	{
		//printf("Flag1\n");
		if(symbol_tab[i]->name == n)
		{
			return symbol_tab[i];
		}
	}
	symdata *temp_o=new symdata(n);
	temp_o->i_val.int_val=0;
	symbol_tab.push_back(temp_o);
	return symbol_tab[symbol_tab.size()-1];
}

symdata* symtab::lookup_2(string n)
{
	// Similar to the lookup function.
	// This functiion is especially designed for the global variables
	int i;
	for(i=0;i<symbol_tab.size();i++)
	{

		if(symbol_tab[i]->name == n)
		{
			return symbol_tab[i];
		}
	}
	for(i=0;i<glob_st->symbol_tab.size();i++)
	{
		if(glob_st->symbol_tab[i]->name == n)
		{
			return glob_st->symbol_tab[i];
		}
	}
	symdata *temp_o=new symdata(n);
	temp_o->i_val.int_val=0;
	symbol_tab.push_back(temp_o);
	return symbol_tab[symbol_tab.size()-1];
}

symdata* symtab::search(string n)
{
	// It searches for the variable 
	// and returns the pointer to it if present
	int i;
	for(i=0;i<symbol_tab.size();i++)
	{
		if(symbol_tab[i]->name==n && symbol_tab[i]->ispresent)
		{
			return (symbol_tab[i]);
		}
	}
	
	return NULL;
}

symdata* symtab::gentemp(type_n *type)
{
	// This function creates a new element in the symbol table 
	// with the type provided at the time of constructing
	char c[10];
	sprintf(c,"t%03d",temp_count);
	temp_count++;
	symdata *temp=lookup(c);
	int temp_sz;
	if(type==NULL)
		temp_sz=0;
	else if((type->basetp) == tp_void)
		temp_sz=0;
	else if((type->basetp) == tp_int)
		temp_sz=size_int;
	else if((type->basetp) == tp_double)
		temp_sz=size_double;
	else if((type->basetp) == tp_bool)
		temp_sz=size_bool;
	else if((type->basetp) == tp_char)
		temp_sz=size_char;
	else if((type->basetp) == tp_ptr)
		temp_sz=size_pointer;
	else
		temp_sz=type->getSize();
	temp->size=temp_sz;
	temp->var_type="temp";
	temp->tp_n=type;
	temp->offset=this->offset;
	this->offset=this->offset+(temp->size);
	return temp;
}

void symtab::update(symdata *sm,type_n *type,basic_val initval,symtab *next)
{
	sm->tp_n=CopyType(type);
	sm->i_val=initval;
	sm->nest_tab=next;
	int temp_sz;
	if(sm->tp_n==NULL)
		temp_sz=0;
	else if(((sm->tp_n)->basetp) == tp_void)
		temp_sz=0;
	else if(((sm->tp_n)->basetp) == tp_int)
		temp_sz=size_int;
	else if(((sm->tp_n)->basetp) == tp_double)
		temp_sz=size_double;
	else if(((sm->tp_n)->basetp) == tp_bool)
		temp_sz=size_bool;
	else if(((sm->tp_n)->basetp) == tp_char)
		temp_sz=size_char;
	else if(((sm->tp_n)->basetp) == tp_ptr)
		temp_sz=size_pointer;
	else
		temp_sz=sm->tp_n->getSize();
	sm->size=temp_sz;
	sm->offset=this->offset;
	this->offset=this->offset+(sm->size);
	sm->isInitialized=false;
}

void symtab::print()
{
	// Prints the symbol table
	cout << "\n\n";
	for(int i = 0; i < 120; i++) {
		cout << "-";
    }
	cout << "\n";
	cout << "Symbol Table: " << setfill(' ') << left << setw(50) << this->name << "\n";
    for(int i = 0; i < 120; i++) {
        cout << '-';
    }
    cout << "\n";

	// Table Headers
    cout << setfill(' ') << left << setw(20) <<  "Name";
    cout << left << setw(20) << "Value";
    cout << left << setw(20) << "Variable Type";
    cout << left << setw(15) << "Size";
    cout << left << setw(15) << "Offset";
    cout << left << "Type" << "\n";

	for(int i = 0; i < 120; i++) {
        cout << '-';
    }
    cout << "\n";

    for(int i = 0; i<(symbol_tab).size(); i++)
    {
        if(symbol_tab[i]->ispresent==false)
        	continue;
        symdata * t = symbol_tab[i];

		cout << left << setw(20) << t->name;
		
        if(t->isInitialized)
        {
        	if((t->tp_n)->basetp == tp_char) cout << left << setw(20) << (t->i_val).char_val;
        	else if((t->tp_n)->basetp == tp_int) cout << left << setw(20) << (t->i_val).int_val;
        	else if((t->tp_n)->basetp == tp_double) cout << left << setw(20) << (t->i_val).double_val;
       	 	else cout << left << setw(20) << "-";
      	}
      	else
      		cout << left << setw(20) << "null";

        cout << left << setw(20) << t->var_type;
        cout << left << setw(15) << t->size;
        cout << left << setw(15) << t->offset;
		cout << left;

		if(t->var_type == "func"){
			cout << "ptr-to-St( " << t->nest_tab->name.c_str();
			cout << " ) ";
		}
		
		if(t->tp_n != NULL)
			(t->tp_n)->print();
		
		cout << "\n";
	}
	for(int i = 0; i < 120; i++) {
        cout << '-';
    }
}


list* makelist(int i)
{
	// Creates new list with only i in it 
	list *temp = (list*)malloc(sizeof(list));
	temp->index=i;
	temp->next=NULL;
	return temp;
}
list* merge(list *lt1,list *lt2)
{
	// Concatenate two lists and return pointer to the merged list
	list *temp = (list*)malloc(sizeof(list));
	list *p1=temp;
	int flag=0;
	list *l1=lt1;
	list *l2=lt2;
	while(l1!=NULL)
	{
		flag=1;
		p1->index=l1->index;
		if(l1->next!=NULL)
		{
			p1->next=(list*)malloc(sizeof(list));
			p1=p1->next;
		}
		l1=l1->next;
	}
	while(l2!=NULL)
	{
		if(flag==1)
		{
			p1->next=(list*)malloc(sizeof(list));
			p1=p1->next;
			flag=0;
		}
		p1->index=l2->index;
		if(l2->next!=NULL)
		{
			p1->next=(list*)malloc(sizeof(list));
			p1=p1->next;
		}
		l2=l2->next;
	}
	p1->next=NULL;
	// Pointer to the merged list is returned
	return temp;
}

quad::quad(opcode opc,string a1,string a2,string rs)
{
	// Constructor for quad
	this->op=opc;
	this->arg1=a1;
	this->result=rs;
	this->arg2=a2;
}

void quad::print_arg()
{
	// Print a quad in the suitable format
	printf("\t%s\t=\t%s\top\t%s\t",result.c_str(),arg1.c_str(),arg2.c_str());
}

quad_arr::quad_arr()
{
	// Construcor for quad_arr
	next_instr=0;
}
// Function overloading while emitting quad arrays
void quad_arr::emit(opcode opc, string arg1, string arg2, string result)
{
	// Emit function to be used when there are 3 inputs with the opcode
	if(result.size()!=0)
	{
		quad new_elem(opc,arg1,arg2,result);
		arr.push_back(new_elem);
	}
	else if(arg2.size()!=0)
	{
		quad new_elem(opc,arg1,"",arg2);
		arr.push_back(new_elem);
	}
	else if(arg1.size()!=0)
	{
		quad new_elem(opc,"","",arg1);
		arr.push_back(new_elem);
	}
	else
	{
		quad new_elem(opc,"","","");
		arr.push_back(new_elem);
	}
	next_instr=next_instr+1;
}
void quad_arr::emit2(opcode opc,string arg1, string arg2, string result)
{
	if(result.size()==0)
	{
		quad new_elem(opc,arg1,arg2,"");
		arr.push_back(new_elem);
	}
}
void quad_arr::emit(opcode opc, int val, string operand)
{
	// Emit function to be used when there is assignment of integer required
	char str[20];
	sprintf(str, "%d", val);
	if(operand.size()==0)
	{
		quad new_quad(opc,"","",str);
		arr.push_back(new_quad);
	}
	else
	{
		quad new_quad(opc,str,"",operand);
		arr.push_back(new_quad);
	}
	next_instr=next_instr+1;
}

void quad_arr::emit(opcode opc, double val, string operand)
{
	// Emit function to be used when there is assignment of double required
	char str[20];
	sprintf(str, "%lf", val);
	if(operand.size()==0)
	{
		quad new_quad(opc,"","",str);
		arr.push_back(new_quad);
	}
	else
	{
		quad new_quad(opc,str,"",operand);
		arr.push_back(new_quad);
	}
	next_instr=next_instr+1;
}

void quad_arr::emit(opcode opc, char val, string operand)
{
	// Emit function to be used when there is assignment of char required
	char str[20];
	sprintf(str, "'%c'", val);
	if(operand.size()==0)
	{
		quad new_quad(opc,"","",str);
		arr.push_back(new_quad);
	}
	else
	{
		quad new_quad(opc,str,"",operand);
		arr.push_back(new_quad);
	}
	next_instr=next_instr+1;
}

void quad_arr::print()
{
	// Print all the quads
	opcode op;
	string arg1;
	string arg2;
	string result;
	for(int i=0;i<next_instr;i++)
	{

		op=arr[i].op;
		arg1=arr[i].arg1;
		arg2=arr[i].arg2;
		result=arr[i].result;
		printf("%3d: ",i);
		if(Q_PLUS<=op && op<=Q_NOT_EQUAL)
	    {
	        printf("%s",result.c_str());
	        printf("\t=\t");
	        printf("%s",arg1.c_str());
	        printf(" ");
	        switch(op)
	        {
	            case Q_PLUS: printf("+"); break;
	            case Q_MINUS: printf("-"); break;
	            case Q_MULT: printf("*"); break;
	            case Q_DIVIDE: printf("/"); break;
	            case Q_MODULO: printf("%%"); break;
	            case Q_LEFT_OP: printf("<<"); break;
	            case Q_RIGHT_OP: printf(">>"); break;
	            case Q_XOR: printf("^"); break;
	            case Q_AND: printf("&"); break;
	            case Q_OR: printf("|"); break;
	            case Q_LOG_AND: printf("&&"); break;
	            case Q_LOG_OR: printf("||"); break;
	            case Q_LESS: printf("<"); break;
	            case Q_LESS_OR_EQUAL: printf("<="); break;
	            case Q_GREATER_OR_EQUAL: printf(">="); break;
	            case Q_GREATER: printf(">"); break;
	            case Q_EQUAL: printf("=="); break;
	            case Q_NOT_EQUAL: printf("!="); break;
	        }
	        printf(" ");
	       	printf("%s\n",arg2.c_str());
	    }
	    else if(Q_UNARY_MINUS<=op && op<=Q_ASSIGN)
	    {
	        printf("%s",result.c_str());
	        printf("\t=\t");
	        switch(op)
	        {
	            
	            case Q_UNARY_MINUS : printf("-"); break;
	            case Q_UNARY_PLUS : printf("+"); break;
	            case Q_COMPLEMENT : printf("~"); break;
	            case Q_NOT : printf("!"); break;
	            //Copy Assignment Instruction
	            case Q_ASSIGN :  break;
	        }
	        printf("%s\n",arg1.c_str());
	    }
	    else if(op == Q_GOTO){printf("goto ");printf("%s\n",result.c_str());}
	    else if(Q_IF_EQUAL<=op && op<=Q_IF_GREATER_OR_EQUAL)
	    {
	        printf("if  ");printf("%s",arg1.c_str());printf(" ");
	        switch(op)
	        {
	            //Conditional Jump
	            case   Q_IF_LESS : printf("<"); break;
	            case   Q_IF_GREATER : printf(">"); break;
	            case   Q_IF_LESS_OR_EQUAL : printf("<="); break;
	            case   Q_IF_GREATER_OR_EQUAL : printf(">="); break;
	            case   Q_IF_EQUAL : printf("=="); break;
	            case   Q_IF_NOT_EQUAL : printf("!="); break;
	            case   Q_IF_EXPRESSION : printf("!= 0"); break;
	            case   Q_IF_NOT_EXPRESSION : printf("== 0"); break;
	        }
	        printf("%s",arg2.c_str());printf("\tgoto ");printf("%s\n",result.c_str());            
	    }
	    else if(Q_CHAR2INT<=op && op<=Q_DOUBLE2INT)
	    {
	        printf("%s",result.c_str());printf("\t=\t");
	        switch(op)
	        {
	            case Q_CHAR2INT : printf(" Char2Int(");printf("%s",arg1.c_str());printf(")\n"); break;
	            case Q_CHAR2DOUBLE : printf(" Char2Double(");printf("%s",arg1.c_str());printf(")\n"); break;
	            case Q_INT2CHAR : printf(" Int2Char(");printf("%s",arg1.c_str());printf(")\n"); break;
	            case Q_DOUBLE2CHAR : printf(" Double2Char(");printf("%s",arg1.c_str());printf(")\n"); break;
	            case Q_INT2DOUBLE : printf(" Int2Double(");printf("%s",arg1.c_str());printf(")\n"); break;
	            case Q_DOUBLE2INT : printf(" Double2Int(");printf("%s",arg1.c_str());printf(")\n"); break;
	        }            
	    }
	    else if(op == Q_PARAM)
	    {
	        printf("param\t");printf("%s\n",result.c_str());
	    }
	    else if(op == Q_CALL)
	    {
	        if(!result.c_str())
					printf("call %s, %s\n", arg1.c_str(), arg2.c_str());
			else if(result.size()==0)
			{
				printf("call %s, %s\n", arg1.c_str(), arg2.c_str());
			}
			else
				printf("%s\t=\tcall %s, %s\n", result.c_str(), arg1.c_str(), arg2.c_str());
	    }
	    else if(op == Q_RETURN)
	    {
	        printf("return\t");printf("%s\n",result.c_str());
	    }
	    else if( op == Q_RINDEX)
	    {
	        printf("%s\t=\t%s[%s]\n", result.c_str(), arg1.c_str(), arg2.c_str());
	    }
	    else if(op == Q_LINDEX)
	    {
	        printf("%s[%s]\t=\t%s\n", result.c_str(), arg1.c_str(), arg2.c_str());
	    }
	    else if(op == Q_LDEREF)
	    {
	        printf("*%s\t=\t%s\n", result.c_str(), arg1.c_str());
	    }
	    else if(op == Q_RDEREF)
	    {
	    	printf("%s\t=\t* %s\n", result.c_str(), arg1.c_str());
	    }
	    else if(op == Q_ADDR)
	    {
	    	printf("%s\t=\t& %s\n", result.c_str(), arg1.c_str());
	    }
	}
}

// Backpatching and related functions
void backpatch(list *l,int i)
{
	// To fill the dangling list of goto's l1 to i
	list *temp =l;
	list *temp2;
	char str[10];
	sprintf(str,"%d",i);
	while(temp!=NULL)
	{
		glob_quad.arr[temp->index].result = str;
		temp2=temp;
		temp=temp->next;
		free(temp2);
	}
}

void typecheck(expresn *e1,expresn *e2,bool isAssign)
{
	// check if both expressions have the same data types
	types type1,type2;
	//if(e2->type)
	if(e1->type==NULL)
	{
		e1->type = CopyType(e2->type);
	}
	else if(e2->type==NULL)
	{
		e2->type =CopyType(e1->type);
	}
	type1=(e1->type)->basetp;
	type2=(e2->type)->basetp;
	if(type1==type2)
	{
		return;
	}
	if(!isAssign)
	{
		if(type1>type2)
		{
			symdata *temp = curr_st->gentemp(e1->type);
			if(type1 == tp_int && type2 == tp_char)
				glob_quad.emit(Q_CHAR2INT, e2->loc->name, temp->name);
			else if(type1 == tp_double && type2 == tp_int)
				glob_quad.emit(Q_INT2DOUBLE, e2->loc->name, temp->name);
			e2->loc = temp;
			e2->type = temp->tp_n;
		}
		else
		{
			symdata *temp = curr_st->gentemp(e2->type);
			if(type2 == tp_int && type1 == tp_char)
				glob_quad.emit(Q_CHAR2INT, e1->loc->name, temp->name);
			else if(type2 == tp_double && type1 == tp_int)
				glob_quad.emit(Q_INT2DOUBLE, e1->loc->name, temp->name);	
			e1->loc = temp;
			e1->type = temp->tp_n;
		}		
	}
	else
	{
		symdata *temp = curr_st->gentemp(e1->type);
		if(type1 == tp_int && type2 == tp_double)
			glob_quad.emit(Q_DOUBLE2INT, e2->loc->name, temp->name);
		else if(type1 == tp_double && type2 == tp_int)
			glob_quad.emit(Q_INT2DOUBLE, e2->loc->name, temp->name);
		else if(type1 == tp_char && type2 == tp_int)
			glob_quad.emit(Q_INT2CHAR, e2->loc->name, temp->name);
		else if(type1 == tp_int && type2 == tp_char)
			glob_quad.emit(Q_CHAR2INT, e2->loc->name, temp->name);
		else
		{
			printf("%s %s Types compatibility not defined\n",e1->loc->name.c_str(),e2->loc->name.c_str());
			exit(-1);
		}
		e2->loc = temp;
		e2->type = temp->tp_n;
	}
}

void print_list(list *root)
{
	int flag=0;
	while(root!=NULL)
	{
		printf("%d ",root->index);
		flag=1;
		root=root->next;
	}
	if(flag==0)
	{
		printf("Empty List\n");
	}
	else
	{
		printf("\n");
	}
}
void conv2Bool(expresn *e)
{
	// To convert the given exprssion type to bool 
	// mostly used in relational operator
	if((e->type)->basetp!=tp_bool)
	{
		(e->type) = new type_n(tp_bool);
		e->falselist=makelist(next_instr);
		glob_quad.emit(Q_IF_EQUAL,e->loc->name,"0","-1");
		e->truelist = makelist(next_instr);
		glob_quad.emit(Q_GOTO,-1);
	}
}

int main()
{
	symdata *temp_printInt=new symdata("printInt");
	temp_printInt->tp_n=new type_n(tp_int);
	temp_printInt->var_type="func";
	temp_printInt->nest_tab=glob_st;
	glob_st->symbol_tab.push_back(temp_printInt);
	
	symdata *temp_readInt=new symdata("readInt");
	temp_readInt->tp_n=new type_n(tp_int);
	temp_readInt->var_type="func";
	temp_readInt->nest_tab=glob_st;
	glob_st->symbol_tab.push_back(temp_readInt);
	
	symdata *temp_printStr=new symdata("printStr");
	temp_printStr->tp_n=new type_n(tp_int);
	temp_printStr->var_type="func";
	temp_printStr->nest_tab=glob_st;
	glob_st->symbol_tab.push_back(temp_printStr);
	yyparse();
	glob_st->name="Global";
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("GENERATED QUADS - TAC TRANSLATION");
	printf("\n------------------------------------------------------------------------------------------------------------------------\n\n");
	glob_quad.print();
	printf("\n------------------------------------------------------------------------------------------------------------------------\n");
	printf("SYMBOL TABLES");
	printf("\n------------------------------------------------------------------------------------------------------------------------");
	glob_st->print();
	set<string> setty;
	setty.insert("Global");
	FILE *fp;
	fp = fopen("output.s","w");
	fprintf(fp,"\t.file\t\"output.s\"\n");
	for (int i = 0; i < strings_label.size(); ++i)
	{
		fprintf(fp,"\n.STR%d:\t.string %s",i,strings_label[i].c_str());	
	}
	set<string>setty_1;
	glob_st->mark_labels();
	glob_st->global_variables(fp);
	setty_1.insert("Global");
	int count_l=0;
	for (int i = 0; i < glob_st->symbol_tab.size(); ++i)
	{
		if(((glob_st->symbol_tab[i])->nest_tab)!=NULL)
		{
			if(setty_1.find(((glob_st->symbol_tab[i])->nest_tab)->name)==setty_1.end())
			{
				glob_st->symbol_tab[i]->nest_tab->assign_offset();
				glob_st->symbol_tab[i]->nest_tab->print();
				glob_st->symbol_tab[i]->nest_tab->function_prologue(fp,count_l);
				glob_st->symbol_tab[i]->nest_tab->function_restore(fp);
				glob_st->symbol_tab[i]->nest_tab->gen_internal_code(fp,count_l);
				setty_1.insert(((glob_st->symbol_tab[i])->nest_tab)->name);
				glob_st->symbol_tab[i]->nest_tab->function_epilogue(fp,count_l,count_l);
				count_l++;
			}
		}
	}
	fprintf(fp,"\n");
	return 0;
}
