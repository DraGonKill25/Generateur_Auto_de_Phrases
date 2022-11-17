#include <stdio.h>
#include <stdlib.h>



void Free_VB_FF(Fvb *f)
{
	if (!f)
	{
		return
	}

	if (f->next != NULL)
	{
		Free_VB_FF(f->next);
	}

	free(f->ff);
	free(f->personne)
    free(f->conjugaison)
    free(f->nombre)
    free(f->genre)
    free(f);
}




void Free_VB(VB *v)
{
	if (vb->nbenfant != 0)
	{
		for (int i=0; i<v->nbenfant; i++)
		{
			Free_VB(v->child[i]);

		}
		Free_VB(v->child[v->nbenfant-1])
	}
	Free_VB_FF(v->ff);
	if (v->ff != NULL)
	{
		free(v->ff);
	}
	free(v->child);
	free(v);
}