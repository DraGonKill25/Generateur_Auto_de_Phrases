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

Fvb* createFvb(char* temp1, char* temp3){
    Fvb *llc = (Fvb*)malloc(sizeof(Fvb));
    char *formef = (char*)malloc(sizeof(char));
    formef = temp1;
    llc->ff = formef;
    llc->next = NULL;
    return llc;
}

void addEndVb(Vb* node, char* dec, char* car){
    node->end = 1;
    node->nbflechit = 1;
    node->ff = createFvb(dec, car);
}

Vb* createNode(Vb* p_node, char lettre){
    p_node->nbenfant +=1;
    p_node->child = realloc(p_node->child, p_node->nbenfant*sizeof(Vb*));
    p_node->child[p_node->nbenfant-1] = newNode(lettre);
    return p_node;
}

RVb insertTreeVb(RVb root, char* temp1, char* temp2, char* temp3){
    Vb* p_node = NULL;
    Fvb* p_llc = NULL;
    int i = 0;

    int find = isValInTab(root.child, root.nbenfant, temp2[i]);

    if(find == -1){
        root.child = realloc(root.child, (root.nbenfant+1)*sizeof(Vb*));
        root.child[root.nbenfant] = newNode(temp2[i]);
        root.nbenfant++;
        p_node = root.child[root.nbenfant-1];
        i++;
        while(temp2[i] != '\0'){
            createNode(p_node, temp2[i]);
            p_node = p_node->child[p_node->nbenfant-1];
            i++;
        }
        addEndVb(p_node, temp1, temp3);
    }else{
        p_node = root.child[find];
        i++;
        find = isValInTab(p_node->child, p_node->nbenfant, temp2[i]);
        while(find != -1 && temp2[i] != '\0'){
            p_node = p_node->child[find];
            i++;
            find = isValInTab(p_node->child, p_node->nbenfant, temp2[i]);
        }
        if(temp2[i] == '\0'){//On se trouve à la fin
            //fonction pour ajouter dans la llc
            p_llc = p_node->ff;
            while(p_llc->next != NULL){//on parcours la LLC
                p_llc = p_llc->next;
            }
            p_llc->next = createFvb(temp1, temp3);// On créer une nouvelle cellule
        }else{//On se trouve dans un noeud (pas à la fin)
            while(temp2[i] != '\0'){
                createNode(p_node, temp2[i]);
                p_node = p_node->child[p_node->nbenfant-1];
                i++;
            }
            addEndVb(p_node, temp1, temp3);
        }
    }
    return root;
}