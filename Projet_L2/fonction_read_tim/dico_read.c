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

        int cpt = 1;

        /** premiere detection de tabulation pour la forme flechie */

        forme_flechie = malloc(100);

        while (car != '\t') {

            if (car == EOF)
                break;

            car = fgetc(file);
            char c = (char) car;
            strncat(forme_flechie, &c, 1);
            cpt++;
        }

        /**reinitialisation de mes parametres pour relancer la boucle pour la forme de base */

        car = '\0';
        cpt = 1;

        /** deuxieme detection  de tabulation pour la forme de base */

        forme_de_base = malloc(100);

        while (car != '\t') {

            car = fgetc(file);
            char c = (char) car;
            strncat(forme_de_base, &c, 1);
            cpt++;

            if (car == EOF)
                break;
        }

        /** reinitialisation */

        car = '\0';
        cpt = 1;

        /** detection du retour a la ligne pour mes parametres */

        parametres = malloc(100);


        //rajouter un fgetc pour les conditions verbes/noms/adj/adv + var booleene
        while (car != '\n') {


            car = fgetc(file);
            char c = (char) car;
            strncat(parametres, &c, 1);
            cpt++;

            if (car == EOF)
                break;
        }

        /** tests */

        printf("%s\n", forme_flechie);
        //printf("\n%c\n", forme_flechie[4]);
        //fflush(stdout);
        //fflush(stdin);

        printf("%s\n", forme_de_base);
        //fflush(stdout);
        //fflush(stdin);

        printf("%s\n", parametres);
        //fflush(stdout);
        //fflush(stdin);


        /** appelle des fonctions de traitement des parametres ici*/

        //fonction pour la construction de l'arbre par caractere de la fdb

        //fonction pour stocker la ff dans un tableau avec les parametres associes

        /** liberation de la memoire allouee */

        free(forme_flechie);
        forme_flechie = NULL;

        free(forme_de_base);
        forme_de_base = NULL;

        free(parametres);
        parametres = NULL;

    }

    /** fermeture du dico */

    fclose(file);
}
