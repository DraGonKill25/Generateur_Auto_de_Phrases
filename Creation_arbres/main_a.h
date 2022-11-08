//
// Created by natha on 03/11/2022.
//


#ifndef MAIN_C_MAIN_A_H
#define MAIN_C_MAIN_A_H

#include <stdlib.h>
#include <stdio.h>
#include "helper.h"


int isValInTab(Vb**, int, char);

Vb* newNode(char);

Fvb* createFvb(char*, char*);

void addEndVb(Vb*, char*, char*);

void initStructVb(Vb*);

Vb* createNode(Vb *, char);

RVb insertTreeVb(RVb, char*, char*, char*);

#endif //MAIN_C_MAIN_A_H
