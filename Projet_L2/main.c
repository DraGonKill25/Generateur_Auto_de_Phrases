#include "dico.h"
#include "dico_tree.h"
#include "../test_fonctions/helper.h"
#include "../test_fonctions/vb.h"

int main() {
    RVb vb;
    RNom nom;
    RAdj adj;
    RAdv adv;

    vb.nbenfant = 0;
    vb.child = NULL;

    nom.nbenfant = 0;
    nom.child = NULL;

    adj.nbenfant = 0;
    adj.child = NULL;

    adv.nbenfant = 0;
    adv.child = NULL;

    //creation des arbres a partir du dico en txt
    dico_read("../Projet_L2/TreeExample/dico_test.txt", &vb, &nom, &adj, &adv);
    char *toreturn = Verbe_Aleatoire(vb,toreturn);

    printf("\n%s", toreturn);
    return 0;
}
