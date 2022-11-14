#include "helper.h"


/*
===============================================================================
							FONCTION ADJ
===============================================================================
*/
Adj* __Adj_Aleatoire(Adj *noeud, char **str_to_return)
{
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
	return __Adj_Aleatoire(noeud->child[aleatoire], str_to_return);
}


Adj* Adj_Aleatoire(RAdj tree, char **str_to_return)
{
	if (!tree.nbenfant)
	{
		return NULL;
	}


	int ale = rand() % tree.nbenfant;
	mystrcat(*str_to_return, &(tree.child[ale]->lettre));

	if (tree.child[ale]->end)
	{
		return tree.child[ale];
	}

	return __Adj_Aleatoire(tree.child[ale], str_to_return);
}


int __Adj_Present(char *mot, Adj *a)
{
	//pcq il y a la root il faudrat rajouter des fonctions chapeau a toutes les autres fonctions
	int pos_mot = 1;

	//tant que je suis pas arriver a la fin du mot que je cherche
	while(*(mot + pos_mot) != '\0')
	{
		int stop = 0;
		int i = 0;
		//je cherche si mes enfants on bien la lettre suivante
		for (; i < a->nbenfant && !stop; i++)
		{
			//si la lettre suivante est trouver je stop
			if (*(mot + pos_mot) == a->child[i]->lettre)
			{
				stop = 1;
			}
		}

		//la lettre est trouver donc je me deplace dessus
		if (stop)
		{
			a = a->child[i];
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



int Adj_Present(char *mot, RAdj tree)
{
	if (!mot)
	{
		return -1;
	}

	int i = 0;
	while (i < tree.nbenfant)
	{
		if (tree.child[i]->lettre == *mot)
		{
			break;
		}
		i++;
	}

	if (i == tree.nbenfant)
	{
		return 0;
	}

	return __Adj_Present(mot, tree.child[i]);
}




int Is_Conj_Adj(Fadj *a, Fnom *n)
{
	if (!a)
	{
		return 0;
	}
	int pos = 0;
	
	/*
		A Gerer selon comment on fait notre gestion de type
		mais sinon faire une boucle simple avec un while et un if simple pour
		check si le type correspond
	*/
	while (a != NULL)
	{
		if (/* on trouve les memes type */)
		{
			return pos;
		}

		pos++;
		a = a->next; 
	}
	return -1;

}

Fadj* flechie_Adj(Fadj *f, int place)
{
	int i = 0;
	while (i < place)
	{
		f = f->next;
	}
	return f;
}


char* __Trouver_Adj_Conj(Adj *noeud, Fnom *n)
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
	noeud = noeud->child[aleatoire];

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
				Fadj *conj_match = flechie_Adj(noeud->ff, isconj); /*la bonne forme flechie*/
				// on retourne la forme flechie dans une string
				return mystrff(fdb, conj_match->ff, conj_match->diff);
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


char* Trouver_Adj_Conj(RAdj tree, Nom *n)
{
	if (!n)
	{
		return NULL;//EXIT_FAILURE;
	}

	char *result = NULL;
	int aleatoire = rand() % tree.nbenfant;

	while (!(result = __Trouver_Adj_Conj(tree.child[aleatoire], n->ff)))//pour le flex
	{
		aleatoire = rand() % tree.nbenfant;
	}

	return result;
}

/*
===============================================================================
							FIN FONCTION ADJ
===============================================================================
*/