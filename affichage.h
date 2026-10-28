#ifndef _AFFICHAGE_H_
#define _AFFICHAGE_H_
#include "personnage.h"
#include "generation.h"
#include <MLV/MLV_all.h>

/*TAILLE FENETRE*/

#define HAUTEUR MLV_get_desktop_height()
#define LARGEUR MLV_get_desktop_width()


void afficher_fenetre_principale();
void dessiner_personnage(Personnage p);

/* Taille (en pixels) d'une case du plateau. */
int taille_case();

/* Couleur d'affichage associee a un type de case. */
MLV_Color couleur_case(TypeCase type);

/* Dessine toute la grille du plateau (une couleur par type de case). */
void dessiner_plateau(const Plateau *p);

#endif /* _AFFICHAGE_H_ */