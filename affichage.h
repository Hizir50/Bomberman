#ifndef _AFFICHAGE_H_
#define _AFFICHAGE_H_
#include <MLV/MLV_all.h>

/*TAILLE FENETRE*/

#define HAUTEUR MLV_get_desktop_height()
#define LARGEUR MLV_get_desktop_width()

void afficher_fenetre_principale();

#endif /* _AFFICHAGE_H_ */