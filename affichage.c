#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"
#include "personnage.h"
#include "bombe.h"
#include "jeu.h"


void dessiner_personnage(Personnage p) {
    MLV_draw_filled_rectangle(p.x, p.y, TAILLE_PERSONNAGE, TAILLE_PERSONNAGE, MLV_COLOR_BLUE);
}

void afficher_fenetre_principale() {
    MLV_create_window(
        "medium - 12 - Le résolution du bureau d'environement", 
        "résolution du bureau", LARGEUR-LARGEUR/6, HAUTEUR-HAUTEUR/6
    );
}

void dessiner_ennemi(Ennemi e){
    MLV_draw_filled_circle(e.x, e.y, TAILLE_PERSONNAGE, MLV_COLOR_PURPLE);
}


void dessiner_bombe_et_explosion(Bombe b) {
    int centre_y, centre_x, rayon, t, portee_l, portee_c;
    if (b.active) {
        centre_x = b.x + TAILLE_PERSONNAGE / 2;
        centre_y = b.y + TAILLE_PERSONNAGE / 2;
        rayon = TAILLE_PERSONNAGE / 2;
        MLV_draw_filled_circle(centre_x, centre_y, rayon, MLV_COLOR_RED);
        MLV_draw_circle(centre_x, centre_y, rayon, MLV_COLOR_BLACK);
    } else if (b.en_explosion) {
        t = TAILLE_PERSONNAGE;
        portee_c = PORTEE_EXPLOSION_COLONNE;
        portee_l = PORTEE_EXPLOSION_LIGNE;
        
        /* explosion haut */
        MLV_draw_filled_rectangle(b.x, b.y - portee_c * t, t, portee_c * t, MLV_COLOR_YELLOW);
        MLV_draw_rectangle(b.x, b.y - portee_c * t, t, portee_c * t, MLV_COLOR_ORANGE);
        /* explosion bas */
        MLV_draw_filled_rectangle(b.x, b.y + t, t, portee_c * t, MLV_COLOR_YELLOW);
        MLV_draw_rectangle(b.x, b.y + t, t, portee_c * t, MLV_COLOR_ORANGE);

        /* explosion gauche */
        MLV_draw_filled_rectangle(b.x - portee_l * t, b.y, portee_l * t, t, MLV_COLOR_YELLOW);
        MLV_draw_rectangle(b.x - portee_l * t, b.y, portee_l * t, t, MLV_COLOR_ORANGE);

        /* explosion droite */
        MLV_draw_filled_rectangle(b.x + t, b.y, portee_l * t, t, MLV_COLOR_YELLOW);
        MLV_draw_rectangle(b.x + t, b.y, portee_l * t, t, MLV_COLOR_ORANGE);
    }
}
