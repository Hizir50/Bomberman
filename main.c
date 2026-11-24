#include <MLV/MLV_all.h>
#include <stdio.h>
#include "affichage.h"
#include "personnage.h"
#include "generation.h"
#include "menu.h"

#define FPS 30


int main(){
        int quitter = 0;
        int est_menu_principale_ouvert = 0;
        int est_menu_ouvert = 0;
        int afficher_charger = 0;
        int afficher_scores = 0;
        int x,y;
        MLV_Event event;
        MLV_Button_state state;
        MLV_Keyboard_button sym;
        Plateau plateau;

        Personnage p = creer_personnage(100, 100);
        afficher_fenetre_principale();
        MLV_change_frame_rate(FPS);
        initialiser_plateau(&plateau);

        while(!quitter) {
                
                MLV_actualise_window();
                MLV_delay_according_to_frame_rate();

                /* --- Boucle principale pour le menu principal---*/
                if(!est_menu_principale_ouvert){
                        afficher_menu_principale();
                        MLV_actualise_window();
                        while(!est_menu_principale_ouvert){
                                event = MLV_get_event(NULL, NULL, NULL, NULL, NULL, &x, &y, NULL, &state);
                                if(event == MLV_MOUSE_BUTTON && state == MLV_RELEASED) {
                                        if(cliquer_nouvelle_partie(x, y)) {
                                                est_menu_principale_ouvert = !est_menu_principale_ouvert;
                                        }
                                        if(cliquer_charger(x, y)) {
                                                est_menu_principale_ouvert = !est_menu_principale_ouvert;
                                                afficher_charger = !afficher_charger;
                                        }
                                        if(cliquer_meilleurs_scores(x, y)) {
                                                est_menu_principale_ouvert = !est_menu_principale_ouvert;
                                                afficher_scores = !afficher_scores;
                                        }
                                        if(cliquer_quitter(x, y)) {
                                                est_menu_principale_ouvert = !est_menu_principale_ouvert;
                                                quitter = 1;
                                        }
                                }
                        }
                }

                /* ---Jeu---*/
                deplacer_personnage(&p, 0, 0);
                dessiner_plateau(&plateau);
                dessiner_personnage(p);
                level1(&plateau);
                dessiner_personnage(p);

                /*---Menu Pause In GAME---*/
                event = MLV_get_event(&sym, NULL, NULL, NULL, NULL, NULL, NULL, NULL, &state);
                if(event == MLV_KEY && sym == MLV_KEYBOARD_ESCAPE && state == MLV_RELEASED && est_menu_principale_ouvert) {
                        est_menu_ouvert = !est_menu_ouvert;
                }

                /*---Ouverture et fermeture du menu pause---*/
                if(est_menu_ouvert) {
                        afficher_menu_pause();
                        MLV_actualise_window();
                        while(est_menu_ouvert) {
                                event = MLV_get_event(NULL, NULL, NULL, NULL, NULL, &x, &y, NULL, &state);
                                if(event == MLV_MOUSE_BUTTON && state == MLV_RELEASED) {
                                        if(cliquer_reprendre(x, y)) { /* A CHANGER clique_retour deviens clique quitter jeu*/
                                                est_menu_ouvert = !est_menu_ouvert;
                                        }
                                }
                                if(event == MLV_MOUSE_BUTTON && state == MLV_RELEASED) {
                                        if(cliquer_sauvegarder(x, y)) { /* A CHANGER clique_retour deviens clique quitter jeu*/
                                                est_menu_ouvert = !est_menu_ouvert;
                                        }
                                }
                                if(event == MLV_MOUSE_BUTTON && state == MLV_RELEASED) {
                                        if(cliquer_menu_principal(x, y)) { /* A CHANGER clique_retour deviens clique quitter jeu*/
                                                est_menu_ouvert = !est_menu_ouvert;
                                                est_menu_principale_ouvert = !est_menu_principale_ouvert;
                                        }
                                }       
                                if(event == MLV_KEY && sym == MLV_KEYBOARD_ESCAPE && state == MLV_RELEASED) {
                                        est_menu_ouvert = !est_menu_ouvert;
                                }
                        }
                }
                
                /*---Ouverture et fermeture du menu charger---*/
                if(afficher_charger) {
                        afficher_ecran_charger();
                        MLV_actualise_window();
                        while(afficher_charger) {
                                event = MLV_get_event(NULL, NULL, NULL, NULL, NULL, &x, &y, NULL, &state);
                                if(event == MLV_MOUSE_BUTTON && state == MLV_RELEASED) {
                                        if(cliquer_retour(x, y)) {
                                                est_menu_principale_ouvert = !est_menu_principale_ouvert;
                                                afficher_charger = !afficher_charger;
                                        }
                                }
                        }
                }

                /*---Ouverture et fermeture du menu meilleurs scores---*/
                if(afficher_scores) {
                        afficher_meilleur_scores();
                        MLV_actualise_window();
                        while(afficher_scores) {
                                event = MLV_get_event(NULL, NULL, NULL, NULL, NULL, &x, &y, NULL, &state);
                                if(event == MLV_MOUSE_BUTTON && state == MLV_RELEASED) {
                                        if(cliquer_retour(x, y)) {
                                                est_menu_principale_ouvert = !est_menu_principale_ouvert;
                                                afficher_scores = !afficher_scores;
                                        }
                                }
                        }
                }
                
                
        }
        MLV_free_window();
        return 0;
}

