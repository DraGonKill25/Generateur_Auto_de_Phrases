//
// Created by debor on 17/10/2022.
//

#ifndef PROJET_L2_DICO_TREE_H
#define PROJET_L2_DICO_TREE_H

#include "dico_node.h"

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


#endif //PROJET_L2_DICO_TREE_H
