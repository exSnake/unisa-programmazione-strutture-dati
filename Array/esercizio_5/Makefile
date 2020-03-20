test: main_test.o vettore.o vettore_sort.o
	gcc main_test.o vettore.o vettore_sort.o -o run_test_inserisci

main_test.o: main_test.c
	gcc -c main_test.c

vettore.o: vettore.c
	gcc -c vettore.c

vettore_sort.o: vettore_sort.c
	gcc -c vettore_sort.c

clean: 
	rm *.o *_output.txt array run_test_ordina_array
