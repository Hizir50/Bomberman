#include "jeu.h"
#include "stdio.h"
#include "bombe.h"
#include "personnage.h"

Ennemi creer_ennemi(){
    Ennemi e;
    e.x = 100;
    e.y = 100;
    e.etourdi = 0;
    e.direction = 0;
    return e;
}

void toucher_ennemi(Ennemi *e,Bombe *b){
    if(b->x < e->x - TAILLE_PERSONNAGE && b->x >){
        e->etourdi = 1;
    }
}

void deplacement_ennemi(Ennemi *e){
    int dx;
    if(e->x == 1500){
        e->direction = 0;
    }
    if(e->x == 50){
        e->direction = 1;
    }
    if(e->direction == 0){
        dx = -1;
    }
    if(e->direction == 1){
        dx = 1;
    }
    if(e->etourdi == 1){
        dx = 0;
    }
    e->x += 10 * dx;
}