//
// Created by natha on 15/11/2022.
//

#ifndef MAIN_A_H_ARBRENOM_H
#define MAIN_A_H_ARBRENOM_H

#include <stdlib.h>
#include <stdio.h>
#include "../Projet_L2/dico_node.h"


int isValInTab(Nom**, int, char);

Nom* newNode(char);

void initStructNom(Nom*);

Nom* createNode(Nom *, char);

char* Calculer_Diff_et_ff(char *temp1, char *temp2, int *diff);

void addFnom(char* temp1, char* temp2, char* temp3, int i, Fnom *f);

FNom* createFirstFnom(char* temp1, char* temp2, char* temp3);

int insertCaracNom(Fnom *, char*, int);

void insertTreeNom(RNom *, char*, char*, char*);

#endif //MAIN_A_H_ARBRENOM_H
