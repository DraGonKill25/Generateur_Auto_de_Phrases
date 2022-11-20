#include "helper.h"
#include "vb.h"
#include <stddef.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
//#include "structures.h"

/*
===============================================================================
						FONCTION VERBE
===============================================================================
*/
void __Verbe_Aleatoire2(Vb *noeud)
{
    //si jamais on rentre avec un arbre vide
    //ou probleme dans la recursion
    if (!noeud)
    {
        return ;//EXIT_FAILURE;
    }

    //mon noeud est pas vide donc j'ajoute la lettre dans ma string
    //str_to_return = mystrcat(str_to_return, &(noeud->lettre));
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
    return __Verbe_Aleatoire2(noeud->child[aleatoire]);
}





char* __Verbe_Aleatoire(Vb *noeud, char *str_to_return)
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
	return __Verbe_Aleatoire(noeud->child[aleatoire], str_to_return);
}



char* Verbe_Aleatoire(RVb tree, char *str_to_return)
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

	return __Verbe_Aleatoire(tree.child[ale], str_to_return);
}





int __Verbe_Present(char *mot, Vb *v)
{
	if (!v)
	{
		return -1;//EXIT_FAILURE;
	}

	//pcq il y a la root il faudra rajouter des fonctions chapeau a toutes les autres fonctions
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
			v = v->child[i - 1];
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

	return __Verbe_Present(mot, tree.child[i]);
}





int Is_Conj_Vb(Fvb *v, Fnom *n)
{
	if (!v)
	{
		return -1;
	}
	int pos = 0;
	
	while (v != NULL)
	{
		if (mystrcmp(v->nombre, n->nombre) == 1)
		{
			    //if (mystrcmp(v->nombre, n->nombre) == 1)
			return pos;
		}
		pos++;
		v = v->next; 
	}
	return -1;

}

Fvb* flechie_Vb(Fvb *f, int place)
{
	int i = 0;
	while (i < place)
	{
		f = f->next;
		i++;
	}
	return f;
}


Fvb* __Trouver_Verbe_Conj (Vb *noeud, Fnom *n, char *f_f)
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
		fdb = mystrcat(fdb, &(noeud->lettre));
		
		//si on arrive sur une fin de forme de base
		if (noeud->end)
		{
			if (noeud->nbenfant != 0)
			{
				int ale = rand() % 2;
				if (ale)
				{
		         	//aleatoire du cas general pour savoir ou on se deplace dans notre
		            //matrice d'enfant
		            int aleatoire = rand() % noeud->nbenfant;
		
		            //on se deplace sur le bon enfant
                    if (noeud->nbenfant >= aleatoire)
		                noeud = noeud->child[aleatoire];
                    else
                        break;
                                        
					continue;
				}
				else
				{
					int isconj = Is_Conj_Vb(noeud->ff, n);//retourne la place dans la forme flechie
					if (isconj >= 0) //si la bonne ff existe
					{
						Fvb *conj_match = flechie_Vb(noeud->ff , isconj); /*la bonne forme flechie*/
						// on retourne la forme flechie dans une string
                        //if (f_f != NULL)
                            //free(f_f);
						//f_f = mystrff(fdb, conj_match->ff, conj_match->diff);
                        if (!conj_match->ff || conj_match->diff == 0)
                            {
                            int k = 0;
                            while (*(fdb + k) != '\0')
                            {
                                *(f_f + k) = *(fdb + k);
                                k++;
                            }
                            *(f_f + k)= '\0';
                        
                            free(fdb);
                            return conj_match;
                        }
					    char *test = mystrff(fdb, conj_match->ff, conj_match->diff);
					    //printf("toto");
					    int j = 0;
					    while ((*(test + j) != '\0'))// && (*(test + j) >= 'a' && *(test + j) <= 'z'))
                        {
                            *(f_f + j) = *(test + j);
                            j++;
                        }
                        *(f_f + j) = '\0';
                        //printf("%s\n", f_f);*/
                        //if (f_f == NULL)
                        //f_f = test;
                        
                        free(fdb);
                        return conj_match;
					}
                    //si la forme flechie n'existe pas on continue sur un autre enfant;
				}
			}
			
			//on verifie qu'il n'y ai pas un enfant qui puisse avoir la bonne conj
			else if (noeud->nbenfant == 0)
			{
			    int isconj = Is_Conj_Vb(noeud->ff, n);//retourne la place dans la forme flechie
				if (isconj >= 0) //si la bonne ff existe
				{
					Fvb *conj_match = flechie_Vb(noeud->ff , isconj); /*la bonne forme flechie*/
					// on retourne la forme flechie dans une string
                    //if (f_f != NULL)
                        //free(f_f);
                    if (!conj_match->ff || conj_match->diff == 0)
                    {
                        int k = 0;
                        while (*(fdb + k) != '\0')
                        {
                            *(f_f + k) = *(fdb + k);
                            k++;
                        }
                        *(f_f + k)= '\0';
                        
                        free(fdb);
                        return conj_match;
                    }
					char *test = mystrff(fdb, conj_match->ff, conj_match->diff);
					//printf("toto");
					int j = 0;
					while ((*(test + j) != '\0'))// && (*(test + j) >= 'a' && *(test + j) <= 'z'))
                    {
                        *(f_f + j) = *(test + j);
                        j++;
                    }
                    *(f_f + j) = '\0';
                    //printf("%s\n", f_f);*/
                    //if (f_f == NULL)
                        //f_f = test;
                    free(fdb);
                    //free(test);
                    return conj_match;
				}
			    
                //permet de remettre l'espace allouer car on doit refaire un parcours
			    if (fdb != NULL)
			        free(fdb);
			    return NULL;				
			}
			//si un enfant peux avoir la bonne conj
			else
				continue;
		}
        
     	//aleatoire du cas general pour savoir ou on se deplace dans notre
		//matrice d'enfant
		int aleatoire = rand() % noeud->nbenfant;
		
		//on se deplace sur le bon enfant
        if (noeud->nbenfant >= aleatoire)
		    noeud = noeud->child[aleatoire];
        else
            break;
	}
    //permet de remettre l'espace allouer car on doit refaire un parcours
	if(fdb != NULL)
	    free(fdb);
	return NULL;
}

Fvb* Trouver_Verbe_Conj(RVb tree, Fnom *n, char *f_f)
{
	if (!n)
	{
		return NULL;//EXIT_FAILURE;
	}

	Fvb *result = NULL;
	int aleatoire = rand() % tree.nbenfant;

	while (!(result = __Trouver_Verbe_Conj(tree.child[aleatoire], n, f_f)))//pour le flex
	{
		aleatoire = rand() % tree.nbenfant;
        //free(f_f);
        //f_f = malloc(45 * sizeof(char));

	}

	return result;
}


/*
===============================================================================
						FIN FONCTION VERBE
===============================================================================
*/
