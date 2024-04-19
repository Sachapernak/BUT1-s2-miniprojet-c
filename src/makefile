main: main.o
	gcc -o main main.o -g
main.o: main.c Lecture.h Crypt.h
	gcc -c main.c -g


Crypt: Crypt.o
	gcc -o Crypt Crypt.o -g
Crypt.o: Crypt.c Lecture.h
	gcc -c Crypt.c -g

