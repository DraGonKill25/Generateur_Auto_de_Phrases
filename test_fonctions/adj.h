#ifndef ADJ_H
#define ADJ_H

#include "helper.h"

Adj* Adj_Aleatoire(RAdj tree, char **str_to_return);
int Adj_Present(char *mot, RAdj tree);
char* Trouver_Adj_Conj(RAdj tree, Nom *n);



#endif ADJ_H