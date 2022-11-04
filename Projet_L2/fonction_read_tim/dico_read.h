//
// Created by TIM on 01/11/2022.
//

#ifndef TEST_READ_TIM_DICO_READ_H
#define TEST_READ_TIM_DICO_READ_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


/*
=====================================================================================
                            Structure for ADV
=====================================================================================
*/
//pour stocker le nombre de forme de base
typedef struct ADV
{
    char lettre;
    int nbenfant;     //nombre d'enfant donc de lettre suivante
    int end;            // est == 1 quand fin de forme de base
    struct ADV **child; //toutes les enfants donc lettre suivant
}Adv;

typedef struct ROOT_ADV{
    int nbenfant;
    struct ADV **child;
}RAdv;



/*
=====================================================================================
                            Structure for ADJ
=====================================================================================
*/
//pour stocker les formes flechits dans une liste chainee
//ainsi que les parametres de cette forme
typedef struct FF_ADJ
{
    char *ff;           //string du du decalage entre fdb et ff
    int diff;           //decalage entre la fdb et la ff
    char *genre;
    char *nombre;
    struct FF_ADJ *next;
}Fadj;

//pour stocker le nombre de forme de base
//ainsi qu'un pointeur vers la liste chainee des formes de base
typedef struct ADJ
{
    char lettre;
    int nbenfant;     //nombre d'enfant donc de lettre suivante
    int nbflechie;      // !=0 quand end == 1
    int end;            // est == 1 quand fin de forme de base
    struct FF_ADJ *ff;   // si end==1 alors *ff != NULL
    struct ADJ **child; //toutes les enfants donc lettre suivant
}Adj;

typedef struct ROOT_ADJ{
    int nbenfant;
    struct ADJ **child;
}RAdj;



/*
=====================================================================================
                            Structure for NOM
=====================================================================================
*/
//pour stocker les formes flechits dans une liste chainee
//ainsi que les parametres de cette forme
typedef struct FF_NOM
{
    char *ff;           //string du du decalage entre fdb et ff
    int diff;           //decalage entre la fdb et la ff
    char *genre;
    char *nombre;
    struct FF_NOM *next;
}Fnom;

//pour stocker le nombre de forme de base
//ainsi qu'un pointeur vers la liste chainee des formes de base
typedef struct NOM
{
    char lettre;
    int nbenfant;     //nombre d'enfant donc de lettre suivante
    int nbflechit;      // !=0 quand end == 1
    int end;            // est == 1 quand fin de forme de base
    struct FF_NOM *ff;   // si end==1 alors *ff != NULL
    struct NOM **child; //toutes les enfants donc lettre suivant
}Nom;

typedef struct ROOT_NOM{
    int nbenfant;
    struct NOM **child;
}RNom;




/*
===============================================================================
                        STRUCTURE POUR LES VERBES
===============================================================================
*/
//pour stocker les formes flechits dans une liste chainee
//ainsi que les parametres de cette forme
typedef struct FF_VB
{
    char *ff;           //string du du decalage entre fdb et ff
    int diff;           //decalage entre la fdb et la ff
    char *personne;
    char *conjugaison;
    char *nombre;
    char *genre;
    struct FF_VB *next;
}Fvb;

//pour stocker le nombre de forme de base
//ainsi qu'un pointeur vers la liste chainee des formes de base
typedef struct VB
{
    char lettre;
    int nbenfant;     //nombre d'enfant donc de lettre suivante
    int nbflechit;      // !=0 quand end == 1
    int end;            // est == 1 quand fin de forme de base
    struct FF_VB *ff;   // si end==1 alors *ff != NULL
    struct VB **child; //toutes les enfants donc lettre suivant
}Vb;

typedef struct ROOT_VB{
    int nbenfant;
    struct VB **child;
}RVb;

/*
===============================================================================
                        STRUCTURE POUR L'ABRE
Cette arbre contient les quatres structure pour les verbes, adj, adv et nom
===============================================================================
*/


//Probleme de compilation avec les tableaux dyn, struct à revoir
typedef struct TREE
{
    struct VB **verbes;
    struct ADJ **adjectifs;
    struct ADV **adverbes;
    struct NOM **noms;
}Tree;

void dico_read(char *dico);

#endif //TEST_READ_TIM_DICO_READ_H
