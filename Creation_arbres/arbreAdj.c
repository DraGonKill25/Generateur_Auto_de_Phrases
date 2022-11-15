#include "arbreAdj.h"

int isValInTabAdj(Adj** tab, int length, char flettre){
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

void initStructAdj(Adj* node){
    node->nbenfant = 0;
    node->nbflechit = 0;
    node->end = 0;
    node->ff = NULL;
    node->child = NULL;
}

Adj* newNodeAdj(char lettre){
    Adj *node = (Adj*)malloc(sizeof(Adj));
    node->lettre = lettre;
    initStructAdj(node);
    return node;
}

Adj* createNodeAdj(Adj* p_node, char lettre){
    p_node->nbenfant +=1;
    p_node->child = realloc(p_node->child, p_node->nbenfant*sizeof(Adj*));
    p_node->child[p_node->nbenfant-1] = newNodeAdj(lettre);
    return p_node;
}

char* Calculer_Diff_et_ffAdj(char *temp1, char *temp2, int *diff)
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

int insertCaracAdj(Fadj *cell, char* carac, int i){
    int j=0;

    char* nomb = (char*)malloc(8*sizeof(char));
    char* genr = (char*)malloc(8*sizeof(char));


    while(carac[i] != '+'){
        genr[j] = carac[i];
        i++;
        j++;
    }
    genr[j] = '\0';
    i++;
    j=0;

    while(carac[i] != '\0' && carac[i] != ':'){
        nomb[j] = carac[i];
        i++;
        j++;
    }
    nomb[j] = '\0';
    if(carac[i] != '\0'){
        i++;
    }
    cell->genre = genr;
    cell->nombre = nomb;

    return i;
}

void addFadj(char* temp1, char* temp2, char* temp3, int i, Fadj *f){
    if(temp3[i] == '\0'){
        return;
    }
    if(i==0){
        while(f->next != NULL){
            f = f->next;
        }
    }

    Fadj *newFadj = malloc(1*sizeof(Fadj));
    newFadj->ff = Calculer_Diff_et_ffAdj(temp1, temp2, &(newFadj->diff));
    //Fonction pour carac
    i = insertCaracAdj(newFadj, temp3, i);

    newFadj->next = NULL;
    f->next = newFadj;

    addFadj(temp1, temp2, temp3, i, newFadj);
}

Fadj* createFirstFadj(char* temp1, char* temp2, char* temp3){
    //creation de la premiere cellule
    Fadj *newFadj= malloc(1 * sizeof(Fadj));
    //parametre de ff ET diff
    newFadj->ff = Calculer_Diff_et_ffAdj(temp1, temp2, &(newFadj->diff));
    int i = 0;
    /*Tout les whiles pour la gestion de newFadj->...*/
    /*maybe faire une fonction pcq ca va etre long*/
    i = insertCaracAdj(newFadj, temp3, i);

    newFadj->next = NULL;
    //si temp3 a plus que 1 parametre
    if (*(temp3 + i) != '\0')
    {
        //appelle de la fonction general
        addFadj(temp1, temp2, temp3, i, newFadj);
    }

    //return la premiere cellule et tout les suivantes si elles exitent
    return newFadj;
}

void insertTreeAdj(RAdj* root, char* temp1, char* temp2, char* temp3){
    Adj* p_node = NULL;
    int i = 0, j = 0;

    int find = isValInTabAdj(root->child, root->nbenfant, temp2[i]);

    if(find == -1){
        root->child = realloc(root->child, (root->nbenfant+1)*sizeof(Adj*));
        root->child[root->nbenfant] = newNodeAdj(temp2[i]);
        root->nbenfant++;
        p_node = root->child[root->nbenfant-1];
        i++;
        while(temp2[i] != '\0'){
            createNodeAdj(p_node, temp2[i]);
            p_node = p_node->child[p_node->nbenfant-1];
            i++;
        }
        p_node->nbflechit = 1;
        p_node->end = 1;
        p_node->ff = createFirstFadj(temp1, temp2, temp3);
    }else{
        p_node = root->child[find];
        i++;
        find = isValInTabAdj(p_node->child, p_node->nbenfant, temp2[i]);
        while(find != -1 && temp2[i] != '\0'){
            p_node = p_node->child[find];
            i++;
            find = isValInTabAdj(p_node->child, p_node->nbenfant, temp2[i]);
        }
        if(temp2[i] == '\0'){//On se trouve à la fin
            //fonction pour ajouter dans la llc
            if(p_node->end){
                addFadj(temp1, temp2, temp3, j, p_node->ff);
            }
            else{
                p_node->nbflechit += 1;
                p_node->end = 1;
                p_node->ff = createFirstFadj(temp1, temp2, temp3);
            }
        }else{//On se trouve dans un noeud (pas à la fin)
            while(temp2[i] != '\0'){
                createNodeAdj(p_node, temp2[i]);
                p_node = p_node->child[p_node->nbenfant-1];
                i++;
            }
            p_node->nbflechit += 1;
            p_node->end = 1;
            p_node->ff = createFirstFadj(temp1, temp2, temp3);
        }
    }
}