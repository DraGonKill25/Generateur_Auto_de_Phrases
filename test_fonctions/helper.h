#ifndef PROJET_L2_DICO_NODE_H
#define PROJET_L2_DICO_NODE_H




/*
=====================================================================================
                            Structure for ADV
=====================================================================================
*/
//pour stocker les formes de base dans une liste chainee
typedef struct NODE_ADV
{
    char *mot;
    NODE_ADJ *next;
}

//pour stocker le nombre de forme de base
//ainsi qu'un pointeur vers la liste chainee des formes de base
typedef struct ADV
{
    int nb_fdb;
    NODE_ADJ *base;
}




/*
=====================================================================================
                            Structure for ADJ
=====================================================================================
*/
//pour stocker les formes flechits dans une liste chainee
//ainsi que les parametres de cette forme
typedef struct FF_ADJ
{
    char *ff;
    int diff;
    char *genre;
    char *nombre;    
    FF_ADJ *next;
};

//pour stocker les formes de base dans une liste chainee
//avec un pointeur vers les formes flechits ainsi que leur nombre
typedef struct NODE_ADJ
{
    char *mot;
    int nb_flechie;
    FF_ADJ *ff;
    NODE_ADJ *next;
}

//pour stocker le nombre de forme de base
//ainsi qu'un pointeur vers la liste chainee des formes de base
typedef struct ADJ
{
    int nb_fdb;
    NODE_ADJ *base;
}




/*
=====================================================================================
                            Structure for NOM
=====================================================================================
*/
//pour stocker les formes flechits dans une liste chainee
//ainsi que les parametres de cette forme
typedef struct FF_NOM
{
    char *ff;
    int diff;
    char *genre;
    char *nombre;
    FF_ADJ *next;
};

//pour stocker les formes de base dans une liste chainee
//avec un pointeur vers les formes flechits ainsi que leur nombre
typedef struct NODE_NOM
{
    char *mot;
    int nb_flechie;
    FF_ADJ *ff;
    NODE_ADJ *next;
}

//pour stocker le nombre de forme de base
//ainsi qu'un pointeur vers la liste chainee des formes de base
typedef struct NOM
{
    int nb_fdb;
    NODE_ADJ *base;
}




/*
===============================================================================
                        STRUCTURE POUR LES VERBES
===============================================================================
*/
//pour stocker les formes flechits dans une liste chainee
//ainsi que les parametres de cette forme
typedef struct FF_VB
{
    char *ff;
    int diff;
    char *personne;
    char *conjugaison;
    char *nombre;
    char *genre;
    FF_ADJ *next;
};

//pour stocker les formes de base dans une liste chainee
//avec un pointeur vers les formes flechits ainsi que leur nombre
typedef struct NODE_VB
{
    char *mot;
    int nb_flechie;
    FF_ADJ *ff;
    NODE_ADJ *next;
}

//pour stocker le nombre de forme de base
//ainsi qu'un pointeur vers la liste chainee des formes de base
typedef struct VB
{
    int nb_fdb;
    NODE_ADJ *base;
}




/*
===============================================================================
                        STRUCTURE POUR L'ABRE
Cette arbre contient les quatres structure pour les verbes, adj, adv et nom
===============================================================================
*/

typedef struct TREE
{
    VB *verbes;
    ADJ *adjectifs;
    ADV *adverbes;
    NOM *noms;
};

#endif
