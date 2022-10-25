//
// Created by debor on 17/10/2022.
//

#include "dico_tree.h"
#include "dico_node.h"

typedef struct ROOT_VB
{
    int nbchildren;
    struct NODE_VB *children[]; //tab des adresses des enfants (max 26)
}Rvb;

typedef struct ROOT_NOM
{
    int nbchildren;
    struct NODE_NOM *children[]; //tab des adresses des enfants (max 26)
}Rnom;

typedef struct ROOT_ADJ
{
    int nbchildren;
    struct NODE_ADJ *children[]; //tab des adresses des enfants (max 26)
}Radj;
typedef struct ROOT_ADV
{
    int nbchildren;
    struct NODE_ADV *children[]; //tab des adresses des enfants (max 26)
}Radv;
