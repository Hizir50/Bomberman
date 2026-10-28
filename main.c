#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include "affichage.h"
#include "personnage.h"
#include "menu.h"

#define FPS 60


int main(){
        int quitter = 0;
        int est_menu_principale_ouvert = 0;
        int est_menu_ouvert = 0;


        Personnage p = creer_personnage(100, 100);
        afficher_fenetre_principale();

        MLV_change_frame_rate(FPS);

        afficher_menu_principale();  
        MLV_actualise_window();
        while(!est_menu_principale_ouvert) {
                if(MLV_get_keyboard_state(MLV_KEYBOARD_e) == MLV_PRESSED) { /*pour l'instant c'est la touche 'e' mais ca va devnir clique souris sur l'emplacement nouvelle partie*/
                        MLV_wait_milliseconds(35);
                        if(MLV_get_keyboard_state(MLV_KEYBOARD_e) == MLV_RELEASED) {
                                est_menu_principale_ouvert = !est_menu_principale_ouvert;
                        }
                }
        }

        while(!quitter) {

                deplacer_personnage(&p, 0, 0);
                MLV_clear_window(MLV_COLOR_BLACK);
                dessiner_personnage(p);
                

                if(MLV_get_keyboard_state(MLV_KEYBOARD_ESCAPE) == MLV_PRESSED) {
                        quitter = 1;
                }
                if(MLV_get_keyboard_state(MLV_KEYBOARD_m) == MLV_PRESSED) {
                        MLV_wait_milliseconds(35);
                        if(MLV_get_keyboard_state(MLV_KEYBOARD_m) == MLV_RELEASED) {
                                est_menu_ouvert = !est_menu_ouvert;
                        }
                }
                if (est_menu_ouvert) {
                        afficher_menu_pause();
                }
                MLV_actualise_window();
                MLV_delay_according_to_frame_rate();
        }
        MLV_free_window();
        return 0;
}

