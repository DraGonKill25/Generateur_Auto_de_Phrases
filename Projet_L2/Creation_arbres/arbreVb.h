//
//Projet Générateur automatique de phrases
//Adam RILI, Timothé DEBORD, Nathan SIMOES
//
//Fichier qui a pour role de définir les protoypes des fonctions utilisées dans le fichier arbreVb.c
//Ces deux fichiers ont pour roles la création de l'arbre des verbes, et l'insertion d'un verbe si cet arbre est déjà
//créé et que le verbe ne s'y trouves pas.

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
