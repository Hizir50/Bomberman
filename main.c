
#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include "affichage.h"
#include "personnage.h"
#include "generation.h"

#define FPS 60


int main(){
        int quitter = 0;
        Plateau plateau;
        Personnage p = creer_personnage(100, 100);
        afficher_fenetre_principale();

        MLV_change_frame_rate(FPS);

       
        initialiser_plateau(&plateau);

        while(!quitter) {
                deplacer_personnage(&p, 0, 0);

                MLV_clear_window(MLV_COLOR_BLACK);

                dessiner_plateau(&plateau);
                dessiner_personnage(p);
                level1(&plateau);
                MLV_actualise_window();

                MLV_delay_according_to_frame_rate();

                

                if(MLV_get_keyboard_state(MLV_KEYBOARD_SPACE) == MLV_PRESSED) {
                        quitter = 1;
                }
        }

        MLV_free_window();

        return 0;
}

