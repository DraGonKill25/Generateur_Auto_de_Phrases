//
//Projet Générateur automatique de phrases
//Adam RILI, Timothé DEBORD, Nathan SIMOES
//
//Fichier qui a pour role de définir les fonctions utilisées pour la création de l'arbre des adverbes.
//Ces deux fichiers ont pour roles la création de l'arbre des adverbes, et l'insertion d'un adverbe si cet arbre est déjà
//créé et que l'adverbe ne s'y trouves pas.

#include "arbreAdv.h"

//Fonction qui prend en paramètres un tableau dynamique de pointeurs, la taille de ce tableau et la lettre que l'on
//veut trouver
//Retourne un entier (-1 si l'on a pas trouvé la lettre dans un des chaques noeuds pointés par les cases du tableau
//sinon l'indice de la case pointant vers le noeud ayant la lettre que l'on cherche)
//Fonction qui s'occupe de vérifier si une lettre ce trouve bien dans un des noeuds pointé par une des cases du tableau
//dynamique.
int isValInTabAdv(Adv** tab, int length, char flettre){
    if(tab == NULL){//Si le tableau dynamique n'existe pas
        return -1;
    }
    int i = 0;
    for(i = 0; i < length; i++){//on parcours le tableau dynamique
        if(tab[i]->lettre == flettre){//Si la lettre du noeud pointé par la case est la lettre que l'on cherche
            return i;//On retourne sa position
        }
    }
    return -1;
}

//Fonction qui prend en paramètres un noeud de l'arbre des adverbes
//Ne retourne rien
//Fonction qui s'occupe d'initialiser les paramètres d'un noeud de type Adv (0 pour int et NULL pour adresses)
//Fait en sorte que les paramètres d'un noeud ne soient pas des valeures inconnues lorsque l'on en créé un.
void initStructAdv(Adv* node){
    node->nbenfant = 0;
    node->end = 0;
    node->child = NULL;
}

//Fonction qui prend en paramètres une lettre
//Retourne une node de type Adv
//Fonction qui créé un nouveau noeud en y insérant la lettre qui lui correspond et qui l'initialise avant de la retourner
Adv* newNodeAdv(char lettre){
    Adv *node = (Adv*)malloc(sizeof(Adv));//On alloue dynamiquement un nouveau noeud
    node->lettre = lettre;//On y insère la lettre
    initStructAdv(node);//On l'initialise
    return node;
}

//Fonction qui prend en paramètres un pointeur sur un noeud et une lettre
//Retourne ce pointeur
//Fonction qui créé un nouveau noeud et qui devient l'enfant du noeud inséré en paramètres
Adv* createNodeAdv(Adv* p_node, char lettre){
    p_node->nbenfant +=1;
    p_node->child = realloc(p_node->child, p_node->nbenfant*sizeof(Adv*));
    p_node->child[p_node->nbenfant-1] = newNodeAdv(lettre);//Le noeud créé devient le fils du noeud pointé
    return p_node;
}

//Fonction qui prend en paramètres une root d'Adverbes, une forme fléchie (temp1), une forme de base (temp2) et les
//caractéristiques (temp3)
//Ne retourne rien
//Fonction principale s'occupant de la création de l'arbre des adverbes et/ou de l'insertion d'une forme de base (de type Adv),
//de sa/ces formes fléchie(s) et de ses caractéristiques
void insertTreeAdv(RAdv* root, char* temp2){
    Adv* p_node = NULL;
    int i = 0;

    //Si la première lettre de la forme de base, se trouve dans un des noeuds pointés par une des cases du tableau dynamique de la root de l'arbre des adverbes
    int find = isValInTabAdv(root->child, root->nbenfant, temp2[i]);

    if(find == -1){//Si la lettre n'y est pas = on créer/insère à partir de la racine
        //On créer le nouveau noeud et on pointe la nouvelle case de la root vers ce noeud
        root->child = realloc(root->child, (root->nbenfant+1)*sizeof(Adv*));
        root->child[root->nbenfant] = newNodeAdv(temp2[i]);
        root->nbenfant++;
        p_node = root->child[root->nbenfant-1];//on pointe p_node à ce nouveau noeud, pour le parcours
        i++;
        //Insertion de toutes les lettres de la forme de base dans chaque nouveau noeud qu'on lie au précédent
        while(temp2[i] != '\0'){
            createNodeAdv(p_node, temp2[i]);
            p_node = p_node->child[p_node->nbenfant-1];
            i++;
        }
        //On arrive à la fin de la forme de base on met end à 1 (pour les adverbes: forme fléchie = forme de base)
        p_node->end = 1;
    }else{//Si la première lettre se trouve dans un des noeuds pointé par une des cases du tableaux dynamique de la racine
        //on effectue le parcours des noeuds jusqu'à ce que la lettre suivante de temp2 ne soient dans aucun des fils ou que l'on arrive à la fin de temp2
        p_node = root->child[find];
        i++;
        find = isValInTabAdv(p_node->child, p_node->nbenfant, temp2[i]);
        while(find != -1 && temp2[i] != '\0'){
            p_node = p_node->child[find];
            i++;
            find = isValInTabAdv(p_node->child, p_node->nbenfant, temp2[i]);
        }
        if(temp2[i] != '\0'){//Si on se trouve dans un noeud et pas à la fin de temp2
            //On créer un nouveau fils puis on parcours et créer les autres fils
            while(temp2[i] != '\0'){
                createNodeAdv(p_node, temp2[i]);
                p_node = p_node->child[p_node->nbenfant-1];
                i++;
            }
            //On arrive à la fin de la forme de base on met end à 1 (pour les adverbes: forme fléchie = forme de base)
            p_node->end = 1;
        }
    }
}