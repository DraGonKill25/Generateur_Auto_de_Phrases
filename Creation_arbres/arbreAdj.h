//
// Created by natha on 15/11/2022.
//

#ifndef MAIN_A_H_ARBREADJ_H
#define MAIN_A_H_ARBREADJ_H

#include <stdlib.h>
#include <stdio.h>
#include "../Projet_L2/dico_node.h"


int isValInTab(Adj**, int, char);

Adj* newNode(char);

void initStructAdj(Adj*);

Adj* createNode(Adj *, char);

char* Calculer_Diff_et_ff(char *temp1, char *temp2, int *diff);

void addFadj(char* temp1, char* temp2, char* temp3, int i, Fadj *f);

Fadj* createFirstFadj(char* temp1, char* temp2, char* temp3);

int insertCaracAdj(Fadj *, char*, int);

void insertTreeAdj(RAdj *, char*, char*, char*);

#endif //MAIN_A_H_ARBREADJ_H
