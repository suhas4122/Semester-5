all: a.out
	
	./a.out < ass5_19CS30048_19CS30030_test1.c > ass5_19CS30048_19CS30030_quads1.out
	@echo "Test File 1 Successfully Translated !\n"
	./a.out < ass5_19CS30048_19CS30030_test2.c > ass5_19CS30048_19CS30030_quads2.out
	@echo "Test File 2 Successfully Translated !\n"
	./a.out < ass5_19CS30048_19CS30030_test3.c > ass5_19CS30048_19CS30030_quads3.out
	@echo "Test File 3 Successfully Translated !\n"
	./a.out < ass5_19CS30048_19CS30030_test4.c > ass5_19CS30048_19CS30030_quads4.out
	@echo "Test File 4 Successfully Translated !\n"
	./a.out < ass5_19CS30048_19CS30030_test5.c > ass5_19CS30048_19CS30030_quads5.out
	@echo "Test File 5 Successfully Translated !\n"

	@echo "\nALL TEST FILES SUCCESSFULLY TRANSLATED !!\n"

a.out: lex.yy.o y.tab.o ass5_19CS30048_19CS30030_translator.o
	g++ lex.yy.o y.tab.o ass5_19CS30048_19CS30030_translator.o -lfl

ass5_19CS30048_19CS30030_translator.o: ass5_19CS30048_19CS30030_translator.cxx ass5_19CS30048_19CS30030_translator.h
	g++ -c ass5_19CS30048_19CS30030_translator.h
	g++ -c ass5_19CS30048_19CS30030_translator.cxx

lex.yy.o: lex.yy.c
	g++ -c lex.yy.c

y.tab.o: y.tab.c
	g++ -c y.tab.c

lex.yy.c: ass5_19CS30048_19CS30030.l y.tab.h ass5_19CS30048_19CS30030_translator.h
	flex ass5_19CS30048_19CS30030.l

y.tab.c: ass5_19CS30048_19CS30030.y
	yacc -dtv ass5_19CS30048_19CS30030.y 

y.tab.h: ass5_19CS30048_19CS30030.y
	yacc -dtv ass5_19CS30048_19CS30030.y 

clean:
	rm lex.yy.c y.tab.c y.tab.h lex.yy.o y.tab.o ass5_19CS30048_19CS30030_translator.o y.output a.out ass5_19CS30048_19CS30030_translator.h.gch \
	ass5_19CS30048_19CS30030_quads1.out \
	ass5_19CS30048_19CS30030_quads2.out \
	ass5_19CS30048_19CS30030_quads3.out \
	ass5_19CS30048_19CS30030_quads4.out \
	ass5_19CS30048_19CS30030_quads5.out
