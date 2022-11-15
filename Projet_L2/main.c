#include "dico.h"
#include "../test_fonctions/vb.h"
#include "../test_fonctions/nom.h"
#include "../test_fonctions/adj.h"
#include "../test_fonctions/adv.h"


int main() {

    srand((unsigned )time(NULL));

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
    dico_read("../Projet_L2/TreeExample/dictionnaire.txt", &vb, &nom, &adj, &adv);
    __Nom_Aleatoire2(nom.child[rand() % nom.nbenfant]);
    printf(" ");
    __Adj_Aleatoire2(adj.child[rand() % adj.nbenfant]);
    printf(" ");
    __Verbe_Aleatoire2(vb.child[rand() % vb.nbenfant]);
    printf(" ");
    __Nom_Aleatoire2(nom.child[rand() % nom.nbenfant]);
    printf(" ");
    printf("\n\n");

    __Nom_Aleatoire2(nom.child[rand() % nom.nbenfant]);
    printf(" qui ");
    __Verbe_Aleatoire2(vb.child[rand() % vb.nbenfant]);
    printf(" ");
    __Verbe_Aleatoire2(vb.child[rand() % vb.nbenfant]);
    printf(" ");
    __Nom_Aleatoire2(nom.child[rand() % nom.nbenfant]);
    printf(" ");
    __Adj_Aleatoire2(adj.child[rand() % adj.nbenfant]);
    printf("\n");

    /*char *toreturn2 = Nom_Aleatoire(nom, toreturn2);
    char * toreturn3 = malloc(20 * sizeof(char));
    toreturn3 = Adj_Aleatoire(adj, toreturn3);
    char * toreturn4 = Adv_Aleatoire(adv, toreturn4);

    printf("%s\n", toreturn);
    printf("%s\n", toreturn2);
    printf("%s\n", toreturn3);
    printf("%s\n", toreturn4);*/
    return 0;
}
