output.txt: a.out ass3_19CS30030_19CS30048_test.c
	./a.out < ass3_19CS30030_19CS30048_test.c > output.txt

a.out: lex.yy.c
	cc lex.yy.c -lfl

lex.yy.c: ass3_19CS30030_19CS30048.l ass3_19CS30030_19CS30048.c
	flex ass3_19CS30030_19CS30048.l ass3_19CS30030_19CS30048.c

ass3_19CS30030_19CS30048.c: 
	touch ass3_19CS30030_19CS30048.c

clean:
	rm a.out lex.yy.c output.txt
