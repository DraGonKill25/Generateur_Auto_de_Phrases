#include "../Fonctionnalites/helper.h"
#include "free_memory.h"
#include "../structures.h"




void Free_Tree_ADV(Adv *a)
{
    if (!a)
        return;
        
    if (a->nbenfant != 0)
    {
        int enfant = a->nbenfant;
        for (int i=0; i<enfant; i++)
        {
            a->nbenfant--;
            Free_Tree_ADV(a->child[i]);
        }
        //Free_Tree_VB(v->child[v->nbenfant-1]);
    }
    if (a->nbenfant == 0)
        free(a->child);
    free(a);
}




void Free_Tree_ADJ(Adj *a)
{
    if (!a)
        return;
        
    if (a->nbenfant != 0)
    {
        int enfant = a->nbenfant;
        for (int i=0; i<enfant; i++)
        {
            a->nbenfant--;
            Free_Tree_ADJ(a->child[i]);
        }
        //Free_Tree_VB(v->child[v->nbenfant-1]);
    }
    
    if (a->ff != NULL)
    {        
        //Free_VB_FF(v->ff);
        Fadj *f = a->ff;
	    while(f !=NULL)
    	{
        	Fadj* temp = f->next;

    		if (f->ff != NULL)
    		{
        	    free(f->ff);
        	    //printf("%d\n", f->diff);
            }
        	if (f->nombre != NULL)
        	    free(f->nombre);
        	if (f->genre != NULL)
        	    free(f->genre);
        	free(f);
        	f = temp;
    	}
    	a->ff = NULL;
    }
    if (a->nbenfant == 0)
        free(a->child);
    free(a);
}




void Free_Tree_NOM(Nom *n)
{
    if (!n)
        return;
        
    if (n->nbenfant != 0)
    {
        int enfant = n->nbenfant;
        for (int i=0; i<enfant; i++)
        {
            n->nbenfant--;
            Free_Tree_NOM(n->child[i]);
        }
        //Free_Tree_VB(v->child[v->nbenfant-1]);
    }
    
    if (n->ff != NULL)
    {        
        //Free_VB_FF(v->ff);
        Fnom *f = n->ff;
	    while(f !=NULL)
    	{
        	Fnom* temp = f->next;

    		if (f->ff != NULL)
    		{
        	    free(f->ff);
        	    //printf("%d\n", f->diff);
            }
        	if (f->nombre != NULL)
        	    free(f->nombre);
        	if (f->genre != NULL)
        	    free(f->genre);
        	free(f);
        	f = temp;
    	}
    	n->ff = NULL;
    }
    
    if (n->child != NULL)
        free(n->child);
    free(n);
}




void Free_Tree_VB(Vb *v)
{
    if (!v)
        return;
        
    if (v->nbenfant != 0)
    {
        int enfant = v->nbenfant;
        for (int i=0; i<enfant; i++)
        {
            v->nbenfant--;
            Free_Tree_VB(v->child[i]);
        }
        //Free_Tree_VB(v->child[v->nbenfant-1]);
    }
    
    if (v->ff != NULL)
    {        
        //Free_VB_FF(v->ff);
        Fvb *f = v->ff;
	    while(f !=NULL)
    	{
        	Fvb* temp = f->next;

    		if (f->ff != NULL)
    		{
        	    free(f->ff);
        	    //printf("%d\n", f->diff);
            }
            if (f->personne != NULL)
        	    free(f->personne);
            if (f->conjugaison != NULL)
        	    free(f->conjugaison);
        	if (f->nombre != NULL)
        	    free(f->nombre);
        	if (f->genre != NULL)
        	    free(f->genre);
        	free(f);
        	f = temp;
    	}
    	v->ff = NULL;
    }
    if (v->nbenfant == 0)
        free(v->child);
    free(v);
    
}




void Free_VB(RVb *tree)
{
    for (int k=0; k<tree->nbenfant; k++)
    {
        //printf("%d\n", k);
        if (!tree->child[k])
            continue;
        Free_Tree_VB(tree->child[k]);
    }
    free(tree->child);
}

void Free_NOM(RNom *nom)
{
    for (int k=0; k<nom->nbenfant; k++)
    {
        //printf("%d\n", k);
        if (!nom->child[k])
            continue;
        Free_Tree_NOM(nom->child[k]);
    }
    free(nom->child);
}

void Free_ADJ(RAdj *adj)
{
    for (int k=0; k<adj->nbenfant; k++)
    {
        //printf("%d\n", k);
        if (!adj->child[k])
            continue;
        Free_Tree_ADJ(adj->child[k]);
    }
    free(adj->child);
}

void Free_ADV(RAdv *adv)
{    
    for (int k=0; k<adv->nbenfant; k++)
    {
        //printf("%d\n", k);
        if (!adv->child[k])
            continue;
        Free_Tree_ADV(adv->child[k]);
    }
    free(adv->child);
}








