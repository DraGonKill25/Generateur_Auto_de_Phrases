//
//Projet Générateur automatique de phrases
//Adam RILI, Timothé DEBORD, Nathan SIMOES
//
//Fichier qui a pour role de définir les protoypes des fonctions utilisées dans le fichier arbreNom.c
//Ces deux fichiers ont pour roles la création de l'arbre des noms, et l'insertion d'un nom si cet arbre est déjà
//créé et que le nom ne s'y trouves pas.

#ifndef CREATION_ARBRES_ARBRENOM_H
#define CREATION_ARBRES_ARBRENOM_H

#include "../Fonctionnalites/helper.h"


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
