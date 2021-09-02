/*
	COMPILERS LABORATORY (CS39003)
	Name - Suhas Jain 
	Roll no. - 19CS30048
	Assignment - 2
	Creating Library
*/

#include "myl.h"
#include <stdio.h>

int main(){
	printStr("*** Welcome To Assignment 2 - 19CS30048 ***\n-------------------------------------------\n");
    printStr("#1 ---------- Test for printStr() ----------\n\n");
	//printStr test 
	printStr("Test string #1 : ");
	char* str = "Hello, I'm Suhas Jain\n";
	int s = printStr(str);
	printStr("Return value (length) :");
	printInt(s);
	printStr("\n\n");	
	printStr("Test string #2 : ");
	str = "This program uses no standard C libraries\n";
	s = printStr(str);
	printStr("Return value (length) :");
	printInt(s);
	printStr("\n\n");

	printStr("#2 ---------- Test for printInt() ----------\n\n");
	//printInt test
	printStr("Test integer #1 : ");
	int a = 1092367;
	s = printInt(a);
	printStr("\nReturn value (no. of characters) : ");
	printInt(s);
	printStr("\n\n");
	printStr("Test integer #2 : ");
	a = -2345;
	s = printInt(a);
	printStr("\nReturn value (no. of characters) : ");
	printInt(s);
	printStr("\n\n");

	printStr("#3 ---------- Test for printFlt() ----------\n\n");
	//printInt test
	printStr("Test float #1 : ");
	float b = 1.215;
	s = printFlt(b);
	printStr("\nReturn value (no. of characters) : ");
	printInt(s);
	printStr("\n\n");
	printStr("Test float #2 : ");
	b = -23.25645;
	s = printFlt(b);
	printStr("\nReturn value (no. of characters) : ");
	printInt(s);
	printStr("\n\n");

	printStr("#4 ---------- Test for readInt() ----------\n\n");
	//readInt test
	printStr((char*)"Enter an integer (Test integer #1) : ");
	int n;
	s = readInt(&n);
	printStr((char*)"Return value (1 for Ok, 0 for ERR) : ");
	printInt(s);
	printStr((char*)"\nTest integer #1 : ");
	printInt(n);
	printStr((char*)"\n\n");
	printStr((char*)"Enter an integer (Test integer #2) : ");
	s = readInt(&n);
	printStr((char*)"Return value (1 for Ok, 0 for ERR) : ");
	printInt(s);
	printStr((char*)"\nTest integer #2 : ");
	printInt(n);
	printStr((char*)"\n\n");

	printStr("#5 ---------- Test for readFlt() ----------\n\n");
	//readFlt test
	printStr((char*)"Enter an float (Test float #1) : ");
	float f;
	s = readFlt(&f);
	printStr((char*)"Return value (1 for Ok, 0 for ERR) : ");
	printInt(s);
	printStr((char*)"\nTest float #1 : ");
	printFlt(f);
	printStr((char*)"\n\n");
	printStr((char*)"Enter an float (Test float #2) : ");
	s = readFlt(&f);
	printStr((char*)"Return value (1 for Ok, 0 for ERR) : ");
	printInt(s);
	printStr((char*)"\nTest float #2 : ");
	printFlt(f);
	printStr((char*)"\n\n********* THANK YOU *********\n\n");
}
