all: main.o vettore.o
	gcc main.o vettore.o -o array

main.o: main.c
	gcc -c main.c

vettore.o: vettore.c
	gcc -c vettore.c

clean: 
	rm *.o array
