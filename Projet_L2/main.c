#include <time.h>
#include "./Lecture_fichier/lecture_fichier.h"
#include "./Fonctionnalites/vb.h"
#include "./Fonctionnalites/nom.h"
#include "./Fonctionnalites/adj.h"
#include "./Fonctionnalites/adv.h"

int main() {

    //Initialisation de srand que servira pour les appels de numéros aléatoires
    srand((unsigned)time(NULL));


    //Initialisation des roots de nos arbres
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

    //Initialisation des variables pour les differents switches
    int choix = 0;
    int choix1 = 0;
    int choix2 = 0;
    int choix3 = 0;
    int choix4 = 0;
    char *res;
    printf("Bonjour, bienvenue sur notre generateur automatique de phrases\n");
    printf("Vous pourrez choisir entre la generation de phrases aleatoires\n");
    printf("ou la recherche de mots dans le dictionnaire.\n\n");

    //utilisations de boucles pour generer le menu tant que la saisie n est pas correcte
    while(choix != 3) {
        printf("- 1 : Generation de phrases\n- 2 : Recherche de mots\n");
        printf("- 3 : Quitter le programme\nVotre choix : ");
        scanf("%d", &choix);
        printf("\n");

        //utilisation de switchs pour permettre de traiter les differents cas demandes dans le projet
        switch (choix) {
            case 1: {

                //la reflexion precedente est repetee tant que plusieurs choix s'offrent a nous
                while (choix1 != 3) {
                    printf("Dans ce module vous pourrez choisir parmi les differents modeles\n");
                    printf("de generation de phrases proposes.\n\n");
                    printf("- 1 : Generation avec des formes de base\n- 2 : Generation de phrases conjugees\n");
                    printf("- 3 : Revenir au menu\nVotre choix : ");
                    scanf("%d", &choix1);
                    switch (choix1) {
                        case 1 : {
                            while (choix3 != 4) {
                                printf("Il vous est propose trois modeles de generation differents\n");
                                printf("Le troisieme etant notre creation personnelle\n\n");
                                printf("- 1 : Modele 1\n- 2 : Modele 2\n- 3 : Modele 3\n- 4 : Revenir a la Generation\n");
                                printf("Votre choix : ");
                                scanf("%d", &choix3);
                                switch (choix3) {
                                    case 1 : {

                                        /** Appel des fonctions de generation aleatoire avec la fonction rand() modulo le nombre d'enfants
                                         * il suffit de faire les appels de nom, adjectif, verbe et adverbes pour que la phrase soit directement
                                         * générée
                                         */

                                        printf("\nModele 1: ");
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
                                        printf("\nModele 2: ");
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
                                        printf("\nModele 3: ");
                                        __Nom_Aleatoire2(nom.child[rand() % nom.nbenfant]);
                                        printf(" qui ");
                                        __Verbe_Aleatoire2(vb.child[rand() % vb.nbenfant]);
                                        printf(" ");
                                        __Adv_Aleatoire2(adv.child[rand() % adv.nbenfant]);
                                        printf(" ");
                                        __Verbe_Aleatoire2(vb.child[rand() % vb.nbenfant]);
                                        printf(" ");
                                        printf("aussi ");
                                        __Nom_Aleatoire2(nom.child[rand() % nom.nbenfant]);
                                        printf("\n\n");

                                        break;
                                    }
                                    case 4 : {
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                        case 2 : {

                            while (choix4 != 4) {
                                printf("Il vous est propose trois modeles de generation differents\n");
                                printf("Ici vous pourrez choisir de conjuger une phrase generee aleatoirement\n\n");
                                //printf("Vous pourrez choisir entre differentes conjugaisons proposees\n");
                                printf("- 1 : Modele 1 conjuge\n- 2 : Modele 2 conjuge\n- 3 : Modele 3 conjuge\n- 4 : Revenir a la Generation\n");
                                //printf("- 5 : Choix de la personne pour la phrase conjugee\n");
                                printf("Votre choix : ");
                                scanf("%d", &choix4);
                                    switch (choix4) {
                                        //appels des fonctions pour les formes conjugees
                                        case 1 : {
                                            printf("Modele 1 : ");
                                            break;
                                        }

                                        case 2 : {
                                            printf("Modele 2 : ");
                                            break;
                                        }

                                        case 3 : {
                                            printf("Modele 3 : ");
                                            break;
                                        }
                                        case 4 : {
                                            break;
                                        }
                                        /*
                                        case 5 : {
                                            break;
                                        }
                                         */
                                    }
                                }
                            }
                        case 3 : {
                            break;
                        }
                    }
                }
                break;
            }


            case 2 : {
                while (choix2 != 5) {
                    printf("Dans ce module, vous pourrez verifier la presence d un mot dans le dictionnaire\n\n");
                    printf("- 1 : Recherche de nom\n- 2 : Recherche de verbe\n");
                    printf("- 3 : Recherche d'adjectif\n- 4 : Recherche d'adverbe\n");
                    printf("- 5 : Revenir au menu\nVotre choix : ");
                    scanf("%d", &choix2);
                    printf("\n");

                    //Recherche de mot avec saisie, on rentre la string avec un scanf et la fonction codée nous indique
                    //avec un int si le mot saisi est présent dans le dictionnaire

                    switch (choix2) {
                        case 1: {
                            char no[50];
                            printf("Saissisez votre nom :");
                            scanf("%s", no);
                            int nompresent = Nom_Present(no, nom);
                            if (nompresent == 1)
                                res = "Oui";
                            else
                                res = "Non";
                            printf("\nLe nom %s est-il dans le dictionnaire ? %s\n", no, res);
                            break;
                        }

                        case 2: {
                            char ver[50];
                            printf("Saissisez votre verbe :");
                            scanf("%s", ver);
                            int vbpresent = Verbe_Present(ver, vb);
                            if (vbpresent == 1)
                                res = "Oui";
                            else
                                res = "Non";
                            printf("\nLe verbe %s est-il dans le dictionnaire ? %s\n", ver, res);
                            break;
                        }

                        case 3: {
                            char adjectif[50];
                            printf("Saissisez votre adjectif :");
                            scanf("%s", adjectif);
                            int adjpresent = Adj_Present(adjectif, adj);
                            if (adjpresent == 1)
                                res = "Oui";
                            else
                                res = "Non";
                            printf("\nL'adjectif %s est-il dans le dictionnaire ? %s\n", adjectif, res);
                            break;
                        }

                        case 4: {
                            char adverbe[50];
                            printf("Saissisez votre adverbe :");
                            scanf("%s", adverbe);
                            int advpresent = Adv_Present(adverbe, adv);
                            if (advpresent == 1)
                                res = "Oui";
                            else
                                res = "Non";
                            printf("\nL'adverbe %s est-il dans le dictionnaire ? %s\n", adverbe, res);
                            break;
                        }
                        case 5 : {
                            break;
                        }
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
