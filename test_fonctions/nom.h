#ifndef NOM_H
#define NOM_H

#include "../Projet_L2/dico_node.h"

char* Nom_Aleatoire(RNom tree, char *str_to_return);
int Nom_Present(char *mot, RNom tree);
char* Trouver_Nom_Conj(RNom tree, Nom *n);



#endif