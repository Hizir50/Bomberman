CC = gcc
CFLAGS = -W -Wall -std=c89 -pedantic -O2
LFLAGS = -lMLV -lm



Bomberman: main.o affichage.o
	$(CC) -o Bomberman main.o affichage.o $(CFLAGS) $(LFLAGS)

main.o: main.c affichage.c
	$(CC) $(CFLAGS) -o main.o -c main.c

affichage.o: affichage.c affichage.h
	$(CC) $(CFLAGS) -o affichage.o -c affichage.c


clean:
	rm -rf Bomberman *.o *~