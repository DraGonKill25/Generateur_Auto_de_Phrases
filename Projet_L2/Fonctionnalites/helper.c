#include "helper.h"
#include <stdlib.h>


/*
===============================================================================
							FONCTION COMMUNE
===============================================================================
*/

size_t mystrlen(char *s)
{
    if (!s)
        return 0;

    size_t i = 0;
    size_t j = 0;
    while (*(s+i) != '\0')
    {
        if (*(s+i)<'a' && *(s+i)>'z')
            j++;
        i++;
    }
    return i - j;
}

char* mystrcat(char *str1, char *str2)
{
	int len1=0;
	/* Calculating length of first string */
	len1 = mystrlen(str1);
	/*on ajoute la place du nouveau caratere + on ajoute la place du '/0'*/
	str1 = realloc(str1, (len1 + 1 + 1) * sizeof(char));
	/*on ajoute le nouveau caractere dans la string*/
	*(str1 + len1) = *str2;
	/*on place le '\0' a la fin de la string*/
	*(str1 + len1 + 1)='\0';

    return str1;
}



int mystrcmp(char *s1, char *s2)
{
    int i = 0;
    if (!s1)
        return 0;

    while(*(s1 + i) != '\0' && *(s2 + i) != '\0' && *(s1 + i) == *(s2 +i))
        i++;

    if(*(s1 + i) == '\0' && *(s2 + i) == '\0')
        return 1;    
    if (!(*(s1 + i) >= 'a' && *(s1 +i) <= 'z'))
        return 0;
    return 0;
      
}


char* mystrff(char *s1, char *s2, int diff)
{

    if(!s2)
    {
        return s1;
    }
	int i=0, len1=0, len2=0, j=0;
	char *toreturn = NULL; //string a retourner avec la forme flechit
	int total = 0;
	len1 = mystrlen(s1);
	len2 = mystrlen(s2);
    //printf("c'est la| %d||%d\n", diff, -diff > (len1 + len2));
	if (-diff > (len1 + len2))
	{
	    diff = 0;
	}

	if (diff == 0)
	    return s1;

	//on differencie 2 cas celui ou la longueur de la chaine toreturn
	//depend entierement de la forme de base donc diff >= 0
	//et ou la forme de base doit etre modifiee donc diff < 0

	//dans le cas ou la forme de base doit etre modifier
	if (diff < 0)
	{
		//on calcule la longueur toreturn
		total = (len1 + len2 + diff + 1/*pour le \0*/);
		//on alloue la bonne taille memoire a toreturn
		toreturn = malloc(total * sizeof(char));

		//boucle pour parcourir toutes ma string
		while (i < total)
		{
			//copie du radical commun entre la fdb et la ff
			if (i < (len1+diff))
			{
				*(toreturn + i) = *(s1 + i);
			}

			//copie de la ff
			else
			{
				*(toreturn + i) = *(s2+ j);
				j++;
			}

			i++;
		}
	}
	
	//dans le cas ou la fdb est incluse dans la ff
	if (diff > 0)
	{
		//on calcule la taille total de to return
		total = (len1 + len2 + 1/*pour le \0*/);
		//et on alloue l'espace necessaire
		toreturn = malloc(total * sizeof(char));

		//on parcours toute la string toreturn
		while (i < total)
		{
			//on copie la forme de base
			if (i < len1)
			{
				*(toreturn + i) = *(s1 + i);
			}
			//on ajoute la ff
			else
			{
				*(toreturn + i) = *(s2 + j);
				j++;
			}

			i++;
		}
	}

	//on return la string de la forme flechit
	return toreturn;
}



/*
===============================================================================
						FIN	FONCTION COMMUNE
===============================================================================
*/
