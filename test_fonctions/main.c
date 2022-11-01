#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>
#include <time.h>
#include <assert.h>
#include <string.h>
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
	realloc(str1, (len1 + 1 + 1) * sizeof(char));
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

Vb Trouver_Verbe(Vb noeud, char *str_to_return)
{
	//parcours de notre arbre jusqu'a touve end == 1
    //pb de compatibilite
	/*if (!noeud)
	{
		return EXIT_FAILURE;
	}*/
	
	mystrcat(str_to_return, noeud.lettre);
	
	if(noeud.end)
	{
		return noeud;
	}

	int aleatoire = rand() % noeud.nbenfant;
	return Trouver_Verbe(*noeud.child[aleatoire], str_to_return);
}



char* mystrff(char *s1, char *s2, int diff)
{
	int i=0, len1=0, len2=0, j=0;
	char *toreturn = NULL;
	int total;
	len1 = mystrlen(s1);
	len2 = mystrlen(s2);

	if (diff < 0)
	{
		total = (len1 + len2 + diff + 1/*pour le \0*/);
		toreturn = malloc(total * sizeof(char));

		while (i < total)
		{
			if (i < (len1-diff))
			{
				*(toreturn + i) = (len1 + i);
			}
			else
			{
				*(toreturn + i) = (len2 + j);
				j++;
			}

			i++;
		}
	}
	
	if (diff > 0)
	{
		total = (len1 + len2 + 1/*pour le \0*/);
		toreturn = malloc(total * sizeof(char));
		while (i < total)
		{
			if (i < len1)
			{
				*(toreturn + i) = (len1 + i);
			}
			else
			{
				*(toreturn + i) = (len2 + j);
				j++;
			}

			i++;
		}
	}

	return toreturn;
}




char* Trouver_FFVB(Vb noeud, char *fdb, Nom n)
{
	char *toreturn; //str qui ca contenir ma forme flechie complete
	Fvb *temp = noeud.ff;
	
	while (temp != NULL)
	{
		if (temp->genre == n.ff->genre)
		{
			if (temp->nombre == n.ff->nombre)
			{
					toreturn = mystrff(fdb, temp->ff, temp->diff);
					break;
			}
		}

		temp = temp->next;
	}

	return toreturn;
}




































int main(int argc, char const *argv[])
{
	/* code */
	srand(time(NULL));
	 
	return 0;
}