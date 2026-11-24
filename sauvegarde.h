#ifndef _SAUVEGARDE_H_
#define _SAUVEGARDE_H_
#include "generation.h"
#include "personnage.h"

int sauvegarder_partie(char* nom_fichier,Plateau* plateau,Personnage* personnage);
int charger_partie(char* nom_fichier, Plateau* plateau, Personnage* personnage);

#endif /* _SAUVEGARDE_H_ */