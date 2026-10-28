#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"
#include "personnage.h"
#include "bombe.h"


void dessiner_personnage(Personnage p) {
    MLV_draw_filled_rectangle(p.x, p.y, TAILLE_PERSONNAGE, TAILLE_PERSONNAGE, MLV_COLOR_BLUE);
}

void afficher_fenetre_principale() {
    MLV_create_window(
        "medium - 12 - Le résolution du bureau d'environement", 
        "résolution du bureau", LARGEUR-LARGEUR/6, HAUTEUR-HAUTEUR/6
    );
}


void dessiner_bombe_et_explosion(Bombe b) {
    if (b.active) {
        int centre_x = b.x + TAILLE_PERSONNAGE / 2;
        int centre_y = b.y + TAILLE_PERSONNAGE / 2;
        int rayon = TAILLE_PERSONNAGE / 2;
        MLV_draw_filled_circle(centre_x, centre_y, rayon, MLV_COLOR_RED);
        MLV_draw_circle(centre_x, centre_y, rayon, MLV_COLOR_BLACK);
    } else if (b.en_explosion) {
        int t = TAILLE_PERSONNAGE;
        int portee = PORTEE_EXPLOSION;

        /* explosion haut */
        MLV_draw_filled_rectangle(b.x, b.y - portee * t, t, portee * t, MLV_COLOR_YELLOW);
        MLV_draw_rectangle(b.x, b.y - portee * t, t, portee * t, MLV_COLOR_ORANGE);

        /* explosion bas */
        MLV_draw_filled_rectangle(b.x, b.y + t, t, portee * t, MLV_COLOR_YELLOW);
        MLV_draw_rectangle(b.x, b.y + t, t, portee * t, MLV_COLOR_ORANGE);

        /* explosion gauche */
        MLV_draw_filled_rectangle(b.x - portee * t, b.y, portee * t, t, MLV_COLOR_YELLOW);
        MLV_draw_rectangle(b.x - portee * t, b.y, portee * t, t, MLV_COLOR_ORANGE);

        /* explosion droite */
        MLV_draw_filled_rectangle(b.x + t, b.y, portee * t, t, MLV_COLOR_YELLOW);
        MLV_draw_rectangle(b.x + t, b.y, portee * t, t, MLV_COLOR_ORANGE);
    }
}
