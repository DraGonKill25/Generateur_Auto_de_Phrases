//
// Created by debor on 17/10/2022.
//

#ifndef PROJET_L2_DICO_NODE_H
#define PROJET_L2_DICO_NODE_H

typedef struct TYPE
{
    int masc;
    int fem;
    int sing;
    int plu;
    int inv;
    int base;
}Type;

typedef struct VTYPE
{
    struct TYPE type;
    int p1;
    int p2;
    int p3;
    char *temp;
    /*
    ppre; //participe
    spre; // subjonctif
    ipre; //indicatif
    cpre; //conditionnel
    iimp; //imparfait de l indicatif
    simp; //imparfait du subjonctif
    ifut; //futur
    ipsim; //passe simple
    inf; //infinitif
    ppas; //participe passe
    impre; //imperatif
    */
}Vtype;

typedef struct VERBE
{
    char lettre;
    struct VTYPE type;
    int nb_flechie; //nombre de declinaisons du verbe
    int end; //si la lettre complete un verbe
}Vb;

typedef struct NOM
{
    char lettre;
    struct TYPE type;
    int nb_flechie; //nombre de declinaisons du verbe
    int end; //si la lettre complete un verbe
}Nom;

typedef struct ADV
{
    char lettre;
    int nb_flechie; //=1 //nombre de declinaisons du verbe
    int end; //si la lettre complete un verbe
}Adv;

typedef struct ADJ
{
    char lettre;
    struct TYPE type;
    int nb_flechie; //nombre de declinaisons de l adj
    int end; //si la lettre complete un verbe
}Adj;

typedef struct NODE_VERBE
{
    struct VERBE *vb;
    int nbchildren; //nombre de lettres suivant celle on l on se trouve
    struct NODE_VERBE *children[]; //tab dyn des adresses des enfants
}Nvb;

typedef struct NODE_NOM
{
    struct NOM *nom;
    int nbchildren; //nombre de lettres suivant celle on l on se trouve
    struct NODE_NOM *children[]; //tab dyn des adresses des enfants
}Nnom;

typedef struct NODE_ADV
{
    struct ADV *adv;
    int nbchildren; //nombre de lettres suivant celle on l on se trouve
    struct NODE_ADV *children[]; //tab dyn des adresses des enfants
}Nadv;

typedef struct NODE_ADJ
{
    struct ADJ *adj;
    int nbchildren; //nombre de lettres suivant celle on l on se trouve
    struct NODE_ADJ *children[]; //tab dyn des adresses des enfants
}Nadj;


#endif //PROJET_L2_DICO_NODE_H
