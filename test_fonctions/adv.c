#include "helper.h"
#include "adv.h"


/*
===============================================================================
							FONCTION ADV
===============================================================================
*/
char* __Adv_Aleatoire(Adv *noeud, char *str_to_return)
{
	//si jamais on rentre avec un arbre vide
	//ou probleme dans la recursion
	if (!noeud)
	{
		return NULL;//EXIT_FAILURE;
	}

	//mon noeud est pas vide donc j'ajoute la lettre dans ma string
	str_to_return = mystrcat(str_to_return, &(noeud->lettre));
	
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
				return str_to_return;
			}
		}
		//sinon on retourne tout simplement le noeud
		else
			return str_to_return;
	}

	//aleatoire du cas general pour savoir ou on se deplace dans notre
	//matrice d'enfant
	int aleatoire = rand() % noeud->nbenfant;

	//on lance la recursion sur le bon enfant
	return __Adv_Aleatoire(noeud->child[aleatoire], str_to_return);
}

char* Adv_Aleatoire(RAdv tree, char *str_to_return)
{
	if (!tree.nbenfant)
	{
		return NULL;
	}


	int ale = rand() % tree.nbenfant;
	//str_to_return = mystrcat(str_to_return, &(tree.child[ale]->lettre));

	if (tree.child[ale]->end)
	{
		return &tree.child[ale]->lettre;
	}

	return __Adv_Aleatoire(tree.child[ale], str_to_return);
}



int __Adv_Present(char *mot, Adv *adv)
{

	//pcq il y a la root il faudrat rajouter des fonctions chapeau a toutes les autres fonctions
	int pos_mot = 1;

	//tant que je suis pas arriver a la fin du mot que je cherche
	while(*(mot + pos_mot) != '\0')
	{
		int stop = 0;
		int i = 0;
		//je cherche si mes enfants on bien la lettre suivante
		for (; i < adv->nbenfant && !stop; i++)
		{
			//si la lettre suivante est trouver je stop
			if (*(mot + pos_mot) == adv->child[i]->lettre)
			{
				stop = 1;
			}
		}

		//la lettre est trouver donc je me deplace dessus
		if (stop)
		{
			adv = adv->child[i];
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



int Adv_Present(char *mot, RAdv tree)
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

	return __Adv_Present(mot, tree.child[i]);
}


/*
===============================================================================
							FIN	FONCTION ADV
===============================================================================
*/