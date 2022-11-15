#ifndef PROJET_L2_DICO_H
#define PROJET_L2_DICO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "dico_node.h"
#include "dico_tree.h"
#include "helper.h"
#include "../Creation_arbres/arbreVb.h"
#include "../Creation_arbres/arbreAdv.h"
#include "../Creation_arbres/arbreAdj.h"
#include "../Creation_arbres/arbreNom.h"

void dico_read(char *dico, RVb *v_tree, RNom *n_tree, RAdj *adj_tree, RAdv *adv_tree);

#endif //PROJET_L2_DICO_H
