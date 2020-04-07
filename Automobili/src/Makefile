CXXFLAGS = -g3 -gdwarf2
CCFLAGS = -g3 -gdwarf-2

all: executable

debug: CXXFLAGS += -DDEBUG -g
debug: CCFLAGS += -DDEBUG -g
debug: executable

executable: main.o automobile.o
	$(CC) $(CCFLAGS) -o automobile.exe main.o automobile.o

main.o: main.c
	$(CC) -c main.c

automobile.o: automobile.c
	$(CC) -c automobile.c

clean:
	rm *.o automobile.exe 