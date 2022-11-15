#ifndef CREATION_ARBRES_ARBRENOM_H
#define CREATION_ARBRES_ARBRENOM_H

#include <stdlib.h>
#include <stdio.h>
#include "../Projet_L2/dico_node.h"
#include "helper.h"

int isValInTabNom(Nom **tab, int length, char flettre);

Nom* newNodeNom(char);

void initStructNom(Nom*);

Nom* createNodeNom(Nom *p_node, char lettre);

char* Calculer_Diff_et_ffNom(char *temp1, char *temp2, int *diff);

void addFnom(char* temp1, char* temp2, char* temp3, int i, Fnom *f);

Fnom* createFirstFnom(char* temp1, char* temp2, char* temp3);

int insertCaracNom(Fnom *, char*, int);

void insertTreeNom(RNom *, char*, char*, char*);

#endif
