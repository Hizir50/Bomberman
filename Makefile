CC = gcc
CFLAGS = -W -Wall -std=c89 -pedantic -O2
LFLAGS = -lMLV -lm



Bomberman: main.o 
	$(CC) -o Bomberman main.o  $(CFLAGS) $(LFLAGS)

main.o: main.c plateau.c
	$(CC) $(CFLAGS) -o main.o -c main.c


clean:
	rm -rf Bomberman *.o *~