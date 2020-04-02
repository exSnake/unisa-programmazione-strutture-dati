all: main.o automobile.o
	gcc main.o automobile.o -o automobile.exe

main.o: main.c
	gcc -c main.c

automobile.o: automobile.c
	gcc -c automobile.c

clean:
	rm *.o automobile.exe 