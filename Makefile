CC = gcc
CFLAGS = -W -Wall -std=c89 -pedantic -O2
LFLAGS = -lMLV -lm



Bomberman: main.o affichage.o personnage.o menu.o
	$(CC) -o Bomberman main.o affichage.o personnage.o menu.o $(CFLAGS) $(LFLAGS)

main.o: main.c affichage.c personnage.c 
	$(CC) $(CFLAGS) -o main.o -c main.c

affichage.o: affichage.c affichage.h
	$(CC) $(CFLAGS) -o affichage.o -c affichage.c

personnage.o: personnage.c personnage.h
	$(CC) $(CFLAGS) -o personnage.o -c personnage.c

menu.o: menu.c menu.h
	$(CC) $(CFLAGS) -o menu.o -c menu.c

clean:
	rm -rf Bomberman *.o *~