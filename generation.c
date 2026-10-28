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

void level1(Plateau *p) {
    int i, j;

    for (i = 0; i < NB_LIGNES; i++) {
        for (j = 0; j < NB_COLONNES; j++) {
            if (i == 0 || i == NB_LIGNES - 1 || j == 0 || j == NB_COLONNES - 1) {
                p->grille[i][j] = LIMITE_NIVEAU;
            } 
            else if ((j == 2 && i == 8) || 
                     (j == 3 && i == 5) || 
                     (j == 8 && (i == 4 || i == 6))) {
                p->grille[i][j] = MUR_DESTRUCTIBLE;
            }
            else if (j == 1 && i != 8) {
                p->grille[i][j] = MUR_INDESTRUCTIBLE;
            }
            else if (j == 2 && (i <= 4 || i >= 9)) {
                p->grille[i][j] = MUR_INDESTRUCTIBLE;
            }
            else if (j == 3 && i != 5) {
                p->grille[i][j] = MUR_INDESTRUCTIBLE;
            }
            else if ((j >= 4 && j <= 6) && (i <= 4 || i >= 6)) {
                p->grille[i][j] = MUR_INDESTRUCTIBLE;
            }
            else if ((j >= 7 && j <= 9) && (i <= 2 || i >= 7)) {
                p->grille[i][j] = MUR_INDESTRUCTIBLE;
            }
            else if (j > 9) {
                p->grille[i][j] = MUR_INDESTRUCTIBLE;
            }
        }
    }
}











