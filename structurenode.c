#include "structurenode.h"

Snode *newSnode(Tnode *a)
	{
	Snode *n = malloc(sizeof(Snode));
	n->tnode = a;
	n->next = NULL;
	n->prev = NULL;
	n->left = 0;
	return n;
	}
Snode *nSnode(void)
	{
	Snode *n = malloc(sizeof(Snode));
	n->tnode = NULL;
	n->next = NULL;
	n->prev = NULL;	
	n->left = 0;
	return n;
	}
void changeSnode(Snode *curr,Snode *a, Snode *b)
	{
	curr->next = a;
	curr->prev = b;
	}		
