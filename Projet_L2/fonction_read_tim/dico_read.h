//
// Created by TIM on 01/11/2022.
//

#ifndef GENERATEUR_AUTO_DE_PHRASES_DICO_READ_H
#define GENERATEUR_AUTO_DE_PHRASES_DICO_READ_H



/*
=====================================================================================
                            Structure for ADV
=====================================================================================
*/
//pour stocker le nombre de forme de base
typedef struct ADV
{
    char *lettre;
    int nbenfant;     //nombre d'enfant donc de lettre suivante
    int end;            // est == 1 quand fin de forme de base
    struct ADV *child[]; //toutes les enfants donc lettre suivant
}Adv;




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
    char *lettre;
    int nbenfant;     //nombre d'enfant donc de lettre suivante
    int nbflechie;      // !=0 quand end == 1
    int end;            // est == 1 quand fin de forme de base
    struct FF_ADJ *ff;   // si end==1 alors *ff != NULL
    struct ADJ *child[]; //toutes les enfants donc lettre suivant
}Adj;




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
    char *lettre;
    int nbenfant;     //nombre d'enfant donc de lettre suivante
    int nbflechit;      // !=0 quand end == 1
    int end;            // est == 1 quand fin de forme de base
    struct FF_NOM *ff;   // si end==1 alors *ff != NULL
    struct NOM *child[]; //toutes les enfants donc lettre suivant
}Nom;





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
    char *lettre;
    int nbenfant;     //nombre d'enfant donc de lettre suivante
    int nbflechit;      // !=0 quand end == 1
    int end;            // est == 1 quand fin de forme de base
    struct FF_VB *ff;   // si end==1 alors *ff != NULL
    struct VB *child[]; //toutes les enfants donc lettre suivant
}Vb;



/*
===============================================================================
                        STRUCTURE POUR L'ABRE
Cette arbre contient les quatres structure pour les verbes, adj, adv et nom
===============================================================================
*/

/*
//Probleme de compilation avec les tableaux dyn, struct à revoir
typedef struct TREE
{
    int test;
    struct VB *verbes[];
    struct ADJ *adjectifs[];
    struct ADV *adverbes[];
    struct NOM *noms[];
}Tree;

 */


#endif //GENERATEUR_AUTO_DE_PHRASES_DICO_READ_H
