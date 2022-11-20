//
//Projet Générateur automatique de phrases
//Adam RILI, Timothé DEBORD, Nathan SIMOES
//
//Fichier qui a pour role de définir les protoypes des fonctions utilisées dans le fichier arbreAdv.c
//Ces deux fichiers ont pour roles la création de l'arbre des adverbes, et l'insertion d'un adverbe si cet arbre est déjà
//créé et que l'adverbe ne s'y trouves pas.

#ifndef CREATION_ARBRES_ARBREADV_H
#define CREATION_ARBRES_ARBREADV_H

#include "../Fonctionnalites/helper.h"



int isValInTabAdv(Adv **tab, int length, char flettre);

Adv* newNodeAdv(char);

void initStructAdv(Adv*);

Adv* createNodeAdv(Adv *p_node, char lettre);

void insertTreeAdv(RAdv *, char*);

#endif
