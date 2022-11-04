//
// Created by TIM on 01/11/2022.
//

#include "dico_read.h"

//"../TreeExample/dico_10_lignes.txt"

void dico_read (char *dico)
{

    /** Ouverture du fichier dico */

    FILE *file = NULL;
    file = fopen(dico, "r");
    if (!file)
        exit(EXIT_FAILURE);


    /** initialisation de mes variables */

    int car = 0;
    char *forme_flechie = NULL;
    char *forme_de_base = NULL;
    char *parametres = NULL;

    /** boucle pour tout le parcours du fichier */

    while(car != EOF) {

        /** allocation de mes strings */

        forme_flechie = malloc(40 * sizeof(char));
        forme_de_base = malloc(40 * sizeof(char));
        parametres = malloc(100 * sizeof(char));
        char *type = malloc(30 * sizeof(char));

        /** premiere detection de tabulation pour la forme flechie */

        while (car != '\t') {

            if (car == EOF)
                break;

            car = fgetc(file);
            char c = (char) car;
            strncat(forme_flechie, &c, 1);
        }

        /**reinitialisation de mes parametres pour relancer la boucle pour la forme de base */

        car = '\0';

        /** deuxieme detection  de tabulation pour la forme de base */

        while (car != '\t') {

            car = fgetc(file);
            char c = (char) car;
            strncat(forme_de_base, &c, 1);

            if (car == EOF)
                break;
        }

        /** reinitialisation */

        car = '\0';

        /** recuperation du type Ver/Nom/Adj/Adv pour un meilleur traitement
         * et pour faciliter l appel de fonction
         */

        while(car != ':')
        {
            car = fgetc(file);
            char c = (char) car;
            strncat(type, &c, 1);
        }

        /** detection du retour a la ligne pour mes parametres */

        while (car != '\n') {

            car = fgetc(file);
            char c = (char) car;
            strncat(parametres, &c, 1);

            if (car == EOF)
                break;
        }

        /** traitement du type de mot dans le dictionnaire pour l'appel de fonction */

        char *nom = "Nom:";
        char *verbe = "Ver:";
        char *adj = "Adj:";
        char *adv = "Adv:";
        int n = strcmp(type, nom);
        int v = strcmp(type, verbe);
        int adje = strcmp(type, adj);
        int adve = strcmp(type, adv);


        if(n == 0)
        {
            /** test */

            printf("NOM\n");

            //appeller la fonction de traitement pour les noms

        }
        if(v == 0)
        {
            /** test */

            printf("VERBE\n");

            //appeller la fonction de traitement pour les verbes
        }
        if(adje == 0)
        {
            /** test */

            printf("ADJECTIF\n");

            //appeller la fonction de traitement pour les adjectifs
        }
        if(adve == 0)
        {
            /** test */

            printf("ADVERBE\n");

            //appeller la fonction de traitement pour les adverbes
        }

        /** tests strings */

        printf("%s\n", forme_flechie);
        printf("%s\n", forme_de_base);
        printf("%s\n", parametres);


        //printf("\n%c\n", forme_flechie[4]);
        //printf("\n%s\n", type);
        //fflush(stdout);
        //fflush(stdin);

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
