CXXFLAGS = -g3 -gdwarf2
CCFLAGS = -g3 -gdwarf-2

all: executable

debug: CXXFLAGS += -DDEBUG -g
debug: CCFLAGS += -DDEBUG -g
debug: executable

executable: main.o list.o item.o
	$(CC) $(CCFLAGS) -o list.exe main.o list.o item.o

main.o: main.c
	$(CC) -c main.c

list.o: list.c
	$(CC) -c list.c

item.o: item.c
	$(CC) -c item.c

clean:
	rm *.o list.exe 