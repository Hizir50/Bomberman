#ifndef _AFFICHAGE_H_
#define _AFFICHAGE_H_
#include "personnage.h"
#include "bombe.h"
#include <MLV/MLV_all.h>

/*TAILLE FENETRE*/

#define HAUTEUR_ECRAN MLV_get_desktop_height()
#define LARGEUR_ECRAN MLV_get_desktop_width()

#define HAUTEUR_FENETRE (HAUTEUR_ECRAN-(HAUTEUR_ECRAN/8))
#define LARGEUR_FENETRE (LARGEUR_ECRAN-(LARGEUR_ECRAN/8))





void afficher_fenetre_principale();
void dessiner_personnage(Personnage p);

#endif /* _AFFICHAGE_H_ */