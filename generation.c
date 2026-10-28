#include "generation.h"


void initialiser_plateau(Plateau *p) {
    int ligne, colonne;

    for (ligne = 0; ligne < NB_LIGNES; ligne++) {
        for (colonne = 0; colonne < NB_COLONNES; colonne++) {
            p->grille[ligne][colonne] = CASE_LIBRE;
        }
    }
    p->depart_colonne = 1;
    p->depart_ligne = 1;
}


int est_dans_grille(int colonne, int ligne) {
    return colonne >= 0 && colonne < NB_COLONNES
        && ligne >= 0 && ligne < NB_LIGNES;
}


TypeCase lire_case(const Plateau *p, int colonne, int ligne) {
    if (!est_dans_grille(colonne, ligne)) {
        return MUR_INDESTRUCTIBLE;
    }
    return p->grille[ligne][colonne];
}


void ecrire_case(Plateau *p, int colonne, int ligne, TypeCase type) {
    if (est_dans_grille(colonne, ligne)) {
        p->grille[ligne][colonne] = type;
    }
}