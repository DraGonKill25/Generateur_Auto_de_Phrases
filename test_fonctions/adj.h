#ifndef ADJ_H
#define ADJ_H

#include "../Projet_L2/dico_node.h"

char* Adj_Aleatoire(RAdj tree, char *str_to_return);
int Adj_Present(char *mot, RAdj tree);
char* Trouver_Adj_Conj(RAdj tree, Nom *n);



#endif