CC = gcc
CFLAGS = -W -Wall -std=c89 -pedantic -O2 -D_POSIX_C_SOURCE=199309L
LFLAGS = -lMLV -lm



Bomberman: main.o affichage.o personnage.o bombe.o jeu.o
	$(CC) -o Bomberman main.o affichage.o personnage.o bombe.o jeu.o $(CFLAGS) $(LFLAGS)

main.o: main.c affichage.c personnage.c bombe.h
	$(CC) $(CFLAGS) -o main.o -c main.c

affichage.o: affichage.c affichage.h bombe.h
	$(CC) $(CFLAGS) -o affichage.o -c affichage.c

personnage.o: personnage.c personnage.h
	$(CC) $(CFLAGS) -o personnage.o -c personnage.c

bombe.o: bombe.c bombe.h
	$(CC) $(CFLAGS) -o bombe.o -c bombe.c

jeu.o: jeu.c jeu.h
	$(CC) $(CFLAGS) -o jeu.o -c jeu.c

clean:
	rm -rf Bomberman *.o *~