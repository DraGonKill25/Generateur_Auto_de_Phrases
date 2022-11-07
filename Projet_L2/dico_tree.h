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


typedef struct TREE
{
    struct ROOT_VB *verbes;
    struct ROOT_ADJ *adjectifs;
    struct ROOT_ADV *adverbes;
    struct ROOT_NOM *noms;
}Tree;


#endif //PROJET_L2_DICO_TREE_H
