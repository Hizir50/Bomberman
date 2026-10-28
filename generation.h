#ifndef _GENERATION_H_
#define _GENERATION_H_

#define NB_COLONNES 15
#define NB_LIGNES   13

typedef enum {
    CASE_LIBRE,          /* le joueur peut s'y deplacer                  */
    MUR_INDESTRUCTIBLE,  /* bloque le joueur et les explosions           */
    MUR_DESTRUCTIBLE     /* bloque le joueur, detruit par une explosion  */
} TypeCase;

typedef struct {
    TypeCase grille[NB_LIGNES][NB_COLONNES];
    int depart_colonne;   /* case de depart du joueur : colonne */
    int depart_ligne;     /* case de depart du joueur : ligne   */
} Plateau;


void initialiser_plateau(Plateau *p);


int est_dans_grille(int colonne, int ligne);

TypeCase lire_case(const Plateau *p, int colonne, int ligne);


void ecrire_case(Plateau *p, int colonne, int ligne, TypeCase type);

#endif /* _GENERATION_H_ */