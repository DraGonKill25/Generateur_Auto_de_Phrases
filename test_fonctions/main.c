#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include "helper.h"



/*
===============================================================================
										FONCTION GENERATION DE PHRASE
===============================================================================
*/


void Generer_Phrase_Ale(Tree t)
{
	char *str_nom1 = NULL;
	char *str_nom2 = NULL;
	char *str_vb = NULL;
	char *str_adv = NULL;
	char *str_adj = NULL;

	Nom *n1 = Nom_Aleatoire(t.noms, &str_nom1);
	Nom *n2 = Nom_Aleatoire(t.noms, &str_nom1);
	Adj *j1 = Adj_Aleatoire(t.adjectifs, &str_adj);
	Vb *v1 = Verbe_Aleatoire(t.verbes, &str_vb);

	printf("%d %d %d %d", n1->lettre, n2->lettre, j1->lettre, v1->lettre);
	printf("Modele 1: de la forme nom - adjectif - verbe - nom\n");
	printf("%s %s %s %s", str_nom1, str_adj, str_vb, str_nom2); 
}





int main()
{
	return 0;
}