all: main.o vettore.o
	gcc main.o vettore.o -o array

test: main_test.o vettore.o
	gcc main_test.o vettore.o -o run_test_ordina_array

main.o: main.c
	gcc -c main.c

main_test.o: main_test.c
	gcc -c main_test.c

vettore.o: vettore.c
	gcc -c vettore.c

clean: 
	rm *.o array run_test_ordina_array
