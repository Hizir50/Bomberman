CC = gcc
CFLAGS = -W -Wall -std=c89 -pedantic -O2
LFLAGS = -lMLV -lm



Bomberman: main.o affichage.o personnage.o generation.o menu.o sauvegarde.o
	$(CC) -o Bomberman main.o affichage.o personnage.o generation.o menu.o sauvegarde.o $(CFLAGS) $(LFLAGS)

main.o: main.c affichage.c personnage.c bombe.h
	$(CC) $(CFLAGS) -o main.o -c main.c

affichage.o: affichage.c affichage.h bombe.h
	$(CC) $(CFLAGS) -o affichage.o -c affichage.c

personnage.o: personnage.c personnage.h
	$(CC) $(CFLAGS) -o personnage.o -c personnage.c

generation.o: generation.c generation.h
	$(CC) $(CFLAGS) -o generation.o -c generation.c
  
menu.o: menu.c menu.h 
	$(CC) $(CFLAGS) -o menu.o -c menu.c

sauvegarde.o: sauvegarde.c sauvegarde.h
	$(CC) $(CFLAGS) -o sauvegarde.o -c sauvegarde.c



clean:
	rm -rf Bomberman *.o *~