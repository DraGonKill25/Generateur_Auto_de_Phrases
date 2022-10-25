#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include "dico_node.h"

#include "helper.h"


size_t mystrlen(char *s)
{
  if (!s)
    return 0;
  
  size_t i = 0;
  while (s[i] != '\0')
    i++;
  return i;
}
void mystrcat(char *str1, char *str2)
{
	int i, len1=0;
	/* Calculating length of first string */
	len1 = mystrlen(str1);
	/*on ajoute la place du nouveau caratere + on ajoute la place du '/0'*/
	realloc(str1, (len1 + 1 + 1) * sizeof(char))
	/*on ajoute le nouveau caractere dans la string*/
	*(str1 + i) = str2;
	/*on place le '\0' a la fin de la string*/
	*(str1 + i + 1)='\0';
}



/*
on sait que on doit lancer diffenrete recherche dans chaque arbre
pour recup chaque type de mot
ensuite on print la phrase
*/






void find_nom (Nnom *tree ,char* word)
{
	//condition d'arret: lorsque qu'on a plus de fils et par consequent que end = 0;
	//on peut refaire un random modulo 2 pour avoir 0 ou 1 pour savoir si on continu ou on s'arrete la pour le mot
	if (tree == NULL)
	{
		return;
	}

	if (tree->nom->end && tree->nbchildren != 0)
	{
		if (rand()%2)
		{
			mystrcat(word, tree->nom->lettre);
			return;
		}
	}

	//copy de la lettre dans le string word
	mystrcat(word, tree->nom->lettre);

	//creation d'un random modulo nbchildren
	int r = rand() % tree->nbchildren;
	
	//on lance la recursion sur l'enfant choisi au hassard
	if (tree->nbchildren != 0)
	{
		return find_nom(tree->children[r], word);
	}
	return;
}


void find_vb (Nnom *tree ,char* word)
{
	//condition d'arret: lorsque qu'on a plus de fils et par consequent que end = 0;
	//on peut refaire un random modulo 2 pour avoir 0 ou 1 pour savoir si on continu ou on s'arrete la pour le mot
	if (tree == NULL)
	{
		return;
	}

	if (tree->Vb->end && tree->nbchildren != 0)
	{
		if (rand()%2)
		{
			mystrcat(word, tree->vb->lettre);
			return;
		}
	}

	//creation d'un random modulo nbchildren
	int r = rand() % tree->nbchildren;
	
	//on lance la recursion sur l'enfant choisi au hassard
	if (tree->nbchildren != 0)
	{
		return find_vb(tree->children[r], word);
	}
	return;
}

void find_adj (Nnom *tree ,char* word)
{
	//condition d'arret: lorsque qu'on a plus de fils et par consequent que end = 0;
	//on peut refaire un random modulo 2 pour avoir 0 ou 1 pour savoir si on continu ou on s'arrete la pour le mot
	if (tree == NULL)
	{
		return;
	}

	if (tree->adj->end && tree->nbchildren != 0)
	{
		if (rand()%2)
		{
			mystrcat(word, tree->adj->lettre);
			return;
		}
	}

	//creation d'un random modulo nbchildren
	int r = rand() % tree->nbchildren;
	
	//on lance la recursion sur l'enfant choisi au hassard
	if (tree->nbchildren != 0)
	{
		return find_adj(tree->children[r], word);
	}
	return;
}

void find_adv (Nnom *tree ,char* word)
{
	//condition d'arret: lorsque qu'on a plus de fils et par consequent que end = 0;
	//on peut refaire un random modulo 2 pour avoir 0 ou 1 pour savoir si on continu ou on s'arrete la pour le mot
	if (tree == NULL)
	{
		return;
	}

	if (tree->adv->end && tree->nbchildren != 0)
	{
		if (rand()%2)
		{
			mystrcat(word, tree->adv->lettre);
			return;
		}
	}

	//creation d'un random modulo nbchildren
	int r = rand() % tree->nbchildren;
	
	//on lance la recursion sur l'enfant choisi au hassard
	if (tree->nbchildren != 0)
	{
		return find_adv(tree->children[r], word);
	}
	return;
}








int main(int argc, char const *argv[])
{
	/* code */
	srand(time(NULL));
	 
	return 0;
}