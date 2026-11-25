#ifndef _JEU_H_
#define _JEU_H_


typedef enum{
    /* portee = 0, freeze = 1, B_ligne = 2, B_colonne = 3 */
    PORTEE,   
    FREEZE,
    B_LIGNE,
    B_COLONNE
}Bonus;

typedef struct{
    int x;
    int y;
    int etourdi; /* si etourdi on peut passer dessus */
    int direction;
}Ennemi;

Ennemi creer_ennemi();
void deplacement_ennemi(Ennemi *e);

#endif