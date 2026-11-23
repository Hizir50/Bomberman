#include <MLV/MLV_all.h>
#include "menu.h"
#include "affichage.h"
#include "jeu.h"

int cliquer_nouvelle_partie(int x, int y) {
    if (x >= BTN_X && x <= BTN_X + BTN_L && y >= BTN_NP_Y && y <= BTN_NP_Y + BTN_H) {
        return 1; /* Clic valide ! */
        
    }
    return 0;
}

int cliquer_charger(int x,int y) {
    if (x >= BTN_X && x <= BTN_X + BTN_L && y >= BTN_CH_Y && y <= BTN_CH_Y + BTN_H) {
        return 1; /* Clic valide ! */
    }
    return 0;
}

int cliquer_meilleurs_scores(int x,int y) {
    if (x >= BTN_X && x <= BTN_X + BTN_L && y >= BTN_MS_Y && y <= BTN_MS_Y + BTN_H) {
        return 1; /* Clic valide ! */
    }
    return 0;
}

int cliquer_quitter(int x, int y){
    if (x >= BTN_X && x <= BTN_X + BTN_L && y >= BTN_QU_Y && y <= BTN_QU_Y + BTN_H) {
        return 1;
    }
    return 0;
}

int cliquer_retour(int x,int y){
    if(x >= BTN_RE_X && x <= BTN_RE_X + BTN_RE_L && y >= BTN_RE_Y && y <= BTN_RE_Y + BTN_H){
        return 1; /* Clic valide ! */
    }
    return 0;
}



