all: netcalc

netcalc: main.o print.o taxes.o utils.o
	gcc -g -Wall -o netcalc main.o print.o taxes.o utils.o

main.o: main.c print.h taxes.h
	gcc -c -g -Wall main.c

print.o: print.c print.h
	gcc -c -g -Wall print.c

taxes.o: taxes.c taxes.h utils.h
	gcc -c -g -Wall taxes.c

utils.o: utils.c utils.h
	gcc -c -g -Wall utils.c

clean:
	rm -f netcalc *.o