#ifndef _BOMBE_H_
#define _BOMBE_H_

#include <stdbool.h>
#include <time.h>

#define PORTEE_EXPLOSION 1

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