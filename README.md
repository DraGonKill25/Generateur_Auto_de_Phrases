# Generateur_Auto_de_Phrases

Fonction de traitement du fichier texte
3 variables temporaires : forme fléchie, forme de base, type
une fois ce traitement effectué, passer au traitement du type si plusieurs formes 
fléchies
Faire des fonctions de traitement pour le type VERBE NOM ADJ ADV PRE FDB:
ces fonctions vont permettre la création des arbres
Détection du \n -> traitement de la ligne finie
Fonction de comparaison entre la forme fléchie et la forme de base !
Une fois la forme de base créée, mettre à jour le nombre de formes fléchies/nbchildren
Récupérer les indices ou les lettres sont différentes pour la première fois
comparaison de temp1 et temp2 afin d'incrémenter le nb de formes fléchies, dans la
fonction de traitement de la forme de base.

Fonction de traitement des paramètres à appeler dans la fonction de traitement du type
Fonction FDB : ajouter +1 au nb de formes fléchies
Fonction forme fléchie : construction dans l'arbre le reste de la ff par rapport à la fdb
Ajout des paramètres via une autre fonction à appeler sur le dernier noeud.