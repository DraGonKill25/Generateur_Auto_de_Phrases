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
														FONCTION COMMUNE
===============================================================================
*/
size_t mystrlen(char *s)
{
  if (!s)
    return 0;
  
  size_t i = 0;
  while (*(s+i) != '\0')
    i++;
  return i;
}

void mystrcat(char *str1, char *str2)
{
	int i, len1=0;
	/* Calculating length of first string */
	len1 = mystrlen(str1);
	/*on ajoute la place du nouveau caratere + on ajoute la place du '/0'*/
	str1 = realloc(str1, (len1 + 1 + 1) * sizeof(char));
	/*on ajoute le nouveau caractere dans la string*/
	*(str1 + i) = *str2;
	/*on place le '\0' a la fin de la string*/
	*(str1 + i + 1)='\0';
}




char* mystrff(char *s1, char *s2, int diff)
{

	int i=0, len1=0, len2=0, j=0;
	char *toreturn = NULL; //string a retourner avec la forme flechit
	int total = 0;
	len1 = mystrlen(s1);
	len2 = mystrlen(s2);

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
			if (i < (len1-diff))
			{
				*(toreturn + i) = (len1 + i);
			}

			//copie de la ff
			else
			{
				*(toreturn + i) = (len2 + j);
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
				*(toreturn + i) = (len1 + i);
			}
			//on ajoute la ff
			else
			{
				*(toreturn + i) = (len2 + j);
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




/*
===============================================================================
														FONCTION VERBE
===============================================================================
*/
Vb* __Verbe_Aleatoire(Vb *noeud, char **str_to_return)
{
	//si jamais on rentre avec un arbre vide
	//ou probleme dans la recursion
	if (!noeud)
	{
		return NULL;//EXIT_FAILURE;
	}

	//mon noeud est pas vide donc j'ajoute la lettre dans ma string
	mystrcat(*str_to_return, &(noeud->lettre));
	
	//je verifie que je suis arrive a une forme de base
	if(noeud->end)
	{
		//si le noeud est pas une feuille
		if (noeud->nbenfant != 0)
		{
			//alors on regarde si on s'arrete a ce noeud
			//ou si on continue l'aleatoire
			int quit = rand() % 2;

			//si on s'arrete a ce noeud
			if (quit)
			{
				return noeud;
			}
		}
		//sinon on retourne tout simplement le noeud
		else
			return noeud;
	}

	//aleatoire du cas general pour savoir ou on se deplace dans notre
	//matrice d'enfant
	int aleatoire = rand() % noeud->nbenfant;

	//on lance la recursion sur le bon enfant
	return __Verbe_Aleatoire(noeud->child[aleatoire], str_to_return);
}



Vb* Verbe_Aleatoire(RVb tree, char **str_to_return)
{
	if (!tree)
	{
		return NULL;
	}


	int ale = rand() % tree->nbenfant;
	mystrcat(*str_to_return, &(tree).child[ale]);\

	if (tree.child[ale]->end)
	{
		return tree.child[ale];
	}

	return __Verbe_Aleatoire(tree.child[ale], str_to_return);
}






int __Verbe_Present(char *mot, Vb *v)
{
	if (!v)
	{
		return NULL;//EXIT_FAILURE;
	}

	//pcq il y a la root il faudrat rajouter des fonctions chapeau a toutes les autres fonctions
	int pos_mot = 1;

	//tant que je suis pas arriver a la fin du mot que je cherche
	while(*(mot + pos_mot) != '\0')
	{
		int stop = 0;
		int i = 0;
		//je cherche si mes enfants on bien la lettre suivante
		for (; i < v->nbenfant && !stop; i++)
		{
			//si la lettre suivante est trouver je stop
			if (*(mot + pos_mot) == v->child[i]->lettre)
			{
				stop = 1;
			}
		}

		//la lettre est trouver donc je me deplace dessus
		if (stop)
		{
			v = v->child[i];
		}
		//elle n'existe pas dans les enfant donc je break
		else
		{
			break;
		}

		pos_mot++;
	}

	//verif si je suis bien arriver a la fin de la string
	//posibilite de faire concorder pos_mot et len(mot)
	//mais plus de calcule pour rien
	if (*(mot + pos_mot) == '\0')
	{
		return 1;
	}

	//je suis pas arriver a la fin de ma string donc le mot n'est pas present
	return 0;
}



int Verbe_Present(char *mot, RVb tree)
{
	if (!mot || *mot="")
	{
		return -1;
	}

	int i = 0;
	while (i < tree.nbenfant)
	{
		if (tree.child[i] == *mot)
		{
			break;
		}
		i++;
	}

	if (i == tree.nbenfant)
	{
		return 0;
	}

	return __Verbe_Present(mot, tree.child[i]);
}





int Is_Conj_Vb(Fvb *v, Nom *n)
{
	if (!v)
	{
		return 0;
	}
	int pos = 0;
	
	/*
		A Gerer selon comment on fait notre gestion de type
		mais sinon faire une boucle simple avec un while et un if simple pour
		check si le type correspond
	*/
	while (v != NULL)
	{
		if (/* on trouve les memes type */)
		{
			return pos;
		}

		pos++;
		v = v->next; 
	}
	return -1;

}

Fvb flechie_Vb(Fvb *f, int place)
{
	int i = 0;
	while (i < place)
	{
		f = f->next;
	}
	return f;
}


char* __Trouver_Verbe_Conj(Vb *noeud, Nom *n)
{
	//si jamais on rentre avec un arbre vide
	//ou probleme dans la recursion
	if (!noeud)
	{
		return NULL;//EXIT_FAILURE;
	}

	char *fdb = NULL;

	while (1)
	{
		//mon noeud est pas vide donc j'ajoute la lettre dans ma string
		mystrcat(fdb, &(noeud->lettre));

		//aleatoire du cas general pour savoir ou on se deplace dans notre
		//matrice d'enfant
		int aleatoire = rand() % noeud->nbenfant;
		
		//si on arrive sur une fin de forme de base
		if (noeud->end)
		{
			if (noeud->nbenfant != 0)
			{
				int ale = rand() % 2;
				if (ale)
				{
					continue;
				}
				else
				{
					int isconj = Is_Conj_Vb(noeud->ff, n);//retourne la place dans la forme flechie
					if (isconj >= 0)
					{
						Fvb *conj_match = flechie_Vb(noeud , isconj); /*la bonne forme flechie*/
						// on retourne la forme flechie dans une string
						return mystrff(fdb, conj_match, conj_match->diff);
					}
				}
			}
			
			//on verifie qu'il n'y ai pas un enfant qui puisse avoir la bonne conj
			else if (noeud->nbenfant == 0)
			{
				return NULL;				
			}
			//si un enfant peux avoir la bonne conj
			else
				continue;
		}

		//on se deplace sur le bon enfant
		noeud = noeud->child[aleatoire];
	} 

	return NULL;
}

char* Trouver_Verbe_Conj(RVb tree, Nom *n)
{
	if (!n)
	{
		return NULL;//EXIT_FAILURE;
	}

	char *result = NULL;
	int aleatoire = rand() % tree.nbenfant;

	while (!(result = __Trouver_Verbe_Conj(tree.child[aleatoire], n)))//pour le flex
	{
		aleatoire = rand() % tree.nbenfant;
	}

	return result;
}


/*
===============================================================================
													FIN FONCTION VERBE
===============================================================================
*/











/*
===============================================================================
														FONCTION NOM
===============================================================================
*/
Nom* Trouver_Nom_Aleatoire(Nom *noeud, char **str_to_return)
{
	//si jamais on rentre avec un arbre vide
	//ou probleme dans la recursion
	if (!noeud)
	{
		return NULL;//EXIT_FAILURE;
	}

	//mon noeud est pas vide donc j'ajoute la lettre dans ma string
	mystrcat(*str_to_return, &(noeud->lettre));
	
	//je verifie que je suis arrive a une forme de base
	if(noeud->end)
	{
		//si le noeud est pas une feuille
		if (noeud->nbenfant != 0)
		{
			//alors on regarde si on s'arrete a ce noeud
			//ou si on continue l'aleatoire
			int quit = rand() % 2;

			//si on s'arrete a ce noeud
			if (quit)
			{
				return noeud;
			}
		}
		//sinon on retourne tout simplement le noeud
		else
			return noeud;
	}

	//aleatoire du cas general pour savoir ou on se deplace dans notre
	//matrice d'enfant
	int aleatoire = rand() % noeud->nbenfant;

	//on lance la recursion sur le bon enfant
	return Trouver_Nom_Aleatoire(noeud->child[aleatoire], str_to_return);
}




int Nom_Present(char *mot, Nom *v)
{
	if (!v)
	{
		return NULL;//EXIT_FAILURE;
	}

	//pcq il y a la root il faudrat rajouter des fonctions chapeau a toutes les autres fonctions
	int pos_mot = 1;

	//tant que je suis pas arriver a la fin du mot que je cherche
	while(*(mot + pos_mot) != '\0')
	{
		int stop = 0;
		int i = 0;
		//je cherche si mes enfants on bien la lettre suivante
		for (; i < v->nbenfant && !stop; i++)
		{
			//si la lettre suivante est trouver je stop
			if (*(mot + pos_mot) == v->child[i]->lettre)
			{
				stop = 1;
			}
		}

		//la lettre est trouver donc je me deplace dessus
		if (stop)
		{
			v = v->child[i];
		}
		//elle n'existe pas dans les enfant donc je break
		else
		{
			break;
		}

		pos_mot++;
	}

	//verif si je suis bien arriver a la fin de la string
	//posibilite de faire concorder pos_mot et len(mot)
	//mais plus de calcule pour rien
	if (*(mot + pos_mot) == '\0')
	{
		return 1;
	}

	//je suis pas arriver a la fin de ma string donc le mot n'est pas present
	return 0;
}




int Is_Conj_Nom(Fnom *n, Fnom *n)
{
	if (!v)
	{
		return 0;
	}
	int pos = 0;
	
	/*
		A Gerer selon comment on fait notre gestion de type
		mais sinon faire une boucle simple avec un while et un if simple pour
		check si le type correspond
	*/
	while (v != NULL)
	{
		if (/* on trouve les memes type */)
		{
			return pos;
		}

		pos++;
		v = v->next; 
	}
	return -1;

}

Fnom flechie_Nom(Fnom *f, int place)
{
	int i = 0;
	while (i < place)
	{
		f = f->next;
	}
	return f;
}


char* Trouver_Nom_Conj(Nom *noeud, Fnom *n)
{
	//si jamais on rentre avec un arbre vide
	//ou probleme dans la recursion
	if (!noeud)
	{
		return NULL;//EXIT_FAILURE;
	}

	Nom *save = noeud;
	char *fdb = NULL;



	int aleatoire = rand() % noeud->nbenfant;
	noeud = noeud = noeud->child[aleatoire];

	while (1)
	{
		//mon noeud est pas vide donc j'ajoute la lettre dans ma string
		mystrcat(fdb, &(noeud->lettre));

		//aleatoire du cas general pour savoir ou on se deplace dans notre
		//matrice d'enfant
		aleatoire = rand() % noeud->nbenfant;
		
		//si on arrive sur une fin de forme de base
		if (noeud->end)
		{
			int isconj = Is_Conj_Nom(noeud->ff, n);
			if (isconj >= 0)
			{
				Fvb *conj_match = flechie_Nom(noeud , isconj); /*la bonne forme flechie*/
				// on retourne la forme flechie dans une string
				return mystrff(fdb, conj_match, conj_match->diff);
			}
			//on verifie qu'il n'y ai pas un enfant qui puisse avoir la bonne conj
			else if (noeud->nbenfant == 0)
			{
				noeud = save;
				aleatoire = rand() % noeud->nbenfant;
				free(fdb);
				fdb = NULL;				
			}
			//si un enfant peux avoir la bonne conj
			else
				continue;
		}

		//on se deplace sur le bon enfant
		noeud = noeud->child[aleatoire];
	} 

	return NULL;
}



/*
===============================================================================
													FIN FONCTION NOM
===============================================================================
*/











/*
===============================================================================
														FONCTION ADJ
===============================================================================
*/
Adj* Trouver_Adj_Aleatoire(Adj *noeud, char **str_to_return)
{
	//si jamais on rentre avec un arbre vide
	//ou probleme dans la recursion
	if (!noeud)
	{
		return NULL;//EXIT_FAILURE;
	}

	//mon noeud est pas vide donc j'ajoute la lettre dans ma string
	mystrcat(*str_to_return, &(noeud->lettre));
	
	//je verifie que je suis arrive a une forme de base
	if(noeud->end)
	{
		//si le noeud est pas une feuille
		if (noeud->nbenfant != 0)
		{
			//alors on regarde si on s'arrete a ce noeud
			//ou si on continue l'aleatoire
			int quit = rand() % 2;

			//si on s'arrete a ce noeud
			if (quit)
			{
				return noeud;
			}
		}
		//sinon on retourne tout simplement le noeud
		else
			return noeud;
	}

	//aleatoire du cas general pour savoir ou on se deplace dans notre
	//matrice d'enfant
	int aleatoire = rand() % noeud->nbenfant;

	//on lance la recursion sur le bon enfant
	return Trouver_Adj_Aleatoire(noeud->child[aleatoire], str_to_return);
}



int Adj_Present(char *mot, Adj *v)
{
	if (!v)
	{
		return NULL;//EXIT_FAILURE;
	}

	//pcq il y a la root il faudrat rajouter des fonctions chapeau a toutes les autres fonctions
	int pos_mot = 1;

	//tant que je suis pas arriver a la fin du mot que je cherche
	while(*(mot + pos_mot) != '\0')
	{
		int stop = 0;
		int i = 0;
		//je cherche si mes enfants on bien la lettre suivante
		for (; i < v->nbenfant && !stop; i++)
		{
			//si la lettre suivante est trouver je stop
			if (*(mot + pos_mot) == v->child[i]->lettre)
			{
				stop = 1;
			}
		}

		//la lettre est trouver donc je me deplace dessus
		if (stop)
		{
			v = v->child[i];
		}
		//elle n'existe pas dans les enfant donc je break
		else
		{
			break;
		}

		pos_mot++;
	}

	//verif si je suis bien arriver a la fin de la string
	//posibilite de faire concorder pos_mot et len(mot)
	//mais plus de calcule pour rien
	if (*(mot + pos_mot) == '\0')
	{
		return 1;
	}

	//je suis pas arriver a la fin de ma string donc le mot n'est pas present
	return 0;
}





int Is_Conj_Adj(Fadj *n, Fnom *n)
{
	if (!v)
	{
		return 0;
	}
	int pos = 0;
	
	/*
		A Gerer selon comment on fait notre gestion de type
		mais sinon faire une boucle simple avec un while et un if simple pour
		check si le type correspond
	*/
	while (v != NULL)
	{
		if (/* on trouve les memes type */)
		{
			return pos;
		}

		pos++;
		v = v->next; 
	}
	return -1;

}

Fadj flechie_Adj(Fadj *f, int place)
{
	int i = 0;
	while (i < place)
	{
		f = f->next;
	}
	return f;
}


char* Trouver_Adj_Conj(Adj *noeud, Fnom *n)
{
	//si jamais on rentre avec un arbre vide
	//ou probleme dans la recursion
	if (!noeud)
	{
		return NULL;//EXIT_FAILURE;
	}

	Adj *save = noeud;
	char *fdb = NULL;



	int aleatoire = rand() % noeud->nbenfant;
	noeud = noeud = noeud->child[aleatoire];

	while (1)
	{
		//mon noeud est pas vide donc j'ajoute la lettre dans ma string
		mystrcat(fdb, &(noeud->lettre));

		//aleatoire du cas general pour savoir ou on se deplace dans notre
		//matrice d'enfant
		aleatoire = rand() % noeud->nbenfant;
		
		//si on arrive sur une fin de forme de base
		if (noeud->end)
		{
			int isconj = Is_Conj_Adj(noeud->ff, n);
			if (isconj >= 0)
			{
				Fvb *conj_match = flechie_Adj(noeud , isconj); /*la bonne forme flechie*/
				// on retourne la forme flechie dans une string
				return mystrff(fdb, conj_match, conj_match->diff);
			}
			//on verifie qu'il n'y ai pas un enfant qui puisse avoir la bonne conj
			else if (noeud->nbenfant == 0)
			{
				noeud = save;
				aleatoire = rand() % noeud->nbenfant;
				free(fdb);
				fdb = NULL;				
			}
			//si un enfant peux avoir la bonne conj
			else
				continue;
		}

		//on se deplace sur le bon enfant
		noeud = noeud->child[aleatoire];
	} 

	return NULL;
}

/*
===============================================================================
													FIN FONCTION ADJ
===============================================================================
*/











/*
===============================================================================
														FONCTION ADV
===============================================================================
*/
Adv* Trouver_Adv_Aleatoire(Adv *noeud, char **str_to_return)
{
	//si jamais on rentre avec un arbre vide
	//ou probleme dans la recursion
	if (!noeud)
	{
		return NULL;//EXIT_FAILURE;
	}

	//mon noeud est pas vide donc j'ajoute la lettre dans ma string
	mystrcat(*str_to_return, &(noeud->lettre));
	
	//je verifie que je suis arrive a une forme de base
	if(noeud->end)
	{
		//si le noeud est pas une feuille
		if (noeud->nbenfant != 0)
		{
			//alors on regarde si on s'arrete a ce noeud
			//ou si on continue l'aleatoire
			int quit = rand() % 2;

			//si on s'arrete a ce noeud
			if (quit)
			{
				return noeud;
			}
		}
		//sinon on retourne tout simplement le noeud
		else
			return noeud;
	}

	//aleatoire du cas general pour savoir ou on se deplace dans notre
	//matrice d'enfant
	int aleatoire = rand() % noeud->nbenfant;

	//on lance la recursion sur le bon enfant
	return Trouver_Adv_Aleatoire(noeud->child[aleatoire], str_to_return);
}



int Adv_Present(char *mot, Adv *v)
{
	if (!v)
	{
		return NULL;//EXIT_FAILURE;
	}

	//pcq il y a la root il faudrat rajouter des fonctions chapeau a toutes les autres fonctions
	int pos_mot = 1;

	//tant que je suis pas arriver a la fin du mot que je cherche
	while(*(mot + pos_mot) != '\0')
	{
		int stop = 0;
		int i = 0;
		//je cherche si mes enfants on bien la lettre suivante
		for (; i < v->nbenfant && !stop; i++)
		{
			//si la lettre suivante est trouver je stop
			if (*(mot + pos_mot) == v->child[i]->lettre)
			{
				stop = 1;
			}
		}

		//la lettre est trouver donc je me deplace dessus
		if (stop)
		{
			v = v->child[i];
		}
		//elle n'existe pas dans les enfant donc je break
		else
		{
			break;
		}

		pos_mot++;
	}

	//verif si je suis bien arriver a la fin de la string
	//posibilite de faire concorder pos_mot et len(mot)
	//mais plus de calcule pour rien
	if (*(mot + pos_mot) == '\0')
	{
		return 1;
	}

	//je suis pas arriver a la fin de ma string donc le mot n'est pas present
	return 0;
}

/*
===============================================================================
												FIN	FONCTION ADV
===============================================================================
*/



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

	Nom n1 = Trouver_Nom_Aleatoire(t.noms, &str_nom1);
	Nom n2 = Trouver_Nom_Aleatoire(t.noms, &str_nom1);
	Adj j1 = Trouver_Adj_Aleatoire(t.adjectifs, &str_adj);
	Vb v1 = Trouver_Verbe_Aleatoire(t.verbes, &str_vb);

	printf("Modele 1: de la forme nom - adjectif - verbe - nom\n");
	printf("%s %s %s %s", str_nom1, str_adj, str_vb, str_nom2); 
}





int main(int argc, char const *argv[])
{
	return 0;
}