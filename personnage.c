#include "personnage.h"
#include <MLV/MLV_all.h>


Personnage creer_personnage(int x, int y) {
    Personnage p;
    p.x = x;
    p.y = y;
    return p;
}

void deplacer_personnage(Personnage *p, int dx, int dy) {

    if(MLV_get_keyboard_state(MLV_KEYBOARD_UP) == MLV_PRESSED) {
        dy = -VITESSE_DEPLACEMENT;
    }
    if(MLV_get_keyboard_state(MLV_KEYBOARD_DOWN) == MLV_PRESSED) {
        dy = VITESSE_DEPLACEMENT;
    }
    if(MLV_get_keyboard_state(MLV_KEYBOARD_LEFT) == MLV_PRESSED) {
        dx = -VITESSE_DEPLACEMENT;
    }
    if(MLV_get_keyboard_state(MLV_KEYBOARD_RIGHT) == MLV_PRESSED) {
        dx = VITESSE_DEPLACEMENT;
    }
    p->x += dx;
    p->y += dy;
}

