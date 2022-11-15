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

    int choix = 0;
    printf("Bonjour, bienvenue sur notre generateur automatique de phrases\n");
    printf("Vous pourrez choisir entre la generation ou la recherche de mot\n");
    printf("dans le dictionnaire.\n");

    while(choix != 3) {
        printf("Choix 1 : generation\nChoix 2 : recherche\nChoix 3 : quitter le menu\nChoix :");
        scanf("%d", &choix);
        printf("\n");

        switch (choix) {
            case 1: {
                printf("phrase 1: ");
                __Nom_Aleatoire2(nom.child[rand() % nom.nbenfant]);
                printf(" ");
                __Adj_Aleatoire2(adj.child[rand() % adj.nbenfant]);
                printf(" ");
                __Verbe_Aleatoire2(vb.child[rand() % vb.nbenfant]);
                printf(" ");
                __Nom_Aleatoire2(nom.child[rand() % nom.nbenfant]);
                printf(" ");
                printf("\n\n");


                printf("phrase 2: ");
                __Nom_Aleatoire2(nom.child[rand() % nom.nbenfant]);
                printf(" qui ");
                __Verbe_Aleatoire2(vb.child[rand() % vb.nbenfant]);
                printf(" ");
                __Verbe_Aleatoire2(vb.child[rand() % vb.nbenfant]);
                printf(" ");
                __Nom_Aleatoire2(nom.child[rand() % nom.nbenfant]);
                printf(" ");
                __Adj_Aleatoire2(adj.child[rand() % adj.nbenfant]);
                printf("\n\n");
                break;
            }

            case 2: {
                char *no = "lait";
                int nompresent = Nom_Present(no, nom);
                printf("le nom %s est-il dans le dico ? %d\n", no, nompresent);

                char *no2 = "trotro";
                int nompresent2 = Nom_Present(no2, nom);
                printf("le nom %s est-il dans le dico ? %d\n", no2, nompresent2);


                char *ver1 = "déplacer";
                int vbpresent1 = Verbe_Present(ver1, vb);
                printf("le verbe %s est-il dans le dico ? %d\n", ver1, vbpresent1);

                char *ver = "abraquadabraquant";
                int vbpresent = Verbe_Present(ver, vb);
                printf("le verbe %s est-il dans le dico ? %d\n", ver, vbpresent);

                char *adjectif = "fort";
                int adjpresent = Adj_Present(adjectif, adj);
                printf("le adjectif %s est-il dans le dico ? %d\n", adjectif, adjpresent);

                char *adverbe = "lamentablement";
                int advpresent = Adv_Present(adverbe, adv);
                printf("le adverbe %s est-il dans le dico? %d\n", adverbe, advpresent);
                break;
            }

            case 3:
            {
                break;
            }
        }

    }






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
