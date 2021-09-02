a.out: main.o libass2_19CS30048.a
		cc main.o -L. -lass2_19CS30048

main.o: main.c myl.h
		cc -Wall -c main.c

libass2_19CS30048.a: ass2_19CS30048.o
		ar -rcs libass2_19CS30048.a ass2_19CS30048.o
	
ass2_19CS30048.o: ass2_19CS30048.c myl.h
		cc -Wall -c ass2_19CS30048.c

clean:
		rm a.out main.o libass2_19CS30048.a ass2_19CS30048.o