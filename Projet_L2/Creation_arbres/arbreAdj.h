//
//Projet Générateur automatique de phrases
//Adam RILI, Timothé DEBORD, Nathan SIMOES
//
//Fichier qui a pour role de définir les protoypes des fonctions utilisées dans le fichier arbreAdj.c
//Ces deux fichiers ont pour roles la création de l'arbre des adjectifs, et l'insertion d'un adjectif si cet arbre est déjà
//créé et que l'adjectif ne s'y trouves pas.

#ifndef CREATION_ARBRE_ARBREADJ_H
#define CREATION_ARBRE_ARBREADJ_H

#include "../Fonctionnalites/helper.h"

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
