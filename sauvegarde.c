#include <stdio.h>
#include <stdlib.h>
#include "sauvegarde.h"
#include "jeu.h"
#include <string.h>
#include "generation.h"
#include "personnage.h"


int sauvegarder_partie(char* nom_fichier,Plateau* plateau,Personnage* personnage) {
    FILE* fichier = NULL;
    char chemin[256] = "";
    int erreur = 0;

    strcat(chemin, "sauvegardes/");
    strcat(chemin, nom_fichier);
    fichier = fopen(chemin, "w+");
    if(fichier == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier %s pour la sauvegarde.\n", chemin);
        erreur = 1;
    }
    fprintf(fichier, "%d %d\n", plateau->depart_ligne, plateau->depart_colonne);
    fprintf(fichier, "%d %d\n", personnage->x, personnage->y);
    
    fclose(fichier);
    return (erreur); 
}


int charger_partie(char* nom_fichier, Plateau* plateau, Personnage* personnage) {
    FILE* fichier = NULL;
    char chemin[256] = "";
    int erreur = 0;

    strcat(chemin, "sauvegardes/");
    strcat(chemin, nom_fichier);
    fichier = fopen(chemin, "r");

    if(fichier == NULL) {
        fprintf(stderr, "Erreur lors de l'ouverture du fichier %s pour le chargement.\n", chemin);
        erreur = 1;
    }
    
    if(fscanf(fichier, "%d %d\n", &(plateau->depart_ligne), &(plateau->depart_colonne)) != 2) {
        fprintf(stderr, "Erreur lors de la lecture des coordonnées du plateau.\n");
        erreur = 1;
    }
    if(fscanf(fichier, "%d %d\n", &(personnage->x), &(personnage->y)) != 2) {
        fprintf(stderr, "Erreur lors de la lecture des coordonnées du personnage.\n");
        erreur = 1;
    }

    fclose(fichier);
    return (erreur); 
}