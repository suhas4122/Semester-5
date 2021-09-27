asgn4_19CS30048_19CS30030.txt: a.out asgn4_19CS30048_19CS30030_test.c
	./a.out < asgn4_19CS30048_19CS30030_test.c > asgn4_19CS30048_19CS30030.txt

a.out: lex.yy.o asgn4_19CS30048_19CS30030.o y.tab.o
	gcc lex.yy.o asgn4_19CS30048_19CS30030.o y.tab.o -lfl 

lex.yy.o: lex.yy.c 
	gcc -c lex.yy.c

asgn4_19CS30048_19CS30030.o: asgn4_19CS30048_19CS30030.c 
	gcc -c asgn4_19CS30048_19CS30030.c  

y.tab.o: y.tab.c 
	gcc -c y.tab.c

lex.yy.c: asgn4_19CS30048_19CS30030.l y.tab.h
	flex asgn4_19CS30048_19CS30030.l

y.tab.c: asgn4_19CS30048_19CS30030.y 
	bison -dty asgn4_19CS30048_19CS30030.y 

y.tab.h: asgn4_19CS30048_19CS30030.y
	bison -dty asgn4_19CS30048_19CS30030.y 

asgn4_19CS30048_19CS30030.c: 
	touch asgn4_19CS30048_19CS30030.c

clean:
	rm a.out lex.yy.* asgn4_19CS30048_19CS30030.o y.tab.* asgn4_19CS30048_19CS30030.txt