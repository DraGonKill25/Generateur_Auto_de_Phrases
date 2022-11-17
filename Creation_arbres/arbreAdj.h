#ifndef CREATION_ARBRE_ARBREADJ_H
#define CREATION_ARBRE_ARBREADJ_H

#include <stdlib.h>
#include <stdio.h>
#include "../Projet_L2/dico_node.h"
#include "../test_fonctions/helper.h"

int isValInTabAdj(Adj **tab, int length, char flettre);

Adj* newNodeAdj(char);

void initStructAdj(Adj*);

Adj* createNodeAdj(Adj *p_node, char lettre);

char* Calculer_Diff_et_ffAdj(char *temp1, char *temp2, int *diff);

void addFadj(char* temp1, char* temp2, char* temp3, int i, Fadj *f);

Fadj* createFirstFadj(char* temp1, char* temp2, char* temp3);

int insertCaracAdj(Fadj *, char*, int);

void insertTreeAdj(RAdj *, char*, char*, char*);

#endif
