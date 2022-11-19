//
//Projet Générateur automatique de phrases
//Adam RILI, Timothé DEBORD, Nathan SIMOES
//
//Fichier qui a pour role de définir les fonctions utilisées pour la création de l'arbre des verbes.
//Ces deux fichiers ont pour roles la création de l'arbre des verbes, et l'insertion d'un verbe si cet arbre est déjà
//créé et que le verbe ne s'y trouves pas.

#include "arbreVb.h"

//Fonction qui prend en paramètres un tableau dynamique de pointeurs, la taille de ce tableau et la lettre que l'on
//veut trouver
//Retourne un entier (-1 si l'on a pas trouvé la lettre dans une des chaques noeuds pointés par les cases du tableau
//sinon l'indice de la case pointant vers le noeud ayant la lettre que l'on cherche)
//Fonction qui s'occupe de vérifier si une lettre ce trouve bien dans un des noeuds pointé par une des cases du tableau
//dynamique.
int isValInTabVb(Vb** tab, int length, char flettre){
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

//Fonction qui prend en paramètres un noeud de l'arbre des verbes
//Ne retourne rien
//Fonction qui s'occupe d'initialiser les paramètres d'un noeud de type Vb (0 pour int et NULL pour adresses)
//Fait en sorte que les paramètres d'un noeud ne soient pas des valeures inconnues lorsque l'on en créé un.
void initStructVb(Vb* node){
    node->nbenfant = 0;
    node->nbflechit = 0;
    node->end = 0;
    node->ff = NULL;
    node->child = NULL;
}

//Fonction qui prend en paramètres une lettre
//Retourne une node de type Vb
//Fonction qui créé un nouveau noeud en y insérer la lettre qui lui correspond et qui l'initialise avant de la retourner
Vb* newNodeVb(char lettre){
    Vb *node = (Vb*)malloc(sizeof(Vb));//On alloue dynamiquement un nouveau noeud
    node->lettre = lettre;//On y insère la lettre
    initStructVb(node);//On l'initialise
    return node;
}

//Fonction qui prend en paramètres un pointeur sur un noeud et une lettre
//Retourne ce pointeur
//Fonction qui créé un nouveau noeud et qui devient l'enfant du noeud inséré en paramètres
Vb* createNodeVb(Vb* p_node, char lettre){
    p_node->nbenfant +=1;
    p_node->child = realloc(p_node->child, p_node->nbenfant*sizeof(Vb*));
    p_node->child[p_node->nbenfant-1] = newNodeVb(lettre); //On créer un nouveau noeud qui devient le fils du noeud pointé
    return p_node;
}

//Fonction qui prend en paramètres deux chaînes de caractères (temp1 = forme fléchie, temp2 = forme de base) et un
//pointeur sur un entier
//Retourne une chaîne de caractères correspondant à la différence de caractères entre la forme de base et la forme fléchie
//et modifie l'entier de différence entre ces deux formes (pointeur en paramètres)
//Fonction qui sert à calculer le nombre de caractères différends entre la forme de base et la forme fléchie et d'identifier
//ces caractères de différences
char* Calculer_Diff_et_ffVb(char *temp1, char *temp2, int *diff)
{
    int i = 0;
    int j = 0;
    int len1 = mystrlen(temp1); //Longueur de la forme fléchie
    int len2 = mystrlen(temp2); //Longueur de la forme de base
    char *toreturn; //caractères de différences

    while (*(temp1 + i) != '\0' && *(temp2 + j) != '\0' &&*(temp1 + i) == *(temp2 + j)) //Parcours jusqu'à ce que ce les deux formes soient différentes
    {
        i++;
        j++;
    }

    if (*(temp2 + j) == '\0') //si on est arrivé à la fin de la forme de base
    {
        if (*(temp1 + i) != '\0') //Si on n'est pas arrivé à la fin de la forme fléchie
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
            *diff = k - 1; //On indique le nombre de caractères différents
            return toreturn;
        }
        else // Si on est aussi arrivé à la fin de la forme fléchie (forme fléchie = forme de base)
        {
            diff = 0;
            return NULL;
        }
    }
    else // Si on est pas arrivé à la fin de la forme de base
    {
        if (*(temp1 + i) != '\0') // Si on est aussi pas arrivé à la fin de la forme fléchie
        {
            *diff = -(len2 - j); //Nombre de caractères de différence à enlever de la forme de base
            toreturn = malloc((len1 - i + 1) * sizeof(char)); //On alloue la taille correspondant à la différence de ces deux formes
            int k = 0;
            while(*(temp1 + i) != '\0')
            {
                *(toreturn + k) = *(temp1 + i); //On insère les caractères de différences
                i++;
                k++;
            }
            *(toreturn + k) = '\0';
            return toreturn;
        }

        else //Si on est arrivé à la fin de la fin de la forme fléchie
        {
            *diff = -(len2 - len1); //Nombre de caractères de différence à enlever de la forme de base
            return NULL; //Il n'y a donc pas de caractères de différence (on en supprime juste)
        }
    }
}

//Fonction qui prend en paramètres une cellule de formes fléchies, une chaîne de caractères comprenant les caractéristiques
//de la forme fléchie (temp3) et un entier i (pour la récursivité)
//Retourne un entier i
//Fonction qui a pour role d'insérer les caractéristiques d'un forme fléchie dans une cellule de la forme fléchie correspondante
int insertCaracVb(Fvb *cell, char* carac, int i){
    int j=0, pass=0;

    char* per = (char*)malloc(8*sizeof(char)); //personne
    char* conj = (char*)malloc(8*sizeof(char)); //conjugaison (temps)
    char* nomb = (char*)malloc(8*sizeof(char)); //nombre
    char* genr = (char*)malloc(8*sizeof(char)); //genre

    while(carac[i] != '\0' && carac[i] != ':'){
        while(carac[i] != '+' && carac[i] != '\0'){
            conj[j] = carac[i]; //On insère le temps du verbe dans conj
            i++;
            j++;
        }
        conj[j] = '\0';
        if(carac[i] == '\0'){ //Si carac = "PPre" ou "PPas"
            pass = 1; //Condition pour l'insertion dans la cellule
            break;
        }
        i++;
        j=0;
        if(carac[i+2] == '+'){ //Si carac = "temps+nombre+personne"
            genr = NULL; //Il n'y aura pas de genre
            while(carac[i] != '+'){
                nomb[j] = carac[i]; //On insère le nombre dans nomb
                i++;
                j++;
            }
            nomb[j] = '\0';
            i++;
            j=0;
            while(carac[i] != '\0' && carac[i] != ':'){
                per[j] = carac[i]; //On insère la personne dans per
                i++;
                j++;
            }
            per[j] = '\0';
        }else{ // Si carac = "temps+genre+nombre"
            per = NULL; //Il n'y aura pas de personne
            while(carac[i] != '+'){
                genr[j] = carac[i]; //On insère le genre dans genr
                i++;
                j++;
            }
            genr[j] = '\0';
            i++;
            j=0;
            while(carac[i] != '\0' && carac[i] != ':'){
                nomb[j] = carac[i]; //On insère le nombre dans nomb
                i++;
                j++;
            }
            nomb[j] = '\0';
        }
    }
    if(carac[i] != '\0'){ //Condition pour que le i ne sorte pas du tableau
        i++;
    }

    if(pass == 1){ //Si carac = "PPre" ou "PPas"
        cell->conjugaison = conj; //On insère juste la conjugaison
        cell->personne = NULL;
        cell->genre = NULL;
        cell->nombre = NULL;
    }
    else{
        cell->conjugaison = conj; //Il y aura forcément un temps et un nombre
        cell->nombre = nomb;
        if(per == NULL){//Si carac = "temps+genre+nombre"
            cell->genre = genr;
            cell->personne = NULL;
        }else{//Si carac = "temps+nombre+personne"
            cell->personne = per;
            cell->genre = NULL;
        }
    }
    return i; //Pour la récursion (Si carac = "temps+nombre+personne:temps+nombre+personne:temps+nombre+personne:...")
}

//Fonction qui prend en paramètres la forme de base, la forme fléchie, les caractéristiques, un entier i et un pointeur
//vers une cellule de forme fléchie
//Fonction récursive qui ne retourne rien
//Fonction qui s'occupe de créer une cellule de forme fléchie et qui la relie à une LSC déjà existante, en créer davantages
//(active la récursion) lorsque temp3 = "temps+nombre+personne:temps+nombre+personne:temps+nombre+personne:..."
void addFvb(char* temp1, char* temp2, char* temp3, int i, Fvb *f){//SI f est NULL??
    if(temp3[i] == '\0'){//Condition d'arrêt de la récursion (Si l'on a déjà inséré toutes les caractéristiques)
        return;
    }
    if(i==0){//Si l'on a pas fait la récursion et/ou pas déjà insérer des caractéristiques des formes fléchies
        while(f->next != NULL){//On parcours la LSC, pour le cas où elle existerais déjà
            f = f->next;
        }
    }

    Fvb *newFvb = malloc(1*sizeof(Fvb));
    newFvb->ff = Calculer_Diff_et_ffVb(temp1, temp2, &(newFvb->diff));//On insère le nombre et les caractères de différences dans cette nouvelle cellule
    i = insertCaracVb(newFvb, temp3, i); //On insère dans cette cellule les caractéristiques (temp3) de la forme fléchie

    newFvb->next = NULL;
    f->next = newFvb;

    addFvb(temp1, temp2, temp3, i, newFvb); //On active la récursion
}

//Fonction qui prend en paramètres la forme fléchie (temp1), la forme de base (temp2) et les caractéristiques (temp3)
//Retourne un pointeur sur une cellule
//Fonction qui créer la premère cellule de la LSC d'un noeud correspondant à la fin d'une forme de base, et les suivantes
//si temp3 à plus que d'un paramètre en appelant la fonction récursive
Fvb* createFirstFvb(char* temp1, char* temp2, char* temp3){
    //creation de la premiere cellule
    Fvb *newFvb = malloc(1 * sizeof(Fvb));
    //parametre de ff ET diff
    newFvb->ff = Calculer_Diff_et_ffVb(temp1, temp2, &(newFvb->diff));
    int i = 0;
    //Paramètres des caractères
    i = insertCaracVb(newFvb, temp3, i);

    newFvb->next = NULL;
    //si temp3 a plus que 1 parametre (temp3 = "temps+nombre+personne:temps+nombre+personne:temps+nombre+personne:...")
    if (*(temp3 + i) != '\0')
    {
        //appelle de la fonction récursive
        addFvb(temp1, temp2, temp3, i, newFvb);
    }

    //return la premiere cellule et tout les suivantes si elles exitent
    return newFvb;
}

//Fonction qui prend en paramètres une root de Verbes, une forme fléchie (temp1), une forme de base (temp2) et les
//caractéristiques (temp3)
//Ne retourne rien
//Fonction principale s'occupant de la création de l'arbre des verbes et/ou de l'insertion d'une forme de base (de type verbe),
//de sa/ces formes fléchie(s) et de ses caractéristiques
void insertTreeVb(RVb* root, char* temp1, char* temp2, char* temp3){
    Vb* p_node = NULL;
    int i = 0, j = 0;

    //Si la première lettre de la forme de base, se trouve dans un des noeuds pointés par une des cases du tableau dynamique de la root de l'arbre des verbes
    int find = isValInTabVb(root->child, root->nbenfant, temp2[i]);

    if(find == -1){ //Si la lettre n'y est pas = on créer/insère à partir de la racine
        //On créer le nouveau noeud et on pointe la nouvelle case de la root vers ce noeud
        root->child = realloc(root->child, (root->nbenfant+1)*sizeof(Vb*));
        root->child[root->nbenfant] = newNodeVb(temp2[i]);
        root->nbenfant++;
        p_node = root->child[root->nbenfant-1];//on pointe p_node à ce nouveau noeud, pour le parcours
        i++;
        //Insertion de toutes les lettres de la forme de base dans chaque nouveau noeud qu'on lie au précédent
        while(temp2[i] != '\0'){
            createNodeVb(p_node, temp2[i]);
            p_node = p_node->child[p_node->nbenfant-1];
            i++;
        }
        //On arrive à la fin de la forme de base (au dernier noeud), on créer donc la LSC pour la/les formes fléchies et ses caractéristiques
        p_node->nbflechit = 1;
        p_node->end = 1;
        p_node->ff = createFirstFvb(temp1, temp2, temp3);
    }else{//Si la première lettre se trouve dans un des noeuds pointé par une des cases du tableaux dynamique de la racine
        //on effectue le parcours des noeuds jusqu'à ce que la lettre suivante de temp2 ne soient dans aucun des fils ou que l'on arrive à la fin de temp2
        p_node = root->child[find];
        i++;
        find = isValInTabVb(p_node->child, p_node->nbenfant, temp2[i]);
        while(find != -1 && temp2[i] != '\0'){
            p_node = p_node->child[find];
            i++;
            find = isValInTabVb(p_node->child, p_node->nbenfant, temp2[i]);
        }
        if(temp2[i] == '\0'){//Si on se trouve à la fin de temp2
            //On doit maintenant ajouter les caractéristiques dans la LSC
            if(p_node->end){//Si la LSC existe déjà = s'il existe déjà des formes fléchies
                addFvb(temp1, temp2, temp3, j, p_node->ff);//On insère de nouvelles cellules (nouvelles caractéristiques) dans cette LSC
            }
            else{//Si la LSC n'existe pas = si il n'y a pas déjà des formes fléchie
                //On ajoute la LSC des formes fléchies
                p_node->nbflechit += 1;
                p_node->end = 1;
                p_node->ff = createFirstFvb(temp1, temp2, temp3);
            }

        }else{//Si on se trouve dans un noeud et pas à la fin de temp2
            //On créer un nouveau fils puis on parcours et créer les autres fils
            while(temp2[i] != '\0'){
                createNodeVb(p_node, temp2[i]);
                p_node = p_node->child[p_node->nbenfant-1];
                i++;
            }
            //On arrive à la fin de la forme de base (au dernier noeud), on créer donc la LSC pour la/les formes fléchies et ses caractéristiques
            p_node->nbflechit += 1;
            p_node->end = 1;
            p_node->ff = createFirstFvb(temp1, temp2, temp3);
        }
    }
}