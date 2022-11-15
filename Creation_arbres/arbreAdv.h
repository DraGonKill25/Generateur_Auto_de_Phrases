#ifndef CREATION_ARBRES_ARBREADV_H
#define CREATION_ARBRES_ARBREADV_H

#include <stdlib.h>
#include <stdio.h>
#include "../Projet_L2/dico_node.h"
#include "helper.h"


int isValInTabAdv(Adv **tab, int length, char flettre);

Adv* newNodeAdv(char);

void initStructAdv(Adv*);

Adv* createNodeAdv(Adv *p_node, char lettre);

void insertTreeAdv(RAdv *, char*);

#endif
