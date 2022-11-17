#ifndef CREATION_ARBRE_ARBREVB_H
#define CREATION_ARBRE_ARBREVB_H

#include "../Fonctionnalites/helper.h"


int isValInTabVb(Vb **tab, int length, char flettre);

Vb* newNodeVb(char);

void initStructVb(Vb*);

Vb* createNodeVb(Vb *p_node, char lettre);

char* Calculer_Diff_et_ffVb(char *temp1, char *temp2, int *diff);

void addFvb(char* temp1, char* temp2, char* temp3, int i, Fvb *f);

Fvb* createFirstFvb(char* temp1, char* temp2, char* temp3);

int insertCaracVb(Fvb *, char*, int);

void insertTreeVb(RVb *, char*, char*, char*);

#endif
