#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"


void afficher_fenetre_principale() {
    MLV_create_window(
        "medium - 12 - Le résolution du bureau d'environement", 
        "résolution du bureau", LARGEUR-LARGEUR/6, HAUTEUR-HAUTEUR/6
    );
    MLV_draw_text(
        200, 20,
        "La résolution du bureau est de : %d X %d",
        MLV_COLOR_GREEN,
        LARGEUR-LARGEUR/6, HAUTEUR-HAUTEUR/6
    );
    
    MLV_actualise_window();
    MLV_wait_seconds(2);
    MLV_free_window();
}

