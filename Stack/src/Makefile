CXXFLAGS = -g3 -gdwarf2
CCFLAGS = -g3 -gdwarf-2

all: executable

debug: CXXFLAGS += -DDEBUG -g
debug: CCFLAGS += -DDEBUG -g
debug: executable

executable: main.o list.o item.o stack_a.o int.o
	$(CC) $(CCFLAGS) -o stack.exe main.o list.o item.o stack_a.o int.o -lm

main.o: main.c
	$(CC) -c main.c

list.o: list.c
	$(CC) -c list.c

item.o: item.c
	$(CC) -c item.c

int.o: int.c
	$(CC) -c int.c

stack_a.o: stack_a.c
	$(CC) -c stack_a.c

stack_l.o: stack_l.c
	$(CC) -c stack_l.c

clean:
	rm *.o stack.exe 