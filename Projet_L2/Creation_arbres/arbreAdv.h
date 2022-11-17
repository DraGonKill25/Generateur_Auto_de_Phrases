#ifndef CREATION_ARBRES_ARBREADV_H
#define CREATION_ARBRES_ARBREADV_H

#include "../Fonctionnalites/helper.h"



int isValInTabAdv(Adv **tab, int length, char flettre);

Adv* newNodeAdv(char);

void initStructAdv(Adv*);

Adv* createNodeAdv(Adv *p_node, char lettre);

void insertTreeAdv(RAdv *, char*);

#endif
