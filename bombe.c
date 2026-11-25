#define _POSIX_C_SOURCE 199309L
#include "bombe.h"
#include <time.h>
#include <stdlib.h>


static double obtenir_temps_actuel(void) {
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return (double)ts.tv_sec + (double)ts.tv_nsec / 1e9;
}

Bombe creer_bombe(void) {
    Bombe b;
    b.x = 0;
    b.y = 0;
    b.active = false;
    b.temps_pose = 0;
    b.en_explosion = false;
    b.temps_explosion = 0;
    return b;
}

void poser_bombe(Bombe *b, int x, int y) {
    if (!b->active && !b->en_explosion) {
        b->x = x;
        b->y = y;
        b->active = true;
        b->temps_pose = obtenir_temps_actuel();
    }
}

void mettre_a_jour_bombe(Bombe *b) {
    double maintenant = obtenir_temps_actuel();

    if (b->active) {
        if (maintenant - b->temps_pose >= DUREE_BOMBE) {
            b->active = false;
            b->en_explosion = true;
            b->temps_explosion = maintenant;
        }
    } else if (b->en_explosion) {
        if (maintenant - b->temps_explosion >= DUREE_EXPLOSION) {
            b->en_explosion = false;
        }
    }
}
