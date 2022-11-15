//
// Created by natha on 15/11/2022.
//

#ifndef MAIN_A_H_ARBREADV_H
#define MAIN_A_H_ARBREADV_H

#include <stdlib.h>
#include <stdio.h>
#include "../Projet_L2/dico_node.h"


int isValInTab(Adv**, int, char);

Adv* newNode(char);

void initStructAdv(Adv*);

Adv* createNode(Adv *, char);

void insertTreeAdv(RAdv *, char*, char*, char*);

#endif //MAIN_A_H_ARBREADV_H
