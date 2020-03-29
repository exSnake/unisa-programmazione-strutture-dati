all: main.o libro.o
	gcc main.o libro.o -o libro.exe

main.o: main.c
	gcc -c main.c

libro.o: libro.c
	gcc -c libro.c

clean:
	rm *.o libro.exe 