//
// Created by natha on 15/11/2022.
//

#include "arbreAdv.h"


int isValInTabAdv(Adv** tab, int length, char flettre){
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

void initStructAdv(Adv* node){
    node->nbenfant = 0;
    node->end = 0;
    node->child = NULL;
}

Adv* newNodeAdv(char lettre){
    Adv *node = (Adv*)malloc(sizeof(Adv));
    node->lettre = lettre;
    initStructAdv(node);
    return node;
}

Adv* createNodeAdv(Adv* p_node, char lettre){
    p_node->nbenfant +=1;
    p_node->child = realloc(p_node->child, p_node->nbenfant*sizeof(Adv*));
    p_node->child[p_node->nbenfant-1] = newNodeAdv(lettre);
    return p_node;
}

void insertTreeAdv(RAdv* root, char* temp2){
    Adv* p_node = NULL;
    int i = 0, j = 0;

    int find = isValInTabAdv(root->child, root->nbenfant, temp2[i]);

    if(find == -1){
        root->child = realloc(root->child, (root->nbenfant+1)*sizeof(Adv*));
        root->child[root->nbenfant] = newNodeAdv(temp2[i]);
        root->nbenfant++;
        p_node = root->child[root->nbenfant-1];
        i++;
        while(temp2[i] != '\0'){
            createNodeAdv(p_node, temp2[i]);
            p_node = p_node->child[p_node->nbenfant-1];
            i++;
        }
        p_node->end = 1;
    }else{
        p_node = root->child[find];
        i++;
        find = isValInTabAdv(p_node->child, p_node->nbenfant, temp2[i]);
        while(find != -1 && temp2[i] != '\0'){
            p_node = p_node->child[find];
            i++;
            find = isValInTabAdv(p_node->child, p_node->nbenfant, temp2[i]);
        }
        if(temp2[i] != '\0'){//On se trouve dans un noeud (pas à la fin)
            while(temp2[i] != '\0'){
                createNodeAdv(p_node, temp2[i]);
                p_node = p_node->child[p_node->nbenfant-1];
                i++;
            }
            p_node->end = 1;
        }
    }
}