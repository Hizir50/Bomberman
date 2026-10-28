#include <stdio.h>
#include "affichage.h"
#include "personnage.h"
#include "bombe.h"


void dessiner_personnage(Personnage p) {
    MLV_draw_filled_rectangle(p.x, p.y, TAILLE_PERSONNAGE, TAILLE_PERSONNAGE, MLV_COLOR_BLUE);
}

void afficher_fenetre_principale() {
    MLV_create_window(
        "medium - 12 - Le résolution du bureau d'environement", 
        "résolution du bureau", LARGEUR_FENETRE, HAUTEUR_FENETRE
    );

}
