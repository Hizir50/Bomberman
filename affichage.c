#include "affichage.h"
#include "personnage.h"
#include "menu.h"
#include "bombe.h"


void dessiner_personnage(Personnage p) {
    MLV_draw_filled_rectangle(p.x, p.y, TAILLE_PERSONNAGE, TAILLE_PERSONNAGE, MLV_COLOR_BLUE);
}

void afficher_fenetre_principale(){
    MLV_create_full_screen_window(
        "medium - 12 - Le résolution du bureau d'environement", 
        "résolution du bureau", LARGEUR_FENETRE, HAUTEUR_FENETRE
    );
}

void afficher_menu_principale(){
    MLV_clear_window(MLV_COLOR_YELLOW);

    MLV_draw_text_box(BTN_X, BTN_NP_Y, BTN_L, BTN_H, "NOUVELllLE PARTIE", 1, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_GREEN, MLV_TEXT_LEFT, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);

    MLV_draw_text_box(BTN_X, BTN_CH_Y, BTN_L, BTN_H, "CHARGER", 1, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLUE, MLV_TEXT_LEFT, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);

    MLV_draw_text_box(BTN_X, BTN_MS_Y, BTN_L, BTN_H, "MEILLEURS SCORES", 1, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_RED, MLV_TEXT_LEFT, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);

    MLV_draw_text_box(BTN_X, BTN_QU_Y, BTN_L, BTN_H, "QUITTER", 1, MLV_COLOR_WHITE, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_LEFT, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
}

void afficher_ecran_charger(){
    MLV_clear_window(MLV_COLOR_ALICEBLUE);

    /*Bouton*/
    MLV_draw_rectangle(BTN_RE_X,BTN_RE_Y,BTN_RE_L,BTN_H,MLV_COLOR_BLACK);

    MLV_draw_rectangle(LARGEUR_FENETRE/4,HAUTEUR_FENETRE-(HAUTEUR_FENETRE/2)*1.5,100,100,MLV_COLOR_BLACK);
}

void afficher_menu_pause(){
    MLV_clear_window(MLV_COLOR_GREY);

    MLV_draw_text_box(BTN_X, BTN_RP_Y, BTN_L, BTN_H, "REPRENDRE", 1, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_LEFT, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);

    MLV_draw_text_box(BTN_X, BTN_SA_Y, BTN_L, BTN_H, "SAUVEGARDER", 1, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_LEFT, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);

    MLV_draw_text_box(BTN_X, BTN_MP_Y, BTN_L, BTN_H, "MENU PRINCIPAL", 1, MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_COLOR_BLACK, MLV_TEXT_LEFT, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
}

void afficher_meilleur_scores(){
    MLV_clear_window(MLV_COLOR_PALE_GREEN);

    /*Bouton Retour*/
    MLV_draw_rectangle(BTN_RE_X,BTN_RE_Y,BTN_RE_L,BTN_H,MLV_COLOR_BLACK);

}

/* Les colonnes (et les lignes) se partagent toute la fenetre. */
int largeur_case() {
    return LARGEUR_FENETRE / NB_COLONNES;
}

int hauteur_case() {
    return HAUTEUR_FENETRE / NB_LIGNES;
}


MLV_Color couleur_case(TypeCase type) {
    switch (type) {
        case MUR_INDESTRUCTIBLE:
            return MLV_COLOR_GRAY;   /* gris fonce */
        case MUR_DESTRUCTIBLE:
            return MLV_COLOR_BROWN; /* marron */
        case LIMITE_NIVEAU:
            return MLV_COLOR_RED;   /* rouge */
        default:
            return MLV_COLOR_SANDYBROWN; /* beige */
    }
}

void dessiner_plateau(const Plateau *p) {
    int ligne, colonne;
    for (ligne = 0; ligne < NB_LIGNES; ligne++) {
        for (colonne = 0; colonne < NB_COLONNES; colonne++) {
            /* bornes calculees sur la fenetre entiere : pas de bande vide a droite/en bas */
            int x0 = colonne * LARGEUR_FENETRE / NB_COLONNES;
            int x1 = (colonne + 1) * LARGEUR_FENETRE / NB_COLONNES;
            int y0 = ligne * HAUTEUR_FENETRE / NB_LIGNES;
            int y1 = (ligne + 1) * HAUTEUR_FENETRE / NB_LIGNES;
            MLV_draw_filled_rectangle(
                x0, y0, x1 - x0, y1 - y0,
                couleur_case(lire_case(p, colonne, ligne))
            );
        }
    }
}