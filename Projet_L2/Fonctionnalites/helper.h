#ifndef HELPER_H
#define HELPER_H


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include "../structures.h"


size_t mystrlen(char *s);
char* mystrcat(char *str1, char *str2);
int mystrcmp(char*, char*);
char* mystrff(char *s1, char *s2, int diff);



#endif
