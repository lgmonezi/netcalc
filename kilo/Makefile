.PHONY = all clean

CC := gcc
STD := -std=c99
DB := -g
WARNFLAG := -Wall -Wextra -pedantic

all: kilo

kilo: kilo.o input.o output.o terminal.o
	$(CC) $(DB) $(WARNFLAG) $(STD) -o kilo kilo.o input.o output.o terminal.o

kilo.o: kilo.c input.h output.h terminal.h
	$(CC) kilo.c -c $(DB) $(WARNFLAG) $(STD)

input.o: input.c input.h terminal.h
	$(CC) input.c -c $(DB) $(WARNFLAG) $(STD)

output.o: output.c output.h
	$(CC) output.c -c $(DB) $(WARNFLAG) $(STD)

terminal.o: terminal.c terminal.h data.h
	$(CC) terminal.c -c $(DB) $(WARNFLAG) $(STD)

clean:
	rm -f kilo *.o