UTILITY=utility
ES1=esercizio_1
ES1_EXE=run_test_ordina_array.exe

ES3=esercizio_3
ES3_EXE=cognome_inverso.exe

ES5=esercizio_5
ES5_EXE=run_test_inserisci.exe

ES6=esercizio_6
ES6_EXE=run_test_somma.exe

all: main.o vettore.o vettore_sort.o
	gcc main.o vettore.o vettore_sort.o -o array

$(ES1): $(ES1)_main.o vettore.o vettore_sort.o
	gcc $(ES1)_main.o vettore.o vettore_sort.o -o $(ES1)/$(ES1_EXE)

$(ES3): $(ES3)_main.o
	gcc $(ES3)_main.o -o $(ES3)/$(ES3_EXE)
	
$(ES5): $(ES5)_main.o vettore.o
	gcc $(ES5)_main.o vettore.o -o $(ES5)/$(ES5_EXE)

$(ES6): $(ES6)_main.o vettore.o vettore_sort.o
	gcc $(ES6)_main.o vettore.o vettore_sort.o -o $(ES6)/$(ES6_EXE)

main.o: main.c
	gcc -c main.c

vettore.o: $(UTILITY)/vettore.c
	gcc -c $(UTILITY)/vettore.c

vettore_sort.o: $(UTILITY)/vettore_sort.c
	gcc -c $(UTILITY)/vettore_sort.c

clean: 
	rm *.o array 
	$(ES1)/*_output.txt $(ES1)/result.txt $(ES1)/*.exe 
	$(ES3)/*.exe 
	$(ES5)/*_output.txt $(ES5)/result.txt $(ES5)/*.exe 
	$(ES6)/*_output.txt $(ES6)/result.txt $(ES6)/*.exe 
