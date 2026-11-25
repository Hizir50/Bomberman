#ifndef _BOMBE_H_
#define _BOMBE_H_

#include <stdbool.h>
#include <time.h>

#define PORTEE_EXPLOSION_COLONNE 1
#define PORTEE_EXPLOSION_LIGNE  1
#define DUREE_BOMBE 2.0     
#define DUREE_EXPLOSION 0.5 

typedef struct {
    int x;
    int y;
    bool active;
    double temps_pose;
    bool en_explosion;
    double temps_explosion;
    int portee;
} Bombe;

Bombe creer_bombe(void);
void poser_bombe(Bombe *b, int x, int y);
void mettre_a_jour_bombe(Bombe *b);

#endif
