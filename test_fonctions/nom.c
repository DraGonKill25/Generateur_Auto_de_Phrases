#include "helper.h"
#include "nom.h"

/*
===============================================================================
							FONCTION NOM
===============================================================================
*/

void __Nom_Aleatoire2 (Nom *noeud)
{

    //mon noeud est pas vide donc j'ajoute la lettre dans ma string
    printf("%c", noeud->lettre);

    //je verifie que je suis arrive a une forme de base
    if(noeud->end)
    {
        //si le noeud est pas une feuille
        if (noeud->nbenfant != 0)
        {
            //alors on regarde si on s'arrete a ce noeud
            //ou si on continue l'aleatoire
            int quit = rand() % 20;

            //si on s'arrete a ce noeud
            if (quit == 18)
            {
                return ;
            }
        }
            //sinon on retourne tout simplement le noeud
        else
            return ;
    }

    //aleatoire du cas general pour savoir ou on se deplace dans notre
    //matrice d'enfant
    int aleatoire = rand() % noeud->nbenfant;

    //on lance la recursion sur le bon enfant
    return __Nom_Aleatoire2(noeud->child[aleatoire]);
}
char* __Nom_Aleatoire(Nom *noeud, char *str_to_return)
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
	return __Nom_Aleatoire(noeud->child[aleatoire], str_to_return);
}

char* Nom_Aleatoire(RNom tree, char *str_to_return)
{
	if (!tree.nbenfant)
	{
		return NULL;
	}
    str_to_return = NULL;

	int ale = rand() % tree.nbenfant;
	//str_to_return = mystrcat(str_to_return, &(tree.child[ale]->lettre));

	if (tree.child[ale]->end)
	{
        //int quit = rand() % 2;
        return &tree.child[ale]->lettre;

	}

	return __Nom_Aleatoire(tree.child[ale], str_to_return);
}


int __Nom_Present(char *mot, Nom *n)
{
	if (!n)
	{
		return -1;//EXIT_FAILURE;
	}

	//pcq il y a la root il faudrat rajouter des fonctions chapeau a toutes les autres fonctions
	int pos_mot = 1;

	//tant que je suis pas arriver a la fin du mot que je cherche
	while(*(mot + pos_mot) != '\0')
	{
		int stop = 0;
		int i = 0;
		//je cherche si mes enfants on bien la lettre suivante
		for (; i < n->nbenfant && !stop; i++)
		{
			//si la lettre suivante est trouver je stop
			if (*(mot + pos_mot) == n->child[i]->lettre)
			{
				stop = 1;
			}
		}

		//la lettre est trouver donc je me deplace dessus
		if (stop)
		{
			n = n->child[i];
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

int Nom_Present(char *mot, RNom tree)
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

	return __Nom_Present(mot, tree.child[i]);
}




int Is_Conj_Nom(Fnom *n1, Fnom *n2)
{
	if (!n1)
	{
		return 0;
	}
	int pos = 0;

    while (n1 != NULL)
    {
        if (strcmp(n1->genre, n2->genre) == 0)
        {
            if (strcmp(n1->nombre, n2->nombre) == 0)
                return pos;
        }

        pos++;
        n1 = n1->next;
    }
    return -1;
}

Fnom* flechie_Nom(Fnom *f, int place)
{
	int i = 0;
	while (i < place)
	{
		f = f->next;
        i++;
	}
	return f;
}


char* __Trouver_Nom_Conj(Nom *noeud, Fnom *n)
{
	Nom *save = noeud;
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
			int isconj = Is_Conj_Nom(noeud->ff, n);
			if (isconj >= 0)
			{
				Fnom *conj_match = flechie_Nom(noeud->ff, isconj); /*la bonne forme flechie*/
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


char* Trouver_Nom_Conj(RNom tree, Nom *n)
{
	if (!n)
	{
		return NULL;//EXIT_FAILURE;
	}

	char *result = NULL;
	int aleatoire = rand() % tree.nbenfant;

	while (!(result = __Trouver_Nom_Conj(tree.child[aleatoire], n->ff)))//pour le flex
	{
		aleatoire = rand() % tree.nbenfant;
	}

	return result;
}



/*
===============================================================================
							FIN FONCTION NOM
===============================================================================
*/