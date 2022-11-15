//
// Created by natha on 03/11/2022.
//

#include "main_a.h"

int isValInTab(Vb** tab, int length, char flettre){
    if(tab == NULL){
        return -1;
    }
    int i = 0;
    for(i = 0; i < length; i++){
        if(tab[i]->lettre == flettre){
            return i;
        }
    }
    return -1;
}

void initStructVb(Vb* node){
    node->nbenfant = 0;
    node->nbflechit = 0;
    node->end = 0;
    node->ff = NULL;
    node->child = NULL;
}

Vb* newNode(char lettre){
    Vb *node = (Vb*)malloc(sizeof(Vb));
    node->lettre = lettre;
    initStructVb(node);
    return node;
}

Vb* createNode(Vb* p_node, char lettre){
    p_node->nbenfant +=1;
    p_node->child = realloc(p_node->child, p_node->nbenfant*sizeof(Vb*));
    p_node->child[p_node->nbenfant-1] = newNode(lettre);
    return p_node;
}

char* Calculer_Diff_et_ff(char *temp1, char *temp2, int *diff)
{
    int i = 0;
    int j = 0;
    int len1 = mystrlen(temp1);
    int len2 = mystrlen(temp2);
    char *toreturn;

    while (*(temp1 + i) != '\0' && *(temp2 + j) != '\0' &&*(temp1 + i) == *(temp2 + j))
    {
        i++;
        j++;
    }

    if (*(temp2 + j) == '\0')
    {
        if (*(temp1 + i) != '\0')
        {
            toreturn = malloc((len1 - i + 1) * sizeof(char));
            int k = 0;
            while(*(temp1 + i) != '\0')
            {
                *(toreturn + k) = *(temp1 + i);
                i++;
                k++;
            }
            *(toreturn + k) = '\0';
            *diff = k - 1;
            return toreturn;
        }
        else
        {
            diff = 0;
            return NULL;
        }
    }
    else
    {
        if (*(temp1 + i) != '\0')
        {
            *diff = -(len2 - j);
            toreturn = malloc((len1 - i + 1) * sizeof(char));
            int k = 0;
            while(*(temp1 + i) != '\0')
            {
                *(toreturn + k) = *(temp1 + i);
                i++;
                k++;
            }
            *(toreturn + k) = '\0';
            return toreturn;
        }

        else
        {
            *diff = -(len2 - len1);
            return NULL;
        }
    }
}

int insertCarac(Fvb *cell, char* carac, int i){
    int j=0, pass=0;

    char* per = (char*)malloc(8*sizeof(char));
    char* conj = (char*)malloc(8*sizeof(char));
    char* nomb = (char*)malloc(8*sizeof(char));
    char* genr = (char*)malloc(8*sizeof(char));

    while(carac[i] != '\0' && carac[i] != ':'){
        while(carac[i] != '+' && carac[i] != '\0'){
            conj[j] = carac[i];
            i++;
            j++;
        }
        conj[j] = '\0';
        if(carac[i] == '\0'){
            pass = 1;
            break;
        }
        i++;
        j=0;
        if(carac[i+2] == '+'){
            genr = NULL;
            while(carac[i] != '+'){
                nomb[j] = carac[i];
                i++;
                j++;
            }
            nomb[j] = '\0';
            i++;
            j=0;
            while(carac[i] != '\0' && carac[i] != ':'){
                per[j] = carac[i];
                i++;
                j++;
            }
            per[j] = '\0';
        }else{
            per = NULL;
            while(carac[i] != '+'){
                nomb[j] = carac[i];
                i++;
                j++;
            }
            nomb[j] = '\0';
            i++;
            j=0;
            while(carac[i] != '\0' && carac[i] != ':'){
                genr[j] = carac[i];
                i++;
                j++;
            }
            genr[j] = '\0';
        }
    }
    if(carac[i] != '\0'){
        i++;
    }

    if(pass == 1){
        cell->conjugaison = conj;
        cell->personne = NULL;
        cell->genre = NULL;
        cell->nombre = NULL;
    }
    else{
        cell->conjugaison = conj;
        cell->nombre = nomb;
        if(per == NULL){
            cell->genre = genr;
            cell->personne = NULL;
        }else{
            cell->personne = per;
            cell->genre = NULL;
        }
    }
    return i;
}

void addFvb(char* temp1, char* temp2, char* temp3, int i, Fvb *f){//SI f est NULL??
    if(temp3[i] == '\0'){
        return;
    }
    if(i==0){
        while(f->next != NULL){
            f = f->next;
        }
    }

    Fvb *newFvb = malloc(1*sizeof(Fvb));
    newFvb->ff = Calculer_Diff_et_ff(temp1, temp2, &(newFvb->diff));
    //Fonction pour carac
    i = insertCarac(newFvb, temp3, i);

    newFvb->next = NULL;
    f->next = newFvb;

    addFvb(temp1, temp2, temp3, i, newFvb);
}

Fvb* createFirstFvb(char* temp1, char* temp2, char* temp3){
    //creation de la premiere cellule
    Fvb *newFvb = malloc(1 * sizeof(Fvb));
    //parametre de ff ET diff
    newFvb->ff = Calculer_Diff_et_ff(temp1, temp2, &(newFvb->diff));
    int i = 0;
    /*Tout les whiles pour la gestion de newFvb->...*/
    /*maybe faire une fonction pcq ca va etre long*/
    i = insertCarac(newFvb, temp3, i);

    newFvb->next = NULL;
    //si temp3 a plus que 1 parametre
    if (*(temp3 + i) != '\0')
    {
        //appelle de la fonction general
        addFvb(temp1, temp2, temp3, i, newFvb);
    }

    //return la premiere cellule et tout les suivantes si elles exitent
    return newFvb;
}

void insertTreeVb(RVb* root, char* temp1, char* temp2, char* temp3){
    Vb* p_node = NULL;
    int i = 0, j = 0;

    int find = isValInTab(root->child, root->nbenfant, temp2[i]);

    if(find == -1){
        root->child = realloc(root->child, (root->nbenfant+1)*sizeof(Vb*));
        root->child[root->nbenfant] = newNode(temp2[i]);
        root->nbenfant++;
        p_node = root->child[root->nbenfant-1];
        i++;
        while(temp2[i] != '\0'){
            createNode(p_node, temp2[i]);
            p_node = p_node->child[p_node->nbenfant-1];
            i++;
        }
        p_node->nbflechit = 1;
        p_node->end = 1;
        p_node->ff = createFirstFvb(temp1, temp2, temp3);//cas pour augmenter nbfléchie!!
    }else{
        p_node = root->child[find];
        i++;
        find = isValInTab(p_node->child, p_node->nbenfant, temp2[i]);
        while(find != -1 && temp2[i] != '\0'){
            p_node = p_node->child[find];
            i++;
            find = isValInTab(p_node->child, p_node->nbenfant, temp2[i]);
        }
        if(temp2[i] == '\0'){//On se trouve à la fin
            //fonction pour ajouter dans la llc
            if(p_node->end){
                addFvb(temp1, temp2, temp3, j, p_node->ff);
            }
            else{
                p_node->nbflechit += 1;
                p_node->end = 1;
                p_node->ff = createFirstFvb(temp1, temp2, temp3);
            }

        }else{//On se trouve dans un noeud (pas à la fin)
            while(temp2[i] != '\0'){
                createNode(p_node, temp2[i]);
                p_node = p_node->child[p_node->nbenfant-1];
                i++;
            }
            p_node->nbflechit += 1;
            p_node->end = 1;
            p_node->ff = createFirstFvb(temp1, temp2, temp3);
        }
    }
}