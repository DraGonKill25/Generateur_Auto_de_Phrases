//
//Projet Générateur automatique de phrases
//Adam RILI, Timothé DEBORD, Nathan SIMOES
//
//Fichier qui a pour role de définir les fonctions utilisées pour la création de l'arbre des adjectifs.
//Ces deux fichiers ont pour roles la création de l'arbre des adjectifs, et l'insertion d'un adjectif si cet arbre est déjà
//créé et que l'adjectif ne s'y trouves pas.

#include "arbreAdj.h"

//Fonction qui prend en paramètres un tableau dynamique de pointeurs, la taille de ce tableau et la lettre que l'on
//veut trouver
//Retourne un entier (-1 si l'on a pas trouvé la lettre dans un des chaques noeuds pointés par les cases du tableau
//sinon l'indice de la case pointant vers le noeud ayant la lettre que l'on cherche)
//Fonction qui s'occupe de vérifier si une lettre ce trouve bien dans un des noeuds pointé par une des cases du tableau
//dynamique.
int isValInTabAdj(Adj** tab, int length, char flettre){
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

//Fonction qui prend en paramètres un noeud de l'arbre des adjectifs
//Ne retourne rien
//Fonction qui s'occupe d'initialiser les paramètres d'un noeud de type Adj (0 pour int et NULL pour adresses)
//Fait en sorte que les paramètres d'un noeud ne soient pas des valeures inconnues lorsque l'on en créé un.
void initStructAdj(Adj* node){
    node->nbenfant = 0;
    node->nbflechit = 0;
    node->end = 0;
    node->ff = NULL;
    node->child = NULL;
}

//Fonction qui prend en paramètres une lettre
//Retourne une node de type Adj
//Fonction qui créé un nouveau noeud en y insérant la lettre qui lui correspond et qui l'initialise avant de la retourner
Adj* newNodeAdj(char lettre){
    Adj *node = (Adj*)malloc(sizeof(Adj));//On alloue dynamiquement un nouveau noeud
    node->lettre = lettre;//On y insère la lettre
    initStructAdj(node);//On l'initialise
    return node;
}

//Fonction qui prend en paramètres un pointeur sur un noeud et une lettre
//Retourne ce pointeur
//Fonction qui créé un nouveau noeud et qui devient l'enfant du noeud inséré en paramètres
Adj* createNodeAdj(Adj* p_node, char lettre){
    p_node->nbenfant +=1;
    p_node->child = realloc(p_node->child, p_node->nbenfant*sizeof(Adj*));
    p_node->child[p_node->nbenfant-1] = newNodeAdj(lettre);//Le noeud créé devient le fils du noeud pointé
    return p_node;
}

//Fonction qui prend en paramètres deux chaînes de caractères (temp1 = forme fléchie, temp2 = forme de base) et un
//pointeur sur un entier
//Retourne une chaîne de caractères correspondant à la différence de caractères entre la forme de base et la forme fléchie
//et modifie l'entier de différence entre ces deux formes (pointeur en paramètres)
//Fonction qui sert à calculer le nombre de caractères différends entre la forme de base et la forme fléchie et d'identifier
//ces caractères de différences
char* Calculer_Diff_et_ffAdj(char *temp1, char *temp2, int *diff)
{
    int i = 0;
    int j = 0;
    int len1 = mystrlen(temp1);//Longueur de la forme fléchie
    int len2 = mystrlen(temp2);//Longueur de la forme de base
    char *toreturn;//caractères de différences

    while (*(temp1 + i) != '\0' && *(temp2 + j) != '\0' &&*(temp1 + i) == *(temp2 + j))//Parcours jusqu'à ce que ce les deux formes soient différentes
    {
        i++;
        j++;
    }

    if (*(temp2 + j) == '\0')//si on est arrivé à la fin de la forme de base
    {
        if (*(temp1 + i) != '\0')//Si on n'est pas arrivé à la fin de la forme fléchie
        {
            toreturn = malloc((len1 - i + 1) * sizeof(char)); //On alloue la taille correspondant à la différence de ces deux formes
            int k = 0;
            while(*(temp1 + i) != '\0')
            {
                *(toreturn + k) = *(temp1 + i); //On insère les caractères de différences
                i++;
                k++;
            }
            *(toreturn + k) = '\0';
            *diff = k - 1;//On indique le nombre de caractères différents
            return toreturn;
        }
        else// Si on est aussi arrivé à la fin de la forme fléchie (forme fléchie = forme de base)
        {
            diff = 0;
            return NULL;
        }
    }
    else// Si on est pas arrivé à la fin de la forme de base
    {
        if (*(temp1 + i) != '\0') // Si on est aussi pas arrivé à la fin de la forme fléchie
        {
            *diff = -(len2 - j);//Nombre de caractères de différence à enlever de la forme de base
            toreturn = malloc((len1 - i + 1) * sizeof(char)); //On alloue la taille correspondant à la différence de ces deux formes
            int k = 0;
            while(*(temp1 + i) != '\0')
            {
                *(toreturn + k) = *(temp1 + i);//On insère les caractères de différences
                i++;
                k++;
            }
            *(toreturn + k) = '\0';
            return toreturn;
        }

        else//Si on est arrivé à la fin de la forme fléchie
        {
            *diff = -(len2 - len1);//Nombre de caractères de différence à enlever de la forme de base
            return NULL;//Il n'y a donc pas de caractères de différence (on en supprime juste)
        }
    }
}

//Fonction qui prend en paramètres une cellule de formes fléchies, une chaîne de caractères comprenant les caractéristiques
//de la forme fléchie (temp3) et un entier i (pour la récursivité)
//Retourne un entier i
//Fonction qui a pour role d'insérer les caractéristiques d'une forme fléchie dans une cellule de la forme fléchie correspondante
int insertCaracAdj(Fadj *cell, char* carac, int i){
    int j=0;

    char* nomb = (char*)malloc(8*sizeof(char));//nombre
    char* genr = (char*)malloc(8*sizeof(char));//genre


    while(carac[i] != '\0' && carac[i] != ':') {
        while (carac[i] != '+' && carac[i] != '\0') {
            genr[j] = carac[i];//On insère le genre dans genr
            i++;
            j++;
        }
        genr[j] = '\0';
        i++;
        j = 0;

        while (carac[i] != '\0' && carac[i] != ':') {
            nomb[j] = carac[i];//On insère le nombre dans nomb
            i++;
            j++;
        }
        nomb[j] = '\0';
    }
    if(carac[i] != '\0'){//Condition pour que le i ne sorte pas du tableau
        i++;
    }

    //On insère les paramètres
    cell->genre = genr;
    cell->nombre = nomb;

    return i;//Pour la récursion
}

//Fonction qui prend en paramètres la forme de base, la forme fléchie, les caractéristiques, un entier i et un pointeur
//vers une cellule de forme fléchie
//Fonction récursive qui ne retourne rien
//Fonction qui s'occupe de créer une cellule de forme fléchie et qui la relie à une LSC déjà existante, en créer davantages
//(active la récursion)
void addFadj(char* temp1, char* temp2, char* temp3, int i, Fadj *f){
    if(temp3[i] == '\0'){//Condition d'arrêt de la récursion (Si l'on a déjà inséré toutes les caractéristiques)
        return;
    }
    if(i==0){//Si l'on a pas fait la récursion et/ou pas déjà insérer des caractéristiques des formes fléchies
        while(f->next != NULL){//On parcours la LSC, pour le cas où elle existerais déjà
            f = f->next;
        }
    }

    Fadj *newFadj = malloc(1*sizeof(Fadj));
    newFadj->ff = Calculer_Diff_et_ffAdj(temp1, temp2, &(newFadj->diff));//On insère le nombre et les caractères de différences dans cette nouvelle cellule
    i = insertCaracAdj(newFadj, temp3, i);//On insère dans cette cellule les caractéristiques (temp3) de la forme fléchie

    newFadj->next = NULL;
    f->next = newFadj;

    addFadj(temp1, temp2, temp3, i, newFadj); //On active la récursion
}

//Fonction qui prend en paramètres la forme fléchie (temp1), la forme de base (temp2) et les caractéristiques (temp3)
//Retourne un pointeur sur une cellule
//Fonction qui créer la premère cellule de la LSC d'un noeud correspondant à la fin d'une forme de base, et les suivantes
//si temp3 à plus que d'un paramètre en appelant la fonction récursive
Fadj* createFirstFadj(char* temp1, char* temp2, char* temp3){
    //creation de la premiere cellule
    Fadj *newFadj= malloc(1 * sizeof(Fadj));
    //parametre de ff ET diff
    newFadj->ff = Calculer_Diff_et_ffAdj(temp1, temp2, &(newFadj->diff));
    int i = 0;
    //Paramètres des caractéristiques
    i = insertCaracAdj(newFadj, temp3, i);

    newFadj->next = NULL;
    //si temp3 a plus que 1 parametre
    if (*(temp3 + i) != '\0')
    {
        //appelle de la fonction récursive
        addFadj(temp1, temp2, temp3, i, newFadj);
    }

    //return la premiere cellule et tout les suivantes si elles exitent
    return newFadj;
}

//Fonction qui prend en paramètres une root d'Adjectifs, une forme fléchie (temp1), une forme de base (temp2) et les
//caractéristiques (temp3)
//Ne retourne rien
//Fonction principale s'occupant de la création de l'arbre des adjectifs et/ou de l'insertion d'une forme de base (de type Adj),
//de sa/ces formes fléchie(s) et de ses caractéristiques
void insertTreeAdj(RAdj* root, char* temp1, char* temp2, char* temp3){
    Adj* p_node = NULL;
    int i = 0, j = 0;

    //Si la première lettre de la forme de base, se trouve dans un des noeuds pointés par une des cases du tableau dynamique de la root de l'arbre des adjectifs
    int find = isValInTabAdj(root->child, root->nbenfant, temp2[i]);

    if(find == -1){//Si la lettre n'y est pas = on créer/insère à partir de la racine
        //On créer le nouveau noeud et on pointe la nouvelle case de la root vers ce noeud
        root->child = realloc(root->child, (root->nbenfant+1)*sizeof(Adj*));
        root->child[root->nbenfant] = newNodeAdj(temp2[i]);
        root->nbenfant++;
        p_node = root->child[root->nbenfant-1];//on pointe p_node à ce nouveau noeud, pour le parcours
        i++;
        //Insertion de toutes les lettres de la forme de base dans chaque nouveau noeud qu'on lie au précédent
        while(temp2[i] != '\0'){
            createNodeAdj(p_node, temp2[i]);
            p_node = p_node->child[p_node->nbenfant-1];
            i++;
        }
        //On arrive à la fin de la forme de base (au dernier noeud), on créer donc la LSC pour la/les formes fléchies et ses caractéristiques
        p_node->nbflechit = 1;
        p_node->end = 1;
        p_node->ff = createFirstFadj(temp1, temp2, temp3);
    }else{//Si la première lettre se trouve dans un des noeuds pointé par une des cases du tableaux dynamique de la racine
        //on effectue le parcours des noeuds jusqu'à ce que la lettre suivante de temp2 ne soient dans aucun des fils ou que l'on arrive à la fin de temp2
        p_node = root->child[find];
        i++;
        find = isValInTabAdj(p_node->child, p_node->nbenfant, temp2[i]);
        while(find != -1 && temp2[i] != '\0'){
            p_node = p_node->child[find];
            i++;
            find = isValInTabAdj(p_node->child, p_node->nbenfant, temp2[i]);
        }
        if(temp2[i] == '\0'){//Si on se trouve à la fin de temp2
            //On doit maintenant ajouter les caractéristiques dans la LSC
            if(p_node->end){//Si la LSC existe déjà = s'il existe déjà des formes fléchies
                addFadj(temp1, temp2, temp3, j, p_node->ff);//On insère de nouvelles cellules (nouvelles caractéristiques) dans cette LSC
            }
            else{//Si la LSC n'existe pas = si il n'y a pas déjà des formes fléchie
                //On ajoute la LSC des formes fléchies
                p_node->nbflechit += 1;
                p_node->end = 1;
                p_node->ff = createFirstFadj(temp1, temp2, temp3);
            }
        }else{//Si on se trouve dans un noeud et pas à la fin de temp2
            //On créer un nouveau fils puis on parcours et créer les autres fils
            while(temp2[i] != '\0'){
                createNodeAdj(p_node, temp2[i]);
                p_node = p_node->child[p_node->nbenfant-1];
                i++;
            }
            //On arrive à la fin de la forme de base (au dernier noeud), on créer donc la LSC pour la/les formes fléchies et ses caractéristiques
            p_node->nbflechit += 1;
            p_node->end = 1;
            p_node->ff = createFirstFadj(temp1, temp2, temp3);
        }
    }
}