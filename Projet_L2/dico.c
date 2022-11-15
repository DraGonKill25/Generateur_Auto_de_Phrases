#include "dico.h"

void dico_read (char *dico, RVb *v_tree, RNom *n_tree, RAdj *adj_tree, RAdv *adv_tree)
{


    /** Ouverture du fichier dico */

    FILE *file = NULL;
    file = fopen(dico, "r");
    if (!file) {
        printf("error");
        exit(EXIT_FAILURE);
    }

    /** initialisation de mes variables */

    int car = fgetc(file);
    int temp;
    char *forme_flechie = NULL;
    char *forme_de_base = NULL;
    char *parametres = NULL;
    char * type = NULL;

    /** boucle pour tout le parcours du fichier */

    while(car != EOF) {

        // allocation de mes strings
        forme_flechie = (char *) malloc(60 * sizeof(char *));
        forme_de_base = (char *) malloc(60 * sizeof(char *));
        parametres = (char *) malloc(80 * sizeof(char ));
        type = (char *) malloc(40 * sizeof(char));
        temp = 0;
        // premiere detection de tabulation pour la forme flechie


        while (1) {

            if (car == EOF)
                break;
            if(car == 32)
                break;
            if(car == '\t')
                break;

            char c = (char) car;
            forme_flechie = mystrcat(forme_flechie, &c);
            car = fgetc(file);
        }

        //deuxieme detection de tabulation pour la forme de base

        while (1) {

            car = fgetc(file);

            if (car == EOF)
                break;
            if(car == 32)
                break;
            if(car == '\t')
                break;
            char c = (char) car;
            strncat(forme_de_base, &c, 1);
        }

        // recuperation du type Ver/Nom/Adj/Adv pour un meilleur traitement
        // et pour faciliter l appel de fonction

        while(1) {

            car = fgetc(file);

            if (car == EOF)
                break;
            if (car == 32)
                break;
            if (car == '\n' || car == '\r') {
                break;
            }
            if (car == ':'){
                car = fgetc(file);
                break;
            }
            char c = (char) car;
            strncat(type, &c, 1);

        }

        while(1) {
            if(car == '\r')
            {
                car = fgetc(file);
            }
            if(car == '\n') {
                temp = 1;
                car = fgetc(file);
            }
            if(car == '\t')
                car = fgetc(file);
            if (car == EOF)
                break;
            else
                break;

        }
        // detection du retour a la ligne pour mes parametres

        while (1) {
            if(temp == 1)
                break;
            if (car == EOF)
                break;
            if (car == 32)
                break;
            if (car == '\n' || car == '\r') {
                break;
            }
            char c = (char) car;
            strncat(parametres, &c, 1);
            car = fgetc(file);
        }

        while(1) {
            if(car == '\r')
            {
                car = fgetc(file);
            }
            else if(car == '\n')
                car = fgetc(file);
            else if (car == EOF)
                break;
            else
                break;

        }

        // traitement du type de mot dans le dictionnaire pour l'appel de fonction

        char *nom = "Nom";
        char *verbe = "Ver";
        char *adj = "Adj";
        char *adv = "Adv";
        int n = strcmp(type, nom);
        int v = strcmp(type, verbe);
        int adje = strcmp(type, adj);
        int adve = strcmp(type, adv);

        if(n == 0)
        {
            // test

            //printf("NOM\n");

            //appeller la fonction de traitement pour les noms
            insertTreeNom(n_tree, forme_flechie, forme_de_base, parametres);
        }

        if(v == 0)
        {
            //printf("VERBE\n");
            insertTreeVb(v_tree, forme_flechie, forme_de_base, parametres);
        }

        if(adje == 0)
        {
            // test

            //printf("ADJECTIF\n");

            //appeller la fonction de traitement pour les adjectifs
            //insertTreeAdj(adj_tree, forme_flechie, forme_de_base, parametres);
        }

        if(adve == 0)
        {
            //test

            //printf("ADVERBE\n");

            //appeller la fonction de traitement pour les adverbes
            //insertTreeAdv(adv_tree, forme_de_base, parametres);
        }

        // tests strings

        //printf("%s\n",parametres);
        /*
        printf("%s\n%s\n%s\n", forme_flechie, forme_de_base, parametres);
        fflush(stdout);
        fflush(stdin);
         */

        //printf("\n%c\n", forme_flechie[4]);
        //printf("\n%s\n", type);

        /** liberation de la memoire allouee */

        free(forme_flechie);
        forme_flechie = NULL;

        free(forme_de_base);
        forme_de_base = NULL;

        free(parametres);
        parametres = NULL;

        free(type);
        type = NULL;

    }

    /** fermeture du dico */

    fclose(file);
}
