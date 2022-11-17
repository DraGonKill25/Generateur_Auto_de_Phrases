#ifndef NOM_H
#define NOM_H

#include "helper.h"

void __Nom_Aleatoire2(Nom *);
char* Nom_Aleatoire(RNom tree, char *str_to_return);
int Nom_Present(char *mot, RNom tree);
char* Trouver_Nom_Conj(RNom tree, Nom *n);



#endif