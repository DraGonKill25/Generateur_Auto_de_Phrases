//
// Created by natha on 03/11/2022.
//


#ifndef MAIN_C_MAIN_A_H
#define MAIN_C_MAIN_A_H

#include <stdlib.h>
#include <stdio.h>
#include "../test_fonctions/helper.h"

size_t mystrlen(char *s);

int isValInTab(Vb**, int, char);

Vb* newNode(char);

void initStructVb(Vb*);

Vb* createNode(Vb *, char);

char* Calculer_Diff_et_ff(char *temp1, char *temp2, int *diff);

void addFvb(char* temp1, char* temp2, char* temp3, int i, Fvb *f);

Fvb* createFirstFvb(char* temp1, char* temp2, char* temp3);

int insertCarac(Fvb *, char*, int);

void insertTreeVb(RVb *, char*, char*, char*);

#endif //MAIN_C_MAIN_A_H
