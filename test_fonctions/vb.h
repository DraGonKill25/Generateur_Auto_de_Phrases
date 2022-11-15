#ifndef VB_H
#define VB_H

#include "../Projet_L2/dico_node.h"

char* Verbe_Aleatoire(RVb tree, char *str_to_return);
int Verbe_Present(char *mot, RVb tree);
char* Trouver_Verbe_Conj(RVb tree, Fnom *n);



#endif