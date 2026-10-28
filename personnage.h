#ifndef _PERSONNAGE_H_
#define _PERSONNAGE_H_

/*VITESSE DEPLACEMENT*/
#define VITESSE_DEPLACEMENT 10

/*TAILLE PERSONNAGE*/
#define TAILLE_PERSONNAGE 25


typedef struct {
    int x;
    int y;
} Personnage;



Personnage creer_personnage(int x, int y);
void deplacer_personnage(Personnage *p, int dx, int dy);

#endif /* _PERSONNAGE_H_ */