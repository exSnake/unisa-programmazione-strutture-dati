main.exe: main.o punto.o
	gcc main.o punto.o -o main.exe
	
punto.o: punto.c
	gcc -c punto.c
	
main.o: main.c
	gcc -c main.c punto.o

clean:
	rm *.o main.exe
	