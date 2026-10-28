#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"
#include "personnage.h"


void dessiner_personnage(Personnage p) {
    MLV_draw_filled_rectangle(p.x, p.y, TAILLE_PERSONNAGE, TAILLE_PERSONNAGE, MLV_COLOR_BLUE);
}

void afficher_fenetre_principale() {
    MLV_create_window(
        "medium - 12 - Le résolution du bureau d'environement",
        "résolution du bureau", LARGEUR-LARGEUR/6, HAUTEUR-HAUTEUR/6
    );
}

int largeur_fenetre() {
    return LARGEUR - LARGEUR/6;
}

int hauteur_fenetre() {
    return HAUTEUR - HAUTEUR/6;
}

/* Les colonnes (et les lignes) se partagent toute la fenetre. */
int largeur_case() {
    return largeur_fenetre() / NB_COLONNES;
}

int hauteur_case() {
    return hauteur_fenetre() / NB_LIGNES;
}


MLV_Color couleur_case(TypeCase type) {
    switch (type) {
        case MUR_INDESTRUCTIBLE:
            return MLV_COLOR_GRAY;   /* gris fonce */
        case MUR_DESTRUCTIBLE:
            return MLV_COLOR_BROWN; /* marron */
        case LIMITE_NIVEAU:
            return MLV_COLOR_RED;   /* rouge */
        default:
            return MLV_COLOR_SANDYBROWN; /* beige */
    }
}

void dessiner_plateau(const Plateau *p) {
    int ligne, colonne;
    int w = largeur_fenetre(), h = hauteur_fenetre();

    for (ligne = 0; ligne < NB_LIGNES; ligne++) {
        for (colonne = 0; colonne < NB_COLONNES; colonne++) {
            /* bornes calculees sur la fenetre entiere : pas de bande vide a droite/en bas */
            int x0 = colonne * w / NB_COLONNES;
            int x1 = (colonne + 1) * w / NB_COLONNES;
            int y0 = ligne * h / NB_LIGNES;
            int y1 = (ligne + 1) * h / NB_LIGNES;
            MLV_draw_filled_rectangle(
                x0, y0, x1 - x0, y1 - y0,
                couleur_case(lire_case(p, colonne, ligne))
            );
        }
    }
}