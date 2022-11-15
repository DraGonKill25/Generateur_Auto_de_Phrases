#include "dico.h"
#include "../test_fonctions/vb.h"
#include "../test_fonctions/nom.h"
#include "../test_fonctions/adj.h"
#include "../test_fonctions/adv.h"
#include "stdio.h"
#include "stdlib.h"


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
    int choix1 = 0;
    int choix2 = 0;
    char *res;
    printf("Bonjour, bienvenue sur notre generateur automatique de phrases\n");
    printf("Vous pourrez choisir entre la generation ou la recherche de mot\n");
    printf("dans le dictionnaire.\n");

    while(choix != 3) {
        printf("Choix 1 : generation\nChoix 2 : recherche\nChoix 3 : quitter le menu\nChoix :");
        scanf("%d", &choix);
        printf("\n");

        switch (choix) {
            case 1: {
                printf("Dans ce module vous pouvez choisir parmi les differents modeles\n");
                printf("de generation de phrase proposes\n");
                printf("Choix 1 : modele 1\nChoix 2 : modele 2\nChoix 3 : modele 3\nChoix : ");
                scanf("%d", &choix1);
                switch(choix1) {
                    case 1 : {
                        printf("\nphrase 1: ");
                        __Nom_Aleatoire2(nom.child[rand() % nom.nbenfant]);
                        printf(" ");
                        __Adj_Aleatoire2(adj.child[rand() % adj.nbenfant]);
                        printf(" ");
                        __Verbe_Aleatoire2(vb.child[rand() % vb.nbenfant]);
                        printf(" ");
                        __Nom_Aleatoire2(nom.child[rand() % nom.nbenfant]);
                        printf(" ");
                        printf("\n\n");
                        break;
                    }

                    case 2 : {
                        printf("\nphrase 2: ");
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

                    case 3 : {
                        printf("\nphrase 3: ");
                        __Nom_Aleatoire2(nom.child[rand() % nom.nbenfant]);
                        printf(" qui ");
                        __Verbe_Aleatoire2(vb.child[rand() % vb.nbenfant]);
                        printf(" ");
                        __Verbe_Aleatoire2(vb.child[rand() % vb.nbenfant]);
                        printf(" ");
                        __Nom_Aleatoire2(nom.child[rand() % nom.nbenfant]);
                        printf(" ");
                        __Adj_Aleatoire2(adj.child[rand() % adj.nbenfant]);
                        printf(" ");
                        __Adv_Aleatoire2(adv.child[rand() % adv.nbenfant]);
                        printf("\n\n");
                        break;
                    }
                }
                break;
            }

            case 2: {
                printf("Dans ce module, vous pourrez rechercher un mot dans le dictionnaire\n");
                printf("Il sera possible d'afficher ses parametres\n");
                printf("Choix 1 : Recherche de nom\nChoix 2 : Recherche de verbe\n");
                printf("Choix 3 : Recherche d'adjectif\nChoix 4 : Recherche d'adverbe\nChoix : ");
                scanf("%d", &choix2);
                printf("\n");
                switch(choix2)
                {
                    case 1: {
                        char no[50];
                        printf("Saissisez votre nom :");
                        scanf("%s", no);
                        int nompresent = Nom_Present(no, nom);
                        if(nompresent == 1)
                            res = "Oui";
                        else
                            res = "Non";
                        printf("\nLe nom %s est-il dans le dico ? %s\n", no, res);
                        break;
                    }

                    case 2: {
                        char ver[50];
                        printf("Saissisez votre verbe :");
                        scanf("%s", ver);
                        int vbpresent = Verbe_Present(ver, vb);
                        if(vbpresent == 1)
                            res = "Oui";
                        else
                            res = "Non";
                        printf("\nLe verbe %s est-il dans le dico ? %s\n", ver, res);
                        break;
                    }

                    case 3: {
                        char adjectif[50];
                        printf("Saissisez votre adjectif :");
                        scanf("%s", adjectif);
                        int adjpresent = Adj_Present(adjectif, adj);
                        if(adjpresent == 1)
                            res = "Oui";
                        else
                            res = "Non";
                        printf("\nL'adjectif %s est-il dans le dico ? %s\n", adjectif, res);
                        break;
                    }

                    case 4: {
                        char adverbe[50];
                        printf("Saissisez votre adverbe :");
                        scanf("%s", adverbe);
                        int advpresent = Adv_Present(adverbe, adv);
                        if(advpresent == 1)
                            res = "Oui";
                        else
                            res = "Non";
                        printf("\nL'adverbe %s est-il dans le dico? %s\n", adverbe, res);
                        break;
                    }



                }
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
