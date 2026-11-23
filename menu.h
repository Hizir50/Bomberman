#ifndef _MENU_H_
#define _MENU_H_
#include "affichage.h"


#define BTN_H 50        /*La hauteur des boutons (TOUS LES MEMES)*/
#define BTN_L (LARGEUR_FENETRE / 3) /*La Largeur des Boutons tous les meme aussi*/

#define BTN_X (LARGEUR_FENETRE / 3) /*L'Alignement en X des boutons (TOUS LES MEME AUSSI CENTREE)*/

#define BTN_NP_Y (HAUTEUR_FENETRE / 8)
#define BTN_CH_Y (HAUTEUR_FENETRE / 8) + 200 
#define BTN_MS_Y (HAUTEUR_FENETRE / 8) + 400  
#define BTN_QU_Y (HAUTEUR_FENETRE / 8) + 600

#define BTN_RE_X 50
#define BTN_RE_Y 50
#define BTN_RE_L LARGEUR_FENETRE / 4



int cliquer_nouvelle_partie(int x,int y);
int cliquer_charger(int x, int y);
int cliquer_meilleurs_scores(int x,int y);
int cliquer_quitter(int x,int y);
int cliquer_retour(int x,int y);
void boucle_affichage();

#endif /* _MENU_H_ */