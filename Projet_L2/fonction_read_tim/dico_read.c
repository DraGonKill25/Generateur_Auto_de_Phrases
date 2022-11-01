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
    char *forme_flechie = NULL;;
    char *forme_de_base = NULL;
    char *parametres = NULL;
    int cpt = 1;

    /** boucle pour tout le parcours du fichier */

    while(car != EOF) {

        /** premiere detection de tabulation pour la forme flechie */

        while (car != '\t') {

            car = fgetc(file);
            char c = (char) car;
            forme_flechie = realloc(forme_flechie, cpt * sizeof(char));
            strncat(forme_flechie, &c, 1);
            cpt++;

            if (car == EOF)
                break;
        }

        /**reinitialisation de mes parametres pour relancer la boucle pour la forme de base */

        car = '\0';

        cpt = 1;

        /** deuxieme detection  de tabulation pour la forme de base */

        while (car != '\t') {

            car = fgetc(file);
            char c = (char) car;
            forme_de_base = realloc(forme_de_base, cpt * sizeof(char));
            strncat(forme_de_base, &c, 1);
            cpt++;

            if (car == EOF)
                break;
        }

        /** reinitialisation */

        car = '\0';

        cpt = 1;

        /** detection du retour a la ligne pour mes parametres */

        while (car != '\n') {

            car = fgetc(file);
            char c = (char) car;
            parametres = realloc(parametres, cpt * sizeof(char));
            strncat(parametres, &c, 1);
            cpt++;

            if (car == EOF)
                break;
        }


        /** tests */

        printf("\n%s\n", forme_flechie);

        printf("\n%s\n", forme_de_base);

        printf("\n%s", parametres);



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
        cpt = 1;

    }

    /** fermeture du dico */

    fclose(file);
}
