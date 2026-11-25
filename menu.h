#ifndef _MENU_H_
#define _MENU_H_
#include "affichage.h"


#define BTN_H 50        /*La hauteur des boutons (TOUS LES MEMES)*/

#define BTN_L (LARGEUR_FENETRE / 3) /*La Largeur des Boutons tous les meme aussi*/
#define BTN_X (LARGEUR_FENETRE / 3) /*L'Alignement en X des boutons (TOUS LES MEME AUSSI CENTREE)*/

#define BTN_NP_Y (HAUTEUR_FENETRE / 5) + 0
#define BTN_CH_Y (HAUTEUR_FENETRE / 5) + 200 
#define BTN_MS_Y (HAUTEUR_FENETRE / 5) + 400  
#define BTN_QU_Y (HAUTEUR_FENETRE / 5) + 600

#define BTN_RP_Y (HAUTEUR_FENETRE / 5) + 0
#define BTN_SA_Y (HAUTEUR_FENETRE / 5) + 300
#define BTN_MP_Y (HAUTEUR_FENETRE / 5) + 600

#define BTN_RE_X 50
#define BTN_RE_Y 50
#define BTN_RE_L LARGEUR_FENETRE / 4

#define BTN_S1_Y (HAUTEUR_FENETRE / 5) 
#define BTN_S2_Y (HAUTEUR_FENETRE / 5) + 200
#define BTN_S3_Y (HAUTEUR_FENETRE / 5) + 400
#define BTN_S4_Y (HAUTEUR_FENETRE / 5) + 600




int cliquer_nouvelle_partie(int x,int y);
int cliquer_charger(int x, int y);
int cliquer_meilleurs_scores(int x,int y);
int cliquer_quitter(int x,int y);
int cliquer_retour(int x,int y);
int cliquer_reprendre(int x,int y);
int cliquer_sauvegarder(int x,int y);
int cliquer_menu_principal(int x,int y);

int cliquer_slot_1(int x,int y);
int cliquer_slot_2(int x,int y);
int cliquer_slot_3(int x,int y);
int cliquer_slot_4(int x,int y);



#endif /* _MENU_H_ */