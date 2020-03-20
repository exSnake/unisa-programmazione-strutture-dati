test: main_test.o vettore.o
	gcc main_test.o vettore.o -o run_test_inserisci

main_test.o: main_test.c
	gcc -c main_test.c

vettore.o: vettore.c
	gcc -c vettore.c

clean: 
	rm *.o *_output.txt run_test_inserisci
