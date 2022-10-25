//
// Created by debor on 17/10/2022.
//

#include "dico_node.h"
#include <stdio.h>
#include <stdlib.h>




void lire_mot_fichier(char *s)
{
    poly p;


    FILE *file;
    file = fopen(s, "r");

    if (!file)
        exit(EXIT_FAILURE);
    int c = fgetc(file);
    p.nb_monome = c - 48;
    p.tab_monomes = malloc (p.nb_monome * sizeof (monome));
    if(!p.tab_monomes)
        exit(EXIT_FAILURE);

    double number = 0;
    int signe = 1;
    int i = 0;
    double compteur = 1;
    int coeff = 1;
    int position = 0;

    while (1){
        c = fgetc(file);

        if (c == ' ' || c == EOF)
        {
            number *= signe;
            //printf("%.1lf\n", number);
            if (coeff == 1)
            {
                (p.tab_monomes + position)->coefficient = number;
                coeff = 0;
            }
            else
            {
                (p.tab_monomes + position)->exposant = (int)number;
                coeff = 1;
                position ++;
            }

            if (c == EOF)
                break;
            signe = 1;
            compteur = 1;
            number = 0;
            i = 0;
        }
        else if (c != '\n')
        {
            if (c == '-')
            {
                signe = -1;
            }
            if (c == '.')
            {
                i = 1;
            }
            if (c != '.' && i == 1)
            {
                double toto = (c - '0') / (10 * compteur);
                compteur++;
                number += toto;
            }
            else
            {
                if (c != '.' && c !='-')
                {
                    number *= 10;
                    number += c - '0';
                }
            }
        }
    }
    p.degree_max = (p.tab_monomes + p.nb_monome-1)->exposant;
    fclose(file);
    return p;
}
