#ifndef _AFFICHAGE_H_
#define _AFFICHAGE_H_
#include "personnage.h"
#include "jeu.h"
#include "bombe.h"
#include "generation.h"
#include <MLV/MLV_all.h>

/*TAILLE FENETRE*/

#define HAUTEUR_FENETRE MLV_get_desktop_height()
#define LARGEUR_FENETRE MLV_get_desktop_width()

void afficher_menu_pause();
void afficher_ecran_charger();
void afficher_menu_principale();
void afficher_meilleur_scores();
void afficher_ecran_sauvegarder();
void afficher_fenetre_principale();
void dessiner_personnage(Personnage p);
void dessiner_bombe_et_explosion(Bombe b);
void dessiner_ennemi(Ennemi e);

/* Taille de la fenetre et d'une case (en pixels) : la grille remplit toute la fenetre. */

int largeur_case();
int hauteur_case();

/* Couleur d'affichage associee a un type de case. */
MLV_Color couleur_case(TypeCase type);

/* Dessine toute la grille du plateau (une couleur par type de case). */
void dessiner_plateau(const Plateau *p);

#endif /* _AFFICHAGE_H_ */