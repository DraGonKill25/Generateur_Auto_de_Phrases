#ifndef PROJET_L2_DICO_NODE_H
#define PROJET_L2_DICO_NODE_H




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
    struct ADV *child[]; //toutes les enfants donc lettre suivant
    int end;            // est == 1 quand fin de forme de base
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
    char *ff;           //string du du decalage entre fdb et ff 
    int diff;           //decalage entre la fdb et la ff
    char *genre;
    char *nombre;    
    FF_ADJ *next;
};

//pour stocker le nombre de forme de base
//ainsi qu'un pointeur vers la liste chainee des formes de base
typedef struct ADJ
{ 
    char *lettre;
    int nbenfant;     //nombre d'enfant donc de lettre suivante
    struct ADJ *child[]; //toutes les enfants donc lettre suivant
    int nbflechie;      // !=0 quand end == 1
    int end;            // est == 1 quand fin de forme de base
    struct FF_ADJ *ff;   // si end==1 alors *ff != NULL
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
    char *ff;           //string du du decalage entre fdb et ff 
    int diff;           //decalage entre la fdb et la ff
    char *genre;
    char *nombre;
    FF_NOM *next;
};

//pour stocker le nombre de forme de base
//ainsi qu'un pointeur vers la liste chainee des formes de base
typedef struct NOM
{  
    char *lettre;
    int nbenfant;     //nombre d'enfant donc de lettre suivante
    struct NOM *child[]; //toutes les enfants donc lettre suivant
    int nbflechit;      // !=0 quand end == 1
    int end;            // est == 1 quand fin de forme de base
    struct FF_NOM *ff;   // si end==1 alors *ff != NULL
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
    char *ff;           //string du du decalage entre fdb et ff 
    int diff;           //decalage entre la fdb et la ff
    char *personne;
    char *conjugaison;
    char *nombre;
    char *genre;
    FF_VB *next;
};

//pour stocker le nombre de forme de base
//ainsi qu'un pointeur vers la liste chainee des formes de base
typedef struct VB
{   
    char *lettre;
    int nbenfant;     //nombre d'enfant donc de lettre suivante
    struct VB *child[]; //toutes les enfants donc lettre suivant
    int nbflechit;      // !=0 quand end == 1
    int end;            // est == 1 quand fin de forme de base
    struct FF_VB *ff;   // si end==1 alors *ff != NULL
}



/*
===============================================================================
                        STRUCTURE POUR L'ABRE
Cette arbre contient les quatres structure pour les verbes, adj, adv et nom
===============================================================================
*/

typedef struct TREE
{
    VB *verbes[];
    ADJ *adjectifs[];
    ADV *adverbes[];
    NOM *noms[];
};

#endif
