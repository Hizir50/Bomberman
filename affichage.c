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

int taille_case() {
    int largeur_case = (LARGEUR - LARGEUR/6) / NB_COLONNES;
    int hauteur_case = (HAUTEUR - HAUTEUR/6) / NB_LIGNES;

    return largeur_case < hauteur_case ? largeur_case : hauteur_case;
}


MLV_Color couleur_case(TypeCase type) {
    switch (type) {
        case MUR_INDESTRUCTIBLE:
            return MLV_convert_rgba_to_color(70, 70, 70, 255);   /* gris fonce */
        case MUR_DESTRUCTIBLE:
            return MLV_convert_rgba_to_color(160, 100, 50, 255); /* marron */
        default:
            return MLV_COLOR_GREEN;
    }
}

void dessiner_plateau(const Plateau *p) {
    int ligne, colonne;
    int t = taille_case();

    for (ligne = 0; ligne < NB_LIGNES; ligne++) {
        for (colonne = 0; colonne < NB_COLONNES; colonne++) {
            MLV_draw_filled_rectangle(
                colonne * t, ligne * t, t, t,
                couleur_case(lire_case(p, colonne, ligne))
            );
        }
    }
}